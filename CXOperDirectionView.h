#ifndef CXOperDIRECTIONVIEW_H
#define CXOperDIRECTIONVIEW_H

#include <QWidget>

#include <QPainterPath>
#include "CXOperVelocityView.h"

namespace OperDirectionView
{
  //! Перечисление возможных значений направления реза.
/*
  enum eMoveDirection
  {
    E_Stop = 0,
    E_Top,
    E_TopLeft,
    E_Left,
    E_BottomLeft,
    E_Bottom,
    E_BottomRight,
    E_Right,
    E_TopRight,
	E_NoDirection = 100
  };
*/
  enum eMoveDirection
  {
    E_Stop = 0,
    E_Top = 1,
    E_Left = 2,
    E_Bottom = 4,
    E_Right = 8,
    E_TopLeft = E_Top | E_Left,
    E_BottomLeft = E_Bottom | E_Left,
    E_BottomRight = E_Bottom | E_Right,
    E_TopRight = E_Top | E_Right,
	E_NoDirection = 100
  };
}

//! Перечисление типов для отображения направления.
enum eDirectionViewTypes
{
	E_Circle,
	E_Fingers
};

/*!
 Класс настройки направления реза.
 */
class CXOperDirectionView : public QWidget
{
Q_OBJECT

public:
  //! Конструктор.
  CXOperDirectionView(QWidget* parent = 0, eDirectionViewTypes aType = E_Circle);

  //! Деструктор.
  virtual ~CXOperDirectionView();

  //! Функция установки направления реза.
  void
  setDirection(OperDirectionView::eMoveDirection aDirection);

  //! Функция установки направления и скорости реза.
  void
  setDirection(OperDirectionView::eMoveDirection aDirection, eVelocity aVelocity);

signals:
  //! Сигнал на изменение направления.
  void
  directionChanged(OperDirectionView::eMoveDirection aDirection);

  //! Сигнал на изменение направления и скорости.
  void
  directionChanged(OperDirectionView::eMoveDirection aDirection, eVelocity aVelocity);

protected:
  //! Переопределенная фукнция рисования.
  virtual void
  paintEvent(QPaintEvent* e);

  //! Переопределенная функция событий таймера.
  virtual void
  timerEvent(QTimerEvent* e);

  //! Переопределенная фукнция обработки нажатия кнопки мышки.
  virtual void
  mousePressEvent(QMouseEvent* e);

  //! Переопределенная фукнция обработки отпускания кнопки мышки.
  virtual void
  mouseReleaseEvent(QMouseEvent* e);

  //! Переопределенная фукнция обработки движения мышки.
  virtual void
  mouseMoveEvent(QMouseEvent* e);

private:
  //! Создание вьювера в виде одного круга с секторами.
  void createCircleType();

  //! Создание вьювера в виде 4х точек для пальцев.
  void createFingersType();

  //! Функция расчета направления по индексу сектора.
  OperDirectionView::eMoveDirection getDirection(int index);

  //! Функция расчета скорости по индексу сектора.
  eVelocity getVelocity(int index);

  /*!
   Функция установки направления по координатам.

   \param aPos - позиция курсора.
   \param aIsMousePress - флаг, что функция была вызвана по нажатию мышки.
   */
  void
  updateDirection(const QPointF& aPos, bool aIsMousePress);

  //! Функция обновления интерфейса по измененным направлению или скорости (установка нужной подсвеченной области).
  void
  updatePaintDirection();

private:
  static int mDelay;
  int mDelayTimer;

  eDirectionViewTypes mType;

  QList<QPainterPath> mPathList;
  QPainterPath mDrawPath;
  QPainterPath mArrowPath;

  QList <QPainterPath> mFingersList;
  QList <QPainterPath> mArrowList;
  QList <QPainterPath> mFingersArrowList;
  QList <QPainterPath> mDirectionPathList;
  //Список направлений для каждого сектора.
  QList <OperDirectionView::eMoveDirection> mDirectionList;
  QList <QPainterPath> mDrawist;

  QRectF mBound;

  int mCurrentFinger;
  int mCurrentDirection;
  OperDirectionView::eMoveDirection mDirection;
  eVelocity mVelocity;
};

#endif // CXOperDIRECTIONVIEW_H
