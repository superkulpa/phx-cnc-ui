#ifndef CXCAMERAWIDGET_H
#define CXCAMERAWIDGET_H

#include "AXBaseWindow.h"

#include <QCamera>

#include "ui_CXCameraWidget.h"

/*!
 Класс окна для показа видео с камеры.
 */
class CXCameraWidget : public AXBaseWindow, public Ui::CXCameraWidget
{
	Q_OBJECT

public:
  //! Конструктор.
  CXCameraWidget();

  //! Деструктор.
  virtual ~CXCameraWidget();

private slots:
  //! Слот обновления списка доступных камер.
  void updateDevices();

  //! Слот для установки текущей камеры.
  void setCurrentCamera(int aIndex);

  //! Слот отображения ошибок при инициализации камеры.
  void displayCameraError();

  void onStateChange(QCamera::State state);

private:
  QCamera* mCamera;
};

#endif // CXCAMERAWIDGET_H
