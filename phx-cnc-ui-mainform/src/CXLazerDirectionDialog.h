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

private slots:
	//! Слот абсолютного смещение.
	void onAbsolute();

	//! Слот относительного смещения.
	void onRelative();
};

#endif // CXLAZERDIRECTIONDIALOG_H
