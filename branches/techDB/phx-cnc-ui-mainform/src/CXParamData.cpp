#include "CXParamData.h"

#include <QXmlQuery>
#include <QRegExp>
#include <QTextCodec>

CIniFile CXParamData::gIniFile;

void CXParamData::open(const QString& aFileName)
{
	gIniFile = CIniFile(aFileName.toStdString(), 0);
	gIniFile.ReadIniFile();
	gIniFile.CaseInsensitive();
}

void CXParamData::close(bool aIsWrite)
{
	if (aIsWrite) gIniFile.WriteIniFile();
	gIniFile.Erase();
}

QMap<QString, QString> CXParamData::getKeys(const QString& aType)
{
	std::string group = (aType + "/Keys").toStdString();
	int count = gIniFile.GetNumValues(group);

	QMap<QString, QString> res;
	std::string valueName;

	for (int i = 0; i < count; i++)
	{
		valueName = gIniFile.GetValueName(group, i);

		res.insert(QString::fromStdString(valueName), QString::fromStdString(gIniFile.GetValue(group, valueName)));
	}

	return res;
}

QMap<QString, QString> CXParamData::getValues(const QString& aType)
{
	std::string group = aType.toStdString();
	int count = gIniFile.GetNumValues(group);

	QMap<QString, QString> res;
	std::string valueName;

	for (int i = 0; i < count; i++)
	{
		valueName = gIniFile.GetValueName(group, i);

		res.insert(QString::fromStdString(valueName), QString::fromStdString(gIniFile.GetValue(group, valueName)));
	}

	return res;
}

QList<SXDataXml> CXParamData::getCaptions(const QString& aFileName, const QString& aType)
{
	QList<SXDataXml> res;

	QXmlQuery xmlQuery(QXmlQuery::XQuery10);
	xmlQuery.setQuery(QString("doc('%1')/Settings/ui-TechParams/%2").arg(aFileName).arg(aType));

	if (!xmlQuery.isValid()) return res;

	QString text;
	if (xmlQuery.evaluateTo(&text))
	{
		QRegExp regExp("<(\\w+)[^>]+/>");
		QRegExp regVisible("visible=\"([^\"]+)\"");
		QRegExp regDescr("descr=\"([^\"]+)\"");
		QRegExp regColumn("column=\"([^\"]+)\"");
		QRegExp regReadOnly("readonly=\"([^\"]+)\"");
		QRegExp regDelta("delta=\"([^\"]+)\"");
		regExp.setMinimal(true);

		int index = regExp.indexIn(text);
		QString tagText;
		while (index >= 0)
		{
			tagText = regExp.cap(0);

			regVisible.indexIn(tagText);

			if (regVisible.cap(1).isEmpty() || regVisible.cap(1) != "0")
			{
				regDescr.indexIn(tagText);
				regColumn.indexIn(tagText);
				regReadOnly.indexIn(tagText);
				regDelta.indexIn(tagText);

				res.append(SXDataXml(regExp.cap(1), regDescr.cap(1), regColumn.cap(1).toInt(), regReadOnly.cap(1).toInt(), regDelta.cap(1).toDouble()));
			}

			index += regExp.matchedLength();
			index = regExp.indexIn(text, index);
		}
	}

	return res;
}

QList <QString> CXParamData::getImages(const QString& aFileName, const QString& aType)
{
	QList <QString> res;

	QXmlQuery xmlQuery(QXmlQuery::XQuery10);
	xmlQuery.setQuery(QString("doc('%1')/Settings/ui-TechParams/%2/assembly").arg(aFileName).arg(aType));

	if (!xmlQuery.isValid()) return res;

	QString text;
	if (xmlQuery.evaluateTo(&text))
	{
		QRegExp regExp("<item +path=\"([^\"]+)\"[^>]*/>");
		regExp.setMinimal(true);

		int index = regExp.indexIn(text);
		while (index >= 0)
		{
			res.append(regExp.cap(1));

			index += regExp.matchedLength();
			index = regExp.indexIn(text, index);
		}
	}

	return res;
}

QMap<QString, QString> CXParamData::getFixedKeys(const QString& aFileName, const QString& aType)
{
	QMap<QString, QString> res;

	QXmlQuery xmlQuery(QXmlQuery::XQuery10);
	xmlQuery.setQuery(QString("doc('%1')/Settings/ui-TechParams/%2/fixed").arg(aFileName).arg(aType));

	if (!xmlQuery.isValid()) return res;

	QString text;
	if (xmlQuery.evaluateTo(&text))
	{
		QRegExp regExp("<([^<]+) +value=\"([^\"]+)\" */>");
		regExp.setMinimal(true);

		int index = regExp.indexIn(text);
		while (index >= 0)
		{
			if (regExp.cap(4).isEmpty() || regExp.cap(4) != "0")
			{
				res.insert(regExp.cap(1), regExp.cap(2));
			}

			index += regExp.matchedLength();
			index = regExp.indexIn(text, index);
		}
	}

	return res;
}

void CXParamData::deleteKeys(const QStringList& aKeys)
{
	for (int i = 0; i < aKeys.count(); i++)
	{
		std::string group = aKeys.at(i).toStdString();
		gIniFile.DeleteKey(group);
	}
}

void CXParamData::setKeysArray(const QString& aGroup, const QStringList& aKeys)
{
	std::string group = (aGroup + "/Keys").toStdString();

	gIniFile.DeleteKey(group);
	gIniFile.SetValue(group, "Keys", aKeys.join(",").toStdString());
}

QStringList CXParamData::getKeysArray(const QString& aGroup)
{
	std::string group = (aGroup + "/Keys").toStdString();

	return QString::fromStdString(gIniFile.GetValue(group, "Keys")).split(",", QString::SkipEmptyParts);
}

void CXParamData::setValues(const QString& aGroup, const PairsList& aValues)
{
	std::string group = aGroup.toStdString();

	QTextCodec* codec = QTextCodec::codecForName("UTF-8");

	for (int i = 0; i < aValues.count(); i++)
	{
		gIniFile.SetValue(group, aValues.at(i).first.toStdString(), codec->fromUnicode(aValues.at(i).second).data());
	}
}
