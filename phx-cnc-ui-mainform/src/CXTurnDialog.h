#ifndef CXTURNDIALOG_H
#define CXTURNDIALOG_H

#include <QWidget>

#include "ui_CXTurnDialog.h"

/*!
	Класс списка файлов для редактора пути.
*/
class CXTurnDialog : public QWidget, public Ui::CXTurnDialog
{
	Q_OBJECT

public:
	//! Конструктор.
	CXTurnDialog(QWidget* parent = 0);

	//! Деструктор.
	~CXTurnDialog();
};

#endif // CXTURNDIALOG_H
