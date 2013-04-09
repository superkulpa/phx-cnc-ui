#ifndef CXLAZERDIRECTIONWINDOW_H
#define CXLAZERDIRECTIONWINDOW_H

#include "AXBaseWindow.h"

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

#include "CXLazerDirectionView.h"
#include "CXLazerVelocityView.h"

class CXTouchButton;
class CXUtilsWindow;

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

public slots:
	//! Слот показа утилит.
	void onUtils();

	//! Слот сброса координат.
	void onResetCoordinates();

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

	//! Слот на изменение направления.
	void onDirectionChange(LazerDirectionView::eMoveDirection aDirection);

	//! Слот на изменение скорости.
	void onVelocityChange(eVelocity aVelocity);

	//! Слот увеличения скорости.
	void onUpSpeed();

	//! Слот уменьшения скорости.
	void onDownSpeed();

	//! Изменение режима работы
	void onModeChange();

	//! Слот получения команды от ядра.
	void onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue);

private:
	void StopCP();
	void StartCP();

private:
	bool mIsRunning;
	CXTouchButton* mForwardButton;
	CXTouchButton* mBackwardButton;
	CXTouchButton* mSearchButton;
	CXTouchButton* mStopButton;

	CXTouchButton* mXYButton;
	QLineEdit* mXEdit;
	QLineEdit* mYEdit;
	QLabel* mFLabel;
	QLineEdit* mFEdit;

	CXTouchButton* mCycleButton;
	CXTouchButton* mStepButton;
	CXTouchButton* mReservButton;

	CXLazerDirectionView* mLazerDirectionView;
	CXLazerVelocityView* mLazerVelocityView;
	QLabel* mCurrentFrameLabel;

	CXUtilsWindow* mUtils;
};

#endif // CXLAZERDIRECTIONWINDOW_H
