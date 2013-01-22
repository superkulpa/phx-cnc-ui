#ifndef CXPARAMETERSWINDOW_H
#define CXPARAMETERSWINDOW_H

#include "AXBaseWindow.h"

#include <QTabWidget>
#include <QProgressBar>
#include <QPushButton>

class CXFtp;

/*!
	Класс для отображения и редактирования параметров.
*/
class CXParametersWindow : public AXBaseWindow
{
	Q_OBJECT

public:
	CXParametersWindow(bool aIsSystem);
	~CXParametersWindow();

	//! Функция установки списка кнопок, которым будут назначены имена.
	void setButtons(const QList <QPushButton*>& aButtons);

public slots:
	//! Слот загрузки файлов с данным по FTP.
	void loadParametersFromFtp();

	//! Слот загрузки параметров в форму.
	void loadParameters();

	//! Слот сохранение изменений параметров.
	void saveParameters();

	//! Слот создания вьюверов параметров.
	void makeTabs(bool aIsSystem);

	//! Слот установки текста в прогресс загрузки.
	void setProgressText(const QString& aText);

	//! Слот, вызываемый по окончанию загрузки.
	void onAllFilesIsLoaded(bool aIsUpload);

	//! Слот показа настроек.
	void showSettings();

private slots:
	//! Слот на нажатие кнопки.
	void buttonClicked();

	//! Слот получения команды от ядра.
	void onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue);

private:
	//! Функция загрузки данных на/с FTP-сервера.
	void loadFiles(bool aIsUpload);

	//! Функция очистки данных.
	void clearData();

	//! Функция очистки вьюверов.
	void clearTables();

	//! Функция обновления названия кнопок.
	void updateButtonsText();

private:
	QTabWidget* mTabWidget;
	QProgressBar* mProgressBar;
	CXFtp* mFtp;
	bool mIsSystem;

	QList <QPushButton*> mButtons;
};

#endif // CXPARAMETERSWINDOW_H
