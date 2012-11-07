#ifndef CXLAZERVELOCITY_H
#define CXLAZERVELOCITY_H

#include <QWidget>
#include "ui_CXLazerVelocity.h"

/*!
	Класс окна с настройками скорости реза.
*/
class CXLazerVelocity : public QWidget, public Ui::CXLazerVelocity
{
	Q_OBJECT

public:
	//! Конструктор.
	CXLazerVelocity(QWidget *parent = 0);

	//! Деструктор.
	~CXLazerVelocity();
};

#endif // CXLAZERVELOCITY_H
