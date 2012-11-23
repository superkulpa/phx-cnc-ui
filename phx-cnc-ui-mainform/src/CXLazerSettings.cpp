#include "CXLazerSettings.h"

#include <QRegExpValidator>

CXLazerSettings::CXLazerSettings() : AXBaseWindow()
{
	setupUi(this);

	mLazerVelocity->setMode(E_SingleMode);
	mLazerVelocity->setTexts(QList<QString>() << "" << trUtf8("стоп\n-\nавто") << "");

	mStopButton->hide();

	connect(mTButton, SIGNAL(clicked()), this, SLOT(onTClick()));
	connect(mZHButton, SIGNAL(clicked()), this, SLOT(onZHClick()));

	connect(mPushingButton, SIGNAL(clicked()), this, SLOT(onStart()));
	connect(mIncutButton, SIGNAL(clicked()), this, SLOT(onStart()));
	connect(mStopButton, SIGNAL(clicked()), this, SLOT(onStop()));

	registerManager();
}

CXLazerSettings::~CXLazerSettings()
{

}

void CXLazerSettings::onTClick()
{
	QList<QAbstractButton*> list = mNuberButtonGroup->buttons();

	bool isCheck = !(mNuberButtonGroup->checkedButton() != NULL);

	for (int i = 0; i < list.count(); ++i)
	{
		list.at(i)->setChecked(isCheck);
	}
}

void CXLazerSettings::onZHClick()
{
	QList<QAbstractButton*> list = mCheckButtonGroup->buttons();

	bool isCheck = !(mCheckButtonGroup->checkedButton() != NULL);

	for (int i = 0; i < list.count(); ++i)
	{
		list.at(i)->setChecked(isCheck);
	}
}

void CXLazerSettings::onStart()
{
	if (sender() == mPushingButton)
	{
		;
	}

	if (sender() == mIncutButton)
	{
		;
	}

	mPushingButton->hide();
	mIncutButton->hide();
	mStopButton->show();
}

void CXLazerSettings::onStop()
{
	mStopButton->hide();
	mPushingButton->show();
	mIncutButton->show();
}
