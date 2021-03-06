#include "CXVirtualKeyboard.h"

#include <QKeyEvent>
#include <QtCore/QtCore>

CXVirtualKeyboard::CXVirtualKeyboard() :
    AXBaseWindow()
{
  setupUi(this);
  setGroupNumber(-1);

  mFocusedWidget = NULL;

  setFocusPolicy(Qt::NoFocus);
  setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
  setAttribute(Qt::WA_GroupLeader);
  setAttribute(Qt::WA_ShowWithoutActivating);

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

  mAcceptWindow << "CXEditPathFile" << "CXParametersWindow" << "CXIniFileEditor" << "CXFilesList";
}

CXVirtualKeyboard::~CXVirtualKeyboard()
{

}

void
CXVirtualKeyboard::mouseReleaseEvent(QMouseEvent* e)
{
  AXBaseWindow::mouseReleaseEvent(e);
}

void
CXVirtualKeyboard::onFocusChange(QWidget* old, QWidget* now)
{
  Q_UNUSED(old)
  if (now != 0 && !isAncestorOf(now))
  {
    if (mFocusedWidget != NULL) disconnect(mFocusedWidget, SIGNAL(destroyed()), this, SLOT(onDelete()));
    mFocusedWidget = now;
    connect(mFocusedWidget, SIGNAL(destroyed()), this, SLOT(onDelete()));

    if (now->property("readOnly").isValid() && now->property("readOnly").toBool() == false)
    {
      QWidget* w = now;
      while (w->parentWidget() != NULL)
	w = w->parentWidget();

      //qDebug() << w->metaObject()->className();
      if (mAcceptWindow.contains(w->metaObject()->className()))
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
CXVirtualKeyboard::onButtonClick()
{
  QAbstractButton* button = qobject_cast<QAbstractButton*>(sender());

  if (button != NULL && !button->shortcut().isEmpty())
  {
    if (mFocusedWidget == NULL)
      return;

    mFocusedWidget->activateWindow();

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
CXVirtualKeyboard::onHide()
{
  disconnect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this,
      SLOT(onFocusChange(QWidget*, QWidget*)));
  hide();
  QApplication::processEvents();
  connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this,
      SLOT(onFocusChange(QWidget*, QWidget*)));
}

void
CXVirtualKeyboard::onDelete()
{
	mFocusedWidget = NULL;
}
