/*
 * CXAdditionalOperDirectionWindow.cpp
 *
 *  Created on: Aug 8, 2014
 *      Author: root
 */

#include "CXAdditionalOperDirectionWindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include "QtGui/qframe.h"
#include "QtGui/qlineedit.h"
#include <QtGui/QApplication>

#include "utils/CXProcess.h"
#include "CXTouchButton.h"
#include "CXUdpManager.h"

#define	A_AXIS_ID 3
#define A_AXIS_MAX_VALUE 500
#define	C_AXIS_ID 5
#define C_AXIS_MAX_VALUE 5600
#define	V_AXIS_ID 7
#define V_AXIS_MAX_VALUE 5600

int CXAdditionalOperDirectionWindow::GetAxisId(int _axisNumber){
  return axisParam[_axisNumber].first;
};

int CXAdditionalOperDirectionWindow::GetAxisPosInMap(int _axisId){
  switch (_axisId){
  case A_AXIS_ID:
    return axisParam.values().indexOf(QPair<int, QString>(A_AXIS_ID,"A"));
  case C_AXIS_ID:
    return axisParam.values().indexOf(QPair<int, QString>(C_AXIS_ID,"C"));
  case V_AXIS_ID:
    return axisParam.values().indexOf(QPair<int, QString>(V_AXIS_ID,"V"));
  }
  return -1;
};

QGroupBox* CXAdditionalOperDirectionWindow::CreateAxisGroup(QString _title, int _id, int _min, int _max){
  QGroupBox* groupBox = new QGroupBox(this);
  groupBox->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

  QVBoxLayout* groupBoxLayout = new QVBoxLayout(groupBox);
  groupBoxLayout->setMargin(7);
  groupBoxLayout->setSpacing(6);

  QHBoxLayout* editLayout = new QHBoxLayout;
  editLayout->setMargin(0);
  editLayout->setSpacing(6);

  //
  QLabel* lAxisName = new QLabel(_title, groupBox);
  editLayout->addWidget(lAxisName, 1);

  curAxisPos.append(new QSpinBox(groupBox));
  curAxisPos[nAxis]->setReadOnly(true);
  curAxisPos[nAxis]->setButtonSymbols(QAbstractSpinBox::NoButtons);
  curAxisPos[nAxis]->setMinimum(-10000);
  curAxisPos[nAxis]->setMaximum(10000);
  editLayout->addWidget(curAxisPos[nAxis],4);

  setAxisPos.append(new QSpinBox(groupBox));
  setAxisPos[nAxis]->setButtonSymbols(QAbstractSpinBox::NoButtons);
  setAxisPos[nAxis]->setMinimum(-10000);
  setAxisPos[nAxis]->setMaximum(10000);
  editLayout->addWidget(setAxisPos[nAxis],4);

  QLabel* lVal = new QLabel(trUtf8("0.1") + QChar(176), groupBox);
  editLayout->addWidget(lVal,2);

  groupBoxLayout->addLayout(editLayout);

  QHBoxLayout* buttonLayout = new QHBoxLayout;
  buttonLayout->setMargin(0);
  buttonLayout->setSpacing(6);

  //
  butRelMove.append(new CXTouchButton(trUtf8("Относительно"), groupBox));
  buttonLayout->addWidget(butRelMove[nAxis]);
  butAbsMove.append(new CXTouchButton(trUtf8("Абсолютно"), groupBox));
  buttonLayout->addWidget(butAbsMove[nAxis]);

  groupBoxLayout->addLayout(buttonLayout);

  //записываем значение
  axisParam.insert(nAxis,QPair<int, QString>(_id,_title));
  //увеличиваем количество осей
  nAxis++;
  return groupBox;
};

CXAdditionalOperDirectionWindow::CXAdditionalOperDirectionWindow() {
  QVBoxLayout* centralLayout = new QVBoxLayout(this);
  centralLayout->setMargin(5);
  nAxis = 0;
  centralLayout->addWidget(new QLabel(trUtf8("Управление поворотным блоком")));
  centralLayout->addWidget(CreateAxisGroup(trUtf8("A"), A_AXIS_ID, -A_AXIS_MAX_VALUE, A_AXIS_MAX_VALUE));
  centralLayout->addWidget(CreateAxisGroup(trUtf8("C"), C_AXIS_ID, -C_AXIS_MAX_VALUE, C_AXIS_MAX_VALUE));
//  centralLayout->addWidget(CreateAxisGroup(trUtf8("V"), V_AXIS_ID, -V_AXIS_MAX_VALUE, V_AXIS_MAX_VALUE));

  QHBoxLayout* butLayout = new QHBoxLayout(this);
  butLayout->addWidget(new CXTouchButton(trUtf8("В ноль"), NULL));
  butLayout->addStretch();
  butLayout->addWidget(new CXTouchButton(trUtf8("Фиксировать\nноль"), NULL));
  centralLayout->addLayout(butLayout);
  //пружинка
  centralLayout->addStretch();

  QHBoxLayout* buttonLayout = new QHBoxLayout;
  buttonLayout->setSpacing(10);

  backButton = new CXTouchButton(trUtf8("<<"), NULL);
  //backButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Minimum);
  buttonLayout->addWidget(backButton,1);

  blockButton = new CXTouchButton(trUtf8("Бл. слежения"), NULL);
  //backButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Minimum);
  buttonLayout->addWidget(blockButton,2);

  keyboardButton = new CXTouchButton(trUtf8("Клавиатура"), NULL);
  //keyboardButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Minimum);
  buttonLayout->addWidget(keyboardButton,3);

  centralLayout->addLayout(buttonLayout);

  connect(backButton, SIGNAL(clicked()), this, SLOT(onBackWindow()));
  connect(blockButton, SIGNAL(clicked()), this, SLOT(onBlockFollow()));
  connect(keyboardButton, SIGNAL(clicked()), this, SLOT(onStartKeyboard()));
  connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)),
      this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));
  for(int i = 0; i < nAxis; i++){
    connect(butRelMove[i], SIGNAL(clicked()), this, SLOT(onComporativeMove()));
    connect(butAbsMove[i], SIGNAL(clicked()), this, SLOT(onAbsoluteMove()));
  }

  registerManager();


}

CXAdditionalOperDirectionWindow::~CXAdditionalOperDirectionWindow() {
}

void CXAdditionalOperDirectionWindow::onStartKeyboard(){
  keyProcess = new CXProcess();
  keyProcess->start("startKeyboard.sh");
  connect(keyProcess, SIGNAL(finished(int, QProcess::ExitStatus))
      , this, SLOT(onKeyboardFinished(int, QProcess::ExitStatus)));
};

void CXAdditionalOperDirectionWindow::onBackWindow(){
  hide();
  emit backWindow();
};

void CXAdditionalOperDirectionWindow::onBlockFollow(){
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_MODE_BLOCK_FOLLOW, Commands::MSG_VALUE_INVERT);
};

void CXAdditionalOperDirectionWindow::onComporativeMove(){
  for (int i = 0; i < nAxis; i++){
    if (sender() == butRelMove[i])
    {
      QString res("%1=%2");
      res = res.arg(GetAxisId(i)).arg(setAxisPos[i]->value() * 100);
      mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_HAND_COMPARATIVE_MOVING, res);
    }
  };
};

void CXAdditionalOperDirectionWindow::onAbsoluteMove(){
  for (int i = 0; i < nAxis; i++){
    if (sender() == butAbsMove[i])
    {
      QString res("%1=%2");
      res = res.arg(GetAxisId(i)).arg(setAxisPos[i]->value() * 100);
      mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_HAND_ABSOLUTE_MOVING, res);
    }
  };
};

void CXAdditionalOperDirectionWindow::onKeyboardFinished(int aExitCode, QProcess::ExitStatus aExitStatus){
  if (keyProcess != NULL)
  {
    keyProcess->deleteLater();
    keyProcess = NULL;
  }
}

void
CXAdditionalOperDirectionWindow::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{


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
        int axisPos = axisPosStr.mid(indx + 1).toInt() / 100.0;//0.1mm
        indx = GetAxisPosInMap(axisIndx);
        if (indx != -1) curAxisPos[indx]->setValue(axisPos);
      }
    }else if (aCommand ==  (Commands::MSG_STATE_MODE_BLOCK_FOLLOW))
      {
        if (aValue ==  (Commands::MSG_VALUE_ON))
          blockButton->setStyleSheet("background-color: green;");
        else
          blockButton->setStyleSheet("");
      }
  }
}
