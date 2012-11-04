#include "CXTitleWindow.h"

#include <QVBoxLayout>
#include <QApplication>

CXTitleWindow::CXTitleWindow() : AXBaseWindow()
{
	QVBoxLayout* centralLayout = new QVBoxLayout(this);

	mFileLabel = new QLabel(this);
	centralLayout->addWidget(mFileLabel);
}

CXTitleWindow::~CXTitleWindow()
{

}

void CXTitleWindow::onFileOpen(const QString& aFileName)
{
	mFileLabel->setText(QString(aFileName).replace(QApplication::applicationDirPath() + "/cps/", ""));
}
