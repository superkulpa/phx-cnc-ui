#include "CXLazerDirectionView.h"

#include <QPainter>
#include <QMouseEvent>
#include <QRadialGradient>
#include <qmath.h>

CXLazerDirectionView::CXLazerDirectionView(QWidget* parent) : QWidget(parent)
{
	setObjectName("CXLazerDirectionView");
/**/
	mDirection = LazerDirectionView::E_None;

	for (int i = 0; i < 8; ++i)
	{
		QPainterPath path;
		path.moveTo(50, 50);
		path.arcTo(0, 0, 100, 100, 67.5 + 45 * i, 45);
		path.lineTo(50, 50);

		mPathList.append(path);
	}

	qreal x = 0;
	qreal y = 0;

	for (int i = 0; i < 4; ++i)
	{
		x = 50.0 * qCos((67.5 + 45.0 * i) * M_PI / 180.0) + 50.0;
		y = 50.0 * qSin((67.5 + 45.0 * i) * M_PI / 180.0) + 50.0;

		mDrawPath.moveTo(x, y);

		x = 50.0 * qCos((67.5 + 45.0 * i + 180.0) * M_PI / 180.0) + 50.0;
		y = 50.0 * qSin((67.5 + 45.0 * i + 180.0) * M_PI / 180.0) + 50.0;

		mDrawPath.lineTo(x, y);
	}

	mDrawPath.addEllipse(0, 0, 100, 100);
}

CXLazerDirectionView::~CXLazerDirectionView()
{

}

void CXLazerDirectionView::setDirection(LazerDirectionView::eMoveDirection aDirection)
{
	mDirection = aDirection;

	update();
}

void CXLazerDirectionView::paintEvent(QPaintEvent*)
{
	qreal scale = qMin(width() / mDrawPath.boundingRect().width(), height() /  mDrawPath.boundingRect().height());

	QPainter painter;
	painter.begin(this);
	painter.scale(scale, scale);
	painter.setRenderHint(QPainter::Antialiasing);

	painter.setPen(Qt::DotLine);

	for (int i = 0; i < 4; ++i)
	{
		painter.fillPath(mPathList.at(i * 2), QColor(0, 255, 0, 15));
	}

	if (mDirection != LazerDirectionView::E_None)
	{
		QRadialGradient radialGradient(50, 50, 50);
		radialGradient.setColorAt(0, Qt::green);
		radialGradient.setColorAt(0.5, Qt::green);
		radialGradient.setColorAt(1, QColor(0, 255, 0, 100));

		painter.fillPath(mPathList.at(mDirection), radialGradient);
	}

//	for (int i = 0; i < mPathList.count(); ++i) painter.drawPath(mPathList.at(i));
	painter.drawPath(mDrawPath);

	painter.end();
}

void CXLazerDirectionView::mousePressEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton)
	{
		QPointF pos = e->posF();

		qreal scale = qMin(width() / mDrawPath.boundingRect().width(), height() /  mDrawPath.boundingRect().height());

		updateDirection(pos / scale);
	}
}

void CXLazerDirectionView::mouseMoveEvent(QMouseEvent* e)
{
	QPointF pos = e->posF();

	qreal scale = qMin(width() / mDrawPath.boundingRect().width(), height() /  mDrawPath.boundingRect().height());

	updateDirection(pos / scale);
}

void CXLazerDirectionView::updateDirection(const QPointF& aPos)
{
	for (int i = 0; i < mPathList.count(); ++i)
	{
		if (mPathList.at(i).contains(aPos))
		{
			mDirection = LazerDirectionView::eMoveDirection(i);
			break;
		}
	}

	update();
}
