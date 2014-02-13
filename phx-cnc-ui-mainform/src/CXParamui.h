#ifndef CXPARAMUI_H
#define CXPARAMUI_H

#include "AXBaseWindow.h"
#include <QComboBox>

#include "ui_CXParam.h"

class CXParamUi : public AXBaseWindow
{
	Q_OBJECT

public:
	CXParamUi();
	~CXParamUi();

private slots:
	void readKeys();
	void readValues();
	void clearLayout(QLayout* aLayout);
	void onKeyChange();
	void updateData();
	void save();
	void onButtonClicked();

signals:
  void iniSaved();

private:
	Ui::CXParamUiClass ui;
	QString mType;
	QString mLastUpdateKey;
	QList <QLineEdit*> mEditors;
	QList <QComboBox*> mKeyList;
};

#endif // CXPARAMUI_H
