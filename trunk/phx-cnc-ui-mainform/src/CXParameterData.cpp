#include "CXParameterData.h"

#include <QStringList>
#include "iniFile.h"

CXParameterData::CXParameterData()
{
	mMin = 0;
	mMax = 10000;
	mValue = 0;
}

CXParameterData::~CXParameterData()
{
}

void CXParameterData::setValue(int aValue)
{
	mValue = aValue;
}

int CXParameterData::getValue()
{
	if (mValue < mMin) return mMin;
	if (mValue > mMax) return mMax;

	return mValue;
}

void CXParameterData::save()
{
/*
	QStringList groups = mConfigGroup.split("/");

	QSettings settings(mConfigFileName, QSettings::IniFormat);
	settings.setIniCodec("UTF-8");

	for (int i = 0; i < groups.count(); ++i)
	{
		settings.beginGroup(groups.at(i));
	}

	settings.setValue(mName, mValue);
/**/
	CIniFile iniFile(mConfigFileName.toStdString());
	iniFile.ReadIniFile();

	iniFile.SetValue(mConfigGroup.toStdString(), "value", QString::number(mValue).toStdString());
	iniFile.WriteIniFile();
}

/**/

CXGroupData::CXGroupData()
{
	mIsVisible = false;
}

CXGroupData::~CXGroupData()
{
	;
}
