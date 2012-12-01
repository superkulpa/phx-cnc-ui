#include "CXPathView.h"

#include <QPainterPath>
#include <QWheelEvent>
#include <qmath.h>

#define MARGIN 5

CXPathView::CXPathView(QWidget* parent) : QWidget(parent)
{
	setMouseTracking(true);
	setFocusPolicy(Qt::StrongFocus);

	mScale = 1.0;

	setAutoFillBackground(true);

	QPalette p = palette();
	p.setColor(QPalette::Background, Qt::white);
	setPalette(p);

	mCellSize = 40;
	mIsFirstStart = false;
	mIsPositionVisible = false;
}

CXPathView::~CXPathView()
{

}

QRectF CXPathView::boundingRect()
{
	return mMainPath.boundingRect().united(mMovePath.boundingRect()).united(mBurnPath.boundingRect());
}

void CXPathView::load(const QString& aMainFile, const QString& aMoveFile)
{
	mBurnPath = QPainterPath();
	mBurnPath.moveTo(0, 0);

	mMovePath = QPainterPath();
	mMovePath.moveTo(0, 0);

	mMainPath = QPainterPath();
	mMainPath.moveTo(0, 0);

	QFile textFile(aMoveFile);
	if (textFile.open(QIODevice::ReadOnly))
	{
		textFile.readLine();
		textFile.readLine();
		textFile.readLine();

		fillPath(textFile, &mMovePath, &mBurnPath);

		textFile.close();
	}

	textFile.setFileName(aMainFile);

	if (textFile.open(QIODevice::ReadOnly))
	{
		textFile.readLine();
		textFile.readLine();
		textFile.readLine();

		fillPath(textFile, &mMainPath);

		textFile.close();
	}

	fitInView();
}

void CXPathView::fitInView()
{
	mScale = getFitScale(MARGIN);

	QSizeF formSize = size();
	formSize /= mScale;
	formSize = (boundingRect().size() - formSize) / 2.0;

	mCurPosition = boundingRect().topLeft() + QPointF(formSize.width(), formSize.height());

	update();
}

void CXPathView::zoomIn()
{
	qreal oldScale = mScale;
	setScale(mScale / 0.7);
/**/
	QPointF pos(width() / oldScale - width() / mScale, height() / oldScale - height() / mScale);
	mCurPosition += pos / 2.0;
/**/
	repaint();
}

void CXPathView::zoomOut()
{
	qreal oldScale = mScale;
	setScale(mScale * 0.7);
/**/
	QPointF pos(width() / oldScale - width() / mScale, height() / oldScale - height() / mScale);
	mCurPosition += pos / 2.0;
/**/
	repaint();
}

void CXPathView::setPositionVisible(bool aIsVisible)
{
	if (mIsPositionVisible != aIsVisible)
	{
		mIsPositionVisible = aIsVisible;

		update();
	}
}

void CXPathView::setPosition(const QPointF& aPos, bool aIsAbsolute)
{
	if (aIsAbsolute) mPos = aPos;
	else mPos += aPos;

	setPositionVisible(true);

	update();
}

void CXPathView::paintEvent(QPaintEvent* e)
{
	QWidget::paintEvent(e);

	QPainter painter;
	painter.begin(this);

	qreal cellSize = mCellSize;
	if (mScale > 1.0)
	{
		while (cellSize * mScale > 1.5 * mCellSize) cellSize /= 2;
	}
	else
	{
		while (cellSize * mScale < mCellSize / 1.5) cellSize *= 2;
	}

	QRectF visibleRect(mCurPosition, QSizeF(size()) / mScale);

	qreal left = cellSize * int(visibleRect.left() / cellSize);
	qreal top = cellSize * int(visibleRect.top() / cellSize);
	qreal right = cellSize * int(visibleRect.right() / cellSize + 1);
	qreal bottom = cellSize * int(visibleRect.bottom() / cellSize + 1);

	painter.setPen(QPen(Qt::black, 0, Qt::DotLine));

	QRect textRect(0, -mCurPosition.y() * mScale, mCellSize, mCellSize);
	qreal curX = 0;
	for (qreal x = left; x <= right; x += cellSize)
	{
		curX = x - mCurPosition.x();
		curX *= mScale;

		painter.drawLine(curX, 0, curX, height());
		textRect.moveTo(curX + 2, textRect.y());
		painter.drawText(textRect, QString("%1").arg(x), QTextOption(Qt::AlignTop | Qt::AlignLeft));
	}

	textRect.moveTo(-mCurPosition.x() * mScale + 2, 0);

	qreal curY = 0;
	for (qreal y = top; y <= bottom; y += cellSize)
	{
		curY = y - mCurPosition.y();
		curY *= mScale;

		painter.drawLine(0, curY, width(), curY);
		textRect.moveTo(textRect.x(), curY);
		painter.drawText(textRect, QString("%1").arg(y), QTextOption(Qt::AlignTop | Qt::AlignLeft));
	}

	painter.setRenderHint(QPainter::Antialiasing);

	painter.scale(mScale, mScale);
	painter.translate(-mCurPosition);

	painter.setPen(Qt::darkGreen);
	painter.drawPath(mMainPath);

	painter.setPen(Qt::red);
	painter.drawPath(mBurnPath);

	painter.setPen(Qt::blue);
	painter.drawPath(mMovePath);

	if (mIsPositionVisible)
	{
		painter.scale(1.0 / mScale, 1.0 / mScale);
		painter.setBrush(Qt::black);
		painter.setPen(Qt::black);
		painter.drawEllipse(mPos * mScale, 2, 2);
	}
}

void CXPathView::mousePressEvent(QMouseEvent* e)
{
	mOldPosition = e->pos();

	mDragPosition = mCurPosition;
}

void CXPathView::wheelEvent(QWheelEvent* e)
{
	qreal oldScale = mScale;
	mScale += e->delta() * mScale/1700;

	setScale(mScale);

	qreal dx = mCurPosition.x() - (e->pos().x() / mScale - e->pos().x() / oldScale);
	qreal dy = mCurPosition.y() - (e->pos().y() / mScale - e->pos().y() / oldScale);

	setOffset(QPointF(dx, dy));

	mDragPosition.setX(mCurPosition.x());
	mDragPosition.setY(mCurPosition.y());

	repaint();
}

void CXPathView::mouseMoveEvent(QMouseEvent* e)
{
	if (e->buttons() == Qt::LeftButton)
	{
		QPoint pos = e->pos();

		setOffset((mOldPosition - pos)/mScale + mDragPosition);

		repaint();
	}
}

void CXPathView::mouseReleaseEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton)
	{
		mDragPosition.setX(mCurPosition.x());
		mDragPosition.setY(mCurPosition.y());
			
		repaint();
	}
}

void CXPathView::mouseDoubleClickEvent(QMouseEvent* e)
{
/*
	if (e->button() == Qt::LeftButton)
	{
		fitInView();
	}
*/
}

void CXPathView::showEvent(QShowEvent* e)
{
	QWidget::showEvent(e);

	if (!mIsFirstStart)
	{
		fitInView();

		mIsFirstStart = true;
	}
}

void CXPathView::resizeEvent(QResizeEvent* e)
{
	QWidget::resizeEvent(e);
}

void CXPathView::fillPath(QFile& aTextFile, QPainterPath* aMainPath, QPainterPath* aBurnPath)
{
	QString buffer;
	int pos = 0;
	int command = 0;
	bool ok;
	QPointF curPoint(0, 0);

	QRegExp pattern("^(0x[^:]+:)(\\d+)");
	QRegExp oneFigures("(-?\\d+)");
	QRegExp twoFigures("(-?\\d+)(\\t+)(-?\\d+)");
	QRegExp fiveFigures("(-?\\d+)(\\t+)(-?\\d+)(\\t+)(-?\\d+)(\\t+)(-?\\d+)(\\t+)(-?\\d+)");

	QPainterPath* curPath = aMainPath;

	while (!aTextFile.atEnd())
	{
		buffer = aTextFile.readLine();

		if ((pos = pattern.indexIn(buffer)) >=0)
		{
			pos += pattern.matchedLength();

			command = pattern.cap(2).toInt(&ok);

			if (ok)
			{
				switch (command)
				{
					case E_Body:
					{
						break;
					}
					case E_FastLine:
					case E_Line:
					{
						if (twoFigures.indexIn(buffer, pos) >= 0)
						{
							if (aBurnPath == NULL)
							{
								if (curPath->elementCount() == 1 && curPath->elementAt(0).type == QPainterPath::MoveToElement)
									curPath->moveTo(QPointF(twoFigures.cap(3).toFloat() / 1000, twoFigures.cap(1).toFloat() / 1000) + curPoint);
								else curPath->lineTo(QPointF(twoFigures.cap(3).toFloat() / 1000, twoFigures.cap(1).toFloat() / 1000) + curPoint);
							}
							else curPath->lineTo(QPointF(twoFigures.cap(3).toFloat() / 1000, twoFigures.cap(1).toFloat() / 1000) + curPoint);

							curPoint = curPath->elementAt(curPath->elementCount() - 1);
						}

						break;
					}
					case E_TechnoCommand:
					{
						if (aBurnPath == NULL) continue;

						if (oneFigures.indexIn(buffer, pos) >= 0)
						{
							int res = oneFigures.cap(1).toInt();

							//начало реза
							if (res >= 3 && res <= 5)
							{
								aBurnPath->moveTo(curPoint);
								curPath = aBurnPath;
							}

							//конец реза
							if (res >= 6 && res <= 8)
							{
								aMainPath->moveTo(curPoint);
								curPath = aMainPath;
							}

							break;
						}

						break;
					}
					case E_Arc:
					{
						if (fiveFigures.indexIn(buffer, pos) >= 0)
						{
							int direction = fiveFigures.cap(1).toInt();

							QPointF centerPoint(fiveFigures.cap(9).toFloat() / 1000, -fiveFigures.cap(7).toFloat() / 1000);
							QPointF endPoint(fiveFigures.cap(5).toFloat() / 1000, -fiveFigures.cap(3).toFloat() / 1000);

							qreal radius = qMax(QLineF(centerPoint, endPoint).length(), QLineF(centerPoint, QPointF(0, 0)).length());

							qreal alphaEnd = qAcos((endPoint.x() - centerPoint.x()) / radius) * 180.0 / M_PI;
							qreal alphaTemp = qAsin((endPoint.y() - centerPoint.y()) / radius) * 180.0 / M_PI;

							//если синус дает отрицательный угол - значит угол идет в другую сторону
							if (alphaTemp < 0) alphaEnd = 360.0 - alphaEnd;

							qreal alphaStart = qAcos(-centerPoint.x() / radius) * 180.0 / M_PI;
							alphaTemp = qAsin(-centerPoint.y() / radius) * 180.0 / M_PI;

							//если синус дает отрицательный угол - значит угол идет в другую сторону
							if (alphaTemp < 0) alphaStart = 360.0 - alphaStart;

							qreal rotateAngle = alphaEnd - alphaStart;
							if (rotateAngle < 0) rotateAngle += 360;

							//по часовой
							if (direction == 1)
							{
								rotateAngle = rotateAngle - 360.0;
							}

							centerPoint.setY(-centerPoint.y());

							curPath->arcTo(QRectF(centerPoint - QPointF(radius, radius) + curPoint, QSizeF(2 * radius, 2 * radius)), alphaStart, rotateAngle);
							curPoint = curPath->elementAt(curPath->elementCount() - 1);

							break;
						}

						break;
					}
				}
			}
		}
	}
}

void CXPathView::setScale(qreal aScale)
{
	qreal scale = getFitScale();
	qreal minScale = qMin(1.0, scale / 3.0);
	qreal maxScale = 20.0;

	mScale = aScale;

	if (mScale < minScale) mScale = minScale;
	if (mScale > maxScale) mScale = maxScale;
}

void CXPathView::setOffset(const QPointF& aPos)
{
	mCurPosition = aPos;

	QRectF bound = boundingRect();
	bound.adjust(-MARGIN, -MARGIN, MARGIN, MARGIN);
/*
	if (mCurPosition.x() + width() / mScale > bound.right()) mCurPosition.setX(bound.right() - width()  / mScale);
	if (mCurPosition.y() + height() / mScale > bound.bottom()) mCurPosition.setY(bound.bottom() - height() / mScale);

	if (mCurPosition.x() < bound.x()) mCurPosition.setX(bound.x());
	if (mCurPosition.y() < bound.y()) mCurPosition.setY(bound.y());
*/
}

qreal CXPathView::getFitScale(qreal aMargin)
{
	QSizeF s = boundingRect().size();

	if (s.width() <= 0 || s.height() <= 0) return 1;

	return qMin((width() - 2.0 * aMargin) / s.width(), (height() - 2.0 * aMargin) / s.height());
}
