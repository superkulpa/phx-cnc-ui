#include <QApplication>

#include <QVBoxLayout>
#include <QTranslator>

#include "CXWindowsManager.h"
#include "CXPathWindow.h"
#include "CXFilesList.h"
#include "CXEditPathFile.h"
#include "CXCompileEdit.h"
#include "CXIniFileEditor.h"
#include "CXIniFileList.h"
#include "CXTitleWindow.h"
#include "CXParametersWindow.h"
#include "CXLazerDirectionWindow.h"
#include "CXLazerSettings.h"
#include "CXTextParameters.h"
#include "CXDeviceView.h"
#include "CXVirtualKeyboard.h"
#include "CXUdpManager.h"

#include "CXGroupPanel.h"

#include "CXSettingsXML.h"

QWidget* getTestWindow(int aIndex, int aGroup)
{
	AXBaseWindow* res = NULL;

	switch (aIndex)
	{
		case 0:
		{
			res = new CXPathWindow();

			break;
		}
		case 1:
		{
			res = new CXFilesList();

			break;
		}
		case 2:
		{
			res = new CXEditPathFile();

			break;
		}
		case 3:
		{
			res = new CXCompileEdit();

			break;
		}
		case 4:
		{
			res = new CXParametersWindow(false);

			break;
		}
		case 5:
		{
			res = new CXIniFileEditor();

			break;
		}
		case 6:
		{
			res = new CXIniFileList();

			break;
		}
		case 7:
		{
			res = new CXLazerDirectionWindow();

			break;
		}
		case 8:
		{
			res = new CXLazerSettings();

			break;
		}
		case 9:
		{
			res = new CXPathWindow();

			break;
		}
		case 10:
		{
			res = new CXTextParameters();

			break;
		}
	}

	if (res != NULL) res->setGroupNumber(aGroup);

	return res;
}

CXGroupPanel* addGroupPanel(int aGroup)
{
	CXGroupPanel* panel = new CXGroupPanel();
	panel->setGroupNumber(aGroup);

    return panel;
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	app.setQuitOnLastWindowClosed(false);

	QString translate = CXSettingsXML::getValue("settings.xml", "translate");
	
	if (!translate.isEmpty())
	{
		QTranslator* translator = new QTranslator(&app);
		translator->load(QApplication::applicationDirPath() + QDir::separator() + "translations" + QDir::separator() + translate);
		app.installTranslator(translator);
	}

	QString style = CXSettingsXML::getValue("settings.xml", "style");

	if (!style.isEmpty())
	{
		app.setStyleSheet(style);
	}

	CXWindowsManager manager;
	AXBaseWindow::mManager = &manager;
	AXBaseWindow::mUdpManager = new CXUdpManager(NULL);

	QWidget* window = NULL;

/**/
	QMap <QString, QWidget*> windows;

	//Создание первой группы окон.
	for (int i = 0; i < 4; ++i)
	{
		window = getTestWindow(i, 1);
		windows.insertMulti(window->metaObject()->className(), window);
	}

	//Создание второй группы окон.
	for (int i = 0; i < 1; ++i)
	{
		window = getTestWindow(i + 4, 2);
		windows.insertMulti(window->metaObject()->className(), window);
	}

	//Создание третьей группы окон.
	for (int i = 0; i < 2; ++i)
	{
		window = getTestWindow(i + 5, 3);
		windows.insertMulti(window->metaObject()->className(), window);
	}

	//Создание четвертой группы окон.
	for (int i = 0; i < 4; ++i)
	{
		window = getTestWindow(i + 7, 4);
		windows.insertMulti(window->metaObject()->className(), window);
	}

	QObject::connect(windows.value("CXFilesList"), SIGNAL(fileManageCreated(const QString&, const QString&)),	windows.values("CXPathWindow").first(), SLOT(load(const QString&, const QString&)));
	QObject::connect(windows.value("CXFilesList"), SIGNAL(fileCreated(const QString&, const QString&)),	windows.values("CXPathWindow").at(1), SLOT(load(const QString&, const QString&)));
	QObject::connect(windows.value("CXFilesList"), SIGNAL(fileOpened(const QString&)),					windows.value("CXEditPathFile"), SLOT(openFile(const QString&)));
	QObject::connect(windows.value("CXFilesList"), SIGNAL(compileTextChanged(const QString&)),			windows.value("CXCompileEdit"), SLOT(setText(const QString&)));
	QObject::connect(windows.value("CXCompileEdit"), SIGNAL(error(const QString&, int)),				windows.value("CXEditPathFile"), SLOT(onError(const QString&, int)));

	QObject::connect(windows.value("CXEditPathFile"), SIGNAL(textChanged(bool)),						windows.value("CXFilesList"), SLOT(onTextChanged(bool)));
	QObject::connect(windows.value("CXEditPathFile"), SIGNAL(newFileCreated()),							windows.value("CXFilesList"), SLOT(onCreateNewFile()));
	QObject::connect(windows.value("CXEditPathFile"), SIGNAL(statSaved()),								windows.value("CXFilesList"), SLOT(onStatSave()));
	QObject::connect(windows.value("CXIniFileList"), SIGNAL(fileOpened(const QString&)),				windows.value("CXIniFileEditor"), SLOT(onOpenFile(const QString&)));
	QObject::connect(windows.value("CXIniFileList"), SIGNAL(fileSaved()),								windows.value("CXIniFileEditor"), SLOT(onSave()));
	QObject::connect(windows.value("CXLazerDirectionWindow"), SIGNAL(positionChanged(const QPointF&, bool)),	windows.values("CXPathWindow").at(0), SLOT(setPosition(const QPointF&, bool)));

  CXGroupPanel* curGroupPanel = NULL;

	//Создание функциональных панелей управления для каждой группы окон.
	for (int i = 1; i < 6; ++i)
	{
        curGroupPanel = addGroupPanel(i);

        switch (i)
        {
            case 1:
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
                texts.append(QString());
                texts.append(QObject::trUtf8("Выключение"));

                curGroupPanel->setButtonsText(texts);

                curGroupPanel->getButton(0)->setProperty("groupName", 4);
				curGroupPanel->getButton(1)->setProperty("groupName", 2);
                QObject::connect(curGroupPanel->getButton(0), SIGNAL(clicked()), curGroupPanel, SLOT(setGroup()));
				QObject::connect(curGroupPanel->getButton(1), SIGNAL(clicked()), curGroupPanel, SLOT(setGroup()));

                QObject::connect(curGroupPanel->getButton(3), SIGNAL(clicked()), &manager, SLOT(changeVisibleVirtualKeyboard()));
                QObject::connect(curGroupPanel->getButton(4), SIGNAL(clicked()), curGroupPanel, SLOT(directoryCommand()));
                QObject::connect(curGroupPanel->getButton(5), SIGNAL(clicked()), curGroupPanel, SLOT(macroCommand()));
                QObject::connect(curGroupPanel->getButton(6), SIGNAL(clicked()), windows.value("CXEditPathFile"), SLOT(onSave()));
                QObject::connect(curGroupPanel->getButton(7), SIGNAL(clicked()), windows.value("CXFilesList"), SLOT(onTurn()));
                QObject::connect(curGroupPanel->getButton(9), SIGNAL(clicked()), curGroupPanel, SLOT(onExit()));


                qobject_cast<CXFilesList*>(windows.value("CXFilesList"))->setButton(curGroupPanel->getButton(6));

                break;
            }
            case 2:
            {
                QStringList texts;
                texts.append(QObject::trUtf8("УП"));
				texts.append(QObject::trUtf8("Управление"));
				texts.append(QString());
				texts.append(QString());
                texts.append(QString());
                texts.append(QString());
                texts.append(QString());
                texts.append(QObject::trUtf8("Наладка"));
                texts.append(QObject::trUtf8("Загрузить"));
                texts.append(QObject::trUtf8("Сохранить"));

                curGroupPanel->getButton(0)->setProperty("groupName", 1);
				curGroupPanel->getButton(1)->setProperty("groupName", 4);
                QObject::connect(curGroupPanel->getButton(0), SIGNAL(clicked()), curGroupPanel, SLOT(setGroup()));
                QObject::connect(curGroupPanel->getButton(1), SIGNAL(clicked()), curGroupPanel, SLOT(setGroup()));

                curGroupPanel->setButtonsText(texts);

                CXParametersWindow* parametersWindow = qobject_cast<CXParametersWindow*>(windows.value("CXParametersWindow"));

                QList <QPushButton*> buttons;
                for (int i = 2; i < 7; ++i) buttons.append(curGroupPanel->getButton(i));

                parametersWindow->setButtons(buttons);

                QObject::connect(curGroupPanel->getButton(7), SIGNAL(clicked()), parametersWindow, SLOT(showSettings()));
                QObject::connect(curGroupPanel->getButton(8), SIGNAL(clicked()), parametersWindow, SLOT(loadParametersFromFtp()));
                QObject::connect(curGroupPanel->getButton(9), SIGNAL(clicked()), parametersWindow, SLOT(saveParameters()));

                break;
			}
			case 3:
			{
				QStringList texts;
				texts.append(QObject::trUtf8("Параметры"));
				texts.append(QString());
				texts.append(QString());
				texts.append(QString());
				texts.append(QString());
				texts.append(QString());
				texts.append(QString());
				texts.append(QString());
				texts.append(QObject::trUtf8("Загрузить"));
				texts.append(QObject::trUtf8("Сохранить"));

				curGroupPanel->getButton(0)->setProperty("groupName", 2);
				QObject::connect(curGroupPanel->getButton(0), SIGNAL(clicked()), curGroupPanel, SLOT(setGroup()));

				QObject::connect(curGroupPanel->getButton(8), SIGNAL(clicked()), windows.value("CXIniFileList"), SLOT(onOpenFile()));
				QObject::connect(curGroupPanel->getButton(9), SIGNAL(clicked()), windows.value("CXIniFileEditor"), SLOT(onSave()));

                curGroupPanel->setButtonsText(texts);

				break;
			}
			case 4:
			{
				QStringList texts;
				texts.append(QObject::trUtf8("УП"));
				texts.append(QObject::trUtf8("Параметры"));
				texts.append(QObject::trUtf8("Наладка"));
				texts.append(QString());
				texts.append(QString());
				texts.append(QObject::trUtf8("Утилиты"));
				texts.append(QObject::trUtf8("Сбросить\nкоординаты"));
				texts.append(QObject::trUtf8("Сброс\nаварий"));
				texts.append(QString());
				texts.append(QString());

				curGroupPanel->getButton(0)->setProperty("groupName", 1);
				curGroupPanel->getButton(1)->setProperty("groupName", 2);
				curGroupPanel->getButton(2)->setProperty("groupName", 5);
				QObject::connect(curGroupPanel->getButton(0), SIGNAL(clicked()), curGroupPanel, SLOT(setGroup()));
				QObject::connect(curGroupPanel->getButton(1), SIGNAL(clicked()), curGroupPanel, SLOT(setGroup()));
				QObject::connect(curGroupPanel->getButton(2), SIGNAL(clicked()), curGroupPanel, SLOT(onDeviceEditShow()));

				QObject::connect(curGroupPanel->getButton(5), SIGNAL(clicked()), windows.value("CXLazerDirectionWindow"), SLOT(onUtils()));
				QObject::connect(curGroupPanel->getButton(6), SIGNAL(clicked()), windows.value("CXLazerDirectionWindow"), SLOT(onResetCoordinates()));
				QObject::connect(curGroupPanel->getButton(7), SIGNAL(clicked()), windows.value("CXTextParameters"), SLOT(onResetAlarms()));

				curGroupPanel->setButtonsText(texts);

				break;
			}
			case 5:
			{
				QList <QPushButton*> buttonsList;
				buttonsList << curGroupPanel->getButton(2) << curGroupPanel->getButton(3) << curGroupPanel->getButton(4) << curGroupPanel->getButton(5) << curGroupPanel->getButton(6) << curGroupPanel->getButton(7);

				CXDeviceView::loadDevices(5, buttonsList);

				QStringList texts;
				texts.append(QObject::trUtf8("УП"));
				texts.append(QObject::trUtf8("Параметры"));
				texts.append(QObject::trUtf8("+"));
				texts.append(QObject::trUtf8("-"));
				texts.append(QObject::trUtf8("0"));
				texts.append(QObject::trUtf8("авто"));
				texts.append(QObject::trUtf8("Канал"));
				texts.append(QObject::trUtf8("Устройство"));
				texts.append(QObject::trUtf8("Загрузить"));
				texts.append(QObject::trUtf8("Сохранить"));

				curGroupPanel->getButton(0)->setProperty("groupName", 1);
				curGroupPanel->getButton(1)->setProperty("groupName", 2);
				QObject::connect(curGroupPanel->getButton(0), SIGNAL(clicked()), curGroupPanel, SLOT(onDeviceEditHide()));
				QObject::connect(curGroupPanel->getButton(1), SIGNAL(clicked()), curGroupPanel, SLOT(onDeviceEditHide()));

				CXParametersWindow* parametersWindow = qobject_cast<CXParametersWindow*>(windows.value("CXParametersWindow"));
				QObject::connect(curGroupPanel->getButton(8), SIGNAL(clicked()), parametersWindow, SLOT(loadParametersFromFtp()));
				QObject::connect(curGroupPanel->getButton(9), SIGNAL(clicked()), parametersWindow, SLOT(saveParametersAnyway()));

				curGroupPanel->setButtonsText(texts);

				break;
			}
        }
	}

/**/
	//Общий заголовок
	CXTitleWindow* title = new CXTitleWindow();
	QObject::connect(windows.value("CXFilesList"),		SIGNAL(fileOpened(const QString&)),	title, SLOT(onFileOpen(const QString&)));
	QObject::connect(windows.value("CXTextParameters"),	SIGNAL(errorReceived(const QString&)),	title, SLOT(onErrorReceive(const QString&)));

	//Загрузка данных о геометрии окон (обязательно только после их создания!).
	manager.load("settings.xml");
	//Установка текущей группы.
	manager.setCurrentGroup(1);

	AXBaseWindow::mUdpManager->sendCommand(Commands::MSG_SECTION_START, Commands::MSG_CMD_FORM_RESTART, "0");
//	CXParametersWindow* parametersWindow = qobject_cast<CXParametersWindow*>(windows.value("CXParametersWindow"));
//	parametersWindow->loadParametersFromFtp();

	return app.exec();
}
