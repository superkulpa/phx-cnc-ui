#include "CXFilesList.h"

#include <QFile>
#include <QtGui/QApplication>
#include <QDomDocument>
#include <QTextStream>
#include <QtGui/QMessageBox>

#include "CXParametersView.h"
#include "CXProcessingParametersWindow.h"
#include "CXTurnDialog.h"
#include "CXUdpManager.h"
#include "CXWindowsManager.h"
#include "utils/CXMLReader.h"
#include <QtGui/QResizeEvent>
#include "utils/iniFile.h"
#include "CXTitleWindow.h"

CXFilesList::CXFilesList(bool aIsSaveDialog) :
    AXBaseWindow()
{
  setupUi(this);

  mIsSaveDialog = aIsSaveDialog;
  if (mIsSaveDialog)
  {
    //setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    //setWindowModality(Qt::ApplicationModal);
  }
  else
  {
    mCloseButton->hide();
    mFileNameEdit->hide();
    mFileNameLabel->hide();
    mSaveButton->hide();
  }

  mProcess = NULL;
  mTurnDialog = NULL;

  mIsShow = false;
  mIsModifier = false;
  mIsCompileNeed = false;

  mModel = new QFileSystemModel(this);
  mModel->setNameFilterDisables(false);
  mModel->setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);

  mFileView->setModel(mModel);
  mRootPath = "cps";//QApplication::applicationDirPath() + "/cps";
  qDebug() << "cps dir=" << mRootPath;
  mRootIndex = mModel->setRootPath(mRootPath);
  mBackIndex = mRootIndex;
  mFileView->setRootIndex(mRootIndex);

  mUpButton->setEnabled(false);
  mOpenButton->setEnabled(false);

  connect(mFileView, SIGNAL(activated(const QModelIndex&)), this,
      SLOT(onItemActivate(const QModelIndex&)));

  connect(mReturnButton, SIGNAL(clicked()), this, SLOT(onReturn()));
  connect(mDownButton, SIGNAL(clicked()), this, SLOT(onDownList()));
  connect(mUpButton, SIGNAL(clicked()), this, SLOT(onUpList()));
  connect(mOpenButton, SIGNAL(clicked()), this, SLOT(onOpen()));
  connect(mCloseButton, SIGNAL(clicked()), this, SLOT(close()));
  connect(mSaveButton, SIGNAL(clicked()), this, SLOT(onSave()));

  connect(mModel, SIGNAL(directoryLoaded(const QString&)), this, SLOT(onDirectoryLoaded()));
  connect(mFileView->selectionModel(),
      SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)), this,
      SLOT(onCurrentChanged(const QModelIndex&, const QModelIndex&)));

  setAcceptDrops(true);
//  setSelectionMode(QAbstractItemView::SingleSelection);
//  setDropIndicatorShown(true);

  registerManager();
}

CXFilesList::~CXFilesList()
{

}

void
CXFilesList::onCreateNewFile()
{
  QFile newFile(QString(mRootPath).append("/noname.cp"));
  newFile.open(QIODevice::WriteOnly);

  newFile.close();

  emit fileOpened(newFile.fileName());
}

void
CXFilesList::setButton(QPushButton* aButton)
{
  mButton = aButton;

  connect(mButton, SIGNAL(clicked()), this, SLOT(onLoadCheckFile()));
}

void
CXFilesList::onTurn()
{
  if (mTurnDialog == NULL)
  {
    mTurnDialog = new CXTurnDialog();
//		mTurnDialog->setAttribute(Qt::WA_DeleteOnClose);
//		mTurnDialog->setWindowFlags(Qt::Dialog);
    mTurnDialog->setWindowModality(Qt::ApplicationModal);

    connect(mTurnDialog, SIGNAL(compileNeeded()), this, SLOT(onCompileFile()));
  }

  mTurnDialog->show();
}

void
CXFilesList::onStatSave()
{
  ;
}

void
CXFilesList::showEvent(QShowEvent* e)
{
  if (!mIsShow)
  {
    mFileName = getConfigAttribute("Common.CpName");
    emit fileOpened(mFileName);
    onProcessFinish(0, QProcess::NormalExit);
    mIsShow = true;
  }

  AXBaseWindow::showEvent(e);
}

void
CXFilesList::onItemActivate(const QModelIndex& aIndex)
{
  if (mModel->isDir(aIndex))
  {
    if (mModel->data(aIndex).toString().compare(QString("..")) == 0)
    {
      QModelIndex index = mFileView->rootIndex();

      if (index.parent().isValid())
      {
        if (index.parent() == mRootIndex){
          mModel->setFilter(
              QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);
        }

        mBackIndex = index.parent();
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
  if (mIsSaveDialog)
  {
    mFileNameEdit->setText(mModel->fileName(aIndex));
    mFileNameEdit->setFocus();
  }

  if (!mIsSaveDialog)
  {
    if (mIsModifier)
    {
      mIsModifier = false;
      mIsCompileNeed = false;
      if (mButton != NULL)
        mButton->setText(
            mButton->text().replace(QRegExp("\n.*"),
                trUtf8("\nЗагрузить")));
    }

    emit fileOpened(mFileName);

    onCompileFile(true);
  }
}

void
CXFilesList::onReturn()
{
  onItemActivate(mRootIndex);//TODO qForm.4: назад сделать через историю
}


void
CXFilesList::onDownList()
{
  QModelIndex curIndex = mFileView->currentIndex();
  if (!curIndex.isValid())
  {
    setCurrentItemToFirst();
    return;
  }

  QModelIndex newIndex = mModel->index(curIndex.row() + 1, curIndex.column(),
      mFileView->rootIndex());

  mFileView->setFocus();

  if (newIndex.isValid())
    mFileView->setCurrentIndex(newIndex);
  else
    mFileView->setCurrentIndex(curIndex);
}

void
CXFilesList::onUpList()
{
  QModelIndex curIndex = mFileView->currentIndex();

  QModelIndex newIndex = mModel->index(curIndex.row() - 1, curIndex.column(),
      mFileView->rootIndex());

  mFileView->setFocus();

  if (newIndex.isValid())
    mFileView->setCurrentIndex(newIndex);
  else
    mFileView->setCurrentIndex(curIndex);
}

void
CXFilesList::onOpen()
{
  QModelIndex curIndex = mFileView->currentIndex();

  if (curIndex.isValid())
    onItemActivate(curIndex);
}

void
CXFilesList::onDirectoryLoaded()
{
  mFileView->setCurrentIndex(QModelIndex());
  /*
   QApplication::processEvents();

   setCurrentItemToFirst();
   */
}

void
CXFilesList::onCurrentChanged(const QModelIndex& current,
    const QModelIndex& previous)
{
  Q_UNUSED(previous)

  mOpenButton->setEnabled(mFileView->currentIndex().isValid());
  mUpButton->setEnabled(
      mModel->index(current.row() - 1, current.column(), mFileView->rootIndex()).isValid());
  mDownButton->setEnabled(
      !current.isValid()
          || mModel->index(current.row() + 1, current.column(),
              mFileView->rootIndex()).isValid());
}

QModelIndex
CXFilesList::setCurrentItemToFirst()
{
  if (!mFileView->currentIndex().isValid()
      || mFileView->selectionModel()->selectedIndexes().isEmpty()
      || !mFileView->hasFocus())
  {
    QModelIndex newIndex = mModel->index(0, 0, mFileView->rootIndex());

    mFileView->setCurrentIndex(newIndex);

    return newIndex;
  }

  return mFileView->currentIndex();
}

void
CXFilesList::onCompileFile(int _clear)
{
  if (mFileName.isEmpty())
    return;

  //не компилировать пока не закочена предыдущая компиляция.
  if (mProcess != NULL)
    return;

  mProcess = new CXProcess(this);

  connect(mProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this,
      SLOT(onProcessFinish(int, QProcess::ExitStatus)));
  connect(mProcess, SIGNAL(error(QProcess::ProcessError)), this,
  SLOT(onProcessError(QProcess::ProcessError)));

  CXMLReader xmlReader(/*QApplication::applicationDirPath() +*/ "jini/compiler0.cfg");
  xmlReader.SetAttribute("compiler/parameters/parameter/Common.CpName"
                            ,"value",mFileName);
  {
    QString d_value, f_value;

    CIniFile configFile(QString(/*QApplication::applicationDirPath() + */"jini/params.ini").toStdString());
    configFile.ReadIniFile();

    d_value        = QString::fromStdString(configFile.GetValue("General/Offset", "value", "0"));
    f_value        = QString::fromStdString(configFile.GetValue("Move/ListFeed", "value", "1000"));

    xmlReader.SetAttribute("compiler/parameters/parameter/Kerfing.D"
        ,"value",d_value);
    xmlReader.SetAttribute("compiler/parameters/parameter/Common.Feed"
        ,"value",f_value);
  }

  if(_clear){
    xmlReader.SetAttribute("compiler/parameters/parameter/RSI.Scale"
                          ,"value","100");
    xmlReader.SetAttribute("compiler/parameters/parameter/RSI.Inverse"
                          ,"value", "0");
    xmlReader.SetAttribute("compiler/parameters/parameter/RSI.RotationAngle"
                          ,"value", "0");
  }
  mProcess->start("cpc.sh " + mFileName);
}

void
CXFilesList::onLoadCheckFile()
{
  if (mIsModifier)
  {
    return;
  }

  if (mIsCompileNeed)
  {
    mIsCompileNeed = false;
    onCompileFile();//здесь поворачивать не надо, так как корректировали программу

    if (mButton != NULL)
      mButton->setText(
          mButton->text().replace(QRegExp("\n.*"), trUtf8("\nЗагрузить")));

    return;
  }

  /**/
  //не загружать пока не закочена компиляция.
  if (mProcess != NULL)
    return;
  if (((CXTitleWindow*)(mManager->getWindow("CXTitleWindow")))->mCPStateLabel->text() != trUtf8("Ручное упр.")){
  	QMessageBox::information(NULL, trUtf8("Сообщение"), trUtf8("Необходимо остановить УП"));
  	return;
  }

  CXProcessingParametersWindow* parametersWindow = new CXProcessingParametersWindow(this);
  parametersWindow->setAttribute(Qt::WA_DeleteOnClose);
  parametersWindow->setWindowFlags(Qt::Dialog);
  parametersWindow->setWindowModality(Qt::ApplicationModal);
  parametersWindow->resize(800, 600);
  parametersWindow->setFileName(getConfigAttribute("Common.OutputCpNameKerf"),
      getConfigAttribute("Common.OutputRunCpName"));
  parametersWindow->show();

//  if (parametersWindow->exec() == QDialog::Accepted)
//  {
//    onAccept();
//  }
}

void
CXFilesList::onTextChanged(bool aIsSaved)
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

    if (mButton != NULL)
      mButton->setText(
          mButton->text().replace(QRegExp("\n.*"), trUtf8("\nПроверить")));
  }
}

void
CXFilesList::onProcessFinish(int aExitCode, QProcess::ExitStatus aExitStatus)
{
  Q_UNUSED(aExitCode)

  if (aExitStatus == QProcess::NormalExit)
  {
    emit fileCreated(getConfigAttribute("Common.OutputCpName"),
        getConfigAttribute("Common.OutputCpNameKerf"));

    if (!mIsShow)
      emit fileManageCreated(getConfigAttribute("Common.OutputCpName"),
          getConfigAttribute("Common.OutputCpNameKerf"));

    QFile compileFile(getConfigAttribute("Common.OutputInfo"));
    compileFile.open(QIODevice::ReadOnly);

    QTextStream in(&compileFile);
    in.setCodec("UTF-8");

    emit compileTextChanged(in.readAll());

    compileFile.close();
  }

  if (mProcess != NULL)
  {
    mProcess->deleteLater();
    mProcess = NULL;
  }
}

void
CXFilesList::onProcessError(QProcess::ProcessError aError)
{
  Q_UNUSED(aError)

  QMessageBox::critical(NULL, trUtf8("Ошибка"),
      qobject_cast<QProcess*>(sender())->errorString());

  mProcess->deleteLater();
  mProcess = NULL;
}

QString
CXFilesList::getConfigAttribute(const QString& aAttributeName)
{
  QFile configFile(/*QApplication::applicationDirPath() +*/ "jini/compiler0.cfg");
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

void
CXFilesList::onSave()
{
  QString rootPath = mModel->filePath(mFileView->rootIndex());
  emit fileSaved(rootPath + QDir::separator() + mFileNameEdit->text());
  close();
}

void
CXFilesList::dropEvent(QDropEvent *ev)
{
  QList<QUrl> urls = ev->mimeData()->urls();
  foreach(QUrl url, urls)
  {
//    qDebug()<<QString("drop:")<<url.toString();
//    qDebug()<<newname;
    QString newname = mModel->filePath(mFileView->rootIndex()) + QDir::separator()
                      + QFileInfo(url.toLocalFile()).fileName();
    QFile::copy(url.toLocalFile(), newname);
  }
}

void
CXFilesList::onAccept()
{
  mIsShow = false;
  onCompileFile();
//  emit fileManageCreated(getConfigAttribute("Common.OutputCpName"),
//                         getConfigAttribute("Common.OutputCpNameKerf"));
}

void CXFilesList::dragEnterEvent(QDragEnterEvent *ev)
{
   ev->accept();
}
