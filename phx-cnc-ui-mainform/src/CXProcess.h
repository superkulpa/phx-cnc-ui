#ifndef CXPROCESS_H
#define CXPROCESS_H

#include <QProcess>

/*!
	Класс для запуска процесса.
*/
class CXProcess: public QProcess
{
public:
	CXProcess(QObject* parent = 0);
	~CXProcess();

	void start(const QString& aProgram);

	static int execute(const QString& aProgram);
};

#endif // CXPROCESS_H
