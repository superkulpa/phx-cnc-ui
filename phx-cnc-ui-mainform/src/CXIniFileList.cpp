#include "CXIniFileList.h"

CXIniFileList::CXIniFileList() : AXBaseWindow()
{
	setupUi(this);

	mModel = new QFileSystemModel(this);
	mModel->setNameFilterDisables(false);
	mModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);

	mIniFileView->setModel(mModel);
	//mRootIndex = mModel->setRootPath(QApplication::applicationDirPath() + "/../cps");
	mIniFileView->setRootIndex(mModel->setRootPath(QApplication::applicationDirPath() + "/jini"));

	connect(mIniFileView, SIGNAL(activated(const QModelIndex&)), this, SLOT(onOpenFile()));

	registerManager();
}

CXIniFileList::~CXIniFileList()
{

}

void CXIniFileList::onOpenFile()
{
	if (mIniFileView->currentIndex().isValid()) emit fileOpened(mModel->filePath(mIniFileView->currentIndex()));
}
