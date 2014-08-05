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


///
class CG59Parser{
public:
  QTextStream& out;

  int ConvertParams(QString _type, QString& _paramSect, QString& _paramName, QString& _paramValue){
    int intParamN = _paramName.toInt();
    int iParamV = _paramValue.toInt();
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
      else if(iParamV == 6) _paramValue = "Copper";
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
      else if(iParamV == 35) _paramValue = "16";
      else if(iParamV == 36) _paramValue = "19";
      else if(iParamV == 37) _paramValue = "22";
      else if(iParamV == 38) _paramValue = "25";
      else if(iParamV == 39) _paramValue = "29";
      else if(iParamV == 40) _paramValue = "32";
      else if(iParamV == 41) _paramValue = "35";
      else if(iParamV == 42) _paramValue = "38";
      else if(iParamV == 43) _paramValue = "45";
      else if(iParamV == 44) _paramValue = "50";
      else if(iParamV == 45) _paramValue = "60";
      else if(iParamV == 46) _paramValue = "64";
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
      else if(iParamV == 64) _paramValue = "105";
      else if(iParamV == 65) _paramValue = "110";
      else if(iParamV == 66) _paramValue = "115";
      else if(iParamV == 67) _paramValue = "120";
      else if(iParamV == 68) _paramValue = "125";
      else if(iParamV == 69) _paramValue = "130";
      else if(iParamV == 70) _paramValue = "135";
      else if(iParamV == 71) _paramValue = "140";
      else if(iParamV == 72) _paramValue = "145";
      else if(iParamV == 73) _paramValue = "150";
      else if(iParamV == 74) _paramValue = "155";
      else if(iParamV == 75) _paramValue = "160";
      else if(iParamV == 76) _paramValue = "165";
      else if(iParamV == 77) _paramValue = "170";
      else if(iParamV == 79) _paramValue = "180";
      else if(iParamV == 80) _paramValue = "185";
      else if(iParamV == 81) _paramValue = "190";
      else if(iParamV == 82) _paramValue = "195";
      else if(iParamV == 83) _paramValue = "200";
      else if(iParamV == 84) _paramValue = "215";
      else if(iParamV == 85) _paramValue = "230";
      else if(iParamV == 86) _paramValue = "240";
      else if(iParamV == 87) _paramValue = "255";
      else if(iParamV == 88) _paramValue = "265";
      else if(iParamV == 89) _paramValue = "280";
      else if(iParamV == 90) _paramValue = "290";
      else if(iParamV == 91) _paramValue = "305";
      else if(iParamV == 92) _paramValue = "9";
      else if(iParamV == 93) _paramValue = "15";
      else if(iParamV == 94) _paramValue = "28";
      else if(iParamV == 95) _paramValue = "44";
      else if(iParamV == 96) _paramValue = "58";
      else if(iParamV == 97) _paramValue = "65";
      else if(iParamV == 98) _paramValue = "23";
      else if(iParamV == 99) _paramValue = "36";
      else if(iParamV == 100) _paramValue = "0.55";
      else if(iParamV == 101) _paramValue = "0.7";
      else if(iParamV == 102) _paramValue = "7";
      else if(iParamV == 103) _paramValue = "13";
      else if(iParamV == 104) _paramValue = "17";
      else if(iParamV == 105) _paramValue = "18";
      else if(iParamV == 106) _paramValue = "20";
      else if(iParamV == 107) _paramValue = "21";
      else if(iParamV == 108) _paramValue = "24";
      else if(iParamV == 109) _paramValue = "26";
      else if(iParamV == 110) _paramValue = "27";
      else if(iParamV == 111) _paramValue = "30";
      else if(iParamV == 112) _paramValue = "31";
      else if(iParamV == 113) _paramValue = "33";
      else if(iParamV == 114) _paramValue = "34";
      else if(iParamV == 115) _paramValue = "37";
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
      //      case 604:
      //              _paramName = _type + "/Common/IgnitionZDistance";
      //      return 1;
    case 605:
      //              _paramName = _type + "/Common/CuttingZDistance";
      //      return 1;
    case 502:
    case 506:
    case 604:
      return 0;
    };
    return -1;
  }

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
      out << "Unable read ini file" << _fname;
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
      out << "Unable save ini file " << _fname;
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
        out << QString("ERROR: parse parameter name = %0, value = %1\n")
              .arg(params[i].left(indx - 1).toStdString().c_str())
              .arg(params[i].right(params[i].size() - (indx + 1)).toStdString().c_str());
        return -1;
      }else if (res == 1){
        //qDebug() << paramName;
        //qDebug() << QPair<QString,QString>(paramSect, paramValue);
        _comMap.insert(paramName, QPair<QString,QString>(paramSect, paramValue));
      }
    }
    CorrectZDistances(_comMap);
    PutConstInFile(fileName,_comMap);
    return 0;
  }

  //
  CG59Parser(QTextStream& _out):
    out(_out){  }
};


int parseG59(QTextStream& _out, const QString& _fileName, const QString& _type, const QString& _parseArg){
  QMap<QString, QPair<QString,QString> > comMap;

  CG59Parser g59parser(_out);
  int res = g59parser.ParseCuttingParams(_fileName, comMap, _type, _parseArg);

  return res;
}
