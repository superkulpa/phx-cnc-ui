#ifndef CXVIRTUALKEYBOARDNUM_H
#define CXVIRTUALKEYBOARDNUM_H

#include "AXBaseWindow.h"

#include "ui_CXVirtualKeyboardNum.h"

class CXVirtualKeyboardNum : public AXBaseWindow, public Ui::CXVirtualKeyboardNum
{
Q_OBJECT
int index;
public:
  CXVirtualKeyboardNum(int index = 0);
  virtual ~CXVirtualKeyboardNum();

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

private:
  QWidget* mFocusedWidget;
};

#endif // CXVIRTUALKEYBOARD_H
