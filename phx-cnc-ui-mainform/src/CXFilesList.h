#ifndef CXFILESLIST_H
#define CXFILESLIST_H

#include <QWidget>
#include <QFileSystemModel>
#include <QProcess>

#include "ui_CXFilesList.h"

/*!
	Класс списка файлов для редактора пути.
*/
class CXFilesList : public QWidget, public Ui::CXFilesList
{
	Q_OBJECT

public:
	//! Конструктор.
	CXFilesList(QWidget* parent = 0);

	//! Деструктор.
	~CXFilesList();

public slots:
	//! Слот создания нового файла.
	void onCreateNewFile();

	//! Установка функциональный кнопки.
	void setButton(QPushButton* aButton);

	//! 
	void onTurn();

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

private:
	QString mRootPath;
	QString mFileName;
	QFileSystemModel* mModel;
	QModelIndex mRootIndex;
	QPushButton* mButton;
	bool mIsModifier;
	bool mIsCompileNeed;
};

#endif // CXFILESLIST_H
