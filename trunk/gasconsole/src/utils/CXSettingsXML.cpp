#include "CXSettingsXML.h"

#include <QFile>
#include <QXmlQuery>

QString
CXSettingsXML::getValue(const QString& aFileName, const QString& aName, const  QString& def)
{
  QString result;
  QFile xmlFile(aFileName);

  if (xmlFile.open(QIODevice::ReadOnly))
  {
    QXmlQuery query;
    query.setFocus(&xmlFile);
    query.setQuery(QString("/Settings/%1/text()").arg(aName));

    query.evaluateTo(&result);

    xmlFile.close();
  }
  if(result.length() == 0) result = def;
  return result;
}

int
CXSettingsXML::getDelay(const QString& aFileName, const QString& aName)
{
  QString value = CXSettingsXML::getValue(aFileName, aName, "100");
  if (value.isEmpty())
    return 200;

  bool ok = true;
  int delay = value.toInt(&ok);

  if (!ok)
    return 200;

  return delay;
}
