#ifndef CXPROCESSINGPARAMETERSWINDOW_H
#define CXPROCESSINGPARAMETERSWINDOW_H

#include "ui_CXProcessingParametersWindow.h"

class CXParametersView;

/*!
	Класс для настройки системных параметров.
*/
class CXProcessingParametersWindow : public QDialog, public Ui::CXProcessingParametersWindow
{
	Q_OBJECT

public:
	CXProcessingParametersWindow(QWidget* parent);
	~CXProcessingParametersWindow();

private slots:
	//! Слот на загрузку.
	void onFileLoad();

private:
	CXParametersView* mParametersView;
};

#endif // CXPROCESSINGPARAMETERSWINDOW_H
