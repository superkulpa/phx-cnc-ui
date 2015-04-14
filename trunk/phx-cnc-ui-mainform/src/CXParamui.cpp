#include "CXParamui.h"

#include <QProcess>
#include <QFile>
#include <QTimer>
#include <QtGui/qmessagebox.h>
#include <QLineEdit>
#include <QKeyEvent>
#include <qdebug.h>
#include <QProcess>

#include "utils/CXSettingsXML.h"
#include "utils/CXParamData.h"
#include "CXUdpManager.h"
#include "CXWindowsManager.h"

#define TECH_PARAMS_PATH "tmp/techparams.ini"
#define SETTINGS_PATH "settings.xml"

CXParamUi::CXParamUi() :
    AXBaseWindow()
{
  //TODO: qForm.2 mType брать из тек технологии
  mType = "MPlasma";
  ui.setupUi(this);
  //ui.mValuesLayout->setObjectName(QString::fromUtf8("mValuesLayout"));

  if (!QFile::exists(TECH_PARAMS_PATH))
  {
    QFile iniFile(TECH_PARAMS_PATH);
    iniFile.open(QIODevice::WriteOnly);
    iniFile.close();
  }
  ui.mValuesScroll->setWidgetResizable(true);

  QWidget* valueWidget = new QWidget(ui.mValuesScroll);
  valueWidget->setObjectName("valueWidget");
  ui.mValuesScroll->setWidget(valueWidget);

  mValuesLayout = new QGridLayout(valueWidget);
  readKeys();
  //readValues();

  connect(ui.mRestoreButton, SIGNAL(clicked()), this, SLOT(repairDB()));
  connect(ui.mAcceptButton, SIGNAL(clicked()), this, SLOT(save()));
  connect(ui.mLaunchGC, SIGNAL(clicked()), this, SLOT(launchGC()));


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

  connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)),
      this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));


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

  CXParamData::open(TECH_PARAMS_PATH);
  QMap<QString, QString> keys = CXParamData::getKeys(mType);
  QMap<QString, QString> fixedKeys = CXParamData::getFixedKeys(SETTINGS_PATH, mType);

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

  QList<SXDataXml> captions = CXParamData::getCaptions(SETTINGS_PATH, mType);

  QLabel* labelValue = NULL;
  QDoubleSpinBox* editValue = NULL;
  mEditors.clear();
  int row1 = 0;
  int row2 = 0;
  int row = 0;
  int column = 0;
  double value = 0;

  foreach (const SXDataXml& data, captions)
  {
  	if (values.contains(data.mName))
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
  QList<QString> imagesGroup = CXParamData::getImages(SETTINGS_PATH, mType);
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
    CXParamData::open(TECH_PARAMS_PATH);
    CXParamData::setValues(mType + "/Keys", keys);
    CXParamData::close();
  }

  updateData();
}

void CXParamUi::repairDB(){
  CXProcess::execute("db.sh"
      , QStringList() << "-f" << TECH_PARAMS_PATH << "-t" << mType << " repair");
  QTimer::singleShot(1, this, SLOT(updateData()));
}

int
CXParamUi::updateData()
{
  int res = CXProcess::execute("db.sh"
      , QStringList() << "-f" << TECH_PARAMS_PATH << "-t" << mType << " reload");
  QTimer::singleShot(1, this, SLOT(readKeys()));
  return res;
}

static QString SendToPlasmaSource(const QString& mType)
{
  CIniFile techIni = CIniFile(TECH_PARAMS_PATH, 0);
  techIni.ReadIniFile();
  string name = mType.toStdString() + "/Command";
  QString command = QString::fromStdString(techIni.GetValue(name, "cmd", ""));
//
//  if(command != "noCmd"){
//    mUdpManager->sendCommand(Commands::MSG_SECTION_GC, Commands::MSG_CMD_GC_DIRECT_CMD, command);
//  }
  return mType+","+command;
}

void CXParamUi::launchGC(){
  //выполнить
  CXProcess::startAsynchro("gc.sh");
}

void
CXParamUi::save()
{
  PairsList values;

  foreach (QDoubleSpinBox* editor, mEditors)
  {  values << QPair<QString, QString>(editor->property("valueName").toString(), editor->text());
  }

  CXParamData::open(TECH_PARAMS_PATH);
  CXParamData::setValues(mType + "/Common", values);
  CXParamData::close(true);
  QString str = "-f ";str +=TECH_PARAMS_PATH;str +=" -t ";str += mType;str +=" transfer makecmd";
  if(0 != executeDB(str))
    QMessageBox::information(NULL, trUtf8("Ошибка"), trUtf8("Не могу сохранить файлы"));
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

void
CXParamUi::setVisible(bool visible)
{
  if(visible){
    readKeys();
  }
  return AXBaseWindow::setVisible(visible);
}

//
void
CXParamUi::loadFiles(bool aIsUpload, const QStringList& files, const char *member_onFtpSuccess)
{
//  mIsUpload = aIsUpload;
//
//  mProgressBar = new QProgressBar;
//  mProgressBar->setWindowFlags(Qt::FramelessWindowHint);
//  mProgressBar->setAlignment(Qt::AlignCenter);
//  mProgressBar->setWindowModality(Qt::ApplicationModal);
//
//  QSize size = QApplication::desktop()->availableGeometry().size();
//  mProgressBar->resize(size.width() * 0.7, size.height() * 0.05);

  QString host = CXSettingsXML::getValue("settings.xml", "kernel_ip", "192.168.233.125");
  QString pswrd = CXSettingsXML::getValue("settings.xml", "ftp", "ftp");

  mFtp = new CXFtp(this);
  mFtp->setConnectData(host, 21, "ftp", pswrd);
  mFtp->setLoadFilesData(/*QApplication::applicationDirPath() + */"jini", CXFtp::remoteCatalog);
//  connect(mFtp, SIGNAL(progressMaximumChanged(int)), mProgressBar, SLOT(setMaximum(int)));
//  connect(mFtp, SIGNAL(progressValueChanged(int)), mProgressBar, SLOT(setValue(int)));
//  connect(mFtp, SIGNAL(progressTextChanged(const QString&)), this, SLOT(setProgressText(const QString&)));
  connect(mFtp, SIGNAL(allFilesIsLoaded(bool)), this, member_onFtpSuccess);
  connect(mFtp, SIGNAL(errorReceived()), this, SLOT(closeFtp()));

  if (aIsUpload)
    mFtp->onFtpUpload(QStringList() << files);
  else
    mFtp->onFtpDownload(QStringList() << files);

//  mProgressBar->show();
}

int
CXParamUi::executeDB (const QString& _values)
{
	//выполнить
	int res =  CXProcess::execute("db.sh", QStringList() << _values);
	if (res == 0)
	{
		//и закачать на УЧПУ
		loadFiles (true,
				 QStringList () << "params.ini" << "params" + mType + ".ini",
				 SLOT(onReiniCompleted(bool)));
	}
	else
	{
		mUdpManager->sendCommand (Commands::MSG_SECTION_GC,
															Commands::MSG_CMD_GC_ERROR, "error");
	}
	return res;
}

//
void CXParamUi::onCommandReceive(const QString& _sect, const QString& _cmd, const QString& _values){

  if (_sect ==  (Commands::MSG_SECTION_GC))
  do{
    if (_cmd ==  (Commands::MSG_STATE_RELOAD_PARAMS))
    {//выполнить
				int res = executeDB (_values);
    }
  }while(0);
}

//
void CXParamUi::onReiniCompleted(bool aIsUpload){
  closeFtp();
  mUdpManager->sendCommand(Commands::MSG_SECTION_PARAMS, Commands::MSG_CMD_RELOAD_PARAMS, "0");
  QString response = SendToPlasmaSource(mType);
  mUdpManager->sendCommand(Commands::MSG_SECTION_GC, Commands::MSG_CMD_GC_RELOAD, response);
}


void
CXParamUi::onClose(bool aIsUpload)
{
//    mUdpManager->sendCommand(Commands::MSG_SECTION_GC, Commands::MSG_CMD_RELOAD_PARAMS, "0");
  closeFtp();
  close();
}

void
CXParamUi::closeFtp()
{
  if(mFtp){
    QObject::disconnect(mFtp, 0, 0, 0);
    mFtp->close();
    mFtp->deleteLater();
    mFtp = NULL;
  }
}
