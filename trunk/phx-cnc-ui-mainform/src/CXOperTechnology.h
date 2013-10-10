#ifndef CXOperSETTINGS_H
#define CXOperSETTINGS_H

#include "AXBaseWindow.h"

#include <QPushButton>
#include <QLabel>

#include "ui_CXOperTechnology.h"

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

private:
  CXTouchButton *mTButton;
  CXTouchButton *mZHButton;

  QList<CXTouchButton*> mbStateSup;
  QList<QLabel*> mSVRZ;
  QList<CXTouchButton*> mbStateZ;

};

#endif // CXOperSETTINGS_H
