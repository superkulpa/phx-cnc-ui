#include "CXLazerDirectionWindow.h"

#include <QHBoxLayout>
#include <QToolButton>

#include "CXLazerVelocityView.h"
#include "CXLazerDirectionView.h"
#include "CXLazerVelocity.h"
#include "CXTouchButton.h"
#include "CXLazerDirectionDialog.h"

CXLazerDirectionWindow::CXLazerDirectionWindow() : AXBaseWindow()
{
	QVBoxLayout* centralLayout = new QVBoxLayout(this); 
	centralLayout->setMargin(5);

	QHBoxLayout* buttonLayout = new QHBoxLayout;
	buttonLayout->setMargin(0);
	buttonLayout->setSpacing(0);

	mForwardButton = new CXTouchButton(trUtf8("Вперед"), this);
	buttonLayout->addWidget(mForwardButton);

	mBackwardButton = new CXTouchButton(trUtf8("Назад"), this);
	buttonLayout->addWidget(mBackwardButton);

	mSearchButton = new CXTouchButton(trUtf8("Поиск"), this);
	buttonLayout->addWidget(mSearchButton);

	mStopButton = new CXTouchButton(trUtf8("Стоп"), this);
	mStopButton->hide();
	buttonLayout->addWidget(mStopButton);

	centralLayout->addLayout(buttonLayout);
/**/
	QHBoxLayout* positionLayout = new QHBoxLayout;

	CXTouchButton* xLabel = new CXTouchButton("X", this);
	xLabel->setObjectName("xButton");
//	xLabel->setAutoRaise(true);
	xLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	positionLayout->addWidget(xLabel);

	mXEdit = new QLineEdit(this);
	mXEdit->setValidator(new QRegExpValidator(QRegExp("\\d*\\.?\\d*")));
	positionLayout->addWidget(mXEdit);

	CXTouchButton* yLabel = new CXTouchButton("Y", this);
	yLabel->setObjectName("yButton");
//	yLabel->setAutoRaise(true);
	yLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	positionLayout->addWidget(yLabel);

	mYEdit = new QLineEdit(this);
	mYEdit->setValidator(new QRegExpValidator(QRegExp("\\d*\\.?\\d*")));
	positionLayout->addWidget(mYEdit);

	centralLayout->addLayout(positionLayout);

	QHBoxLayout* velocityLayout = new QHBoxLayout;
	QToolButton* fLabel = new QToolButton(this);
	fLabel->setText("F");
	fLabel->setAutoRaise(true);
	fLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	velocityLayout->addWidget(fLabel);

	mFEdit = new QLineEdit(this);
	mFEdit->setValidator(new QRegExpValidator(QRegExp("\\d*\\.?\\d*")));
	velocityLayout->addWidget(mFEdit);
	centralLayout->addLayout(velocityLayout);
/**/
	QHBoxLayout* lazerLayout = new QHBoxLayout;
	lazerLayout->setSpacing(10);

	mLazerVelocityView = new CXLazerVelocityView(this);
	mLazerVelocityView->setTexts(QList<QString>() << trUtf8("у\nс\nк") << trUtf8("н\nо\nр\nм") << trUtf8("м\nе\nд\nл"));
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
	connect(xLabel, SIGNAL(clicked()), this, SLOT(onXYClick()));
	connect(yLabel, SIGNAL(clicked()), this, SLOT(onXYClick()));
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
/*
	mForwardButton->hide();
	mBackwardButton->hide();
	mSearchButton->hide();
	mStopButton->show();

	mLazerDirectionView->hide();
	mLazerVelocityView->hide();
	mLazerVelocity->show();
*/
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

void CXLazerDirectionWindow::onXYClick()
{
	CXLazerDirectionDialog dialog(qobject_cast<QWidget*>(sender()));
	int res = dialog.exec();

	switch (res)
	{
		//абсолютное.
		case 1:
		{
			break;
		}
		//относительное.
		case 2:
		{
			break;
		}
	}
}
