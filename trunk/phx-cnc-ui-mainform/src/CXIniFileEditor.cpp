#include "CXIniFileEditor.h"

#include <QTextStream>
//#include <QMessageBox>
#include <QApplication>
#include <QDesktopWidget>

#include "CXSyntaxHighlighter.h"
#include "CXFtp.h"
#include "CXSettingsXML.h"
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
  //mRootIndex = mModel->setRootPath(QApplication::applicationDirPath() + "/../cps");
  mIniFileView->setRootIndex(mModel->setRootPath(QApplication::applicationDirPath() + "/jini"));

//  connect(mIniFileView, SIGNAL(activated(const QModelIndex&)), this, SLOT(onOpenFile()));
//  connect(mIniFileView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(onOpenFile()));
//  connect(mIniFileView, SIGNAL(pressed(const QModelIndex&)), this, SLOT(onOpenFile()));

//
//  connect(mIniFileView, SIGNAL(fileOpened(const QString&)), this, SLOT(onOpenFile(const QString&)));
//  connect(mIniFileView, SIGNAL(fileSaved()), this, SLOT(onSave()));

  connect(mIniFileView, SIGNAL(activated(const QModelIndex&)), this,
      SLOT(onItemActivate(const QModelIndex&)));
  //registerManager();
}

CXIniFileEditor::~CXIniFileEditor()
{

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

//    loadFiles(true);

//		QMessageBox::information(this, trUtf8(""), trUtf8("Файл \"%1\" успешно записан.").arg(mFileName));
  }
}

void
CXIniFileEditor::reloadFiles()
{
  onOpenFile(mFileName);
}



void
CXIniFileEditor::onOpenFile()
{
  if (mIniFileView->currentIndex().isValid())
    emit fileOpened(mModel->filePath(mIniFileView->currentIndex()));
}

