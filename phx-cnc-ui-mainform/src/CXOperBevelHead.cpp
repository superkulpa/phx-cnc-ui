#include "CXOperBevelHead.h"

#include <QtCore/QtCore>
#include <QtGui/QResizeEvent>

#include "ui_CXOperBevelHead.h"
#include "CXUdpManager.h"

#define INDX_AXIS_A 3
#define INDX_AXIS_C 5
#define SIGN_DEG 00B0
static QMap<QString, QPointer<QLabel> > lPos;

CXOperBevelHead::CXOperBevelHead() :
  AXBaseWindow(),
    ui(new Ui::CXOperBevelHead)
{
    ui->setupUi(this);
    ui->label_3->setText(QString::fromUtf8("в 0.1\u00B0"));
    ui->label_4->setText(QString::fromUtf8("в 0.1\u00B0"));
    ui->lposA->setText(QString::fromUtf8("0\u00B0"));
    ui->lposC->setText(QString::fromUtf8("0\u00B0"));

    connect(ui->mButton0, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->mButton1, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->mButton2, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->mButton3, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->mButton4, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->mButton5, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->mButton6, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->mButton7, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->mButton8, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->mButton9, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->mButtonBackspace, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->mButtonDel, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->mButtonPlus, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->mButtonMinus, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
//    connect(mButtonEnter, SIGNAL(clicked()), this, SLOT(onButtonClicked()));

    connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)),
        this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));

    QRegExp regExp("(\\+|-)?\\d*\\.?\\d*");
    ui->eposA->setValidator(new QRegExpValidator(regExp, ui->eposA));
    ui->eposC->setValidator(new QRegExpValidator(regExp, ui->eposC));
    ui->nextWindow->setObjectName(QString::fromUtf8("bevelNextWindow"));

    lPos["3"] = (ui->lposA);
    lPos["5"] = (ui->lposC);

    connect(ui->bAmove, SIGNAL(clicked()), this, SLOT(onAMoveClicked()));
    connect(ui->bCmove, SIGNAL(clicked()), this, SLOT(onCMoveClicked()));
    connect(ui->bGoToZero, SIGNAL(clicked()), this, SLOT(onToZeroClicked()));
    connect(ui->bLockZero, SIGNAL(clicked()), this, SLOT(onLockZeroClicked()));
    connect(ui->bBlockMove, SIGNAL(clicked()), this, SLOT(onBlockMoveClicked()));

    connect(ui->nextWindow, SIGNAL(clicked()), this, SLOT(onNextWindow()));
    ui->eposC->setEnabled(false);
    ui->bCmove->setEnabled(false);

    registerManager();
}

CXOperBevelHead::~CXOperBevelHead()
{
    delete ui;
}

void
CXOperBevelHead::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{
  if (aSection ==  (Commands::MSG_SECTION_MOVE))
  {
    //Позиция осей.
    if (aCommand ==  (Commands::MSG_STATE_POS_AXIS))
    {
      QStringList axisList = aValue.split(",");
      for (auto litem: axisList)
      {//udp:MM#pos_axis#3=49599$
        QStringList valueList = litem.split("=");
        if( valueList.size() != 2 ) break;
        QLabel* label = lPos[valueList[0]];
        if(label == nullptr) break;
        double deg = valueList[1].toDouble() / 1000.0;
        label->setText(trUtf8("%1\u00B0").arg(deg, 0, 'f', 1));
      }
    }else if (aCommand ==  (Commands::MSG_STATE_MODE_BLOCK_FOLLOW))
    {
      if (aValue ==  (Commands::MSG_VALUE_ON))
        ui->bBlockMove->setStyleSheet("background-color: green;");
      else
        ui->bBlockMove->setStyleSheet("");
    }

  }
}

void
CXOperBevelHead::onNextWindow()
{
//  lower();
  emit nextWindow();
}

void
CXOperBevelHead::onButtonClicked()
{
  QAbstractButton* button = qobject_cast<QAbstractButton*>(sender());

  if (button != NULL && !button->shortcut().isEmpty())
  {
    QString text = button->shortcut().toString();
    QWidget* focusedWidget = focusWidget();
    if( focusedWidget->metaObject()->className() ==  QLineEdit::staticMetaObject.className() &&
	(text == "+" || text == "-"))
    {
      QLineEdit* lineEdit = static_cast<QLineEdit*>(focusedWidget);
      QString s = lineEdit->text().replace(QRegExp("(\\+|-)"), "");
      lineEdit->setText(text + s);
    }

    int keyCode = button->shortcut()[0];

    QKeyEvent keyPress(QEvent::KeyPress, keyCode, Qt::NoModifier, button->shortcut().toString());
    QApplication::sendEvent(focusedWidget, &keyPress);

    QKeyEvent keyRelease(QEvent::KeyRelease, keyCode, Qt::NoModifier,
        button->shortcut().toString());
    QApplication::sendEvent(focusedWidget, &keyRelease);

    return;
  }
}

void
CXOperBevelHead::onAMoveClicked ()
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR,
			   Commands::MSG_CMD_HAND_ABSOLUTE_MOVING,
			   QString("%1=%2").arg(INDX_AXIS_A).arg(ui->eposA->text().toInt() * 100) );
}

void
CXOperBevelHead::onCMoveClicked ()
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR,
			   Commands::MSG_CMD_HAND_ABSOLUTE_MOVING,
			   QString("%1=%2").arg(INDX_AXIS_C).arg(ui->eposC->text().toInt() * 100) );
}

void
CXOperBevelHead::onToZeroClicked ()
{
  QString res = QString("%1=0,%2=0").arg(INDX_AXIS_A).arg(INDX_AXIS_C);
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR,
			   Commands::MSG_CMD_HAND_ABSOLUTE_MOVING, res);
}

void
CXOperBevelHead::onLockZeroClicked ()
{
  QString res = QString("%1=0,%2=0").arg(INDX_AXIS_A).arg(INDX_AXIS_C);
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR,
			   Commands::MSG_CMD_SET_ABS_ZERO, res);
}

void CXOperBevelHead::onBlockMoveClicked(){
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_MODE_BLOCK_FOLLOW, Commands::MSG_VALUE_INVERT);
}
