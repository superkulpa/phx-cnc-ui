#ifndef CXEXITDIALOG_H
#define CXEXITDIALOG_H

#include <QDialog>
#include "ui_CXExitDialog.h"

/*!
	����� ������� ������ �� ���������.
*/
class CXExitDialog : public QDialog, public Ui::CXExitDialog
{
	Q_OBJECT

public:
	//! �����������.
	CXExitDialog(QWidget* parent = 0);

	//! ����������.
	~CXExitDialog();

private slots:
	//! ���� ����������.
	void onTurnOff();

	//! ���� ������.
	void onExit();
};

#endif // CXEXITDIALOG_H
