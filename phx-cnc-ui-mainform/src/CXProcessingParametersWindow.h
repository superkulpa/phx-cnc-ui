#ifndef CXPROCESSINGPARAMETERSWINDOW_H
#define CXPROCESSINGPARAMETERSWINDOW_H

#include <QWidget>

#include "ui_CXProcessingParametersWindow.h"

class CXParametersView;

/*!
	Класс для .
*/
class CXProcessingParametersWindow : public QWidget, public Ui::CXProcessingParametersWindow
{

public:
	CXProcessingParametersWindow(QWidget* parent);
	~CXProcessingParametersWindow();

private:
	CXParametersView* mParametersView;
};

#endif // CXPROCESSINGPARAMETERSWINDOW_H
