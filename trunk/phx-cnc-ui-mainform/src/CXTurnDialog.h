#ifndef CXTURNDIALOG_H
#define CXTURNDIALOG_H

#include <QWidget>

#include "ui_CXTurnDialog.h"

/*!
	����� ������ ������ ��� ��������� ����.
*/
class CXTurnDialog : public QWidget, public Ui::CXTurnDialog
{
	Q_OBJECT

public:
	//! �����������.
	CXTurnDialog(QWidget* parent = 0);

	//! ����������.
	~CXTurnDialog();
};

#endif // CXTURNDIALOG_H
