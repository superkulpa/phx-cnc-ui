#include <iostream>
#include <stdexcept>
#include <bitset>
#include "version.h"

#include "CXOperTechnology.h"

#include <QRegExpValidator>

#include "CXUdpManager.h"
#include "utils/CXSettingsXML.h"
#include "CXTechDlg.h"
#include "utils/iniFile.h"

CXOperTechnology::CXOperTechnology() :
    AXBaseWindow(), warmDlg(NULL)
{
  setupUi(this);

  //QVBoxLayout* vLayout_1 = new QVBoxLayout();
//  mTechnology= new CXTouchButton(vLayout_1);
  mTechnology->setLongPress(true);
  mTechnology->setText(QString().fromUtf8("Газокислород"));

//  QHBoxLayout* horizontalLayout_2 = new QHBoxLayout();
//  horizontalLayout_2->setSpacing(10);
//   horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
//   mTButton = new CXTouchButton(frSuppList);
//   mTButton->setText("T");
//   mTButton->setCheckable(true);
//   horizontalLayout_2->addWidget(mTButton);
//
//   mZHButton = new CXTouchButton(frSuppList);
//   mZHButton->setCheckable(true);
//   horizontalLayout_2->addWidget(mZHButton);
//   mZHButton->setText("Z");
//
//   verticalLayout_2->addItem(horizontalLayout_2);
   verticalLayout_2->addStretch();

  mOperVelocity->setMode(E_SingleMode);
  mOperVelocity->setTexts(QList<QString>() << "^" << trUtf8("стоп\n-\nавто") << "v");

  //mStopButton->hide();

//  connect(mTButton, SIGNAL(clicked()), this, SLOT(onTClick()));
//  connect(mZHButton, SIGNAL(clicked()), this, SLOT(onZHClick()));

  connect(mBurnButton, SIGNAL(clicked()), this, SLOT(onStart()));
  connect(mRBurnButton, SIGNAL(clicked()), this, SLOT(onStart()));
  connect(mStopButton, SIGNAL(clicked()), this, SLOT(onStop()));
  connect(mCutModeButton, SIGNAL(clicked()), this, SLOT(onCutMode()));
  connect(mSVRButton, SIGNAL(clicked()), this, SLOT(onSVR()));
  connect(mMarkerButton, SIGNAL(clicked()), this, SLOT(onMarkerMode()));
  connect(mTechnology, SIGNAL(clicked()), this, SLOT(onTechnologyButton()));

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
//заполнение списка технологий
  {
  CIniFile iniFile("jini/config.ini");
  iniFile.ReadIniFile();
  int key = iniFile.FindKey("Form/Technologies");//MPlasma=Микроплазма
  uint32_t i = 0;
  do try{
//    QString nameOfTech = QString::fromStdString(iniFile.ValueName(key, i));//MPlasma
//    if(nameOfTech.isEmpty())
//      throw std::runtime_error("valueName is empty");

//    QStringList values = QString::fromUtf8(iniFile.GetValue(key, i, "0,empty").c_str()).split(",");
//    int nSup = values[0].toInt();
//    if(nSup == 0) {// нет числа суппорт
//      continue;
//    }
//    QString descr = values[1];

    //Oxy=type=TM:Oxy,name=Support2,tag=1,zCtrl=zCtrl2,gc=oxyGC,vl=1,ishead,mngr=Oxy2,mngr=Oxy3

    int maskSup = 0;

    std::string entryName = iniFile.ValueName(key, i);
    if(entryName.empty())
      throw std::runtime_error("entryName is empty");

    QString descr = QString::fromUtf8(iniFile.GetValue(key, i, "empty").c_str());
    if(descr.isEmpty()) continue;

    QString nameOfTech = QString::fromStdString(entryName);
    listOfTechs[nameOfTech] = descr;

    QString entry = QString::fromStdString(iniFile.GetValue("Modules", entryName, ""));

    struct calcMask{ int operator ()(const QString& entry){
        bool isOk = false;
        int tag =  entry.split(",").filter("tag=").value(0).split("=").value(1).toInt(&isOk);
        if(isOk)return (1<<tag);
        return 0;}
    };

    maskSup += calcMask()(entry);

    QStringList ql = entry.split(",").filter("mngr=");
    for(auto &ql_item: ql){
      entryName = (ql_item).split("=").value(1).toStdString();

      entry = QString::fromStdString(iniFile.GetValue("Modules", entryName, ""));
      maskSup += calcMask()(entry);
    }

    listOfSupps[nameOfTech] = maskSup;
  }catch(std::exception& e){
    LOG_E(ERROR);
  }while(++i < iniFile.NumValues(key));
  }

  {

    int countOfSupp = 0;// CXSettingsXML::getValue("settings.xml", "countOfSupp").toInt();
    for(auto it = listOfSupps.begin(); it != listOfSupps.end(); ++it){
      countOfSupp += std::bitset<32>(it->second).count();
    }

    for(int i = 0; i<countOfSupp; i++){
      QHBoxLayout* horizontalLayout_4 = new QHBoxLayout();
      horizontalLayout_4->setSpacing(2);
      mbStateSup.push_back( new CXTouchButton(frSuppList));
      mbStateSup.last()->setCheckable(true);
      mbStateSup.last()->setText(QString().setNum(i + 1));
      mbStateSup.last()->setProperty("indx", (QString().setNum(i)));
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
  }
  currTech = listOfTechs.begin();
  mTechnology->setText(currTech->second);
  CXTechDlg::create(this, listOfTechs,  SLOT(onTechDlgClose(const QString&)) );

  //QTimer::singleShot(0, this, );
  onCommandReceive( Commands::MSG_SECTION_TECH, Commands::MSG_STATE_TECHNOLOGY , currTech->first);
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
//  mUdpManager->sendCommand(Commands::MSG_SECTION_IO, "IOn7",
//      "10=invert");
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
  default:;
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

  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_HAND_DIR_MOVING_Z, res);

  mOperVelocity->setVelocity(aVelocity);
}

void
CXOperTechnology::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{
  if (aSection ==  (Commands::MSG_SECTION_TECH))
  do{
    //Напряжение
    if (aCommand ==  (Commands::MSG_STATE_SVR_VOLTAGE))
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

    if (aCommand ==  (Commands::MSG_STATE_TECH))
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
        //0=disact
        int index = QString(currentValue.at(0)).toInt();
        QStringRef value = currentValue.rightRef(currentValue.length() - 2);

        if (index >= 0 && index < buttons.count())
        {
          curButton = buttons.at(index);

          curButton->blockSignals(true);
          if (value == MSG_VALUE_TECH_DISACT){
            curButton->setText(" ");
            curButton->setStyleSheet("");
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
//          QString styleSheet = curButton->styleSheet();
//          if (value <= 1 || value == 4 || value == 5)
//            curButton->setStyleSheet("");
          if (value == MSG_VALUE_TECH_FIRE)
            curButton->setStyleSheet("background-color: yellow;");
          else if (value == MSG_VALUE_TECH_CUT)
            curButton->setStyleSheet("background-color: red;");
          else if (value == MSG_VALUE_TECH_READY)
            curButton->setStyleSheet("background-color: ;");

          curButton->blockSignals(false);
        }
      }
      break;
    }

    if (aCommand ==  (Commands::MSG_STATE_MODE_POINTER))
    {
      if (aValue ==  (Commands::MSG_VALUE_ON))
        mMarkerButton->setStyleSheet("background-color: green;");
      else
        mMarkerButton->setStyleSheet("");
      break;
    }
    if (aCommand ==  (Commands::MSG_STATE_MODE_SVR))
    {
      if (aValue ==  (Commands::MSG_VALUE_ON))
        mSVRButton->setStyleSheet("background-color: green;");
      else
        mSVRButton->setStyleSheet("");
      break;
    }
    if (aCommand ==  (Commands::MSG_STATE_MODE_CUT))
    {
      if (aValue ==  (Commands::MSG_VALUE_ON))
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

    if (aCommand ==  (Commands::MSG_STATE_MODE_CUT))
    {
      if (aValue ==  (Commands::MSG_VALUE_ON))
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
    if((aCommand ==  (Commands::MSG_STATE_WAITING) ) )
    {
      warmDlg->setStateWaiting(aValue);
      break;
    }
    if((aCommand ==  (Commands::MSG_STATE_TECHNOLOGY) ) )
    {
    try{
      //QStringList values = aValue.split("=");//Oxy=4,Кислород

      currTech = listOfTechs.find(aValue);
      if(currTech == listOfTechs.end()) throw std::runtime_error(QString("Unknown tech: %1").arg(aValue).toUtf8().begin());

      mTechnology->setText(currTech->second);
      int suppMask = listOfSupps[aValue];
      for(int i=0; i<mbStateSup.size(); i++){
        bool visi = (1<<i) & suppMask;
        mbStateSup[i]->setVisible(visi);
        mSVRZ[i]     ->setVisible(visi);
        mbStateZ[i]  ->setVisible(visi);
        mbStateZ[i]  ->setChecked(visi);
      }

      emit eventTechnologyChanged(currTech->first);
    }catch(std::exception& e){
      LOG_E(ERROR);
    }
    }

  }while(0);
}

void
CXOperTechnology::onButtonCheck()
{
  CXTouchButton* button = qobject_cast<CXTouchButton*>(sender());

  if (button != NULL)
  {
    //auto &buttons = mbStateSup;

    int index = button->property("indx").toInt();
    QString res("%1=%2");

    if ( button->isChecked()){
      res = res.arg(index).arg( (Commands::MSG_VALUE_TECH_READY));
    }
    else{
      res = res.arg(index).arg( (Commands::MSG_VALUE_TECH_DISACT));
    }
    //
    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_TS, res);
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
CXOperTechnology::onTechnologyButton()
{
  CXTechDlg::getInstance()->show();
}

void
CXOperTechnology::onTechDlgClose(const QString& _tech)
{
  if(_tech.isEmpty())return;
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_TECHNOLOGY, _tech);
//  onCommandReceive( (Commands::MSG_SECTION_TECH),  (Commands::MSG_STATE_TECHNOLOGY), _tech);
}