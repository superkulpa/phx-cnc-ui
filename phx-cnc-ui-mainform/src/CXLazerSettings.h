#ifndef CXLAZERSETTINGS_H
#define CXLAZERSETTINGS_H

#include "AXBaseWindow.h"

#include <QPushButton>

#include "ui_CXLazerSettings.h"

/*!
 Класс настройки начальной позиции реза.
 */
class CXLazerSettings : public AXBaseWindow, public Ui::CXLazerSettings
{
Q_OBJECT

public:
  //! Конструктор.
  CXLazerSettings();

  //! Деструктор.
  virtual ~CXLazerSettings();

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
  QButtonGroup* mCheckButtonGroup;
  QList<QLabel*> mVoltages;
};

#endif // CXLAZERSETTINGS_H
