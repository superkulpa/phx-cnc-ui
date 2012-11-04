#ifndef CXLAZERDIRECTIONWINDOW_H
#define CXLAZERDIRECTIONWINDOW_H

#include "AXBaseWindow.h"

#include <QPushButton>
#include <QLineEdit>

class CXLazerDirectionView;
class CXLazerVelocityView;
class CXLazerVelocity;
class CXTouchButton;

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

	//! Слот обработки клика по X и Y.
	void onXYClick();

private:
	CXTouchButton* mForwardButton;
	CXTouchButton* mBackwardButton;
	CXTouchButton* mSearchButton;
	CXTouchButton* mStopButton;

	QLineEdit* mXEdit;
	QLineEdit* mYEdit;
	QLineEdit* mFEdit;

	CXLazerDirectionView* mLazerDirectionView;
	CXLazerVelocityView* mLazerVelocityView;
	CXLazerVelocity* mLazerVelocity;
};

#endif // CXLAZERDIRECTIONWINDOW_H
