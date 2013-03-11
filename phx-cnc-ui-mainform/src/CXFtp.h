#ifndef CXFTP_H
#define CXFTP_H

#include <QFtp>
#include <QFile>
#include <QStringList>

/*!
	Структура с данными по файлу на FTP-сервере.
*/
struct CXFtpFileInfo
{
public:
	//! Конструктор.
	CXFtpFileInfo() { }

	/*!
		Конструктор

		\param aFileName - имя файла.
		\param aFileSize - размер файла.
	*/
	CXFtpFileInfo(const QString& aFileName, quint64 aFileSize)
	{
		mFileName = aFileName;
		mFileSize = aFileSize;
	}

	QString mFileName;
	quint64 mFileSize;
};

/*!
	Класс по работе с FTP-сервером.
*/
class CXFtp : public QFtp
{
	Q_OBJECT

public:
	//! Конструктор.
	CXFtp(QObject* parent);

	//! Деструктор.
	~CXFtp();

	/*!
		Функция установки необходимых данных для подключения к FTP-серверу.

		\param aHost - хост-адрес FTP-сервера.
		\param aPort - порт.
		\param aUser - логин.
		\param aPassword - пароль.
	*/
	void setConnectData(const QString& aHost, quint16 aPort, const QString& aUser, const QString& aPassword);

	/*!
		Функция установки удаленной и локальной директорий, для загрузки файлов с/на FTP-сервер.

		\param aSaveDir - локальная директория.
		\param aRemoteDir - удаленная директория.
	*/
	void setLoadFilesData(const QString& aSaveDir, const QString& aRemoteDir = QString());

public slots:
	/*!
		Слот загрузки файлов c FTP.
		\param aFiles - фильтр расширений файлов.
	*/
	void onFtpDownload(const QStringList& aFiles = QStringList());

	/*!
		Слот загрузки файлов на FTP.
		\param aFiles - фильтр расширений файлов.
	*/
	void onFtpUpload(const QStringList& aFiles = QStringList());

signals:
	//! Сигнал об изменении максимального значения прогресса загрузки.
	void progressMaximumChanged(int aMax);

	//! Сигнал об изменении текущего значения прогресса загрузки.
	void progressValueChanged(int aMax);

	//! Сигнал об изменении текущего текста прогресса загрузки.
	void progressTextChanged(const QString& aText);

	//! Сигнал о завершении загрузки.
	void allFilesIsLoaded(bool aIsUpload);

	//! Сигнал об ошибке.
	void errorReceived();

protected:
	//! Функция событий таймера.
	void timerEvent(QTimerEvent* e);

private slots:
	/*!
		Слот смены состояния FTP-соединения.

		\param aState - текущее состояние.
	*/
	void onStateChanged(int aState);

	/*!
		Слот завершения команды.

		\param id - идентификатор команды.
		\param aIsError - признак ошибки.
	*/
	void onFtpCommandFinish(int id, bool aIsError);

	/*!
		Слот получения данных о файлах и каталогах на FTP-сервере.

		\param aInfo - данные о файле или каталоге.
	*/
	void onListInfo(const QUrlInfo& aInfo);

	/*!
		Слот прогресса загрузки данных.

		\param done - размер загруженных данных.
		\param total - общий размер.
	*/
	void onDataTransferProgress(qint64 done, qint64 total);

	//! Слот, который срабатывает при появлении блока данных.
	void onReadyRead();

private:
	//! Функция загрузки/скачивания файлов на/с FTP.
	void loadFiles();

	//! Функция расчета максимального значения прогресса.
	void calculateProgressSize();

	//! Функция загрузки следующего файла.
	void loadNextFile();

	//! Функция очистки данных загрузки.
	void clearCurrentFileData();

	/*!
		Функция обработки ошибок.

		\param aErrorText - текст ошибки.
	*/
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

	QStringList mFileFilters;
	QList <CXFtpFileInfo> mFilesList;
};

#endif // CXFTP_H
