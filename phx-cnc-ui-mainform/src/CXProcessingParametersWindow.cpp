#include "CXProcessingParametersWindow.h"

#include <QVBoxLayout>
#include <QPushButton>

#include "CXParametersView.h"
#include "CXWindowsManager.h"

CXProcessingParametersWindow::CXProcessingParametersWindow(QWidget* parent) : QWidget(parent)
{
	setupUi(this);

	mParametersView = new CXParametersView(this, CXParametersView::mDataMap.values(0));

	mCentralLayout->insertWidget(0, mParametersView);

	connect(mCancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(mLoadButton, SIGNAL(clicked()), this, SLOT(onFileLoad()));
}

CXProcessingParametersWindow::~CXProcessingParametersWindow()
{
}

void CXProcessingParametersWindow::onFileLoad()
{
	AXBaseWindow::mManager->setCurrentGroup(4);
	close();
}
