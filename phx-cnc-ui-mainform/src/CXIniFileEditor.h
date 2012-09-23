#ifndef CXINIFILEEDITOR_H
#define CXINIFILEEDITOR_H

#include <QWidget>
#include <QSyntaxHighlighter>

#include "ui_CXIniFileEditor.h"

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

private:
	QString mFileName;
	QSyntaxHighlighter* mHighlighter;
};

#endif // CXINIFILEEDITOR_H
