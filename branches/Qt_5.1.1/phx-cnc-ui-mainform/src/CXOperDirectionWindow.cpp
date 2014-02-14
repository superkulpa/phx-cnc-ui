#include "CXOperDirectionWindow.h"

#include <QHBoxLayout>
#include <QGroupBox>

#include "CXTouchButton.h"
#include "CXOperDirectionDialog.h"
#include "CXUtilsWindow.h"
#include "CXUdpManager.h"
#include "CXSettingsXML.h"

CXOperDirectionWindow::CXOperDirectionWindow() :
    AXBaseWindow()
{
  mIsRunning = false;
  mUtils = NULL;
  mOperDirectionDialog = NULL;
  mRotateAxis = CXSettingsXML::getValue("settings.xml", "rotateAxis").toInt();

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
  QHBoxLayout* OperLayout = new QHBoxLayout;
  OperLayout->setSpacing(10);

  int directionViewType = CXSettingsXML::getValue("settings.xml", "directionViewType").toInt();

  mOperVelocityView = new CXOperVelocityView(this);
  if (directionViewType != E_Circle) mOperVelocityView->hide();
  mOperVelocityView->setTexts(
      QList<QString>() << trUtf8("у\nс\nк") << trUtf8("н\nо\nр\nм") << trUtf8("м\nе\nд\nл"));
  OperLayout->addWidget(mOperVelocityView, 1);

  QHBoxLayout* OperDirectionLayout = new QHBoxLayout;
  OperDirectionLayout->setMargin(0);
  OperDirectionLayout->setSpacing(0);

  mOperDirectionView = new CXOperDirectionView(this, eDirectionViewTypes(directionViewType));
  OperLayout->addWidget(mOperDirectionView, 5);
/*
  mCurrentFrameLabel = new QLabel(this);
  mCurrentFrameLabel->hide();
  OperLayout->addWidget(mCurrentFrameLabel, 5);
*/
/**/
  mFrameWidget = new QWidget(this);
  mFrameWidget->hide();

  QGridLayout* frameWidgetLayout = new QGridLayout(mFrameWidget);
  frameWidgetLayout->setMargin(0);
  frameWidgetLayout->setSpacing(0);

  mFPlusButton = new CXTouchButton(trUtf8("+"), mFrameWidget);
  mFPlusButton->setObjectName("mFPlusButton");
  mFPlusButton->setLongPress(true);
  mFPlusButton->setFlat(true);
  mFPlusButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

  mFMinusButton = new CXTouchButton(trUtf8("-"), mFrameWidget);
  mFMinusButton->setObjectName("mFMinusButton");
  mFMinusButton->setLongPress(true);
  mFMinusButton->setFlat(true);
  mFMinusButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

  frameWidgetLayout->addWidget(mFPlusButton, 0, 0);
  frameWidgetLayout->addWidget(mFMinusButton, 1, 0);

  QWidget* frameSpacerWidget = new QWidget(mFrameWidget);
  frameSpacerWidget->setObjectName("frameSpacerWidget");
  frameWidgetLayout->addWidget(frameSpacerWidget, 0, 1);

  mVelocityView = new CXOperVelocityView(mFrameWidget);
  mVelocityView->setObjectName("mVelocityView");
  mVelocityView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  mVelocityView->setTexts(QList<QString>() << "^" << trUtf8("*") << "v");

  frameWidgetLayout->addWidget(mVelocityView, 0, 2, 2, 1);

  QGridLayout* dataLayout = new QGridLayout();
  dataLayout->setMargin(5);
  dataLayout->setSpacing(5);

  QLabel* frameLabel = new QLabel(trUtf8("Кадр"), mFrameWidget);
  QLabel* burnLabel = new QLabel(trUtf8("Пробивка"), mFrameWidget);
  mFrameEdit = new QLineEdit(mFrameWidget);
  mBurnEdit = new QLineEdit(mFrameWidget);
  
  dataLayout->addWidget(frameLabel, 0, 0);
  dataLayout->addWidget(burnLabel, 1, 0);
  dataLayout->addWidget(mFrameEdit, 0, 1);
  dataLayout->addWidget(mBurnEdit, 1, 1);
  dataLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 2, 0, 1, 2);

  frameWidgetLayout->addLayout(dataLayout, 0, 3, 2, 1);

  OperLayout->addWidget(mFrameWidget, 5);
/**/
  centralLayout->addLayout(OperLayout);
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
  connect(mOperDirectionView, SIGNAL(directionChanged(OperDirectionView::eMoveDirection)), this,
      SLOT(onDirectionChange(OperDirectionView::eMoveDirection)));
  connect(mOperDirectionView, SIGNAL(directionChanged(OperDirectionView::eMoveDirection, eVelocity)), this,
      SLOT(onDirectionChange(OperDirectionView::eMoveDirection, eVelocity)));

  connect(mOperVelocityView, SIGNAL(velocityChanged(eVelocity)), this,
      SLOT(onVelocityChange(eVelocity)));
  connect(mVelocityView, SIGNAL(velocityChanged(eVelocity)), this,
      SLOT(onVelocityChange(eVelocity)));
  connect(plusButton, SIGNAL(clicked()), this, SLOT(onUpSpeed()));
  connect(minusButton, SIGNAL(clicked()), this, SLOT(onDownSpeed()));
  connect(mFPlusButton, SIGNAL(clicked()), this, SLOT(onUpSpeed()));
  connect(mFMinusButton, SIGNAL(clicked()), this, SLOT(onDownSpeed()));
  connect(mCycleButton, SIGNAL(clicked()), this, SLOT(onModeChange()));
  connect(mStepButton, SIGNAL(clicked()), this, SLOT(onModeChange()));

  connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)),
      this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));

  registerManager();
}

CXOperDirectionWindow::~CXOperDirectionWindow()
{

}

void
CXOperDirectionWindow::onUtils()
{
  if (mUtils == NULL)
  {
    mUtils = new CXUtilsWindow();
    mUtils->setWindowModality(Qt::ApplicationModal);
  }

  mUtils->show();
}

void
CXOperDirectionWindow::onResetCoordinates()
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_RESET_POS, "0");
}

void
CXOperDirectionWindow::onXYClick()
{
  if (mIsRunning)
    return;

  if (mOperDirectionDialog == NULL)
  {
	  mOperDirectionDialog = new CXOperDirectionDialog();
	  mOperDirectionDialog->setWindowModality(Qt::ApplicationModal);
  }

  mOperDirectionDialog->show();
}

void
CXOperDirectionWindow::onStart()
{
  if (sender() == mForwardButton)
  {
    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_RUN_CP,
        Commands::MSG_VALUE_FORWARD);
  }

  if (sender() == mBackwardButton)
  {
    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_RUN_CP,
        Commands::MSG_VALUE_BACKWARD);
  }

  if (sender() == mSearchButton)
  {
    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_RUN_CP,
        Commands::MSG_VALUE_FIND_TRJ);
  }
}

void
CXOperDirectionWindow::onStop()
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_STOP_OPERATION, "0");
}

QString
CXOperDirectionWindow::getDirectionCommand(OperDirectionView::eMoveDirection aDirection)
{
  if (aDirection == OperDirectionView::E_Stop)
  {
    return "0";
  }

  QString x = "0";
  QString y = "0";

  if (aDirection != OperDirectionView::E_Left && aDirection != OperDirectionView::E_Right)
  {
    if (aDirection & OperDirectionView::E_Top)
    {
      if(mRotateAxis)
        y = "+2";
      else
        x = "-2";
    }
    else
    {
      if(mRotateAxis)
        y = "-2";
      else
        x = "+2";
    }
  }

  if (aDirection != OperDirectionView::E_Top && aDirection != OperDirectionView::E_Bottom)
  {
    if (aDirection & OperDirectionView::E_Left)
    {
      if(mRotateAxis)
        x = "-2";
      else
        y = "-2";
    }
    else
    {
      if(mRotateAxis)
        x = "+2";
      else
        y = "+2";
    }
  }

  QString res;
  res.append("0=" + x).append(",1=" + y);
  return res;
}

void
CXOperDirectionWindow::onDirectionChange(OperDirectionView::eMoveDirection aDirection)
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_HAND_DIR_MOVING,
      getDirectionCommand(aDirection).toStdString());
}

void
CXOperDirectionWindow::onDirectionChange(OperDirectionView::eMoveDirection aDirection, eVelocity aVelocity)
{
  onDirectionChange(aDirection);
  onVelocityChange(aVelocity);
}

void
CXOperDirectionWindow::onVelocityChange(eVelocity aVelocity)
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

void
CXOperDirectionWindow::onUpSpeed()
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_FEED,
      Commands::MSG_VALUE_INC);
}

void
CXOperDirectionWindow::onDownSpeed()
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_FEED,
      Commands::MSG_VALUE_DEC);
}

void
CXOperDirectionWindow::onModeChange()
{
  if (sender() == mCycleButton)
  {
    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_MODE_LOOP,
        Commands::MSG_VALUE_INVERT);
  }
  else if (sender() == mStepButton)
  {
    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_MODE_BY_STEP,
        Commands::MSG_VALUE_INVERT);
  }
}

void
CXOperDirectionWindow::StartCP()
{
  mIsRunning = true;

  mForwardButton->hide();
  mBackwardButton->hide();
  mSearchButton->hide();
  mOperDirectionView->hide();

  mStopButton->show();
//  mCurrentFrameLabel->show();
  mFrameWidget->show();
}

void
CXOperDirectionWindow::StopCP()
{
  mIsRunning = false;

  mForwardButton->show();
  mBackwardButton->show();
  mSearchButton->show();
  mOperDirectionView->setDirection(OperDirectionView::E_Stop);
  mOperDirectionView->show();

  mStopButton->hide();
//  mCurrentFrameLabel->hide();
  mFrameWidget->hide();
}

void
CXOperDirectionWindow::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
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
      if (aValue == QString::fromStdString(Commands::MSG_VALUE_HAND))
        StopCP();
      else
        StartCP();
    }

    //Текущий кадр.
    if (aCommand == QString::fromStdString(Commands::MSG_STATE_CP_LINE))
    {
      //mCurrentFrameLabel->setText(trUtf8("Текущий кадр: %1").arg(aValue));
    }

    //Режимы работы
    if (aCommand == QString::fromStdString(Commands::MSG_STATE_MODE_LOOP))
    {
      if (aValue == QString::fromStdString(Commands::MSG_VALUE_ON))
        mCycleButton->setStyleSheet("background-color: green;");
      else
        mCycleButton->setStyleSheet("");
    }
    else if (aCommand == QString::fromStdString(Commands::MSG_STATE_MODE_BY_STEP))
    {
      if (aValue == QString::fromStdString(Commands::MSG_VALUE_ON))
        mStepButton->setStyleSheet("background-color: green;");
      else
        mStepButton->setStyleSheet("");
    }

	//Изменение скорости и направления.
	if (aCommand == QString::fromStdString(Commands::MSG_STATE_HAND_DIR_MOVING))
	{
      QStringList values = aValue.split(",");
	  eVelocity velocity = E_NoVelocity;
	  OperDirectionView::eMoveDirection direction = OperDirectionView::E_NoDirection;

	  if (values.count() == 3)
	  {
		  if (values.first().length() == 3 && values.first().at(0) == 'F')
		  {
			  QString value = values.first().at(2);

			  if (value == QString::fromStdString(Commands::MSG_VALUE_NORMAL))
				  velocity = E_Normal;
			  if (value == QString::fromStdString(Commands::MSG_VALUE_FAST))
				  velocity = E_Boost;
			  if (value == QString::fromStdString(Commands::MSG_VALUE_SLOW))
				  velocity = E_Slow;
		  }

		  if (values.at(1).length() >= 3 && values.at(2).length() >= 3)
		  {
			  QString value1 = values.at(1);
			  QString value2 = values.at(2);
			  OperDirectionView::eMoveDirection xDirection = OperDirectionView::E_NoDirection;
			  OperDirectionView::eMoveDirection yDirection = OperDirectionView::E_NoDirection;

			  QMap <QString, OperDirectionView::eMoveDirection> xDirections;
			  xDirections.insert("-2", OperDirectionView::E_Top);
			  xDirections.insert("+2", OperDirectionView::E_Bottom);
			  xDirections.insert("0", OperDirectionView::E_Stop);

			  QMap <QString, OperDirectionView::eMoveDirection> yDirections;
			  yDirections.insert("-2", OperDirectionView::E_Left);
			  yDirections.insert("+2", OperDirectionView::E_Right);
			  yDirections.insert("0", OperDirectionView::E_Stop);

			  if (value1.at(0) == '0' || value2.at(0) == '0') value1 = (value1.at(0) == '0'? value1.mid(2) : value2.mid(2));
			  else value1 == " ";
			 
			  if (value2.at(0) == '1' || value1.at(0) == '1') value2 = (value2.at(0) == '1'? value2.mid(2) : value1.mid(2));
			  else value2 == " ";

			  if (mRotateAxis)
			  {
				  if (yDirections.contains(value1)) yDirection = yDirections.value(value1);
				  if (xDirections.contains(value2)) xDirection = xDirections.value(value2);
			  }
			  else
			  {
				  if (xDirections.contains(value1)) xDirection = xDirections.value(value1);
				  if (yDirections.contains(value2)) yDirection = yDirections.value(value2);
			  }

			  if (xDirection == OperDirectionView::E_NoDirection || yDirection == OperDirectionView::E_NoDirection)
			  {
				  direction = OperDirectionView::E_NoDirection;
			  }
			  else if (xDirection == OperDirectionView::E_Stop || yDirection == OperDirectionView::E_Stop)
			  {
				  direction = OperDirectionView::E_Stop;
			  }
			  else direction = OperDirectionView::eMoveDirection(xDirection | yDirection);
		  }
	  }

	  if (velocity != E_NoVelocity && direction != OperDirectionView::E_NoDirection)
	  {
		  mOperDirectionView->blockSignals(true);
		  mOperDirectionView->setDirection(direction, velocity);
		  mOperDirectionView->blockSignals(false);
	  }
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
      QString value = trUtf8("%1 мм/мин").arg(int((aValue.toFloat() / 1000.0) + 0.5));

      mFEdit->setText(value);
    }

    //Скорость работы (нормально, медленно, ускоренно)
    if (aCommand == QString::fromStdString(Commands::MSG_STATE_MODE_FEED))
    {
      eVelocity value = E_Normal;

      if (aValue == QString::fromStdString(Commands::MSG_VALUE_NORMAL))
        value = E_Normal;
      if (aValue == QString::fromStdString(Commands::MSG_VALUE_FAST))
        value = E_Boost;
      if (aValue == QString::fromStdString(Commands::MSG_VALUE_SLOW))
        value = E_Slow;

      mOperVelocityView->setVelocity(value);
    }
  }
}