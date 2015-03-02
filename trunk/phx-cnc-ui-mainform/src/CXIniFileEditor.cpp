#include "CXIniFileEditor.h"

#include <QTextStream>
//#include <QMessageBox>
#include <QApplication>
#include <QDesktopWidget>

#include "utils/CXSyntaxHighlighter.h"
#include "utils/CXFtp.h"
#include "utils/CXSettingsXML.h"
#include "CXUdpManager.h"

CXIniFileEditor::CXIniFileEditor() //:
{
  setupUi(this);

//  mIsUpload = false;
//  mProgressBar = NULL;

  mHighlighter = new CXIniSyntaxHighlighter(mIniFileEdit->document());

  mModel = new QFileSystemModel(this);
  mModel->setNameFilterDisables(false);
  mModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);

  mIniFileView->setModel(mModel);
  mIniFileView->setRootIndex(mModel->setRootPath(/*QApplication::applicationDirPath() + */"jini"));

  //QIcon icon; icon.addFile(QString::fromUtf8(":/images/down.png"), QSize(), QIcon::Normal, QIcon::Off);
  btnDown->setIcon(QIcon(":/images/down.png"));
  btnDown->setIconSize(QSize(24, 24));
  btnDown->setAutoRepeat(true);
  btnDown->setAutoRepeatInterval(100);
  btnUp->setIcon(QIcon(":/images/up.png"));
  btnUp->setIconSize(QSize(24, 24));
  btnUp->setAutoRepeat(true);
  btnUp->setAutoRepeatInterval(100);
  btnLoad->setIcon(QIcon(":/images/open_folder.png"));
  btnLoad->setIconSize(QSize(24, 24));
  btnLoad->setAutoRepeat(true);
  btnLoad->setAutoRepeatInterval(100);

  connect(btnDown, SIGNAL(clicked()), this, SLOT(onDownList()));
  connect(btnUp, SIGNAL(clicked()), this, SLOT(onUpList()));
  connect(btnLoad, SIGNAL(clicked()), this, SLOT(onOpenFile()));

  connect(mIniFileView, SIGNAL(activated(const QModelIndex&)), this, SLOT(onItemActivate(const QModelIndex&)));
  connect(this, SIGNAL(fileOpened(const QModelIndex&)), this, SLOT(onItemActivate(const QModelIndex&)));


  //registerManager();
}

CXIniFileEditor::~CXIniFileEditor()
{

}

QModelIndex
CXIniFileEditor::setCurrentItemToFirst()
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


void
CXIniFileEditor::onOpenFile()
{
  if (mIniFileView->currentIndex().isValid())
    emit fileOpened(mIniFileView->currentIndex());
//    onOpenFile(mModel->filePath(mIniFileView->currentIndex()));
}

void
CXIniFileEditor::onDownList()
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
CXIniFileEditor::onUpList()
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


void
CXIniFileEditor::onOpenFile(const QString& aFileName)
{
  if(mFileName.size() == 0) return ;
  mFileName = aFileName;

  QFile file(mFileName);
  file.open(QIODevice::ReadOnly);

  QTextStream in(&file);
  in.setCodec("UTF-8");

  mIniFileEdit->setPlainText(in.readAll());

  file.close();

  if (mIniFileEdit->toPlainText().at(0) == '<'
      && mHighlighter->metaObject()->className() != QString("CXXmlSyntaxHighlighter"))
  {
    delete mHighlighter;
    mHighlighter = new CXXmlSyntaxHighlighter(mIniFileEdit->document());
  }
  else if (mHighlighter->metaObject()->className() != QString("CXXmlSyntaxHighlighter"))
  {
    delete mHighlighter;
    mHighlighter = new CXIniSyntaxHighlighter(mIniFileEdit->document());
  }
}

void
CXIniFileEditor::onItemActivate(const QModelIndex& aIndex)
{
  mFileName = mModel->filePath(aIndex);
  onOpenFile(mFileName);
}


void
CXIniFileEditor::onSave()
{
  if (!mFileName.isEmpty() && QFile::exists(mFileName))
  {
//		if (QMessageBox::question(this, trUtf8(""), trUtf8("Вы действительно хотите перезаписать файл?"), QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) return;

    QFile file(mFileName);
    file.open(QIODevice::WriteOnly);

    QTextStream out(&file);
    out.setCodec("UTF-8");

    out << mIniFileEdit->toPlainText();

    file.close();

    //loadFiles(true);

//		QMessageBox::information(this, trUtf8(""), trUtf8("Файл \"%1\" успешно записан.").arg(mFileName));
  }
}

void
CXIniFileEditor::reloadFiles()
{
  onOpenFile(mFileName);
}
