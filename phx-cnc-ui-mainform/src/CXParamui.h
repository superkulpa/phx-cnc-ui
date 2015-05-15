#ifndef CXPARAMUI_H
#define CXPARAMUI_H

#include "AXBaseWindow.h"
#include <QComboBox>
#include <QDoubleSpinBox>
#include "utils/CXFtp.h"

#include "ui_CXParam.h"
#include "utils/CXProcess.h"

class CXParamUi : public AXBaseWindow
{
  Q_OBJECT

protected:
  CXProcess* mProcess;

public:
  CXParamUi();
  virtual ~CXParamUi();

  virtual void setVisible(bool visible);

private slots:
  void readKeys();
  void readValues();
  void clearLayout(QLayout* aLayout);
  void onKeyChange();
  int updateData();
  void repairDB();
  void save();
  void launchGC();
  void onButtonClicked();
  void onCommandReceive(const QString&, const QString&, const QString&);
  void onReiniCompleted(bool);
  void closeFtp();
  void onClose(bool aIsUpload);

  //! Слот завершения процесса компиляции файла пути.
  void
  onProcessFinish(int aExitCode, QProcess::ExitStatus aExitStatus);

  //! Слот на ошибки процесса компиляции файла пути.
  void
  onProcessError(QProcess::ProcessError aError);


  void loadFiles(bool aIsUpload, const QStringList& files, const char *member_onFtpSuccess);
	int
	executeDB (const QString& _values);

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
