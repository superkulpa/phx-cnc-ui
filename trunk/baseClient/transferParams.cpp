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

////раскидываем параметры разметчика
//int
//ReloadWriterCuttingParams(CIniFile& _cutIni)
//{
//  int _listFeed = _cutIni.GetValueI("Writer/Common", "CuttingFeed", 1000);
//  iniFileParams.SetValueI("Move/ListFeed", "value", _listFeed);
//
//  double zTouchUp = _cutIni.GetValueF("Writer/Common", "CuttingZDistance", 0)
//              * 10;
//  iniParamsTech.SetValueI("Technology/Writer/TouchUp", "value", zTouchUp);
//
//  double zHunt = _cutIni.GetValueF("Writer/Common", "SVRVoltage", 0);
//
//  iniParamsTech.SetValueF("Technology/Writer/ZHunt","value", zHunt);
//
//  //  if (SetZHuntValue(3, _cutIni.GetValueF("Writer/Common", "ArcVoltage", 0))
//  //      != 0)
//  //    return 1;
//
//  if (!iniParamsTech.WriteIniFile())
//  {
//    printf("ERROR: fault to write Ini file\n");
//    iniParamsTech.ReadIniFile();
//    return 1;
//  }; //else SendReloadIniFile(iniParamsWriter.Path());
//  return 0;
//
//}
//
////при необходимости раскидываем параметры кислорода
//int
//ReloadOxyCuttingParams(CIniFile& _cutIni)
//{
//  ///скидываем параметры с временного файла в файл инициализации
//  int _listFeed = _cutIni.GetValueI("Oxy/Common", "CuttingFeed", 1000);
//  iniFileParams.SetValueI("Move/ListFeed", "value", _listFeed);
//  iniFileParams.SetValueI("General/Offset", "value",
//      qRound(_cutIni.GetValueF("Oxy/Common", "Kerf", 0) * 10 / 2));
//
//  //файл для передачи параметров кислородной газовой консоли
//  CIniFile iniParamsGC("./jini/paramsGC.ini", 1000);
//  iniParamsGC.ReadFile("./jini/paramsGC.ini");
//  ///настройка газовой консоли
//  QString n_sup = "";
//  for (int i = 0; i < MAX_SUPP_COUNT; i++)
//  {
//    if ((1 << i) & supp_mask)
//    {
//      n_sup = "Oxy/Support" + QString::number(i + 1);
//      string n_sup_std = n_sup.toStdString();
//      iniParamsGC.SetValueF(n_sup_std, "KP",
//          _cutIni.GetValueF(n_sup_std, "KP", 0));
//      iniParamsGC.SetValueF(n_sup_std, "KPV",
//          _cutIni.GetValueF(n_sup_std, "KPV", 0));
//      iniParamsGC.SetValueF(n_sup_std, "GG",
//          _cutIni.GetValueF(n_sup_std, "GG", 0));
//      iniParamsGC.SetValueF(n_sup_std, "GGV",
//          _cutIni.GetValueF(n_sup_std, "GGV", 0));
//    };
//  };
//
//  iniParamsGC.SetValueF("Oxy/MOxy_Pressure", "value",
//      _cutIni.GetValueF("Oxy/MOxy_Pressure", "value", 10));
//  iniParamsGC.SetValueF("Oxy/MOxy_Pressure_Hi", "value",
//      _cutIni.GetValueF("Oxy/MOxy_Pressure_Hi", "value", 10));
//
//  //iniParamsGC.SetValueF("Oxy/AccTimeMOxy", "value", iniParamsOxy.GetValueF("Technology/Oxy/WaitKr2","value", 10) );
//
//  if (!iniParamsGC.WriteIniFile())
//  {
//    printf("ERROR: fault to write Ini file\n");
//    iniParamsGC.ReadIniFile();
//    return 1;
//  }; //else SendReloadIniFile(iniParamsGC.Path());
//
//  ///настройкм технологических параметров
//  iniParamsTech.SetValueI("Technology/Oxy/WarmTime", "value",
//      _cutIni.GetValueF("Oxy/Common", "WarmingTime", 60) * 10);
//
//  iniParamsTech.SetValueI("Technology/Oxy/Burn/Time", "value",
//      _cutIni.GetValueF("Oxy/Common", "BurningTime", 2) * 10);
//
//  int burn_feed = _cutIni.GetValueI("Oxy/Common", "BurningFeed", 0);
//  iniParamsTech.SetValueI("Technology/Oxy/Burn/FeedDivisor", "value",
//      (int) burn_feed * 100 / _listFeed);
//
//
//  double zHunt = _cutIni.GetValueF("Oxy/Common", "SVRVoltage", 0);
//
//  iniParamsTech.SetValueF("Technology/Oxy/ZHunt","value", zHunt);
//
//
//  if (!iniParamsTech.WriteIniFile())
//  {
//    printf("ERROR: fault to write Ini file\n");
//    iniParamsTech.ReadIniFile();
//    return 1;
//  }; //else SendReloadIniFile(iniParamsOxy.Path());
//
//  //  if(SetZHuntValue(supp_count, _cutIni.GetValueF(name, "SVRVoltage", 0)) != 0)
//  //      return 1;
//  return 0;
//}

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
  return 0;
}
