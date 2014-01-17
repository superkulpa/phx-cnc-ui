#include "CXUdpManager.h"

#include <QTextCodec>

CXUdpManager::CXUdpManager(const QString& aHost, int aPort, QObject* parent) : QUdpSocket(parent)
{
	connect(this, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

	mHost = aHost;
	mPort = aPort;
	bind(QHostAddress::Any, mPort);
}

CXUdpManager::~CXUdpManager()
{

}

void CXUdpManager::sendCommand(const QString& aCommand)
{
	QTextCodec* codec = QTextCodec::codecForName("UTF-8");
	
	writeDatagram(codec->fromUnicode(aCommand), QHostAddress(mHost), mPort);
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

		emit commandReceived(QTextCodec::codecForName("UTF-8")->toUnicode(datagram));
	}
}
