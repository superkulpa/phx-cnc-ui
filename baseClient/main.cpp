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

//
int getFromDB(QTextStream& out, const QString& fileName, const QString& type);
//
int parseG59(QTextStream& out, const QString& fileName, const QString& type, const QString& parseArg);
//
int transferToParams(QTextStream& out, const QString& fileName, const QString& type);


int
main(int argc, char *argv[])
{
//
//  QFile logFile("logs/dbclient.log");
//  logFile.open(QIODevice::WriteOnly);

  QTextStream out(stdout, QIODevice::WriteOnly);
  out.setCodec(QTextCodec::codecForName("UTF-8"));

  out << "start dbClient";

  QString fileName = "tmp/techparams.ini", type = "MPlasma", cmd = "";//-f techparams.ini -t MPlasma cmd
  QString parse_arg;
  int i = 1;
  while (i < argc)
  {
    if (QString(argv[i]) == "-f" && ++i < argc)
    {
      out << " fname:" << (fileName = argv[i]);

    }else
    if (QString(argv[i]) == "-t" && ++i < argc)
    {
      out << " type:" << (type = argv[i]);
    }else
    if (QString(argv[i]) == "-c" && ++i < argc)
    {
      parse_arg = QString(argv[i]).remove(QRegExp("[\t\n\r\'\" ]+"));
      out << " parsearg:" << parse_arg;
    }else{
    cmd += argv[i];
    cmd += ' ';//last args are cmds
    out << " " << argv[i];;
    }
    i++;
  }
  if(cmd.length() == 0) cmd = "reload ";
  out << "\n";

  QCoreApplication app(argc, argv);

  if (type.isEmpty()){
    out << "missing parameters: type (-t) isEmpty \n";
    return -1;
  }
  if (!QFile::exists(fileName)){
    out << "missing parameters: file (-f) isn't exist\n";
    return -1;
  }

  int res = 0;
  while(res == 0 && !cmd.isEmpty()){
    int pos = cmd.indexOf(' ');

    if(cmd.left(pos) == "parse"){
      res = parseG59(out, fileName, type, parse_arg);
    }else
    if(cmd.left(pos) == "reload"){
      res = getFromDB(out, fileName, type);
    }else
    if(cmd.left(pos) == "transfer"){
      res = transferToParams(out, fileName, type);
    }
    cmd.remove(0, pos<=0?0xff:pos+1);
  }
  return res;
}

//-t MPlasma -c "502=35  ,503=1   ,504=200 ,505=2   ,506=1   ,507=111 ,600=144.  ,601=2.2   ,602=400   ,603=5.08  ,604=200. " parse reload transfer
//-t MPlasma -c "502=35  ,503=1   ,504=200 ,505=2   ,506=1   ,507=111 ,600=144.  ,601=2.2   ,602=400   ,603=5.08  ,604=200. " parse reload transfer
//-t MPlasma -c "502=35  ,503=1   ,504=400 ,505=2   ,506=1   ,507=111 ,600=144.  ,601=2.2   ,602=400   ,603=5.08  ,604=200. " parse reload transfer$
