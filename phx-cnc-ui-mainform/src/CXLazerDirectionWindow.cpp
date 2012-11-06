#include "CXLazerDirectionWindow.h"

#include <QHBoxLayout>

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

	mXYButton = new CXTouchButton("X/Y", this);
	mXYButton->setObjectName("xyButton");
	mXYButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	positionLayout->addWidget(mXYButton);

	QLineEdit* mXEdit = new QLineEdit(this);
	mXEdit->setValidator(new QRegExpValidator(QRegExp("\\d*\\.?\\d*")));
	positionLayout->addWidget(mXEdit);

	QLineEdit* mYEdit = new QLineEdit(this);
	mYEdit->setValidator(new QRegExpValidator(QRegExp("\\d*\\.?\\d*")));
	positionLayout->addWidget(mYEdit);
	
	centralLayout->addLayout(positionLayout);

	QHBoxLayout* velocityLayout = new QHBoxLayout;

	mFLabel = new QLabel("F", this);
	mFLabel->setObjectName("mFLabel");
	mFLabel->setAlignment(Qt::AlignCenter);
	mFLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	velocityLayout->addWidget(mFLabel);

	mFEdit = new QLineEdit(this);
	mFEdit->setValidator(new QRegExpValidator(QRegExp("\\d*\\.?\\d*")));
	velocityLayout->addWidget(mFEdit);

	CXTouchButton* plusButton = new CXTouchButton("+", this);
	plusButton->setObjectName("plusButton");
	plusButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	velocityLayout->addWidget(plusButton);

	CXTouchButton* minusButton = new CXTouchButton("-", this);
	minusButton->setObjectName("minusButton");
	velocityLayout->addWidget(minusButton);

	centralLayout->addLayout(velocityLayout);
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
	mForwardButton->show();
	mBackwardButton->show();
	mSearchButton->show();
//	mXYButton->show();
//	mFLabel->show();
//	mFEdit->show();
	mLazerDirectionView->show();
//	mLazerVelocityView->show();

	mStopButton->hide();
	mLazerVelocity->hide();
}

void CXLazerDirectionWindow::onXYClick()
{
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
