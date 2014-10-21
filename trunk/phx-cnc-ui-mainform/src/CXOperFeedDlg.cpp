#include <QClipboard>

#include "CXOperFeedDlg.h"
#include "utils/iniFile.h"

int CXOperFeedDlg::createAndGetFeedDlg(QWidget *parent){
  CXOperFeedDlg dlg(parent);

  int res = dlg.exec();
  if(! res) return res;
  return 1;
}

CXOperFeedDlg::CXOperFeedDlg(QWidget *parent) :
    QDialog(parent)
{
  setupUi(this);
  setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);

//  std::string s = QApplication::applicationDirPath().toStdString() + "/jini/params.ini";
  iniFile = CIniFile("jini/params.ini");
  iniFile.ReadIniFile();
  int feeds[3];
  feeds[0] = QString::fromStdString(iniFile.GetValue("Move/ListFeed", "value", "1000")).toInt();
  feeds[1] = QString::fromStdString(iniFile.GetValue("Move/FastFeed", "value", "10000")).toInt();
  feeds[2] = QString::fromStdString(iniFile.GetValue("Move/LowFeed", "value", "100")).toInt();

  QRegExp regExp("(\\+|-)?\\d*\\.?\\d*");
  mFRegularEdit->setValidator(new QRegExpValidator(regExp, mFRegularEdit));
  mFRegularEdit->setText(QString::number(feeds[0]));

  mFFastEdit->setValidator(new QRegExpValidator(regExp, mFFastEdit));
  mFFastEdit->setText(QString::number(feeds[1]));

  mFSlowEdit->setValidator(new QRegExpValidator(regExp, mFSlowEdit));
  mFSlowEdit->setText(QString::number(feeds[2]));

  //
  connect(mCancelButton, SIGNAL(clicked()), this, SLOT(reject()));
  connect(apply, SIGNAL(clicked()), this, SLOT(accept()));

  connect(mButton0, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(mButton1, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(mButton2, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(mButton3, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(mButton4, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(mButton5, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(mButton6, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(mButton7, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(mButton8, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(mButton9, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(mButtonPlus, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(mButtonMinus, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(mButtonBackspace, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(mButtonDel, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
  connect(mButtonEnter, SIGNAL(clicked()), this, SLOT(onButtonClicked()));

}

//
CXOperFeedDlg::~CXOperFeedDlg()
{

}

//

void CXOperFeedDlg::onButtonClicked()
{
  QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
  QLineEdit* lineEdit = qobject_cast<QLineEdit*>(focusWidget());

  if (clickedButton != NULL && lineEdit != NULL)
  {
    static QMap<QKeySequence, QString> keyValues;
    if(keyValues.empty()){
      keyValues.insert(Qt::Key_0, "0");
      keyValues.insert(Qt::Key_1, "1");
      keyValues.insert(Qt::Key_2, "2");
      keyValues.insert(Qt::Key_3, "3");
      keyValues.insert(Qt::Key_4, "4");
      keyValues.insert(Qt::Key_5, "5");
      keyValues.insert(Qt::Key_6, "6");
      keyValues.insert(Qt::Key_7, "7");
      keyValues.insert(Qt::Key_8, "8");
      keyValues.insert(Qt::Key_9, "9");
      keyValues.insert(Qt::Key_Plus, "+");
      keyValues.insert(Qt::Key_Minus, "-");
    }

    if (keyValues.contains(clickedButton->shortcut()))
    {
      QString text;
      text = keyValues.value(clickedButton->shortcut());

      if (text == "+" || text == "-")
      {
        QString s = lineEdit->text().replace(QRegExp("(\\+|-)"), "");
        lineEdit->setText(text + s);
      }
      else
      {
        QClipboard* clipboard = QApplication::clipboard();
        clipboard->setText(text);
        lineEdit->paste();
      }

      return;
    }

    switch (clickedButton->shortcut())
    {
    case Qt::Key_Backspace:
      {
      lineEdit->backspace();

      break;
    }
    case Qt::Key_Delete:
      {
      lineEdit->del();

      break;
    }
    case Qt::Key_Enter:
      {
        accept();
      break;
    }
    }
  }
}

//
void
CXOperFeedDlg::accept()
{
  //проверяем значения
  int maxFeed = QString::fromStdString(iniFile.GetValue("Move/MaxFeed", "value", "100")).toInt();
  int feeds[3];
  feeds[0] = mFRegularEdit->text().toInt();
  if(feeds[0] > maxFeed) feeds[0] = maxFeed;
  feeds[1] = mFFastEdit->text().toInt();
  if(feeds[1] > maxFeed) feeds[1] = maxFeed;
  feeds[2] = mFSlowEdit->text().toInt();
  if(feeds[2] > maxFeed) feeds[2] = maxFeed;

  iniFile.SetValue("Move/ListFeed", "value", QString::number(feeds[0]).toStdString());
  iniFile.SetValue("Move/FastFeed", "value", QString::number(feeds[1]).toStdString());
  iniFile.SetValue("Move/LowFeed", "value", QString::number(feeds[2]).toStdString());
  iniFile.WriteIniFile();

  QDialog::accept();
}
