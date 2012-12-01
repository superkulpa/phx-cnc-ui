#include "CXTextParameters.h"

#include <QVBoxLayout>
#include <QTextEdit>

#include "CXUdpManager.h"

CXTextParameters::CXTextParameters() : AXBaseWindow()
{
	QVBoxLayout* centralLayout = new QVBoxLayout(this);
	centralLayout->setMargin(5);

	mTextEdit = new QTextEdit(this);
	mTextEdit->setReadOnly(true);
	mTextEdit->setMinimumHeight(10);
	centralLayout->addWidget(mTextEdit);

	connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)), this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));

	registerManager();
}

CXTextParameters::~CXTextParameters()
{

}

void CXTextParameters::onResetAlarms()
{
	mUdpManager->sendCommand(Commands::MSG_SECTION_ALARM, Commands::MSG_CMD_RESET_ALARMS, "0");

	mTextEdit->clear();
}

void CXTextParameters::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{
	if (aSection == QString::fromStdString(Commands::MSG_SECTION_ALARM))
	{
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_MULTI_ALARM))
		{
			mTextEdit->clear();
			mTextEdit->setPlainText(aValue);
		}
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_MULTI_ALARM_ADD))
		{
			if (!mTextEdit->toPlainText().contains(aValue))
			{
				mTextEdit->append(aValue);
			}
		}
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_MULTI_ALARM_REMOVE))
		{
			if (mTextEdit->toPlainText().contains(aValue))
			{
				mTextEdit->setText(mTextEdit->toPlainText().replace(aValue, ""));
			}
		}
	}
}
