#ifndef CXTURNDIALOG_H
#define CXTURNDIALOG_H

#include <QWidget>

#include "ui_CXTurnDialog.h"

/*!
	Класс настройки поворота и мастабирования УП.
*/
class CXTurnDialog : public QWidget, public Ui::CXTurnDialog
{
	Q_OBJECT

public:
	//! Конструктор.
	CXTurnDialog(QWidget* parent = 0);

	//! Деструктор.
	~CXTurnDialog();

signals:
	/*!
		Сигнал, информирующий необходимость перекомпиляции УП.
	*/
	void compileNeeded();

private slots:
	/*!
		Слот обработки нажатий на виртуальную клавиатуру.
	*/
	void onButtonClicked();

	/*!
		Слот на запись значения угла поворота.
	*/
	void onWriteRotation();

	/*!
		Слот на расчет выражения в поле редактора поворота.
	*/
	void onCalculateRotation();

	/*!
		Слот на запись значения реверсии по X.
	*/
	void onWriteFlipX();

	/*!
		Слот на запись значения реверсии по Y.
	*/
	void onWriteFlipY();

	/*!
		Слот на запись значения масштаба.
	*/
	void onWriteScale();

private:
	/*!
		Функция сохранения изменений в xml-файл.

		\param aAttributeName - имя атрибута.
		\param aAttributeValue - значение атрибута.
	*/
	void saveAttribute(const QString& aAttributeName, const QString& aAttributeValue);
};

#endif // CXTURNDIALOG_H
