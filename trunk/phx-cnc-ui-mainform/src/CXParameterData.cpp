#include "CXParameterData.h"

#include "utils/iniFile.h"

CXParameterData::CXParameterData()
{
  mMin = 0;
  mMax = 10000;
  mValue = 0;
  isModified = false;
}

CXParameterData::~CXParameterData()
{
}

void
CXParameterData::setValue(int aValue)
{
  isModified = (mValue != aValue);
  mValue = aValue;
}

int
CXParameterData::getValue()
{
  if (mValue < mMin)
    return mMin;
  if (mValue > mMax)
    return mMax;

  return mValue;
}

void
CXParameterData::save()
{
  if(isModified){
    CIniFile iniFile(mConfigFileName.toStdString());
    iniFile.ReadIniFile();

    iniFile.SetValue(mConfigGroup.toStdString(), "value", QString::number(mValue).toStdString());
    iniFile.WriteIniFile();
  }
  isModified = false;
}

/**/

CXGroupData::CXGroupData(const QString& _mName)
  :mName(_mName)
{
  mIsVisible = true;
}

CXGroupData::~CXGroupData()
{
  ;
}
