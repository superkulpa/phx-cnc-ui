/*
 * CXZParamui.cpp
 *
 *  Created on: 09 апр. 2014 г.
 *      Author: tsvet
 */

#include "CXZParamui.h"

#include <QProcess>
#include <QFile>
#include <QTimer>
#include <QtGui/qmessagebox.h>
#include <QLineEdit>
#include <QKeyEvent>
#include <qdebug.h>

#include "utils/CXParamData.h"
#include "CXUdpManager.h"

#define XML_PATH "settings.xml"

#define suppCount  2
CXZParamUi::CXZParamUi() :
    AXBaseWindow()
{


  ui.setupUi(this);

//  if (!QFile::exists(INI_PATH))
//  {
//    QFile iniFile(INI_PATH);
//    iniFile.open(QIODevice::WriteOnly);
//    iniFile.close();
//  }
  ui.mValuesScroll->setWidgetResizable(true);

  QWidget* valueWidget = new QWidget(ui.mValuesScroll);
  valueWidget->setObjectName("valueWidget");
  ui.mValuesScroll->setWidget(valueWidget);
//  valueWidget->setStyleSheet("background-color: silver;");
  mValuesLayout = new QVBoxLayout(valueWidget);

  QLabel* zNumber = NULL;
  QDoubleSpinBox* zPosEditor = NULL;
  CXTouchButton* fixZPos = NULL;
  QDoubleSpinBox* vEditor = NULL;
  CXTouchButton* fixV = NULL;
  QGroupBox* groupBox = NULL;
  QGridLayout* groupLayout = NULL;
  for(int i = 0; i < suppCount; i++){
	  groupBox = new QGroupBox(valueWidget);
	  groupLayout = new QGridLayout(groupBox);

	  zNumber = new QLabel(groupBox);
	  zNumber->setText(trUtf8("%1").arg(i + 1));
	  zNumber->setMaximumWidth(40);
	  zNumber->setMargin(2);

	  zPosEditor = new QDoubleSpinBox(groupBox);
	  zPosEditor->setMaximum (10000);
	  zPosEditor->setMinimum (-10000);
	  zPosEditor->setDecimals(2);
	  mZPosEditors.append(zPosEditor);
	  groupLayout->addWidget(zPosEditor, i * 2, 1);


	  fixZPos = new CXTouchButton(groupBox);
	  fixZPos->setText(trUtf8("Фиксировать"));
	  fixZPos->setProperty("indx", i + 1);
	  mfixZPos.append(fixZPos);
	  connect(mfixZPos[mfixZPos.count() - 1], SIGNAL(clicked()), this, SLOT(onFixZPosButtonClicked()));
	  groupLayout->addWidget(fixZPos, i * 2, 2);

	  vEditor = new QDoubleSpinBox(groupBox);
	  vEditor->setMaximum (100);
	  vEditor->setDecimals(1);
	  mVEditors.append(vEditor);
	  groupLayout->addWidget(vEditor, i * 2 + 1, 1);

	  fixV = new CXTouchButton(groupBox);
	  fixV->setText(trUtf8("Фиксировать"));
	  fixV->setProperty("indx", i + 1);
	  mfixV.append(fixV);

	  connect(mfixV[mfixV.count() - 1], SIGNAL(clicked()), this, SLOT(onFixVButtonClicked()));
	  groupLayout->addWidget(fixV, i * 2 + 1, 2);

	  groupLayout->addWidget(zNumber, i * 2, 0, 2, 1);

	  mValuesLayout->addWidget(groupBox);
  }
  mValuesLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

  connect(ui.mButton0, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton1, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton2, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton3, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton4, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton5, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton6, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton7, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton8, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton9, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButtonBackspace, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButtonDel, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButtonDot, SIGNAL(clicked()), this, SLOT(onButtonClicked()));

  connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)),
		  	  	  this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));
  registerManager();
}

CXZParamUi::~CXZParamUi()
{
}

void CXZParamUi::setVisible(bool visible){
	if(visible)
		AXBaseWindow::mUdpManager->sendCommand(Commands::MSG_SECTION_IO,
      		Commands::MSG_CMD_ADC_START, "0");
    else
    	AXBaseWindow::mUdpManager->sendCommand(Commands::MSG_SECTION_IO,
    	    Commands::MSG_CMD_ADC_STOP, "0");
	AXBaseWindow::setVisible(visible);
};

void
CXZParamUi::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{
	if(! isVisible()) return;
	if (aSection ==  (Commands::MSG_SECTION_IO))
	{
	 //TODO сделать нормально
	  if(aCommand.indexOf("Z1") != -1){
		//1 суппорт
		QStringList list = aValue.split(",");
		for (int i = 0; i < list.size(); i++) {
		  const QString& curValue = list.at(i);
		  int index = curValue.indexOf("=");
		  int channelNumber = curValue.mid(0, index).toInt();

		  if (channelNumber < 0)	continue;
		  if (channelNumber == 16) mVEditors[0]->setValue(curValue.mid(index + 1).toInt() / 10);
		}
	  }
	}else if (aSection ==  (Commands::MSG_SECTION_TECH)) {
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
			qDebug(trUtf8("%1").arg(axisIndx).toStdString().c_str());
			qDebug(trUtf8("%1").arg(axisPos).toStdString().c_str());
     	    mZPosEditors[axisIndx]->setValue(axisPos);
		  }

		}
	 };
}


void
CXZParamUi::onButtonClicked()
{
  QAbstractButton* button = qobject_cast<QAbstractButton*>(sender());

  if (button != NULL && !button->shortcut().isEmpty())
  {
    int keyCode = button->shortcut()[0];

    QWidget* focusedWidget = focusWidget();

    QKeyEvent keyPress(QEvent::KeyPress, keyCode, Qt::NoModifier, button->shortcut().toString());
    QApplication::sendEvent(focusedWidget, &keyPress);

    QKeyEvent keyRelease(QEvent::KeyRelease, keyCode, Qt::NoModifier,
        button->shortcut().toString());
    QApplication::sendEvent(focusedWidget, &keyRelease);

    return;
  }
}

void
CXZParamUi::onFixZPosButtonClicked()
{
  int indx = sender()->property("indx").toInt();
  QString suppName = "Support" + sender()->property("indx").toString();
  //qDebug(trUtf8("%1").arg(indx).toStdString().c_str());
  //сохраняем позицию быстрого поиска
  QString suppPath = QApplication::applicationDirPath() + "/jini/params" + suppName + ".ini";
  CIniFile suppFile(suppPath.toStdString());
  suppFile.ReadIniFile();
  suppFile.SetValue(suppName.toStdString() + "/ZDownFast" ,"value",mZPosEditors[indx - 1]->text().toStdString(),true);
  suppFile.WriteIniFile();
  emit iniSaved();
}

void
CXZParamUi::onFixVButtonClicked()
{
  int indx = sender()->property("indx").toInt();
  //qDebug(trUtf8("%1").arg(indx).toStdString().c_str());
  //сохраняем вольты в уровень стабилизации
  QString suppName = "Support" + sender()->property("indx").toString();
  //qDebug(trUtf8("%1").arg(indx).toStdString().c_str());
  //сохраняем позицию быстрого поиска
  QString suppPath = QApplication::applicationDirPath() + "/jini/params" + suppName + ".ini";
  CIniFile suppFile(suppPath.toStdString());
  suppFile.ReadIniFile();
  int koef = suppFile.GetValueI(suppName.toStdString() + "/THC/ZVFactor","value", 1);
  double val = mVEditors[indx - 1]->value() * koef;
  suppFile.SetValue(suppName.toStdString() + "/THC/ZHunt","value", trUtf8("%1").arg(val).toStdString());
  suppFile.WriteIniFile();
  emit iniSaved();
}


