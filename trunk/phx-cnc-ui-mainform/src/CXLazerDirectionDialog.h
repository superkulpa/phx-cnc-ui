#ifndef CXLAZERDIRECTIONDIALOG_H
#define CXLAZERDIRECTIONDIALOG_H

#include <QDialog>
#include "ui_CXLazerDirectionDialog.h"

class CXUdpManager;

/*!
 Класс диалога указания типа смещения (абсолютное, относительное).
 */
class CXLazerDirectionDialog : public QDialog, public Ui::CXLazerDirectionDialog
{
Q_OBJECT

public:
  //! Конструктор.
  CXLazerDirectionDialog(QWidget *parent = 0);

  //! Деструктор.
  virtual ~CXLazerDirectionDialog();

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

public:
  CXUdpManager* mUdpManager;

};

#endif // CXLAZERDIRECTIONDIALOG_H
