#include "BaseCreator.h"

BaseCreator::BaseCreator(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);
}

BaseCreator::~BaseCreator()
{

}
