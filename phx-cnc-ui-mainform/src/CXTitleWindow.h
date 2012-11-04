#ifndef CXTITLEWINDOW_H
#define CXTITLEWINDOW_H

#include "AXBaseWindow.h"

#include <QLabel>

/*!
	Класс заголовка окна.
*/
class CXTitleWindow : public AXBaseWindow
{
	Q_OBJECT

public:
	CXTitleWindow();
	~CXTitleWindow();

public slots:
	//! Слот на загрузку файла.
	void onFileOpen(const QString& aFileName);
	
private:
	QLabel* mFileLabel;
};

#endif // CXTITLEWINDOW_H
