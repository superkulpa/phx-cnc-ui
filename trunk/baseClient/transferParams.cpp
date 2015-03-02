/*
 * parseG59.cpp
 *
 *  Created on: Jul 31, 2014
 *      Author: kulpanov
 */


#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QTextCodec>
#include <qdebug.h>
#include <math.h>

#include "CXBaseClient.h"
#include "utils/CXParamData.h"
#include "utils/iniFile.h"


//при необходимости раскидываем параметры плазмы
int
ReloadPlasmaCuttingParams(CIniFile& cutIni, CIniFile& moveIni, CIniFile& techIni, QString _name)
{
  string name = _name.toStdString() + "/Common";

  int listFeed = cutIni.GetValueI(name, "CuttingFeed", 1000);
  moveIni.SetValueI("Move/ListFeed", "value", listFeed);
  moveIni.SetValueI("General/Offset", "value", qRound(cutIni.GetValueF(name, "Kerf", 0) * 10 / 2));

  int burn_feed = cutIni.GetValueI(name, "BurningFeed", 0);

  double zTouchUp = 0;
  double zUpAfterArc = 0;
  double zCutDistance = 0;
  double motionDelay = qRound(cutIni.GetValueF(name, "BurningTime", 0) * 10);
  string paramName = "Technology/" + _name.toStdString() + "/MotionDelay";
  techIni.SetValueI(paramName, "value", (motionDelay >= 0) ? motionDelay : 0);
  paramName = "Technology/" + _name.toStdString() + "/Burn/FeedDivisor";
  techIni.SetValueI(paramName, "value", (int) burn_feed * 100 / listFeed);

  zTouchUp = cutIni.GetValueF(name, "IgnitionDistance", 0) * 10;
  paramName = "Technology/" + _name.toStdString() + "/TouchUp";
  techIni.SetValueI(paramName, "value", zTouchUp);

  zUpAfterArc = cutIni.GetValueF(name, "BurningZDistance", 0) * 10;

  paramName = "Technology/" + _name.toStdString() + "/Burn/ZUp";
  if (zUpAfterArc - zTouchUp > 0)
    techIni.SetValueI(paramName, "value", (zUpAfterArc - zTouchUp));
  else
    techIni.SetValueI(paramName, "value", 0);

  zCutDistance = cutIni.GetValueF(name, "CuttingZDistance", 0) * 10;

  //высота реза
  paramName = "Technology/" + _name.toStdString() + "/CutZDistance";
  techIni.SetValueI(paramName, "value", zCutDistance);

  double zHunt = cutIni.GetValueF(name, "SVRVoltage", 0);

  paramName = "Technology/" + _name.toStdString() + "/ZHunt";

  techIni.SetValueF(paramName, "value", zHunt);

  return 0;
}

//перегружаем параметры реза
int transferToParams(QTextStream& out, const QString& fileName, const QString& type){
  CIniFile cutIni(fileName.toStdString(), -1);
  if (!cutIni.ReadFile(fileName.toStdString()))
  {
    out << "dbClient: "<< fileName << ": Unable read file";
    return 1;
  }
  string path = "./jini/params.ini";
  CIniFile iniFileParams(path);
  if (!iniFileParams.ReadIniFile())
  {
    out << "dbClient: "<< iniFileParams.Path().c_str() << ": Unable to read file";
    return 1;
  }
  path = "./jini/params" + type.toStdString() + ".ini";
  CIniFile iniParamsTech(path);
  if (!iniParamsTech.ReadIniFile())
  {
    out << "dbClient: "<< iniParamsTech.Path().c_str() << ": Unable to read file";
    return 1;
  }

  //обновляем нужную технологию
  int res = 0;
  if(type == "MPlasma" || type == "Plasma")
    res = ReloadPlasmaCuttingParams(cutIni, iniFileParams, iniParamsTech, type);
//  else if (_type == "Oxy")
//    res = ReloadOxyCuttingParams(cutIni);
//  else
//    res = ReloadWriterCuttingParams(cutIni);
  if (res != 0)
    return res;

  if (!iniParamsTech.WriteIniFile())
  {
    out << "dbClient: "<< iniParamsTech.Path().c_str() << ": Unable to write file";
    return 1;
  }

  if (!iniFileParams.WriteIniFile())
  {
    out << "dbClient: "<< iniFileParams.Path().c_str() << ": Unable to write file";
    return 1;
  }
//  QFile::remove("jini/techparams.ini");
//  QFile::copy(fileName, "jini/techparams.ini");
  return 0;
}
