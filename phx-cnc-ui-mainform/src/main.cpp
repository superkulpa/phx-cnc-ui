#include <QApplication>

#include <QVBoxLayout>
#include <QTranslator>
#include "version.h"

#include "CXWindowsManager.h"
#include "CXPathWindow.h"
#include "CXFilesList.h"
#include "CXEditPathFile.h"
#include "CXCompileEdit.h"
#include "CXIniFileEditor.h"
#include "CXIniFileList.h"
#include "CXTitleWindow.h"
#include "CXParametersWindow.h"
#include "CXOperDirectionWindow.h"
#include "CXOperTechnology.h"
#include "CXTextParameters.h"
#include "CXDeviceView.h"
#include "CXVirtualKeyboard.h"
#include "CXUdpManager.h"
#include "CXParamui.h"
#include "CXZParamui.h"
#include "CXSupports.h"

/* *
 * TODO: qForm: gasConsole: провести команды регуляции газа, проверить работу с techparams и
 * загрузки файла
 * TODO: qForm: ввести запрет загрузки УП пока не стоп
 *
 * TODO: qForm: повторный сброс аварий очищает поле аварий
 *
 * TODO: qForm: доступ разным пользователям к различным утилитам УЧПУ
 * */

#include "terminalCtrl.h"
//
#include "CXGroupPanel.h"

#include "utils/CXSettingsXML.h"

QWidget*
createUIWindow(const char* aIndex, int aGroup, QMap<QString, QWidget*>& windows)
{
  AXBaseWindow* res = NULL;
  do
  {
    if (aIndex == CXPathWindow::staticMetaObject.className())
    {
      res = new CXPathWindow();

      break;
    }
    if (aIndex == CXFilesList::staticMetaObject.className())
    {
      res = new CXFilesList();

      break;
    }
    if (aIndex == CXEditPathFile::staticMetaObject.className())
    {
      res = new CXEditPathFile();

      break;
    }
    if (aIndex == CXCompileEdit::staticMetaObject.className())
    {
      res = new CXCompileEdit();

      break;
    }
    if (aIndex == CXParamUi::staticMetaObject.className())
    {
      res = new CXParamUi();

      break;
    }
//    if (aIndex == CXZParamUi::staticMetaObject.className())
//	{
//	  res = new CXZParamUi();
//
//	  break;
//	}
    if (aIndex == CXSupportsWindow::staticMetaObject.className())
    {
      res = new CXSupportsWindow();
      break;
    }

    if (aIndex == CXParametersWindow::staticMetaObject.className())
    {
      res = new CXParametersWindow(false);

      break;
    }
    //    if (aIndex == CXIniFileEditor::staticMetaObject.className())
    //    {
    //      res = new CXIniFileEditor();
    //
    //      break;
    //    }
    //    if (aIndex == CXIniFileList::staticMetaObject.className())
    //    {
    //      res = new CXIniFileList();
    //
    //      break;
    //    }
    if (aIndex == CXOperDirectionWindow::staticMetaObject.className())
    {
      res = new CXOperDirectionWindow();

      break;
    }
    if (aIndex == CXOperTechnology::staticMetaObject.className())
    {
      res = new CXOperTechnology();

      break;
    }
    if (aIndex == CXPathWindow::staticMetaObject.className())
    {
      res = new CXPathWindow();

      break;
    }
    if (aIndex == CXTextParameters::staticMetaObject.className())
    {
      res = new CXTextParameters();

      break;
    }
  }
  while (0);

  if (res == NULL)
    return NULL;

  res->setGroupNumber(aGroup);
  windows.insertMulti(aIndex, res);

  return res;
}

CXGroupPanel*
addGroupPanel(int aGroup)
{
  CXGroupPanel* panel = new CXGroupPanel();
  panel->setGroupNumber(aGroup);

  return panel;
}

int userIsOperator = 0;


int
main(int argc, char *argv[])
{
//  fLB::FLAGS_logtostderr = 1;
//  fLI::FLAGS_v = 3;
//  google::InitGoogleLogging(argv[0]);
  VLOG(INFO) << "Start cnc-ui\n";

  QApplication app(argc, argv);
  app.setQuitOnLastWindowClosed(false);


  if(QString(getenv("USER")) == "op") userIsOperator = 1;

  QString translate = CXSettingsXML::getValue("settings.xml", "translate", "0");

  if (!translate.isEmpty())
  {
    QTranslator* translator = new QTranslator(&app);
    translator->load(
        QApplication::applicationDirPath() + QDir::separator() + "translations" + QDir::separator()
            + translate);
    app.installTranslator(translator);
  }

  QString style = CXSettingsXML::getValue("settings.xml", "style", "");

  if (!style.isEmpty())
  {
    app.setStyleSheet(style);
  }
  CXTouchButton::mDelay = CXSettingsXML::getDelay("settings.xml", "buttonDelay");
  CXTouchButton::mDelayLong = CXSettingsXML::getDelay("settings.xml", "buttonDelayLong");


  CXWindowsManager manager;
  AXBaseWindow::mManager = &manager;
  AXBaseWindow::mUdpManager = new CXUdpManager(NULL);

  /**/
  QMap<QString, QWidget*> windows;
  createUIWindow(CXParametersWindow::staticMetaObject.className(), CXWindowsManager::_wingroupParams,
      windows);

  //Создание групп окон.
  createUIWindow(CXPathWindow::staticMetaObject.className(), CXWindowsManager::_wingroupCP,
      windows);

  createUIWindow(CXFilesList::staticMetaObject.className(), CXWindowsManager::_wingroupCP,
      windows);

  createUIWindow(CXEditPathFile::staticMetaObject.className(), CXWindowsManager::_wingroupCP,
      windows);

  createUIWindow(CXCompileEdit::staticMetaObject.className(), CXWindowsManager::_wingroupCP,
      windows);

  createUIWindow(CXParamUi::staticMetaObject.className(), 1000,
      windows);

//  createUIWindow(CXZParamUi::staticMetaObject.className(), 1000,
//        windows);

  createUIWindow(CXSupportsWindow::staticMetaObject.className(), 1000,
      windows);

  createUIWindow(CXOperDirectionWindow::staticMetaObject.className(), CXWindowsManager::_wingroupOper,
      windows);
  createUIWindow(CXOperTechnology::staticMetaObject.className(), CXWindowsManager::_wingroupOper,
      windows);
  createUIWindow(CXPathWindow::staticMetaObject.className(), CXWindowsManager::_wingroupOper,
      windows);
  createUIWindow(CXTextParameters::staticMetaObject.className(), CXWindowsManager::_wingroupOper,
      windows);

  QObject::connect(windows.value("CXFilesList"),
      SIGNAL(fileManageCreated(const QString&, const QString&)),
      windows.values("CXPathWindow").first(), SLOT(load(const QString&, const QString&)));
  QObject::connect(windows.value("CXFilesList"),
      SIGNAL(fileCreated(const QString&, const QString&)),
      windows.values("CXPathWindow").at(1), SLOT(load(const QString&, const QString&)));
  QObject::connect(windows.value("CXFilesList"), SIGNAL(fileOpened(const QString&)),
      windows.value("CXEditPathFile"), SLOT(openFile(const QString&)));
  QObject::connect(windows.value("CXFilesList"), SIGNAL(compileTextChanged(const QString&)),
      windows.value("CXCompileEdit"), SLOT(setText(const QString&)));
  QObject::connect(windows.value("CXCompileEdit"), SIGNAL(error(const QString&, int)),
      windows.value("CXEditPathFile"), SLOT(onError(const QString&, int)));

  QObject::connect(windows.value("CXEditPathFile"), SIGNAL(textChanged(bool)),
      windows.value("CXFilesList"), SLOT(onTextChanged(bool)));
  QObject::connect(windows.value("CXEditPathFile"), SIGNAL(newFileCreated()),
      windows.value("CXFilesList"), SLOT(onCreateNewFile()));
  QObject::connect(windows.value("CXEditPathFile"), SIGNAL(statSaved()),
      windows.value("CXFilesList"), SLOT(onStatSave()));

  QObject::connect(windows.value("CXOperDirectionWindow"),
      SIGNAL(positionChanged(const QPointF&, bool)),
      windows.values("CXPathWindow").at(0), SLOT(setPosition(const QPointF&, bool)));

  QObject::connect(windows.value("CXOperTechnology"), SIGNAL(eventTechnologyChanged(const QString&)),
      windows.value("CXParametersWindow"), SLOT(setTechnology(const QString&)));


  //Создание функциональных панелей управления для каждой группы окон.
  {
    CXGroupPanel* curGroupPanel;
    //    case 1:

    if(NULL != (curGroupPanel = addGroupPanel(CXWindowsManager::_wingroupCP)))
    {
      QStringList texts;
      texts.append(QObject::trUtf8("Управление"));
      texts.append(QObject::trUtf8("Параметры"));
      texts.append(QString());
      texts.append(QObject::trUtf8("Клавиатура"));
      texts.append(QObject::trUtf8("Каталог"));
      texts.append(QObject::trUtf8("Макро"));
      texts.append(QObject::trUtf8("Загрузить"));
      texts.append(QObject::trUtf8("Повернуть"));
      texts.append(QObject::trUtf8(" "));
      texts.append(QObject::trUtf8("Выключение"));
      curGroupPanel->setButtonsText(texts);

      //настройка группы переключения
      curGroupPanel->getButton(0)->setProperty("groupName", CXWindowsManager::_wingroupOper);
      curGroupPanel->getButton(1)->setProperty("groupName", CXWindowsManager::_wingroupParams);

      QObject::connect(curGroupPanel->getButton(0), SIGNAL(clicked()), curGroupPanel,
          SLOT(setGroup()));
      QObject::connect(curGroupPanel->getButton(1), SIGNAL(clicked()), curGroupPanel,
		  SLOT(setGroup()));

      QObject::connect(curGroupPanel->getButton(3), SIGNAL(clicked()), &manager,
          SLOT(changeVisibleVirtualKeyboard()));
      QObject::connect(curGroupPanel->getButton(4), SIGNAL(clicked()), curGroupPanel,
          SLOT(directoryCommand()));
      QObject::connect(curGroupPanel->getButton(5), SIGNAL(clicked()), curGroupPanel,
          SLOT(macroCommand()));
      QObject::connect(curGroupPanel->getButton(6), SIGNAL(clicked()),
          windows.value("CXEditPathFile"), SLOT(onSave()));
      QObject::connect(curGroupPanel->getButton(7), SIGNAL(clicked()), windows.value("CXFilesList"),
		  SLOT(onTurn()));

      QObject::connect(curGroupPanel->getButton(9), SIGNAL(clicked()), curGroupPanel,
		  SLOT(onExit()));

      qobject_cast<CXFilesList*>(windows.value("CXFilesList"))->setButton(
          curGroupPanel->getButton(6));

    }

    if(NULL != (curGroupPanel = addGroupPanel(CXWindowsManager::_wingroupParams)))
    {
      QStringList texts;
      texts.append(QObject::trUtf8("УП"));
      texts.append(QObject::trUtf8("Управление"));
      texts.append(QString());
      texts.append(QString());
      texts.append(QString());
      texts.append(QString());
      texts.append(QString());
      texts.append(QString());
      texts.append(QObject::trUtf8("Загрузить"));
      texts.append(QObject::trUtf8("Сохранить"));
      curGroupPanel->setButtonsText(texts);

      //настройка группы переключения
      curGroupPanel->getButton(0)->setProperty("groupName", CXWindowsManager::_wingroupCP);
      curGroupPanel->getButton(1)->setProperty("groupName", CXWindowsManager::_wingroupOper);
      QObject::connect(curGroupPanel->getButton(0), SIGNAL(clicked()), curGroupPanel,
          SLOT(setGroup()));
      QObject::connect(curGroupPanel->getButton(1), SIGNAL(clicked()), curGroupPanel,
          SLOT(setGroup()));

      CXParametersWindow* parametersWindow = qobject_cast<CXParametersWindow*>(
          windows.value("CXParametersWindow"));

      QList<QPushButton*> buttons;
      for (int i = 2; i < 8; ++i)
        buttons.append(curGroupPanel->getButton(i));

      parametersWindow->setButtons(buttons);

//      QObject::connect(curGroupPanel->getButton(7), SIGNAL(clicked()), parametersWindow,
//          SLOT(showSettings()));
      QObject::connect(curGroupPanel->getButton(8), SIGNAL(clicked()), parametersWindow,
          SLOT(loadParametersFromFtp()));
      QObject::connect(curGroupPanel->getButton(9), SIGNAL(clicked()), parametersWindow,
          SLOT(saveParameters()));
    }

//    if(NULL != (curGroupPanel = addGroupPanel(CXWindowsManager::_wingroupCustom)))
//    {
//      QStringList texts;
//      texts.append(QObject::trUtf8("Параметры"));
//      texts.append(QString());
//      texts.append(QString());
//      texts.append(QString());
//      texts.append(QString());
//      texts.append(QString());
//      texts.append(QString());
//      texts.append(QString());
//      texts.append(QObject::trUtf8("Загрузить"));
//      texts.append(QObject::trUtf8("Сохранить"));
//      curGroupPanel->setButtonsText(texts);
//
//      curGroupPanel->getButton(0)->setProperty("groupName",CXWindowsManager::_wingroupParams);
//      QObject::connect(curGroupPanel->getButton(0), SIGNAL(clicked()), curGroupPanel,
//          SLOT(setGroup()));
//
//      QObject::connect(curGroupPanel->getButton(8), SIGNAL(clicked()),
//          windows.value("CXIniFileList"), SLOT(onOpenFile()));
//      QObject::connect(curGroupPanel->getButton(9), SIGNAL(clicked()),
//          windows.value("CXIniFileEditor"), SLOT(onSave()));
//
//    }

    if(NULL != (curGroupPanel = addGroupPanel(CXWindowsManager::_wingroupOper)))
    {
      QStringList texts;
      texts.append(QObject::trUtf8("УП"));
      texts.append(QObject::trUtf8("Параметры"));
      texts.append( (! userIsOperator)?QObject::trUtf8("Наладка"):QObject::trUtf8(""));
      texts.append(QObject::trUtf8("Утилиты"));
//      texts.append(QObject::trUtf8("Раскрой"));
      texts.append(QObject::trUtf8("Параметры\nреза"));
      texts.append(QString());
      texts.append(QObject::trUtf8("Сбросить\nкоординаты"));
      texts.append(QString());
      texts.append(QString());
      //texts.append(QObject::trUtf8("Настройка\nсуппорта"));
      texts.append(QObject::trUtf8("Сброс\nаварий"));
      curGroupPanel->setButtonsText(texts);

      curGroupPanel->getButton(0)->setProperty("groupName", CXWindowsManager::_wingroupCP);
      curGroupPanel->getButton(1)->setProperty("groupName", CXWindowsManager::_wingroupParams);
      QObject::connect(curGroupPanel->getButton(0), SIGNAL(clicked()), curGroupPanel,
          SLOT(setGroup()));
      QObject::connect(curGroupPanel->getButton(1), SIGNAL(clicked()), curGroupPanel,
          SLOT(setGroup()));
      if(! userIsOperator){
        curGroupPanel->getButton(2)->setProperty("groupName", CXWindowsManager::_wingroupIO);
        QObject::connect(curGroupPanel->getButton(2), SIGNAL(clicked()), curGroupPanel,
            SLOT(onDeviceEditShow()));
      }

      QObject::connect(curGroupPanel->getButton(3), SIGNAL(clicked()),
          windows.value("CXOperDirectionWindow"), SLOT(onUtils()));

      QObject::connect(curGroupPanel->getButton(4), SIGNAL(clicked())
         , windows.value("CXParamUi"), SLOT(show()));
//         , windows.value("CXSupportsWindow"), SLOT(show()));
//TODO: qForm: продумать вывод Раскроя/БД

      QObject::connect(curGroupPanel->getButton(6), SIGNAL(clicked()),
          windows.value("CXOperDirectionWindow"), SLOT(onResetCoordinates()));
//	  QObject::connect(curGroupPanel->getButton(8), SIGNAL(clicked()),
//          windows.value("CXZParamUi"), SLOT(show()));
      QObject::connect(curGroupPanel->getButton(9), SIGNAL(clicked()),
          windows.value("CXTextParameters"), SLOT(onResetAlarms()));

//      QObject::connect(curGroupPanel->getButton(8), SIGNAL(clicked()),
//          &manager, SLOT(changeVisibleVirtualKeyboardNum0()));
    }

    if(! userIsOperator)
    if(NULL != (curGroupPanel = addGroupPanel(CXWindowsManager::_wingroupIO)))
    {
      QList<QPushButton*> buttonsList;
      buttonsList << curGroupPanel->getButton(2) << curGroupPanel->getButton(3)
              << curGroupPanel->getButton(4) << curGroupPanel->getButton(5)
              << curGroupPanel->getButton(6) << curGroupPanel->getButton(7);

      CXDeviceView::loadDevices(5, buttonsList);

      QStringList texts;
      texts.append(QObject::trUtf8("Управление"));
      texts.append(QObject::trUtf8("Параметры"));
      texts.append(QObject::trUtf8("+"));
      texts.append(QObject::trUtf8("-"));
      texts.append(QObject::trUtf8("0"));
      texts.append(QObject::trUtf8("авто"));
      texts.append(QObject::trUtf8("Устройство"));
      texts.append(QObject::trUtf8("Канал"));
      texts.append(QObject::trUtf8("Загрузить"));
      texts.append(QObject::trUtf8("Сохранить"));
      curGroupPanel->setButtonsText(texts);

      curGroupPanel->getButton(0)->setProperty("groupName", CXWindowsManager::_wingroupOper);
      curGroupPanel->getButton(1)->setProperty("groupName", CXWindowsManager::_wingroupParams);
      QObject::connect(curGroupPanel->getButton(0), SIGNAL(clicked()), curGroupPanel,
          SLOT(onDeviceEditHide()));
      QObject::connect(curGroupPanel->getButton(1), SIGNAL(clicked()), curGroupPanel,
          SLOT(onDeviceEditHide()));

      CXParametersWindow* parametersWindow = qobject_cast<CXParametersWindow*>(
          windows.value("CXParametersWindow"));
      QObject::connect(curGroupPanel->getButton(8), SIGNAL(clicked()), parametersWindow,
          SLOT(loadParametersFromFtp()));
      QObject::connect(curGroupPanel->getButton(9), SIGNAL(clicked()), parametersWindow,
          SLOT(saveParametersAnyway()));
    }
    //   }
  }

  QObject::connect(windows.value("CXParamUi"), SIGNAL(iniSaved()),
        windows.value("CXParametersWindow"), SLOT(saveParametersAnyway()));

//  QObject::connect(windows.value("CXZParamUi"), SIGNAL(iniSaved()),
//        windows.value("CXParametersWindow"), SLOT(saveParametersAnyway()));
  /**/
  //Общий заголовок
  CXTitleWindow* title = new CXTitleWindow();
  QObject::connect(windows.value("CXFilesList"), SIGNAL(fileOpened(const QString&)), title,
      SLOT(onFileOpen(const QString&)));
  QObject::connect(windows.value("CXTextParameters"), SIGNAL(errorReceived(const QString&)), title,
      SLOT(onErrorReceive(const QString&)));

  //
  QObject::connect(windows.value("CXOperDirectionWindow"), SIGNAL(paramsChanged(bool , const QStringList& ))
      , windows.value("CXParametersWindow"),  SLOT(loadFiles(bool , const QStringList& )));

  manager.createKeyboards();
  //Загрузка данных о геометрии окон (обязательно только после их создания!).
  manager.load("settings.xml");
  //Установка текущей группы.
  manager.setCurrentGroup(1);

  AXBaseWindow::mUdpManager->sendCommand(Commands::MSG_SECTION_START,
      Commands::MSG_CMD_FORM_RESTART, "0");
  //	CXParametersWindow* parametersWindow = qobject_cast<CXParametersWindow*>(windows.value("CXParametersWindow"));
  //	parametersWindow->loadParametersFromFtp();

  //
  CTerminalCntrl::startTerminal(AXBaseWindow::mUdpManager);

  int ret = app.exec();
//  google::ShutdownGoogleLogging();
  return  ret;
}
