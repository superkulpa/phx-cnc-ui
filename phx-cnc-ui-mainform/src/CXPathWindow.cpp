#include "CXPathWindow.h"

#include <QVBoxLayout>
#include <QPushButton>

#include "CXPathView.h"

CXPathWindow::CXPathWindow() : AXBaseWindow()
{
	setObjectName("CXPathWindow");
/**/
	QVBoxLayout* centralLayout = new QVBoxLayout(this);

	mPathView = new CXPathView(this);
	//pathView->load("C:/Users/OLEG@tor/Downloads/files/list.kerf.cpr.ccp", "C:/Users/OLEG@tor/Downloads/files/list.cpr.ccp");
	//pathView->load(QApplication::applicationDirPath() + "/tmp/list.cpr.ccp", QApplication::applicationDirPath() + "/tmp/list.kerf.cpr.ccp");
	centralLayout->addWidget(mPathView);

	QHBoxLayout* horLayout = new QHBoxLayout;
	centralLayout->setMargin(5);
	centralLayout->setSpacing(5);

	QPushButton* zoomInButton = new QPushButton(QObject::trUtf8("+ Увеличить"), this);
	horLayout->addWidget(zoomInButton);

	QPushButton* showAllButton = new QPushButton(QObject::trUtf8("x"), this);
	horLayout->addWidget(showAllButton);

	QPushButton* zoomOutButton = new QPushButton(QObject::trUtf8("- Уменьшить"), this);
	horLayout->addWidget(zoomOutButton);

	connect(zoomInButton, SIGNAL(clicked()), mPathView, SLOT(zoomIn()));
	connect(zoomOutButton, SIGNAL(clicked()), mPathView, SLOT(zoomOut()));
	connect(showAllButton, SIGNAL(clicked()), mPathView, SLOT(fitInView()));

	centralLayout->addLayout(horLayout);
}

CXPathWindow::~CXPathWindow()
{

}

void CXPathWindow::load(const QString& aMainFile, const QString& aMoveFile)
{
	mPathView->load(aMainFile, aMoveFile);
}

void CXPathWindow::setPosition(const QPointF& aPos, bool aIsAbsolute)
{
	mPathView->setPosition(aPos, aIsAbsolute);
}
