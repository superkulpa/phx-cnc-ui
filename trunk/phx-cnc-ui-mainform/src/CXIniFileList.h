#ifndef CXINIFILELIST_H
#define CXINIFILELIST_H

#include <QFileSystemModel>

#include "AXBaseWindow.h"
#include "ui_CXIniFileList.h"

/*!
	Класс списка ini-файлов.
*/
class CXIniFileList : public AXBaseWindow, public Ui::CXIniFileList
{
	Q_OBJECT

public:
	//! Конструктор.
	CXIniFileList();

	//! Деструктор.
	~CXIniFileList();

signals:
	//! Сигнал на открытие файла.
	void fileOpened(const QString& aFileName);

	//! Сигнал на сохранение изменений в файле.
	void fileSaved();

private slots:
	/*!
		Слот выбора файла из списка на редактирование.
	*/
	void onItemActivate(const QModelIndex& aIndex);

private:
	QFileSystemModel* mModel;
};

#endif // CXINIFILELIST_H
