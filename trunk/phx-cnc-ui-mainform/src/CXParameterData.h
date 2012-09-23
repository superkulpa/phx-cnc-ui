#ifndef CXPARAMETERDATA_H
#define CXPARAMETERDATA_H

#include <QString>
#include <QList>

/*!
	Класс для полей параметров.
*/
class CXParameterData
{
public:
	CXParameterData();
	~CXParameterData();

	//! Функция установки значения параметра.
	void setValue(int aValue);

	//! Функция получения значения параметра.
	int getValue();

	//! Функция сохранения данных.
	void save();

public:
	//! Имя конфигурационного файла параметра.
	QString mConfigFileName;

	//! Имя группы параметра.
	QString mConfigGroup;

	//! Имя параметра.
	QString mName;

	//! Номера групп параметра.
	QList <int> mGroups;

	//! Минимальная граница значений параметра.
	int mMin;

	//! Максимальная граница значений параметра.
	int mMax;

private:
	int mValue;
};

/*!
	Класс для полей группы.
*/
class CXGroupData
{
public:
	CXGroupData();
	~CXGroupData();

public:
	//! Имя группы.
	QString mName;

	//! Видимость группы в основном менюю.
	bool mIsVisible;
};

#endif // CXPARAMETERDATA_H
