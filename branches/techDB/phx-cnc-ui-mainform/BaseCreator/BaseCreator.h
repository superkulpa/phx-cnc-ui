#ifndef BASECREATOR_H
#define BASECREATOR_H

#include <QtGui/QWidget>
#include "ui_BaseCreator.h"

class BaseCreator : public QWidget
{
	Q_OBJECT

public:
	BaseCreator(QWidget *parent = 0, Qt::WFlags flags = 0);
	~BaseCreator();

private:
	Ui::BaseCreatorClass ui;
};

#endif // BASECREATOR_H
