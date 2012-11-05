#ifndef CXLAZERDIRECTIONDIALOG_H
#define CXLAZERDIRECTIONDIALOG_H

#include <QDialog>
#include "ui_CXLazerDirectionDialog.h"

/*!
	����� ������� �������� ���� �������� (����������, �������������).
*/
class CXLazerDirectionDialog : public QDialog, public Ui::CXLazerDirectionDialog
{
	Q_OBJECT

public:
	//! �����������.
	CXLazerDirectionDialog(QWidget *parent = 0);

	//! ����������.
	~CXLazerDirectionDialog();

	//! ��������� ���������.
	QPointF getPosition();

private slots:
	//! ���� ����������� ��������.
	void onAbsolute();

	//! ���� �������������� ��������.
	void onRelative();

	/*!
		���� ��������� ������� �� ����������� ����������.
	*/
	void onButtonClicked();
};

#endif // CXLAZERDIRECTIONDIALOG_H
