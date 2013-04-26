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

	QRegExp regExp("\\d*\\.?\\d*");

	mXEdit = new QLineEdit(groupBox);
	mXEdit->setReadOnly(true);
	mXEdit->setValidator(new QRegExpValidator(regExp, mXEdit));
	positionLayout->addWidget(mXEdit);

	mYEdit = new QLineEdit(groupBox);
	mYEdit->setReadOnly(true);
	mYEdit->setValidator(new QRegExpValidator(regExp, mYEdit));
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
	mFEdit->setValidator(new QRegExpValidator(regExp, mFEdit));
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
/**/
	QHBoxLayout* modeLayout = new QHBoxLayout;

	modeLayout->setSpacing(10);
	mCycleButton = new CXTouchButton(trUtf8("Зацикленно"), NULL);
	modeLayout->addWidget(mCycleButton);
	mReservButton = new CXTouchButton(trUtf8(""), NULL);
	modeLayout->addWidget(mReservButton);
	mStepButton = new CXTouchButton(trUtf8("Покадрово"), NULL);
	modeLayout->addWidget(mStepButton);

	centralLayout->addLayout(modeLayout);

	connect(mForwardButton, SIGNAL(clicked()), this, SLOT(onStart()));
	connect(mBackwardButton, SIGNAL(clicked()), this, SLOT(onStart()));
	connect(mSearchButton, SIGNAL(clicked()), this, SLOT(onStart()));
	connect(mStopButton, SIGNAL(clicked()), this, SLOT(onStop()));
	connect(mXYButton, SIGNAL(clicked()), this, SLOT(onXYClick()));
	connect(mLazerDirectionView, SIGNAL(directionChanged(LazerDirectionView::eMoveDirection)), this, SLOT(onDirectionChange(LazerDirectionView::eMoveDirection)));
	connect(mLazerVelocityView, SIGNAL(velocityChanged(eVelocity)), this, SLOT(onVelocityChange(eVelocity)));
	connect(plusButton, SIGNAL(clicked()), this, SLOT(onUpSpeed()));
	connect(minusButton, SIGNAL(clicked()), this, SLOT(onDownSpeed()));
	connect(mCycleButton, SIGNAL(clicked()), this, SLOT(onModeChange()));
	connect(mStepButton, SIGNAL(clicked()), this, SLOT(onModeChange()));

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
}

void CXLazerDirectionWindow::onDirectionChange(LazerDirectionView::eMoveDirection aDirection)
{
	if (aDirection == LazerDirectionView::E_Stop)
	{
		mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_MOVE_STOP, "0");
		return;
	}

	QString x = "0";
	QString y = "0";

	if (aDirection != LazerDirectionView::E_Left && aDirection != LazerDirectionView::E_Right)
	{
		if (aDirection == LazerDirectionView::E_Top || aDirection == LazerDirectionView::E_TopLeft || aDirection == LazerDirectionView::E_TopRight)
		{
			x = "-2";
		}
		else
		{
			x = "+2";
		}
	}

	if (aDirection != LazerDirectionView::E_Top && aDirection != LazerDirectionView::E_Bottom)
	{
		if (aDirection == LazerDirectionView::E_TopLeft || aDirection == LazerDirectionView::E_Left || aDirection == LazerDirectionView::E_BottomLeft)
		{
			y = "-2";
		}
		else
		{
			y = "+2";
		}
	}

	QString res;

	res.append("0=" + x);
	res.append(",");
	res.append("1=" + y);

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

	mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_MODE_FEED, value);
}

void CXLazerDirectionWindow::onUpSpeed()
{
	mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_FEED, Commands::MSG_VALUE_INC);
}

void CXLazerDirectionWindow::onDownSpeed()
{
	mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_FEED, Commands::MSG_VALUE_DEC);
}

void CXLazerDirectionWindow::onModeChange()
{
	if (sender() == mCycleButton)
	{
		mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_MODE_LOOP, Commands::MSG_VALUE_INVERT);
	}
	else if (sender() == mStepButton)
	{
		mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_MODE_BY_STEP, Commands::MSG_VALUE_INVERT);
	}
}


void CXLazerDirectionWindow::StartCP()
{
	mIsRunning = true;

	mForwardButton->hide();
	mBackwardButton->hide();
	mSearchButton->hide();
	mLazerDirectionView->hide();

	mStopButton->show();
	mCurrentFrameLabel->show();

};

void CXLazerDirectionWindow::StopCP()
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

void CXLazerDirectionWindow::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{
	if (aSection == QString::fromStdString(Commands::MSG_SECTION_OPERATOR))
	{
		//Стоп
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_STOP_CP))
		{
			StopCP();
		}

		//Запуск
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_RUN_CP))
		{
			if(aValue == QString::fromStdString(Commands::MSG_VALUE_HAND)) StopCP();
			else StartCP();
		}

		//Текущий кадр.
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_CP_LINE))
		{
			mCurrentFrameLabel->setText(trUtf8("Текущий кадр: %1").arg(aValue));
		}
		//Режимы работы
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_MODE_LOOP))
		{
			if(aValue == QString::fromStdString(Commands::MSG_VALUE_ON)) mCycleButton->setStyleSheet("background-color: green;");
			else mCycleButton->setStyleSheet("");
		}
		else if(aCommand == QString::fromStdString(Commands::MSG_STATE_MODE_BY_STEP))
		{
			if(aValue == QString::fromStdString(Commands::MSG_VALUE_ON)) mStepButton->setStyleSheet("background-color: green;");
			else mStepButton->setStyleSheet("");
		}
	}

	if (aSection == QString::fromStdString(Commands::MSG_SECTION_MOVE))
	{
		//Позиция осей.
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_POS_AXIS))
		{
			//TODO реализовать красиво отображеие координат может прихолить по одной
			QStringList list = aValue.split(",");
			for (int i = 0; i < list.size(); i++)
			{
				QString axisPosStr = list.at(i);
				int indx = axisPosStr.indexOf("=");
				int axisIndx = axisPosStr.mid(0, indx).toInt();
				double axisPos = axisPosStr.mid(indx + 1).toDouble() / 1000.0;

				switch (axisIndx)
				{
					case 0:
					{
						mXEdit->setText(trUtf8("%1 мм").arg(axisPos, 0, 'f', 2));
						break;
					}
					case 1:
					{
						mYEdit->setText(trUtf8("%1 мм").arg(axisPos, 0, 'f', 2));
						break;
					}
				}
			}

			QString valueX = mXEdit->text();
			valueX = valueX.mid(0, valueX.indexOf(" "));

			QString valueY = mYEdit->text();
			valueY = valueY.mid(0, valueY.indexOf(" "));

			emit positionChanged(QPointF(valueX.toDouble(), valueY.toDouble()), true);
		}

		//Текущая скорость.
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_FEED_RESULT))
		{
			QString value = trUtf8("%1 мм/мин").arg(aValue.toInt() / 1000.0);

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
