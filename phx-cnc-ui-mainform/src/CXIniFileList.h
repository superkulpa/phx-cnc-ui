#ifndef CXINIFILELIST_H
#define CXINIFILELIST_H

#include <QFileSystemModel>

#include "AXBaseWindow.h"
#include "ui_CXIniFileList.h"

/*!
 Класс списка ini-файлов.
 */
class CXIniFileList : public AXBaseWindow, public Ui::CXIniFileList
{
Q_OBJECT

public:
  //! Конструктор.
  CXIniFileList();

  //! Деструктор.
  virtual ~CXIniFileList();

public slots:
  //! Слот на открытие файла.
  void
  onOpenFile();

  void onDownList();

  void onUpList();
signals:
  //! Сигнал на открытие файла.
  void
  fileOpened(const QString& aFileName);

  //! Сигнал на сохранение изменений в файле.
  void
  fileSaved();

private:
  QModelIndex setCurrentItemToFirst();

  QFileSystemModel* mModel;
};

#endif // CXINIFILELIST_H
