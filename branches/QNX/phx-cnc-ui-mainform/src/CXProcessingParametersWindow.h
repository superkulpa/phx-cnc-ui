#ifndef CXPROCESSINGPARAMETERSWINDOW_H
#define CXPROCESSINGPARAMETERSWINDOW_H

#include "ui_CXProcessingParametersWindow.h"

class CXParametersView;
class CXFtp;

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

	//! Слот, вызываемый по окончанию загрузки.
	void onAllFilesIsLoaded(bool aIsUpload);

private:
	CXParametersView* mParametersView;
	CXFtp* mFtp;
};

#endif // CXPROCESSINGPARAMETERSWINDOW_H
