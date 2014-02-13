#ifndef CXUTILSWINDOW_H
#define CXUTILSWINDOW_H

#include "AXBaseWindow.h"

#include <QTreeWidget>

#include "utils/CXProcess.h"

/*!
 Класс окна для утилит.
 */
class CXUtilsWindow : public AXBaseWindow
{
Q_OBJECT

public:
  //! Конструктор.
  CXUtilsWindow();

  //! Деструктор.
  virtual ~CXUtilsWindow();

private:
  /*!
   Функция загрузки данных из файла.
   \param aFileName - имя файла.
   */
  void
  load(const QString& aFileName);

private slots:
  //! Слот выполнения комманды.
  void
  onExecute();

  //! Слот завершения процесса компиляции файла пути.
  void
  onProcessFinish(int aExitCode, QProcess::ExitStatus aExitStatus);

  //! Слот на ошибки процесса компиляции файла пути.
  void
  onProcessError(QProcess::ProcessError aError);

private:
  QTreeWidget* mTreeWidget;
  CXProcess* mProcess;
};

#endif // CXUTILSWINDOW_H
