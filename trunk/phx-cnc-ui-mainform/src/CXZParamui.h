/*
 * CXZParamui.h
 *
 *  Created on: 09 апр. 2014 г.
 *      Author: tsvet
 */

#ifndef CXZPARAMUI_H_
#define CXZPARAMUI_H_

#include "AXBaseWindow.h"
#include <QComboBox>
#include <QDoubleSpinBox>

#include "ui_CXZParam.h"

class CXZParamUi : public AXBaseWindow
{
   Q_OBJECT

public:
  CXZParamUi();
  ~CXZParamUi();

private slots:
//  void readKeys();
//  void readValues();
//  void clearLayout(QLayout* aLayout);
//  void onKeyChange();
//  void updateData();
//  void save();
	void onButtonClicked();
	void onFixZPosButtonClicked();
	void onFixVButtonClicked();
	void onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue);
signals:
    void iniSaved();
public:
	virtual void setVisible(bool visible);
private:
	Ui::CXZParamUiClass ui;
	QVBoxLayout* mValuesLayout;
	QList <QDoubleSpinBox*> mZPosEditors;
	QList <CXTouchButton*> mfixZPos;
	QList <QDoubleSpinBox*> mVEditors;
	QList <CXTouchButton*> mfixV;
};



#endif /* CXZPARAMUI_H_ */
