#ifndef CXSETTINGSXML_H
#define CXSETTINGSXML_H

#include <QString>

/*!
 Класс для работы с настройками в xml-файле.
 */
class CXSettingsXML
{
public:
  /*! Функция получения значения переменной в файле настроек.
   \param aFileName - имя файла настроек.
   \param aName - имя настройки.
   */
  static QString
  getValue(const QString& aFileName, const QString& aName);

  //! Функция получения задержки.
  static int
  getDelay(const QString& aFileName, const QString& aName);
};

#endif // CXSETTINGSXML_H
