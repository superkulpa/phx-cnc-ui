#ifndef CXOperTechnology_H
#define CXOperTechnology_H

#include "AXBaseWindow.h"

#include <QPushButton>
#include <QLabel>

#include "ui_CXOperTechnology.h"

#include "CXWarmingUpDlg.h"
#include "CXTechDlg.h"

/*!
 Класс настройки начальной позиции реза.
 */
class CXOperTechnology : public AXBaseWindow, public Ui::CXOperTechnology
{
Q_OBJECT
public:
  //! Конструктор.
  CXOperTechnology();

  //! Деструктор.
  virtual ~CXOperTechnology();

signals:
  void eventTechnologyChanged(const QString& _tech);

private slots:
  //!
  void
  onTClick();

  //!
  void
  onZHClick();

  //!
  void
  onStart();

  //!
  void
  onStop();

  //!
  void
  onSVR();

  void onMarkerMode();

  void
  onCutMode();

  //! Слот на изменение скорости.
  void
  onVelocityChange(eVelocity aVelocity);

  //! Слот получения команды от ядра.
  void
  onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue);

  //!
  void
  onButtonCheck();

  ///Смена технологий
  void
  onTechnologyButton();

  ///Реакция на продолжить-прервать прогрев
  void onWarmUpConinueBreak(int _continueBreak);

  ///Смена технологии
  void onTechDlgClose(const QString& _tech);

private:
  CXTouchButton *mTButton;
  CXTouchButton *mZHButton;

  QList<CXTouchButton*> mbStateSup;
  QList<QLabel*> mSVRZ;
  QList<CXTouchButton*> mbStateZ;

  CXWarmingUpDlg* warmDlg;
  //
  CXTechDlg::MSupps listOfSupps;
  CXTechDlg::MTechs listOfTechs;
  CXTechDlg::MTechs::iterator currTech;
};

#endif // CXOperSETTINGS_H
