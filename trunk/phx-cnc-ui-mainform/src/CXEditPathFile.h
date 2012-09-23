#ifndef CXEDITPATHFILE_H
#define CXEDITPATHFILE_H

#include <QWidget>
#include "ui_CXEditPathFile.h"

/*!
	Класс окна редактора файлов с данными для построения пути реза, подсветкой синтаксиса и сохранением изменений.
*/
class CXEditPathFile : public QWidget, public Ui::CXEditPathFile
{
	Q_OBJECT

public:
	//! Конструктор.
	CXEditPathFile(QWidget* parent = 0);

	//! Деструктор.
	~CXEditPathFile();

public slots:
	/*!
		Слот установкий редактируемого файла.
		\param aFileName - путь с именем файла для редактирования.
	*/
	void openFile(const QString& aFileName);

	//! Слот сохранения изменений в тексте файла.
	void onSave();

	//! Слот сохранения изменений в тексте файла с заданием имя для сохранения.
	void onSaveAs();

signals:
	//! Сигнал на создание нового файла.
	void newFileCreated();

	//! Сигнал на изменение текста.
	void textChanged(bool aIsSaved = false);

private slots:
	//! Слот на изменение позиции курсора.
	void onCursorPositionChange();

private:
	QString mFileName;
};

#endif // CXEDITPATHFILE_H
