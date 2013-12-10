#include "CXOperTechnology.h"

#include <QRegExpValidator>

#include "CXUdpManager.h"
#include "CXSettingsXML.h"

CXOperTechnology::CXOperTechnology() :
    AXBaseWindow(), warmDlg(NULL)
{
  setupUi(this);

  //QVBoxLayout* vLayout_1 = new QVBoxLayout();
//  mTechnology= new CXTouchButton(vLayout_1);
  mTechnology->setText(QString().fromUtf8("Т: Газокислород"));

  //QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
  QHBoxLayout* horizontalLayout_2 = new QHBoxLayout();
  horizontalLayout_2->setSpacing(10);
//   horizontalLayout_2->setContentsMargins(3, 3, 3, 3);
   //horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
   horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
   mTButton = new CXTouchButton(frSuppList);
//   mTButton->setObjectName(QString::fromUtf8("mTButton"));
//   QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
//   sizePolicy1.setHorizontalStretch(0);
//   sizePolicy1.setVerticalStretch(0);
//   sizePolicy1.setHeightForWidth(mTButton->sizePolicy().hasHeightForWidth());
//   mTButton->setSizePolicy(sizePolicy1);
   mTButton->setText("T");
   mTButton->setCheckable(true);
   horizontalLayout_2->addWidget(mTButton);

   mZHButton = new CXTouchButton(frSuppList);
//   mZHButton->setObjectName(QString::fromUtf8("mZHButton"));
//   sizePolicy1.setHeightForWidth(mZHButton->sizePolicy().hasHeightForWidth());
//   mZHButton->setSizePolicy(sizePolicy1);
   mZHButton->setCheckable(true);
   horizontalLayout_2->addWidget(mZHButton);
   mZHButton->setText("Z");

   verticalLayout_2->addItem(horizontalLayout_2);
   verticalLayout_2->addStretch();

  int countOfSupp =  CXSettingsXML::getValue("settings.xml", "countOfSupp").toInt();

  for(int i = 0; i<countOfSupp; i++){
    QHBoxLayout* horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setSpacing(2);
    mbStateSup.push_back( new CXTouchButton(frSuppList));
    mbStateSup.last()->setCheckable(true);
    mbStateSup.last()->setText(QString().setNum(i + 1));
    connect(mbStateSup.last(), SIGNAL(toggled(bool)), this, SLOT(onButtonCheck()));

    horizontalLayout_4->addWidget(mbStateSup.last());

    mSVRZ.push_back( new QLabel(frSuppList));
    //  mSVRZ.last()->setAlignment(Qt::AlignCenter);
    mSVRZ.last()->setText("V:125");
    horizontalLayout_4->addWidget(mSVRZ.last());

    mbStateZ.push_back( new CXTouchButton(frSuppList));
    mbStateZ.last()->setCheckable(true);
    mbStateZ.last()->setText("Z" + QString().setNum(i + 1));
    mbStateZ.last()->setChecked(true);
    horizontalLayout_4->addWidget(mbStateZ.last());

    horizontalLayout_4->setAlignment(Qt::AlignCenter);
    //  verticalLayout_2->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum));
    verticalLayout_2->addItem(horizontalLayout_4);
    //  verticalLayout_2->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
    verticalLayout_2->addStretch();
  }
  verticalLayout_2->addStretch();

  mOperVelocity->setMode(E_SingleMode);
  mOperVelocity->setTexts(QList<QString>() << "^" << trUtf8("стоп\n-\nавто") << "v");

  //mStopButton->hide();

  connect(mTButton, SIGNAL(clicked()), this, SLOT(onTClick()));
  connect(mZHButton, SIGNAL(clicked()), this, SLOT(onZHClick()));

  connect(mBurnButton, SIGNAL(clicked()), this, SLOT(onStart()));
  connect(mRBurnButton, SIGNAL(clicked()), this, SLOT(onStart()));
  connect(mStopButton, SIGNAL(clicked()), this, SLOT(onStop()));
  connect(mCutModeButton, SIGNAL(clicked()), this, SLOT(onCutMode()));
  connect(mSVRButton, SIGNAL(clicked()), this, SLOT(onSVR()));
  connect(mMarkerButton, SIGNAL(clicked()), this, SLOT(onMarkerMode()));
  connect(mTechnology, SIGNAL(clicked()), this, SLOT(onTechnology()));

  connect(mOperVelocity, SIGNAL(velocityChanged(eVelocity)), this,
      SLOT(onVelocityChange(eVelocity)));

  connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)),
      this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));


//  QList<QAbstractButton*> buttons = mNuberButtonGroup->buttons();
//  for (int i = 0; i < buttons.count(); ++i)
//  {
//    connect(buttons.at(i), SIGNAL(toggled(bool)), this, SLOT(onButtonCheck()));
//  }

  registerManager();

//  mVoltages.append(mSVRZ);
//  mVoltages.append(mSVRZ2);
//  mVoltages.append(mLabel3);
//  mVoltages.append(mLabel4);

  mMarkerButton->setText(trUtf8("Указатель"));

  mCutModeButton->setText(trUtf8("Черчение"));
//
  warmDlg = new CXWarmingUpDlg(this);
  warmDlg->setWindowFlags(Qt::Dialog);
  warmDlg->registerContinueBreak(this, SLOT(onWarmUpConinueBreak(int)));
}

CXOperTechnology::~CXOperTechnology()
{

}

void
CXOperTechnology::onTClick()
{
  auto &buttons =  mbStateSup;//mNuberButtonGroup->buttons();

  bool isCheck = mTButton->isChecked();

  for (int i = 0; i < buttons.count(); ++i)
  {
    auto curButton = buttons.at(i);
    if (curButton->isChecked() == isCheck)
      continue;

    curButton->setChecked(isCheck);
  }
}

void
CXOperTechnology::onZHClick()
{
  auto &buttons = mbStateZ;
  bool isCheck  = mZHButton->isChecked();
  for (int i = 0; i < buttons.count(); ++i)
  {
    auto curButton = buttons.at(i);
    if (curButton->isChecked() == isCheck)
      continue;
    curButton->setChecked(isCheck);
  }
}

void
CXOperTechnology::onStart()
{
  if (sender() == mBurnButton)
  {
    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_BURN, "0");
  }

  if (sender() == mRBurnButton)
  {
    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_R_BURN, "0");
  }

  //mBurnButton->hide();
  //mRBurnButton->hide();
  mStopButton->show();
}

void
CXOperTechnology::onStop()
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_CUT2_OFF, "0");

  //mStopButton->hide();
  mBurnButton->show();
  mRBurnButton->show();
}

void
CXOperTechnology::onSVR()
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_MODE_SVR,
      MSG_VALUE_INVERT);
}

void
CXOperTechnology::onMarkerMode(){
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_MODE_POINTER,
      MSG_VALUE_INVERT);
  mUdpManager->sendCommand(Commands::MSG_SECTION_IO, "IOn7",
      "10=invert");
//TODO: qForm: сделать по уму
}

void
CXOperTechnology::onCutMode()
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_MODE_CUT,
      MSG_VALUE_INVERT);
}

void
CXOperTechnology::onVelocityChange(eVelocity aVelocity)
{
  QString value;

  switch (aVelocity)
  {
  case E_Slow:
    {
    value = "+2";
    break;
  }
  case E_Normal:
    {
    value = "0";
    break;
  }
  case E_Boost:
    {
    value = "-2";
    break;
  }
  }

  QString res;
  auto& buttons = mbStateZ;

  for (int i = 0; i < buttons.count(); ++i)
  {
    if (!res.isEmpty())
      res.append(",");

    if (buttons.at(i)->isChecked())
      res.append(QString("%1=%2").arg(i).arg(value));
    else
      res.append(QString("%1=0").arg(i));
  }

  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_HAND_DIR_MOVING_Z,
      res.toStdString());

  mOperVelocity->setVelocity(aVelocity);
}

void
CXOperTechnology::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{
  if (aSection == QString::fromStdString(Commands::MSG_SECTION_TECH))
  do{
    //Напряжение
    if (aCommand == QString::fromStdString(Commands::MSG_STATE_SVR_VOLTAGE))
    {
      QString currentValue;
      QStringList list = aValue.split(",");

      for (int i = 0; i < list.count(); i++)
      {
        currentValue = list.at(i);
        int index = QString(currentValue.at(0)).toInt();

        if (index >= 0 && index < mSVRZ.count())
        {
          mSVRZ.at(index)->setText(QString("V:")
              + currentValue.mid(currentValue.indexOf("=") + 1).left(3));
        }
      }
      break;
    }

    if (aCommand == QString::fromStdString(Commands::MSG_STATE_TECH))
    {
      QString currentValue;
      QStringList list = aValue.split(",");
      auto &buttons = mbStateSup;//mNuberButtonGroup->buttons();
      QAbstractButton* curButton = NULL;

      for (int i = 0; i < list.count(); i++)
      {
        currentValue = list.at(i);
        if (currentValue.length() < 3)
          continue;

        int index = QString(currentValue.at(0)).toInt();
        int value = QString(currentValue.at(2)).toInt();

        if (index >= 0 && index < buttons.count())
        {
          curButton = buttons.at(index);

          curButton->blockSignals(true);
          if (value == 0){
            curButton->setText(" ");
            curButton->setChecked(false);
          }else{
            curButton->setText(QString::number(index + 1));
            curButton->setChecked(true);
          }
//if (value <= 3) curButton->setText(QString::number(index + 1));
//if (value == 4) curButton->setText(trUtf8("Поиск\n0"));
//if (value == 5) curButton->setText(trUtf8("Поиск\nлиста"));
//
//if (value == 0 || value == 4) curButton->setChecked(false);
//if ((value >= 1 && value <= 3) || value == 5) curButton->setChecked(true);
          QString styleSheet = curButton->styleSheet();
          if (value <= 1 || value == 4 || value == 5)
            curButton->setStyleSheet("");
          if (value == 2)
            curButton->setStyleSheet("background-color: yellow;");
          if (value == 3)
            curButton->setStyleSheet("background-color: red;");

          curButton->blockSignals(false);
        }
      }
      break;
    }

    if (aCommand == QString::fromStdString(Commands::MSG_STATE_MODE_SVR))
    {
      if (aValue == QString::fromStdString(Commands::MSG_VALUE_ON))
        mSVRButton->setStyleSheet("background-color: green;");
      else
        mSVRButton->setStyleSheet("");
      break;
    }

    if (aCommand == QString::fromStdString(Commands::MSG_STATE_MODE_CUT))
    {
      if (aValue == QString::fromStdString(Commands::MSG_VALUE_ON))
      {
        mCutModeButton->setStyleSheet("background-color: green;");
        mCutModeButton->setText(trUtf8("Резка"));
      }
      else
      {
        mCutModeButton->setStyleSheet("");
        mCutModeButton->setText(trUtf8("Черчение"));
      }
      break;
    }
    if((aCommand == QString::fromStdString(Commands::MSG_STATE_WAITING) ) )
    {
      warmDlg->setStateWaiting(aValue);
      break;
    }

  }while(0);
}

void
CXOperTechnology::onButtonCheck()
{
  CXTouchButton* button = qobject_cast<CXTouchButton*>(sender());

  if (button != NULL)
  {
    auto &buttons = mbStateSup;

    int index = buttons.indexOf(button);
    QString res("%1=%2");

    if ( buttons[index]->isChecked()){
      res = res.arg(index).arg(QString::fromStdString(Commands::MSG_VALUE_TECH_READY));
    }
    else{
      res = res.arg(index).arg(QString::fromStdString(Commands::MSG_VALUE_TECH_DISACT));
    }
    //
    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_TS,
        res.toStdString());
  }
}


//Реакция на продолжить-прервать прогрев
void CXOperTechnology::onWarmUpConinueBreak(int _continueBreak){
//
  if(_continueBreak == CXWarmingUpDlg::_continue)
    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_WAITING_CONTINUE, "0");
  else
    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_WAITING_BREAK, "0");
}

//
void
CXOperTechnology::onTechnology()
{
//  if (warmDlg == NULL)
//  {
//    warmDlg = new CXWarmingUpDlg(this);
////    warmDlg->setAttribute(Qt::WA_DeleteOnClose);
//    warmDlg->setWindowFlags(Qt::Dialog);
////    mTurnDialog->setWindowModality(Qt::ApplicationModal);
////    connect(warmDlg, SIGNAL(compileNeeded()), this, SLOT(onCompileFile()));
//  }
  warmDlg->show();
}
