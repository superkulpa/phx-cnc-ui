#include "CXTitleWindow.h"

#include <QVBoxLayout>
#include <QApplication>
#include <QFileInfo>

#include "CXUdpManager.h"

CXTitleWindow::CXTitleWindow() : AXBaseWindow()
{
	setGroupNumber(0);

	QHBoxLayout* centralLayout = new QHBoxLayout(this);
	centralLayout->setMargin(7);

	mControlButton = new QPushButton(trUtf8("Управление выкл."), this);
	mControlButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
	mControlButton->setFocusPolicy(Qt::NoFocus);
	centralLayout->addWidget(mControlButton);

	QLabel* lbl2 = new QLabel(this);
	lbl2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
	centralLayout->addWidget(lbl2);

	mFileLabel = new QLabel(this);
	centralLayout->addWidget(mFileLabel);

	registerManager();

	connect(mControlButton, SIGNAL(clicked()), this, SLOT(onControl()));
	connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)), this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));
}

CXTitleWindow::~CXTitleWindow()
{

}

void CXTitleWindow::onFileOpen(const QString& aFileName)
{
//	mFileName = QString(aFileName).replace(QApplication::applicationDirPath() + "/cps/", "");
	mFileName = QFontMetrics(font()).elidedText(QFileInfo(aFileName).fileName(), Qt::ElideMiddle, width() - 10);
	mFileLabel->setText(mFileName);
}

void CXTitleWindow::onControl()
{
	mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_CONTROL, "0");
}

void CXTitleWindow::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{
	if (aSection == QString::fromStdString(Commands::MSG_SECTION_OPERATOR))
	{
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_CONTROL))
		{
			if (aValue == QString::fromStdString(Commands::MSG_VALUE_ON))
			{
				mControlButton->setStyleSheet("background-color: green;");
			}
			else
			{
				mControlButton->setStyleSheet("");
			}
		}
	}

	if (aSection == QString::fromStdString(Commands::MSG_SECTION_ALARM))
	{
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_INFO_ALARM))
		{
			if (aValue == "0")
			{
				mFileLabel->setText(mFileName);
				mFileLabel->setStyleSheet("");
			}
			else
			{
				mFileLabel->setText(aValue);
				mFileLabel->setStyleSheet("background-color: red;");
			}
		}
	}
}
