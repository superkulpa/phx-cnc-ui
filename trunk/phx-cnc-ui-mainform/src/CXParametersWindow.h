#ifndef CXPARAMETERSWINDOW_H
#define CXPARAMETERSWINDOW_H

#include <QTabWidget>
#include <QProgressBar>
#include <QPushButton>

class CXFtp;

/*!
	Класс для отображения и редактирования параметров.
*/
class CXParametersWindow : public QTabWidget
{
	Q_OBJECT

public:
	CXParametersWindow(QWidget* parent, bool aIsSystem);
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

private slots:
	//! Слот на нажатие кнопки.
	void buttonClicked();

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
	QProgressBar* mProgressBar;
	CXFtp* mFtp;
	bool mIsSystem;

	QList <QPushButton*> mButtons;
};

#endif // CXPARAMETERSWINDOW_H
