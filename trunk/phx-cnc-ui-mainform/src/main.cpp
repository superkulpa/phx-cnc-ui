#include <QApplication>

#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QTreeWidget>
#include <QListWidget>
#include <QLineEdit>

#include "CXWindowsManager.h"
#include "CXPanelWindow.h"
#include "CXPathWindow.h"
#include "CXFilesList.h"
#include "CXEditPathFile.h"
#include "CXIniFileEditor.h"
#include "CXIniFileList.h"
#include "CXTitleWindow.h"
#include "CXParametersWindow.h"
#include "CXLazerDirectionWindow.h"
#include "CXLazerSettings.h"
#include "CXTextParameters.h"

#include "CXGroupPanel.h"

QWidget* getTestWindow(int aIndex, int aGroup)
{
	QWidget* res = NULL;

	switch (aIndex)
	{
		case 0:
		{
			CXPathWindow* pathWindow = new CXPathWindow();
			pathWindow->setGroupNumber(aGroup);

			res = pathWindow;

			break;
		}
		case 1:
		{
			CXFilesList* filesList = new CXFilesList();
			filesList->setGroupNumber(aGroup);

			res = filesList;

			break;
		}
		case 2:
		{
			CXEditPathFile* editFile = new CXEditPathFile();
			editFile->setGroupNumber(aGroup);

			res = editFile;

			break;
		}
		case 3:
		{
			AXBaseWindow* window = new AXBaseWindow();
			window->setGroupNumber(aGroup);

			QVBoxLayout* centralLayout = new QVBoxLayout(window);
/**/
			CXParametersWindow* parametersWindow = new CXParametersWindow(window, false);

			centralLayout->addWidget(parametersWindow);

			res = parametersWindow;

			break;
		}
		case 4:
		{
			CXIniFileEditor* editIniFile = new CXIniFileEditor();
			editIniFile->setGroupNumber(aGroup);

			res = editIniFile;

			break;
		}
		case 5:
		{
			CXIniFileList* iniFileList = new CXIniFileList();
			iniFileList->setGroupNumber(aGroup);

			res = iniFileList;

			break;
		}
		case 6:
		{
			CXLazerDirectionWindow* lazerPosition = new CXLazerDirectionWindow();
			lazerPosition->setGroupNumber(aGroup);

			res = lazerPosition;

			break;
		}
		case 7:
		{
			CXLazerSettings* lazerSettings = new CXLazerSettings();
			lazerSettings->setGroupNumber(aGroup);

			res = lazerSettings;

			break;
		}
		case 8:
		{
			CXPathWindow* pathWindow = new CXPathWindow();
			pathWindow->setGroupNumber(aGroup);

			res = pathWindow;

			break;
		}
		case 9:
		{
			CXTextParameters* textParameters = new CXTextParameters();
			textParameters->setGroupNumber(aGroup);

			res = textParameters;

			break;
		}
	}

//	window->show();

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
	app.setStyleSheet(
						"QWidget { font-size: 13pt; }\n\
						CXPathView { font-size: 10pt; }\n\
						QTabBar::tab { padding: 15px; }\n\
						CXProcessingParametersWindow QAbstractButton, CXEditPathFile QAbstractButton, CXPathWindow QAbstractButton { min-height: 30px; padding: 15px; }\n\
						CXFilesList QAbstractButton { padding: 20px 35px; }\n\
						CXPanelWindow QAbstractButton { min-width: 110px; min-height: 75px; }\n\
						CXGroupPanel QAbstractButton { min-width: 105px; min-height: 75px; }\n\
						CXIniFileList QAbstractButton { padding: 15px; }\n\
						CXTurnDialog * { font-size: 14pt; }\n\
						CXTurnDialog QAbstractButton { min-width: 100px; min-height: 75px; }\n\
						CXTurnDialog #mTurnSettings QAbstractButton { min-width: 200px; }\n\
						CXLazerVelocity QAbstractButton { font-size: 24pt; min-height: 140px; min-width: 100px; }\n\
						CXLazerVelocity QLabel { font-size: 80pt; min-width: 100px; }\n\
						CXLazerSettings QAbstractButton { min-width: 80px; min-height: 75px; }\n\
						CXLazerSettings QLabel { font-size: 14pt; min-width: 50px; }\n\
						CXLazerDirectionWindow QAbstractButton { min-height: 75px; }\n\
						CXLazerDirectionWindow #xButton, CXLazerDirectionWindow #yButton { min-height: 50px; min-width: 50px; font-size: 14pt; }\n\
						CXLazerDirectionWindow QLineEdit { font-size: 16pt; padding: 5px; }\n\
						CXLazerDirectionDialog QAbstractButton { padding: 0px 10px; }\n\
						CXExitDialog QAbstractButton { padding: 30px 60px; }"
					  );

	CXWindowsManager manager;
	AXBaseWindow::mManager = &manager;

	QWidget* window = NULL;

/**/
	QMap <QString, QWidget*> windows;

	//Создание первой группы окон.
	for (int i = 0; i < 3; ++i)
	{
		window = getTestWindow(i, 1);
		windows.insertMulti(window->metaObject()->className(), window);
	}

	//Создание второй группы окон.
	for (int i = 0; i < 1; ++i)
	{
		window = getTestWindow(i + 3, 2);
		windows.insertMulti(window->metaObject()->className(), window);
	}

	//Создание третьей группы окон.
	for (int i = 0; i < 2; ++i)
	{
		window = getTestWindow(i + 4, 3);
		windows.insertMulti(window->metaObject()->className(), window);
	}

	//Создание четвертой группы окон.
	for (int i = 0; i < 4; ++i)
	{
		window = getTestWindow(i + 6, 4);
		windows.insertMulti(window->metaObject()->className(), window);
	}

	QObject::connect(windows.value("CXFilesList"), SIGNAL(fileCreated(const QString&, const QString&)),	windows.values("CXPathWindow").first(), SLOT(load(const QString&, const QString&)));
	QObject::connect(windows.value("CXFilesList"), SIGNAL(fileCreated(const QString&, const QString&)),	windows.values("CXPathWindow").at(1), SLOT(load(const QString&, const QString&)));
	QObject::connect(windows.value("CXFilesList"), SIGNAL(fileOpened(const QString&)),					windows.value("CXEditPathFile"), SLOT(openFile(const QString&)));
	QObject::connect(windows.value("CXEditPathFile"), SIGNAL(textChanged(bool)),						windows.value("CXFilesList"), SLOT(onTextChanged(bool)));
	QObject::connect(windows.value("CXEditPathFile"), SIGNAL(newFileCreated()),							windows.value("CXFilesList"), SLOT(onCreateNewFile()));
	QObject::connect(windows.value("CXEditPathFile"), SIGNAL(statSaved()),								windows.value("CXFilesList"), SLOT(onStatSave()));
	QObject::connect(windows.value("CXIniFileList"), SIGNAL(fileOpened(const QString&)),				windows.value("CXIniFileEditor"), SLOT(onOpenFile(const QString&)));
	QObject::connect(windows.value("CXIniFileList"), SIGNAL(fileSaved()),								windows.value("CXIniFileEditor"), SLOT(onSave()));

    CXGroupPanel* curGroupPanel = NULL;

	//Создание функциональных панелей управления для каждой группы окон.
	for (int i = 1; i < 5; ++i)
	{
        curGroupPanel = addGroupPanel(i);

        switch (i)
        {
            case 1:
            {
                QStringList texts;
                texts.append(QString());
                texts.append(QString());
                texts.append(QString());
                texts.append(QString());
                texts.append(QObject::trUtf8("Каталог"));
                texts.append(QObject::trUtf8("Макро"));
                texts.append(QObject::trUtf8("Загрузить"));
                texts.append(QObject::trUtf8("Повернуть"));

                curGroupPanel->setButtonsText(texts);

                QObject::connect(curGroupPanel->getButton(4), SIGNAL(clicked()), curGroupPanel, SLOT(directoryCommand()));
                QObject::connect(curGroupPanel->getButton(5), SIGNAL(clicked()), curGroupPanel, SLOT(macroCommand()));
                QObject::connect(curGroupPanel->getButton(6), SIGNAL(clicked()), windows.value("CXEditPathFile"), SLOT(onSave()));
                QObject::connect(curGroupPanel->getButton(7), SIGNAL(clicked()), windows.value("CXFilesList"), SLOT(onTurn()));

				qobject_cast<CXFilesList*>(windows.value("CXFilesList"))->setButton(curGroupPanel->getButton(6));

                break;
            }
            case 2:
            {
                QStringList texts;
                texts.append(QString());
                texts.append(QString());
                texts.append(QString());
                texts.append(QString());
                texts.append(QString());
				texts.append(QString());
				texts.append(QString());
                texts.append(QObject::trUtf8("Наладка"));
                texts.append(QObject::trUtf8("Загрузить"));
                texts.append(QObject::trUtf8("Сохранить"));

                curGroupPanel->setButtonsText(texts);

				CXParametersWindow* parametersWindow = qobject_cast<CXParametersWindow*>(windows.value("CXParametersWindow"));

				QList <QPushButton*> buttons;
				for (int i = 0; i < 7; ++i) buttons.append(curGroupPanel->getButton(i));

				parametersWindow->setButtons(buttons);

                QObject::connect(curGroupPanel->getButton(7), SIGNAL(clicked()), parametersWindow, SLOT(showSettings()));
                QObject::connect(curGroupPanel->getButton(8), SIGNAL(clicked()), parametersWindow, SLOT(loadParametersFromFtp()));
                QObject::connect(curGroupPanel->getButton(9), SIGNAL(clicked()), parametersWindow, SLOT(saveParameters()));

                break;
            }
        }
	}

/**/
	//Общий заголовок
	CXTitleWindow* title = new CXTitleWindow();
	QObject::connect(windows.value("CXFilesList"), SIGNAL(fileOpened(const QString&)),	title, SLOT(onFileOpen(const QString&)));

	//Общая панель управления.
	CXPanelWindow* panel = new CXPanelWindow();

	//Загрузка данных о геометрии окон (обязательно только после их создания!).
	manager.load("windows.xml");
	//Установка текущей группы.
	manager.setCurrentGroup(1);

	//Установка текущего состояния заморозки.
	panel->setFreezeState(manager.getFreeze());
	panel->show();

	QObject::connect(panel, SIGNAL(closed()), &app, SLOT(quit()));

	return app.exec();
}
