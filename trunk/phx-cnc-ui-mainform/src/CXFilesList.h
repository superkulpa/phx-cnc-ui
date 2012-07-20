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
	void onDirectoryLoaded(const QString& path);

	//! Слот на изменение текущего выделенного элемента.
	void onCurrentChanged(const QModelIndex& current, const QModelIndex& previous);

	//! Слот завершения процесса компиляции файла пути.
	void onProcessFinish(int aExitCode, QProcess::ExitStatus aExitStatus);

	//! Слот на ошибки процесса компиляции файла пути.
	void onProcessError(QProcess::ProcessError aError);

private:
	QFileSystemModel* mModel;
	QModelIndex mRootIndex;
};

#endif // CXFILESLIST_H
