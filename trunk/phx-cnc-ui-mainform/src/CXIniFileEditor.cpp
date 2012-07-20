#include "CXIniFileEditor.h"

#include <QMessageBox>
#include <QTextStream>

#include "CXSyntaxHighlighter.h"

CXIniFileEditor::CXIniFileEditor(QWidget* parent) : QWidget(parent)
{
	setupUi(this);

	mHighlighter = new CXIniSyntaxHighlighter(mIniFileEdit->document());

	mModel = new QFileSystemModel(this);
	mModel->setNameFilterDisables(false);
	mModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);

	mIniFileView->setModel(mModel);
	//mRootIndex = mModel->setRootPath(QApplication::applicationDirPath() + "/../cps");
	mIniFileView->setRootIndex(mModel->setRootPath(QApplication::applicationDirPath() + "/jini"));

	connect(mIniFileView, SIGNAL(activated(const QModelIndex&)), this, SLOT(onItemActivate(const QModelIndex&)));
	connect(mSaveButton, SIGNAL(clicked()), this, SLOT(onSave()));
}

CXIniFileEditor::~CXIniFileEditor()
{

}

void CXIniFileEditor::onItemActivate(const QModelIndex& aIndex)
{
	mFileName = mModel->filePath(aIndex);

	QFile file(mFileName);
	file.open(QIODevice::ReadOnly);

	mIniFileEdit->setPlainText(file.readAll());

	file.close();

	QFileInfo fileInfo(mFileName);
	if (fileInfo.suffix() == "xml" && mHighlighter->metaObject()->className() != "CXXmlSyntaxHighlighter")
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
		out << mIniFileEdit->toPlainText();

		file.close();

		QMessageBox::information(this, trUtf8(""), trUtf8("Файл \"%1\" успешно записан.").arg(mFileName));
	}
}
