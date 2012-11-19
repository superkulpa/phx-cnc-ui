#include "CXLazerSettings.h"

#include <QRegExpValidator>

CXLazerSettings::CXLazerSettings() : AXBaseWindow()
{
	setupUi(this);

	mLazerVelocity->setMode(E_SingleMode);
	mLazerVelocity->setTexts(QList<QString>() << "" << trUtf8("стоп\n-\nавто") << "");

	connect(mTButton, SIGNAL(clicked()), this, SLOT(onTClick()));
	connect(mZHButton, SIGNAL(clicked()), this, SLOT(onZHClick()));

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
