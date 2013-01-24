#include "CXTouchButton.h"

#include <QApplication>
#include <QTimerEvent>
#include <QMouseEvent>
#include <QStyleOption>
#include <QPainter>

#include "CXSettingsXML.h"

int CXTouchButton::mDelay = 0;

CXTouchButton::CXTouchButton(QWidget* parent) : QPushButton(parent)
{
	mTimer = -1;
	setFocusPolicy(Qt::NoFocus);

	if (mDelay == 0) mDelay = CXSettingsXML::getDelay("settings.xml", "buttonDelay");
}

CXTouchButton::CXTouchButton(const QString& text, QWidget* parent) : QPushButton(text, parent)
{
	mTimer = -1;
	setFocusPolicy(Qt::NoFocus);

	if (mDelay == 0) mDelay = CXSettingsXML::getDelay("settings.xml", "buttonDelay");
}

CXTouchButton::~CXTouchButton()
{

}

void CXTouchButton::paintEvent(QPaintEvent* e)
{
	QPushButton::paintEvent(e);
/*
	QStyleOption styleOption;
	styleOption.init(this);
	QPainter painter(this);
	style()->drawPrimitive(QStyle::PE_Widget, &styleOption, &painter, this);
*/
}

void CXTouchButton::mousePressEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton)
	{
		mTimer = startTimer(mDelay);

		if (!isCheckable()) QPushButton::mousePressEvent(e);
	}
}

void CXTouchButton::mouseReleaseEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton)
	{
		e->pos();
		e->buttons();
		e->modifiers();

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
	else QPushButton::mouseReleaseEvent(e);
}

void CXTouchButton::timerEvent(QTimerEvent* e)
{
	if (e->timerId() == mTimer)
	{
		killTimer(mTimer);
		mTimer = -1;

		if (isCheckable())
		{
			setChecked(!isChecked());
			emit clicked(isChecked());
		}
		else
		{
			QMouseEvent* e = new QMouseEvent(QEvent::MouseButtonRelease, QPoint(1, 1), Qt::LeftButton, Qt::NoButton, Qt::NoModifier);
			QApplication::postEvent(this, e);
		}
	}
}
