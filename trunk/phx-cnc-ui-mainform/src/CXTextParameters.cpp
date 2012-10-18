#include "CXTextParameters.h"

#include <QVBoxLayout>
#include <QTextEdit>

CXTextParameters::CXTextParameters() : AXBaseWindow()
{
	QVBoxLayout* centralLayout = new QVBoxLayout(this);

	QTextEdit* textEdit = new QTextEdit(this);
	centralLayout->addWidget(textEdit);
}

CXTextParameters::~CXTextParameters()
{

}
