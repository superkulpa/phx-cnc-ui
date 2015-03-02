#include "CXParamui.h"

#include <QProcess>
#include <QFile>
#include <QTimer>
#include <QLineEdit>
#include <QKeyEvent>
#include <qdebug.h>

#include "CXSupports.h"
#include "utils/CXParamData.h"
#include "CXUdpManager.h"

//struct G30_Messages{
//  typedef QString String;
//  //секция G30, разведенеи суппортов
//  public static String MSG_SECTION_G30 = "g30";
//
//  public static String MSG_CMD_FIX_AXIS = "cmd_fix_axis";
//  public static String MSG_STATE_FIX_AXIS = "state_fix_axis";
//  //значения могут идти через запятую: "0=+1,1=-1,2=0
//  public static String MSG_VALUE_FIX_AXIS0F = "0=+1"; //прямая
//  public static String MSG_VALUE_FIX_AXIS0B = "0=-1"; //обратная
//  public static String MSG_VALUE_FIX_AXIS0S = "0=0";  //портал
//
//  public static String MSG_VALUE_FIX_AXIS1F = "1=+1";
//  public static String MSG_VALUE_FIX_AXIS1B = "1=-1";
//  public static String MSG_VALUE_FIX_AXIS1S = "1=0";
//
//  public static String MSG_VALUE_FIX_AXIS2F = "2=+1";
//  public static String MSG_VALUE_FIX_AXIS2B = "2=-1";
//  public static String MSG_VALUE_FIX_AXIS2S = "2=0";
//
//  public static String MSG_VALUE_FIX_AXIS3F = "3=+1";
//  public static String MSG_VALUE_FIX_AXIS3B = "3=-1";
//  public static String MSG_VALUE_FIX_AXIS3S = "3=0";
//  };
//G30_Messages g30;

CXSupportsWindow::CXSupportsWindow() : AXBaseWindow()
{
  ui.setupUi(this);
  connect(ui.cutY1,   SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.frwrdY1, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.stopY1,  SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.bkwrdY1, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.cutY2,   SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.frwrdY2, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.stopY2,  SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.bkwrdY2, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.cutY3,   SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.frwrdY3, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.stopY3,  SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.bkwrdY3, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.cutY4,   SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.frwrdY4, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.stopY4,  SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.bkwrdY4, SIGNAL(clicked()), this, SLOT(onButtonClicked()));

  connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)),
      this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));
  cutButtons.push_back(ui.cutY1);
  cutButtons.push_back(ui.cutY2);
  cutButtons.push_back(ui.cutY3);
  cutButtons.push_back(ui.cutY4);
  for(auto button: cutButtons) button->setProperty("cut", 0);

  registerManager();
}

CXSupportsWindow::~CXSupportsWindow()
{
}

void CXSupportsWindow::onButtonClicked()
{
  QAbstractButton* button = qobject_cast<QAbstractButton*>(sender());
//todo: qForm.5 рефакторить фикс суппортов
  if (button == ui.cutY1 )
  {
    if(ui.cutY1->property("cut") == 0){
      mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, "cmd_tech23", "0");
    }else{
      mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_CUT2_OFF, "0");
    }
    return;//cmd_tech23#0$
  }
  if (button == ui.frwrdY1 )
  {
    mUdpManager->sendCommand("G30", "cmd_fix_axis", "0=+1");
    return;
  }
  if (button == ui.stopY1 )
  {
    mUdpManager->sendCommand("G30", "cmd_fix_axis", "0=0");
    return;
  }
  if (button == ui.bkwrdY1 )
  {
    mUdpManager->sendCommand("G30", "cmd_fix_axis", "0=-1");
    return;
  }
  if (button == ui.cutY2 )
  {
    if(ui.cutY2->property("cut") == 0){
      mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, "cmd_tech23", "1");
    }else{
      mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_CUT2_OFF, "1");
    }
    return;
  }
  if (button == ui.frwrdY2 )
  {
    mUdpManager->sendCommand("G30", "cmd_fix_axis", "1=+1");
    return;
  }
  if (button == ui.stopY2 )
  {
    mUdpManager->sendCommand("G30", "cmd_fix_axis", "1=0");
    //mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_CUT2_OFF, "1");
    return;
  }
  if (button == ui.bkwrdY2 )
  {
    mUdpManager->sendCommand("G30", "cmd_fix_axis", "1=-1");
    return;
  }
  if (button == ui.cutY3 )
  {
    if(ui.cutY3->property("cut") == 0)
      mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, "cmd_tech23", "2");
    else
      mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_CUT2_OFF, "2");


    return;
  }
  if (button == ui.frwrdY3 )
  {
    mUdpManager->sendCommand("G30", "cmd_fix_axis", "2=+1");
    return;
  }
  if (button == ui.stopY3 )
  {
    mUdpManager->sendCommand("G30", "cmd_fix_axis", "2=0");
//    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_CUT2_OFF, "2");
    return;
  }
  if (button == ui.bkwrdY3 )
  {
    mUdpManager->sendCommand("G30", "cmd_fix_axis", "2=-1");
    return;
  }
  if (button == ui.cutY4 )
  {
    if(ui.cutY4->property("cut") == 0)
      mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, "cmd_tech23", "3");
    else
      mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_CUT2_OFF, "3");

    return;
  }
  if (button == ui.frwrdY4 )
  {
    mUdpManager->sendCommand("G30", "cmd_fix_axis", "3=+1");
    return;
  }
  if (button == ui.stopY4 )
  {
    mUdpManager->sendCommand("G30", "cmd_fix_axis", "3=0");
//    mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_CUT2_OFF, "3");
    return;
  }
  if (button == ui.bkwrdY4 )
  {
    mUdpManager->sendCommand("G30", "cmd_fix_axis", "3=-1");
    return;
  }

}

void CXSupportsWindow::setVisible(bool visible) {
//  if(visible)
//    mUdpManager->sendCommand("G30", Commands::MSG_CMD_FORM_RESTART, "1");
//  else
//    mUdpManager->sendCommand("G30", Commands::MSG_CMD_FORM_RESTART, "0");
  AXBaseWindow::setVisible(visible);
}

void
CXSupportsWindow::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{
  if (aSection ==  "G30")
  {
    if (aCommand ==  "state_fix_axis"){//0=+1,1=0,2=-1
      QStringList sl = aValue.split(',');
      for(auto sl_it: sl){
        //QStringList sl2 = *sl_it.split('=')
        const QChar c = sl_it.at(0);
        int dir = sl_it.remove(0, 2).toInt();
        switch(c.toAscii()){
        case '0':
          ui.frwrdY1->setStyleSheet("");
          ui.stopY1->setStyleSheet("");
          ui.bkwrdY1->setStyleSheet("");
          switch(dir){
          case  0: ui.stopY1->setStyleSheet("background-color: green;"); break;
          case +1: ui.frwrdY1->setStyleSheet("background-color: green;"); break;
          case -1: ui.bkwrdY1->setStyleSheet("background-color: green;"); break;
          }
        break;
        case '1':
          ui.frwrdY2->setStyleSheet("");
          ui.stopY2->setStyleSheet("");
          ui.bkwrdY2->setStyleSheet("");
          switch(dir){
          case  0: ui.stopY2->setStyleSheet("background-color: green;"); break;
          case +1: ui.frwrdY2->setStyleSheet("background-color: green;"); break;
          case -1: ui.bkwrdY2->setStyleSheet("background-color: green;"); break;
          }
        break;
        case '2':
          ui.frwrdY3->setStyleSheet("");
          ui.stopY3->setStyleSheet("");
          ui.bkwrdY3->setStyleSheet("");
          switch(dir){
          case  0: ui.stopY3->setStyleSheet("background-color: green;"); break;
          case +1: ui.frwrdY3->setStyleSheet("background-color: green;"); break;
          case -1: ui.bkwrdY3->setStyleSheet("background-color: green;"); break;
          }
        break;
        case '3':
          ui.frwrdY4->setStyleSheet("");
          ui.stopY4->setStyleSheet("");
          ui.bkwrdY4->setStyleSheet("");
          switch(dir){
          case  0: ui.stopY4->setStyleSheet("background-color: green;"); break;
          case +1: ui.frwrdY4->setStyleSheet("background-color: green;"); break;
          case -1: ui.bkwrdY4->setStyleSheet("background-color: green;"); break;
          }
        break;
        }
      }
    }
    return ;
  }
  if (aSection ==  Commands::MSG_SECTION_TECH){
    if (aCommand ==  (Commands::MSG_STATE_TECH))
    {
    QStringList list = aValue.split(",");
    QAbstractButton* curButton = NULL;
//udp:TM#state_TS#0=fire$
    for (int i = 0; i < list.count(); i++)
    {
      const QString& currentValue = list.at(i);
      if (currentValue.length() < 3)
        continue;
      //0=disact
      int index = QString(currentValue.at(0)).toInt();
      QStringRef value = currentValue.rightRef(currentValue.length() - 2);

      if (index >= 0 && index < cutButtons.count())
      {
        curButton = cutButtons.at(index);

        curButton->blockSignals(true);
        if (value == MSG_VALUE_TECH_DISACT){
          curButton->hide();
        }else{
          curButton->show();
          //curButton->setText(QString().fromUtf8("Резать"));
          curButton->setText(QString().fromUtf8("Резать"));
          curButton->setProperty("cut", 0);
        }
        if (value == MSG_VALUE_TECH_FIRE)
          curButton->setStyleSheet("background-color: yellow;");
        else if (value == MSG_VALUE_TECH_CUT){
          curButton->setStyleSheet("background-color: red;");
          curButton->setText(QString().fromUtf8("Стоп\nреза"));
          curButton->setProperty("cut", 1);
        }else if (value == MSG_VALUE_TECH_READY){
          curButton->setStyleSheet("background-color: ;");
        }
        curButton->blockSignals(false);
      }
    }
    }
  }

}
