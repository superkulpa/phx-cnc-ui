#ifndef CXOperTechnology_H
#define CXOperTechnology_H

#include <QPushButton>
#include <QLabel>

#include "AXBaseWindow.h"

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
	void
	OnTechConsole();

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

//  //! Слот на изменение скорости.
//  void
//  onVelocityChange(eVelocity aVelocity);

  //! Слот получения команды от ядра.
  void
  onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue);

  //!
  void
  onButtonCheck();

  ///Смена технологий
  void
  onTechnologyButton();

  ///Смена задания Z
	void onZTypeButton();

  ///Реакция на продолжить-прервать прогрев
  void onWarmUpConinueBreak(int _continueBreak);

  ///Смена технологии
  void onTechDlgClose(const QString& _tech);

  //обработка движения вверх/вниз
  void onZUp();
  void onZDown();
private:
  CXTouchButton *mTButton;
  CXTouchButton *mZHButton;

  CXTouchButton* zTypeBut;
  bool zMoveType;

  QList<CXTouchButton*> mbStateSup;
  QList<QLabel*> mSVRZ;
  //QList<CXTouchButton*> mbStateZ;
  QList<CXTouchButton*> mbZDown;
  QList<CXTouchButton*> mbZUp;

  CXWarmingUpDlg* warmDlg;
  //
  CXTechDlg::MSupps listOfSupps;
  CXTechDlg::MTechs listOfTechs;
  CXTechDlg::MTechs listOfOpts;
  CXTechDlg::MOpts 	currValueOpts;
  CXTechDlg::MTechs::iterator currTech;
};

#endif // CXOperSETTINGS_H
