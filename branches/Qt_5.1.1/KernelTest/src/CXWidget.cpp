#include "CXWidget.h"

#include <QList>
#include <QNetworkInterface>

#include "CXUdpManager.h"

CXWidget::CXWidget() : QWidget()
{
	setupUi(this);

	mUdpManager = NULL;

	connect(mStartButton, SIGNAL(clicked()), this, SLOT(onStart()));
	connect(mSendButton, SIGNAL(clicked()), this, SLOT(onSend()));
	connect(mClearButton, SIGNAL(clicked()), mReceiveView, SLOT(clear()));
}

CXWidget::~CXWidget()
{
	;
}

void CXWidget::onStart()
{
	if (mUdpManager != NULL) delete mUdpManager;

	mUdpManager = new CXUdpManager(mHostEdit->text(), mPortEdit->text().toInt(), this);
	connect(mUdpManager, SIGNAL(commandReceived(const QString&)), this, SLOT(onReceive(const QString&)));
}

void CXWidget::onSend()
{
	if (mUdpManager != NULL) mUdpManager->sendCommand(mSendEdit->toPlainText());
}

void CXWidget::onReceive(const QString& aCommand)
{
	mReceiveView->append(aCommand);
}
