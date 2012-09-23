#include "CXIniFileList.h"

CXIniFileList::CXIniFileList(QWidget* parent) : QWidget(parent)
{
	setupUi(this);

	mModel = new QFileSystemModel(this);
	mModel->setNameFilterDisables(false);
	mModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);

	mIniFileView->setModel(mModel);
	//mRootIndex = mModel->setRootPath(QApplication::applicationDirPath() + "/../cps");
	mIniFileView->setRootIndex(mModel->setRootPath(QApplication::applicationDirPath() + "/jini"));

	connect(mIniFileView, SIGNAL(activated(const QModelIndex&)), this, SLOT(onItemActivate(const QModelIndex&)));
	connect(mSaveButton, SIGNAL(clicked()), this, SIGNAL(fileSaved()));
}

CXIniFileList::~CXIniFileList()
{

}

void CXIniFileList::onItemActivate(const QModelIndex& aIndex)
{
	emit fileOpened(mModel->filePath(aIndex));
}
