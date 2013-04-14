#ifndef CXFILESLIST_H
#define CXFILESLIST_H

#include <QFileSystemModel>

#include "ui_CXFilesList.h"
#include "AXBaseWindow.h"
#include "CXProcess.h"

class CXTurnDialog;

/*!
	Класс списка файлов для редактора пути.
*/
class CXFilesList : public AXBaseWindow, public Ui::CXFilesList
{
	Q_OBJECT

public:
	//! Конструктор.
	CXFilesList(bool aIsSaveDialog = false);

	//! Деструктор.
	~CXFilesList();

public slots:
	//! Слот создания нового файла.
	void onCreateNewFile();

	//! Установка функциональный кнопки.
	void setButton(QPushButton* aButton);

	//! Слот показа диалога поворота и мастабирования пути.
	void onTurn();

	//! Слот сохранения статистики.
	void onStatSave();

signals:
	/*!
		Сигнал на открытие файла пути.
		\param aFileName - имя файла для редактирования.
	*/
	void fileOpened(const QString& aFileName);

	/*!
		Сигнал на открытие пути реза.
		\param aMainFile - файл с основным путем реза.
		\param aMoveFile - файл с полными данными для реза.
	*/
	void fileCreated(const QString& aMainFile, const QString& aMoveFile);

	/*!
		Сигнал на открытие пути реза в управлении.
		\param aMainFile - файл с основным путем реза.
		\param aMoveFile - файл с полными данными для реза.
	*/
	void fileManageCreated(const QString& aMainFile, const QString& aMoveFile);

	/*!
		Сигнал на сохранение файла.
		\param aFileName - имя файла.
	*/
	void fileSaved(const QString& aFileName);

	/*!
		Сигнал об изменении в логе компиляции.
	*/
	void compileTextChanged(const QString& aText);

protected:
	//! Переопределенная функция показа.
	virtual void showEvent(QShowEvent* e);

private slots:
	//! Слот выбора файла из списка.
	void onItemActivate(const QModelIndex&);

	//! Слот выделения следующего файла в списке.
	void onDownList();

	//! Слот выделения предыдущего файла в списке.
	void onUpList();

	//! Слот открытия файла/папки.
	void onOpen();

	//! Слот завершения асинхронного загрузка дерева папки в модель.
	void onDirectoryLoaded();

	//! Слот на изменение текущего элемента.
	void onCurrentChanged(const QModelIndex& current, const QModelIndex& previous);

	/*! Слот установки текущего элемента на первый.

		\return Текущий элемент.
	*/
	QModelIndex setCurrentItemToFirst();

	//! Слот запуска компиляции файла.
	void onCompileFile();

	//! Слот проверки/загрузки файла.
	void onLoadCheckFile();

	//! Слот на изменение текста.
	void onTextChanged(bool aIsSaved);

	//! Слот завершения процесса компиляции файла пути.
	void onProcessFinish(int aExitCode, QProcess::ExitStatus aExitStatus);

	//! Слот на ошибки процесса компиляции файла пути.
	void onProcessError(QProcess::ProcessError aError);

	//! Получение значения заданного параметра в файле настроек.
	QString getConfigAttribute(const QString& aAttributeName);

	//! Слот на сохранение файла.
	void onSave();

private:
	bool mIsShow;
	bool mIsSaveDialog;
	QString mRootPath;
	QString mFileName;
	QFileSystemModel* mModel;
	QModelIndex mRootIndex;
	QPushButton* mButton;

	CXProcess* mProcess;
	CXTurnDialog* mTurnDialog;

	bool mIsModifier;
	bool mIsCompileNeed;
};

#endif // CXFILESLIST_H
