#include "CXParamui.h"

#include <QProcess>
#include <QFile>
#include <QTimer>
#include <QtGui/qmessagebox.h>
#include <QLineEdit>
#include <QKeyEvent>
#include <qdebug.h>

#include "utils/CXParamData.h"
#include "CXUdpManager.h"

#define INI_PATH "techparams.ini"
#define XML_PATH "settings.xml"

CXParamUi::CXParamUi() :
    AXBaseWindow()
{
  //TODO: qForm.2 mType брать из тек технологии
  mType = "MPlasma";
  ui.setupUi(this);
  //ui.mValuesLayout->setObjectName(QString::fromUtf8("mValuesLayout"));

  if (!QFile::exists(INI_PATH))
  {
    QFile iniFile(INI_PATH);
    iniFile.open(QIODevice::WriteOnly);
    iniFile.close();
  }
  ui.mValuesScroll->setWidgetResizable(true);

  QWidget* valueWidget = new QWidget(ui.mValuesScroll);
  valueWidget->setObjectName("valueWidget");
  ui.mValuesScroll->setWidget(valueWidget);

  mValuesLayout = new QGridLayout(valueWidget);
  readKeys();

  connect(ui.mRestoreButton, SIGNAL(clicked()), this, SLOT(updateData()));
  connect(ui.mAcceptButton, SIGNAL(clicked()), this, SLOT(save()));

  connect(ui.mButton0, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton1, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton2, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton3, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton4, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton5, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton6, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton7, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton8, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButton9, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButtonBackspace, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButtonDel, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(ui.mButtonDot, SIGNAL(clicked()), this, SLOT(onButtonClicked()));

  registerManager();
}

CXParamUi::~CXParamUi()
{
}

void
CXParamUi::readKeys()
{
  mKeyList.clear();
  clearLayout(ui.mKeysLayout);

  CXParamData::open(INI_PATH);
  QMap<QString, QString> keys = CXParamData::getKeys(mType);
  QMap<QString, QString> fixedKeys = CXParamData::getFixedKeys(XML_PATH, mType);

  bool isUpdateNeed = false;
  bool isBreak = false;
  bool isSaveNeed = false;

  QLabel* keyCaption = NULL;
  QComboBox* keyComboBox = NULL;
  QStringList items, allKeys, keyText, keyName;

  allKeys << "Source" << "MetallType" << "Thickness" << "Power" << "GasTypes" << "ConsAngles";
  keyText << trUtf8("Выберите производителя") << trUtf8("Выберите тип металла")
      << trUtf8("Выберите толщину") << trUtf8("Выберите мощность") << trUtf8("Выберите тип газа")
      << trUtf8("Выберите угол реза");
  keyName << trUtf8("Производитель") << trUtf8("Тип металла") << trUtf8("Толщина")
      << trUtf8("Мощность") << trUtf8("Тип газа") << trUtf8("Угол реза");

  QString curKey;
  int i = 0;
  for (i = 0; i < allKeys.count() && !isBreak; i++)
  {
    curKey = allKeys.at(i);

    items = CXParamData::getKeysArray(curKey);
    if (items.isEmpty() && keys.contains(curKey))
      items.append(keys.value(curKey));

    if (items.isEmpty())
    {
      //чтобы небыло циклического обновления при отсутствии ключа.
      if (mLastUpdateKey != curKey)
        isUpdateNeed = true;
      mLastUpdateKey = curKey;
      break;
    }

    QGroupBox* keyWidget = new QGroupBox(this);

    QVBoxLayout* keyLayout = new QVBoxLayout(keyWidget);
    keyLayout->setMargin(4);

    keyCaption = new QLabel(keyName.at(i), keyWidget);
    keyLayout->addWidget(keyCaption);

    keyComboBox = new QComboBox(keyWidget);
    keyComboBox->setFocusPolicy(Qt::NoFocus);
    keyComboBox->setEditable(false);
    keyComboBox->addItems(items);

    mKeyList << keyComboBox;
    keyLayout->addWidget(keyComboBox);

    ui.mKeysLayout->addWidget(keyWidget);

    if (fixedKeys.contains(curKey))
    {
      keyComboBox->hide();

      if (!items.contains(fixedKeys.value(curKey)))
      {
        //чтобы небыло циклического обновления при отсутствии ключа.
        if (mLastUpdateKey != curKey)
          isUpdateNeed = true;
        mLastUpdateKey = curKey;
        break;
      }
      else
      {
        isSaveNeed = true;
        keyComboBox->setCurrentIndex(items.indexOf(fixedKeys.value(curKey)));
      }
    }
    else if (!keys.contains(curKey) || !items.contains(keys.value(curKey)))
    {
      keyComboBox->setCurrentIndex(-1);
      isBreak = true;
    }
    else
      keyComboBox->setCurrentIndex(items.indexOf(keys.value(curKey)));

    connect(keyComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onKeyChange()));
  }

  ui.mKeysLayout->addStretch();
  ui.mKeysBox->setEnabled(true);

  bool isValues = !CXParamData::getValues(mType + "/Common").isEmpty();

  ui.mStackWidget->setCurrentIndex(1);
  if (!isValues)
    ui.mErrorLabel->setText(keyText.at(qMax(0, i - 1)));

  if (isUpdateNeed && !isValues)
  {
    CXParamData::close(false);
    if (isSaveNeed)
      onKeyChange();
    else
      updateData();
  }
  else
  {
    setUpdatesEnabled(false);
//    clearLayout(ui.mValuesLayout);
    clearLayout(ui.mImagesLayout);

    if (!isBreak)
      readValues();

    CXParamData::close(false);

    setUpdatesEnabled(true);
    repaint();
  }
}

void
CXParamUi::readValues()
{
  QMap<QString, QString> values = CXParamData::getValues(mType + "/Common");

  if (values.isEmpty())
  {
    ui.mErrorLabel->setText(trUtf8("Не найдено записей для данного ключа."));
    ui.mStackWidget->setCurrentIndex(1);
    return;
  }

  ui.mStackWidget->setCurrentIndex(0);

  QList<SXDataXml> captions = CXParamData::getCaptions(XML_PATH, mType);

  QLabel* labelValue = NULL;
  QDoubleSpinBox* editValue = NULL;
  mEditors.clear();
  int row1 = 0;
  int row2 = 0;
  int row = 0;
  int column = 0;
  double value = 0;

  foreach (const SXDataXml& data, captions)
  {  if (values.contains(data.mName))
  {
    column = (data.mColumn > 0) ? 2 : 0;
    row = (data.mColumn > 0) ? row1++ : row2++;

    labelValue = new QLabel(data.mDescr, this);
    labelValue->setMargin(5);
    if (row % 2 == 0) labelValue->setStyleSheet("background-color: silver;");
    mValuesLayout->addWidget(labelValue, row, column);

    value = values.value(data.mName).toDouble();

    editValue = new QDoubleSpinBox(this);
    if (data.mDelta > 0)
    {
      editValue->setRange(value - data.mDelta, value + data.mDelta);
    }
    else
    editValue->setRange(0.01, 99999);
    editValue->setValue(value);

    editValue->setButtonSymbols(QAbstractSpinBox::NoButtons);
    editValue->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
    editValue->setReadOnly(data.mIsReadOnly);
    editValue->setLocale(QLocale(QLocale::English));

    editValue->setProperty("valueName", data.mName);
    mEditors.append(editValue);
    mValuesLayout->addWidget(editValue, row, column + 1);
  }
}

  QGroupBox* imageBox = NULL;
  QVBoxLayout* imageLayout = NULL;
  QList<QString> imagesGroup = CXParamData::getImages(XML_PATH, mType);
  QList<QLabel*> images;
  QSize imgSize;

  for (int i = 0; i < imagesGroup.count(); i++)
  {
    values = CXParamData::getValues(mType + "/" + imagesGroup.at(i));
    if (values.contains("image"))
    {
      imageBox = new QGroupBox();
      imageLayout = new QVBoxLayout(imageBox);
      imageLayout->setMargin(0);

      labelValue = new QLabel(this);
      labelValue->setAlignment(Qt::AlignCenter);
      QPixmap p(QApplication::applicationDirPath() + "/db/" + values.value("image"));
      imgSize.setWidth(qMax(imgSize.width(), p.width()));
      imgSize.setHeight(qMax(imgSize.height(), p.height()));
      labelValue->setPixmap(p);
      imageLayout->addWidget(labelValue);
      images.append(labelValue);

      labelValue = new QLabel(this);
      labelValue->setAlignment(Qt::AlignCenter);
      labelValue->setText(values.value("number") + "\n" + values.value("name"));
      labelValue->setStyleSheet("font-size: 9pt;");
      imageLayout->addWidget(labelValue);

      ui.mImagesLayout->addWidget(imageBox);
    }
  }

  for (int i = 0; i < images.count(); i++)
    images.at(i)->setMinimumSize(imgSize);

  ui.mImagesLayout->addStretch();

}

void
CXParamUi::clearLayout(QLayout* aLayout)
{
  QLayoutItem* child = NULL;

  while ((child = aLayout->itemAt(0)) != NULL)
  {
    if (child->widget() != NULL)
      child->widget()->deleteLater();
    if (child->layout() != NULL)
      clearLayout(child->layout());

    aLayout->removeItem(child);
  }
}

void
CXParamUi::onKeyChange()
{
  ui.mKeysBox->setEnabled(false);

  QStringList allKeys;
  QComboBox* curComboBox;
  PairsList keys;

  allKeys << "Source" << "MetallType" << "Thickness" << "Power" << "GasTypes" << "ConsAngles";

  for (int i = 0; i < ui.mKeysLayout->count(); i++)
  {
    if (ui.mKeysLayout->itemAt(i)->widget() == NULL)
      break;

    curComboBox = mKeyList.at(i);

    if (curComboBox == NULL || curComboBox->currentIndex() < 0)
      break;

    keys.append(QPair<QString, QString>(allKeys.at(i), curComboBox->currentText()));
  }

  if (!keys.isEmpty())
  {
    CXParamData::open(INI_PATH);
    CXParamData::setValues(mType + "/Keys", keys);
    CXParamData::close();
  }

  updateData();
}

void
CXParamUi::updateData()
{
  QProcess::execute(QApplication::applicationDirPath() + "/db.sh"
      , QStringList() << "-f" << INI_PATH << "-t" << mType);
  QTimer::singleShot(1, this, SLOT(readKeys()));
}

void
CXParamUi::save()
{
  PairsList values;

  foreach (QDoubleSpinBox* editor, mEditors)
  {  values << QPair<QString, QString>(editor->property("valueName").toString(), editor->text());
}

  CXParamData::open(INI_PATH);
  CXParamData::setValues(mType + "/Common", values);
  CXParamData::close(true);
  //сохраняем по файлам
//  qDebug() << mType;
//TODO: qForm.2 маску суппортов брать из тек маски технологии
//TODO: qForm.2 добавить разброс по файлам суппортов, с правильной секцией

  int res = QProcess::execute(QApplication::applicationDirPath() + "/db.sh"
      , QStringList() << "-f" << INI_PATH << "-t" << mType << " -m 1");
  if (res == 0)
  {
    //отправляем переинициализацию
    emit iniSaved();
    close();
  }
  else
  {
    //ошибка
    QMessageBox::information(NULL, trUtf8("Ошибка"), trUtf8("Не могу сохранить файлы"));
  }
}

void
CXParamUi::onButtonClicked()
{
  QAbstractButton* button = qobject_cast<QAbstractButton*>(sender());

  if (button != NULL && !button->shortcut().isEmpty())
  {
    int keyCode = button->shortcut()[0];

    QWidget* focusedWidget = focusWidget();

    QKeyEvent keyPress(QEvent::KeyPress, keyCode, Qt::NoModifier, button->shortcut().toString());
    QApplication::sendEvent(focusedWidget, &keyPress);

    QKeyEvent keyRelease(QEvent::KeyRelease, keyCode, Qt::NoModifier,
        button->shortcut().toString());
    QApplication::sendEvent(focusedWidget, &keyRelease);

    return;
  }
}
