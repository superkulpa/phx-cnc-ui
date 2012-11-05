#ifndef CXTOUCHBUTTON_H
#define CXTOUCHBUTTON_H

#include <QPushButton>
#include <QTime>

/*!
	Класс кнопки для учета антидребезга.
*/
class CXTouchButton : public QPushButton
{
public:
	CXTouchButton(QWidget* parent);
	CXTouchButton(const QString& text, QWidget* parent);
	~CXTouchButton();

protected:
	virtual void mousePressEvent(QMouseEvent* e);
	virtual void mouseReleaseEvent(QMouseEvent* e);
	virtual void timerEvent(QTimerEvent* e);

private:
	//! Функция получения задержки.
	static int getDelay();

private:
	QTime mTime;
	int mTimer;

	static int mDelay;
};

#endif // CXTOUCHBUTTON_H
