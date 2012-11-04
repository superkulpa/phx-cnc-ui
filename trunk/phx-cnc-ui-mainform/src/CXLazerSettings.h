#ifndef CXLAZERSETTINGS_H
#define CXLAZERSETTINGS_H

#include "AXBaseWindow.h"

#include <QPushButton>

#include "ui_CXLazerSettings.h"

/*!
	Класс настройки начальной позиции реза.
*/
class CXLazerSettings : public AXBaseWindow, public Ui::CXLazerSettings
{
	Q_OBJECT

public:
	//! Конструктор.
	CXLazerSettings();

	//! Деструктор.
	~CXLazerSettings();

private slots:
	//!
	void onTClick();

	//!
	void onZHClick();
};

#endif // CXLAZERSETTINGS_H
