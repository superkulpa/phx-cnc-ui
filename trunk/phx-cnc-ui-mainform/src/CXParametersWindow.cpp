#include "CXParametersWindow.h"

#include <QDir>
//#include <QSettings>
#include <QApplication>
#include <QDesktopWidget>

#include "CXFtp.h"
#include "CXParametersView.h"
#include "CXParametersView.h"
#include "iniFile.h"
#include "AXBaseWindow.h"
#include "CXWindowsManager.h"

CXParametersWindow::CXParametersWindow(QWidget* parent, bool aIsSystem) : QTabWidget(parent)
{
	mProgressBar = NULL;
	mIsSystem = aIsSystem;

	loadParameters();
}

CXParametersWindow::~CXParametersWindow()
{
}

void CXParametersWindow::setButtons(const QList <QPushButton*>& aButtons)
{
	mButtons = aButtons;
	updateButtonsText();
}

void CXParametersWindow::loadParametersFromFtp()
{
	loadFiles(false);
}

void CXParametersWindow::loadParameters()
{
	clearData();

	QDir configsDir(QApplication::applicationDirPath() + "/jini");
	QStringList fileList = configsDir.entryList(QStringList() << "*.ini");

	QString curFile;
	QString curGroup;
	QStringList curGroups;
	QStringList groups;
	QStringList allKeys;
	QString curKey;
	CXParameterData* curParameterData = NULL;
	CXGroupData* curGroupData = NULL;

	for (int i = 0; i < fileList.count(); ++i)
	{
		curFile = fileList.at(i);
		curFile.prepend(configsDir.path() + "/");
/**/
		CIniFile iniFile(curFile.toStdString());
		iniFile.ReadIniFile();
		int keysNum = iniFile.NumKeys();

		for (int i = 0; i < keysNum; ++i)
		{
			curGroup = QString::fromStdString(iniFile.GetKeyName(i));

			if (curGroup.startsWith("Form"))
			{
				if (iniFile.FindValue(i, "value") >= 0)
				{
					curGroupData = new CXGroupData;
					curGroupData->mName = QString::fromUtf8(QString::fromStdString(iniFile.GetValue(curGroup.toStdString(), "descr")).toAscii());
					if (iniFile.GetValueI(curGroup.toStdString(), "visible") == 1) curGroupData->mIsVisible = true;

					CXParametersView::mGropusMap.insert(iniFile.GetValueI(curGroup.toStdString(), "value"), curGroupData);
				}

				continue;
			}

			if (iniFile.FindValue(i, "group") >= 0)
			{
				curParameterData = new CXParameterData;
				curParameterData->mConfigFileName = curFile;
				curParameterData->mConfigGroup = curGroup;
				curParameterData->mName = QString::fromUtf8(QString::fromStdString(iniFile.GetValue(curGroup.toStdString(), "descr")).toAscii());
				curParameterData->setValue(iniFile.GetValueI(curGroup.toStdString(), "value"));
				groups = QString::fromUtf8(QString::fromStdString(iniFile.GetValue(curGroup.toStdString(), "group")).toAscii()).split(",", QString::SkipEmptyParts);
//				if (groups.first().isEmpty()) groups.takeFirst();

				if (iniFile.FindValue(i, "min") >= 0) curParameterData->mMin = iniFile.GetValueI(curGroup.toStdString(), "min");
				if (iniFile.FindValue(i, "max") >= 0) curParameterData->mMax = iniFile.GetValueI(curGroup.toStdString(), "max");

				for (int gr = 0; gr < groups.count(); ++gr)
				{
					curParameterData->mGroups.append(groups.at(gr).toInt());

					CXParametersView::mDataMap.insertMulti(groups.at(gr).toInt(), curParameterData);
				}

				if (groups.isEmpty())
				{
					CXParametersView::mDataMap.insertMulti(-1, curParameterData);
				}
			}
		}
/**/
/*
		QSettings settings(curFile, QSettings::IniFormat);
		settings.setIniCodec("UTF-8");
		curGroups = settings.childGroups();

		for (int f = 0; f < curGroups.count(); ++f)
		{
			curGroup = curGroups.at(f);

			if (curGroup == QString("Form"))
			{
				settings.beginGroup("Form/ParamGroups");
				QStringList allGroups = settings.childGroups();
				settings.endGroup();

				for (int gr = 0; gr < allGroups.count(); ++gr)
				{
					settings.beginGroup("Form/ParamGroups/" + allGroups.at(gr));
					if (settings.contains("value"))
					{
						curGroupData = new CXGroupData;
						curGroupData->mName = settings.value("descr").toString();
						if (settings.value("visible").toInt() == 1) curGroupData->mIsVisible = true;

						CXParametersView::mGropusMap.insert(settings.value("value").toInt(), curGroupData);
					}
					settings.endGroup();
				}

				continue;
			}

			settings.beginGroup(curGroup);
			allKeys = settings.allKeys();
			settings.endGroup();

			for (int key = 0; key < allKeys.count(); ++key)
			{
				curKey = allKeys.at(key);
				if (curKey.endsWith("group"))
				{
					curKey = curGroup + "/" + curKey.left(curKey.count() - 6);
					settings.beginGroup(curKey);

					curParameterData = new CXParameterData;
					curParameterData->mConfigFileName = curFile;
					curParameterData->mConfigGroup = curKey;
					curParameterData->mName = settings.value("descr").toString();
					curParameterData->setValue(settings.value("value").toInt());
					groups = settings.value("group").toString().split(",");

					if (settings.contains("min")) curParameterData->mMin = settings.value("min").toInt();
					if (settings.contains("max")) curParameterData->mMax = settings.value("max").toInt();

					for (int gr = 0; gr < groups.count(); ++gr)
					{
						curParameterData->mGroups.append(groups.at(gr).toInt());

						CXParametersView::mDataMap.insertMulti(groups.at(gr).toInt(), curParameterData);
					}

					settings.endGroup();
				}
			}
		}
/**/
	}

	makeTabs(mIsSystem);
}

void CXParametersWindow::saveParameters()
{
	QMap <int, CXParameterData*>::iterator iter;
	for (iter = CXParametersView::mDataMap.begin(); iter != CXParametersView::mDataMap.end(); ++iter)
	{
		iter.value()->save();
	}

	loadFiles(true);
}

void CXParametersWindow::makeTabs(bool aIsSystem)
{
	clearTables();

	QList <CXParameterData*> parameters;
	QList <int> groups = CXParametersView::mGropusMap.keys();
	CXGroupData* curGroupData = NULL;
	for (int i = 0; i < groups.count(); ++i)
	{
		parameters = CXParametersView::mDataMap.values(groups.at(i));
		parameters.count();

		curGroupData = CXParametersView::mGropusMap.value(groups.at(i));

		if (curGroupData->mIsVisible != aIsSystem) addTab(new CXParametersView(this, parameters), curGroupData->mName);
	}

	updateButtonsText();
}

void CXParametersWindow::setProgressText(const QString& aText)
{
	mProgressBar->setFormat(trUtf8("Загружается ") + aText + " (%p%)");
}

void CXParametersWindow::onAllFilesIsLoaded(bool aIsUpload)
{
	if (mProgressBar == NULL) return;

	mProgressBar->close();
	delete mProgressBar;
	mProgressBar = NULL;

	mFtp->deleteLater();
	mFtp = NULL;

	if (!aIsUpload) loadParameters();
}

void CXParametersWindow::showSettings()
{
	AXBaseWindow::mManager->setCurrentGroup(3);
}

void CXParametersWindow::buttonClicked()
{
	QPushButton* button = qobject_cast<QPushButton*>(sender());

	if (button != NULL)
	{
		setCurrentIndex(mButtons.indexOf(button));
	}
}

void CXParametersWindow::loadFiles(bool aIsUpload)
{
	mProgressBar = new QProgressBar;
	mProgressBar->setWindowFlags(Qt::FramelessWindowHint);
	mProgressBar->setAlignment(Qt::AlignCenter);
	mProgressBar->setWindowModality(Qt::ApplicationModal);

	QSize size = QApplication::desktop()->availableGeometry().size();
	mProgressBar->resize(size.width() * 0.7, size.height() * 0.05);

	CIniFile iniFile(QApplication::applicationDirPath().toStdString() + "/jini/config.ini");
	iniFile.ReadIniFile();
	QString host = QString::fromStdString(iniFile.GetValue("Connect", "core_ip"));

	mFtp = new CXFtp(this);
	mFtp->setConnectData(host, 21, "ftp", "ftp");
	mFtp->setLoadFilesData(QApplication::applicationDirPath() + "/jini", "pub/updates/jini");

	connect(mFtp, SIGNAL(progressMaximumChanged(int)), mProgressBar, SLOT(setMaximum(int)));
	connect(mFtp, SIGNAL(progressValueChanged(int)), mProgressBar, SLOT(setValue(int)));
	connect(mFtp, SIGNAL(progressTextChanged(const QString&)), this, SLOT(setProgressText(const QString&)));
	connect(mFtp, SIGNAL(allFilesIsLoaded(bool)), this, SLOT(onAllFilesIsLoaded(bool)));

	if (aIsUpload) mFtp->onFtpUpload();
	else mFtp->onFtpDownload();

	mProgressBar->show();
}

void CXParametersWindow::clearData()
{
	clearTables();

	CXParameterData* curParamData = NULL;
	QList <CXParameterData*> parametersList = CXParametersView::mDataMap.values();
	while (!parametersList.isEmpty())
	{
		curParamData = parametersList.takeFirst();
		parametersList.removeAll(curParamData);
		delete curParamData;
	}

//	qDeleteAll(parametersList.begin(), parametersList.end());
	CXParametersView::mDataMap.clear();
	qDeleteAll(CXParametersView::mGropusMap.begin(), CXParametersView::mGropusMap.end());
	CXParametersView::mGropusMap.clear();
}

void CXParametersWindow::clearTables()
{
	QWidget* curWidget = NULL;
	for (int i = 0; i < count(); ++i)
	{
		curWidget = widget(i);
		removeTab(i);
		delete curWidget;

		i--;
	}
}

void CXParametersWindow::updateButtonsText()
{
	int groupIndex = 0;
	QList <CXGroupData*> groups = CXParametersView::mGropusMap.values();

	QString text;
	QPushButton* curButon = NULL;
	QList <QPushButton*>::iterator iter;
	for (iter = mButtons.begin(); iter != mButtons.end(); ++iter)
	{
		while (groupIndex < groups.count() && !groups.at(groupIndex)->mIsVisible) groupIndex++;

		curButon = *iter;
		text = curButon->text();

		if (groupIndex < groups.count())
		{
			text = text.replace(QRegExp("\n.*"), "\n" + groups.at(groupIndex)->mName);
			connect(curButon, SIGNAL(clicked()), this, SLOT(buttonClicked()));
		}
		else
		{
			text = text.replace(QRegExp("\n.*"), "\n");
			disconnect(curButon, SIGNAL(clicked()), this, SLOT(buttonClicked()));
		}

		curButon->setText(text);
		groupIndex++;
	}
}
