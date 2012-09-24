#ifndef CXINIFILEEDITOR_H
#define CXINIFILEEDITOR_H

#include <QWidget>
#include <QSyntaxHighlighter>
#include <QProgressBar>

#include "ui_CXIniFileEditor.h"

class CXFtp;

/*!
	Класс окна редактора ini-файлов, со списком файлов, с подсветкой синтаксиса и сохранением изменений.
*/
class CXIniFileEditor : public QWidget, public Ui::CXIniFileEditor
{
	Q_OBJECT

public:
	//! Конструктор.
	CXIniFileEditor(QWidget* parent = 0);

	//! Деструктор.
	~CXIniFileEditor();

public slots:
	/*!
		Слот выбора файла из списка на редактирование.
	*/
	void onOpenFile(const QString& aFileName);

	//! Слот сохранения изменений в тексте файла.
	void onSave();
	
	//! Функция загрузки данных на/с FTP-сервера.
	void loadFiles(bool aIsUpload);

	//! Слот установки текста в прогресс загрузки.
	void setProgressText(const QString& aText);

	//! Слот, вызываемый по окончанию загрузки.
	void onAllFilesIsLoaded(bool aIsUpload);

private:
	QString mFileName;
	QSyntaxHighlighter* mHighlighter;

	QProgressBar* mProgressBar;
	CXFtp* mFtp;
};

#endif // CXINIFILEEDITOR_H
