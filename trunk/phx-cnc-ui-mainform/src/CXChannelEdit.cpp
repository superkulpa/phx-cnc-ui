#include "CXChannelEdit.h"

#include <QDialog>
#include <QMessageBox>

#include "iniFile.h"

CXChannelEdit::CXChannelEdit(QWidget* parent) :
    QDialog(parent)
{
  setupUi(this);
  setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);

  QRegExpValidator* validator = new QRegExpValidator(QRegExp("[^,]*"), this);

  mModifyEdit->setValidator(validator);
  mDescriptionEdit->setValidator(validator);

  connect(mSectionsList, SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem*)), this,
      SLOT(onSectionChange()));
  connect(mNamesList, SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem*)), this,
      SLOT(onNameChange()));
}

CXChannelEdit::~CXChannelEdit()
{

}

void
CXChannelEdit::setData(const SXChannelData& aData)
{
  mChannelData = aData;

  mModifyEdit->setText(mChannelData.mModify);
  mDescriptionEdit->setText(mChannelData.mDescription);

  if (!mChannelData.mSectionName.isEmpty())
  {
    mSectionsList->setCurrentRow(mSectionsMap.uniqueKeys().indexOf(mChannelData.mSectionName));
    mNamesList->setCurrentRow(
        mSectionsMap.values(mChannelData.mSectionName).indexOf(mChannelData.mValueName));
  }
  else
  {
    mSectionsList->setCurrentRow(0);
    mNamesList->setCurrentItem(NULL);
  }
}

const SXChannelData&
CXChannelEdit::getData()
{
  return mChannelData;
}

void
CXChannelEdit::setSectionData(const QMap<QString, QString>& aSectionsMap)
{
  mSectionsMap = aSectionsMap;

  mSectionsList->addItems(mSectionsMap.uniqueKeys());
}

void
CXChannelEdit::accept()
{
  if (mSectionsList->currentItem() == NULL)
  {
    QMessageBox::critical(this, trUtf8("Ошибка"), trUtf8("Выберите секцию."));

    mSectionsList->setFocus();
    return;
  }

  if (mNamesList->currentItem() == NULL)
  {
    QMessageBox::critical(this, trUtf8("Ошибка"), trUtf8("Выберите название параметра."));

    mNamesList->setFocus();
    return;
  }

  if (mModifyEdit->text().isEmpty())
  {
    QMessageBox::critical(this, trUtf8("Ошибка"), trUtf8("Введите модификатор канала."));

    mModifyEdit->setFocus();
    return;
  }

  if (mDescriptionEdit->text().isEmpty())
  {
    QMessageBox::critical(this, trUtf8("Ошибка"), trUtf8("Введите описание канала."));

    mDescriptionEdit->setFocus();
    return;
  }

  mChannelData.mModify = mModifyEdit->text();
  mChannelData.mDescription = mDescriptionEdit->text();
  mChannelData.mSectionName = mSectionsList->currentItem()->text();
  mChannelData.mValueName = mNamesList->currentItem()->text();

  QDialog::accept();
}

void
CXChannelEdit::onSectionChange()
{
  mNamesList->clear();
  if (mSectionsList->currentItem() == NULL)
    return;

  QString sectionName = mSectionsList->currentItem()->text();

  mNamesList->addItems(mSectionsMap.values(sectionName));

  if (sectionName == mChannelData.mSectionName)
  {
    mNamesList->setCurrentRow(
        mSectionsMap.values(mChannelData.mSectionName).indexOf(mChannelData.mValueName));
  }
}

void
CXChannelEdit::onNameChange()
{
  if (mNamesList->currentRow() >= 0)
  {
    QString channelsPath = QApplication::applicationDirPath() + "/jini/iochannels.ini";
    CIniFile channelsFile(channelsPath.toStdString());
    channelsFile.ReadIniFile();

    QString sectionName = mSectionsList->currentItem()->text();
    QString valueName = mNamesList->currentItem()->text();
    QString value = QString::fromStdString(
        channelsFile.GetValue(sectionName.toStdString(), valueName.toStdString()));
    value = QString::fromUtf8(value.toAscii());

    QStringList dataList = value.split(",");

    if (dataList.count() > 3)
    {
      int index = dataList.at(1).toInt();

      if (index < 0)
        return;

      mModifyEdit->setText(dataList.at(2));
      mDescriptionEdit->setText(dataList.at(3));
    }
  }
}
