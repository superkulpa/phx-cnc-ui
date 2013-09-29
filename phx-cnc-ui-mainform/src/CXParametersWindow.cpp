#include "CXParametersWindow.h"

#include <QVBoxLayout>
#include <QDir>
//#include <QSettings>
#include <QApplication>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QTimer>

#include "CXFtp.h"
#include "CXParametersView.h"
#include "iniFile.h"
#include "AXBaseWindow.h"
#include "CXWindowsManager.h"
#include "CXUdpManager.h"
#include "CXSettingsXML.h"

#include "CXIniFileEditor.h"

CXParametersWindow::CXParametersWindow(bool aIsSystem) :
    AXBaseWindow()
{
  mWaitTimer = -1;
  curTab = 0;
  mIsUpload = false;
  mProgressBar = NULL;
  mIsSystem = aIsSystem;

  QVBoxLayout* centralLayout = new QVBoxLayout(this);
  centralLayout->setMargin(7);
  centralLayout->setSpacing(6);

  mTabWidget = new QTabWidget(this);
  centralLayout->addWidget(mTabWidget);
  fileEditor = new CXIniFileEditor();

//	loadParameters();
  connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)),
      this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));

  //загружаем параметры
  loadFiles(false);
  registerManager();

  QEventLoop loop; QTimer::singleShot(2000, &loop, SLOT(quit())); loop.exec();
}

CXParametersWindow::~CXParametersWindow()
{
}

void
CXParametersWindow::setButtons(const QList<QPushButton*>& aButtons)
{
  mButtons = aButtons;
  updateButtonsText();
}

void
CXParametersWindow::loadParametersFromFtp()
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_PARAMS, Commands::MSG_CMD_RELOAD_PARAMS, "1");
  int timerTimeout = CXSettingsXML::getValue("settings.xml", "parametersTimeout").toInt();

  if (timerTimeout <= 0)
    timerTimeout = 1000;

  mWaitTimer = startTimer(timerTimeout);
}

void
CXParametersWindow::loadParameters()
{
//  if(mTabWidget->count() == 0){
//    //первый запуск
//  }
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
    curFile.prepend(configsDir.path() + QDir::separator());
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
          curGroupData->mName =
              QString::fromStdString(iniFile.GetValue(curGroup.toStdString(), "descr"));
          if (iniFile.GetValueI(curGroup.toStdString(), "visible") == 1)
            curGroupData->mIsVisible = true;

          CXParametersView::mGropusMap.insert(
              iniFile.GetValueI(curGroup.toStdString(), "value"), curGroupData);
        }

        continue;
      }

      if (iniFile.FindValue(i, "group") >= 0)
      {
        curParameterData = new CXParameterData;
        curParameterData->mConfigFileName = curFile;
        curParameterData->mConfigGroup = curGroup;

        curParameterData->mName = QString::fromStdString(iniFile.GetValue(curGroup.toStdString(), "descr"));
        curParameterData->setValue(iniFile.GetValueI(curGroup.toStdString(), "value"));
        groups =
            QString::fromStdString(iniFile.GetValue(curGroup.toStdString(), "group")).split(
                ",", QString::SkipEmptyParts);
//				if (groups.first().isEmpty()) groups.takeFirst();

        if (iniFile.FindValue(i, "min") >= 0)
          curParameterData->mMin = iniFile.GetValueI(curGroup.toStdString(), "min");
        if (iniFile.FindValue(i, "max") >= 0)
          curParameterData->mMax = iniFile.GetValueI(curGroup.toStdString(), "max");

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
  }

  makeTabs(mIsSystem);
}

void
CXParametersWindow::saveParametersAnyway()
{
  loadFiles(true);
}

void
CXParametersWindow::saveParameters()
{
  curTab = mTabWidget->currentIndex();
  if(curTab == mTabWidget->count() - 1){
  //с последней вкладки сохранять из iniEditor
    fileEditor->onSave();
  }else{

//  bool isModified = false;
//
//  for (int i = 0; i < mTabWidget->count(); i++)
//  {
//    CXParametersView* view = qobject_cast<CXParametersView*>(mTabWidget->widget(i));
//    if (view != NULL)
//    {
//      if (view->isModified())
//      {
//        isModified = true;
//        view->resetIsModified();
//      }
//    }
//  }
//
//  if (!isModified)
//    return;
//
    QMap<int, CXParameterData*>::iterator iter;
    for (iter = CXParametersView::mDataMap.begin(); iter != CXParametersView::mDataMap.end(); ++iter)
    {
      iter.value()->save();
    }
  }

  loadFiles(true);
}

void
CXParametersWindow::makeTabs(bool aIsSystem)
{
  //int curTab = mTabWidget->property("currentIndex").toInt();//mTabWidget->currentIndex();//mTabWidget?mTabWidget->currentIndex():-1;
  //const QString curFName = fileEditor?fileEditor->getFName():"";

  clearTables();

  QList<CXParameterData*> parameters;
  QList<int> groups = CXParametersView::mGropusMap.keys();
  CXGroupData* curGroupData = NULL;
  for (int i = 0; i < groups.count(); ++i)
  {
    parameters = CXParametersView::mDataMap.values(groups.at(i));
    parameters.count();

    curGroupData = CXParametersView::mGropusMap.value(groups.at(i));

    if (curGroupData->mIsVisible != aIsSystem)
      mTabWidget->addTab(new CXParametersView(this, parameters), curGroupData->mName);
  }

  //if(curFName.size()>0)fileEditor->onOpenFile(curFName);
  fileEditor->reloadFiles();
  mTabWidget->addTab(fileEditor, QString::fromUtf8("Все"));
  updateButtonsText();
  mTabWidget->setCurrentIndex(curTab);
  //setTabEnabled(curTab, true);
}

void
CXParametersWindow::setProgressText(const QString& aText)
{
  if (mIsUpload)
    mProgressBar->setFormat(trUtf8("Сохранение ") + aText + " (%p%)");
  else
    mProgressBar->setFormat(trUtf8("Загружается ") + aText + " (%p%)");
}

void
CXParametersWindow::closeFtp()
{
  if (mProgressBar == NULL)
    return;

  mProgressBar->close();
  delete mProgressBar;
  mProgressBar = NULL;

  disconnect(mFtp, 0, 0, 0);

  mFtp->close();
  mFtp->deleteLater();
  mFtp = NULL;
}

void
CXParametersWindow::onFtpSuccess(bool aIsUpload)
{
  closeFtp();

  if (aIsUpload){
    mUdpManager->sendCommand(Commands::MSG_SECTION_PARAMS, Commands::MSG_CMD_REFRESH_PARAMS, "0");
  }
  loadParameters();
}

void
CXParametersWindow::onFtpError()
{
  closeFtp();
  loadParameters();
}

void
CXParametersWindow::showSettings()
{
  AXBaseWindow::mManager->setCurrentGroup(3);
}

void
CXParametersWindow::timerEvent(QTimerEvent* e)
{
  if (e->timerId() == mWaitTimer)
  {
    killTimer(mWaitTimer);
    mWaitTimer = -1;

    QMessageBox::information(NULL, trUtf8("Ошибка"), trUtf8("Нет ответа от ядра."));
    loadFiles(false);
  }
}

void
CXParametersWindow::buttonClicked()
{
  QPushButton* button = qobject_cast<QPushButton*>(sender());

  if (button != NULL)
  {
    mTabWidget->setCurrentIndex(mButtons.indexOf(button));
  }
}

void
CXParametersWindow::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{
  Q_UNUSED(aValue)

  if (aSection == QString::fromStdString(Commands::MSG_SECTION_PARAMS))
  {
    if (mWaitTimer != -1)
    {
      killTimer(mWaitTimer);
      mWaitTimer = -1;
    }

    if (aCommand == QString::fromStdString(Commands::MSG_STATE_RELOAD_PARAMS))
    {
      loadFiles(false);
    }
    else if (aCommand == QString::fromStdString(Commands::MSG_STATE_REFRESH_PARAMS))
    {

    }
  }
}

void
CXParametersWindow::loadFiles(bool aIsUpload)
{
  mIsUpload = aIsUpload;

  mProgressBar = new QProgressBar;
  mProgressBar->setWindowFlags(Qt::FramelessWindowHint);
  mProgressBar->setAlignment(Qt::AlignCenter);
  mProgressBar->setWindowModality(Qt::ApplicationModal);

  QSize size = QApplication::desktop()->availableGeometry().size();
  mProgressBar->resize(size.width() * 0.7, size.height() * 0.05);

  QString host = CXSettingsXML::getValue("settings.xml", "kernel_ip");

  mFtp = new CXFtp(this);
  mFtp->setConnectData(host, 21, "ftp", "ftp");
  mFtp->setLoadFilesData(QApplication::applicationDirPath() + "/jini", CXFtp::remoteCatalog);

  connect(mFtp, SIGNAL(progressMaximumChanged(int)), mProgressBar, SLOT(setMaximum(int)));
  connect(mFtp, SIGNAL(progressValueChanged(int)), mProgressBar, SLOT(setValue(int)));
  connect(mFtp, SIGNAL(progressTextChanged(const QString&)), this,
      SLOT(setProgressText(const QString&)));
  connect(mFtp, SIGNAL(allFilesIsLoaded(bool)), this, SLOT(onFtpSuccess(bool)));
  connect(mFtp, SIGNAL(errorReceived()), this, SLOT(onFtpError()));

  if (aIsUpload)
    mFtp->onFtpUpload(QStringList() << "*.ini" << "*.xml");
  else
    mFtp->onFtpDownload(QStringList() << "ini" << "xml");

  mProgressBar->show();
}

void
CXParametersWindow::clearData()
{
  clearTables();

  CXParameterData* curParamData = NULL;
  QList<CXParameterData*> parametersList = CXParametersView::mDataMap.values();
  while (!parametersList.isEmpty())
  {
    curParamData = parametersList.takeFirst();
    parametersList.removeAll(curParamData);
    delete curParamData;
  }

  CXParametersView::mDataMap.clear();
  qDeleteAll(CXParametersView::mGropusMap.begin(), CXParametersView::mGropusMap.end());
  CXParametersView::mGropusMap.clear();
}

void
CXParametersWindow::clearTables()
{
  //fileEditor = NULL;
  QWidget* curWidget = NULL;
  for (int i = 0; i < mTabWidget->count(); ++i)
  {
    curWidget = mTabWidget->widget(i);
    mTabWidget->removeTab(i);
    if(curWidget != fileEditor)delete curWidget;

    i--;
  }
}

void
CXParametersWindow::updateButtonsText()
{
  int groupIndex = 0;
  QList<CXGroupData*> groups = CXParametersView::mGropusMap.values();

  QString text;
  QPushButton* curButon = NULL;
  QList<QPushButton*>::iterator iter;
  for (iter = mButtons.begin(); iter != mButtons.end(); ++iter)
  {
    while (groupIndex < groups.count() && !groups.at(groupIndex)->mIsVisible)
      groupIndex++;

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
