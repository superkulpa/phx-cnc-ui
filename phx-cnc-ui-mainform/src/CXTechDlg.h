#ifndef CXTECHDLG_H
#define CXTECHDLG_H

//#include <QWidget>
#include "AXBaseWindow.h"

#include "ui_CXTechDlg.h"
#include "CXUdpManager.h"
#include "CXTouchButton.h"

/*!
 Класс настройки поворота и мастабирования УП.
 */
class CXTechDlg : public QDialog, public Ui::dlgTechnology
{
Q_OBJECT
  QList<CXTouchButton*> btnList;
public:
  typedef std::pair<QString, QString > MTechsItem;
  typedef std::map<QString, QString > MTechs;
  typedef std::map<QString, int > MSupps;

public:
  //! Конструктор.
  CXTechDlg(QObject* _master, const MTechs& _techs);
protected:
  //! Деструктор.
  virtual ~CXTechDlg();


private slots:
  void onButtonClicked();

signals:
  void postTechnology(QString _tech);

public:
  //interface methods
  void registerTechnology(QObject* _receiver, const char* _member);
public:
  ///
  static CXTechDlg* create(QObject* _master, const MTechs& _techs, const char* _member);
  ///
  static CXTechDlg* getInstance();
};

#endif // CXTURNDIALOG_H
