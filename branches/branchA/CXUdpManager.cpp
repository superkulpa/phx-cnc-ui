#include "CXUdpManager.h"

#include <QApplication>

#include "CXSettingsXML.h"

CXUdpManager::CXUdpManager(QObject* parent) :
    QUdpSocket(parent)
{
  mCodec = QTextCodec::codecForName("UTF-8");

  connect(this, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

  host = QHostAddress(CXSettingsXML::getValue("settings.xml", "kernel_ip"));
  port = CXSettingsXML::getValue("settings.xml", "kernel_port").toInt();

  bind(QHostAddress::Any, port);
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
CXUdpManager::sendCommand(const String& aSection, const String& aCommand, const String& aValue)
{
  QString command("%4%1%5%1%6%2%3");
  command = command.arg(QString::fromStdString(Commands::SIMPLE_DELIMITER)).arg(
      QString::fromStdString(Commands::DELIMITER)).arg(
      QString::fromStdString(Commands::END_OF_MESSAGE));
  command = command.arg(QString::fromStdString(aSection)).arg(QString::fromStdString(aCommand)).arg(
      QString::fromStdString(aValue));
  qDebug() << "qform:out:"<< command.left(command.length()-2);
  writeDatagram(QByteArray().append(command), host, port);
}

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

    if (mCommands.contains(QString::fromStdString(Commands::END_OF_MESSAGE)))
    {
      mCommands.replace(QString::fromStdString(Commands::END_OF_MESSAGE), "");
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
  int pos = mCommands.indexOf(QString::fromStdString(Commands::DELIMITER));

  while (pos >= 0)
  {
    command = mCommands.left(pos);

    commands = command.split('#');
    if (commands.count() == 3)
    {
      qDebug() << "qform:in:" << mCommands;
      emit commandReceived(commands.at(0), commands.at(1), commands.at(2));
    }

    mCommands = mCommands.mid(pos + 1);
    pos = mCommands.indexOf(QString::fromStdString(Commands::DELIMITER));
  }
}
