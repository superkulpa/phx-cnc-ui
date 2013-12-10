#include "CXProcess.h"

#include <QProcess>

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
  QProcess::start(aProgram);
}

int
CXProcess::execute(const QString& aProgram)
{
  return QProcess::execute(aProgram);
}
