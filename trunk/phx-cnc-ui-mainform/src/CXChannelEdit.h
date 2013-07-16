#ifndef CXCHANNELEDIT_H
#define CXCHANNELEDIT_H

#include <QDialog>
#include "ui_CXChannelEdit.h"

#include "SXChannelData.h"

/*!
 Класс для редактирования данных канала устройства.
 */
class CXChannelEdit : public QDialog, public Ui::CXChannelEdit
{
Q_OBJECT

public:
  //! Конструктор.
  CXChannelEdit(QWidget* parent = 0);

  //! Деструктор.
  virtual ~CXChannelEdit();

  /*!
   Функция установки объекта канала для редактирования.
   \param aData - экземпляр объект канала.
   */
  void
  setData(const SXChannelData& aData);

  /*
   Функция получения редактируемого объекта канала.
   \return Экземпляр объект канала с новыми данными.
   */
  const SXChannelData&
  getData();

  /*!
   Функция установки данных для секций и наименований.
   \param aSectionsMap - карта связей между секцией и наименованиями.
   */
  void
  setSectionData(const QMap<QString, QString>& aSectionsMap);

public slots:
  //! Переопределенный слот применения изменений.
  virtual void
  accept();

private slots:
  //! Слот на изменение текущей секции.
  void
  onSectionChange();

  //! Слот на изменение текущего имени.
  void
  onNameChange();

private:
  SXChannelData mChannelData;
  QMap<QString, QString> mSectionsMap;
};

#endif // CXCHANNELEDIT_H
