#include "CXPanelWindow.h"

#include <QVariant>

#include "CXWindowsManager.h"
#include "flowlayout.h"

CXPanelWindow::CXPanelWindow() : AXBaseWindow()
{
	setObjectName("CXPanelWindow");
	setFocusPolicy(Qt::StrongFocus);

	QPushButton* btnGroup1 = new QPushButton(trUtf8("УП"), this);
	btnGroup1->setProperty("groupName", 1);

	QPushButton* btnGroup2 = new QPushButton(trUtf8("Параметры"), this);
	btnGroup2->setProperty("groupName", 2);

	QPushButton* btnGroup3 = new QPushButton(trUtf8("Наладка"), this);
	btnGroup3->setProperty("groupName", 3);

	QPushButton* btnGroup4 = new QPushButton(trUtf8("Grop 4"), this);
	btnGroup4->setProperty("groupName", 4);

	btnFreeze = new QPushButton("Freeze", this);
	btnFreeze->setCheckable(true);

	QPushButton* btnExit = new QPushButton("Exit", this);

/**/
	FlowLayout* centralLayout = new FlowLayout(this);
	centralLayout->addWidget(btnGroup1);
	centralLayout->addWidget(btnGroup2);
	centralLayout->addWidget(btnGroup3);
	centralLayout->addWidget(btnGroup4);
	centralLayout->addWidget(btnFreeze);
	centralLayout->addWidget(btnExit);
/**/

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint/* | Qt::WindowStaysOnTopHint*/);

	connect(btnGroup1,	SIGNAL(clicked()), this, SLOT(setGroup()));
	connect(btnGroup2,	SIGNAL(clicked()), this, SLOT(setGroup()));
	connect(btnGroup3,	SIGNAL(clicked()), this, SLOT(setGroup()));
	connect(btnGroup4,	SIGNAL(clicked()), this, SLOT(setGroup()));
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
