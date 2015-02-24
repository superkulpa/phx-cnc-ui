#include "CXUdpManager.h"

#include <QApplication>

#include "debug.h"
#include "utils/CXSettingsXML.h"

CXUdpManager::CXUdpManager(QObject* parent) :
    QUdpSocket(parent)
{
  mCodec = QTextCodec::codecForName("UTF-8");

  connect(this, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

  host = QHostAddress(CXSettingsXML::getValue("settings.xml", "kernel_ip", "192.168.233.125"));
  port_out = CXSettingsXML::getValue("settings.xml", "kernel_port", "50001").toInt();
  port_in  = CXSettingsXML::getValue("settings.xml", "kernel_port2", "50002").toInt();

  bind(QHostAddress::Any, port_in);
}

CXUdpManager::~CXUdpManager()
{

}


void
CXUdpManager::onEchoCmd(const QString& _cmd){
  mCommands.append(_cmd);

  analyze();
}

void
CXUdpManager::sendCommand(const QString& aSection, const QString& aCommand, const QString& aValue)
{
  QString command("%4%1%5%1%6%2%3");
  command = command.arg( (Commands::SIMPLE_DELIMITER)).arg(
       (Commands::DELIMITER)).arg(
       (Commands::END_OF_MESSAGE));
  command = command.arg(aSection)
                   .arg(aCommand)
                   .arg(aValue);
  VLOG(D3) << "udp:out:" << qPrintable(command.left(command.length()-2)) << LOGN;
  writeDatagram(QByteArray().append(command), host, port_out);
}

//void
//CXUdpManager::sendCommand(const QString& aSection, const QString& aCommand, const QString& aValue = "")
//{
//  QString command("%4%1%5%1%6%2%3");
//  command = command.arg( (Commands::SIMPLE_DELIMITER)).arg(
//       (Commands::DELIMITER)).arg(
//       (Commands::END_OF_MESSAGE));
//  command = command.arg(QString::fromStdString(aSection)).arg(QString::fromStdString(aCommand)).arg(
//      QString::fromStdString(aValue));
//  qDebug() << "qform:out:"<< command.left(command.length()-2);
//  writeDatagram(QByteArray().append(command), host, port);
//}

void
CXUdpManager::onReadyRead()
{
  while (hasPendingDatagrams())
  {
    QByteArray datagram;
    datagram.resize(pendingDatagramSize());
    QHostAddress sender;
    quint16 senderPort;

    readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

    mCommands.append(mCodec->toUnicode(datagram));

    if (mCommands.contains( (Commands::END_OF_MESSAGE)))
    {
      mCommands.replace( (Commands::END_OF_MESSAGE), "");
      analyze();
    }
  }
}

void
CXUdpManager::postEchoCmd(const QString& _cmd)
{
  QGenericReturnArgument ret;
  QMetaObject::invokeMethod(this, "onEchoCmd", Qt::QueuedConnection, ret, Q_ARG(QString, _cmd));
}

void
CXUdpManager::analyze()
{
  QString command;
  QStringList commands;
  int pos = mCommands.indexOf( (Commands::DELIMITER));

  while (pos >= 0)
  {
    command = mCommands.left(pos);

    commands = command.split('#');
    if (commands.count() == 3)
    {
      VLOG(D3) << "udp:in :" << qPrintable(mCommands) << LOGN;
      emit commandReceived(commands.at(0), commands.at(1), commands.at(2));
    }

    mCommands = mCommands.mid(pos + 1);
    pos = mCommands.indexOf( (Commands::DELIMITER));
  }
}
