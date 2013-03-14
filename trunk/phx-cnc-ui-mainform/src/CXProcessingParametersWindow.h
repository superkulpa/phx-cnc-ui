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

	/*!
		Установка имени откомпилированного файла.
		\param aFileName - имя файла.
	*/
	void setFileName(const QString& aFileName);

private slots:
	//! Слот на загрузку.
	void onFileLoad();

	//! Слот на закрытие FTP.
	void closeFtp();

	//! Слот, вызываемый по окончанию загрузки.
	void onAllFilesIsLoaded(bool aIsUpload);

private:
	QString mFileName;
	CXParametersView* mParametersView;
	CXFtp* mFtp;
};

#endif // CXPROCESSINGPARAMETERSWINDOW_H
