#ifndef CXFTP_H
#define CXFTP_H

#include <QFtp>
#include <QFile>

/*!
*/
struct CXFtpFileInfo
{
public:
	CXFtpFileInfo() { }

	CXFtpFileInfo(const QString& aFileName, quint64 aFileSize)
	{
		mFileName = aFileName;
		mFileSize = aFileSize;
	}

	QString mFileName;
	quint64 mFileSize;
};

/*!
	Класс
*/
class CXFtp : public QFtp
{
	Q_OBJECT

public:
	CXFtp(QObject* parent);
	~CXFtp();

	//!
	void setConnectData(const QString& aHost, quint16 aPort, const QString& aUser, const QString& aPassword);

	//!
	void setLoadFilesData(const QString& aSaveDir, const QString& aRemoteDir = QString());

public slots:
	//! Слот загрузки файлов c FTP.
	void onFtpDownload();

	//! Слот загрузки файлов на FTP.
	void onFtpUpload();

signals:
	//!
	void progressMaximumChanged(int aMax);

	//!
	void progressValueChanged(int aMax);

	//!
	void progressTextChanged(const QString& aText);

	//!
	void allFilesIsLoaded(bool aIsUpload);

protected:
	//!
	void timerEvent(QTimerEvent* e);

private slots:
	//!
	void onStateChanged(int aState);

	//!
	void onFtpCommandFinish(int id, bool aIsError);

	//!
	void onListInfo(const QUrlInfo& aInfo);

	//!
	void onDataTransferProgress(qint64 done, qint64 total);

	//!
	void onReadyRead();

private:
	//! Функция загрузки/скачивания файлов на/с FTP.
	void loadFiles();

	//!
	void calculateProgressSize();

	//!
	void loadNextFile();

	//!
	void clearCurrentFileData();

	//!
	void onFtpError(const QString& aErrorText);

private:
	int mWaitTimer;
	bool mIsUpload;
	quint64 mProgressMaximum;
	quint64 mCurrentProgressValue;

	QString mHost;
	quint16 mPort;

	QString mUser;
	QString mPassword;

	QString mRemoteDir;
	QString mSaveDir;

	QFile* mLoadFile;

	QList <CXFtpFileInfo> mFilesList;
};

#endif // CXFTP_H
