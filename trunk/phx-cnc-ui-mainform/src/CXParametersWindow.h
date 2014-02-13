#ifndef CXPARAMETERSWINDOW_H
#define CXPARAMETERSWINDOW_H

#include "AXBaseWindow.h"

#include <QTabWidget>
#include <QProgressBar>
#include <QPushButton>

class CXFtp;
class CXIniFileEditor;

/*!
 Класс для отображения и редактирования параметров.
 */
class CXParametersWindow : public AXBaseWindow
{
Q_OBJECT

public:
  CXParametersWindow(bool aIsSystem);
  virtual ~CXParametersWindow();

  //! Функция установки списка кнопок, которым будут назначены имена.
  void
  setButtons(const QList<QPushButton*>& aButtons);

private:
  void
  loadGroups();
public slots:
  //! Слот загрузки файлов с данным по FTP.
  void
  loadParametersFromFtp();

  //! Слот загрузки параметров в форму.
  void
  loadParameters();

  //! Слот сохранение изменений параметров в любом случае.
  void
  saveParametersAnyway();

  //! Слот сохранение изменений параметров (не сохраняет при отсутствии изменений).
  void
  saveParameters();

  //! Слот создания вьюверов параметров.
  void
  makeTabs(bool aIsSystem);

  //! Слот установки текста в прогресс загрузки.
  void
  setProgressText(const QString& aText);

  //! Слот, вызываемый по окончанию загрузки.
  void
  onFtpSuccess(bool aIsUpload);

  //! Слот, вызываемый по ошибке ftp.
  void
  onFtpError();

  //! Слот показа настроек.
  void
  showSettings();

  void setTechnology(const QString& _tech);

signals:
  void saveParams();

protected:
  //! Функция событий таймера.
  void
  timerEvent(QTimerEvent* e);

  //! Закрыть FTP.
  void
  closeFtp();
private slots:
  //! Слот на нажатие кнопки.
  void
  buttonClicked();

  //! Слот получения команды от ядра.
  void
  onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue);

  void loadFiles(bool aIsUpload, const QStringList& files);

private:
  //! Функция загрузки данных на/с FTP-сервера.
  void
  loadFiles(bool aIsUpload);
  //! Функция очистки данных.
  void
  clearData();

  //! Функция очистки вьюверов.
  void
  clearTables();

  //! Функция обновления названия кнопок.
  void
  updateButtonsText();

private:
  QTabWidget* mTabWidget;
  QProgressBar* mProgressBar;
  CXFtp* mFtp;
  CXIniFileEditor* fileEditor;
  bool mIsSystem;
  bool mIsUpload;

  int mWaitTimer;
  int curTab;
  QString currTech;
  QList<QPushButton*> mButtons;
};

#endif // CXPARAMETERSWINDOW_H
