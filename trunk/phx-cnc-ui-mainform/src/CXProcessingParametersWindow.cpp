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
	mFtp->setLoadFilesData(fileInfo.absoluteDir().absolutePath(), "unitverru/www/!test!");

	connect(mFtp, SIGNAL(allFilesIsLoaded(bool)), this, SLOT(onAllFilesIsLoaded(bool)));

	mFtp->onFtpUpload(QStringList() << fileInfo.fileName());
}

void CXProcessingParametersWindow::onAllFilesIsLoaded(bool aIsUpload)
{
	Q_UNUSED(aIsUpload);

	if (mFtp == NULL) return;

	mFtp->deleteLater();
	mFtp = NULL;

	AXBaseWindow::mManager->setCurrentGroup(4);
	accept();
}
