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

	//! Функция установки функциональных кнопок.
	void setButtons(const QList <QPushButton*>& aButtons);

signals:
	/*!
		Сигнал о изменении позиции реза.

		\param aPos - координаты реза.
		\param aIsAbsolute - абсолютное ли смещение.
	*/
	void positionChanged(const QPointF& aPos, bool aIsAbsolute);

private slots:
	//! Слот обработки нажатия на кнопку F9.
	void onButton1Clicked();

	//! Слот обработки нажатия на кнопку F10.
	void onButton2Clicked();

protected:
	bool eventFilter(QObject* obj, QEvent* e);

private:
	QList <QPushButton*> mButtons;
};

#endif // CXLAZERSETTINGS_H
