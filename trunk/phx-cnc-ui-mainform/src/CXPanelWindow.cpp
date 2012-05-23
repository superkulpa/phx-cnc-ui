#include "CXPanelWIndow.h"

#include "CXWindowsManager.h"
#include "flowlayout.h"

CXPanelWindow::CXPanelWindow() : AXBaseWindow()
{
	btnGroup1 = new QPushButton("Group 1", this);
	QPushButton* btnGroup2 = new QPushButton("Group 2", this);
	QPushButton* btnFreeze = new QPushButton("Freeze", this);
	btnFreeze->setCheckable(true);
	QPushButton* btnExit = new QPushButton("Exit", this);

/**/
	FlowLayout* centralLayout = new FlowLayout(this);
	centralLayout->addWidget(btnGroup1);
	centralLayout->addWidget(btnGroup2);
	centralLayout->addWidget(btnFreeze);
	centralLayout->addWidget(btnExit);
/**/

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

	connect(btnGroup1,	SIGNAL(clicked()), this, SLOT(setGroup()));
	connect(btnGroup2,	SIGNAL(clicked()), this, SLOT(setGroup()));
	connect(btnExit,	SIGNAL(clicked()), this, SLOT(close()));
	connect(btnFreeze,	SIGNAL(clicked(bool)), mManager, SLOT(setFreeze(bool)));

}

CXPanelWindow::~CXPanelWindow()
{

}

void CXPanelWindow::setGroup()
{
	QPushButton* btn = qobject_cast<QPushButton*>(sender());

	if (btn == btnGroup1) mManager->setCurrentGroup(1);
	else mManager->setCurrentGroup(2);
}
