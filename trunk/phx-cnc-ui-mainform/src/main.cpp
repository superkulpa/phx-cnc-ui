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
			horLayout->addWidget(zoomInButton);

			QPushButton* zoomOutButton = new QPushButton(QObject::trUtf8("- Уменьшить"), window);
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
			QListWidget* list = new QListWidget(window);

			for (int i = 0; i < 7; ++i) list->addItem(new QListWidgetItem(QString("Item %1").arg(i + 1)));

			centralLayout->addWidget(list);

			break;
		}
		case 4:
		{
			QLabel* label = NULL;
			QLineEdit* edit = NULL;

			for (int i = 0; i < 3; ++i)
			{
				label = new QLabel(QString("Label %1").arg(i + 1), window);
				edit = new QLineEdit(window);

				centralLayout->addWidget(label);
				centralLayout->addWidget(edit);
			}

			centralLayout->addStretch();

			break;
		}
		case 5:
		{
			CXIniFileEditor* editIniFile = new CXIniFileEditor(window);

			centralLayout->setMargin(0);
			centralLayout->setSpacing(0);
			centralLayout->addWidget(editIniFile);

			break;
		}
	}

//	window->show();

	return res;
}

void addGroupPanel(int aGroup)
{
	CXGroupPanel* panel = new CXGroupPanel();
	panel->setGroupNumber(aGroup);
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	CXWindowsManager manager;
	AXBaseWindow::mManager = &manager;

	QWidget* window = NULL;

/**/
	QList <QWidget*> windows;

	//Создание первой группы окон.
	for (int i = 0; i < 3; ++i)
	{
		window = getTestWindow(i, 1);
		windows.append(window);
	}

	//Создание второй группы окон.
	for (int i = 0; i < 2; ++i)
	{
		window = getTestWindow(i + 3, 2);
		windows.append(window);
	}

	//Создание третьей группы окон.
	for (int i = 0; i < 1; ++i)
	{
		window = getTestWindow(i + 5, 3);
		windows.append(window);
	}

	QObject::connect(windows.at(1), SIGNAL(fileCreated(const QString&, const QString&)), windows.at(0), SLOT(load(const QString&, const QString&)));
	QObject::connect(windows.at(1), SIGNAL(fileOpened(const QString&)), windows.at(2), SLOT(openFile(const QString&)));
	
	//Создание функциональных панелей управления для каждой группы окон.
	for (int i = 1; i < 4; ++i)
	{
		addGroupPanel(i);
	}

/**/
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
