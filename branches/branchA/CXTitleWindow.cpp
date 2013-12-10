#include "CXTitleWindow.h"

#include <QVBoxLayout>
#include <QApplication>
#include <QFileInfo>

#include "CXUdpManager.h"

CXTitleWindow::CXTitleWindow() :
    AXBaseWindow()
{
  setGroupNumber(0);

  QHBoxLayout* centralLayout = new QHBoxLayout(this);
  centralLayout->setMargin(7);

  mStopButton = new CXTouchButton(trUtf8("          Стоп операций          "), this);
  mStopButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
  mStopButton->setFocusPolicy(Qt::NoFocus);
  centralLayout->addWidget(mStopButton);

  mCPStateLabel = new QLabel(trUtf8("Ручное упр."), this);
  mCPStateLabel->setObjectName("mCPStateLabel");
  mCPStateLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
  mCPStateLabel->setAlignment(Qt::AlignCenter);
  centralLayout->addWidget(mCPStateLabel);

  mControlButton = new CXTouchButton(trUtf8("Управление выкл."), this);
  mControlButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
  mControlButton->setFocusPolicy(Qt::NoFocus);
  centralLayout->addWidget(mControlButton);

  mFileLabel = new QLabel(this);
  mFileLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
  centralLayout->addWidget(mFileLabel);

  registerManager();

  connect(mControlButton, SIGNAL(clicked()), this, SLOT(onControl()));

  connect(mStopButton, SIGNAL(clicked()), this, SLOT(onStopOperation()));

  connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)),
      this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));
}

CXTitleWindow::~CXTitleWindow()
{

}

void
CXTitleWindow::onFileOpen(const QString& aFileName)
{
  mFileName = QFontMetrics(font()).elidedText(aFileName, Qt::ElideLeft, width() - 10);
  mFileLabel->setText(mFileName);
}

void
CXTitleWindow::onErrorReceive(const QString& aError)
{
  if (aError.isEmpty())
  {
    mFileLabel->setText(mFileName);
    mFileLabel->setStyleSheet("");
    mFileLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
  }
  else
  {
    mFileLabel->setText(aError);
    mFileLabel->setStyleSheet("color: red");
    mFileLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
  }
}

void
CXTitleWindow::onControl()
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_CONTROL,
      Commands::MSG_VALUE_INVERT);
}

void
CXTitleWindow::onStopOperation(){
  mUdpManager->sendCommand(Commands::MSG_SECTION_OPERATOR, Commands::MSG_CMD_STOP_OPERATION,
      Commands::MSG_VALUE_ZERO);
}


void
CXTitleWindow::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{
  if (aSection == QString::fromStdString(Commands::MSG_SECTION_OPERATOR))
  {
    if (aCommand == QString::fromStdString(Commands::MSG_STATE_CONTROL))
    {
      if (aValue == QString::fromStdString(Commands::MSG_VALUE_ON))
      {
        mControlButton->setStyleSheet("background-color: green;");
        mControlButton->setText(trUtf8("Управление вкл."));
      }
      else
      {
        mControlButton->setStyleSheet("");
        mControlButton->setText(trUtf8("Управление выкл."));
      }
    }
    else if (aCommand == QString::fromStdString(Commands::MSG_STATE_STOP_CP))
    {
      mCPStateLabel->setText(trUtf8("Ручное упр."));
    }
    else if (aCommand == QString::fromStdString(Commands::MSG_STATE_RUN_CP))
    {
      if (aValue == QString::fromStdString(Commands::MSG_VALUE_HAND))
        mCPStateLabel->setText(trUtf8("Ручное упр."));
      else if (aValue == QString::fromStdString(Commands::MSG_VALUE_FORWARD))
        mCPStateLabel->setText(trUtf8("Вперед"));
      else if (aValue == QString::fromStdString(Commands::MSG_VALUE_BACKWARD))
        mCPStateLabel->setText(trUtf8("Назад"));
      else if (aValue == QString::fromStdString(Commands::MSG_VALUE_FIND_TRJ))
        mCPStateLabel->setText(trUtf8("Поиск контура"));
    }
  }

  if (aSection == QString::fromStdString(Commands::MSG_SECTION_ALARM))
  {
    if (aCommand == QString::fromStdString(Commands::MSG_STATE_INFO_ALARM))
    {
      if (aValue == "0")
      {
        mFileLabel->setText(mFileName);
        mFileLabel->setStyleSheet("");
      }
      else
      {
        mFileLabel->setText(aValue);
        mFileLabel->setStyleSheet("background-color: red;");
      }
    }
  }
}
