#ifndef CXLAZERVELOCITY_H
#define CXLAZERVELOCITY_H

#include <QWidget>
#include "ui_CXLazerVelocity.h"

/*!
	����� ���� � ����������� �������� ����.
*/
class CXLazerVelocity : public QWidget, public Ui::CXLazerVelocity
{
	Q_OBJECT

public:
	//! �����������.
	CXLazerVelocity(QWidget *parent = 0);

	//! ����������.
	~CXLazerVelocity();
};

#endif // CXLAZERVELOCITY_H
