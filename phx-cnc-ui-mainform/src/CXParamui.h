#ifndef CXPARAMUI_H
#define CXPARAMUI_H

#include "AXBaseWindow.h"
#include <QComboBox>
#include <QDoubleSpinBox>
#include "utils/CXFtp.h"

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
  void loadFiles(bool aIsUpload, const QStringList& files, const char *member_onFtpSuccess);
  void onButtonClicked();
  void onCommandReceive(const QString&, const QString&, const QString&);
  void onReiniCompleted(bool);
  void closeFtp();
  void onFtpSuccess_step1(bool);

  void onClose(bool aIsUpload);
  signals:
  void iniSaved();

private:
	Ui::CXParamUiClass ui;
	QGridLayout* mValuesLayout;
        CXFtp* mFtp;
        QString lastStateValue;

	QString mType;
	QString mLastUpdateKey;
	QList <QDoubleSpinBox*> mEditors;
	QList <QComboBox*> mKeyList;
};

#endif // CXPARAMUI_H
