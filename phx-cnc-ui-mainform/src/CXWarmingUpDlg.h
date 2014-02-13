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
enum EStages{
  _ticTac
 ,_continue
 ,_break
};
public:
  //! Конструктор.
  CXWarmingUpDlg(QObject* _master);
protected:
  //! Деструктор.
  virtual ~CXWarmingUpDlg();

public:
  virtual void setVisible(bool visible);
public:
  //interface methods
  void setStateWaiting(const QString &_aValue);
  void registerContinueBreak(QObject* _receiver, const char* _member);

private slots:
  void onButtonClicked();

  void onWarmProcess(int _percent);
signals:
  void postStateWaiting(int _percent);
  void postCmdWaiting(int _action);

private:

  EStages stage;
};

#endif // CXTURNDIALOG_H
