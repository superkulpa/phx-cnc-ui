#include "CXProcessingParametersWindow.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QFileInfo>
#include <QDir>

#include "CXParametersView.h"
#include "CXWindowsManager.h"
#include "utils/CXFtp.h"
#include "utils/CXSettingsXML.h"
#include "CXUdpManager.h"
#include "CXParamui.h"

CXProcessingParametersWindow::CXProcessingParametersWindow(QWidget* _parent) :
    QDialog(_parent)
{
  setupUi(this);
  setWindowFlags(Qt::Dialog /*| Qt::WindowCloseButtonHint*/);

  mFtp = NULL;
  mParametersView = new CXParametersView(this, CXParametersView::mDataMap.values(0));

  mCentralLayout->insertWidget(0, mParametersView);

  connect(mCancelButton, SIGNAL(clicked()), this, SLOT(reject()));
  connect(mLoadButton, SIGNAL(clicked()), this, SLOT(onFileLoad()));
  connect(mLoadBaseButton, SIGNAL(clicked()), this, SLOT(onLoadDB()));

  connect(this, SIGNAL(accepted()), parent(), SLOT(onAccept()) );
}

CXProcessingParametersWindow::~CXProcessingParametersWindow()
{
  disconnect(AXBaseWindow::mManager->getWindow("CXParamUi"), SIGNAL(iniSaved())
          , this, SLOT(close() ));
//  disconnect(this, SIGNAL(accepted()), parent(), SLOT(onAccept()) );
  disconnect(AXBaseWindow::mManager->getWindow("CXParamUi"), SIGNAL(iniSaved())
         , AXBaseWindow::mManager->getWindow("CXFilesList"), SLOT(onAccept()) );
}

void
CXProcessingParametersWindow::setFileName(const QString& aFileName, const QString& aFtpFileName)
{
  mFileName = aFileName;
  mFtpFileName = aFtpFileName;
}

void CXProcessingParametersWindow::onLoadDB(){
//  AXBaseWindow::mManager->getWindow("CXParamUi")->show();
   //AXBaseWindow* parametersWindow = AXBaseWindow::mManager->getWindow("CXParamUi");//= new CXParamUi();
   //connect(parametersWindow, SIGNAL(iniSaved()), this, SLOT(close()));
  connect(AXBaseWindow::mManager->getWindow("CXParamUi"), SIGNAL(iniSaved())
         , AXBaseWindow::mManager->getWindow("CXFilesList"), SLOT(onAccept()) );

//          , this, SIGNAL(accepted()));
  connect(AXBaseWindow::mManager->getWindow("CXParamUi"), SIGNAL(closed())
          , this, SLOT(close() ));

//
//  connect(AXBaseWindow::mManager->getWindow("CXParamUi"), SIGNAL(closed())
//         , this, SLOT(show()) );
  hide();
  AXBaseWindow::mManager->getWindow("CXParamUi")->show();
  //close();
//   if (parametersWindow->show() == QDialog::Accepted)
//   {
//     accept();
//   }
}

void
CXProcessingParametersWindow::onFileLoad()
{
  QString host = CXSettingsXML::getValue("settings.xml", "kernel_ip", "192.168.0.125");

  //QFile::rename(mFileName, mFtpFileName);

  QFileInfo fileInfo(mFileName);
//  qDebug() << QApplication::applicationDirPath() + "/tmp/list.kerf.ccp";
//  qDebug() << QApplication::applicationDirPath() + "/jini";

  QFile::remove(/* QApplication::applicationDirPath() +*/ "jini/list.kerf.ccp");
  QFile::copy( /*QApplication::applicationDirPath() + */ "tmp/list.kerf.ccp"
      , /* QApplication::applicationDirPath() +*/ "jini/list.kerf.ccp");

  //QFileInfo fileFTPInfo(mFtpFileName);
  QString pswrd = CXSettingsXML::getValue("settings.xml", "ftp", "ftp");

  mFtp = new CXFtp(this);
  mFtp->setConnectData(host, 21, "ftp", pswrd);
//  mFtp->setLoadFilesData(fileInfo.absoluteDir().absolutePath(), CXFtp::remoteCatalog);
  mFtp->setLoadFilesData("jini", CXFtp::remoteCatalog);

  //записываем куда загрузится
  //mFtpFileName = "pub/updates/jini/" + mFtpFileName;

  connect(mFtp, SIGNAL(allFilesIsLoaded(bool)), this, SLOT(onAllFilesIsLoaded(bool)));
  connect(mFtp, SIGNAL(errorReceived()), this, SLOT(closeFtp()));

  QStringList loadFiles;
  loadFiles << fileInfo.fileName();

  if (mParametersView->isModified())
  {
    mParametersView->resetIsModified();

    QMap<int, CXParameterData*>::iterator iter;
    for (iter = CXParametersView::mDataMap.begin(); iter != CXParametersView::mDataMap.end();
        ++iter)
    {
      if(iter.value()->isModified){
        if(!loadFiles.contains( QFileInfo(iter.value()->mConfigFileName).fileName()))
          loadFiles << QFileInfo(iter.value()->mConfigFileName).fileName();
        iter.value()->save();
      }
    }
  }
  mFtp->onFtpUpload(loadFiles);
}

void
CXProcessingParametersWindow::closeFtp()
{
  if (mFtp == NULL)
    return;

  QFile::rename(mFtpFileName, mFileName);

  disconnect(mFtp, 0, 0, 0);

  mFtp->close();
  mFtp->deleteLater();
  mFtp = NULL;
}

void
CXProcessingParametersWindow::onAllFilesIsLoaded(bool aIsUpload)
{
  Q_UNUSED(aIsUpload);

  closeFtp();

  AXBaseWindow::mManager->setCurrentGroup(4);
  if(aIsUpload){
    AXBaseWindow::mUdpManager->sendCommand(Commands::MSG_SECTION_PARAMS,Commands::MSG_CMD_RELOAD_PARAMS,
        "0");

    AXBaseWindow::mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_LOAD_CP,
        mFtpFileName);
  }
  accept();
}
