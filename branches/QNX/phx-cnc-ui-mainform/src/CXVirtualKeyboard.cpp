#include "CXVirtualKeyboard.h"

#include <QKeyEvent>

CXVirtualKeyboard::CXVirtualKeyboard() : AXBaseWindow()
{
	setupUi(this);
	setGroupNumber(-1);

	mFocusedWidget = NULL;

	setFocusPolicy(Qt::NoFocus);
	setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
	setAttribute(Qt::WA_GroupLeader);

	installEventFilter(this);

	connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(onFocusChange(QWidget*, QWidget*)));
	connect(mCloseButton, SIGNAL(clicked()), this, SLOT(onHide()));

	QList <QAbstractButton*> buttonList = mLiteralGroup->buttons();

	for (int i = 0; i < buttonList.count(); ++i)
	{
		connect(buttonList.at(i), SIGNAL(clicked()), this, SLOT(onButtonClick()));
	}

	registerManager();
}

CXVirtualKeyboard::~CXVirtualKeyboard()
{

}

void CXVirtualKeyboard::mouseReleaseEvent(QMouseEvent* e)
{
	AXBaseWindow::mouseReleaseEvent(e);
}

void CXVirtualKeyboard::onFocusChange(QWidget* old, QWidget* now)
{
	Q_UNUSED(old)	

	if (now != 0 && !isAncestorOf(now))
	{
		mFocusedWidget = now;

		if (now->property("readOnly").isValid() && now->property("readOnly").toBool() == false)
		{
			QObject* w = now;
			while (w->parent() != NULL) w = w->parent();

			if (w->metaObject()->className() == QString("CXEditPathFile") || w->metaObject()->className() == QString("CXFilesList") || w->metaObject()->className() == QString("CXIniFileEditor"))
			{
				show();
			}
			else hide();
		}
		else hide();
	}
}

void CXVirtualKeyboard::onButtonClick()
{
	QAbstractButton* button = qobject_cast<QAbstractButton*>(sender());

	if (button != NULL && !button->shortcut().isEmpty())
	{
		if (mFocusedWidget == NULL) return;

		mFocusedWidget->activateWindow();

		int keyCode = button->shortcut()[0];

		QKeyEvent keyPress(QEvent::KeyPress, keyCode, Qt::NoModifier, button->shortcut().toString());
		QApplication::sendEvent(mFocusedWidget, &keyPress);

		QKeyEvent keyRelease(QEvent::KeyRelease, keyCode, Qt::NoModifier, button->shortcut().toString());
		QApplication::sendEvent(mFocusedWidget, &keyRelease);

		return;
	}
}

void CXVirtualKeyboard::onHide()
{
	hide();
	//setWindowState(Qt::WindowMinimized);
}
