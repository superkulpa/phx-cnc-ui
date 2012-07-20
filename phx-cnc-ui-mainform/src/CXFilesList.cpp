#include "CXFilesList.h"

#include <QFile>

CXFilesList::CXFilesList(QWidget* parent) : QWidget(parent)
{
	setupUi(this);

	mModel = new QFileSystemModel(this);
	mModel->setNameFilterDisables(false);
	mModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);

	mFileView->setModel(mModel);
	//mRootIndex = mModel->setRootPath(QApplication::applicationDirPath() + "/../cps");
	mRootIndex = mModel->setRootPath("D:/cps");
	mFileView->setRootIndex(mRootIndex);

	connect(mFileView, SIGNAL(activated(const QModelIndex&)), this, SLOT(onItemActivate(const QModelIndex&)));
	connect(mDownButton, SIGNAL(clicked()), this, SLOT(onDownList()));
	connect(mUpButton, SIGNAL(clicked()), this, SLOT(onUpList()));
	connect(mOpenButton, SIGNAL(clicked()), this, SLOT(onOpen()));

	connect(mModel, SIGNAL(directoryLoaded(const QString&)), this, SLOT(onDirectoryLoaded(const QString&)));
	connect(mFileView->selectionModel(), SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onCurrentChanged(const QModelIndex&, const QModelIndex&)));
}

CXFilesList::~CXFilesList()
{

}

void CXFilesList::onItemActivate(const QModelIndex& aIndex)
{
	if (mModel->isDir(aIndex))
	{
		if (mModel->data(aIndex).toString().compare(QString("..")) == 0)
		{
			QModelIndex index = mFileView->rootIndex();

			if (index.parent().isValid())
			{
				if (index.parent() == mRootIndex) mModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);
				mFileView->setRootIndex(index.parent());
			}
		}
		else
		{
			mModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDot);
			mFileView->setRootIndex(aIndex);
		}

		QModelIndex newIndex = mModel->index(0, 0, mFileView->rootIndex());
		mFileView->setCurrentIndex(newIndex);

		return;
	}

	emit fileOpened(mModel->filePath(aIndex));

	QProcess* process = new QProcess(this);

	connect(process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(onProcessFinish(int, QProcess::ExitStatus)));
	connect(process, SIGNAL(error(QProcess::ProcessError)), this, SLOT(onProcessError(QProcess::ProcessError)));

	process->start(QApplication::applicationDirPath() + "/compile.bat");

//	onProcessFinish(0, QProcess::NormalExit);
}

void CXFilesList::onDownList()
{
	QModelIndex curIndex = mFileView->currentIndex();

	QModelIndex newIndex = mModel->index(curIndex.row() + 1, curIndex.column(), mFileView->rootIndex());

	mFileView->setFocus();

	if (newIndex.isValid()) mFileView->setCurrentIndex(newIndex);
	else mFileView->setCurrentIndex(curIndex);
}

void CXFilesList::onUpList()
{
	QModelIndex curIndex = mFileView->currentIndex();

	QModelIndex newIndex = mModel->index(curIndex.row() - 1, curIndex.column(), mFileView->rootIndex());

	mFileView->setFocus();

	if (newIndex.isValid()) mFileView->setCurrentIndex(newIndex);
	else mFileView->setCurrentIndex(curIndex);
}

void CXFilesList::onOpen()
{
	QModelIndex curIndex = mFileView->currentIndex();

	if (curIndex.isValid()) onItemActivate(curIndex);
}

void CXFilesList::onDirectoryLoaded(const QString& path)
{
	QApplication::processEvents();
	QModelIndex newIndex = mModel->index(0, 0, mFileView->rootIndex());

	mFileView->setCurrentIndex(newIndex);
}

void CXFilesList::onCurrentChanged(const QModelIndex& current, const QModelIndex& previous)
{
	mUpButton->setEnabled(mModel->index(current.row() - 1, current.column(), mFileView->rootIndex()).isValid());
	mDownButton->setEnabled(mModel->index(current.row() + 1, current.column(), mFileView->rootIndex()).isValid());
}

void CXFilesList::onProcessFinish(int aExitCode, QProcess::ExitStatus aExitStatus)
{
	if (aExitStatus == QProcess::NormalExit)
	{
		emit fileCreated(QApplication::applicationDirPath() + "/tmp/list.cpr.ccp", QApplication::applicationDirPath() + "/tmp/list.kerf.cpr.ccp");

		QFile compileFile(QApplication::applicationDirPath() + "/tmp/compile.out");
		compileFile.open(QIODevice::ReadOnly);

		mCompileEdit->setText(compileFile.readAll());

		compileFile.close();
	}
}

void CXFilesList::onProcessError(QProcess::ProcessError aError)
{
}
