/*
 * CXAdditionalOperDirectionWindow.h
 *
 *  Created on: Aug 8, 2014
 *      Author: root
 */

#ifndef CXADDITIONALOPERDIRECTIONWINDOW_H_
#define CXADDITIONALOPERDIRECTIONWINDOW_H_

#include "QtGui/qgroupbox.h"
#include "QtGui/qspinbox.h"
#include "AXBaseWindow.h"
#include "utils/CXProcess.h"
#include "CXTouchButton.h"



class CXAdditionalOperDirectionWindow: public AXBaseWindow {
	Q_OBJECT
public:
	QGroupBox* CreateAxisGroup(QString _title, int _id, int _min, int _max);
	int GetAxisId(int _axis);
	int GetAxisPosInMap(int _axisId);
protected:
	int nAxis;
	QMap <int, QPair<int, QString> > axisParam;
	CXTouchButton* backButton;
	CXTouchButton* blockButton;
	CXTouchButton* keyboardButton;
	QVector<QSpinBox*> curAxisPos;
	QVector<QSpinBox*> setAxisPos;
	QVector<CXTouchButton*> butRelMove;
	QVector<CXTouchButton*> butAbsMove;
	CXProcess* keyProcess;
public:
	CXAdditionalOperDirectionWindow();
	virtual ~CXAdditionalOperDirectionWindow();

public slots:
	//! Назад.
	void onBackWindow();
	//Режим слежения
	void onBlockFollow();
	void onStartKeyboard();
	void onComporativeMove();
	void onAbsoluteMove();
	void onKeyboardFinished(int aExitCode, QProcess::ExitStatus aExitStatus);
	void onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue);
signals:
	void backWindow();
};

#endif /* CXADDITIONALOPERDIRECTIONWINDOW_H_ */
