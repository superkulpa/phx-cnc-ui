#ifndef CXTURNDIALOG_H
#define CXTURNDIALOG_H

//#include <QWidget>
#include "AXBaseWindow.h"

#include "ui_CXWarmingUpDlg.h"
#include "CXUdpManager.h"

/*!
 Класс настройки поворота и мастабирования УП.
 */
class CXWarmingUpDlg : public QDialog, public Ui::WarmingUp
{
Q_OBJECT

public:
  //! Конструктор.
  CXWarmingUpDlg(QObject* _master);

  //! Деструктор.
  virtual ~CXWarmingUpDlg();

private slots:
  void onButtonClicked();

  void onWarmProcess(int _procent);

private:
  enum EStages{
    _ticTac
   ,_continue
  };
  EStages stage;
};

#endif // CXTURNDIALOG_H
