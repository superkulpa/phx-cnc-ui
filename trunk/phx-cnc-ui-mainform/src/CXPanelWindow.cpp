#include "CXPanelWindow.h"

#include <QVariant>

#include "CXTouchButton.h"
#include "CXWindowsManager.h"
#include "CXExitDialog.h"
#include "flowlayout.h"

CXPanelWindow::CXPanelWindow() : AXBaseWindow()
{
	setFocusPolicy(Qt::StrongFocus);

	CXTouchButton* btnGroup1 = new CXTouchButton(trUtf8("УП"), this);
	btnGroup1->setProperty("groupName", 1);

	CXTouchButton* btnGroup2 = new CXTouchButton(trUtf8("Параметры"), this);
	btnGroup2->setProperty("groupName", 2);
/*
	CXTouchButton* btnGroup3 = new CXTouchButton(trUtf8("Наладка"), this);
	btnGroup3->setProperty("groupName", 3);
*/
	CXTouchButton* btnGroup4 = new CXTouchButton(trUtf8("Управление"), this);
	btnGroup4->setProperty("groupName", 4);

	btnFreeze = new QPushButton("Freeze", this);
	btnFreeze->setCheckable(true);

	CXTouchButton* btnExit = new CXTouchButton(trUtf8("Выключение"), this);

/**/
	FlowLayout* centralLayout = new FlowLayout(this);
	centralLayout->addWidget(btnGroup1);
	centralLayout->addWidget(btnGroup2);
//	centralLayout->addWidget(btnGroup3);
	centralLayout->addWidget(btnGroup4);
	centralLayout->addWidget(btnFreeze);
	centralLayout->addWidget(btnExit);
/**/

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint/* | Qt::WindowStaysOnTopHint*/);

	connect(btnGroup1,	SIGNAL(clicked()), this, SLOT(setGroup()));
	connect(btnGroup2,	SIGNAL(clicked()), this, SLOT(setGroup()));
//	connect(btnGroup3,	SIGNAL(clicked()), this, SLOT(setGroup()));
	connect(btnGroup4,	SIGNAL(clicked()), this, SLOT(setGroup()));
	connect(btnExit,	SIGNAL(clicked()), this, SLOT(onExit()));
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

void CXPanelWindow::onExit()
{
	CXExitDialog exitDialog(this);
	exitDialog.setWindowState(Qt::WindowFullScreen);
	int res = exitDialog.exec();

	switch (res)
	{
		//выключение.
		case 1:
		{
			break;
		}
		//выход.
		case 2:
		{
			close();

			break;
		}
	}
}
