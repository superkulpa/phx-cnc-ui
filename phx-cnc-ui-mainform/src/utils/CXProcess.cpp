#include "CXProcess.h"

#include <QDebug>
#include <QProcess>
#include <QtGui/QApplication>

CXProcess::CXProcess(QObject* parent) :
    QProcess(parent)
{
  ;
}

CXProcess::~CXProcess()
{
  ;
}

void
CXProcess::start(const QString& aProgram)
{
  QString launchCmd = QApplication::applicationDirPath() + "/" + aProgram;
  qDebug() << "CXProcess::start()" << launchCmd;
  QProcess::start(launchCmd);
}

int
CXProcess::startAsynchro(const QString& aProgram)
{
  QString launchCmd = QApplication::applicationDirPath() + "/" + aProgram;
  qDebug() << "CXProcess::startAsynchro()" << launchCmd;
  return QProcess::startDetached(launchCmd);
}

int
CXProcess::execute(const QString &program, const QStringList &arguments){
  QString launchCmd = QApplication::applicationDirPath() + "/" + program;
  qDebug() << "CXProcess::execute()" << launchCmd << " " << arguments;
  return QProcess::execute(launchCmd, arguments);
}
