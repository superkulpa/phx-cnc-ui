#include "CXVirtualKeyboardNum.h"

#include <QKeyEvent>

CXVirtualKeyboardNum::CXVirtualKeyboardNum(int _index) :
    AXBaseWindow()
{
  setupUi(this);
  setGroupNumber(-1);
  index = _index;
  mFocusedWidget = NULL;

  setFocusPolicy(Qt::NoFocus);
  setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
  setAttribute(Qt::WA_GroupLeader);

  installEventFilter(this);

  connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this,
      SLOT(onFocusChange(QWidget*, QWidget*)));
  connect(mCloseButton, SIGNAL(clicked()), this, SLOT(onHide()));

  QList<QAbstractButton*> buttonList = mLiteralGroup->buttons();

  for (int i = 0; i < buttonList.count(); ++i)
  {
    connect(buttonList.at(i), SIGNAL(clicked()), this, SLOT(onButtonClick()));
  }

  registerManager();
}

CXVirtualKeyboardNum::~CXVirtualKeyboardNum()
{

}

void
CXVirtualKeyboardNum::mouseReleaseEvent(QMouseEvent* e)
{
  AXBaseWindow::mouseReleaseEvent(e);
}

void
CXVirtualKeyboardNum::onFocusChange(QWidget* old, QWidget* now)
{
  Q_UNUSED(old)
    if(index != 2) return;

  if (now != 0 && !isAncestorOf(now))
  {
    mFocusedWidget = now;
    if (now->property("readOnly").isValid() && now->property("readOnly").toBool() == false)
    {
      QObject* w = now;
      while (w->parent() != NULL)
        w = w->parent();

      if (w->metaObject()->className() == QString("CXParametersWindow"))
      {
        show();
      }
      else
        hide();
    }
    else
      hide();
  }
}

void
CXVirtualKeyboardNum::onButtonClick()
{
  QAbstractButton* button = qobject_cast<QAbstractButton*>(sender());

  if (button != NULL && !button->shortcut().isEmpty())
  {
    if (mFocusedWidget == NULL)
      return;

    //mFocusedWidget->activateWindow();

    int keyCode = button->shortcut()[0];

    QKeyEvent keyPress(QEvent::KeyPress, keyCode, Qt::NoModifier, button->shortcut().toString());
    QApplication::sendEvent(mFocusedWidget, &keyPress);

    QKeyEvent keyRelease(QEvent::KeyRelease, keyCode, Qt::NoModifier,
        button->shortcut().toString());
    QApplication::sendEvent(mFocusedWidget, &keyRelease);

    return;
  }
}

void
CXVirtualKeyboardNum::onHide()
{
  disconnect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this,
      SLOT(onFocusChange(QWidget*, QWidget*)));
  hide();
  QApplication::processEvents();
  connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this,
      SLOT(onFocusChange(QWidget*, QWidget*)));
}
