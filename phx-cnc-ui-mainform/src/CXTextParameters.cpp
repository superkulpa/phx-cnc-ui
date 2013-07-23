#include "CXTextParameters.h"

#include <QVBoxLayout>
#include <QTextEdit>

#include "CXUdpManager.h"

CXTextParameters::CXTextParameters() :
    AXBaseWindow()
{
  mIsError = false;

  QVBoxLayout* centralLayout = new QVBoxLayout(this);
  centralLayout->setMargin(5);

  mTextEdit = new QTextEdit(this);
  mTextEdit->setReadOnly(true);
  mTextEdit->setMinimumHeight(10);
  mTextEdit->setPlainText(trUtf8("Нет сообщений"));
  centralLayout->addWidget(mTextEdit);

  connect(mUdpManager, SIGNAL(commandReceived(const QString&, const QString&, const QString&)),
      this, SLOT(onCommandReceive(const QString&, const QString&, const QString&)));

  registerManager();
}

CXTextParameters::~CXTextParameters()
{

}


void CXTextParameters::onEmptyAlarmsList(){
  mIsError = false;
  mTextEdit->setPlainText(trUtf8("Нет аварий и предупреждений"));
}

void
CXTextParameters::onResetAlarms()
{
  mUdpManager->sendCommand(Commands::MSG_SECTION_ALARM, Commands::MSG_CMD_RESET_ALARMS, "0");

  mTextEdit->clear();
  onEmptyAlarmsList();
}

void
CXTextParameters::onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue)
{
  if (aSection == QString::fromStdString(Commands::MSG_SECTION_ALARM))
  {
    if (!mIsError || aCommand == QString::fromStdString(Commands::MSG_STATE_MULTI_ALARM))
    {
      mTextEdit->clear();
    }

    mIsError = true;

    QStringList alarms = aValue.split(";", QString::SkipEmptyParts);

    if (aCommand == QString::fromStdString(Commands::MSG_STATE_MULTI_ALARM)
        || aCommand == QString::fromStdString(Commands::MSG_STATE_MULTI_ALARM_ADD))
    {
      QString buffer;

      for (int i = 0; i < alarms.count(); i++)
      {
        buffer = alarms.at(i).trimmed();
        qDebug() << buffer;
        if (!buffer.contains(QString().fromUtf8("1.Блокировка операций")))
        if (!mTextEdit->toPlainText().contains(buffer))
        {
          mTextEdit->append(buffer);
        }
      }
    }

    if (aCommand == QString::fromStdString(Commands::MSG_STATE_MULTI_ALARM_REMOVE))
    {
      QString text = mTextEdit->toPlainText();
      QString buffer;

      for (int i = 0; i < alarms.count(); i++)
      {
        buffer = alarms.at(i).trimmed();

        if (text.contains(buffer))
        {
          text.replace(buffer, "");
        }
      }
//			if (text == "\n") text = "";

      mTextEdit->setPlainText(text);
    }

    //чистим лишнее
    QString errorText = mTextEdit->toPlainText();
    static const QRegExp regExp("^\n|^ \n");
    while (errorText.contains(regExp))
      errorText.replace(regExp, "");

    mTextEdit->setPlainText(errorText);

    //errorText = mTextEdit->toPlainText();
    //отослать верхнюю аварию
    int indx = errorText.indexOf("\n");
    if (indx >= 0) errorText = errorText.mid(0, indx );

    emit errorReceived(errorText);

    if (mTextEdit->toPlainText().isEmpty())
    {
      onEmptyAlarmsList();
//      mIsError = false;
//      mTextEdit->setPlainText(trUtf8("Нет аварий и предупреждений"));
    }
  }
}
