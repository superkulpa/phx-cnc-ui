#ifndef CXLAZERDIRECTIONWINDOW_H
#define CXLAZERDIRECTIONWINDOW_H

#include "AXBaseWindow.h"

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

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

signals:
	/*!
		Сигнал о изменении позиции реза.

		\param aPos - координаты реза.
		\param aIsAbsolute - абсолютное ли смещение.
	*/
	void positionChanged(const QPointF& aPos, bool aIsAbsolute);

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

	CXTouchButton* mXYButton;
	QLabel* mFLabel;
	QLineEdit* mFEdit;

	CXLazerDirectionView* mLazerDirectionView;
	CXLazerVelocityView* mLazerVelocityView;
	CXLazerVelocity* mLazerVelocity;
};

#endif // CXLAZERDIRECTIONWINDOW_H
