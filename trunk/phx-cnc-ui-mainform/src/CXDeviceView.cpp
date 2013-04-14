#include "CXDeviceView.h"

#include <QTextCodec>
#include <QKeyEvent>
#include <QSignalMapper>

#include "CXSettingsXML.h"
#include "CXUdpManager.h"
#include "iniFile.h"

CXDeviceView* CXDeviceView::mLastView = NULL;
CXDeviceEdit* CXDeviceView::mDeviceEdit = NULL;
CXChannelEdit* CXDeviceView::mChannelEdit = NULL;
int CXDeviceView::mDelay = 0;

CXDeviceView::CXDeviceView(const QString& aDeviceName, QWidget*) : AXBaseWindow()
{
	setupUi(this);

	mDeviceName = aDeviceName;
	mChannelCount = 0;
	if (mDelay == 0)
	{
		mDelay = CXSettingsXML::getDelay("settings.xml", "delay");
		connect(qApp, SIGNAL(focusChanged(QWidget*, QWidget*)), this, SLOT(onFocusChange(QWidget*, QWidget*)));
	}

	mNameLabel->setText(mDeviceName);
	mChannelsTable->setColumnCount(2);

	QHeaderView* horizontalHeader = mChannelsTable->horizontalHeader();

	horizontalHeader->setMinimumSectionSize(40);
	horizontalHeader->setResizeMode(1, QHeaderView::ResizeToContents);
	horizontalHeader->setResizeMode(0, QHeaderView::Stretch);

	connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)), this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));

	load();

	mChannelsTable->installEventFilter(this);

	registerManager();
}

CXDeviceView::~CXDeviceView()
{
	if (mDeviceEdit != NULL)
	{
		delete mDeviceEdit;
		mDeviceEdit = NULL;
	}

	if (mChannelEdit != NULL)
	{
		delete mChannelEdit;
		mChannelEdit = NULL;
	}
}

void CXDeviceView::load()
{
	QString configPath = QApplication::applicationDirPath() + "/jini/config.ini";
	CIniFile configFile(configPath.toStdString());
	configFile.ReadIniFile();

	mDeviceData = QString::fromStdString(configFile.GetValue("Modules", mDeviceName.toStdString()));

	int channelStart = mDeviceData.indexOf("nCh=");

	if (channelStart < 0) return;

	channelStart += 4;
	int channelEnd = mDeviceData.indexOf(",", channelStart);

	mChannelCount = mDeviceData.mid(channelStart, channelEnd - channelStart).toInt();
	mChannelList.resize(mChannelCount);

	QString channelsPath = QApplication::applicationDirPath() + "/jini/iochannels.ini";
	CIniFile channelsFile(channelsPath.toStdString());
	channelsFile.ReadIniFile();

	int keysNum = channelsFile.NumKeys();
	int valuesNum = 0;
	std::string keyName;
	std::string valueName;
	QString curValue;
	QStringList dataList;

	for (int i = 0; i < keysNum; ++i)
	{
		keyName = channelsFile.GetKeyName(i);
		valuesNum = channelsFile.GetNumValues(keyName);

		for (int j = 0; j < valuesNum; j++)
		{
			valueName = channelsFile.GetValueName(keyName, j);
			curValue = QString::fromStdString(channelsFile.GetValue(keyName, valueName));
			curValue = QString::fromUtf8(curValue.toAscii());

			if (curValue.contains(mDeviceName))
			{
				dataList = curValue.split(",");

				if (dataList.count() > 3)
				{
					int index = dataList.at(1).toInt();

					if (index < 0) continue;

					SXChannelData& curChannelData = mChannelList[index];
					curChannelData.mModify = dataList.at(2);
					curChannelData.mSectionName = QString::fromStdString(keyName);
					curChannelData.mValueName = QString::fromStdString(valueName);
					curChannelData.mDescription = dataList.at(3);
				}

				continue;
			}
		}
	}

	mChannelsTable->setRowCount(mChannelCount);

	for (int i = 0; i < mChannelCount; i++)
	{
		if (mChannelsTable->item(i, 0) == NULL) mChannelsTable->setItem(i, 0, new QTableWidgetItem);
		if (mChannelsTable->item(i, 1) == NULL) mChannelsTable->setItem(i, 1, new QTableWidgetItem);

		setDescription(i, mChannelList.at(i).mDescription);

		if (!mChannelList.at(i).mDescription.isEmpty()) mChannelsTable->item(i, 1)->setText("0");
	}

	mChannelsTable->resizeColumnToContents(0);
}

void CXDeviceView::loadDevices(int aGroupNumber, const QList <QPushButton*>& aButtonsList)
{
	QString path = QApplication::applicationDirPath() + "/jini/config.ini";
	CIniFile configFile(path.toStdString());
	configFile.ReadIniFile();

	QString devices = QString::fromStdString(configFile.GetValue("IO", "start"));

	QSignalMapper* signalMapper = NULL;

	if (!devices.isEmpty())
	{
		CXDeviceView* curDeviceView = NULL;
		QStringList devicesList = devices.split(",");

		for (int i = 0; i < devicesList.count(); i++)
		{
			if (configFile.GetValue("Modules", devicesList.at(i).toStdString()).length() <= 0) continue;
			if (devicesList.at(i) == QString("INI")) continue;

			curDeviceView = new CXDeviceView(devicesList.at(i));
			curDeviceView->setGroupNumber(aGroupNumber);

			signalMapper = new QSignalMapper(curDeviceView);

			if (aButtonsList.count() > 5) connect(aButtonsList.at(5), SIGNAL(clicked()), curDeviceView, SLOT(editChannel()));
			if (aButtonsList.count() > 4) connect(aButtonsList.at(4), SIGNAL(clicked()), curDeviceView, SLOT(editDevice()));
			if (aButtonsList.count() > 3)
			{
				connect(signalMapper, SIGNAL(mapped(const QString&)), curDeviceView, SLOT(onSendCommand(const QString &)));

				QPushButton* curButton = NULL;
				QList <QString> commands;
				commands << "inc" << "dec" << "stop" << "invert";

				for (int button = 0; button < 4; button++)
				{
					curButton = aButtonsList.at(button);
					connect(curButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
					signalMapper->setMapping(curButton, commands.at(button));
				}
			}
		}
	}
}

bool CXDeviceView::eventFilter(QObject* watched, QEvent* e)
{
	if (watched == mChannelsTable)
	{
		switch (e->type())
		{
			case QEvent::KeyRelease:
			{
				QKeyEvent* ev = dynamic_cast<QKeyEvent*>(e);

				QList <int> incKeys;
				incKeys << Qt::Key_Q << Qt::Key_W << Qt::Key_E << Qt::Key_R << Qt::Key_T << Qt::Key_Y << Qt::Key_U << Qt::Key_I << Qt::Key_O << Qt::Key_P;
				QList <int> invKeys;
				invKeys << Qt::Key_A << Qt::Key_S << Qt::Key_D << Qt::Key_F << Qt::Key_G << Qt::Key_H << Qt::Key_J << Qt::Key_K << Qt::Key_L << Qt::Key_Semicolon;
				QList <int> decKeys;
				decKeys << Qt::Key_Z << Qt::Key_X << Qt::Key_C << Qt::Key_V << Qt::Key_B << Qt::Key_N << Qt::Key_M << Qt::Key_Comma << Qt::Key_Period << Qt::Key_Slash;

				QString value;
				int index = 0;

				if (incKeys.contains(ev->key()))
				{
					index = incKeys.indexOf(ev->key());
					value = QString("%1=").arg(index) + QString::fromStdString(MSG_VALUE_INC);
				}
				else if (invKeys.contains(ev->key()))
				{
					index = invKeys.indexOf(ev->key());
					value = QString("%1=").arg(index) + QString::fromStdString(MSG_VALUE_INVERT);
				}
				else if (decKeys.contains(ev->key()))
				{
					index = decKeys.indexOf(ev->key());
					value = QString("%1=").arg(index) + QString::fromStdString(MSG_VALUE_DEC);
				}
				else break;

				if (index >= mChannelCount) break;

				mUdpManager->sendCommand(Commands::MSG_SECTION_IO, Commands::MSG_CMD_SET_VALUE + mDeviceName.toStdString(), value.toStdString());
				if (mChannelsTable->currentRow() != index) mChannelsTable->setCurrentItem(mChannelsTable->item(index, 0));

				break;
			}
		}
	}

	return false;
}

void CXDeviceView::keyPressEvent(QKeyEvent* e)
{
	switch (e->key())
	{
		case Qt::Key_Q:
		{
			break;
		}
	}

	AXBaseWindow::keyPressEvent(e);
}

void CXDeviceView::onFocusChange(QWidget*, QWidget*)
{
	if (QApplication::activeWindow() != NULL && QApplication::activeWindow()->metaObject()->className() == QString("CXDeviceView"))
	{
		mLastView = dynamic_cast<CXDeviceView*>(QApplication::activeWindow());
	}
}

void CXDeviceView::setDescription(int aIndex, const QString& aDescription)
{
	QString description = aDescription;

	if (!description.isEmpty())
	{
		if (description.contains(";")) description = description.left(description.indexOf(";"));
		description.prepend(QString("%1=").arg(aIndex));
	}

	mChannelsTable->item(aIndex, 0)->setText(description);
}

void CXDeviceView::editDevice()
{
	if (this != mLastView) return;
	if (mDeviceEdit == NULL) mDeviceEdit = new CXDeviceEdit;

	mDeviceEdit->setData(mDeviceData);

	if (mDeviceEdit->exec())
	{
		mDeviceData = mDeviceEdit->getData();

		QString channelsPath = QApplication::applicationDirPath() + "/jini/config.ini";
		CIniFile channelsFile(channelsPath.toStdString());
		channelsFile.ReadIniFile();

		channelsFile.SetValue("Modules", mDeviceName.toStdString(), mDeviceData.toStdString());

		int channelStart = mDeviceData.indexOf("nCh=");

		if (channelStart < 0) mChannelCount = 0;
		else
		{
			channelStart += 4;
			int channelEnd = mDeviceData.indexOf(",", channelStart);

			mChannelCount = mDeviceData.mid(channelStart, channelEnd - channelStart).toInt();

			mChannelsTable->setRowCount(mChannelCount);
			mChannelList.resize(mChannelCount);
		}

		channelsFile.WriteIniFile();
	}
}

void CXDeviceView::editChannel()
{
	if (this != mLastView) return;

	int index = mChannelsTable->currentRow();

	if (index < 0 || index > mChannelList.count()) return;

	if (mChannelEdit == NULL)
	{
		mChannelEdit = new CXChannelEdit;

		QString channelsPath = QApplication::applicationDirPath() + "/jini/iochannels.ini";
		CIniFile channelsFile(channelsPath.toStdString());
		channelsFile.ReadIniFile();

		int keysNum = channelsFile.NumKeys();
		int valuesNum = 0;
		std::string keyName;
		std::string valueName;

		QMap <QString, QString> sectionsMap;

		for (int i = 0; i < keysNum; ++i)
		{
			keyName = channelsFile.GetKeyName(i);
			valuesNum = channelsFile.GetNumValues(keyName);

			for (int j = 0; j < valuesNum; j++)
			{
				valueName = channelsFile.GetValueName(keyName, j);

				if (QString::fromStdString(channelsFile.GetValue(keyName, valueName)).split(",").count() < 3) continue;

				sectionsMap.insertMulti(QString::fromStdString(keyName), QString::fromStdString(valueName));
			}
		}

		mChannelEdit->setSectionData(sectionsMap);
	}

	SXChannelData& curChannelData = mChannelList[index];
	mChannelEdit->setData(curChannelData);

	if (mChannelEdit->exec())
	{
		const SXChannelData& newChannelData = mChannelEdit->getData();

		QString channelsPath = QApplication::applicationDirPath() + "/jini/iochannels.ini";
		CIniFile channelsFile(channelsPath.toStdString());
		channelsFile.ReadIniFile();

		QString value("%1,%2,%3,%4");
		value = value.arg(mDeviceName).arg(index).arg(newChannelData.mModify).arg(newChannelData.mDescription);
		std::string v = QString(value.toUtf8()).toStdString();

		if (!curChannelData.mSectionName.isEmpty())
		{
			if (curChannelData.mSectionName != newChannelData.mSectionName || curChannelData.mValueName != newChannelData.mValueName)
			{
				channelsFile.DeleteValue(curChannelData.mSectionName.toStdString(), curChannelData.mValueName.toStdString());
				channelsFile.AddValue(newChannelData.mSectionName.toStdString(), newChannelData.mValueName.toStdString(), v);
			}
			else channelsFile.SetValue(newChannelData.mSectionName.toStdString(), newChannelData.mValueName.toStdString(), v);
		}
		else channelsFile.AddValue(newChannelData.mSectionName.toStdString(), newChannelData.mValueName.toStdString(), v);

		channelsFile.WriteIniFile();

		curChannelData = newChannelData;

		setDescription(index, curChannelData.mDescription);
	}
}

void CXDeviceView::onSendCommand(const QString& aCommand)
{
	if (this != mLastView) return;

	mUdpManager->sendCommand(Commands::MSG_SECTION_IO, Commands::MSG_CMD_SET_VALUE + mDeviceName.toStdString(), aCommand.toStdString());
}

void CXDeviceView::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{
	if (aSection == QString::fromStdString(Commands::MSG_SECTION_IO))
	{
		if (aCommand == QString::fromStdString(Commands::MSG_STATE_GET_VALUE) + mDeviceName)
		{
			QStringList list = aValue.split(",");
			
			for (int i = 0; i < list.size(); i++)
			{
				const QString& curValue = list.at(i);
				int index = curValue.indexOf("=");
				int channelNumber = curValue.mid(0, index).toInt();

				if (channelNumber < 0) continue;

				if (mChannelsTable->item(channelNumber, 1) == NULL)
				{
					mChannelsTable->setItem(channelNumber, 1, new QTableWidgetItem);
				}

				mChannelsTable->item(channelNumber, 1)->setText(curValue.mid(index + 1));
			}
		}
	}
}
