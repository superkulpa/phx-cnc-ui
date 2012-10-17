#include "CXLazerVelocityView.h"

#include <QPainter>
#include <QMouseEvent>

CXLazerVelocityView::CXLazerVelocityView(QWidget* parent) : QWidget(parent)
{
	setObjectName("CXLazerVelocityView");
/**/
	mVelocity = E_Normal;

	qreal width = 25;

	for (int i = 0; i < 3; ++i)
	{
		QPainterPath path;
		path.moveTo(0, 50 * i);
		path.lineTo(0, 50 * i + 50);
		path.lineTo(width, 50 * i + 50);
		path.lineTo(width, 50 * i);
		path.closeSubpath();

		mPathList.append(path);
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

void CXLazerVelocityView::paintEvent(QPaintEvent*)
{
	qreal scaleX = width() / mDrawPath.boundingRect().width();
	qreal scaleY = height() /  mDrawPath.boundingRect().height();

	QPainter painter;
	painter.begin(this);
	painter.scale(scaleX, scaleY);
	painter.setRenderHint(QPainter::Antialiasing);

	painter.setPen(Qt::DotLine);

	for (int i = 0; i < mVelocity + 1; ++i)
	{
		painter.fillPath(mPathList.at(mPathList.count() - i - 1), QColor(0, 255, 0, 200 - (mPathList.count() - mVelocity) * 40));
	}

	painter.drawPath(mDrawPath);

	painter.end();
}

void CXLazerVelocityView::mousePressEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton)
	{
		QPointF pos = e->posF();

		qreal scaleX = width() / mDrawPath.boundingRect().width();
		qreal scaleY = height() /  mDrawPath.boundingRect().height();

		updateVelocity(QPointF(pos.x() / scaleX, pos.y() / scaleY));
	}
}

void CXLazerVelocityView::mouseMoveEvent(QMouseEvent* e)
{
	QPointF pos = e->posF();

	qreal scaleX = width() / mDrawPath.boundingRect().width();
	qreal scaleY = height() /  mDrawPath.boundingRect().height();

	updateVelocity(QPointF(pos.x() / scaleX, pos.y() / scaleY));
}

void CXLazerVelocityView::updateVelocity(const QPointF& aPos)
{
	for (int i = 0; i < mPathList.count(); ++i)
	{
		if (mPathList.at(i).contains(aPos))
		{
			mVelocity = eVelocity(mPathList.count() - i - 1);
			break;
		}
	}

	update();
}
