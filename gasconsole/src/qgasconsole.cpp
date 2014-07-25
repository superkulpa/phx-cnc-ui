#include "qgasconsole.h"
#include "ui_qgasconsole.h"

CXUdpManager* QGasConsole::mUdpManager = NULL;

#define HPR_CMD_HELLO "000"
#define HPR_CMD_VERSION "001"
#define HPR_CMD_RESET "068"
#define HPR_CMD_GET_STATE "002"
#define HPR_CMD_LAST_ERRORS "134"
#define HPR_CMD_GET_PLASMA_AMPS "028"
#define HPR_CMD_GET_CONTROL_VOLTAGE "072"
#define HPR_CMD_GET_PS_INFO "079"
#define HPR_CMD_READ_GAS_PRESSURE "094"
#define HPR_CMD_GET_INLET_GASES "098"
#define HPR_CMD_GET_GAS_FLOWS "099"
#define HPR_CMD_GET_CONTROL_DATA "100"
#define HPR_CMD_START_TEST_PRE_FLOW "064"
#define HPR_CMD_STOP_TEST_PRE_FLOW "065"
#define HPR_CMD_START_TEST_CUT_FLOW "066"
#define HPR_CMD_STOP_TEST_CUT_FLOW "067"
#define HPR_CMD_GET_TIMER_COUNTER "125"
#define HPR_CMD_GET_INFO_CHOPPER_DC "133"
#define HPR_CMD_CONNECTION_TIMEOUT "Timeout"

QString GetPSStatus(int _code){
  switch (_code){
    case 0:
    return "IDLE";
    case 2:
    return "PURGE";
    case 3:
    return "IDLE2";
    case 4:
    return "PREFLOW";
    case 5:
    return "PILOT ARC";
    case 6:
    return "TRANSFER";
    case 7:
    return "RAMP-UP";
    case 8:
    return "STEADY STATE";
    case 9:
    return "RAMP-DOWN";
    case 10:
    return "FINAL RAMP-DOWN";
    case 11:
    return "AUTO OFF";
    case 12:
    return "TEST CUTFLOW";
    case 14:
    return "SHUTDOWN";
    case 15:
    return "RESET";
    case 16:
    return "MAINTENANCE";
    case 20:
    return "TESTPREFLOW";
    case 22:
    return "MANUAL PUMP CONTROL";
    case 23:
    return "INLET LEAD CHECK";
    case 24:
    return "SYSTEM LEAD CHECK";
    case 25:
    return "BURKERT FLOW CHECK";
  }
  return "NoName";
}

QString GetGasName(int _gas){
  switch (_gas){
    case 0:
    return "No Gas";
    case 1:
    return "Oxygen";
    case 2:
    return "Methane(not supported)";
    case 3:
    return "H35(argon - hydrogen)";
    case 4:
    return "H5(not supported)";
    case 5:
    return "Air";
    case 6:
    return "Nitrogen";
    case 7:
    return "Argon";
    case 8:
    return "F5(N95)";
  }
  return "NoName";
}



QGasConsole::QGasConsole(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QGasConsole), startPreFlow(false), startCutFlow(false)
{
    mUdpManager->sendCommand(Commands::MSG_SECTION_GC, Commands::MSG_CMD_GC_START, "");
    ui->setupUi(this);
    connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)),
          this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));

    connect(ui->btClear, SIGNAL(clicked()), this, SLOT(onClear()));

    connect(ui->btUpdate, SIGNAL(clicked()), this, SLOT(onUpdate()));
    connect(ui->btUpdateAdd, SIGNAL(clicked()), this, SLOT(onUpdate()));

    connect(ui->btTestCutflow, SIGNAL(clicked()), this, SLOT(onTestCutFlow()));
    connect(ui->btTestPreflow, SIGNAL(clicked()), this, SLOT(onTestPreFlow()));
    //
    connect(ui->btClose, SIGNAL(clicked()), this, SLOT(onClose()));
    connect(ui->btCloseAdd, SIGNAL(clicked()), this, SLOT(onClose()));
    ui->tabConsole->setCurrentIndex(0);
    //отправляем проверку связи
    //SendCommand(HPR_CMD_HELLO);
    onUpdate();
}

QGasConsole::~QGasConsole()
{
    delete ui;
}

void QGasConsole::SendCommand(const QString& aCommand)
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_GC, Commands::MSG_CMD_GC_DIRECT_CMD, aCommand);
}

QStringList ParseHPRCmd(QString command){
  QStringList commands;
  QString curCommand;
  int pos = command.indexOf(" ");

  while (pos >= 0)
  {
    curCommand = command.left(pos);

    command = command.mid(pos + 1);
    pos = command.indexOf(" ");
    qDebug(curCommand.toStdString().c_str());
    commands.append(curCommand);
  }
  qDebug(command.toStdString().c_str());
  commands.append(command);
  return commands;
};

void QGasConsole::ParseResponseFromHPR(const QString& aValue){
  QString curCommand = aValue.mid(0,3);//выбираем команду
  QStringList curValues = ParseHPRCmd(aValue.right(aValue.size() - 3));//значение
  qDebug(curCommand.toStdString().c_str());
  if(curCommand == HPR_CMD_HELLO){
    //qDebug("Hello");
    setWindowTitle(curValues.value(0));
    SendCommand(HPR_CMD_VERSION);
  }else if(curCommand == HPR_CMD_VERSION){
    //ревизия
    ui->lPS_Rev->setText(curValues.value(0));
    ui->lGC_Rev->setText(curValues.value(1));
    SendCommand(HPR_CMD_LAST_ERRORS);
  }else if(curCommand == HPR_CMD_CONNECTION_TIMEOUT){
    setWindowTitle("Can not connect...");
  }else if(curCommand == HPR_CMD_RESET){
    //qDebug("Reset");
    onUpdate();
  }else if(curCommand == HPR_CMD_GET_STATE){
    //qDebug("GetState");
    //SendCommand(HPR_CMD_LAST_ERRORS);
    ui->lPSStateCode->setText(GetPSStatus(curValues.value(0).toInt()));
  }else if(curCommand == HPR_CMD_LAST_ERRORS){
    //qDebug("LastError");
    QString Errors = "";
    for (int i = 0; i < curValues.size(); i++)
      Errors += curValues.value(i) + " ";
    ui->lLastErrors->setText(Errors);
    SendCommand(HPR_CMD_GET_PS_INFO);
    //SendCommand(HPR_CMD_GET_CONTROL_VOLTAGE);
    //SendCommand(HPR_CMD_GET_PLASMA_AMPS);
  }else if(curCommand == HPR_CMD_GET_PLASMA_AMPS){
    //qDebug("GetPlasmaAmps");
    //ui->lCurSetPoint->setText(curValues.value(0));
    //SendCommand(HPR_CMD_GET_CONTROL_VOLTAGE);
  }else if(curCommand == HPR_CMD_GET_CONTROL_VOLTAGE){
    //QString voltage("%1");
    //ui->lLineVoltage->setText(voltage.arg(curValues.value(0).toFloat() / 10));
    //SendCommand(HPR_CMD_GET_PS_INFO);
  }else if(curCommand == HPR_CMD_GET_PS_INFO){
    //qDebug("GetPSInfo");
    QString value("%1");
    ui->lPlasmaCutflow->setText(value.arg(curValues.value(0).mid(2).toInt()));
    ui->lPlasmaPreflow->setText(value.arg(curValues.value(1).mid(2).toInt()));
    ui->lShieldCutflow->setText(value.arg(curValues.value(2).mid(2).toInt()));
    ui->lShieldPreflow->setText(value.arg(curValues.value(3).mid(2).toInt()));
    ui->lCurSetPoint->setText(value.arg(curValues.value(4).mid(2).toInt()));
    ui->lPSStateCode->setText(GetPSStatus(curValues.value(5).mid(2).toInt()));
    ui->lInletGas1->setText(value.arg(curValues.value(7).mid(2).toInt()));
    ui->lInletGas2->setText(value.arg(curValues.value(8).mid(2).toInt()));
    ui->lMixedGas1->setText(value.arg(curValues.value(9).mid(2).toInt()));
    ui->lMixedGas2->setText(value.arg(curValues.value(10).mid(2).toInt()));
    //SendCommand(HPR_CMD_READ_GAS_PRESSURE);
    SendCommand(HPR_CMD_GET_INLET_GASES);
  }else if(curCommand == HPR_CMD_READ_GAS_PRESSURE){
    //qDebug("ReadGasPressure");
    SendCommand(HPR_CMD_GET_INLET_GASES);
  }else if(curCommand == HPR_CMD_GET_INLET_GASES){
    //qDebug("GetInletGas");
    ui->lPlasmaIG->setText(GetGasName(curValues.value(0).toInt()));
    ui->lShieldIG->setText(GetGasName(curValues.value(1).toInt()));
    SendCommand(HPR_CMD_GET_CONTROL_DATA);
    //SendCommand(HPR_CMD_GET_GAS_FLOWS);
  }else if(curCommand == HPR_CMD_GET_GAS_FLOWS){
    //qDebug("GetGasFlow");
    //SendCommand(HPR_CMD_GET_CONTROL_DATA);
  }else if(curCommand == HPR_CMD_GET_CONTROL_DATA){
    //qDebug("GetControlData");
    QString value("%1");
    ui->lChopperATemp->setText(value.arg(curValues.value(0).mid(3).toInt()));
    ui->lChopperBTemp->setText(value.arg(curValues.value(1).mid(3).toInt()));
    ui->lLineVoltage->setText(value.arg(curValues.value(2).mid(3).toFloat() / 10));
    ui->lCoolantFlow->setText(value.arg(curValues.value(3).mid(3).toFloat() / 100));
    ui->lCoolantTemp->setText(value.arg(curValues.value(4).mid(3).toInt()));
    ui->lTransformerTemp->setText(value.arg(curValues.value(5).mid(3).toInt()));
    ui->lChA_Cur->setText(value.arg(curValues.value(6).mid(3).toInt()));
    ui->lChB_Cur->setText(value.arg(curValues.value(7).mid(3).toInt()));
    ui->lWorkLead->setText(value.arg(curValues.value(8).mid(3).toInt()));
    ui->lChA_SP->setText(value.arg(curValues.value(9).mid(3).toInt()));
    ui->lChB_SP->setText(value.arg(curValues.value(10).mid(3).toInt()));
    SendCommand(HPR_CMD_GET_TIMER_COUNTER);
  }else if(curCommand == HPR_CMD_GET_TIMER_COUNTER){
    QString value("%1");
    ui->lArcOnTime->setText(value.arg(curValues.value(0).toInt()));
    ui->lSysOnTime->setText(value.arg(curValues.value(1).toInt()));
    ui->lTotStarts->setText(value.arg(curValues.value(2).toInt()));
    ui->lTotErrors->setText(value.arg(curValues.value(3).toInt()));
    ui->lRampErrors->setText(value.arg(curValues.value(4).toInt()));
    //SendCommand(HPR_CMD_GET_INFO_CHOPPER_DC);
  }else if(curCommand == HPR_CMD_GET_INFO_CHOPPER_DC){
    QString value("%1");
    ui->lChopperCTemp->setText(value.arg(curValues.value(0).toInt()));
    ui->lChopperDTemp->setText(value.arg(curValues.value(1).toInt()));
    ui->lChC_Cur->setText(value.arg(curValues.value(2).toInt()));
    ui->lChD_Cur->setText(value.arg(curValues.value(3).toInt()));
  }else if(curCommand == HPR_CMD_START_TEST_PRE_FLOW){
    //qDebug("StartTestPreFlow");
  }else if(curCommand == HPR_CMD_STOP_TEST_PRE_FLOW){
    //qDebug("StopTestPreFlow");
  }else if(curCommand == HPR_CMD_START_TEST_CUT_FLOW){
    //qDebug("StartTestCutFlow");
  }else if(curCommand == HPR_CMD_STOP_TEST_CUT_FLOW){
    //qDebug("StopTestCutFlow");
  };
};

void
QGasConsole::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{
  if (aSection ==  (Commands::MSG_SECTION_GC))
  {
    if (aCommand == (Commands::MSG_STATE_GC_RESPONSE)){
        //Разбираем параметры
        ParseResponseFromHPR(aValue);
    };
  }

}

void
QGasConsole::onClose()
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_GC, Commands::MSG_CMD_GC_STOP, "");
  close();
}


void QGasConsole::onClear(){
  SendCommand(HPR_CMD_RESET);//REset
  //onUpdate();
}

void QGasConsole::onUpdate()
{
  SendCommand(HPR_CMD_HELLO);
  //SendCommand(HPR_CMD_GET_STATE);
}

void QGasConsole::onTestPreFlow(){
  if(startPreFlow){
    ui->btTestPreflow->setText("Test");
    SendCommand(HPR_CMD_STOP_TEST_PRE_FLOW);
  }else{
    ui->btTestPreflow->setText("TestPreflow");
    SendCommand(HPR_CMD_START_TEST_PRE_FLOW);
  };

  startPreFlow = !startPreFlow;
}

void QGasConsole::onTestCutFlow(){
  if(startCutFlow){
    ui->btTestCutflow->setText("Test");
    SendCommand(HPR_CMD_STOP_TEST_CUT_FLOW);
  }else{
    ui->btTestCutflow->setText("TestCutflow");
    SendCommand(HPR_CMD_START_TEST_CUT_FLOW);
  };
  startCutFlow = !startCutFlow;
}
