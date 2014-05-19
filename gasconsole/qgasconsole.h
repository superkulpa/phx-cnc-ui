#ifndef QGASCONSOLE_H
#define QGASCONSOLE_H

#include <QDialog>

namespace Ui {
class QGasConsole;
}

class QGasConsole : public QDialog
{
    Q_OBJECT
    
public:
    explicit QGasConsole(QWidget *parent = 0);
    ~QGasConsole();
    
private:
    Ui::QGasConsole *ui;
};

#endif // QGASCONSOLE_H
