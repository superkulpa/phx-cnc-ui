#ifndef CXLAZERDIRECTIONWINDOW_H
#define CXLAZERDIRECTIONWINDOW_H

#include "AXBaseWindow.h"

#include <QPushButton>

class CXLazerDirectionView;
class CXLazerVelocityView;
class CXLazerVelocity;

/*!
	Класс настройки направления и скорости реза с функциональными кнопками.
*/
class CXLazerDirectionWindow : public AXBaseWindow
{
	Q_OBJECT

public:
	//! Конструктор.
	CXLazerDirectionWindow();

	//! Деструктор.
	~CXLazerDirectionWindow();

private slots:
	//! Запуск процесса.
	void onStart();

	//! Остановка процесса.
	void onStop();

private:
	QPushButton* mForwardButton;
	QPushButton* mBackwardButton;
	QPushButton* mSearchButton;
	QPushButton* mStopButton;

	CXLazerDirectionView* mLazerDirectionView;
	CXLazerVelocityView* mLazerVelocityView;
	CXLazerVelocity* mLazerVelocity;
};

#endif // CXLAZERDIRECTIONWINDOW_H
