/*
 * combinePlasmaSourceCommand.cpp
 *
 *  Created on: Feb 12, 2015
 *      Author: kulpanov
 */
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

#include "utils/iniFile.h"

using namespace std;
///
class CCombinePlasmaSourceCommand{
public:
  QTextStream& out;
  CIniFile cutIni;
  QMap<QString, QString> gasId;

  int AddParam(QString& _cmd, const QString& _fname, const string& _s_name, const string& _v_name){

    int res = cutIni.GetValueI(_s_name, _v_name, -1);
    if(res == -1){
      out << "Cannot find parameter Power" << _fname;
      return 1;
    }else _cmd += (QString().number(res) + " ");
    return 0;
  }

  QString GetGasId(QString & _gasName){
    return gasId.value(_gasName);
  }

  int CombineCommand(const QString& _fname, const QString&  _type){
    cutIni = CIniFile(_fname.toStdString(), -1);
    if (!cutIni.ReadIniFile())
    {
      out << "Unable read ini file" << _fname;
      return 1;
    }
    QString cmd = "095 ";

    string name = _type.toStdString() + "/Common";

    if(AddParam(cmd, _fname, name, "Power") != 0) return 1;

    cmd += "100 ";//current corner percent
    string tmpName = "GasTypes/Keys";
    QString gases = QString::fromStdString(cutIni.GetValue("GasTypes/Keys", "Keys", "noValue"));
    if(gases == "noValue"){
	out << "Cannot find parameter GasTypes" << _fname;
	return 1;
    };

    QStringList lGases = gases.split("/");
    cmd += GetGasId(lGases[0]) + " ";
    cmd += GetGasId(lGases[1]) + " ";

    if(AddParam(cmd, _fname, name, "Gas1CutflowRate") != 0) return 1;
    if(AddParam(cmd, _fname, name, "Gas1PreflowRate") != 0) return 1;
    if(AddParam(cmd, _fname, name, "Gas2CutflowRate") != 0) return 1;
    if(AddParam(cmd, _fname, name, "Gas2PreflowRate") != 0) return 1;
    if(AddParam(cmd, _fname, name, "Mixes1") != 0) return 1;
    if(AddParam(cmd, _fname, name, "Mixes2") != 0) return 1;

    tmpName = _type.toStdString() + "/Command";
    cutIni.SetValue(tmpName,"cmd",cmd.toStdString(),true);//если что создаем


    if (!cutIni.WriteIniFile())
    {
      out << "Unable save ini file " << _fname;
      return 1;
    }
    return 0;
  }

  //
  CCombinePlasmaSourceCommand(QTextStream& _out):
    out(_out){
    gasId.insert("Nogas","0");
    gasId.insert("O2"	,"1");
    gasId.insert("CH4"	,"2");
    gasId.insert("H35"	,"3");
    gasId.insert("H5"	,"4");
    gasId.insert("Air"	,"5");
    gasId.insert("N2"	,"6");
    gasId.insert("Ar"	,"7");
    gasId.insert("F5"	,"8");
  }
};


int combinePlasmaSourceCommand(QTextStream& _out, const QString& _fileName, const QString& _type){

  CCombinePlasmaSourceCommand psCommand(_out);

  int res = psCommand.CombineCommand(_fileName, _type);

  return res;
}


