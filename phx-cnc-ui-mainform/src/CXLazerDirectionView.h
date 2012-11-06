#ifndef CXLAZERDIRECTIONVIEW_H
#define CXLAZERDIRECTIONVIEW_H

#include <QWidget>

#include <QPainterPath>

namespace LazerDirectionView
{
	//! Перечисление возможных значений направления реза.
	enum eMoveDirection
	{
		E_Stop = 0,
		E_Top,
		E_TopLeft,
		E_Left,
		E_BottomLeft,
		E_Bottom,
		E_BottomRight,
		E_Right,
		E_TopRight
	};
}

/*!
	Класс настройки направления реза.
*/
class CXLazerDirectionView : public QWidget
{
public:
	//! Конструктор.
	CXLazerDirectionView(QWidget* parent = 0);

	//! Деструктор.
	~CXLazerDirectionView();

	//! Функция установки направления реза.
	void setDirection(LazerDirectionView::eMoveDirection aDirection);

protected:
	//! Переопределенная фукнция рисования.
	virtual void paintEvent(QPaintEvent* e);

	//! Переопределенная функция событий таймера.
	virtual void timerEvent(QTimerEvent* e);

	//! Переопределенная фукнция обработки нажатия кнопки мышки.
	virtual void mousePressEvent(QMouseEvent* e);

	//! Переопределенная фукнция обработки отпускания кнопки мышки.
	virtual void mouseReleaseEvent(QMouseEvent* e);

	//! Переопределенная фукнция обработки движения мышки.
	virtual void mouseMoveEvent(QMouseEvent* e);

private:
	/*!
		Функция установки направления по координатам.

		\param aPos - позиция курсора.
	*/
	void updateDirection(const QPointF& aPos);

	//! Функция получения задержки.
	static int getDelay();

private:
	static int mDelay;
	int mDelayTimer;

	QList <QPainterPath> mPathList;
	QPainterPath mDrawPath;
	LazerDirectionView::eMoveDirection mDirection;
};

#endif // CXLAZERDIRECTIONVIEW_H
