#ifndef CXLAZERVELOCITYVIEW_H
#define CXLAZERVELOCITYVIEW_H

#include <QWidget>
#include <QPainterPath>

//! Перечисление возможных значения скорости реза.
enum eVelocity
{
	E_Slow,
	E_Normal,
	E_Boost
};

/*!
	Класс настройки скорости перемещения реза.
*/
class CXLazerVelocityView : public QWidget
{
public:
	//! Конструктор.
	CXLazerVelocityView(QWidget* parent = 0);

	//! Деструктор.
	~CXLazerVelocityView();

protected:
	//! Переопределенная фукнция рисования.
	virtual void paintEvent(QPaintEvent* e);

	//! Переопределенная фукнция обработки нажатия кнопки мышки.
	virtual void mousePressEvent(QMouseEvent* e);

	//! Переопределенная фукнция обработки движения мышки.
	virtual void mouseMoveEvent(QMouseEvent* e);

private:
	/*!
		Функция установки скорости по координатам.

		\param aPos - позиция курсора.
	*/
	void updateVelocity(const QPointF& aPos);

private:
	QList <QPainterPath> mPathList;
	QPainterPath mDrawPath;
	eVelocity mVelocity;
};

#endif // CXLAZERVELOCITYVIEW_H
