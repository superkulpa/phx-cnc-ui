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
	CXPanelWindow();
	~CXPanelWindow();

	void setFreezeState(bool aIsFreeze);

private slots:
	void setGroup();

private:
	QPushButton* btnGroup1;
	QPushButton* btnFreeze;
};

#endif // CXPANELWINDOW_H
