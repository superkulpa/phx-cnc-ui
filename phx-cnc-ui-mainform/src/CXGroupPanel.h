#ifndef CXGROUPPANEL_H
#define CXGROUPPANEL_H

#include "AXBaseWindow.h"

/*!
	Класс панели для группы с функциональными клавишами F1-F12.
*/
class CXGroupPanel : public AXBaseWindow
{
	Q_OBJECT

public:
	//! Конструктор.
	CXGroupPanel();

	//! Деструктор.
	~CXGroupPanel();
};

#endif // CXGROUPPANEL_H
