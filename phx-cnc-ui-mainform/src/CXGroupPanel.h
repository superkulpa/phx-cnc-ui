#ifndef CXGROUPPANEL_H
#define CXGROUPPANEL_H

#include "AXBaseWindow.h"

#include <QtGui/QPushButton>

/*!
 Класс панели для группы с функциональными клавишами F1-F12.
 */
class CXGroupPanel : public AXBaseWindow
{
Q_OBJECT

public:
  //! Конструктор.
  CXGroupPanel();

  //! Деструктор.
  virtual ~CXGroupPanel();

  //! Установка названий для кнопок.
  void
  setButtonsText(const QStringList& aTexts);

  //! Установка названия для кнопоки.
  void
  setButtonText(int aButtonNumber, const QString& aText);

  //! Получение кнопки по индексу.
  QPushButton*
  getButton(quint8 aButtonNumber);

public slots:
  //! Слот на показ нужной группы.
  void
  setGroup();

  //! Слот запуска fm.sh по кнопке "Каталог".
  void
  directoryCommand();

  //! Слот запуска macro.sh по кнопке "Макро".
  void
  macroCommand();

  void
  macroCommand2();

  //! Слот на выход.
  void
  onExit();

  //! Слот на показ группы настройки устройств.
  void
  onDeviceEditShow();

  //! Слот на сокрытие группы настройки устройств.
  void
  onDeviceEditHide();

private:
  QList<QPushButton*> mButtonsList;
};

#endif // CXGROUPPANEL_H
