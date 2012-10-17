#include "CXEditPathFile.h"

#include <QFile>
#include <QTextStream>
//#include <QMessageBox>
#include <QFileDialog>

#include "CXSyntaxHighlighter.h"

CXEditPathFile::CXEditPathFile() : AXBaseWindow()
{
	setupUi(this);

	mTextEdit->setReadOnly(true);

	mSaveButton->setFont(QFont("", mSaveButton->height() / 5));
	mSaveAsButton->setFont(QFont("", mSaveButton->height() / 5));
	mCreateButton->setFont(QFont("", mSaveButton->height() / 5));

	new CXSyntaxHighlighter(mTextEdit->document());

	connect(mSaveButton, SIGNAL(clicked()), this, SLOT(onSave()));
	connect(mSaveAsButton, SIGNAL(clicked()), this, SLOT(onSaveAs()));
	connect(mCreateButton, SIGNAL(clicked()), this, SIGNAL(newFileCreated()));
	connect(mTextEdit, SIGNAL(cursorPositionChanged()), this, SLOT(onCursorPositionChange()));
	connect(mTextEdit, SIGNAL(textChanged()), this, SIGNAL(textChanged()));
}

CXEditPathFile::~CXEditPathFile()
{

}

void CXEditPathFile::openFile(const QString& aFileName)
{
	mFileName = aFileName;

	mTitleLabel->setText(QString(mFileName).replace(QApplication::applicationDirPath() + "/cps/", ""));

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

void CXEditPathFile::onSave()
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

void CXEditPathFile::onSaveAs()
{
	if (!mFileName.isEmpty() && QFile::exists(mFileName))
	{
		QString fileName = QFileDialog::getSaveFileName(this, trUtf8("Сохранить как"), mFileName);

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

void CXEditPathFile::onCursorPositionChange()
{
    mCurrentLineLabel->setText(trUtf8("Текущая строка: %1").arg(mTextEdit->textCursor().blockNumber() + 1));
}
