#ifndef CXPARAMDATA_H
#define CXPARAMDATA_H

#include <QStringList>
#include <QPair>

#include "iniFile.h"

typedef QList<QPair<QString, QString> > PairsList;

struct SXDataXml
{
public:
	SXDataXml(const QString& aName, const QString& aDescr, int aColumn)
	{
		mName = aName;
		mDescr = aDescr;
		mColumn = aColumn;
	}
	
	QString mName;
	QString mDescr;
	int mColumn;
};

class CXParamData
{
public:
	/*!
		������� �������� ini-�����.
		\param aFileName - ��� ����� � �����.
	*/
	static void open(const QString& aFileName);

	/*!
		������� �������� ini-����� � ������������ ��������.
		\param aIsWrite - ���������� �� ��������� �� ����.
	*/
	static void close(bool aIsWrite = true);

	/*!
		������� ��������� ������ ������ � �� ��������.
		\param aType - ��� ���� (������������� ��������� Keys � ����� ������).
	*/
	static QMap<QString, QString> getKeys(const QString& aType);

	/*!
		������� ��������� ������ �������� � �������� ���������.
		\param aType - ��� ����.
	*/
	static QMap<QString, QString> getValues(const QString& aType);

	/*!
	������� ��������� ������ �������� � �������� ���������.
	\param aFileName - ��� xml-�����.
		\param aType - ��� ����.
	*/
	static QList<SXDataXml> getCaptions(const QString& aFileName, const QString& aType);

	/*!
		������� ��������� ������ �������� ������ ��������.
		\param aFileName - ��� xml-�����.
		\param aType - ��� ����.
		\return ������ �������� ������ ��������.
	*/
	static QList <QString> getImages(const QString& aFileName, const QString& aType);

	/*!
		������� ��������� ������ ��������������� ������.
		\param aFileName - ��� xml-�����.
		\param aType - ��� ����.
		\return ������ ��������������� ������.
	*/
	static QMap<QString, QString> getFixedKeys(const QString& aFileName, const QString& aType);

	/*!
		������� �������� ������ ������/����� �� ini-�����.
		\param aKeys - ������ ��������� ������/����� (������������� ��������� Keys � ����� ������).
	*/
	static void deleteKeys(const QStringList& aKeys);

	/*!
		������� ��������� ������ ��������� ������ ��� ������.
		\param aGroup - ��� ������, ��� ������� ��������������� ������ ������ (������������� ��������� Keys � ����� ������).
		\param aKeys - ������ ����������� ������.
	*/
	static void setKeysArray(const QString& aGroup, const QStringList& aKeys);
	
	/*!
		������� ��������� ������ ��������� ������ ��� ������.
		\param aGroup - ��� ������, ��� ������� ��������������� ������ ������ (������������� ��������� Keys � ����� ������).
		\return ������ ��������� ������.
	*/
	static QStringList getKeysArray(const QString& aGroup);

	/*!
		������� ��������� �������� ������.
		\param aGroup - ��� ������, ��� ������� ��������������� ��������.
		\param aValues - ������ ��� (���, ��������).
	*/
	static void setValues(const QString& aGroup, const PairsList& aValues);

private:
	static CIniFile gIniFile;
};

#endif // CXPARAMDATA_H
