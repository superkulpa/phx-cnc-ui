#ifndef CXPANELWINDOW_H
#define CXPANELWINDOW_H

#include "AXBaseWindow.h"

#include <QPushButton>

class CXPanelWindow : public AXBaseWindow
{
	Q_OBJECT

public:
	CXPanelWindow();
	~CXPanelWindow();

private slots:
	void setGroup();

private:
	QPushButton* btnGroup1;
};

#endif // CXPANELWINDOW_H
