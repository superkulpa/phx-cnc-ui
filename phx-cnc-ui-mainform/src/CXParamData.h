#ifndef CXPARAMDATA_H
#define CXPARAMDATA_H

#include <QStringList>
#include <QPair>

#include "iniFile.h"

typedef QList<QPair<QString, QString>> PairsList;

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
		Функция открытия ini-файла.
		\param aFileName - имя файла с путем.
	*/
	static void open(const QString& aFileName);

	/*!
		Функция закрытия ini-файла и освобождение ресурсов.
		\param aIsWrite - записывать ли изменения на диск.
	*/
	static void close(bool aIsWrite = true);

	/*!
		Функция получения списка ключей и их значений.
		\param aType - тип реза (автоматически добавляет Keys к имени группы).
	*/
	static QMap<QString, QString> getKeys(const QString& aType);

	/*!
		Функция получения списка название и значение параметра.
		\param aType - тип реза.
	*/
	static QMap<QString, QString> getValues(const QString& aType);

	/*!
	Функция получения списка название и описание параметра.
	\param aFileName - имя xml-файла.
		\param aType - тип реза.
	*/
	static QList<SXDataXml> getCaptions(const QString& aFileName, const QString& aType);

	/*!
		Функция получения списка названий секций картинок.
		\param aFileName - имя xml-файла.
		\param aType - тип реза.
		\return Список названий секций картинок.
	*/
	static QList <QString> getImages(const QString& aFileName, const QString& aType);

	/*!
		Функция получения списка зафиксированных ключей.
		\param aFileName - имя xml-файла.
		\param aType - тип реза.
		\return Список зафиксированных ключей.
	*/
	static QMap<QString, QString> getFixedKeys(const QString& aFileName, const QString& aType);

	/*!
		Функция удаления списка ключей/групп из ini-файла.
		\param aKeys - список удаляемых ключей/групп (автоматически добавляет Keys к имени группы).
	*/
	static void deleteKeys(const QStringList& aKeys);

	/*!
		Функция установки списка доступных ключей для группы.
		\param aGroup - имя группы, для которых устанавливается список ключей (автоматически добавляет Keys к имени группы).
		\param aKeys - список добавляемых ключей.
	*/
	static void setKeysArray(const QString& aGroup, const QStringList& aKeys);
	
	/*!
		Функция получения списка доступных ключей для группы.
		\param aGroup - имя группы, для которых устанавливается список ключей (автоматически добавляет Keys к имени группы).
		\return Список доступных ключей.
	*/
	static QStringList getKeysArray(const QString& aGroup);

	/*!
		Функция установки значений группе.
		\param aGroup - имя группы, для которой устанавливаются значения.
		\param aValues - список пар (имя, значение).
	*/
	static void setValues(const QString& aGroup, const PairsList& aValues);

private:
	static CIniFile gIniFile;
};

#endif // CXPARAMDATA_H
