#include "CXWarmingUpDlg.h"

#include <QRegExpValidator>
#include <QClipboard>
#include <QFile>
#include <QDomDocument>
#include <QTextStream>
#include <QMessageBox>
#include <QKeyEvent>

#include "CXUdpManager.h"

CXWarmingUpDlg::CXWarmingUpDlg(QObject* _master)
{
  Ui::WarmingUp::setupUi(this);
  stage = _ticTac;
  btContinueBreak->setText(QString().fromUtf8("Продолжить"));
  connect(btContinueBreak, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
 }

CXWarmingUpDlg::~CXWarmingUpDlg()
{

}

void
CXWarmingUpDlg::onButtonClicked()
{
  switch(stage){
  case _ticTac:
    btContinueBreak->setText(QString().fromUtf8("Прервать"));
    stage = _continue;
    break;
  case _continue:
    close();
    break;
  }
}

void CXWarmingUpDlg::onWarmProcess(int _procent){
  //

}
