#include "CXLazerDirectionWindow.h"

#include <QHBoxLayout>
#include <QGroupBox>

#include "CXTouchButton.h"
#include "CXLazerDirectionDialog.h"
#include "CXUtilsWindow.h"
#include "CXUdpManager.h"

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

	mXEdit = new QLineEdit(groupBox);
	mXEdit->setReadOnly(true);
	mXEdit->setValidator(new QRegExpValidator(QRegExp("\\d*\\.?\\d*")));
	positionLayout->addWidget(mXEdit);

	mYEdit = new QLineEdit(groupBox);
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

	mCurrentFrameLabel = new QLabel(this);
	mCurrentFrameLabel->hide();
	lazerLayout->addWidget(mCurrentFrameLabel, 5);

	centralLayout->addLayout(lazerLayout);

	connect(mForwardButton, SIGNAL(clicked()), this, SLOT(onStart()));
	connect(mBackwardButton, SIGNAL(clicked()), this, SLOT(onStart()));
	connect(mSearchButton, SIGNAL(clicked()), this, SLOT(onStart()));
	connect(mStopButton, SIGNAL(clicked()), this, SLOT(onStop()));
	connect(mXYButton, SIGNAL(clicked()), this, SLOT(onXYClick()));
	connect(mLazerDirectionView, SIGNAL(directionChanged(LazerDirectionView::eMoveDirection)), this, SLOT(onDirectionChange(LazerDirectionView::eMoveDirection)));
	connect(mLazerVelocityView, SIGNAL(velocityChanged(eVelocity)), this, SLOT(onVelocityChange(eVelocity)));
	connect(plusButton, SIGNAL(clicked()), this, SLOT(onUpSpeed()));
	connect(minusButton, SIGNAL(clicked()), this, SLOT(onDownSpeed()));

	connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)), this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));

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

void CXLazerDirectionWindow::onResetCoordinates()
{
	mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_RESET_POS, "0");
}

void CXLazerDirectionWindow::onStart()
{
	if (sender() == mForwardButton)
	{
		mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_RUN_CP, Commands::MSG_VALUE_FORWARD);
	}

	if (sender() == mBackwardButton)
	{
		mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_RUN_CP, Commands::MSG_VALUE_BACKWARD);
	}

	if (sender() == mSearchButton)
	{
		mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_RUN_CP, Commands::MSG_VALUE_FIND_TRJ);
	}
}

void CXLazerDirectionWindow::onStop()
{
	mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_STOP_OPERATION, "0");
}

void CXLazerDirectionWindow::onXYClick()
{
	if (mIsRunning) return;

	CXLazerDirectionDialog dialog(qobject_cast<QWidget*>(sender()));
	dialog.mUdpManager = mUdpManager;
	dialog.exec();
/*
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
*/
}

void CXLazerDirectionWindow::onDirectionChange(LazerDirectionView::eMoveDirection aDirection)
{
	if (aDirection == LazerDirectionView::E_Stop)
	{
		mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_MOVE_STOP, "0");
		return;
	}

	QString x;
	QString y;

	if (aDirection != LazerDirectionView::E_Left && aDirection != LazerDirectionView::E_Right)
	{
		if (aDirection == LazerDirectionView::E_Top || aDirection == LazerDirectionView::E_TopLeft || aDirection == LazerDirectionView::E_TopRight)
		{
			x = "-1";
		}
		else
		{
			x = "+1";
		}
	}

	if (aDirection != LazerDirectionView::E_Top && aDirection != LazerDirectionView::E_Bottom)
	{
		if (aDirection == LazerDirectionView::E_TopLeft || aDirection == LazerDirectionView::E_Left || aDirection == LazerDirectionView::E_BottomLeft)
		{
			y = "-1";
		}
		else
		{
			y = "+1";
		}
	}

	QString res;

	if (!x.isEmpty()) res.append("0=" + x);
	if (!y.isEmpty())
	{
		if (!res.isEmpty()) res.append(",");
		res.append("1=" + y);
	}

	mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_HAND_DIR_MOVING, res.toStdString());
}

void CXLazerDirectionWindow::onVelocityChange(eVelocity aVelocity)
{
	String value;

	switch (aVelocity)
	{
		case E_Slow:
		{
			value = Commands::MSG_VALUE_SLOW;
			break;
		}
		case E_Normal:
		{
			value = Commands::MSG_VALUE_NORMAL;
			break;
		}
		case E_Boost:
		{
			value = Commands::MSG_VALUE_FAST;
			break;
		}
	}

	mUdpManager->sendCommand(Commands::MSG_SECTION_MOVE, Commands::MSG_CMD_MODE_FEED, value);
}

void CXLazerDirectionWindow::onUpSpeed()
{
	mUdpManager->sendCommand(Commands::MSG_SECTION_MOVE, Commands::MSG_CMD_FEED, "+1");
}

void CXLazerDirectionWindow::onDownSpeed()
{
	mUdpManager->sendCommand(Commands::MSG_SECTION_MOVE, Commands::MSG_CMD_FEED, "-1");
}

void CXLazerDirectionWindow::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{
	if (aSection == QString::fromStdString(Commands::MSG_SECTION_OPERATOR))
	{
		//Стоп
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_STOP_CP))
		{
			mIsRunning = false;

			mForwardButton->show();
			mBackwardButton->show();
			mSearchButton->show();
			mLazerDirectionView->setDirection(LazerDirectionView::E_Stop);
			mLazerDirectionView->show();

			mStopButton->hide();
			mCurrentFrameLabel->hide();
		}

		//Запуск
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_RUN_CP))
		{
			mIsRunning = true;

			mForwardButton->hide();
			mBackwardButton->hide();
			mSearchButton->hide();
			mLazerDirectionView->hide();

			mStopButton->show();
			mCurrentFrameLabel->show();
		}

		//Текущий кадр.
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_CP_LINE))
		{
			mCurrentFrameLabel->setText(trUtf8("Текущий кадр: %1").arg(aValue));
		}
	}

	if (aSection == QString::fromStdString(Commands::MSG_SECTION_MOVE))
	{
		//Позиция осей.
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_POS_AXIS))
		{
			QStringList list = aValue.split(",");
			QString x = list.at(0);
			x = x.mid(x.indexOf("=") + 1);
			QString y = list.at(1);
			y = y.mid(y.indexOf("=") + 1);

			mXEdit->setText(x);
			mYEdit->setText(y);
		}
		//Текущая скорость.
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_FEED_RESULT))
		{
			QString value = QString("%1").arg(aValue.toDouble() * 1000.0, 0, 'f', 2);

			mFEdit->setText(value);
		}
		//Скорость работы (нормально, медленно, ускоренно)
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_MODE_FEED))
		{
			eVelocity value = E_Normal;

			if (aValue == QString::fromStdString(Commands::MSG_VALUE_NORMAL)) value = E_Normal;
			if (aValue == QString::fromStdString(Commands::MSG_VALUE_FAST)) value = E_Boost;
			if (aValue == QString::fromStdString(Commands::MSG_VALUE_SLOW)) value = E_Slow;

			mLazerVelocityView->setVelocity(value);
		}
	}
}
