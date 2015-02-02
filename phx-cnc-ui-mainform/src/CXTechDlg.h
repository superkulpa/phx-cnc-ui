#ifndef CXTECHDLG_H
#define CXTECHDLG_H

#include <QtGui/qcheckbox.h>
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
  QHBoxLayout* horizontalLayout;
  QList<QCheckBox*> ckBox;
public:
  typedef std::pair<QString, QString > MTechsItem;
  typedef std::map<QString, QString > MTechs;
  typedef std::map<QString, int > MSupps;
  typedef std::map<QString, bool > MOpts;
public:

  //! Конструктор.
  CXTechDlg(QObject* _master, const MTechs& _techs, const MTechs& _opts);
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
  //
  void setOptions(QString opt_name, int value);
public:
  ///
  static CXTechDlg* create(QObject* _master, const MTechs& _techs, const MTechs& _opts, const char* _member);
  ///
  static CXTechDlg* getInstance();
};

#endif // CXTURNDIALOG_H
