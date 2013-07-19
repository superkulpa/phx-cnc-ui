#ifndef CXOperDIRECTIONVIEW_H
#define CXOperDIRECTIONVIEW_H

#include <QWidget>

#include <QPainterPath>

namespace OperDirectionView
{
  //! Перечисление возможных значений направления реза.
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
    E_TopRight
  };
}

/*!
 Класс настройки направления реза.
 */
class CXOperDirectionView : public QWidget
{
Q_OBJECT

public:
  //! Конструктор.
  CXOperDirectionView(QWidget* parent = 0);

  //! Деструктор.
  virtual ~CXOperDirectionView();

  //! Функция установки направления реза.
  void
  setDirection(OperDirectionView::eMoveDirection aDirection);

signals:
  //! Сигнал на изменение направления.
  void
  directionChanged(OperDirectionView::eMoveDirection aDirection);

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
  /*!
   Функция установки направления по координатам.

   \param aPos - позиция курсора.
   */
  void
  updateDirection(const QPointF& aPos);

private:
  static int mDelay;
  int mDelayTimer;

  QList<QPainterPath> mPathList;
  QPainterPath mDrawPath;
  QPainterPath mArrowPath;
  OperDirectionView::eMoveDirection mDirection;
};

#endif // CXOperDIRECTIONVIEW_H
