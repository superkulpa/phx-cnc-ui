#include "CXLazerDirectionWindow.h"

#include <QHBoxLayout>

#include "CXLazerVelocityView.h"
#include "CXLazerDirectionView.h"
#include "CXLazerVelocity.h"

CXLazerDirectionWindow::CXLazerDirectionWindow() : AXBaseWindow()
{
	setObjectName("CXLazerDirectionWindow");
/**/
	QVBoxLayout* centralLayout = new QVBoxLayout(this); 

	QHBoxLayout* buttonLayout = new QHBoxLayout;
	buttonLayout->setMargin(5);
	buttonLayout->setSpacing(0);

	mForwardButton = new QPushButton(trUtf8("Вперед"), this);
	buttonLayout->addWidget(mForwardButton);

	mBackwardButton = new QPushButton(trUtf8("Назад"), this);
	buttonLayout->addWidget(mBackwardButton);

	mSearchButton = new QPushButton(trUtf8("Поиск"), this);
	buttonLayout->addWidget(mSearchButton);

	mStopButton = new QPushButton(trUtf8("Стоп"), this);
	mStopButton->hide();
	buttonLayout->addWidget(mStopButton);

	centralLayout->addLayout(buttonLayout);

	QHBoxLayout* lazerLayout = new QHBoxLayout;
	lazerLayout->setSpacing(10);

	mLazerVelocityView = new CXLazerVelocityView(this);
	lazerLayout->addWidget(mLazerVelocityView, 1);

	mLazerDirectionView = new CXLazerDirectionView(this);
	lazerLayout->addWidget(mLazerDirectionView, 5);

	mLazerVelocity = new CXLazerVelocity(this);
	mLazerVelocity->hide();
	lazerLayout->addWidget(mLazerVelocity, 1);

	centralLayout->addLayout(lazerLayout);

	connect(mForwardButton, SIGNAL(clicked()), this, SLOT(onStart()));
	connect(mBackwardButton, SIGNAL(clicked()), this, SLOT(onStart()));
	connect(mSearchButton, SIGNAL(clicked()), this, SLOT(onStart()));
	connect(mStopButton, SIGNAL(clicked()), this, SLOT(onStop()));
}

CXLazerDirectionWindow::~CXLazerDirectionWindow()
{

}

void CXLazerDirectionWindow::onStart()
{
	if (sender() == mForwardButton)
	{
		;
	}

	if (sender() == mBackwardButton)
	{
		;
	}

	if (sender() == mSearchButton)
	{
		;
	}

	mForwardButton->hide();
	mBackwardButton->hide();
	mSearchButton->hide();
	mStopButton->show();

	mLazerDirectionView->hide();
	mLazerVelocityView->hide();
	mLazerVelocity->show();
}

void CXLazerDirectionWindow::onStop()
{
	mStopButton->hide();
	mForwardButton->show();
	mBackwardButton->show();
	mSearchButton->show();

	mLazerDirectionView->show();
	mLazerVelocityView->show();
	mLazerVelocity->hide();

//	mLazerDirectionView->setDirection(LazerDirectionView::E_None);
}
