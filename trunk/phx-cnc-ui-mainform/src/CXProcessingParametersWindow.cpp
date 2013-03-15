#include "CXProcessingParametersWindow.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QFileInfo>
#include <QDir>

#include "CXParametersView.h"
#include "CXWindowsManager.h"
#include "CXFtp.h"
#include "CXSettingsXML.h"

CXProcessingParametersWindow::CXProcessingParametersWindow(QWidget* parent) : QDialog(parent)
{
	setupUi(this);

	mFtp = NULL;
	mParametersView = new CXParametersView(this, CXParametersView::mDataMap.values(0));

	mCentralLayout->insertWidget(0, mParametersView);

	connect(mCancelButton, SIGNAL(clicked()), this, SLOT(reject()));
	connect(mLoadButton, SIGNAL(clicked()), this, SLOT(onFileLoad()));
}

CXProcessingParametersWindow::~CXProcessingParametersWindow()
{
}

void CXProcessingParametersWindow::setFileName(const QString& aFileName, const QString& aFtpFileName)
{
	mFileName = aFileName;
	mFtpFileName = QFileInfo(mFileName).absoluteDir().absoluteFilePath(QFileInfo(aFtpFileName).fileName());
}

void CXProcessingParametersWindow::onFileLoad()
{
	QString host = CXSettingsXML::getValue("settings.xml", "kernel_ip");

	QFile::rename(mFileName, mFtpFileName);

	QFileInfo fileInfo(mFtpFileName);

	mFtp = new CXFtp(this);

	mFtp->setConnectData(host, 21, "ftp", "ftp");
	mFtp->setLoadFilesData(/*fileInfo.absoluteDir().absolutePath()*/
	    QApplication::applicationDirPath() + "/jini" , "pub/updates/jini");

	connect(mFtp, SIGNAL(allFilesIsLoaded(bool)), this, SLOT(onAllFilesIsLoaded(bool)));
	connect(mFtp, SIGNAL(errorReceived()), this, SLOT(closeFtp()));

	QStringList loadFiles;
	loadFiles << fileInfo.fileName();

	if (mParametersView->isModified())
	{

    QMap <int, CXParameterData*>::iterator iter;
    for (iter = CXParametersView::mDataMap.begin(); iter != CXParametersView::mDataMap.end(); ++iter)
    {
      iter.value()->save();
    }
	  loadFiles << "*.ini";
	}

	mFtp->onFtpUpload(loadFiles);
}

void CXProcessingParametersWindow::closeFtp()
{
	if (mFtp == NULL) return;
	
	QFile::rename(mFtpFileName, mFileName);

	disconnect(mFtp, 0, 0, 0);

	mFtp->close();
	mFtp->deleteLater();
	mFtp = NULL;
}

void CXProcessingParametersWindow::onAllFilesIsLoaded(bool aIsUpload)
{
	Q_UNUSED(aIsUpload);

	closeFtp();

	AXBaseWindow::mManager->setCurrentGroup(4);
	accept();
}
