#include <QApplication>

#include "CXWidget.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	CXWidget widget;
	widget.show();

	return app.exec();
}
