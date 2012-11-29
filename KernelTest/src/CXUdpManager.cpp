#include "CXUdpManager.h"

CXUdpManager::CXUdpManager(const QString& aHost, int aPort, QObject* parent) : QUdpSocket(parent)
{
	connect(this, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

	mHost = aHost;
	mPort = aPort;
	bind(QHostAddress(mHost), mPort);
}

CXUdpManager::~CXUdpManager()
{

}

void CXUdpManager::sendCommand(const QString& aCommand)
{
	writeDatagram(QByteArray().append(aCommand), QHostAddress(mHost), mPort);
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

		emit commandReceived(datagram);
	}
}
