#include <QtCore/QCoreApplication>
#include <QApplication>
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

#define MAX_SUPP_COUNT 8
CIniFile iniFileParams;
CIniFile iniParamsTech;
//CIniFile iniParamsSup[MAX_SUPP_COUNT];
int supp_count;
int supp_mask;

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
      CXParamData::close();
      return -1;
    }

  QStringList list;
  foreach (Pair curValue, aAvailableKeys){
    list.append(curValue.first);
  }

  CXParamData::setKeysArray(aCurKey, list);

  if (!contains(aCurKey, aKeys, aAvailableKeys, aType))
    {
      CXParamData::close();
      return 0;
    }

  return 1;
}

//int
//SetZHuntValue(int _supp_count, double _zHunt, double _preZHunt = .0)
//{
//  // for (int i = 0; i < _supp_count; i++)
//  {
//    iniParamsSup[0].SetValueF("Support1/THC/ZHunt", "value", _zHunt);
//    if (_preZHunt != 0)
//      iniParamsSup[0].SetValueF("Support1/THC/preZHunt", "value", _preZHunt);
//    if (!iniParamsSup[0].WriteIniFile())
//      return 1;
//  };
//return 0;
//}

//при необходимости раскидываем параметры плазмы
int
ReloadPlasmaCuttingParams(CIniFile& _cutIni, CIniFile& _techIni, QString _name)
{
  string name = _name.toStdString() + "/Common";

  int _listFeed = _cutIni.GetValueI(name, "CuttingFeed", 1000);
  iniFileParams.SetValueI("Move/ListFeed", "value", _listFeed);
  iniFileParams.SetValueI("General/Offset", "value", qRound(_cutIni.GetValueF(name, "Kerf", 0) * 10 / 2));

  int burn_feed = _cutIni.GetValueI(name, "BurningFeed", 0);

  double zTouchUp = 0;
  double zUpAfterArc = 0;
  double zCutDistance = 0;
  double motionDelay = qRound(_cutIni.GetValueF(name, "BurningTime", 0) * 10);
  string paramName = "Technology/" + _name.toStdString() + "/MotionDelay";
  _techIni.SetValueI(paramName, "value", (motionDelay >= 0) ? motionDelay : 0);
  paramName = "Technology/" + _name.toStdString() + "/Burn/FeedDivisor";
  _techIni.SetValueI(paramName, "value", (int) burn_feed * 100 / _listFeed);

  zTouchUp = _cutIni.GetValueF(name, "IgnitionZDistance", 0) * 10;
  paramName = "Technology/" + _name.toStdString() + "/TouchUp";
  _techIni.SetValueI(paramName, "value", zTouchUp);

  zUpAfterArc = _cutIni.GetValueF(name, "BurningZDistance", 0) * 10;

  paramName = "Technology/" + _name.toStdString() + "/Burn/ZUp";
  if (zUpAfterArc - zTouchUp > 0)
    _techIni.SetValueI(paramName, "value", (zUpAfterArc - zTouchUp));
  else
    _techIni.SetValueI(paramName, "value", 0);

  zCutDistance = _cutIni.GetValueF(name, "CuttingZDistance", 0) * 10;

  //высота реза
  paramName = "Technology/" + _name.toStdString() + "/BurnZDistance";
  _techIni.SetValueI(paramName, "value", zCutDistance);

  double zHunt = _cutIni.GetValueF(name, "SVRVoltage", 0);

  paramName = "Technology/" + _name.toStdString() + "/ZHunt";

  _techIni.SetValueF(paramName, "value", zHunt);
//
//  if (SetZHuntValue(supp_count, _cutIni.GetValueF(name, "SVRVoltage", 0)) != 0)
//    return 1;

  if (!_techIni.WriteIniFile())
    {
      printf("ERROR: fault to write Ini file\n");
      _techIni.ReadIniFile();
      return 1;
    }; //else SendReloadIniFile(_techIni->Path());
  return 0;
}

//раскидываем параметры разметчика
int
ReloadWriterCuttingParams(CIniFile& _cutIni)
{
  int _listFeed = _cutIni.GetValueI("Writer/Common", "CuttingFeed", 1000);
  iniFileParams.SetValueI("Move/ListFeed", "value", _listFeed);

  double zTouchUp = _cutIni.GetValueF("Writer/Common", "CuttingZDistance", 0)
          * 10;
  iniParamsTech.SetValueI("Technology/Writer/TouchUp", "value", zTouchUp);

  double zHunt = _cutIni.GetValueF("Writer/Common", "SVRVoltage", 0);

  iniParamsTech.SetValueF("Technology/Writer/ZHunt","value", zHunt);

//  if (SetZHuntValue(3, _cutIni.GetValueF("Writer/Common", "ArcVoltage", 0))
//      != 0)
//    return 1;

  if (!iniParamsTech.WriteIniFile())
    {
      printf("ERROR: fault to write Ini file\n");
      iniParamsTech.ReadIniFile();
      return 1;
    }; //else SendReloadIniFile(iniParamsWriter.Path());
  return 0;

}

//при необходимости раскидываем параметры кислорода
int
ReloadOxyCuttingParams(CIniFile& _cutIni)
{
  ///скидываем параметры с временного файла в файл инициализации
  int _listFeed = _cutIni.GetValueI("Oxy/Common", "CuttingFeed", 1000);
  iniFileParams.SetValueI("Move/ListFeed", "value", _listFeed);
  iniFileParams.SetValueI("General/Offset", "value",
      qRound(_cutIni.GetValueF("Oxy/Common", "Kerf", 0) * 10 / 2));

  //файл для передачи параметров кислородной газовой консоли
  CIniFile iniParamsGC("./jini/paramsGC.ini", 1000);
  iniParamsGC.ReadFile("./jini/paramsGC.ini");
  ///настройка газовой консоли
  QString n_sup = "";
  for (int i = 0; i < MAX_SUPP_COUNT; i++)
    {
      if ((1 << i) & supp_mask)
        {
          n_sup = "Oxy/Support" + QString::number(i + 1);
          string n_sup_std = n_sup.toStdString();
          iniParamsGC.SetValueF(n_sup_std, "KP",
              _cutIni.GetValueF(n_sup_std, "KP", 0));
          iniParamsGC.SetValueF(n_sup_std, "KPV",
              _cutIni.GetValueF(n_sup_std, "KPV", 0));
          iniParamsGC.SetValueF(n_sup_std, "GG",
              _cutIni.GetValueF(n_sup_std, "GG", 0));
          iniParamsGC.SetValueF(n_sup_std, "GGV",
              _cutIni.GetValueF(n_sup_std, "GGV", 0));
        };
    };

  iniParamsGC.SetValueF("Oxy/MOxy_Pressure", "value",
      _cutIni.GetValueF("Oxy/MOxy_Pressure", "value", 10));
  iniParamsGC.SetValueF("Oxy/MOxy_Pressure_Hi", "value",
      _cutIni.GetValueF("Oxy/MOxy_Pressure_Hi", "value", 10));

  //iniParamsGC.SetValueF("Oxy/AccTimeMOxy", "value", iniParamsOxy.GetValueF("Technology/Oxy/WaitKr2","value", 10) );

  if (!iniParamsGC.WriteIniFile())
    {
      printf("ERROR: fault to write Ini file\n");
      iniParamsGC.ReadIniFile();
      return 1;
    }; //else SendReloadIniFile(iniParamsGC.Path());

  ///настройкм технологических параметров
  iniParamsTech.SetValueI("Technology/Oxy/WarmTime", "value",
      _cutIni.GetValueF("Oxy/Common", "WarmingTime", 60) * 10);

  iniParamsTech.SetValueI("Technology/Oxy/Burn/Time", "value",
      _cutIni.GetValueF("Oxy/Common", "BurningTime", 2) * 10);

  int burn_feed = _cutIni.GetValueI("Oxy/Common", "BurningFeed", 0);
  iniParamsTech.SetValueI("Technology/Oxy/Burn/FeedDivisor", "value",
      (int) burn_feed * 100 / _listFeed);


  double zHunt = _cutIni.GetValueF("Oxy/Common", "SVRVoltage", 0);

  iniParamsTech.SetValueF("Technology/Oxy/ZHunt","value", zHunt);


  if (!iniParamsTech.WriteIniFile())
    {
      printf("ERROR: fault to write Ini file\n");
      iniParamsTech.ReadIniFile();
      return 1;
    }; //else SendReloadIniFile(iniParamsOxy.Path());

  //  if(SetZHuntValue(supp_count, _cutIni.GetValueF(name, "SVRVoltage", 0)) != 0)
  //      return 1;
  return 0;
}

//перегружаем параметры реза
int
ReloadCuttingParams(QString _fname, QString _type/*, int _supp_mask*/)
{
  CIniFile cutIni(_fname.toStdString(), -1);
  if (!cutIni.ReadFile(_fname.toStdString()))
    {
      fprintf(stdout, "%s\n", "Unable read ini file 'techparams.ini'");
      return 1;
    }
  string path = "./jini/params.ini";
  iniFileParams.SetPath(path);
  if (!iniFileParams.ReadFile(path))
    {
      fprintf(stdout, "%s\n", "Unable read ini file './jini/params.ini'");
      return 1;
    };
  path = "./jini/params" + _type.toStdString() + ".ini";
  iniParamsTech.SetPath(path);
  if (!iniParamsTech.ReadFile(path))
    {
      string warn = "Unable read ini file " + iniParamsTech.Path();
      fprintf(stdout, "%s\n", warn.c_str());
      return 1;
    };
//  //нечего инициализировать
//  if (_supp_mask == 0)
//    return 1;
//  supp_mask = _supp_mask;
//
//  for (int i = 0; i < MAX_SUPP_COUNT; i++)
//    {
//      if (_supp_mask & (1 << i))
//        {
//          QString suppName = "./jini/paramsSupport" + QString::number(i + 1)
//          + ".ini";
//          iniParamsSup[supp_count] = CIniFile(suppName.toStdString(), -1);
//          if (!iniParamsSup[supp_count].ReadFile(suppName.toStdString()))
//            {
//              string warn = "Unable read ini file " + suppName.toStdString();
//              fprintf(stdout, "%s\n", warn.c_str());
//              return 1;
//            };
//          supp_count++;
//        };
//    };
  //обновляем нужную технологию
  int res = 0;
  if ((_type == "MPlasma") || (_type == "Plasma"))
    res = ReloadPlasmaCuttingParams(cutIni, iniParamsTech, _type);
  else if (_type == "Oxy")
    res = ReloadOxyCuttingParams(cutIni);
  else
    res = ReloadWriterCuttingParams(cutIni);
  if (res != 0)
    return res;
  if (!iniFileParams.WriteIniFile())
    {
      printf("ERROR: fault to write Ini file\n");
      iniFileParams.ReadIniFile();
      return 1;
    };	//else SendReloadIniFile(iniFileParams.Path());
  return 0;
}

int ConvertParams(QString _type, QString& _paramSect, QString& _paramName, QString& _paramValue){
  int intParamN = _paramName.toInt();
  double iParamV = _paramValue.toInt();
  //double dParamV = _paramValue.toDouble();
  switch(intParamN){
  	case 503:
  		_paramSect = _type + "/Keys";
  		_paramName = "MetallType";
  		if(iParamV == 1) _paramValue = "Mild steel";
  		else if(iParamV == 2) _paramValue = "Stainless steel";
  		else if(iParamV == 3) _paramValue = "Aluminum";
  		else if(iParamV == 4) _paramValue = "Other";
  		else if(iParamV == 5) _paramValue = "Brass";
  		else if(iParamV == 6) _paramValue = "Cooper";
  		//elseif (dParam = 1) _paramValue = "Mild steel";//TODO TH?
  	return 1;
  	case 504:
  		_paramSect = _type + "/Keys";
  		_paramName = "Power";
	return 1;
  	case 505:
  		_paramSect = _type + "/Keys";
  		_paramName = "GasTypes";
  		if(iParamV == 1) _paramValue = "Air/Air";
		else if(iParamV == 2) _paramValue = "O2/Air";
		else if(iParamV == 3) _paramValue = "O2/O2";
		else if(iParamV == 4) _paramValue = "N2/Air";
		else if(iParamV == 5) _paramValue = "N2/CO2";
		else if(iParamV == 6) _paramValue = "None/N2";
		else if(iParamV == 7) _paramValue = "O2/N2";
		else if(iParamV == 8) _paramValue = "CH4/N2";
		else if(iParamV == 9) _paramValue = "H35/N2";
		else if(iParamV == 10) _paramValue = "H5/N2";
		else if(iParamV == 11) _paramValue = "Air/N2";
		else if(iParamV == 12) _paramValue = "N2/N2";
		else if(iParamV == 13) _paramValue = "CO2/N2";
		else if(iParamV == 14) _paramValue = "None/Air";
		else if(iParamV == 15) _paramValue = "CH4/Air";
		else if(iParamV == 16) _paramValue = "O2-N2/Air";
		else if(iParamV == 17) _paramValue = "O2-N2/O2";
		else if(iParamV == 18) _paramValue = "O2";
		else if(iParamV == 19) _paramValue = "N2";
		else if(iParamV == 20) _paramValue = "N2/None";
		else if(iParamV == 21) _paramValue = "Air";
		else if(iParamV == 22) _paramValue = "F5/N2";
		else if(iParamV == 23) _paramValue = "H35&N2/N2";
		else if(iParamV == 24) _paramValue = "H17/N2";
		else if(iParamV == 25) _paramValue = "Ar/Ar";
		else if(iParamV == 26) _paramValue = "Air/Ar";
		else if(iParamV == 27) _paramValue = "Ar/Air";
	return 1;
  	case 507:
  		_paramSect = _type + "/Keys";
  		_paramName = "Thickness";
  		if(iParamV == 1) _paramValue = "None";
  		else if(iParamV < 4) _paramValue = "0.35";
  		else if(iParamV < 6) _paramValue = "0.4";
  		else if(iParamV < 8) _paramValue = "0.5";
  		else if(iParamV < 10) _paramValue = "0.6";
  		else if(iParamV < 12) _paramValue = "0.8";
  		else if(iParamV < 14) _paramValue = "0.9";
  		else if(iParamV == 14) _paramValue = "1";
  		else if(iParamV < 17) _paramValue = "1.2";
  		else if(iParamV < 19) _paramValue = "1.5";
  		else if(iParamV == 19) _paramValue = "1.6";
  		else if(iParamV < 22) _paramValue = "2";
  		else if(iParamV == 22) _paramValue = "2.4";
  		else if(iParamV < 25) _paramValue = "2.5";
  		else if(iParamV == 25) _paramValue = "3.2";
  		else if(iParamV < 28) _paramValue = "3.5";
  		else if(iParamV == 28) _paramValue = "4.8";
  		else if(iParamV == 29) _paramValue = "6";
  		else if(iParamV == 30) _paramValue = "8";
  		else if(iParamV == 31) _paramValue = "10";
  		else if(iParamV == 32) _paramValue = "11";
  		else if(iParamV == 33) _paramValue = "12";
  		else if(iParamV == 34) _paramValue = "14";
  		else if(iParamV == 35) _paramValue = "15";
  		else if(iParamV == 36) _paramValue = "20";
  		else if(iParamV == 37) _paramValue = "22";
  		else if(iParamV == 38) _paramValue = "25";
  		else if(iParamV == 39) _paramValue = "30";
  		else if(iParamV == 40) _paramValue = "32";
  		else if(iParamV == 41) _paramValue = "35";
  		else if(iParamV == 42) _paramValue = "38";
  		else if(iParamV == 43) _paramValue = "45";
  		else if(iParamV == 44) _paramValue = "50";
  		else if(iParamV == 45) _paramValue = "60";
  		else if(iParamV == 46) _paramValue = "65";
  		else if(iParamV == 47) _paramValue = "2.2";
  		else if(iParamV == 48) _paramValue = "3";
  		else if(iParamV == 49) _paramValue = "3.8";
  		else if(iParamV == 50) _paramValue = "4.5";
  		else if(iParamV == 51) _paramValue = "5.5";
  		else if(iParamV == 52) _paramValue = "4";
  		else if(iParamV == 53) _paramValue = "5";
  		else if(iParamV == 54) _paramValue = "40";
  		else if(iParamV == 55) _paramValue = "48";
  		else if(iParamV == 56) _paramValue = "55";
  		else if(iParamV == 57) _paramValue = "70";
  		else if(iParamV == 58) _paramValue = "75";
  		else if(iParamV == 59) _paramValue = "80";
  		else if(iParamV == 60) _paramValue = "85";
  		else if(iParamV == 61) _paramValue = "90";
  		else if(iParamV == 62) _paramValue = "95";
  		else if(iParamV == 63) _paramValue = "100";
	return 1;
  	case 600:
  		_paramSect = _type + "/Common";
  		_paramName = "SVRVoltage";
  	return 1;
  	case 601:
  		_paramSect = _type + "/Common";
  		_paramName = "BurningTime";
  	return 1;
  	case 602:
  		_paramSect = _type + "/Common";
  		_paramName = "BurningZDistance";
  	return 1;
  	case 603:
  		_paramSect = _type + "/Common";
  		_paramName = "CuttingZDistance";
  	return 1;
//  	case 604:
//		_paramName = _type + "/Common/IgnitionZDistance";
//	return 1;
  	case 605:
//  		_paramName = _type + "/Common/CuttingZDistance";
//	return 1;
  	case 502:
  	case 506:
  	case 604:
  	return 0;
  };
  return -1;
};

int CorrectZDistances(QMap<QString, QPair <QString, QString> >& _comMap){
	double zDistance = _comMap["CuttingZDistance"].second.toDouble();
	//qDebug() << zDistance;
	//qDebug() << QString("%1").arg(zDistance * _comMap["BurningZDistance"].second.toDouble() / 100);
	//_comMap[_type + "/Common/IgnitionZDistance"] = QString("%1").arg(zDistance * _comMap[_type + "/Common/IgnitionZDistance"].toDouble() / 100);
	_comMap["BurningZDistance"].second = QString("%1").arg(zDistance * _comMap["BurningZDistance"].second.toDouble() / 100);
	return 1;
}

int PutConstInFile(QString _fname, QMap<QString, QPair<QString,QString>>& _comMap){
  CIniFile cutIni(_fname.toStdString(), -1);
  if (!cutIni.ReadFile(_fname.toStdString()))
	{
	  fprintf(stdout, "%s\n", "Unable read ini file 'techparams.ini'");
	  return 1;
	}
  for (int i = 0; i < _comMap.size(); i++){
	  string sect = _comMap.values().at(i).first.toStdString();
	  //qDebug() << _comMap.values().at(i).first;
	  string name = _comMap.keys().at(i).toStdString();
	  //qDebug() << _comMap.keys().at(i);
	  string value = _comMap.values().at(i).second.toStdString();
	  //qDebug() << _comMap.values().at(i).second;
	  cutIni.SetValue(sect, name, value);
  };
  if (!cutIni.WriteIniFile())
 	{
 	  fprintf(stdout, "%s\n", "Unable save ini file 'techparams.ini'");
 	  return 1;
 	}
  return 0;
}


int ParseCuttingParams(QString fileName, QMap<QString, QPair<QString,QString>>& _comMap,  QString _type, QString _command){
  QStringList params = _command.split(",");
//  qDebug() << params;
  QString paramName;QString paramValue;QString paramSect;
  for (int i = 0; i < params.size(); i++){
//    qDebug() << params[i];
    int indx = params[i].indexOf("=");
    paramName = params[i].left(indx);
//    qDebug() << paramName;
    paramValue = params[i].right(params[i].size() - (indx + 1));
//    qDebug() << paramValue;
    int res = ConvertParams(_type, paramSect, paramName, paramValue);
    if(res == -1){
      printf("ERROR: parse parameter name = %s, value = %s\n"
    		  , params[i].left(indx - 1).toStdString().c_str()
    		  , params[i].right(params[i].size() - (indx + 1)).toStdString().c_str());
      return 0;
    }else if (res == 1){
       //qDebug() << paramName;
       //qDebug() << QPair<QString,QString>(paramSect, paramValue);
       _comMap.insert(paramName, QPair<QString,QString>(paramSect, paramValue));
    }
  }
  CorrectZDistances(_comMap);
  PutConstInFile(fileName,_comMap);
  return 1;
};

int
main(int argc, char *argv[])
{
  QString fileName, type, smask, command;
  QMap<QString, QPair<QString, QString>> comMap;
  for (int i = 1; i < argc; i++)
    {
      if (QString(argv[i]) == "-f" && i + 1 < argc)
        {
          fileName = argv[i + 1];
        }

      if (QString(argv[i]) == "-t" && i + 1 < argc)
        {
          type = argv[i + 1];
        }
      if (QString(argv[i]) == "-m" && i + 1 < argc)
        {
          smask = argv[i + 1];
        }
      if (QString(argv[i]) == "-c" && i + 1 < argc)
		{
    	  command = argv[i + 1];
		}

    }
  if (command.size() > 0){
	return ParseCuttingParams(fileName, comMap, type, command);
  }

  if (smask.size() > 0)
    {
      return ReloadCuttingParams(fileName, type/*, smask.toInt()*/);
    }

  //QStringList str; str.append(".");
  QCoreApplication app(argc, argv);
  //  app.setLibraryPaths(str);
  //  app.addLibraryPath("./libs");
  //  app.addLibraryPath(".");
  //qDebug()<<"my library path : "<< app.libraryPaths();
  //
  //  QLibrary sqlib("./libs/libqsqlite.so");
  //  sqlib.load();
  //  //qDebug()<<"my library loaded"<<sqlib.isLoaded();

  QFile logFile("logs/dbclient.log");
  logFile.open(QIODevice::WriteOnly);

  QTextStream out(&logFile);
  out.setCodec(QTextCodec::codecForName("UTF-8"));

  if (type.isEmpty() || !QFile::exists(fileName))
    {
      out << "missing parameters:\n";
      if (type.isEmpty())
        out << "type (-t)\n";
      if (!QFile::exists(fileName))
        out << "file (-f)\n";

      return -1;
    }
  CXParamData::open(fileName);

  KeyValueMap keys = CXParamData::getValues(type + "/Keys");
  CXParamData::deleteKeys(QStringList() << type);
  /**/
  QStringList allKeys;
  allKeys <<  "Source/Keys" << "MetallType/Keys" << "Thickness/Keys" << "Power/Keys" << "GasTypes/Keys" << "ConsAngles/Keys" << type + "/Common";
  CXParamData::deleteKeys(allKeys);
  /**/
  CXBaseClient client;
  KeyValueMap dataBase = CXParamData::getValues("Database");
  QString dbFileName =  dataBase.value("name");
  QString resString = client.connectToDataBase(dataBase.value("hosts"), dataBase.value("name"),
      dataBase.value("port").toInt(), dataBase.value("user"), dataBase.value("password"));

  if (!resString.isEmpty())
    {
      out << "connection error:\n";
      out << resString;
      out << "\n";

      return -1;
    }
  /*
   QString curKey = "Manufactor";
   KeyValueList availableKeys = client.execute("tbl_manufacturers", "id, name",
   "", "name");

   int res = check(availableKeys, curKey, keys, type);
   if (res <= 0)
   {
   if (res < 0)
   out << QString("%1: available keys are empty\n").arg(curKey);
   else
   out
   << QString("wrong key: %1-%2\n").arg(curKey).arg(
   keys.value(curKey));

   return res;
   }
   /**/
  /**/
  QString curKey = "Source";
  KeyValueList availableKeys = client.execute("tbl_plasma_sources", "id, name", "", "name");

  int res = check(availableKeys, curKey, keys, type);
  if (res <= 0)
    {
      if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
      else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

      return res;
    }

  curKey = "MetallType";
  QString w = QString("plasma_source=%1").arg(keys.value("Source"));
  availableKeys = client.execute("tbl_plasma_metal_types as a, tbl_plasma_params as b", "DISTINCT metal_type, a.name", w + " AND metal_type=a.id", "a.name");

  res = check(availableKeys, curKey, keys, type);
  if (res <= 0)
    {
      if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
      else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

      return res;
    }

  curKey = "Thickness";
  w += QString(" AND metal_type=%2").arg(keys.value("MetallType"));
  availableKeys = client.execute("tbl_plasma_params", "DISTINCT min_thickness, min_thickness", w, "min_thickness");

  res = check(availableKeys, curKey, keys, type);
  if (res <= 0)
    {
      if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
      else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

      return res;
    }

  curKey = "Power";
  w += QString(" AND max_thickness=%1").arg(keys.value("Thickness"));
  availableKeys = client.execute("tbl_plasma_params", "DISTINCT amperage, amperage", w, "amperage");

  res = check(availableKeys, curKey, keys, type);
  if (res <= 0)
    {
      if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
      else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

      return res;
    }

  curKey = "GasTypes";
  w += QString(" AND amperage=%1").arg(keys.value("Power"));
  availableKeys = client.execute("tbl_gas_types as a, tbl_plasma_params as b", "DISTINCT b.gases, a.gases", w + " AND b.gases=a.id", "a.gases");

  res = check(availableKeys, curKey, keys, type);
  if (res <= 0)
    {
      if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
      else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

      return res;
    }

  curKey = "ConsAngles";
  w += QString(" AND gases=%1").arg(keys.value("GasTypes"));
  availableKeys = client.execute("tbl_cons_angles as a, tbl_plasma_params as b", "DISTINCT b.cons_angle, a.name", w + " AND b.cons_angle=a.id", "a.name");

  res = check(availableKeys, curKey, keys, type);
  if (res <= 0)
    {
      if (res < 0) out << QString("%1: available keys are empty\n").arg(curKey);
      else out << QString("wrong key: %1-%2\n").arg(curKey).arg(keys.value(curKey));

      return res;
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
  columnValuesMap.insert("out_ignition_distance", "IgnitionZDistance");
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
  /**/
  CXParamData::close();
  return 0;

}
