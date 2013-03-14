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

void CXProcessingParametersWindow::setFileName(const QString& aFileName)
{
	mFileName = aFileName;
}

void CXProcessingParametersWindow::onFileLoad()
{
	QString host = CXSettingsXML::getValue("settings.xml", "kernel_ip");

	QFileInfo fileInfo(mFileName);

	mFtp = new CXFtp(this);
	mFtp->setConnectData(host, 21, "ftp", "ftp");
	mFtp->setLoadFilesData(fileInfo.absoluteDir().absolutePath(), "pub/updates/jini");

	connect(mFtp, SIGNAL(allFilesIsLoaded(bool)), this, SLOT(onAllFilesIsLoaded(bool)));
	connect(mFtp, SIGNAL(errorReceived()), this, SLOT(closeFtp()));

	mFtp->onFtpUpload(QStringList() << fileInfo.fileName());
}

void CXProcessingParametersWindow::closeFtp()
{
	if (mFtp == NULL) return;

	disconnect(mFtp, 0, 0, 0);

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
