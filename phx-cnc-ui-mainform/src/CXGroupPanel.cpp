#include "CXGroupPanel.h"

//#include <QApplication>
//#include <QDesktopWidget>
#include <QtCore/QVariant>
#include <QtGui/QShortcut>

#include "CXTouchButton.h"
#include "CXWindowsManager.h"
#include "CXExitDialog.h"
#include "utils/flowlayout.h"
#include "CXUdpManager.h"
#include "utils/CXProcess.h"

CXGroupPanel::CXGroupPanel() :
    AXBaseWindow()
{
  setWindowFlags(Qt::Window | Qt::FramelessWindowHint/* | Qt::WindowStaysOnTopHint*/);
  /**/
  QLayout* centralLayout = new QHBoxLayout(this); //new FlowLayout(this);
  centralLayout->setMargin(8);
  centralLayout->setSpacing(8);
  /**/

  CXTouchButton* button = NULL;
//	int buttonSize = QApplication::desktop()->availableGeometry().width() / 20;
  for (int i = 1; i < 11; ++i)
  {
    button = new CXTouchButton(QString("F%1\n").arg(i), this);
    button->setFocusPolicy(Qt::NoFocus);

    QShortcut* shortcut = new QShortcut(QKeySequence(QString("F%1").arg(i)), this, 0, 0,
        Qt::ApplicationShortcut);
    connect(shortcut, SIGNAL(activated()), button, SIGNAL(clicked()));

//		button->setFont(QFont("", buttonSize / 7));
//		button->setFixedSize(buttonSize + 20, buttonSize);

    centralLayout->addWidget(button);

    mButtonsList.append(button);
  }

  QShortcut* shortcut = new QShortcut(QKeySequence("Ctrl+Q"), this, 0, 0, Qt::ApplicationShortcut);
  connect(shortcut, SIGNAL(activated()), qApp, SLOT(quit()));

  registerManager();
}

CXGroupPanel::~CXGroupPanel()
{

}

void
CXGroupPanel::setButtonsText(const QStringList& aTexts)
{
  for (int i = 0; i < mButtonsList.count(); ++i)
  {
    if (i < aTexts.count())
      mButtonsList.at(i)->setText(QString("F%1\n%2").arg(i + 1).arg(aTexts.at(i)));
  }
}

QPushButton*
CXGroupPanel::getButton(quint8 aButtonNumber)
{
  return mButtonsList.at(aButtonNumber);
}

void
CXGroupPanel::setButtonText(int aButtonNumber, const QString& aText)
{
  if (mButtonsList.at(aButtonNumber) != NULL)
  {
    mButtonsList.at(aButtonNumber)->setText(QString("F%1\n%2").arg(aButtonNumber).arg(aText));
  }
}

void
CXGroupPanel::setGroup()
{
  QPushButton* btn = qobject_cast<QPushButton*>(sender());

  mManager->setCurrentGroup(btn->property("groupName").toInt());
}

void
CXGroupPanel::directoryCommand()
{
  CXProcess::startAsynchro("fm.sh");
}

void
CXGroupPanel::macroCommand()
{
  CXProcess::startAsynchro("macro.sh");
}

void
CXGroupPanel::macroCommand2()
{
  CXProcess::startAsynchro("macro2.sh");
}

void
CXGroupPanel::onExit()
{
  CXExitDialog exitDialog(this);
  exitDialog.setWindowState(Qt::WindowFullScreen);
  int res = exitDialog.exec();

  switch (res)
  {
  //выключение.
  case 1:
    {
    mUdpManager->sendCommand(Commands::MSG_SECTION_START, Commands::MSG_CMD_SHUTDOWN, "0");
    CXProcess::execute("shutdown.sh", QStringList());
    QApplication::processEvents();
//		QApplication::exit(res);//quit();

    break;
  }
    //выход.
  case 2:
    {
    QApplication::exit(res);//quit();

    break;
  }
  }
}

void
CXGroupPanel::onDeviceEditShow()
{
  QPushButton* btn = qobject_cast<QPushButton*>(sender());

  mManager->setCurrentGroup(btn->property("groupName").toInt());

  AXBaseWindow::mUdpManager->sendCommand(Commands::MSG_SECTION_IO, "cmd_start", "0");
  //запускаем АЦП
  AXBaseWindow::mUdpManager->sendCommand(Commands::MSG_SECTION_IO, Commands::MSG_CMD_ADC_START, "0");
}

void
CXGroupPanel::onDeviceEditHide()
{
  QPushButton* btn = qobject_cast<QPushButton*>(sender());

  mManager->setCurrentGroup(btn->property("groupName").toInt());

  AXBaseWindow::mUdpManager->sendCommand(Commands::MSG_SECTION_IO, "cmd_stop", "0");
  //останавливаем АЦП
  AXBaseWindow::mUdpManager->sendCommand(Commands::MSG_SECTION_IO, Commands::MSG_CMD_ADC_STOP, "0");
}
