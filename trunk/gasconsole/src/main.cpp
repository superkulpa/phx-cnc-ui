#include <QtGui/QApplication>
#include "qgasconsole.h"
#include "CXUdpManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGasConsole::mUdpManager = new CXUdpManager(NULL);

    QGasConsole w;
    w.show();

    return a.exec();
}
