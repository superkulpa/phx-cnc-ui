#ifndef CXVIRTUALKEYBOARD_H
#define CXVIRTUALKEYBOARD_H

#include "AXBaseWindow.h"

#include "ui_CXVirtualKeyboard.h"

class CXVirtualKeyboard : public AXBaseWindow, public Ui::CXVirtualKeyboard
{
Q_OBJECT

public:
  CXVirtualKeyboard();
  virtual ~CXVirtualKeyboard();

protected:
  virtual void
  mouseReleaseEvent(QMouseEvent* e);

private slots:
  //!
  void
  onFocusChange(QWidget* old, QWidget* now);

  //!
  void
  onButtonClick();

  void
  onHide();

  void
  onDelete();

private:
  QWidget* mFocusedWidget;
  QVector <QString> mAcceptWindow;
};

#endif // CXVIRTUALKEYBOARD_H
