#ifndef CXTITLEWINDOW_H
#define CXTITLEWINDOW_H

#include "AXBaseWindow.h"

#include <QLabel>
#include <QPushButton>

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

  //! Слот получения команды от ядра.
  void
  onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue);

private:
  QLabel* mFileLabel;
  QLabel* mCPStateLabel;
  QPushButton* mControlButton;
  QString mFileName;
};

#endif // CXTITLEWINDOW_H
