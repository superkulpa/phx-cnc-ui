#ifndef CXPARAMUI_H
#define CXPARAMUI_H

#include "AXBaseWindow.h"
#include <QComboBox>
#include <QDoubleSpinBox>

#include "ui_cxparamui.h"

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
	QGridLayout* mValuesLayout;

	QString mType;
	QString mLastUpdateKey;
	QList <QDoubleSpinBox*> mEditors;
	QList <QComboBox*> mKeyList;
};

#endif // CXPARAMUI_H
