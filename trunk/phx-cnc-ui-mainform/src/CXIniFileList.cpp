#include "CXIniFileList.h"

CXIniFileList::CXIniFileList() :
    AXBaseWindow()
{
  setupUi(this);

  mModel = new QFileSystemModel(this);
  mModel->setNameFilterDisables(false);
  mModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);

  mIniFileView->setModel(mModel);
  mIniFileView->setRootIndex(mModel->setRootPath(/*QApplication::applicationDirPath() +*/ "jini"));

  connect(mIniFileView, SIGNAL(activated(const QModelIndex&)), this, SLOT(onOpenFile()));

  connect(btnDown, SIGNAL(clicked()), this, SLOT(onDownList()));
  connect(btnUp, SIGNAL(clicked()), this, SLOT(onUpList()));
  connect(btnLoad, SIGNAL(clicked()), this, SLOT(onOpenFile()));

  registerManager();
}

CXIniFileList::~CXIniFileList()
{

}

void
CXIniFileList::onOpenFile()
{
  if (mIniFileView->currentIndex().isValid())
    emit fileOpened(mModel->filePath(mIniFileView->currentIndex()));
}

void
CXIniFileList::onDownList()
{
  QModelIndex curIndex = mIniFileView->currentIndex();
  if (!curIndex.isValid())
  {
    setCurrentItemToFirst();
    return;
  }

  QModelIndex newIndex = mModel->index(curIndex.row() + 1, curIndex.column(),  mIniFileView->rootIndex());

  mIniFileView->setFocus();

  if (newIndex.isValid())
    mIniFileView->setCurrentIndex(newIndex);
  else
    mIniFileView->setCurrentIndex(curIndex);
}

void
CXIniFileList::onUpList()
{
  QModelIndex curIndex = mIniFileView->currentIndex();
  if (!curIndex.isValid())
  {
    setCurrentItemToFirst();
    return;
  }

  QModelIndex newIndex = mModel->index(curIndex.row() - 1, curIndex.column(),  mIniFileView->rootIndex());

  mIniFileView->setFocus();

  if (newIndex.isValid())
    mIniFileView->setCurrentIndex(newIndex);
  else
    mIniFileView->setCurrentIndex(curIndex);
}

QModelIndex
CXIniFileList::setCurrentItemToFirst()
{
  if (!mIniFileView->currentIndex().isValid()
      || mIniFileView->selectionModel()->selectedIndexes().isEmpty()
      || !mIniFileView->hasFocus())
  {
    QModelIndex newIndex = mModel->index(0, 0, mIniFileView->rootIndex());

    mIniFileView->setCurrentIndex(newIndex);

    return newIndex;
  }

  return mIniFileView->currentIndex();
}
