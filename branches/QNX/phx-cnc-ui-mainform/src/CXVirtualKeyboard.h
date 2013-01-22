#ifndef CXVIRTUALKEYBOARD_H
#define CXVIRTUALKEYBOARD_H

#include "AXBaseWindow.h"

#include "ui_CXVirtualKeyboard.h"

class CXVirtualKeyboard : public AXBaseWindow, public Ui::CXVirtualKeyboard
{
	Q_OBJECT

public:
	CXVirtualKeyboard();
	~CXVirtualKeyboard();

protected:
	virtual void mouseReleaseEvent(QMouseEvent* e);

private slots:
	//! Слот смены фокуса приложения.
	void onFocusChange(QWidget* old, QWidget* now);

	//! Слот обработки нажатий кнопок.
	void onButtonClick();

	void onHide();

private:
	QWidget* mFocusedWidget;
};

#endif // CXVIRTUALKEYBOARD_H
