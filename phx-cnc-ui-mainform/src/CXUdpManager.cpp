#include "CXUdpManager.h"

#include <QApplication>

#include "CXSettingsXML.h"

CXUdpManager::CXUdpManager(QObject* parent) : QUdpSocket(parent)
{
	mSections	<< QString::fromStdString(Commands::MSG_SECTION_IO)
				<< QString::fromStdString(Commands::MSG_SECTION_START)
				<< QString::fromStdString(Commands::MSG_SECTION_OPERATOR)
				<< QString::fromStdString(Commands::MSG_SECTION_MOVE)
				<< QString::fromStdString(Commands::MSG_SECTION_TECH)
				<< QString::fromStdString(Commands::MSG_SECTION_PARAMS)
				<< QString::fromStdString(Commands::MSG_SECTION_ALARM)
				<< QString::fromStdString(Commands::MSG_SECTION_CART)
				<< QString::fromStdString(Commands::MSG_SECTION_GC);

	connect(this, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

	QString host = CXSettingsXML::getValue("settings.xml", "kernel_ip");
	QString port = CXSettingsXML::getValue("settings.xml", "kernel_port");

	bind(QHostAddress(host), port.toInt());
}

CXUdpManager::~CXUdpManager()
{

}

void CXUdpManager::sendCommand(const String& aSection, const String& aCommand, const String& aValue)
{
	QString command("%4%1%5%1%6%2%3");
	command = command.arg(QString::fromStdString(Commands::SIMPLE_DELIMITER)).arg(QString::fromStdString(Commands::DELIMITER)).arg(QString::fromStdString(Commands::END_OF_MESSAGE));
	command = command.arg(QString::fromStdString(aSection)).arg(QString::fromStdString(aCommand)).arg(QString::fromStdString(aValue));

	writeDatagram(QByteArray().append(command), QHostAddress::LocalHost, 7755);
}

void CXUdpManager::onReadyRead()
{
	while (hasPendingDatagrams())
	{
		QByteArray datagram;
		datagram.resize(pendingDatagramSize());
		QHostAddress sender;
		quint16 senderPort;

		readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

		mCommands.append(datagram);

		if (mCommands.contains(QString::fromStdString(Commands::END_OF_MESSAGE)))
		{
			mCommands.replace(QString::fromStdString(Commands::END_OF_MESSAGE), "");
			analyze();
		}
	}
}

void CXUdpManager::analyze()
{
	QString command;
	QStringList commands;
	int pos = mCommands.indexOf(QString::fromStdString(Commands::DELIMITER));

	while (pos >= 0)
	{
		command = mCommands.left(pos);
		mCommands = mCommands.mid(pos + 1);

		commands = command.split('#');
		if (commands.count() == 3)
		{
			emit commandReceived(commands.at(0), commands.at(1), commands.at(2));
/*
			switch (mSections.indexOf(commands.at(0)))
			{
				//MSG_SECTION_IO
				case 0:
				{
					break;
				}
				//MSG_SECTION_START
				case 1:
				{
					break;
				}
				//MSG_SECTION_OPERATOR
				case 2:
				{
					break;
				}
				//MSG_SECTION_MOVE
				case 3:
				{
					break;
				}
				//MSG_SECTION_TECH
				case 4:
				{
					break;
				}
				//MSG_SECTION_PARAMS
				case 5:
				{
					break;
				}
				//MSG_SECTION_ALARM
				case 6:
				{
					break;
				}
				//MSG_SECTION_CART
				case 7:
				{
					break;
				}
				//MSG_SECTION_GC
				case 8:
				{
					break;
				}
			}
*/
		}

		pos = mCommands.indexOf(QString::fromStdString(Commands::DELIMITER));
	}
}
