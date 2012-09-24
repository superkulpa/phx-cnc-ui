#include "CXTurnDialog.h"


CXTurnDialog::CXTurnDialog(QWidget* parent) : QWidget(parent)
{
	setupUi(this);

	connect(mCloseButton, SIGNAL(clicked()), this, SLOT(close()));
}

CXTurnDialog::~CXTurnDialog()
{

}
