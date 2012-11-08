#include "CXCompileEdit.h"

#include <QVBoxLayout>
#include <QTextEdit>

CXCompileEdit::CXCompileEdit() : AXBaseWindow()
{
	QVBoxLayout* centralLayout = new QVBoxLayout(this);
	centralLayout->setMargin(5);

	mTextEdit = new QTextEdit(this);
	mTextEdit->setMinimumHeight(10);
	centralLayout->addWidget(mTextEdit);
}

CXCompileEdit::~CXCompileEdit()
{

}

void CXCompileEdit::setText(const QString& aText)
{
	mTextEdit->setText(aText);
}
