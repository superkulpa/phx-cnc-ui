#include "CXLazerDirectionDialog.h"

CXLazerDirectionDialog::CXLazerDirectionDialog(QWidget* parent) : QDialog(parent)
{
	setupUi(this);

	connect(mCancelButton, SIGNAL(clicked()), this, SLOT(reject()));
	connect(mAbsoluteButton, SIGNAL(clicked()), this, SLOT(onAbsolute()));
	connect(mRelativeButton, SIGNAL(clicked()), this, SLOT(onRelative()));
}

CXLazerDirectionDialog::~CXLazerDirectionDialog()
{

}

void CXLazerDirectionDialog::onAbsolute()
{
	done(1);
}

void CXLazerDirectionDialog::onRelative()
{
	done(2);
}