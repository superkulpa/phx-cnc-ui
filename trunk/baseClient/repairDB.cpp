#include <QApplication>
#include <QtCore/QTextStream>
#include <QtCore/QFile>

int repairDB(QTextStream& _out, const QString& _fileName, const QString& type){
	//QString fileName = QApplication::applicationDirPath() + _fileName;
	_out << "Repair DB " << _fileName;

  QFile::remove(_fileName);
  QFile::copy(QApplication::applicationDirPath() + "/db/techparams.ini", _fileName);
  return 0;
}
