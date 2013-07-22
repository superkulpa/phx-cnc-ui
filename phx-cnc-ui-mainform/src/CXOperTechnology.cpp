#include "CXOperTechnology.h"

#include <QRegExpValidator>

#include "CXUdpManager.h"

CXOperTechnology::CXOperTechnology() :
    AXBaseWindow()
{
  setupUi(this);

//  QHBoxLayout* horizontalLayout_4 = new QHBoxLayout();
//
//  horizontalLayout_4->setSpacing(6);
////  horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
//
//  mbStateSup.push_back( new CXTouchButton(mButtonWidget));
//  mNuberButtonGroup = new QButtonGroup(CXOperTechnology);
////  mNuberButtonGroup->setObjectName(QString::fromUtf8("mNuberButtonGroup"));
//  mNuberButtonGroup->setExclusive(false);
//  mNuberButtonGroup->addButton(mbStateSup1);
//  mbStateSup1->setObjectName(QString::fromUtf8("mbStateSup1"));
//  sizePolicy1.setHeightForWidth(mbStateSup1->sizePolicy().hasHeightForWidth());
//  mbStateSup1->setSizePolicy(sizePolicy1);
//  mbStateSup1->setCheckable(true);
//
//  horizontalLayout_4->addWidget(mbStateSup1);
//
//  mSVRZ1 = new QLabel(mButtonWidget);
//  mSVRZ1->setObjectName(QString::fromUtf8("mSVRZ1"));
//  QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
//  sizePolicy2.setHorizontalStretch(0);
//  sizePolicy2.setVerticalStretch(0);
//  sizePolicy2.setHeightForWidth(mSVRZ1->sizePolicy().hasHeightForWidth());
//  mSVRZ1->setSizePolicy(sizePolicy2);
//  mSVRZ1->setAlignment(Qt::AlignCenter);
//
//  horizontalLayout_4->addWidget(mSVRZ1);
//
//  mbStateZ1 = new CXTouchButton(mButtonWidget);
//  mbStateZ1->setObjectName(QString::fromUtf8("mbStateZ1"));
//  sizePolicy1.setHeightForWidth(mbStateZ1->sizePolicy().hasHeightForWidth());
//  mbStateZ1->setSizePolicy(sizePolicy1);
//  mbStateZ1->setCheckable(true);
//
//  horizontalLayout_4->addWidget(mbStateZ1);
//
//
//  formLayout->setLayout(1, QFormLayout::LabelRole, horizontalLayout_4);
//
//
//  horizontalLayout_2->addLayout(formLayout);
//
//  mOperVelocity = new CXOperVelocityView(mButtonWidget);
//  mOperVelocity->setObjectName(QString::fromUtf8("mOperVelocity"));
//  QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
//  sizePolicy3.setHorizontalStretch(0);
//  sizePolicy3.setVerticalStretch(0);
//  sizePolicy3.setHeightForWidth(mOperVelocity->sizePolicy().hasHeightForWidth());
//  mOperVelocity->setSizePolicy(sizePolicy3);
//  mOperVelocity->setMinimumSize(QSize(75, 0));
//  mOperVelocity->setMaximumSize(QSize(130, 16777215));
//
//  horizontalLayout_2->addWidget(mOperVelocity);


  mCheckButtonGroup = new QButtonGroup(this);
  mCheckButtonGroup->addButton(mbStateZ1, 0);
  //mCheckButtonGroup->addButton(mbStateSup2, 0);
//  mCheckButtonGroup->addButton(pushButton_10, 0);
//  mCheckButtonGroup->addButton(pushButton_11, 0);
  mCheckButtonGroup->setExclusive(false);

  //mOperVelocity->setMode(E_SingleMode);
  mOperVelocity->setTexts(QList<QString>() << "" << trUtf8("стоп\n-\nавто") << "");

  mStopButton->hide();

  connect(mTButton, SIGNAL(clicked()), this, SLOT(onTClick()));
  connect(mZHButton, SIGNAL(clicked()), this, SLOT(onZHClick()));

  connect(mBurnButton, SIGNAL(clicked()), this, SLOT(onStart()));
  connect(mRBurnButton, SIGNAL(clicked()), this, SLOT(onStart()));
  connect(mStopButton, SIGNAL(clicked()), this, SLOT(onStop()));
  connect(mCutModeButton, SIGNAL(clicked()), this, SLOT(onCutMode()));
  connect(mSVRButton, SIGNAL(clicked()), this, SLOT(onSVR()));

  connect(mOperVelocity, SIGNAL(velocityChanged(eVelocity)), this,
      SLOT(onVelocityChange(eVelocity)));

  connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)),
      this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));

  QList<QAbstractButton*> buttons = mNuberButtonGroup->buttons();
  for (int i = 0; i < buttons.count(); ++i)
  {
    connect(buttons.at(i), SIGNAL(toggled(bool)), this, SLOT(onButtonCheck()));
  }

  registerManager();

  mVoltages.append(mSVRZ1);
//  mVoltages.append(mSVRZ2);
//  mVoltages.append(mLabel3);
//  mVoltages.append(mLabel4);

  mCutModeButton->setText(trUtf8("Черчение"));
}

CXOperTechnology::~CXOperTechnology()
{

}

void
CXOperTechnology::onTClick()
{
  QList<QAbstractButton*> buttons = mNuberButtonGroup->buttons();

  bool isCheck = !(mNuberButtonGroup->checkedButton() != NULL);

  QString res;
  QAbstractButton* curButton = NULL;

  for (int i = 0; i < buttons.count(); ++i)
  {
    curButton = buttons.at(i);
    if (curButton->isChecked() == isCheck)
      continue;

    curButton->blockSignals(true);
    curButton->setChecked(isCheck);
    curButton->blockSignals(false);

    if (!res.isEmpty())
      res.append(",");

    res.append(QString("%1=%2").arg(i).arg(curButton->isChecked() ? "1" : "0"));
  }

  mUdpManager->sendCommand(Commands::MSG_SECTION_TECH, Commands::MSG_CMD_TS, res.toStdString());
}

void
CXOperTechnology::onZHClick()
{
  QList<QAbstractButton*> buttons = mCheckButtonGroup->buttons();

  bool isCheck = !(mCheckButtonGroup->checkedButton() != NULL);

  for (int i = 0; i < buttons.count(); ++i)
  {
    buttons.at(i)->setChecked(isCheck);
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

  mBurnButton->hide();
  mRBurnButton->hide();
  mStopButton->show();
}

void
CXOperTechnology::onStop()
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_CUT2_OFF, "0");

  mStopButton->hide();
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
    value = "-2";
    break;
  }
  case E_Normal:
    {
    value = "0";
    break;
  }
  case E_Boost:
    {
    value = "+2";
    break;
  }
  }

  QString res;
  QList<QAbstractButton*> buttons = mCheckButtonGroup->buttons();

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
}

void
CXOperTechnology::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{
  if (aSection == QString::fromStdString(Commands::MSG_SECTION_TECH))
  {
    //Напряжение
    if (aCommand == QString::fromStdString(Commands::MSG_STATE_SVR_VOLTAGE))
    {
      QString currentValue;
      QStringList list = aValue.split(",");

      for (int i = 0; i < list.count(); i++)
      {
        currentValue = list.at(i);
        int index = QString(currentValue.at(0)).toInt() - 1;

        if (index >= 0 && index < 4)
        {
          mVoltages.at(index)->setText(currentValue.mid(currentValue.indexOf("=") + 1));
        }
      }
    }

    if (aCommand == QString::fromStdString(Commands::MSG_STATE_TECH))
    {
      QString currentValue;
      QStringList list = aValue.split(",");
      QList<QAbstractButton*> buttons = mNuberButtonGroup->buttons();
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
          curButton = buttons.at(index - 1);

          curButton->blockSignals(true);
          if (value == 0)
            curButton->setText("");
          else
            curButton->setText(QString::number(index));
//					if (value <= 3) curButton->setText(QString::number(index + 1));
//					if (value == 4) curButton->setText(trUtf8("Поиск\n0"));
//					if (value == 5) curButton->setText(trUtf8("Поиск\nлиста"));

//					if (value == 0 || value == 4) curButton->setChecked(false);
//					if ((value >= 1 && value <= 3) || value == 5) curButton->setChecked(true);

          if (value <= 1 || value == 4 || value == 5)
            curButton->setStyleSheet("");
          if (value == 2)
            curButton->setStyleSheet("background-color: yellow;");
          if (value == 3)
            curButton->setStyleSheet("background-color: red;");

          curButton->blockSignals(false);
        }
      }
    }

    if (aCommand == QString::fromStdString(Commands::MSG_STATE_MODE_SVR))
    {
      if (aValue == QString::fromStdString(Commands::MSG_VALUE_ON))
        mSVRButton->setStyleSheet("background-color: green;");
      else
        mSVRButton->setStyleSheet("");
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
    }
  }
}

void
CXOperTechnology::onButtonCheck()
{
  QAbstractButton* button = qobject_cast<QAbstractButton*>(sender());

  if (button != NULL)
  {
    QList<QAbstractButton*> buttons = mNuberButtonGroup->buttons();

    int index = buttons.indexOf(button);
    QString res("%1=%2");

    if (! buttons[index]->isChecked())
      res = res.arg(index + 1).arg(QString::fromStdString(Commands::MSG_VALUE_TECH_READY));
    else
      res = res.arg(index + 1).arg(QString::fromStdString(Commands::MSG_VALUE_TECH_DISACT));
    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_TS,
        res.toStdString());
  }
}
