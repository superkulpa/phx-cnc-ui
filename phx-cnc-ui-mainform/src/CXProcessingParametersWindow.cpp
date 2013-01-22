#include "CXProcessingParametersWindow.h"

#include <QVBoxLayout>
#include <QPushButton>

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

void CXProcessingParametersWindow::onFileLoad()
{
	QString host = CXSettingsXML::getValue("settings.xml", "kernel_ip");

	mFtp = new CXFtp(this);
	mFtp->setConnectData(host, 21, "ftp", "ftp");
	mFtp->setLoadFilesData(QApplication::applicationDirPath() + "/tmp", "pub/updates/jini");

	connect(mFtp, SIGNAL(allFilesIsLoaded(bool)), this, SLOT(onAllFilesIsLoaded(bool)));

	mFtp->onFtpUpload(QStringList()  << "list.kerf.cpr.ccp");

	AXBaseWindow::mManager->setCurrentGroup(4);
	accept();
}

void CXProcessingParametersWindow::onAllFilesIsLoaded(bool aIsUpload)
{
	Q_UNUSED(aIsUpload);

	if (mFtp == NULL) return;

	mFtp->deleteLater();
	mFtp = NULL;
}
