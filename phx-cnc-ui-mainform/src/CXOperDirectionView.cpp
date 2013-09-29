#include "CXOperDirectionView.h"

#include <QPainter>
#include <QMouseEvent>
#include <QRadialGradient>
#include <qmath.h>

#include "CXSettingsXML.h"

#define FINGER_RADIUS 10.0
#define RADIUS 18.0
int CXOperDirectionView::mDelay = 0;

CXOperDirectionView::CXOperDirectionView(QWidget* parent, eDirectionViewTypes aType) :
    QWidget(parent)
{
  mType = aType;
  if (mType > E_Fingers) mType = E_Fingers;
  mVelocity = E_NoVelocity;
  mDirection = OperDirectionView::E_Stop;

  mDelayTimer = -1;
  mCurrentFinger = -1;
  mCurrentDirection = -1;

  if (mDelay == 0)
    mDelay = CXSettingsXML::getDelay("settings.xml", "delay");

  switch (mType)
  {
    case E_Circle:
    {
      createCircleType();
      break;
	}
	case E_Fingers:
    {
      createFingersType();
      break;
	}
  }
}

CXOperDirectionView::~CXOperDirectionView()
{

}

void
CXOperDirectionView::setDirection(OperDirectionView::eMoveDirection aDirection)
{
  if (mDirection == aDirection)
    return;

  mDirection = aDirection;
  if (mDirection == OperDirectionView::E_Stop)
  {
	  mCurrentDirection = -1;
  }

  emit directionChanged(mDirection);

//  updatePaintDirection();
  update();
}

void
CXOperDirectionView::setDirection(OperDirectionView::eMoveDirection aDirection, eVelocity aVelocity)
{
  if (mDirection == aDirection && mVelocity == aVelocity)
    return;

  mDirection = aDirection;
  mVelocity = aVelocity;
  if (mDirection == OperDirectionView::E_Stop)
  {
	  mCurrentDirection = -1;
	  emit directionChanged(mDirection, E_Normal);
  }
  else emit directionChanged(mDirection, mVelocity);

  updatePaintDirection();
  update();
}

void
CXOperDirectionView::paintEvent(QPaintEvent*)
{
  qreal scale = qMin(width() / mBound.width(),
      height() / mBound.height());

  QPainter painter;
  painter.begin(this);
  painter.scale(scale, scale);
  painter.setRenderHint(QPainter::Antialiasing);

  switch (mType)
  {
    case E_Circle:
	{
	  painter.setPen(QPen(Qt::black, 0, Qt::DotLine));

	  for (int i = 1; i < 5; ++i)
	  {
		painter.fillPath(mPathList.at(i * 2), QColor(0, 255, 0, 15));
	  }

	//	if (mDirection != OperDirectionView::E_Stop)
	  {
		QRadialGradient radialGradient(50, 50, 50);
		radialGradient.setColorAt(0, Qt::green);
		radialGradient.setColorAt(0.5, Qt::green);
		radialGradient.setColorAt(1, QColor(0, 255, 0, 100));

		painter.fillPath(mPathList.at(mDirection), radialGradient);
	  }

	//	for (int i = 0; i < mPathList.count(); ++i) painter.drawPath(mPathList.at(i));
	  painter.drawPath(mDrawPath);

	  painter.translate(50, 50);

	  for (int i = 0; i < 8; i++)
	  {
		painter.rotate(45.0);
		painter.fillPath(mArrowPath, QColor(0, 0, 0, 100));
	  }

	  painter.translate(-50, -50);

	  painter.scale(1.0 / scale, 1.0 / scale);

	  painter.setFont(QFont(font().family(), 6 * scale));

	  QTextOption textOption;
	  textOption.setAlignment(Qt::AlignCenter);
	  painter.drawText(
		  QRectF((50.0 - RADIUS) * scale, (50.0 - RADIUS) * scale, 2.0 * RADIUS * scale,
			  2.0 * RADIUS * scale), trUtf8("стоп"), textOption);

      break;
	}
    case E_Fingers:
	{
	  QPainterPath tempPath;
	  if (mCurrentFinger < 0)
	  foreach (tempPath, mArrowList)
	  {
		  painter.fillPath(tempPath, QColor(0, 0, 0, 100));
	  }
/**/
	  painter.setPen(QPen(Qt::black, 0, Qt::DotLine));
	  painter.setBrush(Qt::NoBrush);
	  if (mCurrentFinger >= 0) painter.drawPath(mDrawist.at(mCurrentFinger));
/*
	  for (int i = 0; i < mDirectionPathList.count(); i++)
	  {
		  if (i >= mCurrentFinger * 9 && i < (mCurrentFinger + 1) * 9) painter.drawPath(mDirectionPathList.at(i));
	  }
/**/
	  painter.setPen(QPen(Qt::black, 0, Qt::SolidLine));
	  painter.setBrush(Qt::gray);

	  if (mCurrentFinger >= 0) painter.setOpacity(0.2);
	  
	  for (int i = 0; i < mFingersList.count(); i++)
	  {
		  if (i == mCurrentFinger) continue;

		  painter.drawPath(mFingersList.at(i));
	  }
	  
	  painter.setOpacity(1.0);

	  if (mCurrentDirection >= 0)
	  {
		  painter.fillPath(mDirectionPathList.at(mCurrentDirection), Qt::green);
	  }

	  if (mCurrentFinger >= 0) painter.drawPath(mFingersList.at(mCurrentFinger));

	  for (int i = 0; i < mFingersArrowList.count(); i++)
	  {
		  if (i >= mCurrentFinger * 3 && i < (mCurrentFinger + 1) * 3) painter.fillPath(mFingersArrowList.at(i), QColor(0, 0, 0, 100));
	  }

	  break;
	}
  }

  painter.end();
}

void
CXOperDirectionView::timerEvent(QTimerEvent* e)
{
  if (e->timerId() == mDelayTimer)
  {
    killTimer(mDelayTimer);
    mDelayTimer = -1;

    QPointF pos = mapFromGlobal(QCursor::pos());

    qreal scale = qMin(width() / mBound.width(),
        height() / mBound.height());

    updateDirection(pos / scale, true);
  }
}

void
CXOperDirectionView::mousePressEvent(QMouseEvent* e)
{
  if (e->button() == Qt::LeftButton)
  {
    if (mDelayTimer != -1)
    {
      killTimer(mDelayTimer);
      mDelayTimer = -1;
    }

    mDelayTimer = startTimer(mDelay);
  }
}

void
CXOperDirectionView::mouseReleaseEvent(QMouseEvent*)
{
  if (mDelayTimer != -1)
  {
    killTimer(mDelayTimer);
    mDelayTimer = -1;
  }
  else
  {
    mCurrentFinger = -1;

	if (mType == E_Circle) setDirection(OperDirectionView::E_Stop);
	else setDirection(OperDirectionView::E_Stop, E_NoVelocity);

	update();
  }
}

void
CXOperDirectionView::mouseMoveEvent(QMouseEvent* e)
{
  if (mDelayTimer == -1)
  {
    QPointF pos = e->pos();

    qreal scale = qMin(width() / mBound.width(),
        height() / mBound.height());

    updateDirection(pos / scale, false);
  }
}

void
CXOperDirectionView::createCircleType()
{
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
/**/
  for (int i = 0; i < 8; ++i)
  {
    x = 50.0 * qCos((67.5 + 45.0 * i) * M_PI / 180.0) + 50.0;
    y = 50.0 * qSin((67.5 + 45.0 * i) * M_PI / 180.0) + 50.0;

    mDrawPath.moveTo(x, y);

    x = RADIUS * qCos((67.5 + 45.0 * i) * M_PI / 180.0) + 50.0;
    y = RADIUS * qSin((67.5 + 45.0 * i) * M_PI / 180.0) + 50.0;

    mDrawPath.lineTo(x, y);
  }

  mDrawPath.addEllipse(0, 0, 100, 100);
  mDrawPath.addEllipse(QPointF(50, 50), RADIUS, RADIUS);

  mArrowPath.moveTo(5 + 0, 15 - 50);
  mArrowPath.lineTo(0 + 0, 5 - 50);
  mArrowPath.lineTo(-5 + 0, 15 - 50);
  mArrowPath.lineTo(5 + 0, 15 - 50);

  mBound = mDrawPath.boundingRect();
}

void
CXOperDirectionView::createFingersType()
{
  qreal x = 0;
  qreal y = 0;

  //Формирование круга под палец.
  QPainterPath mFingerPath;
  QPointF center(FINGER_RADIUS, 50.0);
  mFingerPath.addEllipse(center, FINGER_RADIUS, FINGER_RADIUS);
  mFingersList << mFingerPath;
  mBound = mFingerPath.boundingRect();

  //Формирование стрелки направления.
  mArrowPath.moveTo(-5, -5);
  mArrowPath.lineTo(5, 0);
  mArrowPath.lineTo(-5, 5);
  mArrowPath.closeSubpath();

  mArrowList << QTransform().translate(32, 50).map(mArrowPath);

  mFingerPath = QPainterPath();

  mDirectionList << OperDirectionView::E_TopRight << OperDirectionView::E_Right << OperDirectionView::E_BottomRight <<
					OperDirectionView::E_BottomLeft << OperDirectionView::E_Left << OperDirectionView::E_TopLeft <<
					OperDirectionView::E_BottomRight << OperDirectionView::E_Bottom << OperDirectionView::E_BottomLeft <<
					OperDirectionView::E_TopLeft << OperDirectionView::E_Top << OperDirectionView::E_TopRight;

  QSize cellSize(24, 30);
  qreal startAngle = -55.0 * M_PI / 180.0;
  qreal inclination = -75 * M_PI / 180.0;
  qreal inclWidth = cellSize.height() * qTan(M_PI / 2.0 - qAbs(inclination));

  QPointF lastPoint;
  QPainterPath drawPath;

  //Формирование сетки направления и скорости.
  for (int r = 0; r < 3; r++)
  {
	  if (r == 2) inclination *= -1;

	  for (int i = 0; i < 3; i++)
	  {
		  if (i == 0)
		  {
			  x = 2.0 * center.x();
			  y = center.y() - (r == 2? -0.5 : 0.5) * cellSize.height();

			  QTransform transform;
			  transform = transform.translate(x + ((r==1?0:inclWidth) + cellSize.width()) / 2.0, center.y() - cellSize.height() * (1.0 - r));
			  if (r != 1) transform = transform.rotate(r == 0?-35.0:35.0);

			  drawPath.moveTo(QPointF(x, y));
			  mFingersArrowList << transform.map(mArrowPath);
		  }
		  else
		  {
			  x = lastPoint.x();
			  y = lastPoint.y();
		  }

		  mFingerPath.moveTo(QPointF(x, y));

		  if (r == 1)
		  {
			  if (i == 0)
			  {
				  drawPath.moveTo(QPointF(FINGER_RADIUS * qCos(startAngle), FINGER_RADIUS * qSin(startAngle)) + center);
				  drawPath.lineTo(QPointF(x, y));
				  mFingerPath.moveTo(QPointF(FINGER_RADIUS * qCos(startAngle), FINGER_RADIUS * qSin(startAngle)) + center);
				  mFingerPath.lineTo(QPointF(x, y));
			  }
			  else
			  {
				  y -= cellSize.height();
				  mFingerPath.lineTo(QPointF(x, y));
			  }

			  x += cellSize.width();

			  drawPath.moveTo(QPointF(x, y));
			  mFingerPath.lineTo(QPointF(x, y));

			  y += cellSize.height();

			  lastPoint = QPointF(x, y);
			  drawPath.lineTo(lastPoint);
			  mFingerPath.lineTo(lastPoint);

			  if (i == 0)
			  {
				  lastPoint = QPointF(x, y);
				  
				  x -= cellSize.width();

				  drawPath.moveTo(QPointF(x, y));
				  drawPath.lineTo(QPointF(FINGER_RADIUS * qCos(-startAngle), FINGER_RADIUS * qSin(-startAngle)) + center);

				  mFingerPath.lineTo(QPointF(x, y));
				  mFingerPath.lineTo(QPointF(FINGER_RADIUS * qCos(-startAngle), FINGER_RADIUS * qSin(-startAngle)) + center);
			  }
		  }
		  else
		  {
			  x = qAbs(cellSize.height() / qSin(inclination)) * qCos(inclination) + x;
			  y = qAbs(cellSize.height() / qSin(inclination)) * qSin(inclination) + y;

			  mFingerPath.lineTo(QPointF(x, y));
			  if (i == 0)
			  {
				  drawPath.lineTo(QPointF(x, y));
			  }

			  x += cellSize.width();

			  mFingerPath.lineTo(QPointF(x, y));
			  drawPath.moveTo(QPointF(x, y));

			  x -= inclWidth;

			  if (inclination > 0) y -= cellSize.height();
			  else y += cellSize.height();

			  lastPoint = QPointF(x, y);

			  drawPath.lineTo(lastPoint);
			  mFingerPath.lineTo(lastPoint);
		  }

		  mFingerPath.closeSubpath();

		  mDirectionPathList << mFingerPath;
		  mFingerPath = QPainterPath();
	  }

	  int count = drawPath.elementCount();
	  if (r == 1)
	  {
		  drawPath.moveTo(drawPath.elementAt(count - 9));
		  drawPath.lineTo(drawPath.elementAt(count - 2));
		  drawPath.moveTo(drawPath.elementAt(count - 1));
		  drawPath.lineTo(drawPath.elementAt(count - 6));
	  }
	  else
	  {
		  drawPath.moveTo(drawPath.elementAt(count - 7));
		  drawPath.lineTo(drawPath.elementAt(count - 2));
	  }
  }

  mDrawist << drawPath;

  //список углов, чтобы сначала была левая точка, потом правая, затем остальные.
  //Чтобы при изменении направления или скорости поиск был по порядку, сначала слева, потом справа, затем в остальных точках.
  QList <qreal> anglesList;
  anglesList << 180 << 90 << 270;

  int directionListCount = mDirectionPathList.count();
  int drawistCount = mDrawist.count();
  int arrowCount = mFingersArrowList.count();
  for (int i = 0; i < 3; i++)
  {
	  QTransform transform;
	  transform.translate(50, 50);
	  transform.rotate(anglesList.at(i));
	  transform.translate(-50, -50);

	  mFingersList << transform.map(mFingersList.at(0));
	  mBound = mBound.united(mFingersList.last().boundingRect());

	  mArrowList << transform.map(mArrowList.at(0));
	  for (int c = 0; c < directionListCount; c++) mDirectionPathList << transform.map(mDirectionPathList.at(c));
	  for (int c = 0; c < drawistCount; c++) mDrawist << transform.map(mDrawist.at(c));
	  for (int c = 0; c < arrowCount; c++) mFingersArrowList << transform.map(mFingersArrowList.at(c));
  }
}

OperDirectionView::eMoveDirection CXOperDirectionView::getDirection(int index)
{
	return mDirectionList.at(index / 3);
}

eVelocity CXOperDirectionView::getVelocity(int index)
{
	return eVelocity(index % 3);
}

void
CXOperDirectionView::updateDirection(const QPointF& aPos, bool aIsMousePress)
{
  if (mType == E_Circle)
  {
    for (int i = 0; i < mPathList.count(); ++i)
    {
      if (mPathList.at(i).contains(aPos))
      {
        setDirection(OperDirectionView::eMoveDirection(i));
        break;
      }
    }

    return;
  }

  if (mType == E_Fingers)
  {
    if (mCurrentFinger >= 0)
    {
  	  if (aIsMousePress && mFingersList.at(mCurrentFinger).contains(aPos))
  	  {
  		  mCurrentFinger = -1;
  		  setDirection(OperDirectionView::E_Stop);
  		  update();
  		  return;
  	  }
  
  	  if (mFingersList.at(mCurrentFinger).contains(aPos))
  	  {
  		  setDirection(OperDirectionView::E_Stop);
  		  update();
  		  return;
  	  }
  
	  //если текущий сектор не изменился.
	  if (mCurrentDirection >= 0 && mDirectionPathList.at(mCurrentDirection).contains(aPos) && mCurrentDirection >= mCurrentFinger * 9 && mCurrentDirection < (mCurrentFinger + 1) * 9) return;
  
  	  for (int i = 0; i < mDirectionPathList.count(); i++)
  	  {
  		  if (mDirectionPathList.at(i).contains(aPos) && i >= mCurrentFinger * 9 && i < (mCurrentFinger + 1) * 9)
  		  {
			  mCurrentDirection = i;
  			  setDirection(getDirection(i), getVelocity(i));
  
  			  return;
  		  }
  	  }
    }

	mCurrentDirection = -1;

    if (aIsMousePress)
    for (int i = 0; i < mFingersList.count(); i++)
    {
  	  if (mFingersList.at(i).contains(aPos))
  	  {
  		  mCurrentFinger = i;
  		  update();
  		  return;
  	  }
    }

	return;
  }
}

void
CXOperDirectionView::updatePaintDirection()
{
  //если установлены правильное направление и скорость - не производить перерасчет.
  if (mCurrentFinger >= 0 && mCurrentDirection >= 0 && getVelocity(mCurrentDirection) == mVelocity && getDirection(mCurrentDirection) == mDirection) return;
  if (mDirection == OperDirectionView::E_Stop && mCurrentDirection == -1) return;

  int startIndex = qMax(0, mCurrentFinger * 3);
  int count = mCurrentFinger < 0 ? mDirectionList.count() : startIndex + 3;
  if (mCurrentFinger >= 0) startIndex = mCurrentFinger * 9;

  for (int i = startIndex; i < count; i++)
  {
    if (mDirectionList.at(i) == mDirection)
	{
      mCurrentFinger = i / 3;
	  mCurrentDirection = i * 3 + mVelocity;
      return;
	}
  }

  for (int i = 0; i < mDirectionList.count(); i++)
  {
    if (mDirectionList.at(i) == mDirection)
	{
      mCurrentDirection = i * mVelocity;
      return;
	}
  }

  mCurrentDirection = -1;
}
