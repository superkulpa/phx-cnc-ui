#include "CXLazerDirectionWindow.h"

#include <QHBoxLayout>
#include <QGroupBox>

#include "CXLazerVelocityView.h"
#include "CXLazerDirectionView.h"
#include "CXLazerVelocity.h"
#include "CXTouchButton.h"
#include "CXLazerDirectionDialog.h"
#include "CXUtilsWindow.h"

CXLazerDirectionWindow::CXLazerDirectionWindow() : AXBaseWindow()
{
	mIsRunning = false;
	mUtils = NULL;

	QVBoxLayout* centralLayout = new QVBoxLayout(this); 
	centralLayout->setMargin(5);

	QGroupBox* groupBox = new QGroupBox(this);
	groupBox->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

	QVBoxLayout* groupBoxLayout = new QVBoxLayout(groupBox);
	groupBoxLayout->setMargin(7);
	groupBoxLayout->setSpacing(6);

	QHBoxLayout* buttonLayout = new QHBoxLayout;
	buttonLayout->setMargin(0);
	buttonLayout->setSpacing(6);

	mForwardButton = new CXTouchButton(trUtf8("Вперед"), groupBox);
	buttonLayout->addWidget(mForwardButton);

	mBackwardButton = new CXTouchButton(trUtf8("Назад"), groupBox);
	buttonLayout->addWidget(mBackwardButton);

	mSearchButton = new CXTouchButton(trUtf8("Поиск"), groupBox);
	buttonLayout->addWidget(mSearchButton);

	mStopButton = new CXTouchButton(trUtf8("Стоп"), groupBox);
	mStopButton->hide();
	buttonLayout->addWidget(mStopButton);

	groupBoxLayout->addLayout(buttonLayout);
/**/
	QHBoxLayout* positionLayout = new QHBoxLayout;

	mXYButton = new CXTouchButton("X/Y", groupBox);
	mXYButton->setObjectName("xyButton");
	mXYButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	positionLayout->addWidget(mXYButton);

	QLineEdit* mXEdit = new QLineEdit(groupBox);
	mXEdit->setReadOnly(true);
	mXEdit->setValidator(new QRegExpValidator(QRegExp("\\d*\\.?\\d*")));
	positionLayout->addWidget(mXEdit);

	QLineEdit* mYEdit = new QLineEdit(groupBox);
	mYEdit->setReadOnly(true);
	mYEdit->setValidator(new QRegExpValidator(QRegExp("\\d*\\.?\\d*")));
	positionLayout->addWidget(mYEdit);
	
	groupBoxLayout->addLayout(positionLayout);

	QHBoxLayout* velocityLayout = new QHBoxLayout;

	mFLabel = new QLabel("F", groupBox);
	mFLabel->setObjectName("mFLabel");
	mFLabel->setAlignment(Qt::AlignCenter);
	mFLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	velocityLayout->addWidget(mFLabel);

	mFEdit = new QLineEdit(groupBox);
	mFEdit->setReadOnly(true);
	mFEdit->setValidator(new QRegExpValidator(QRegExp("\\d*\\.?\\d*")));
	velocityLayout->addWidget(mFEdit);

	CXTouchButton* plusButton = new CXTouchButton("+", groupBox);
	plusButton->setObjectName("plusButton");
	plusButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	velocityLayout->addWidget(plusButton);

	CXTouchButton* minusButton = new CXTouchButton("-", groupBox);
	minusButton->setObjectName("minusButton");
	velocityLayout->addWidget(minusButton);

	groupBoxLayout->addLayout(velocityLayout);

	centralLayout->addWidget(groupBox);
/**/
	QHBoxLayout* lazerLayout = new QHBoxLayout;
	lazerLayout->setSpacing(10);

	mLazerVelocityView = new CXLazerVelocityView(this);
	mLazerVelocityView->setTexts(QList<QString>() << trUtf8("у\nс\nк") << trUtf8("н\nо\nр\nм") << trUtf8("м\nе\nд\nл"));
	lazerLayout->addWidget(mLazerVelocityView, 1);

	QHBoxLayout* lazerDirectionLayout = new QHBoxLayout;
	lazerDirectionLayout->setMargin(0);
	lazerDirectionLayout->setSpacing(0);

	mLazerDirectionView = new CXLazerDirectionView(this);
	lazerLayout->addWidget(mLazerDirectionView, 5);

	mLazerVelocity = new CXLazerVelocity(this);
	mLazerVelocity->hide();
	lazerLayout->addWidget(mLazerVelocity, 5);

	centralLayout->addLayout(lazerLayout);

	connect(mForwardButton, SIGNAL(clicked()), this, SLOT(onStart()));
	connect(mBackwardButton, SIGNAL(clicked()), this, SLOT(onStart()));
	connect(mSearchButton, SIGNAL(clicked()), this, SLOT(onStart()));
	connect(mStopButton, SIGNAL(clicked()), this, SLOT(onStop()));
	connect(mXYButton, SIGNAL(clicked()), this, SLOT(onXYClick()));

	registerManager();
}

CXLazerDirectionWindow::~CXLazerDirectionWindow()
{

}

void CXLazerDirectionWindow::onUtils()
{
	if (mUtils == NULL)
	{
		mUtils = new CXUtilsWindow();
		mUtils->setWindowModality(Qt::ApplicationModal);
	}

	mUtils->show();
}

void CXLazerDirectionWindow::onStart()
{
	mIsRunning = true;

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
//	mXYButton->hide();
//	mFLabel->hide();
//	mFEdit->hide();
	mLazerDirectionView->hide();
//	mLazerVelocityView->hide();

	mStopButton->show();
	mLazerVelocity->show();
}

void CXLazerDirectionWindow::onStop()
{
	mIsRunning = false;

	mForwardButton->show();
	mBackwardButton->show();
	mSearchButton->show();
//	mXYButton->show();
//	mFLabel->show();
//	mFEdit->show();
	mLazerDirectionView->setDirection(LazerDirectionView::E_Stop);
	mLazerDirectionView->show();
//	mLazerVelocityView->show();

	mStopButton->hide();
	mLazerVelocity->hide();
}

void CXLazerDirectionWindow::onXYClick()
{
	if (mIsRunning) return;

	CXLazerDirectionDialog dialog(qobject_cast<QWidget*>(sender()));
	int res = dialog.exec();

	QPointF pos = dialog.getPosition();

	switch (res)
	{
		//абсолютное.
		case 1:
		{
			emit positionChanged(pos, true);
			break;
		}
		//относительное.
		case 2:
		{
			emit positionChanged(pos, false);
			break;
		}
	}
}
