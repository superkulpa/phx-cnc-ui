#include "CXTouchButton.h"

#include <QTimerEvent>

CXTouchButton::CXTouchButton(QWidget* parent) : QPushButton(parent)
{
	mTimer = -1;
}

CXTouchButton::CXTouchButton(const QString& text, QWidget* parent) : QPushButton(text, parent)
{
	mTimer = -1;
}

CXTouchButton::~CXTouchButton()
{

}

void CXTouchButton::mousePressEvent(QMouseEvent* e)
{
	mTimer = startTimer(200);

	if (!isCheckable()) QPushButton::mousePressEvent(e);
}

void CXTouchButton::mouseReleaseEvent(QMouseEvent* e)
{
	if (mTimer == -1) QPushButton::mouseReleaseEvent(e);
	else
	{
		killTimer(mTimer);
		mTimer = -1;

		blockSignals(true);
		QPushButton::mouseReleaseEvent(e);
		blockSignals(false);
	}
}

void CXTouchButton::timerEvent(QTimerEvent* e)
{
	if (e->timerId() == mTimer)
	{
		killTimer(mTimer);
		mTimer = -1;

		if (isCheckable()) setChecked(!isChecked());
	}
}
