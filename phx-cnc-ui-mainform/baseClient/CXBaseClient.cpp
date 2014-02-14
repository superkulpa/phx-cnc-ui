#include "CXBaseClient.h"

#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QFile>

CXBaseClient::CXBaseClient()
{

}

CXBaseClient::~CXBaseClient()
{

}

QString CXBaseClient::connectToDataBase(const QString& aIP, const QString& aDBName, int aPort, const QString& aUser, const QString& aPassword)
{
	if (mDataBase.isOpen()) mDataBase.close();
/*
	mDataBase = QSqlDatabase::addDatabase("QPSQL");
	mDataBase.setHostName(aIP);
	mDataBase.setDatabaseName(aDBName);
	mDataBase.setUserName(aUser);
	mDataBase.setPassword(aPassword);
*/

	mDataBase = QSqlDatabase::addDatabase("QSQLITE");
	mDataBase.setDatabaseName(aDBName);

	bool ok = mDataBase.open();

	if (!ok)
	{
		return mDataBase.lastError().text();
	}

	return QString();
}

KeyValueList CXBaseClient::execute(const QString& aTableName, const QString& aColumns, const QString& aWhere, const QString& aOrder)
{
	KeyValueList values;

	QString queryString = QString("SELECT %1 FROM %2").arg(aColumns).arg(aTableName);

	if (!aWhere.isEmpty()) queryString.append(QString(" WHERE %1").arg(aWhere));
	if (!aOrder.isEmpty()) queryString.append(QString(" ORDER BY %1").arg(aOrder));

	queryString.append(";");

	QSqlQuery query(mDataBase);
	if (query.exec(queryString))
	{
		while (query.next())
		{
			//values.insert(query.value(1).toString(), query.value(0).toString());
			values.append(Pair(query.value(1).toString(), query.value(0).toString()));
		}
	}
//	else query.lastError().text();

	return values;
}

KeyValueMap CXBaseClient::getValues(const QString& aTableName, const QString& aColumns, const QString& aWhere)
{
	KeyValueMap values;

	QString queryString = QString("SELECT %1 FROM %2").arg(aColumns).arg(aTableName);

	if (!aWhere.isEmpty()) queryString.append(QString(" WHERE %1").arg(aWhere));

	queryString.append(";");

	QSqlQuery query(mDataBase);
	if (query.exec(queryString) && query.first())
	{
		QSqlRecord record = query.record();
		for (int i = 0; i < record.count(); i++)
		{
			values.insert(record.fieldName(i), query.value(i).toString());
		}
	}
//	else query.lastError().text();

	return values;
}

KeyValueMap CXBaseClient::getImageData(const QString& aTableName, const QString& aColumns, const QString& aWhere, const QString& aFileName)
{
	KeyValueMap values;

	QString queryString = QString("SELECT %1 FROM %2").arg(aColumns).arg(aTableName);

	if (!aWhere.isEmpty()) queryString.append(QString(" WHERE %1").arg(aWhere));

	queryString.append(";");

	QSqlQuery query(mDataBase);
	if (query.exec(queryString) && query.first())
	{
		QSqlRecord record = query.record();
		for (int i = 0; i < record.count(); i++)
		{
			//бинарные данные картинки должны быть последними.
			if (i == record.count() - 1)
			{
				QFile imageFile(aFileName);
				if (imageFile.open(QIODevice::WriteOnly))
				{
					//QVariant v = query.value(i);
					//QString s = query.value(i).toString();
					QByteArray data = query.value(i).toByteArray();
					imageFile.write(data);
					imageFile.close();
				}
			}
			else values.insert(record.fieldName(i), query.value(i).toString());
		}
	}
	//	else query.lastError().text();

	return values;
}
