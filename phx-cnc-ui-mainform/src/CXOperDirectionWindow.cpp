#include <iostream>

#include "CXOperDirectionWindow.h"

#include <QHBoxLayout>
#include <QGroupBox>


#include "CXTouchButton.h"
#include "CXOperDirectionDialog.h"
#include "CXUtilsWindow.h"
#include "CXUdpManager.h"
#include "utils/CXSettingsXML.h"
#include "CXVirtualKeyboardNum.h"
#include "CXOperFeedDlg.h"

CXOperDirectionWindow::CXOperDirectionWindow() :
AXBaseWindow()
{
  mIsRunning = false;
  mUtils = NULL;
  mRotateAxis = CXSettingsXML::getValue("settings.xml", "rotateAxis", "0").toInt();

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
  mXEdit->setAlignment(Qt::AlignRight);

  positionLayout->addWidget(mXEdit);

  mYEdit = new QLineEdit(groupBox);
  mYEdit->setReadOnly(true);
  mYEdit->setValidator(new QRegExpValidator(regExp, mYEdit));
  mYEdit->setAlignment(Qt::AlignRight);
  positionLayout->addWidget(mYEdit);

  groupBoxLayout->addLayout(positionLayout);

  QHBoxLayout* velocityLayout = new QHBoxLayout;

  mFLabel = new CXTouchButton("F", groupBox);
  mFLabel->setObjectName("mFLabel");
  //  mFLabel->setAlignment(Qt::AlignCenter);
  mFLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  velocityLayout->addWidget(mFLabel);

  mFEdit = new QLineEdit(groupBox);
  mFEdit->setReadOnly(true);
  mFEdit->setValidator(new QRegExpValidator(regExp, mFEdit));
  mFEdit->setAlignment(Qt::AlignLeft);
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

  int directionViewType = CXSettingsXML::getValue("settings.xml", "directionViewType", "0").toInt();

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

  //QGridLayout* frameWidgetLayout = new QVBoxLayout(mFrameWidget);//new QGridLayout(mFrameWidget);
  QVBoxLayout* frameWidgetLayout = new QVBoxLayout(mFrameWidget);
  frameWidgetLayout->setMargin(0);
  frameWidgetLayout->setSpacing(0);

//  mFPlusButton = new CXTouchButton(trUtf8("+"), mFrameWidget);
//  mFPlusButton->setObjectName("mFPlusButton");
//  //  mFPlusButton->setLongPress(true);
//  mFPlusButton->setFlat(true);
//  mFPlusButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
//
//  mFMinusButton = new CXTouchButton(trUtf8("-"), mFrameWidget);
//  mFMinusButton->setObjectName("mFMinusButton");
//  //  mFMinusButton->setLongPress(true);
//  mFMinusButton->setFlat(true);
//  mFMinusButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

//  frameWidgetLayout->addWidget(mFPlusButton, 0, 0);
//  frameWidgetLayout->addWidget(mFMinusButton, 1, 0);

//  QWidget* frameSpacerWidget = new QWidget(mFrameWidget);
//  frameSpacerWidget->setObjectName("frameSpacerWidget");
//  frameWidgetLayout->addWidget(frameSpacerWidget, 0, 1);

//  mVelocityView = new CXOperVelocityView(mFrameWidget);
//  mVelocityView->setObjectName("mVelocityView");
//  mVelocityView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//  mVelocityView->setTexts(QList<QString>() << "^" << trUtf8("*") << "v");

//  frameWidgetLayout->addWidget(mVelocityView, 0, 2, 2, 1);

  QGroupBox* frameGroupBox = new QGroupBox(mFrameWidget);

  QGridLayout* dataLayout = new QGridLayout(frameGroupBox);
  //dataLayout->setMargin(5);
  //dataLayout->setSpacing(5);

  QLabel* frameLabel = new QLabel(trUtf8("Кадр"), mFrameWidget);
  QLabel* burnLabel = new QLabel(trUtf8("Пробивка"), mFrameWidget);
  mFrameEdit = new QLineEdit(mFrameWidget);
  mFrameEdit->setObjectName("mFrameEdit");
  mBurnEdit = new QLineEdit(mFrameWidget);
  mBurnEdit->setObjectName("mBurnEdit");

//  dataLayout->addWidget(frameLabel, 0, 0);
//  dataLayout->addWidget(burnLabel, 1, 0);
//  dataLayout->addWidget(mFrameEdit, 0, 1);
//  dataLayout->addWidget(mBurnEdit, 1, 1);
  dataLayout->addWidget(frameLabel, 0, 0);
  dataLayout->addWidget(mFrameEdit, 0, 1);
  dataLayout->addWidget(burnLabel, 0, 2);
  dataLayout->addWidget(mBurnEdit, 0, 3);

  //dataLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 1, 0, 1, 2);
  //dataLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 1, 0, 1, 2);

  //frameWidgetLayout->addLayout(dataLayout, 0, 3, 2, 1);
  //frameWidgetLayout->addLayout(dataLayout,2);

  mBigStopButton = new CXTouchButton(trUtf8("Стоп УП"), mFrameWidget);
  mBigStopButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Expanding);
  dataLayout->addWidget(mBigStopButton, 1, 0, 3, 4);
  frameWidgetLayout->addWidget(frameGroupBox);
//  frameWidgetLayout->addWidget(mBigStopButton);
  OperLayout->addWidget(mFrameWidget, 5);


  /**/
  centralLayout->addLayout(OperLayout);
  /**/
  QHBoxLayout* modeLayout = new QHBoxLayout;

  modeLayout->setSpacing(10);
  mCycleButton = new CXTouchButton(trUtf8("Зацикленно"), NULL);
  modeLayout->addWidget(mCycleButton);
  mFastButton = new CXTouchButton(trUtf8("Ускоренно"), NULL);
  modeLayout->addWidget(mFastButton);
  //mStepButton = new CXTouchButton(trUtf8("Покадрово"), NULL);
  //modeLayout->addWidget(mStepButton);
  mNextWindow = new CXTouchButton(trUtf8(">>"), NULL);
  modeLayout->addWidget(mNextWindow);

  centralLayout->addLayout(modeLayout);

  connect(mForwardButton, SIGNAL(clicked()), this, SLOT(onStart()));
  connect(mBackwardButton, SIGNAL(clicked()), this, SLOT(onStart()));
  connect(mSearchButton, SIGNAL(clicked()), this, SLOT(onStart()));
  connect(mStopButton, SIGNAL(clicked()), this, SLOT(onStop()));
  connect(mBigStopButton, SIGNAL(clicked()), this, SLOT(onStop()));
  connect(mXYButton, SIGNAL(clicked()), this, SLOT(onXYClick()));
  connect(mFLabel, SIGNAL(clicked()), this, SLOT(onFClick()));
  connect(mOperDirectionView, SIGNAL(directionChanged(OperDirectionView::eMoveDirection)), this,
      SLOT(onDirectionChange(OperDirectionView::eMoveDirection)));
  connect(mOperDirectionView, SIGNAL(directionChanged(OperDirectionView::eMoveDirection, eVelocity)), this,
      SLOT(onDirectionChange(OperDirectionView::eMoveDirection, eVelocity)));

  connect(mOperVelocityView, SIGNAL(velocityChanged(eVelocity)), this,
      SLOT(onVelocityChange(eVelocity)));
//  connect(mVelocityView, SIGNAL(velocityChanged(eVelocity)), this,
//      SLOT(onVelocityChange(eVelocity)));
  connect(plusButton, SIGNAL(clicked()), this, SLOT(onUpSpeed()));
  connect(minusButton, SIGNAL(clicked()), this, SLOT(onDownSpeed()));
//  connect(mFPlusButton, SIGNAL(clicked()), this, SLOT(onUpSpeed()));
//  connect(mFMinusButton, SIGNAL(clicked()), this, SLOT(onDownSpeed()));
  connect(mCycleButton, SIGNAL(clicked()), this, SLOT(onModeChange()));
  //connect(mStepButton, SIGNAL(clicked()), this, SLOT(onModeChange()));
  connect(mFastButton, SIGNAL(clicked()), this, SLOT(onModeChange()));
  connect(mNextWindow, SIGNAL(clicked()), this, SLOT(onNextWindow()));

  connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)),
      this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));

  registerManager();

  //StartCP();
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

void
CXOperDirectionWindow::onXYClick()
{
  if (mIsRunning)
    return;

  CXOperDirectionDialog dialog(qobject_cast<QWidget*>(sender()));
  dialog.mUdpManager = mUdpManager;
  dialog.exec();
}

void
CXOperDirectionWindow::onFClick()
{
  if(CXOperFeedDlg::createAndGetFeedDlg(this)){
    emit paramsChanged(true, QStringList() << "params.ini");
  }
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
        y = "+1";
      else
        x = "-1";
    }
    else
    {
      if(mRotateAxis)
        y = "-1";
      else
        x = "+1";
    }
  }

  if (aDirection != OperDirectionView::E_Top && aDirection != OperDirectionView::E_Bottom)
  {
    if (aDirection & OperDirectionView::E_Left)
    {
      if(mRotateAxis)
        x = "-1";
      else
        y = "-1";
    }
    else
    {
      if(mRotateAxis)
        x = "+1";
      else
        y = "+1";
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
      getDirectionCommand(aDirection));
}

void
CXOperDirectionWindow::onDirectionChange(OperDirectionView::eMoveDirection aDirection, eVelocity aVelocity)
{
  onVelocityChange(aVelocity);
  onDirectionChange(aDirection);
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
  default:
    break;
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
//  else if (sender() == mStepButton)
//  {
//    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_MODE_BY_STEP,
//        Commands::MSG_VALUE_INVERT);
//  }
  else if (sender() == mFastButton)
  {
    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_MODE_FEED,
        Commands::MSG_VALUE_INVERT);
  }
}

void
CXOperDirectionWindow::onNextWindow()
{
	lower();
	emit nextWindow();
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

  if (aSection ==  (Commands::MSG_SECTION_TECH))
  {
    if (aCommand ==  (Commands::MSG_STATE_COUNT_BURN)){
      mBurnEdit->setText(trUtf8("%1").arg(aValue));
    }
  }

  if (aSection ==  (Commands::MSG_SECTION_OPERATOR))
  {
    //Стоп
    if (aCommand ==  (Commands::MSG_STATE_STOP_CP))
    {
      StopCP();
    }

    //Запуск
    if (aCommand ==  (Commands::MSG_STATE_RUN_CP))
    {
      if (aValue ==  (Commands::MSG_VALUE_HAND))
        StopCP();
      else
        StartCP();
    }

    //Текущий кадр.
    if (aCommand ==  (Commands::MSG_STATE_CP_LINE))
    {
      mFrameEdit->setText(trUtf8("%1").arg(aValue));
    }

    //Режимы работы
    if (aCommand ==  (Commands::MSG_STATE_MODE_LOOP))
    {
      if (aValue ==  (Commands::MSG_VALUE_ON))
        mCycleButton->setStyleSheet("background-color: green;");
      else
        mCycleButton->setStyleSheet("");
    }
    else if (aCommand ==  (Commands::MSG_STATE_MODE_BY_STEP))
    {
//      if (aValue ==  (Commands::MSG_VALUE_ON))
//        mStepButton->setStyleSheet("background-color: green;");
//      else
//        mStepButton->setStyleSheet("");
    }
  }

  if (aSection ==  (Commands::MSG_SECTION_MOVE))
  {
    //Позиция осей.
    if (aCommand ==  (Commands::MSG_STATE_POS_AXIS))
    {
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
          mXEdit->setCursorPosition(0);
          break;
        }
        case 1:
        {
          mYEdit->setText(trUtf8("%1 мм").arg(axisPos, 0, 'f', 2));
          mYEdit->setCursorPosition(0);
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
    if (aCommand ==  (Commands::MSG_STATE_FEED_RESULT))
    {
      QString value = trUtf8("%1 мм/мин").arg(int((aValue.toFloat() / 1000.0) + 0.5));

      mFEdit->setText(value);
      mFEdit->setCursorPosition(0);
    }

    //Скорость работы (нормально, медленно, ускоренно)
    if (aCommand ==  (Commands::MSG_STATE_MODE_FEED))
    {
      eVelocity value = E_Normal;

      if (aValue ==  (Commands::MSG_VALUE_NORMAL)){
        mFastButton->setStyleSheet("");
        value = E_Normal;
      }else if (aValue ==  (Commands::MSG_VALUE_FAST)){
        mFastButton->setStyleSheet("background-color: green;");
        value = E_Boost;
      }else if (aValue ==  (Commands::MSG_VALUE_SLOW)){
        mFastButton->setStyleSheet("background-color: yellow;");
        value = E_Slow;
      }

//      std::cout << "onCommandReceive: value " << value << std::endl;
      mOperVelocityView->setVelocity(value);
      //mVelocityView->setVelocity(value);
    }

//    //Изменение скорости и направления.
//    if (aCommand ==  (Commands::MSG_STATE_HAND_DIR_MOVING))
//    {
//      QStringList values = aValue.split(",");
//      eVelocity velocity = E_NoVelocity;
//      OperDirectionView::eMoveDirection direction = OperDirectionView::E_NoDirection;
//
//      if (values.count() == 3)
//      {
//        if (values.first().length() == 3 && values.first().at(0) == 'F')
//        {
//          QString value = values.first().at(2);
//
//          if (value ==  (Commands::MSG_VALUE_NORMAL))
//            velocity = E_Normal;
//          if (value ==  (Commands::MSG_VALUE_FAST))
//            velocity = E_Boost;
//          if (value ==  (Commands::MSG_VALUE_SLOW))
//            velocity = E_Slow;
//        }
//
//        if (values.at(1).length() >= 3 && values.at(2).length() >= 3)
//        {
//          QString value1 = values.at(1);
//          QString value2 = values.at(2);
//          OperDirectionView::eMoveDirection xDirection = OperDirectionView::E_NoDirection;
//          OperDirectionView::eMoveDirection yDirection = OperDirectionView::E_NoDirection;
//
//          QMap <QString, OperDirectionView::eMoveDirection> xDirections;
//          xDirections.insert("-2", OperDirectionView::E_Top);
//          xDirections.insert("+2", OperDirectionView::E_Bottom);
//          xDirections.insert("0", OperDirectionView::E_Stop);
//
//          QMap <QString, OperDirectionView::eMoveDirection> yDirections;
//          yDirections.insert("-2", OperDirectionView::E_Left);
//          yDirections.insert("+2", OperDirectionView::E_Right);
//          yDirections.insert("0", OperDirectionView::E_Stop);
//
//          if (value1.at(0) == '0' || value2.at(0) == '0') value1 = (value1.at(0) == '0'? value1.mid(2) : value2.mid(2));
//          else value1 == " ";
//
//          if (value2.at(0) == '1' || value1.at(0) == '1') value2 = (value2.at(0) == '1'? value2.mid(2) : value1.mid(2));
//          else value2 == " ";
//
//          if (mRotateAxis)
//          {
//            if (yDirections.contains(value1)) yDirection = yDirections.value(value1);
//            if (xDirections.contains(value2)) xDirection = xDirections.value(value2);
//          }
//          else
//          {
//            if (xDirections.contains(value1)) xDirection = xDirections.value(value1);
//            if (yDirections.contains(value2)) yDirection = yDirections.value(value2);
//          }
//
//          if (xDirection == OperDirectionView::E_NoDirection || yDirection == OperDirectionView::E_NoDirection)
//          {
//            direction = OperDirectionView::E_NoDirection;
//          }
//          else if (xDirection == OperDirectionView::E_Stop || yDirection == OperDirectionView::E_Stop)
//          {
//            direction = OperDirectionView::E_Stop;
//          }
//          else direction = OperDirectionView::eMoveDirection(xDirection | yDirection);
//        }
//      }
//
//      if (velocity != E_NoVelocity && direction != OperDirectionView::E_NoDirection)
//      {
//        mOperDirectionView->blockSignals(true);
//        mOperDirectionView->setDirection(direction, velocity);
//        mOperDirectionView->blockSignals(false);
//      }
//    }

  }
}
