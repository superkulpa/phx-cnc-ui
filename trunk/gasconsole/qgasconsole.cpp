#include "qgasconsole.h"
#include "ui_qgasconsole.h"

QGasConsole::QGasConsole(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QGasConsole)
{
    ui->setupUi(this);
}

QGasConsole::~QGasConsole()
{
    delete ui;
}
