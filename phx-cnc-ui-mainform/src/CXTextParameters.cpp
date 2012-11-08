#include "CXTextParameters.h"

#include <QVBoxLayout>
#include <QTextEdit>

CXTextParameters::CXTextParameters() : AXBaseWindow()
{
	QVBoxLayout* centralLayout = new QVBoxLayout(this);
	centralLayout->setMargin(5);

	QTextEdit* textEdit = new QTextEdit(this);
	textEdit->setMinimumHeight(10);
	centralLayout->addWidget(textEdit);
}

CXTextParameters::~CXTextParameters()
{

}
