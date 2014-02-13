#ifndef CXOperFeedDlg_H
#define CXOperFeedDlg_H

#include <QDialog>
#include "ui_CXOperFeedDlg.h"
#include "utils/iniFile.h"

class CXUdpManager;

/*!
 Класс диалога указания типа смещения (абсолютное, относительное).
 */
class CXOperFeedDlg : public QDialog, public Ui::CXOperFeedDlg
{
Q_OBJECT
CIniFile iniFile;
//int feeds[3];
protected:
  //! Конструктор.
  CXOperFeedDlg(QWidget *parent);

  //! Деструктор.
  virtual ~CXOperFeedDlg();
private slots:
  /*!
   Слот обработки нажатий на виртуальную клавиатуру.
   */
  void
  onButtonClicked();
private:
  virtual void accept();
public:
  static int createAndGetFeedDlg(QWidget *parent);
};

#endif // CXOperDIRECTIONDIALOG_H
