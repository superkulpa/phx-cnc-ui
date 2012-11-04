#ifndef CXPANELWINDOW_H
#define CXPANELWINDOW_H

#include "AXBaseWindow.h"

#include <QPushButton>

/*!
	Класс панели с функциональными кнопками программы.
*/
class CXPanelWindow : public AXBaseWindow
{
	Q_OBJECT

public:
	//! Конструктор.
	CXPanelWindow();
	
	//! Деструктор.
	~CXPanelWindow();

	//! Установка состояния заморозки окон приложения.
	void setFreezeState(bool aIsFreeze);

private slots:
	//! Слот на показ нужной группы.
	void setGroup();

	//! Слот на выход.
	void onExit();

private:
	QPushButton* btnFreeze;
};

#endif // CXPANELWINDOW_H
