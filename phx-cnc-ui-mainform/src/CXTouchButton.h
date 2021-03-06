#ifndef CXTOUCHBUTTON_H
#define CXTOUCHBUTTON_H

#include <QPushButton>
#include <QTime>

/*!
 Класс кнопки для учета антидребезга.
 */
class CXTouchButton : public QPushButton
{
Q_OBJECT

public:
  CXTouchButton(QWidget* parent);
  CXTouchButton(const QString& text, QWidget* parent);
  virtual ~CXTouchButton();

  //! Функция установки флага, использовать ли зажатие кнопки или сразу отжимать кнопку после нажатия.
  void setLongPress(bool aIsLongPress);

  //! Функция установки флага, нужно ли различать короткое и длинное нажатие.
  void SetNeedFirstEvent(bool aNeedFirstEvent);
signals:
  void onFirstEvent();

protected:
  //! Переопределенная фукнция рисования.
  virtual void
  paintEvent(QPaintEvent* e);

  //! Переопределенная фукнция обработки нажатия кнопки мышки.
  virtual void
  mousePressEvent(QMouseEvent* e);

  //! Переопределенная фукнция обработки отпускания кнопки мышки.
  virtual void
  mouseReleaseEvent(QMouseEvent* e);

  //! Переопределенная функция событий таймера.
  virtual void
  timerEvent(QTimerEvent* e);

private:
  QTime mTime;
  int mTimer;
  bool mIsLongPress;
  bool needFirstEvent;
public:
  static int mDelay;
  static int mDelayLong;
};

#endif // CXTOUCHBUTTON_H
