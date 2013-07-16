#ifndef CXEDITPATHFILE_H
#define CXEDITPATHFILE_H

#include "AXBaseWindow.h"

#include "ui_CXEditPathFile.h"

class CXFilesList;

/*!
 Класс окна редактора файлов с данными для построения пути реза, подсветкой синтаксиса и сохранением изменений.
 */
class CXEditPathFile : public AXBaseWindow, public Ui::CXEditPathFile
{
Q_OBJECT

public:
  //! Конструктор.
  CXEditPathFile();

  //! Деструктор.
  virtual ~CXEditPathFile();

public slots:
  /*!
   Слот установкий редактируемого файла.
   \param aFileName - путь с именем файла для редактирования.
   */
  void
  openFile(const QString& aFileName);

  //! Слот сохранения изменений в тексте файла.
  void
  onSave();

  //! Слот сохранения изменений в тексте файла с заданием имени для сохранения.
  void
  onSaveAs();

  /*!
   Слот на ошибку компиляции в строке.
   \param aText - текст ошибки.
   \param aLineNumber - номер строки с ошибкой.
   */
  void
  onError(const QString& aText, int aLineNumber);

signals:
  //! Сигнал на создание нового файла.
  void
  newFileCreated();

  //! Сигнал на изменение текста.
  void
  textChanged(bool aIsSaved = false);

  //! Сигнал на сохранение статистики.
  void
  statSaved();

private slots:
  //! Слот на изменение позиции курсора.
  void
  onCursorPositionChange();

  /*!
   Слот сохранения изменений в тексте файла с заданным именем для сохранения.
   \param aFileName - имя сохраняемого файла.
   */
  void
  onSaveAs(const QString& aFileName);

private:
  QString mFileName;
  CXFilesList* mSaveDialog;
};

#endif // CXEDITPATHFILE_H
