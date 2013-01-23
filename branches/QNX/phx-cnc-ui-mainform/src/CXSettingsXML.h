#ifndef CXSETTINGSXML_H
#define CXSETTINGSXML_H

#include <QString>

/*!
	Класс для работы с настройками в xml-файле.
*/
class CXSettingsXML
{
public:
	static QString getValue(const QString& aFileName, const QString& aName);
};

#endif // CXSETTINGSXML_H
