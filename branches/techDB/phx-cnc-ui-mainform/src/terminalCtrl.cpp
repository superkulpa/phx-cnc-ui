

#include <iostream>

#include <QThread>

#include "terminalCtrl.h"
#include "CXUdpManager.h"

CTerminalCntrl::CTerminalCntrl(CXUdpManager* _udp)
  : udp(_udp)
{
  thRunner = new QThread;
  this->moveToThread(thRunner);

//  connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
  connect(thRunner, SIGNAL(started()), this, SLOT(onStart()));
  connect(this, SIGNAL(finished()), thRunner, SLOT(quit()));
  connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
  connect(thRunner, SIGNAL(finished()), thRunner, SLOT(deleteLater()));
  thRunner->start();
}

CTerminalCntrl::~CTerminalCntrl()
{

}

void CTerminalCntrl::onStart(){

  QTextStream qtin(stdin);

  while(1) {
    QString line = qtin.readLine();
    if(line.left(4) == "udp:"){
      line.remove(0, 4);
      udp->postEchoCmd(line);
    }
  }
  emit finished();
}

//
CTerminalCntrl* CTerminalCntrl::startTerminal(CXUdpManager* udp){
  static CTerminalCntrl* terminal = NULL;
  if(terminal) return terminal;

  return terminal = new CTerminalCntrl(udp);
}
