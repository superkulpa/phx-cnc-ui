#include "CXFilesList.h"

#include <QFile>
#include <QApplication>
#include <QDomDocument>
#include <QTextStream>
#include <QMessageBox>

#include "CXParametersView.h"

#define ROOT_PATH "./cps"

CXFilesList::CXFilesList(QWidget* parent) : QWidget(parent)
{
	setupUi(this);

	mIsModifier = false;
	mIsCompileNeed = false;

	mModel = new QFileSystemModel(this);
	mModel->setNameFilterDisables(false);
	mModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);

	mFileView->setModel(mModel);
	//mRootIndex = mModel->setRootPath(QApplication::applicationDirPath() + "/../cps");
	mRootIndex = mModel->setRootPath(ROOT_PATH);
	mFileView->setRootIndex(mRootIndex);

	mUpButton->setEnabled(false);
	mOpenButton->setEnabled(false);

	connect(mFileView, SIGNAL(activated(const QModelIndex&)), this, SLOT(onItemActivate(const QModelIndex&)));
	connect(mDownButton, SIGNAL(clicked()), this, SLOT(onDownList()));
	connect(mUpButton, SIGNAL(clicked()), this, SLOT(onUpList()));
	connect(mOpenButton, SIGNAL(clicked()), this, SLOT(onOpen()));

	connect(mModel, SIGNAL(directoryLoaded(const QString&)), this, SLOT(onDirectoryLoaded()));
	connect(mFileView->selectionModel(), SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onCurrentChanged(const QModelIndex&, const QModelIndex&)));
}

CXFilesList::~CXFilesList()
{

}

void CXFilesList::onCreateNewFile()
{
	QFile newFile(QString(ROOT_PATH).append("/noname.cp"));
	newFile.open(QIODevice::WriteOnly);

	newFile.close();

	emit fileOpened(newFile.fileName());
}

void CXFilesList::setButton(QPushButton* aButton)
{
	mButton = aButton;

	connect(mButton, SIGNAL(clicked()), this, SLOT(onLoadCheckFile()));
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

//		setCurrentItemToFirst();
		onDirectoryLoaded();

		return;
	}

	mFileName = mModel->filePath(aIndex);

	emit fileOpened(mFileName);

	onCompileFile();
}

void CXFilesList::onDownList()
{
	QModelIndex curIndex = mFileView->currentIndex();
	if (!curIndex.isValid())
	{
		setCurrentItemToFirst();
		return;
	}

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

void CXFilesList::onDirectoryLoaded()
{
	mFileView->setCurrentIndex(QModelIndex());
/*
	QApplication::processEvents();

	setCurrentItemToFirst();
*/
}

void CXFilesList::onCurrentChanged(const QModelIndex& current, const QModelIndex& previous)
{
	mOpenButton->setEnabled(mFileView->currentIndex().isValid());
	mUpButton->setEnabled(mModel->index(current.row() - 1, current.column(), mFileView->rootIndex()).isValid());
	mDownButton->setEnabled(!current.isValid() || mModel->index(current.row() + 1, current.column(), mFileView->rootIndex()).isValid());
}

QModelIndex CXFilesList::setCurrentItemToFirst()
{
	if (!mFileView->currentIndex().isValid() || mFileView->selectionModel()->selectedIndexes().isEmpty() || !mFileView->hasFocus())
	{
		QModelIndex newIndex = mModel->index(0, 0, mFileView->rootIndex());

		mFileView->setCurrentIndex(newIndex);

		return newIndex;
	}

	return mFileView->currentIndex();
}

void CXFilesList::onCompileFile()
{
	if (mFileName.isEmpty()) return;

	QProcess* process = new QProcess(this);

	connect(process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(onProcessFinish(int, QProcess::ExitStatus)));
	connect(process, SIGNAL(error(QProcess::ProcessError)), this, SLOT(onProcessError(QProcess::ProcessError)));

	QFile configFile("./jini/compiler0.cfg");
	configFile.open(QIODevice::ReadOnly);

	QDomDocument doc;
	doc.setContent(&configFile);

	QDomElement domElement = doc.documentElement();
	if (!domElement.isNull())
	{
		domElement = domElement.firstChildElement("parameter");

		while (!domElement.isNull())
		{
			if (domElement.attribute("name") == QString("Common.CpName"))
			{
				domElement.setAttribute("value", mFileName);

				break;
			}

			domElement = domElement.nextSiblingElement("parameter");
		}
	}

	configFile.close();

	process->start("bash ./cpc.sh");
}

void CXFilesList::onLoadCheckFile()
{
	if (mIsModifier)
	{
		QMessageBox::information(this, trUtf8("Информация"), trUtf8("Сохраните изменения перед выполнением операции проверки!"));
		return;
	}

	if (mIsCompileNeed)
	{
		onCompileFile();

		if (mButton != NULL) mButton->setText( mButton->text().replace(QRegExp("\n.*"), trUtf8("\nЗагрузить")));

		return;
	}

/**/

	CXParametersView* parametersView = new CXParametersView(NULL, CXParametersView::mDataMap.values(-1));
	parametersView->setAttribute(Qt::WA_DeleteOnClose);
	parametersView->setWindowFlags(Qt::Dialog);
	parametersView->setWindowModality(Qt::ApplicationModal);
	parametersView->resize(800, 600);

	parametersView->show();
}

void CXFilesList::onTextChanged(bool aIsSaved)
{
	if (aIsSaved)
	{
		mIsModifier = false;
		return;
	}

	if (!mIsModifier && !mFileName.isEmpty())
	{
		mIsModifier = true;
		mIsCompileNeed = true;

		if (mButton != NULL) mButton->setText( mButton->text().replace(QRegExp("\n.*"), trUtf8("\nПроверить")));
	}
}

void CXFilesList::onProcessFinish(int aExitCode, QProcess::ExitStatus aExitStatus)
{
	if (aExitStatus == QProcess::NormalExit)
	{
		//emit fileCreated(QApplication::applicationDirPath() + "/tmp/list.cpr.ccp", QApplication::applicationDirPath() + "/tmp/list.kerf.cpr.ccp");
		emit fileCreated(QApplication::applicationDirPath() + getConfigAttribute("Common.OutputCpName"), QApplication::applicationDirPath() + getConfigAttribute("Common.OutputCpNameKerf"));

		QFile compileFile(QApplication::applicationDirPath() + getConfigAttribute("Common.OutputInfo"));
		compileFile.open(QIODevice::ReadOnly);

		QTextStream in(&compileFile);
		in.setCodec("UTF-8");

		mCompileEdit->setText(in.readAll());

		compileFile.close();
	}
}

void CXFilesList::onProcessError(QProcess::ProcessError aError)
{
	QMessageBox::critical(this, trUtf8("Ошибка"), qobject_cast<QProcess*>(sender())->errorString());
}

QString CXFilesList::getConfigAttribute(const QString& aAttributeName)
{
	QFile configFile("./jini/compiler0.cfg");
	configFile.open(QIODevice::ReadOnly);

	QDomDocument doc;
	doc.setContent(&configFile);

	QDomElement domElement = doc.documentElement();
	domElement = domElement.firstChildElement("parameters");

	if (!domElement.isNull())
	{
		domElement = domElement.firstChildElement("parameter");

		while (!domElement.isNull())
		{
			if (domElement.attribute("name") == aAttributeName)
			{
				return domElement.attribute("value");

				break;
			}

			domElement = domElement.nextSiblingElement("parameter");
		}
	}

	return QString();
}
