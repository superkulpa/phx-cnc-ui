#include <QtGui/QApplication>
#include "qgasconsole.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGasConsole w;
    w.show();
    
    return a.exec();
}
