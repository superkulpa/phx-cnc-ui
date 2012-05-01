#include <QApplication>

#include "CXWindowsManager.h"
#include "CXPanelWindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	CXWindowsManager manager;
	AXBaseWindow::mManager = &manager;

	AXBaseWindow* window = NULL;

	for (int i = 0; i < 3; ++i)
	{
		window = new AXBaseWindow();
		window->setGroupNumber(1);
		window->show();
	}

	for (int i = 0; i < 2; ++i)
	{
		window = new AXBaseWindow();
		window->setGroupNumber(2);
		window->show();
	}

	CXPanelWindow* panel = new CXPanelWindow();
	panel->show();

	manager.load("windows.xml");
	manager.setCurrentGroup(1);

	QObject::connect(panel, SIGNAL(closed()), &app, SLOT(quit()));

	return app.exec();
}
