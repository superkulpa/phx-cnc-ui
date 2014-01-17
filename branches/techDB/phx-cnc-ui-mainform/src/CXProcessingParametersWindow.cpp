#include "CXProcessingParametersWindow.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QFileInfo>
#include <QDir>

#include "CXParametersView.h"
#include "CXWindowsManager.h"
#include "CXFtp.h"
#include "CXSettingsXML.h"
#include "CXUdpManager.h"

CXProcessingParametersWindow::CXProcessingParametersWindow(QWidget* parent) :
    QDialog(parent)
{
  setupUi(this);
  setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);

  mFtp = NULL;
  mParametersView = new CXParametersView(this, CXParametersView::mDataMap.values(0));

  mCentralLayout->insertWidget(0, mParametersView);

  connect(mCancelButton, SIGNAL(clicked()), this, SLOT(reject()));
  connect(mLoadButton, SIGNAL(clicked()), this, SLOT(onFileLoad()));
}

CXProcessingParametersWindow::~CXProcessingParametersWindow()
{
}

void
CXProcessingParametersWindow::setFileName(const QString& aFileName, const QString& aFtpFileName)
{
  mFileName = aFileName;
  mFtpFileName = aFtpFileName;
}

void
CXProcessingParametersWindow::onFileLoad()
{
  QString host = CXSettingsXML::getValue("settings.xml", "kernel_ip");

  //QFile::rename(mFileName, mFtpFileName);

  QFileInfo fileInfo(mFileName);
  //QFileInfo fileFTPInfo(mFtpFileName);

  mFtp = new CXFtp(this);

  mFtp->setConnectData(host, 21, "ftp", "ftp");
  mFtp->setLoadFilesData(fileInfo.absoluteDir().absolutePath(), CXFtp::remoteCatalog);

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
      iter.value()->save();
    }

    loadFiles << "*.ini";
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
  AXBaseWindow::mUdpManager->sendCommand(Commands::MSG_SECTION_PARAMS,
      Commands::MSG_CMD_REFRESH_PARAMS, "0");
  AXBaseWindow::mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_LOAD_CP,
      mFtpFileName.toStdString());
  accept();
}
