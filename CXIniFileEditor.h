#ifndef CXINIFILEEDITOR_H
#define CXINIFILEEDITOR_H

#include <QSyntaxHighlighter>
#include <QProgressBar>
#include <QFileSystemModel>

#include "AXBaseWindow.h"

#include "ui_CXIniFileEditor.h"

class CXFtp;

/*!
 Класс окна редактора ini-файлов, со списком файлов, с подсветкой синтаксиса и сохранением изменений.
 */
class CXIniFileEditor : public QWidget, public Ui::CXIniFileEditor
{
Q_OBJECT

public:
  //! Конструктор.
  CXIniFileEditor();

  //! Деструктор.
  virtual ~CXIniFileEditor();

public slots:
  /*!
   Слот выбора файла из списка на редактирование.

   \param aFileName - имя выбранного файла.
   */
  void
  onOpenFile(const QString& aFileName);

  //! Слот сохранения изменений в тексте файла.
  void
  onSave();

  //! Функция загрузки данных на/с FTP-сервера.
  void
  reloadFiles();

public slots:
  //! Слот на открытие файла.
  void
  onOpenFile();

  void
  onItemActivate(const QModelIndex&);

signals:
  //! Сигнал на открытие файла.
  void
  fileOpened(const QString& aFileName);

  //! Сигнал на сохранение изменений в файле.
  void
  fileSaved();


public:
  const QString getFName(){return mFileName;}

private:
  QFileSystemModel* mModel;

private:
  QString mFileName;
  QSyntaxHighlighter* mHighlighter;

//  bool mIsUpload;
//  QProgressBar* mProgressBar;
//  CXFtp* mFtp;
};

#endif // CXINIFILEEDITOR_H
