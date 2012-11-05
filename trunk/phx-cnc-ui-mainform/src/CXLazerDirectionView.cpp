#include "CXLazerDirectionView.h"

#include <QPainter>
#include <QMouseEvent>
#include <QRadialGradient>
#include <qmath.h>

#define RADIUS 18.0

CXLazerDirectionView::CXLazerDirectionView(QWidget* parent) : QWidget(parent)
{
	mDirection = LazerDirectionView::E_Stop;

	qreal x = 0;
	qreal y = 0;

	QPainterPath path;
	path.addEllipse(QPointF(50, 50), RADIUS, RADIUS);
	mPathList.append(path);

	for (int i = 0; i < 8; ++i)
	{
		x = RADIUS * qCos(-(67.5 + 45.0 * i) * M_PI / 180.0) + 50.0;
		y = RADIUS * qSin(-(67.5 + 45.0 * i) * M_PI / 180.0) + 50.0;

		QPainterPath path;
		path.moveTo(x, y);
		path.arcTo(0, 0, 100, 100, 67.5 + 45.0 * i, 45.0);

		x = RADIUS * qCos(-(67.5 + 45.0 * (i + 1)) * M_PI / 180.0) + 50.0;
		y = RADIUS * qSin(-(67.5 + 45.0 * (i + 1)) * M_PI / 180.0) + 50.0;

		path.lineTo(x, y);
		path.arcTo(50.0 - RADIUS, 50.0 - RADIUS, 2 * RADIUS, 2 * RADIUS, 67.5 + 45.0 * (i + 1), -45.0);

		mPathList.append(path);
	}

	for (int i = 0; i < 8; ++i)
	{
		x = 50.0 * qCos((67.5 + 45.0 * i) * M_PI / 180.0) + 50.0;
		y = 50.0 * qSin((67.5 + 45.0 * i) * M_PI / 180.0) + 50.0;

		mDrawPath.moveTo(x, y);

		x = RADIUS * qCos((67.5 + 45.0 * i) * M_PI / 180.0) + 50.0;
		y = RADIUS * qSin((67.5 + 45.0 * i) * M_PI / 180.0) + 50.0;
/*
		x = 50.0 * qCos((67.5 + 45.0 * i + 180.0) * M_PI / 180.0) + 50.0;
		y = 50.0 * qSin((67.5 + 45.0 * i + 180.0) * M_PI / 180.0) + 50.0;
*/
		mDrawPath.lineTo(x, y);
	}

	mDrawPath.addEllipse(0, 0, 100, 100);
	mDrawPath.addEllipse(QPointF(50, 50), RADIUS, RADIUS);
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

	for (int i = 1; i < 5; ++i)
	{
		painter.fillPath(mPathList.at(i * 2), QColor(0, 255, 0, 15));
	}

//	if (mDirection != LazerDirectionView::E_Stop)
	{
		QRadialGradient radialGradient(50, 50, 50);
		radialGradient.setColorAt(0, Qt::green);
		radialGradient.setColorAt(0.5, Qt::green);
		radialGradient.setColorAt(1, QColor(0, 255, 0, 100));

		painter.fillPath(mPathList.at(mDirection), radialGradient);
	}

//	for (int i = 0; i < mPathList.count(); ++i) painter.drawPath(mPathList.at(i));
	painter.drawPath(mDrawPath);

	painter.scale(1.0 / scale, 1.0 / scale);

	painter.setFont(QFont("", 6 * scale));

	QTextOption textOption;
	textOption.setAlignment(Qt::AlignCenter);
	painter.drawText(QRectF((50.0 - RADIUS) * scale, (50.0 - RADIUS) * scale, 2.0 * RADIUS * scale, 2.0 * RADIUS * scale), trUtf8("стоп"), textOption);

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
