#include "CXEditPathFile.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include "CXSyntaxHighlighter.h"

CXEditPathFile::CXEditPathFile(QWidget* parent) : QWidget(parent)
{
	setupUi(this);

	new CXSyntaxHighlighter(mTextEdit->document());

	connect(mSaveButton, SIGNAL(clicked()), this, SLOT(onSave()));
}

CXEditPathFile::~CXEditPathFile()
{

}

void CXEditPathFile::openFile(const QString& aFileName)
{
	mFileName = aFileName;

	QFile file(aFileName);
	file.open(QIODevice::ReadOnly);

	mTextEdit->setText(file.readAll());

	file.close();
}

void CXEditPathFile::onSave()
{
	if (!mFileName.isEmpty() && QFile::exists(mFileName))
	{
		if (QMessageBox::question(this, trUtf8(""), trUtf8("Вы действительно хотите перезаписать файл?"), QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) return;

		QFile file(mFileName);
		file.open(QIODevice::WriteOnly);

		QTextStream out(&file);
		out << mTextEdit->toPlainText();

		file.close();

		QMessageBox::information(this, trUtf8(""), trUtf8("Файл \"%1\" успешно записан.").arg(mFileName));
	}
}
