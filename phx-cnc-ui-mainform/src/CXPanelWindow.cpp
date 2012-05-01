#include "CXPanelWIndow.h"

#include "CXWindowsManager.h"

CXPanelWindow::CXPanelWindow() : AXBaseWindow()
{
	ui.setupUi(this);

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

	connect(ui.btnGroup1,	SIGNAL(clicked()), this, SLOT(setGroup()));
	connect(ui.btnGroup2,	SIGNAL(clicked()), this, SLOT(setGroup()));
	connect(ui.btnExit,		SIGNAL(clicked()), this, SLOT(close()));
}

CXPanelWindow::~CXPanelWindow()
{

}

void CXPanelWindow::setGroup()
{
	QPushButton* btn = qobject_cast<QPushButton*>(sender());

	if (btn == ui.btnGroup1) mManager->setCurrentGroup(1);
	else mManager->setCurrentGroup(2);
}
