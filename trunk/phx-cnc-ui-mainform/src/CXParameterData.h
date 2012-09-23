#ifndef CXPARAMETERDATA_H
#define CXPARAMETERDATA_H

#include <QString>
#include <QList>

/*!
	����� ��� ����� ����������.
*/
class CXParameterData
{
public:
	CXParameterData();
	~CXParameterData();

	//! ������� ��������� �������� ���������.
	void setValue(int aValue);

	//! ������� ��������� �������� ���������.
	int getValue();

	//! ������� ���������� ������.
	void save();

public:
	//! ��� ����������������� ����� ���������.
	QString mConfigFileName;

	//! ��� ������ ���������.
	QString mConfigGroup;

	//! ��� ���������.
	QString mName;

	//! ������ ����� ���������.
	QList <int> mGroups;

	//! ����������� ������� �������� ���������.
	int mMin;

	//! ������������ ������� �������� ���������.
	int mMax;

private:
	int mValue;
};

/*!
	����� ��� ����� ������.
*/
class CXGroupData
{
public:
	CXGroupData();
	~CXGroupData();

public:
	//! ��� ������.
	QString mName;

	//! ��������� ������ � �������� �����.
	bool mIsVisible;
};

#endif // CXPARAMETERDATA_H
