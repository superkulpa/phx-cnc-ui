#ifndef CXOperDIRECTIONDIALOG_H
#define CXOperDIRECTIONDIALOG_H

#include "AXBaseWindow.h"

#include "ui_CXOperDirectionDialog.h"

class CXUdpManager;

/*!
 Класс диалога указания типа смещения (абсолютное, относительное).
 */
class CXOperDirectionDialog : public AXBaseWindow, public Ui::CXOperDirectionDialog
{
Q_OBJECT

public:
  //! Конструктор.
  CXOperDirectionDialog(QWidget *parent = 0);

  //! Деструктор.
  virtual ~CXOperDirectionDialog();

  //! Получение координат.
  QPointF
  getPosition();

private slots:
  //! Слот абсолютного смещение.
  void
  onAbsolute();

  //! Слот относительного смещения.
  void
  onRelative();

  /*!
   Слот обработки нажатий на виртуальную клавиатуру.
   */
  void
  onButtonClicked();

  //! Слот переезда в кадр.
  void
  onStepMove();

  //! Слот установки в кадр.
  void
  onStepSet();

  //! Слот переезда в пробивку.
  void
  onBurnMove();

  //! Слот установки в пробивку.
  void
  onBurnSet();

};

#endif // CXOperDIRECTIONDIALOG_H
