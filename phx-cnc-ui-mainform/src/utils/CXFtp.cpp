#include <iostream>

#include "CXFtp.h"

#include <QMessageBox>
//#include <QApplication>
#include <QTimerEvent>
#include <QDir>
#include "version.h"
#include "utils/CXSettingsXML.h"

#define PROGRESS_MAXIMUM 10000

const QString CXFtp::remoteCatalog = "pub/updates/jini";

CXFtp::CXFtp(QObject* parent) :
    QFtp(parent)
{
  mLoadFile = NULL;
  mWaitTimer = -1;
  mIsUpload = false;
  mProgressMaximum = 0;
  mCurrentProgressValue = 0;

  connect(this, SIGNAL(stateChanged(int)), this, SLOT(onStateChanged(int)));
  connect(this, SIGNAL(commandFinished(int,bool)), this, SLOT(onFtpCommandFinish(int,bool)));
  connect(this, SIGNAL(listInfo(const QUrlInfo&)), this, SLOT(onListInfo(const QUrlInfo&)));

  connect(this, SIGNAL(dataTransferProgress(qint64, qint64)), this,
  SLOT(onDataTransferProgress(qint64, qint64)));
  connect(this, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

CXFtp::~CXFtp()
{

}

void
CXFtp::setConnectData(const QString& aHost, quint16 aPort, const QString& aUser,
    const QString& aPassword)
{
  mHost = aHost.trimmed();
  mPort = aPort;
  mUser = aUser.trimmed();
  mPassword = aPassword.trimmed();
}

void
CXFtp::setLoadFilesData(const QString& aSaveDir, const QString& aRemoteDir)
{
  mRemoteDir = aRemoteDir;
  mSaveDir = aSaveDir;
}

void
CXFtp::onFtpDownload(const QStringList& aFiles)
{
  mIsUpload = false;
  mFileFilters = aFiles;
  VLOG(D4) << LOGS << LOGP(mFileFilters) << LOGN;
  loadFiles();
}

void
CXFtp::onFtpUpload(const QStringList& aFiles)
{
  mIsUpload = true;

  QDir dir(mSaveDir);
  QFileInfoList fileList = dir.entryInfoList(aFiles, QDir::Files);

  QFileInfoList::iterator iter;
  for (iter = fileList.begin(); iter != fileList.end(); ++iter)
  {
    mFilesList.append(CXFtpFileInfo(iter->absoluteFilePath(), iter->size()));
  }
 // VLOG(D4) << LOGS << LOGP(mFilesList) << LOGN;
  loadFiles();
}

void
CXFtp::timerEvent(QTimerEvent* e)
{
  if (e->timerId() == mWaitTimer)
  {
    killTimer(mWaitTimer);
    mWaitTimer = -1;

    switch (currentCommand())
    {
    case QFtp::ConnectToHost:
      {
      onFtpError(trUtf8("Не удалось подключиться к FTP-серверу. Сервер недоступен."));

      break;
    }
    case QFtp::Login:
      {
      onFtpError(trUtf8("Не удалось подключиться к FTP-серверу. Неверная пара логин/пароль."));

      break;
    }
    default:
      {
      break;
    }
    }

    emit
    errorReceived();
//		emit allFilesIsLoaded(mIsUpload);
  }
}

void
CXFtp::onStateChanged(int aState)
{
  if (aState == QFtp::Unconnected)
  {
//		emit allFilesIsLoaded(mIsUpload);
  }
}

void
CXFtp::onFtpCommandFinish(int id, bool aIsError)
{
  Q_UNUSED(id)

  switch (currentCommand())
  {
  case QFtp::ConnectToHost:
    {
    if (aIsError)
      onFtpError(
          trUtf8("Не удалось подключиться к FTP-серверу. Сервер недоступен.\n[%1]").arg(
              errorString()));
    else
    {
      killTimer(mWaitTimer);
      mWaitTimer = -1;

      login(mUser, mPassword);
      VLOG(D4) << LOGS<< LOGP(aIsError) << ",login" <<LOGPqs(mUser) << LOGPqs(mPassword) << LOGN;

      if (error() != QFtp::NoError)
      {
        onFtpError(trUtf8("Не удалось подключиться к FTP-серверу:\n[%1]").arg(errorString()));
        return;
      }
      int timerTimeout = CXSettingsXML::getValue("settings.xml", "ftpTimeout", "5000").toInt();
      mWaitTimer = startTimer(timerTimeout);
    }
    break;
  }
  case QFtp::Login:
    {
    killTimer(mWaitTimer);
    mWaitTimer = -1;

    if (aIsError)
    {
      onFtpError(
          trUtf8("Не удалось подключиться к FTP-серверу. Неверная пара логин/пароль.\n[%1]").arg(
              errorString()));
      break;
    }

    if (!mRemoteDir.isEmpty())
    {
      VLOG(D4) << LOGS << LOGP(aIsError)  << ",cd" << LOGPqs(mRemoteDir) << LOGN;
      cd(mRemoteDir);
      if (error() != QFtp::NoError)
        onFtpError(trUtf8("Не удалось подключиться к FTP-серверу:\n%1").arg(errorString()));
      break;
    }
    break;
  }
  case QFtp::Cd:
    {
    if (aIsError)
    {
      onFtpError(trUtf8("Не удалось выполнить команду CD.\n[%1]").arg(errorString()));
      break;
    }

    if (mIsUpload)
    {
      calculateProgressSize();
      loadNextFile();
    }
    else{
      list();
      VLOG(D4) << LOGS << LOGP(aIsError)  << ",list" << LOGN;
    }
    break;
  }
  case QFtp::List:
  {

    if (aIsError)
    {
      onFtpError(trUtf8("Не удалось выполнить команду LIST.\n[%1]").arg(errorString()));
      break;
    }

    calculateProgressSize();
    loadNextFile();

    break;
  }
    case QFtp::Put:
    //    {
//      QString fileName = mFilesList.first().mFileName;
//      fileName = QFileInfo(fileName).fileName();
//      QString command = QString("chmod 666 %1%2").arg("/home/ftp/pub/updates/jini/").arg(fileName);
//      rawCommand(command);
//    clearCurrentFileData();
//    mFilesList.takeFirst();
//    loadNextFile();
//    break;
//  }
    case QFtp::Get:
    case QFtp::RawCommand:
    {
      VLOG(D4) << LOGS << LOGP(aIsError)  << ",put/get/raw" << LOGN;
      clearCurrentFileData();
      mFilesList.takeFirst();
      loadNextFile();
    break;
  }

  default:
    {
    break;
  }
  }
}

void
CXFtp::onListInfo(const QUrlInfo& aInfo)
{//Фильтры понимают только так
  //     *.ini
  //     techparams.ini
  //     TODO: qForm - допилить фильтры через regexp
  if (aInfo.isFile() && ! mFileFilters.isEmpty()){
    bool bingo = false;
    if(mFileFilters.at(0) == "*.ini"&& (QFileInfo(aInfo.name()).completeSuffix() == "ini") )
      bingo = true;

    if(!bingo && mFileFilters.contains(aInfo.name()))
      bingo = true;
    if(bingo)
    {
      VLOG(D4) << LOGS << LOGPqs(aInfo.name()) << LOGN;
      mFilesList.append(CXFtpFileInfo(aInfo.name(), aInfo.size()));
    }
  }
}

void
CXFtp::onDataTransferProgress(qint64 done, qint64 total)
{
  Q_UNUSED(total)

  mCurrentProgressValue += done;
  emit progressValueChanged(
      mCurrentProgressValue * (qreal(PROGRESS_MAXIMUM) / mProgressMaximum));
}

void
CXFtp::onReadyRead()
{
  if (mLoadFile != NULL)
  {
    mLoadFile->write(readAll());
  }
}

void
CXFtp::loadFiles()
{
  if (state() != QFtp::Unconnected)
  {
    close();
    clearCurrentFileData();

    mFilesList.clear();
  }

  connectToHost(mHost, mPort);

  if (error() != QFtp::NoError)
  {
    onFtpError(trUtf8("Не удалось подключиться к FTP-серверу:\n%1").arg(errorString()));
  }

  mWaitTimer = startTimer(1000);
}

void
CXFtp::calculateProgressSize()
{
  mProgressMaximum = 0;
  QList<CXFtpFileInfo>::iterator iter;
  for (iter = mFilesList.begin(); iter != mFilesList.end(); ++iter)
  {
    mProgressMaximum += iter->mFileSize;
  }
  VLOG(D4) << LOGS<<LOGP(mProgressMaximum) << LOGN;
  emit progressMaximumChanged(PROGRESS_MAXIMUM);
}

void
CXFtp::loadNextFile()
{
  if (mLoadFile == NULL && !mFilesList.isEmpty())
  {
    QString fileName = mFilesList.first().mFileName;

    if (!QDir(mSaveDir).exists())
    {
      QDir().mkpath(mSaveDir);
    }

    if (mIsUpload)
    {
      mLoadFile = new QFile(fileName);
      mLoadFile->open(QIODevice::ReadOnly);

      VLOG(D4) << LOGS<< ", put" <<LOGPqs(QFileInfo(fileName).fileName()) << LOGN;
      put(mLoadFile, QFileInfo(fileName).fileName());
    }
    else
    {
      mLoadFile = new QFile(mSaveDir + QDir::separator() + fileName);

      if (!mLoadFile->open(QIODevice::WriteOnly))
      {
        onFtpError(trUtf8("Не удалось создать файл:\n%1").arg(mLoadFile->fileName()));

        clearCurrentFileData();

        return;
      }

//          if (!mLoadFile->setPermissions(QFile::WriteOwner | QFile::WriteUser | QFile::WriteGroup
//                                        | QFile::ReadOwner | QFile::ReadUser | QFile::ReadGroup))
//            {
//              onFtpError(
//                  trUtf8("Не удалось изменить права доступа файла:\n%1").arg(mLoadFile->fileName()));
//            }
      VLOG(D4) << LOGS<< ", get" <<LOGPqs(fileName) << LOGN;
      get(fileName);
    }

    emit progressTextChanged(fileName);
  }

  if (mFilesList.isEmpty())
  {
//		close();

    emit allFilesIsLoaded(mIsUpload);
  }
}

void
CXFtp::clearCurrentFileData()
{
  if (mLoadFile != NULL)
  {
    mLoadFile->close();
    delete mLoadFile;
    mLoadFile = NULL;
  }
}

void
CXFtp::onFtpError(const QString& aErrorText)
{
  if (mWaitTimer != -1)
  {
    killTimer(mWaitTimer);
    mWaitTimer = -1;
  }

  clearCurrentFileData();
  close();

  emit errorReceived();

  QMessageBox::information(NULL, trUtf8("Ошибка"), aErrorText);
}
