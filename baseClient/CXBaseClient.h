#ifndef CXBASECLIENT_H
#define CXBASECLIENT_H

#include <QMap>
#include <QPair>
#include <QString>
#include <QStringList>
#include <QSqlDatabase>

typedef QMap <QString, QString> KeyValueMap;
typedef QPair<QString, QString> Pair;
typedef QList<Pair> KeyValueList;

class CXBaseClient
{
public:
	CXBaseClient();
	~CXBaseClient();

	QString connectToDataBase(const QString& aIP, const QString& aDBName, int aPort, const QString& aUser, const QString& aPassword);
	KeyValueList execute(const QString& aTableName, const QString& aColumns, const QString& aWhere, const QString& aOrder = QString());
	KeyValueMap getValues(const QString& aTableName, const QString& aColumns, const QString& aWhere);
	KeyValueMap getImageData(const QString& aTableName, const QString& aColumns, const QString& aWhere, const QString& aFileName);

private:
	QSqlDatabase mDataBase;
};

#endif // CXBASECLIENT_H
