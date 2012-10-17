#ifndef CXINIFILEEDITOR_H
#define CXINIFILEEDITOR_H

#include <QSyntaxHighlighter>
#include <QProgressBar>

#include "AXBaseWindow.h"

#include "ui_CXIniFileEditor.h"

class CXFtp;

/*!
	Класс окна редактора ini-файлов, со списком файлов, с подсветкой синтаксиса и сохранением изменений.
*/
class CXIniFileEditor : public AXBaseWindow, public Ui::CXIniFileEditor
{
	Q_OBJECT

public:
	//! Конструктор.
	CXIniFileEditor();

	//! Деструктор.
	~CXIniFileEditor();

public slots:
	/*!
		Слот выбора файла из списка на редактирование.

		\param aFileName - имя выбранного файла.
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
