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
  btContinue->setText(QString().fromUtf8("Продолжить"));
  btContinue->setMinimumHeight(75);
  btBreak->setText(QString().fromUtf8("Прервать"));
  btBreak->setMinimumHeight(75);
  connect(btContinue, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(btBreak, SIGNAL(clicked()), this, SLOT(onButtonClickedBreak()));
  connect(this, SIGNAL(postStateWaiting(int)), this, SLOT(onWarmProcess(int)));
 }

CXWarmingUpDlg::~CXWarmingUpDlg()
{

}


void
CXWarmingUpDlg::onButtonClicked()
{
  switch(stage){
  case _ticTac:
    btContinue->hide();//setText(QString().fromUtf8("Прервать"));
    stage = _continue;
    emit postCmdWaiting(_continue);
    break;
  case _continue:
    emit postCmdWaiting(_break);
    hide();//close();
    break;
  default:
    break;
  }
}

void CXWarmingUpDlg::onButtonClickedBreak(){
  stage = _continue;
  onButtonClicked();
}

void
CXWarmingUpDlg::setVisible(bool visible)
{
  if(visible == false){
    stage = _ticTac;
    progressBar->setValue(0);
    btContinue->show();//setText(QString().fromUtf8("Продолжить"));
  }
  QDialog::setVisible(visible);
}

void CXWarmingUpDlg::onWarmProcess(int _percent){
  //
  progressBar->setValue(_percent);
  if(_percent == 0 || _percent >= 100){
//    stage = _continue;
//    onButtonClicked();
    hide();
  }else
  if(isHidden()) show();
}

void
CXWarmingUpDlg::setStateWaiting(const QString& _aValue)
{
  int _percent = _aValue.toInt();
  if(_percent == 0)
    hide();
  else
    emit postStateWaiting(_percent);
}

void
CXWarmingUpDlg::registerContinueBreak(QObject* _receiver, const char* _member)
{
  connect(this, SIGNAL(postCmdWaiting(int)), _receiver, _member);
}
