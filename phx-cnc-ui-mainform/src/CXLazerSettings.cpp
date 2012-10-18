#include "CXLazerSettings.h"

#include <QRegExpValidator>

CXLazerSettings::CXLazerSettings() : AXBaseWindow()
{
	setObjectName("CXLazerSettings");
/**/
	setupUi(this);

	mXEdit->setValidator(new QRegExpValidator(QRegExp("\\d*\\.?\\d*")));
	mYEdit->setValidator(new QRegExpValidator(QRegExp("\\d*\\.?\\d*")));

	mXEdit->installEventFilter(this);
	mYEdit->installEventFilter(this);
	mVelocityEdit->installEventFilter(this);
	mBoostEdit->installEventFilter(this);
}

CXLazerSettings::~CXLazerSettings()
{

}

void CXLazerSettings::setButtons(const QList <QPushButton*>& aButtons)
{
	mButtons = aButtons;

	if (mButtons.count() >= 2)
	{
		connect(mButtons.at(0), SIGNAL(clicked()), this, SLOT(onButton1Clicked()));
		connect(mButtons.at(1), SIGNAL(clicked()), this, SLOT(onButton2Clicked()));
	}
}

void CXLazerSettings::onButton1Clicked()
{
	QWidget* widget = focusWidget();

	if (widget == mXEdit || widget == mYEdit)
	{
		emit positionChanged(QPointF(mXEdit->text().toFloat(), mYEdit->text().toFloat()), false);
	}
	else if (widget == mVelocityEdit || widget == mBoostEdit)
	{
		;
	}
}

void CXLazerSettings::onButton2Clicked()
{
	QWidget* widget = focusWidget();

	if (widget == mXEdit || widget == mYEdit)
	{
		emit positionChanged(QPointF(mXEdit->text().toFloat(), mYEdit->text().toFloat()), true);
	}
	else if (widget == mVelocityEdit || widget == mBoostEdit)
	{
		;
	}
}

bool CXLazerSettings::eventFilter(QObject* obj, QEvent* e)
{
	if (e->type() == QEvent::FocusIn || e->type() == QEvent::FocusOut)
	{
		if (mButtons.count() < 2) return false;

		QWidget* widget = focusWidget();
		QString text1, text2;

		if (widget == mXEdit || widget == mYEdit)
		{
			text1 = trUtf8("\nОтносит.");
			text2 = trUtf8("\nАбсолютное");
		}
		else if (widget == mVelocityEdit || widget == mBoostEdit)
		{
			text1 = trUtf8("\n");
			text2 = trUtf8("\nПрименить");
		}
		else
		{
			text1 = trUtf8("\n");
			text2 = trUtf8("\n");
		}

		QPushButton* curButton = mButtons.at(0);
		QString curText = curButton->text();

		curButton->setText(curText.replace(QRegExp("\n.*"), text1));

		curButton = mButtons.at(1);
		curText = curButton->text();

		curButton->setText(curText.replace(QRegExp("\n.*"), text2));
	}

	return false;
}
