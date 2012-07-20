#ifndef CXINIFILEEDITOR_H
#define CXINIFILEEDITOR_H

#include <QWidget>
#include <QFileSystemModel>
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

private slots:
	/*!
		Слот выбора файла из списка на редактирование.
	*/
	void onItemActivate(const QModelIndex&);

	//! Слот сохранения изменений в тексте файла.
	void onSave();

private:
	QString mFileName;
	QFileSystemModel* mModel;
	QSyntaxHighlighter* mHighlighter;
};

#endif // CXINIFILEEDITOR_H
