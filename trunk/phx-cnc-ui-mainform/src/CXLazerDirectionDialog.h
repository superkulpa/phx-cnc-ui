#ifndef CXLAZERDIRECTIONDIALOG_H
#define CXLAZERDIRECTIONDIALOG_H

#include <QDialog>
#include "ui_CXLazerDirectionDialog.h"

/*!
	Класс диалога указания типа смещения (абсолютное, относительное).
*/
class CXLazerDirectionDialog : public QDialog, public Ui::CXLazerDirectionDialog
{
	Q_OBJECT

public:
	//! Конструктор.
	CXLazerDirectionDialog(QWidget *parent = 0);

	//! Деструктор.
	~CXLazerDirectionDialog();

	//! Получение координат.
	QPointF getPosition();

private slots:
	//! Слот абсолютного смещение.
	void onAbsolute();

	//! Слот относительного смещения.
	void onRelative();

	/*!
		Слот обработки нажатий на виртуальную клавиатуру.
	*/
	void onButtonClicked();
};

#endif // CXLAZERDIRECTIONDIALOG_H
