#include "CXTitleWindow.h"

#include <QVBoxLayout>
#include <QApplication>

CXTitleWindow::CXTitleWindow() : AXBaseWindow()
{
	setGroupNumber(0);

	QHBoxLayout* centralLayout = new QHBoxLayout(this);
	centralLayout->setMargin(7);

	mFileLabel = new QLabel(this);
	centralLayout->addWidget(mFileLabel);

	QLabel* lbl1 = new QLabel(this);
	lbl1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
	centralLayout->addWidget(lbl1);

	QLabel* lbl2 = new QLabel(this);
	lbl2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
	centralLayout->addWidget(lbl2);

	registerManager();
}

CXTitleWindow::~CXTitleWindow()
{

}

void CXTitleWindow::onFileOpen(const QString& aFileName)
{
	mFileLabel->setText(QString(aFileName).replace(QApplication::applicationDirPath() + "/cps/", ""));
}
