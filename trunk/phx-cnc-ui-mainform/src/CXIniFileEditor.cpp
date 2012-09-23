#include "CXIniFileEditor.h"

#include <QTextStream>
#include <QMessageBox>

#include "CXSyntaxHighlighter.h"

CXIniFileEditor::CXIniFileEditor(QWidget* parent) : QWidget(parent)
{
	setupUi(this);

	mHighlighter = new CXIniSyntaxHighlighter(mIniFileEdit->document());
}

CXIniFileEditor::~CXIniFileEditor()
{

}

void CXIniFileEditor::onOpenFile(const QString& aFileName)
{
	mFileName = aFileName;

	QFile file(mFileName);
	file.open(QIODevice::ReadOnly);

	QTextStream in(&file);
	in.setCodec("UTF-8");

	mIniFileEdit->setPlainText(in.readAll());

	file.close();

	if (mIniFileEdit->toPlainText().at(0) == '<' && mHighlighter->metaObject()->className() != "CXXmlSyntaxHighlighter")
	{
		delete mHighlighter;
		mHighlighter = new CXXmlSyntaxHighlighter(mIniFileEdit->document());
	}
	else if (mHighlighter->metaObject()->className() != "CXXmlSyntaxHighlighter")
	{
		delete mHighlighter;
		mHighlighter = new CXIniSyntaxHighlighter(mIniFileEdit->document());
	}
}

void CXIniFileEditor::onSave()
{
	if (!mFileName.isEmpty() && QFile::exists(mFileName))
	{
		if (QMessageBox::question(this, trUtf8(""), trUtf8("Вы действительно хотите перезаписать файл?"), QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) return;

		QFile file(mFileName);
		file.open(QIODevice::WriteOnly);

		QTextStream out(&file);
		out.setCodec("UTF-8");

		out << mIniFileEdit->toPlainText();

		file.close();

		QMessageBox::information(this, trUtf8(""), trUtf8("Файл \"%1\" успешно записан.").arg(mFileName));
	}
}
