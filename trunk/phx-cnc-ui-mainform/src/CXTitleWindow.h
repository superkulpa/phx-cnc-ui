#ifndef CXTITLEWINDOW_H
#define CXTITLEWINDOW_H

#include "AXBaseWindow.h"

#include <QLabel>
#include <QPushButton>
#include <CXTouchButton.h>

/*!
 Класс заголовка окна.
 */
class CXTitleWindow : public AXBaseWindow
{
Q_OBJECT

public:
  CXTitleWindow();
  virtual ~CXTitleWindow();

public slots:
  /*!
   Слот на загрузку файла.
   \param aFileName - имя файла.
   */
  void
  onFileOpen(const QString& aFileName);

  /*!
   Слот на отображение ошибки.
   \param aError - текстовая строка с ошибкой.
   */
  void
  onErrorReceive(const QString& aError);

private slots:
  //! Слот на управление.
  void
  onControl();

  //! Стоп операций
  void
  onStopOperation();

  //! Слот получения команды от ядра.
  void
  onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue);

private:
  QLabel* mFileLabel;
  QLabel* mCPStateLabel;
  CXTouchButton* mStopButton;
  CXTouchButton* mControlButton;
  QString mFileName;
};

#endif // CXTITLEWINDOW_H
