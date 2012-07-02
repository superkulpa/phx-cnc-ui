#include "CXFilesList.h"

#include <QFile>

#include "CXSyntaxHighlighter.h"

CXFilesList::CXFilesList(QWidget* parent) : QWidget(parent)
{
	setupUi(this);

	mModel = new QFileSystemModel(this);
	mModel->setNameFilterDisables(false);

	mFileView->setModel(mModel);
	//mFileView->setRootIndex(mModel->setRootPath(QApplication::applicationDirPath() + "/../cps"));
	mFileView->setRootIndex(mModel->setRootPath("D:/cps"));

	CXSyntaxHighlighter* highlighter = new CXSyntaxHighlighter(mTextEdit->document());

	connect(mFileView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(onItemDoubleClick(const QModelIndex&)));
}

CXFilesList::~CXFilesList()
{

}

void CXFilesList::onItemDoubleClick(const QModelIndex& aIndex)
{
	QFile file(mModel->filePath(aIndex));
	file.open(QIODevice::ReadOnly);

	mTextEdit->setText(file.readAll());

	file.close();

	QProcess* process = new QProcess(this);

	connect(process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(onProcessFinish(int, QProcess::ExitStatus)));
	connect(process, SIGNAL(error(QProcess::ProcessError)), this, SLOT(onProcessError(QProcess::ProcessError)));

	process->start(QApplication::applicationDirPath() + "/compile.bat");

//	onProcessFinish(0, QProcess::NormalExit);
}

void CXFilesList::onProcessFinish(int aExitCode, QProcess::ExitStatus aExitStatus)
{
	if (aExitStatus == QProcess::NormalExit)
	{
		emit fileCreated(QApplication::applicationDirPath() + "/tmp/list.cpr.ccp", QApplication::applicationDirPath() + "/tmp/list.kerf.cpr.ccp");
	}
}

void CXFilesList::onProcessError(QProcess::ProcessError aError)
{
}
