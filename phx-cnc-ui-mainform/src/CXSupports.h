#ifndef CXSUPPORTS_H
#define CXSUPPORTS_H

#include "AXBaseWindow.h"
#include <QtGui/QComboBox>

#include "ui_CXSupports.h"

class CXSupportsWindow : public AXBaseWindow
{
	Q_OBJECT

public:
	CXSupportsWindow();
	~CXSupportsWindow();

  virtual void setVisible(bool visible);
private slots:
	void onButtonClicked();
	void onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue);

private:
	Ui::CXSupportsClass ui;
  QList<QAbstractButton*> cutButtons;

};

#endif // CXPARAMUI_H
