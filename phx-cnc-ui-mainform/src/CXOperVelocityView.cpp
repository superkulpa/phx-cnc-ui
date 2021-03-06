#include "CXOperVelocityView.h"

#include <QPainter>
#include <QMouseEvent>

#include "utils/CXSettingsXML.h"

int CXOperVelocityView::mDelay = 0;

CXOperVelocityView::CXOperVelocityView(QWidget* parent) :
    QWidget(parent)
{
  mMode = E_Accumulate;
  mVelocity = E_Normal;

  mDelayTimer = -1;
  if (mDelay == 0)
    mDelay = CXSettingsXML::getDelay("settings.xml", "delay");

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

CXOperVelocityView::~CXOperVelocityView()
{

}

void
CXOperVelocityView::setMode(eVelocityMode aMode)
{
  mMode = aMode;
  update();
}

void
CXOperVelocityView::setTexts(const QList<QString>& aTexts)
{
  mTexts = aTexts;
  update();
}

void
CXOperVelocityView::setVelocity(eVelocity aVelocity)
{
  if (mVelocity != aVelocity)
  {
    mVelocity = aVelocity;

    update();
  }
}

void
CXOperVelocityView::paintEvent(QPaintEvent*)
{
  qreal scaleX = width() / mDrawPath.boundingRect().width();
  qreal scaleY = height() / mDrawPath.boundingRect().height();

  QPainter painter;
  painter.begin(this);
  painter.scale(scaleX, scaleY);
  painter.setRenderHint(QPainter::Antialiasing);

  painter.setPen(Qt::DotLine);

  switch (mMode)
  {
  case E_Accumulate:
    {
    painter.fillRect(mPathList.at(mPathList.count() - mVelocity - 1), QColor(0, 255, 0, 200)); //QColor(0, 255, 0, 200 - (mPathList.count() - mVelocity) * 40)

    break;
  }
  case E_SingleMode:
    {
    painter.fillRect(mPathList.at(mPathList.count() - mVelocity - 1), QColor(0, 255, 0, 200));

    break;
  }
  }

  painter.setFont(QFont(font().family(), 6 * scaleY));
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

void
CXOperVelocityView::timerEvent(QTimerEvent* e)
{
  if (e->timerId() == mDelayTimer)
  {
    killTimer(mDelayTimer);
    mDelayTimer = -1;

    QPointF pos = mapFromGlobal(QCursor::pos());

    qreal scaleX = width() / mDrawPath.boundingRect().width();
    qreal scaleY = height() / mDrawPath.boundingRect().height();

    updateVelocity(QPointF(pos.x() / scaleX, pos.y() / scaleY));
  }
}

void
CXOperVelocityView::mousePressEvent(QMouseEvent* e)
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
CXOperVelocityView::mouseReleaseEvent(QMouseEvent* e)
{
  if (mDelayTimer != -1)
  {
    killTimer(mDelayTimer);
    mDelayTimer = -1;
  }

  if (e->button() == Qt::LeftButton && mMode == E_SingleMode)
  {
    setCurrentVelocity(E_Normal);
  }
}

void
CXOperVelocityView::mouseMoveEvent(QMouseEvent* e)
{
  if (mDelayTimer == -1)
  {
    QPointF pos = e->posF();

    qreal scaleX = width() / mDrawPath.boundingRect().width();
    qreal scaleY = height() / mDrawPath.boundingRect().height();

    updateVelocity(QPointF(pos.x() / scaleX, pos.y() / scaleY));
  }
}

void
CXOperVelocityView::updateVelocity(const QPointF& aPos)
{
  for (int i = 0; i < mPathList.count(); ++i)
  {
    if (mPathList.at(i).contains(aPos))
    {
      setCurrentVelocity(eVelocity(mPathList.count() - i - 1));
      break;
    }
  }
}

void
CXOperVelocityView::setCurrentVelocity(eVelocity aVelocity)
{
  if (mVelocity != aVelocity)
  {
//		mVelocity = aVelocity;

    emit velocityChanged(aVelocity);

//		update();
  }
}
