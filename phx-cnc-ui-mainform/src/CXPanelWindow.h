#ifndef CXPANELWINDOW_H
#define CXPANELWINDOW_H

#include "AXBaseWindow.h"
#include "ui_CXPanelWindow.h"

class CXPanelWindow : public AXBaseWindow
{
	Q_OBJECT

public:
	CXPanelWindow();
	~CXPanelWindow();

private slots:
	void setGroup();

private:
	Ui::CXPanelWindow ui;
};

#endif // CXPANELWINDOW_H
