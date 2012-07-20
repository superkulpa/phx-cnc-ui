#include "CXGroupPanel.h"

#include <QPushButton>
#include <QApplication>
#include <QDesktopWidget>

#include "flowlayout.h"

CXGroupPanel::CXGroupPanel() : AXBaseWindow()
{
/**/
	FlowLayout* centralLayout = new FlowLayout(this);
	centralLayout->setMargin(8);
	centralLayout->setSpacing(8);
/**/

	QPushButton* button = NULL;
	int buttonSize = QApplication::desktop()->availableGeometry().width() / 20;

	for (int i = 1; i < 13; ++i)
	{
		button = new QPushButton(QString("F%1").arg(i), this);
		button->setFont(QFont("", buttonSize / 6));
		button->setFixedSize(buttonSize, buttonSize);

		centralLayout->addWidget(button);
	}
}

CXGroupPanel::~CXGroupPanel()
{

}
