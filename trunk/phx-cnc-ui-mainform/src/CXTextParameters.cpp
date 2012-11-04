#include "CXTextParameters.h"

#include <QVBoxLayout>
#include <QTextEdit>

CXTextParameters::CXTextParameters() : AXBaseWindow()
{
	QVBoxLayout* centralLayout = new QVBoxLayout(this);
	centralLayout->setMargin(5);

	QTextEdit* textEdit = new QTextEdit(this);
	centralLayout->addWidget(textEdit);
}

CXTextParameters::~CXTextParameters()
{

}
