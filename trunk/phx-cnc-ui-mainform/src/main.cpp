#include <QApplication>

#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QTreeWidget>
#include <QListWidget>
#include <QLineEdit>

#include "CXWindowsManager.h"
#include "CXPanelWindow.h"
#include "CXPathView.h"
#include "CXFilesList.h"
#include "CXEditPathFile.h"
#include "CXIniFileEditor.h"
#include "CXIniFileList.h"
#include "CXTitleWindow.h"
#include "CXParametersWindow.h"

#include "CXGroupPanel.h"

QWidget* getTestWindow(int aIndex, int aGroup)
{
	QWidget* res = NULL;
	AXBaseWindow* window = new AXBaseWindow();
	window->setGroupNumber(aGroup);

	QVBoxLayout* centralLayout = new QVBoxLayout(window);

	switch (aIndex)
	{
		case 0:
		{
			CXPathView* pathView = new CXPathView(window);
			//pathView->load("C:/Users/OLEG@tor/Downloads/files/list.kerf.cpr.ccp", "C:/Users/OLEG@tor/Downloads/files/list.cpr.ccp");
			//pathView->load(QApplication::applicationDirPath() + "/tmp/list.cpr.ccp", QApplication::applicationDirPath() + "/tmp/list.kerf.cpr.ccp");
			centralLayout->addWidget(pathView);

			QHBoxLayout* horLayout = new QHBoxLayout;

			QPushButton* zoomInButton = new QPushButton(QObject::trUtf8("+ Увеличить"), window);
			zoomInButton->setMinimumSize(100, 60);
			zoomInButton->setFont(QFont("", zoomInButton->height() / 5));
			horLayout->addWidget(zoomInButton);

			QPushButton* zoomOutButton = new QPushButton(QObject::trUtf8("- Уменьшить"), window);
			zoomOutButton->setMinimumSize(100, 60);
			zoomOutButton->setFont(QFont("", zoomOutButton->height() / 5));
			horLayout->addWidget(zoomOutButton);

			QObject::connect(zoomInButton, SIGNAL(clicked()), pathView, SLOT(zoomIn()));
			QObject::connect(zoomOutButton, SIGNAL(clicked()), pathView, SLOT(zoomOut()));

			centralLayout->addLayout(horLayout);

			res = pathView;

			break;
		}
		case 1:
		{
			CXFilesList* filesList = new CXFilesList(window);
			centralLayout->setMargin(0);
			centralLayout->setSpacing(0);
			centralLayout->addWidget(filesList);

			res = filesList;

			break;
		}
		case 2:
		{
			CXEditPathFile* editFile = new CXEditPathFile(window);
			centralLayout->setMargin(0);
			centralLayout->setSpacing(0);
			centralLayout->addWidget(editFile);

			res = editFile;

			break;
		}
		case 3:
		{
			CXParametersWindow* parametersWindow = new CXParametersWindow(window, false);

			centralLayout->addWidget(parametersWindow);

			res = parametersWindow;

			break;
		}
		case 4:
		{
			CXIniFileEditor* editIniFile = new CXIniFileEditor(window);

			centralLayout->setMargin(0);
			centralLayout->setSpacing(0);
			centralLayout->addWidget(editIniFile);

			res = editIniFile;

			break;
		}
		case 5:
		{
			CXIniFileList* iniFileList = new CXIniFileList(window);

			centralLayout->setMargin(0);
			centralLayout->setSpacing(0);
			centralLayout->addWidget(iniFileList);

			res = iniFileList;

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

	CXWindowsManager manager;
	AXBaseWindow::mManager = &manager;

	QWidget* window = NULL;

/**/
	QMap <QString, QWidget*> windows;

	//Создание первой группы окон.
	for (int i = 0; i < 3; ++i)
	{
		window = getTestWindow(i, 1);
		windows.insert(window->metaObject()->className(), window);
	}

	//Создание второй группы окон.
	for (int i = 0; i < 1; ++i)
	{
		window = getTestWindow(i + 3, 2);
		windows.insert(window->metaObject()->className(), window);
	}

	//Создание третьей группы окон.
	for (int i = 0; i < 2; ++i)
	{
		window = getTestWindow(i + 4, 3);
		windows.insert(window->metaObject()->className(), window);
	}

	QObject::connect(windows.value("CXFilesList"), SIGNAL(fileCreated(const QString&, const QString&)),	windows.value("CXPathView"), SLOT(load(const QString&, const QString&)));
	QObject::connect(windows.value("CXFilesList"), SIGNAL(fileOpened(const QString&)),					windows.value("CXEditPathFile"), SLOT(openFile(const QString&)));
	QObject::connect(windows.value("CXEditPathFile"), SIGNAL(textChanged(bool)),						windows.value("CXFilesList"), SLOT(onTextChanged(bool)));
	QObject::connect(windows.value("CXEditPathFile"), SIGNAL(newFileCreated()),							windows.value("CXFilesList"), SLOT(onCreateNewFile()));
	QObject::connect(windows.value("CXIniFileList"), SIGNAL(fileOpened(const QString&)),				windows.value("CXIniFileEditor"), SLOT(onOpenFile(const QString&)));
	QObject::connect(windows.value("CXIniFileList"), SIGNAL(fileSaved()),								windows.value("CXIniFileEditor"), SLOT(onSave()));

    CXGroupPanel* curGroupPanel = NULL;

	//Создание функциональных панелей управления для каждой группы окон.
	for (int i = 1; i < 4; ++i)
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
                texts.append(QString());
                texts.append(QObject::trUtf8("Загрузить"));
                texts.append(QObject::trUtf8("Сохранить"));

                curGroupPanel->setButtonsText(texts);

				CXParametersWindow* parametersWindow = qobject_cast<CXParametersWindow*>(windows.value("CXParametersWindow"));

				QList <QPushButton*> buttons;
				for (int i = 0; i < 8; ++i) buttons.append(curGroupPanel->getButton(i));

				parametersWindow->setButtons(buttons);

                QObject::connect(curGroupPanel->getButton(8), SIGNAL(clicked()), parametersWindow, SLOT(loadParametersFromFtp()));
                QObject::connect(curGroupPanel->getButton(9), SIGNAL(clicked()), parametersWindow, SLOT(saveParameters()));

                break;
            }
        }
	}

/**/
	//Общий заголовок
	CXTitleWindow* title = new CXTitleWindow();

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
