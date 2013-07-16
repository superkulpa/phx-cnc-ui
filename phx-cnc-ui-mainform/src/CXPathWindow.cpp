#include "CXPathWindow.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QGroupBox>

#include "CXPathView.h"
#include "CXTouchButton.h"

CXPathWindow::CXPathWindow() :
    AXBaseWindow()
{
  QVBoxLayout* centralLayout = new QVBoxLayout(this);
  centralLayout->setMargin(5);

  QGroupBox* groupBox = new QGroupBox(this);

  QVBoxLayout* groupBoxLayout = new QVBoxLayout(groupBox);
  groupBoxLayout->setMargin(7);
  groupBoxLayout->setSpacing(6);

  mPathView = new CXPathView(groupBox);
  //pathView->load("C:/Users/OLEG@tor/Downloads/files/list.kerf.cpr.ccp", "C:/Users/OLEG@tor/Downloads/files/list.cpr.ccp");
  //pathView->load(QApplication::applicationDirPath() + "/tmp/list.cpr.ccp", QApplication::applicationDirPath() + "/tmp/list.kerf.cpr.ccp");
  groupBoxLayout->addWidget(mPathView);

  QHBoxLayout* horLayout = new QHBoxLayout;

  CXTouchButton* zoomInButton = new CXTouchButton(QObject::trUtf8("+ Увеличить"), groupBox);
  horLayout->addWidget(zoomInButton);

  CXTouchButton* showAllButton = new CXTouchButton(QObject::trUtf8("x"), this);
  horLayout->addWidget(showAllButton);

  CXTouchButton* zoomOutButton = new CXTouchButton(QObject::trUtf8("- Уменьшить"), groupBox);
  horLayout->addWidget(zoomOutButton);

  CXTouchButton* maximizeButton = new CXTouchButton(QObject::trUtf8("□"), groupBox);
  horLayout->addWidget(maximizeButton);

  connect(zoomInButton, SIGNAL(clicked()), mPathView, SLOT(zoomIn()));
  connect(zoomOutButton, SIGNAL(clicked()), mPathView, SLOT(zoomOut()));
  connect(showAllButton, SIGNAL(clicked()), mPathView, SLOT(fitInView()));
  connect(maximizeButton, SIGNAL(clicked()), this, SLOT(onMaximize()));

  groupBoxLayout->addLayout(horLayout);

  centralLayout->addWidget(groupBox);

  registerManager();
}

CXPathWindow::~CXPathWindow()
{

}

void
CXPathWindow::load(const QString& aMainFile, const QString& aMoveFile)
{
  mPathView->load(aMainFile, aMoveFile);
}

void
CXPathWindow::setPosition(const QPointF& aPos, bool aIsAbsolute)
{
  mPathView->setPosition(aPos, aIsAbsolute);
}

void
CXPathWindow::onMaximize()
{
  if (isFullScreen())
    showNormal();
  else
    showFullScreen();
}
