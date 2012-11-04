#ifndef CXEXITDIALOG_H
#define CXEXITDIALOG_H

#include <QDialog>
#include "ui_CXExitDialog.h"

/*!
	Класс диалога выхода из программы.
*/
class CXExitDialog : public QDialog, public Ui::CXExitDialog
{
	Q_OBJECT

public:
	//! Конструктор.
	CXExitDialog(QWidget* parent = 0);

	//! Деструктор.
	~CXExitDialog();

private slots:
	//! Слот выключения.
	void onTurnOff();

	//! Слот выхода.
	void onExit();
};

#endif // CXEXITDIALOG_H
