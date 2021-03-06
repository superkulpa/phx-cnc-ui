#include "CXTurnDialog.h"

#include <QRegExpValidator>
#include <QClipboard>
#include <QFile>
#include <QDomDocument>
#include <QTextStream>
#include <QMessageBox>
#include <QKeyEvent>

CXTurnDialog::CXTurnDialog() :
    AXBaseWindow()
{
  setupUi(this);

  setGroupNumber(100);

  connect(mCloseButton, SIGNAL(clicked()), this, SLOT(close()));
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

  connect(mWriteRotationButton, SIGNAL(clicked()), this, SLOT(onWriteRotation()));
  connect(mCalculateRotationButton, SIGNAL(clicked()), this, SLOT(onCalculateRotation()));
  connect(mFlipXButton, SIGNAL(clicked()), this, SLOT(onWriteFlipX()));
  connect(mFlipYButton, SIGNAL(clicked()), this, SLOT(onWriteFlipY()));
  connect(mWriteScaleButton, SIGNAL(clicked()), this, SLOT(onWriteScale()));

  mRotateEdit->setValidator(new QRegExpValidator(QRegExp("(\\+|-)?\\d+"), mRotateEdit));
  mScaleEdit->setValidator(new QRegExpValidator(QRegExp("(\\+|-)?\\d+"), mScaleEdit));

	invValue = getAttribute("RSI.Inverse").toInt();

	registerManager();
}

CXTurnDialog::~CXTurnDialog()
{

}

void
CXTurnDialog::keyPressEvent(QKeyEvent* e)
{
  if (e->key() == Qt::Key_Escape)
  {
    close();
  }

  AXBaseWindow::keyPressEvent(e);
}

void
CXTurnDialog::onButtonClicked()
{
  QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
  QLineEdit* lineEdit = qobject_cast<QLineEdit*>(focusWidget());

  if (clickedButton != NULL && lineEdit != NULL)
  {
    QMap<QKeySequence, QString> keyValues;
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

      break;
    }
    }
  }
}

void
CXTurnDialog::onWriteRotation()
{
  saveAttribute("RSI.RotationAngle", mRotateEdit->text());
  emit compileNeeded();
}

void
CXTurnDialog::onCalculateRotation()
{
}

void
CXTurnDialog::onWriteFlipX()
{
  if(invValue & 1) invValue = (invValue & ~1) & (invValue & 2);
  else invValue |= 1;
  QString value; value.setNum(invValue & 0xF);
	saveAttribute("RSI.Inverse", value);
	emit compileNeeded();
}

void
CXTurnDialog::onWriteFlipY()
{
  if(invValue & 2) invValue = (invValue & ~2) & (invValue & 1);
  else invValue |= 2;
  QString value; value.setNum(invValue & 0xF);
  saveAttribute("RSI.Inverse", value);
	emit compileNeeded();
}

void
CXTurnDialog::onWriteScale()
{
	saveAttribute("RSI.Scale", mScaleEdit->text());
	emit compileNeeded();
}

QString CXTurnDialog::getAttribute(const QString& aAttributeName){
  QFile configFile(/*QApplication::applicationDirPath() +*/ "jini/compiler0.cfg");
  configFile.open(QIODevice::ReadOnly);

  QDomDocument doc;
  doc.setContent(&configFile);
  QString value = "";
  QDomElement domElement = doc.documentElement();
  domElement = domElement.firstChildElement("parameters");

  if (!domElement.isNull())
  {
    domElement = domElement.firstChildElement("parameter");

    while (!domElement.isNull())
    {
      if (domElement.attribute("name") == aAttributeName)
      {
        value = domElement.attribute("value", "0");

        break;
      }

      domElement = domElement.nextSiblingElement("parameter");
    }
  }

  configFile.close();
  return value;
}

void CXTurnDialog::saveAttribute(const QString& aAttributeName, const QString& aAttributeValue)
{
  QFile configFile("jini/compiler0.cfg");
  configFile.open(QIODevice::ReadOnly);

  QDomDocument doc;
  doc.setContent(&configFile);

  QDomElement domElement = doc.documentElement();
  domElement = domElement.firstChildElement("parameters");

  if (!domElement.isNull())
  {
    domElement = domElement.firstChildElement("parameter");

    while (!domElement.isNull())
    {
      if (domElement.attribute("name") == aAttributeName)
      {
        domElement.setAttribute("value", aAttributeValue);

        break;
      }

      domElement = domElement.nextSiblingElement("parameter");
    }
  }

  configFile.close();

  configFile.open(QIODevice::WriteOnly);
  QTextStream out(&configFile);
  out.setCodec("UTF-8");

  doc.save(out, 2);

  configFile.close();
}
