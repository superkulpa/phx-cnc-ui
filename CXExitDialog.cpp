#include "CXExitDialog.h"

CXExitDialog::CXExitDialog(QWidget* parent) :
    QDialog(parent)
{
  setupUi(this);

  connect(mCancelButton, SIGNAL(clicked()), this, SLOT(reject()));
  connect(mTurnOffButton, SIGNAL(clicked()), this, SLOT(onTurnOff()));
  connect(mExitButton, SIGNAL(clicked()), this, SLOT(onExit()));
}

CXExitDialog::~CXExitDialog()
{

}

void
CXExitDialog::onTurnOff()
{
  done(1);
}

void
CXExitDialog::onExit()
{
  done(2);
}
