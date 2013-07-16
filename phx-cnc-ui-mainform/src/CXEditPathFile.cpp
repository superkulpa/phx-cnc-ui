#include "CXEditPathFile.h"

#include <QFile>
#include <QTextStream>
//#include <QMessageBox>
#include <QFileDialog>

#include "CXSyntaxHighlighter.h"
#include "CXFilesList.h"

CXEditPathFile::CXEditPathFile() :
    AXBaseWindow()
{
  setupUi(this);

  mSaveDialog = NULL;

  mTextEdit->setReadOnly(true);
  /*
   mSaveButton->setFont(QFont("", mSaveButton->height() / 5));
   mSaveAsButton->setFont(QFont("", mSaveButton->height() / 5));
   mCreateButton->setFont(QFont("", mSaveButton->height() / 5));
   */
  new CXSyntaxHighlighter(mTextEdit->document());

  connect(mSaveButton, SIGNAL(clicked()), this, SLOT(onSave()));
  connect(mSaveAsButton, SIGNAL(clicked()), this, SLOT(onSaveAs()));
  connect(mCreateButton, SIGNAL(clicked()), this, SIGNAL(newFileCreated()));
  connect(mStatButton, SIGNAL(clicked()), this, SIGNAL(statSaved()));

  connect(mTextEdit, SIGNAL(cursorPositionChanged()), this, SLOT(onCursorPositionChange()));
  connect(mTextEdit, SIGNAL(textChanged()), this, SIGNAL(textChanged()));

  registerManager();
}

CXEditPathFile::~CXEditPathFile()
{

}

void
CXEditPathFile::openFile(const QString& aFileName)
{
  mFileName = aFileName;

  mTitleGroup->setTitle(
      QFontMetrics(mTitleGroup->font()).elidedText(QFileInfo(mFileName).fileName(), Qt::ElideMiddle,
          mTitleGroup->width() - 10));

  QFile file(aFileName);
  file.open(QIODevice::ReadOnly);

  QTextStream in(&file);
  in.setCodec("UTF-8");

  mTextEdit->setReadOnly(false);
  mTextEdit->blockSignals(true);
  mTextEdit->setText(in.readAll());
  mTextEdit->blockSignals(false);

  file.close();
}

void
CXEditPathFile::onSave()
{
  if (!mFileName.isEmpty() && QFile::exists(mFileName))
  {
//		if (QMessageBox::question(this, trUtf8(""), trUtf8("Вы действительно хотите перезаписать файл?"), QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) return;

    QFile file(mFileName);
    file.open(QIODevice::WriteOnly);

    QTextStream out(&file);
    out.setCodec("UTF-8");

    out << mTextEdit->toPlainText();

    file.close();

    emit textChanged(true);

//		QMessageBox::information(this, trUtf8(""), trUtf8("Файл \"%1\" успешно записан.").arg(mFileName));
  }
}

void
CXEditPathFile::onSaveAs()
{
  if (!mFileName.isEmpty() && QFile::exists(mFileName))
  {

    if (mSaveDialog == NULL)
    {
      mSaveDialog = new CXFilesList(true);
      mSaveDialog->setGroupNumber(-1);
      mSaveDialog->setWindowModality(Qt::ApplicationModal);
      connect(mSaveDialog, SIGNAL(fileSaved(const QString&)), this, SLOT(onSaveAs(const QString&)));
    }

    mSaveDialog->show();

    return;
    /*
     QFileDialog fileDialog(this);
     fileDialog.setAcceptMode(QFileDialog::AcceptSave);
     fileDialog.setModal(false);
     fileDialog.setWindowModality(Qt::WindowModal);
     fileDialog.exec();

     QString fileName = fileDialog.selectedFiles().first();
     */
    QString fileName = QFileDialog::getSaveFileName(this, trUtf8("Сохранить как"), mFileName,
        QString(), NULL/*, QFileDialog::DontUseNativeDialog*/);

    if (!fileName.isEmpty())
    {
      mFileName = fileName;
      QFile file(mFileName);
      file.open(QIODevice::WriteOnly);

      QTextStream out(&file);
      out.setCodec("UTF-8");

      out << mTextEdit->toPlainText();

      file.close();

//			QMessageBox::information(this, trUtf8(""), trUtf8("Файл \"%1\" успешно записан.").arg(mFileName));
    }
  }
}

void
CXEditPathFile::onError(const QString& aText, int aLineNumber)
{
  Q_UNUSED(aText)

  QTextDocument* doc = mTextEdit->document();
  QTextBlock textBlock = doc->findBlockByLineNumber(aLineNumber - 1);
  int pos = textBlock.position();

  QTextCursor textCursor = mTextEdit->textCursor();
  textCursor.setPosition(pos);
  textCursor.select(QTextCursor::LineUnderCursor);
  mTextEdit->setTextCursor(textCursor);
}

void
CXEditPathFile::onCursorPositionChange()
{
  mCurrentLineLabel->setText(
      trUtf8("Текущая строка: %1").arg(mTextEdit->textCursor().blockNumber() + 1));
}

void
CXEditPathFile::onSaveAs(const QString& aFileName)
{
  if (!aFileName.isEmpty())
  {
    mFileName = aFileName;
    QFile file(mFileName);
    file.open(QIODevice::WriteOnly);

    QTextStream out(&file);
    out.setCodec("UTF-8");

    out << mTextEdit->toPlainText();

    file.close();
  }
}
