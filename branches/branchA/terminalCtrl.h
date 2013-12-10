#ifndef TERMINAL_CTRL_H
#define TERMINAL_CTRL_H

#include <QThread>

#include "CXUdpManager.h"

/*!
 Класс терминала управления.
 */
class CTerminalCntrl : public QObject
{
Q_OBJECT

protected:
  //! Конструктор.
  CTerminalCntrl(CXUdpManager* udp);

  //! Деструктор.
  virtual ~CTerminalCntrl();
signals:
    void finished();

protected slots:
  void onStart();

private:
  QThread* thRunner;
  CXUdpManager* udp;
public:
  static CTerminalCntrl* startTerminal(CXUdpManager* udp);
};

#endif // CXTURNDIALOG_H
