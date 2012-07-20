#include "CXPanelWindow.h"

#include <QApplication>
#include <QVariant>

#include "CXWindowsManager.h"
#include "flowlayout.h"

CXPanelWindow::CXPanelWindow() : AXBaseWindow()
{
	setFocusPolicy(Qt::StrongFocus);

	QPushButton* btnGroup1 = new QPushButton("Group 1", this);
	btnGroup1->setProperty("groupName", 1);
	QPushButton* btnGroup2 = new QPushButton("Group 2", this);
	btnGroup2->setProperty("groupName", 2);
	QPushButton* btnGroup3 = new QPushButton("Group 3", this);
	btnGroup3->setProperty("groupName", 3);
	btnFreeze = new QPushButton("Freeze", this);
	btnFreeze->setCheckable(true);
	QPushButton* btnExit = new QPushButton("Exit", this);

/**/
	FlowLayout* centralLayout = new FlowLayout(this);
	centralLayout->addWidget(btnGroup1);
	centralLayout->addWidget(btnGroup2);
	centralLayout->addWidget(btnGroup3);
	centralLayout->addWidget(btnFreeze);
	centralLayout->addWidget(btnExit);
/**/

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

	connect(btnGroup1,	SIGNAL(clicked()), this, SLOT(setGroup()));
	connect(btnGroup2,	SIGNAL(clicked()), this, SLOT(setGroup()));
	connect(btnGroup3,	SIGNAL(clicked()), this, SLOT(setGroup()));
	connect(btnExit,	SIGNAL(clicked()), this, SLOT(close()));
	connect(btnFreeze,	SIGNAL(clicked(bool)), mManager, SLOT(setFreeze(bool)));
}

CXPanelWindow::~CXPanelWindow()
{

}

void CXPanelWindow::setFreezeState(bool aIsFreeze)
{
	btnFreeze->setChecked(aIsFreeze);
	setFreeze(aIsFreeze);
}

void CXPanelWindow::setGroup()
{
	QPushButton* btn = qobject_cast<QPushButton*>(sender());

	mManager->setCurrentGroup(btn->property("groupName").toInt());
}
