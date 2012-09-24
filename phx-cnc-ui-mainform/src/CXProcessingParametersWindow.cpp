#include "CXProcessingParametersWindow.h"

#include <QVBoxLayout>
#include <QPushButton>

#include "CXParametersView.h"

CXProcessingParametersWindow::CXProcessingParametersWindow(QWidget* parent) : QWidget(parent)
{
	setupUi(this);

	mParametersView = new CXParametersView(this, CXParametersView::mDataMap.values(0));

	mCentralLayout->insertWidget(0, mParametersView);

	connect(mCancelButton, SIGNAL(clicked()), this, SLOT(close()));
/*
	QVBoxLayout* centralLayout = new QVBoxLayout(this);


	centralLayout->addWidget(mParametersView);

	QHBoxLayout* buttonsLayout = new QHBoxLayout;
	buttonsLayout->addStretch();

	QPushButton* loadFromBaseButton = new QPushButton(this);
	loadFromBaseButton->setText(trUtf8("Загрузить из базы"));
	buttonsLayout->addWidget(loadFromBaseButton);
	
	QPushButton* loadButton = new QPushButton(this);
	loadButton->setText(trUtf8("Загрузить"));
	buttonsLayout->addWidget(loadButton);
	
	QPushButton* cancelButton = new QPushButton(this);
	cancelButton->setText(trUtf8("Отмена"));
	buttonsLayout->addWidget(cancelButton);

	centralLayout->addLayout(buttonsLayout);
*/
}

CXProcessingParametersWindow::~CXProcessingParametersWindow()
{
}
