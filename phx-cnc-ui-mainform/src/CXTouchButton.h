#ifndef CXTOUCHBUTTON_H
#define CXTOUCHBUTTON_H

#include <QPushButton>
#include <QTime>

/*!
	����� ������ ��� ����� ������������.
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
	QTime mTime;
	int mTimer;
};

#endif // CXTOUCHBUTTON_H
