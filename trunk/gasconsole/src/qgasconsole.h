#ifndef QGASCONSOLE_H
#define QGASCONSOLE_H

#include <QDialog>
#include "CXUdpManager.h"

namespace Ui {
class QGasConsole;
}

class QGasConsole : public QDialog
{
    Q_OBJECT

private slots:

  //! Слот получения команды от ядра.
  void
  onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue);

  void  onClose();
  void  onClear();
  void  onUpdate();
  void onTestPreFlow();
  void onTestCutFlow();
  void onPump();

public:
  void SendCommand(const QString& aCommand);
  void ParseResponseFromHPR(const QString& aValue);
public:
    explicit QGasConsole(QWidget *parent = 0);
    ~QGasConsole();

public:
    //! Статический указатель на класс работы с UDP.
    static CXUdpManager* mUdpManager;
private:
    Ui::QGasConsole *ui;
    bool startPreFlow;
    bool startCutFlow;
    bool startPumpTest;

};

#endif // QGASCONSOLE_H
