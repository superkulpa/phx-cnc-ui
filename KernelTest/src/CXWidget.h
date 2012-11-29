#ifndef CXWIDGET_H
#define CXWIDGET_H

#include <QWidget>
#include <QNetworkInterface>

#include "ui_CXWidget.h"

class CXUdpManager;

/*!
*/
class CXWidget : public QWidget, public Ui::CXWidget
{
	Q_OBJECT

public:
	CXWidget();
	~CXWidget();

private slots:
	void onStart();
	void onSend();
	void onReceive(const QString& aCommand);

private:
	CXUdpManager* mUdpManager;
};

#endif // CXWIDGET_H
