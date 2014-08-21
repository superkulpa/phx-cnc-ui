#include <QLibrary>

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QTextCodec>
#include <QSqlQuery>
#include <qdebug.h>
#include <math.h>

#include "CXBaseClient.h"
#include "utils/CXParamData.h"
#include "utils/iniFile.h"

//
class CDBParser{

public:
  QTextStream& out;

  bool
  contains(const QString& aKey, KeyValueMap& aKeys,
      const KeyValueList& aAvailableKeys, const QString& aType)
  {
    if (!aKeys.contains(aKey))
      return false;

    QString keyValue = aKeys.value(aKey);

    QString value;
    foreach (Pair curValue, aAvailableKeys){
      if (curValue.first == keyValue)
      {
        value = curValue.second;
        break;
      }
    }

    if (value.isEmpty())
      return false;

    QString res = aKeys.value(aKey);
    aKeys.insert(aKey, value);

    CXParamData::setValues(aType + "/Keys",
        PairsList() << QPair<QString, QString>(aKey, res));

    return true;
  }

  int
  check(const KeyValueList& aAvailableKeys, const QString& aCurKey,
      KeyValueMap& aKeys, const QString& aType)
  {
    if (aAvailableKeys.isEmpty())
    {
     // CXParamData::close();
      return -1;
    }

    QStringList list;
    foreach (Pair curValue, aAvailableKeys){
      list.append(curValue.first);
    }

    CXParamData::setKeysArray(aCurKey, list);

    if (!contains(aCurKey, aKeys, aAvailableKeys, aType))
    {
     // CXParamData::close();
      return 0;
    }

    return 1;
  }
  CDBParser(QTextStream& _out):
    out(_out)
  {    }

};

//
int getFromDB(QTextStream& out, const QString& fileName, const QString& type){
  /**/
  CXParamData::open(fileName);
  CXBaseClient client;
//  KeyValueMap dataBase = CXParamData::getValues("Database");
  QString dbFileName = "db/" + type + ".db";// dataBase.value("name");

//  QString resString = client.connectToDataBase(dataBase.value("hosts"), dbFileName,
//      dataBase.value("port").toInt(), dataBase.value("user"), dataBase.value("password"));
  QString resString = client.connectToDataBase("", dbFileName, 0, "", "");

  int res = 0;
  CDBParser dbparser(out);
  do{
    if (!resString.isEmpty())
    {
      out << "connection error: '"<< resString << "'";
      res = -1;
      break;
    }

    KeyValueMap keys = CXParamData::getValues(type + "/Keys");
    CXParamData::deleteKeys(QStringList() << type);
    /**/
    QStringList allKeys;
    allKeys <<  "Source/Keys" << "MetallType/Keys" << "Thickness/Keys" << "Power/Keys" << "GasTypes/Keys" << "ConsAngles/Keys" << type + "/Common";
    CXParamData::deleteKeys(allKeys);

    /**/
    QString curKey = "Source";
    KeyValueList availableKeys = client.execute("tbl_plasma_sources", "id, name", "", "name");

    res = dbparser.check(availableKeys, curKey, keys, type);
    if (res <= 0)
    {
      if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
      else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

      res = -2;
      break;
    }

    curKey = "MetallType";
    QString w = QString("plasma_source=%1").arg(keys.value("Source"));
    availableKeys = client.execute("tbl_plasma_metal_types as a, tbl_plasma_params as b", "DISTINCT metal_type, a.name", w + " AND metal_type=a.id", "a.name");

    res = dbparser.check(availableKeys, curKey, keys, type);
    if (res <= 0)
    {
      if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
      else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));
      res = -3;
      break;
    }

    curKey = "Thickness";
    w += QString(" AND metal_type=%2").arg(keys.value("MetallType"));
    availableKeys = client.execute("tbl_plasma_params", "DISTINCT min_thickness, min_thickness", w, "min_thickness");

    res = dbparser.check(availableKeys, curKey, keys, type);
    if (res <= 0)
    {
      if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
      else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

      res = -4;
      break;
    }

    curKey = "Power";
    w += QString(" AND max_thickness=%1").arg(keys.value("Thickness"));
    availableKeys = client.execute("tbl_plasma_params", "DISTINCT amperage, amperage", w, "amperage");
    res = dbparser.check(availableKeys, curKey, keys, type);
    if (res <= 0)
    {
      if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
      else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

      res = -5;
      break;
    }

    curKey = "GasTypes";
    w += QString(" AND amperage=%1").arg(keys.value("Power"));
    availableKeys = client.execute("tbl_gas_types as a, tbl_plasma_params as b", "DISTINCT b.gases, a.gases", w + " AND b.gases=a.id", "a.gases");

    res = dbparser.check(availableKeys, curKey, keys, type);
    if (res <= 0)
    {
      if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
      else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

      res = -6;
      break;
    }

    curKey = "ConsAngles";
    w += QString(" AND gases=%1").arg(keys.value("GasTypes"));
    availableKeys = client.execute("tbl_cons_angles as a, tbl_plasma_params as b", "DISTINCT b.cons_angle, a.name", w + " AND b.cons_angle=a.id", "a.name");

    res = dbparser.check(availableKeys, curKey, keys, type);
    if (res <= 0)
    {
      if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
      else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

      res = -7;
      break;
    }

    w += QString(" AND cons_angle=%1").arg(keys.value("ConsAngles"));

    /* Загрузка значений полей */
    KeyValueMap columnValuesMap;

    columnValuesMap.insert("min_thickness", "MinThickness");
    columnValuesMap.insert("max_thickness", "MaxThickness");

    columnValuesMap.insert("amperage", "Power");
    columnValuesMap.insert("out_description", "Description");
    columnValuesMap.insert("out_under_water", "UnderWater");
    columnValuesMap.insert("out_voltage", "SVRVoltage");
    columnValuesMap.insert("out_feed", "CuttingFeed");
    columnValuesMap.insert("out_burning_z_distance", "BurningZDistance");
    columnValuesMap.insert("out_cutting_z_distance", "CuttingZDistance");
    columnValuesMap.insert("out_kerf", "Kerf");
    columnValuesMap.insert("out_ignition_distance", "IgnitionDistance");
    columnValuesMap.insert("out_burning_feed", "BurningFeed");
    columnValuesMap.insert("out_burning_time", "BurningTime");
    columnValuesMap.insert("out_parts_group", "PartsNumber");
    columnValuesMap.insert("out_gases_mix1", "Mixes1");
    columnValuesMap.insert("out_gases_mix2", "Mixes2");
    columnValuesMap.insert("out_plasma_preflow_pressure", "Gas1PreflowPressure");
    columnValuesMap.insert("out_shield_preflow_pressure", "Gas2PreflowPressure");
    columnValuesMap.insert("out_plasma_cutflow_pressure", "Gas1CutflowPressure");
    columnValuesMap.insert("out_shield_cutflow_pressure", "Gas2CutflowPressure");
    columnValuesMap.insert("out_plasma_preflow_rate", "Gas1PreflowRate");
    columnValuesMap.insert("out_shield_preflow_rate", "Gas2PreflowRate");
    columnValuesMap.insert("out_plasma_cutflow_rate", "Gas1CutflowRate");
    columnValuesMap.insert("out_shield_cutflow_rate", "Gas2CutflowRate");

    KeyValueMap values = client.getValues("tbl_plasma_params", QStringList(columnValuesMap.keys()).join(","), w);
    if (!values.isEmpty())
    {
      PairsList resValues;
      QMap<QString, QString>::iterator iter;
      QString value;

      for (iter = columnValuesMap.begin(); iter != columnValuesMap.end(); iter++)
      {
        value = values.value(iter.key());

        if (value == "false") value = "0";
        if (value == "true") value = "1";

        resValues.append(QPair<QString,QString>(iter.value(), value));
      }

      CXParamData::setValues(type + "/Common", resValues);
    }

    /**/
    /*
   for (int i = 2; i <= 76; i++)
   {
   //client.getImageData("tbl_torch_parts_types as a, tbl_torch_parts as b", "a.name, a.description, b.image", QString("b.id=%1").arg(i), QString("d:/%1.bmp").arg(i));

   QFile file(QString("d:/!images!/%1.bmp").arg(i));
   if (!file.open(QIODevice::ReadOnly)) continue;
   QByteArray byteArray = file.readAll();

   QString queryString = QString("UPDATE tbl_torch_parts SET image=? WHERE id=?;");

   QSqlQuery query;
   query.prepare(queryString);
   query.addBindValue(byteArray);
   query.addBindValue(i);
   bool b = query.exec();
   b = b;
   }
     */
    /* Загрузка картинок */
    bool isBreak = false;
    int imageIndex = 1;
    KeyValueMap imageParts = client.getValues("tbl_parts_groups"
        , "part_1,part_2,part_3,part_4,part_5,part_6,part_7,part_8,part_9,part_10"
        , QString("id=%1").arg(values.value("out_parts_group")));
    QString curPart;
    QFileInfo fileInfo(dbFileName);

    QDir imagesDir(QString("db/%1").arg(type));
    if (!imagesDir.exists())
      imagesDir.mkpath(QString("db/%1").arg(type));

    while (!isBreak)
    {
      curPart = QString("part_%1").arg(imageIndex);
      values = CXParamData::getValues(QString("%1/Image%2").arg(type).arg(imageIndex));

      if (values.isEmpty() || !imageParts.contains(curPart)) isBreak = true;
      else
      {
        values = client.getImageData("tbl_torch_parts_types as a, tbl_torch_parts as b"
            , "a.name, a.description, b.number, b.image"
            , "b.type = a.id AND b.id=" + imageParts.value(curPart)
            , QString("db/%1/Image%2").arg(type).arg(imageIndex));

        //          qDebug() << values;
        PairsList imageValues;
        imageValues << QPair<QString, QString>("image", QString("%1/Image%2").arg(type).arg(imageIndex));
        QMap<QString, QString>::iterator iter;
        for (iter = values.begin(); iter != values.end(); iter++)
        {
          if (iter.key() == QString("image")) continue;

          imageValues << QPair<QString, QString>(iter.key(), iter.value());
        }
        //          qDebug() << imageValues;
        CXParamData::setValues(QString("%1/Image%2").arg(type).arg(imageIndex), imageValues);
      }

      imageIndex++;
    }
  }while(0);

  /**/
  CXParamData::close();
  return res>0?0:res;

}

