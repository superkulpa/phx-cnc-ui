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

AXBaseWindow* getTestWindow(int aIndex, int aGroup)
{
	AXBaseWindow* window = new AXBaseWindow();
	window->setGroupNumber(aGroup);

	QVBoxLayout* centralLayout = new QVBoxLayout(window);

	switch (aIndex)
	{
		case 0:
		{
			CXPathView* pathView = new CXPathView(window);
			//pathView->load("C:/Users/OLEG@tor/Downloads/files/list.kerf.cpr.ccp", "C:/Users/OLEG@tor/Downloads/files/list.cpr.ccp");
			pathView->load("tmp/list.kerf.cpr.ccp", "tmp/list.cpr.ccp");
			centralLayout->addWidget(pathView);

			QHBoxLayout* horLayout = new QHBoxLayout;

			QPushButton* zoomInButton = new QPushButton(QObject::trUtf8("+ Увеличить"), window);
			horLayout->addWidget(zoomInButton);

			QPushButton* zoomOutButton = new QPushButton(QObject::trUtf8("- Уменьшить"), window);
			horLayout->addWidget(zoomOutButton);

			QObject::connect(zoomInButton, SIGNAL(clicked()), pathView, SLOT(zoomIn()));
			QObject::connect(zoomOutButton, SIGNAL(clicked()), pathView, SLOT(zoomOut()));

			centralLayout->addLayout(horLayout);

			break;
		}
		case 1:
		{
			QTextEdit* edit = new QTextEdit(window);
			edit->setPlainText("Text");
			centralLayout->addWidget(edit);

			break;
		}
		case 2:
		{
			QTreeWidget* tree = new QTreeWidget(window);

			QTreeWidgetItem* item1 = new QTreeWidgetItem(tree);
			item1->setText(0, "Node 1");
			tree->addTopLevelItem(item1);

			QTreeWidgetItem* item2 = new QTreeWidgetItem(tree);
			item2->setText(0, "Node 2");
			tree->addTopLevelItem(item2);

			QTreeWidgetItem* item3 = new QTreeWidgetItem(tree);
			item3->setText(0, "Node 3");
			tree->addTopLevelItem(item3);

			QList <QTreeWidgetItem*> list;
			list.append(item1);
			list.append(item2);
			list.append(item3);

			QTreeWidgetItem* tempItem = NULL;
			for (int item = 0; item < list.count(); ++item)
			{
				for (int i = 0; i < 3; ++i)
				{
					tempItem = new QTreeWidgetItem();
					tempItem->setText(0, QString("Child %1").arg(i + 1));
					list.at(item)->addChild(tempItem);
				}
			}

			centralLayout->addWidget(tree);

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
	}

//	window->show();

	return window;
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	CXWindowsManager manager;
	AXBaseWindow::mManager = &manager;

	AXBaseWindow* window = NULL;

	for (int i = 0; i < 3; ++i) window = getTestWindow(i, 1);
	for (int i = 0; i < 2; ++i) window = getTestWindow(i + 3, 2);

	CXPanelWindow* panel = new CXPanelWindow();
	panel->show();

	manager.load("windows.xml");
	manager.setCurrentGroup(1);

	QObject::connect(panel, SIGNAL(closed()), &app, SLOT(quit()));

	return app.exec();
}
