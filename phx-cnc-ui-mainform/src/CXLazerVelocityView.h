#ifndef CXLAZERVELOCITYVIEW_H
#define CXLAZERVELOCITYVIEW_H

#include <QWidget>
#include <QPainterPath>

//! Перечень режимов.
enum eVelocityMode
{
	E_Accumulate,
	E_SingleMode
};

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
	Q_OBJECT

public:
	//! Конструктор.
	CXLazerVelocityView(QWidget* parent = 0);

	//! Деструктор.
	~CXLazerVelocityView();

	//! Функция установки режима отображения.
	void setMode(eVelocityMode aMode);

	//! Функция установки текста описания делений.
	void setTexts(const QList <QString>& aTexts);

	//! Функция установки текущего значения скорости.
	void setVelocity(eVelocity aVelocity);

signals:
	//! Сигнал на изменение скорости.
	void velocityChanged(eVelocity aVelocity);

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
		Функция установки скорости по координатам.

		\param aPos - позиция курсора.
	*/
	void updateVelocity(const QPointF& aPos);

	//! Функция установки текущего значения скорости.
	void setCurrentVelocity(eVelocity aVelocity);

private:
	static int mDelay;
	int mDelayTimer;

	QList <QRectF> mPathList;
	QList <QString> mTexts;
	QPainterPath mDrawPath;
	eVelocityMode mMode;
	eVelocity mVelocity;
};

#endif // CXLAZERVELOCITYVIEW_H
