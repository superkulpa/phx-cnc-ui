#include "CXLazerVelocityView.h"

#include <QPainter>
#include <QMouseEvent>
#include <QXmlQuery>

int CXLazerVelocityView::mDelay = 0;

CXLazerVelocityView::CXLazerVelocityView(QWidget* parent) : QWidget(parent)
{
	mMode = E_Accumulate;
	mVelocity = E_Normal;

	mDelayTimer = -1;
	if (mDelay == 0) mDelay = getDelay();

	qreal width = 25;

	for (int i = 0; i < 3; ++i)
	{
		QRectF rect(0, 50 * i, width, 50);

		mPathList.append(rect);
	}

	mDrawPath.moveTo(0, 0);

	for (int i = 0; i < 3; ++i)
	{
		mDrawPath.moveTo(0, 50 * i);
		mDrawPath.lineTo(width, 50 * i);
	}

	mDrawPath.moveTo(0, 0);
	mDrawPath.lineTo(0, 150);
	mDrawPath.lineTo(width, 150);
	mDrawPath.lineTo(width, 0);
}

CXLazerVelocityView::~CXLazerVelocityView()
{

}

void CXLazerVelocityView::setMode(eVelocityMode aMode)
{
	mMode = aMode;
	update();
}

void CXLazerVelocityView::setTexts(const QList <QString>& aTexts)
{
	mTexts = aTexts;
	update();
}

void CXLazerVelocityView::paintEvent(QPaintEvent*)
{
	qreal scaleX = width() / mDrawPath.boundingRect().width();
	qreal scaleY = height() /  mDrawPath.boundingRect().height();

	QPainter painter;
	painter.begin(this);
	painter.scale(scaleX, scaleY);
	painter.setRenderHint(QPainter::Antialiasing);

	painter.setPen(Qt::DotLine);

	switch (mMode)
	{
		case E_Accumulate:
		{
			for (int i = 0; i < mVelocity + 1; ++i)
			{
				painter.fillRect(mPathList.at(mPathList.count() - i - 1), QColor(0, 255, 0, 200 - (mPathList.count() - mVelocity) * 40));
			}

			break;
		}
		case E_SingleMode:
		{
			painter.fillRect(mPathList.at(mPathList.count() - mVelocity - 1), QColor(0, 255, 0, 200));

			break;
		}
	}

	painter.setFont(QFont("", 6 * scaleY));
	QTextOption textOption(Qt::AlignCenter);

	painter.drawPath(mDrawPath);

	painter.scale(1.0 / scaleX, 1.0 / scaleY);

	QRectF curRect;
	for (int i = 0; i < 3; ++i)
	{
		curRect = mPathList.at(i);
		curRect.moveTo(curRect.x() * scaleX, curRect.y() * scaleY);
		curRect.setSize(QSizeF(curRect.width() * scaleX, curRect.height() * scaleY));

		painter.drawText(curRect, mTexts.at(i), textOption);
	}

	painter.end();
}

void CXLazerVelocityView::timerEvent(QTimerEvent* e)
{
	if (e->timerId() == mDelayTimer)
	{
		killTimer(mDelayTimer);
		mDelayTimer = -1;

		QPointF pos = mapFromGlobal(QCursor::pos());

		qreal scaleX = width() / mDrawPath.boundingRect().width();
		qreal scaleY = height() /  mDrawPath.boundingRect().height();

		updateVelocity(QPointF(pos.x() / scaleX, pos.y() / scaleY));
	}
}

void CXLazerVelocityView::mousePressEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton)
	{
		mDelayTimer = startTimer(mDelay);
	}
}

void CXLazerVelocityView::mouseReleaseEvent(QMouseEvent* e)
{
	if (mDelayTimer != -1)
	{
		killTimer(mDelayTimer);
		mDelayTimer = -1;
	}

	if (e->button() == Qt::LeftButton && mMode == E_SingleMode)
	{
		setVelocity(E_Normal);
	}
}

void CXLazerVelocityView::mouseMoveEvent(QMouseEvent* e)
{
	if (mDelayTimer == -1)
	{
		QPointF pos = e->posF();

		qreal scaleX = width() / mDrawPath.boundingRect().width();
		qreal scaleY = height() /  mDrawPath.boundingRect().height();

		updateVelocity(QPointF(pos.x() / scaleX, pos.y() / scaleY));
	}
}

void CXLazerVelocityView::updateVelocity(const QPointF& aPos)
{
	for (int i = 0; i < mPathList.count(); ++i)
	{
		if (mPathList.at(i).contains(aPos))
		{
			setVelocity(eVelocity(mPathList.count() - i - 1));
			break;
		}
	}
}

void CXLazerVelocityView::setVelocity(eVelocity aVelocity)
{
	if (mVelocity != aVelocity)
	{
		mVelocity = aVelocity;
		update();
	}
}

int CXLazerVelocityView::getDelay()
{
	QFile xmlFile("settings.xml");

	if (xmlFile.open(QIODevice::ReadOnly))
	{
		QXmlQuery query;
		query.setFocus(&xmlFile);
		query.setQuery("/Settings/delay/text()");

		QString res;
		query.evaluateTo(&res);

		xmlFile.close();

		return qMax(200, res.toInt());
	}

	return 200;
}
