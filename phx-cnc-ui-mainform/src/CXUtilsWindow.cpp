#include "CXUtilsWindow.h"

#include <QVBoxLayout>
#include <QApplication>
#include <QDir>
#include <QDomDocument>
#include <QMessageBox>

#include "CXTouchButton.h"

CXUtilsWindow::CXUtilsWindow() :
    AXBaseWindow()
{
  setGroupNumber(101);
  mProcess = NULL;

  QVBoxLayout* centralLayout = new QVBoxLayout(this);
  centralLayout->setMargin(7);
  centralLayout->setSpacing(6);

  mTreeWidget = new QTreeWidget(this);
  mTreeWidget->setHeaderHidden(true);
  mTreeWidget->setRootIsDecorated(false);

  centralLayout->addWidget(mTreeWidget);
  /**/
  QHBoxLayout* buttonLayout = new QHBoxLayout;
  buttonLayout->setMargin(0);
  buttonLayout->setSpacing(6);

  buttonLayout->addStretch();

  CXTouchButton* executeButton = new CXTouchButton(trUtf8("Запустить"), this);
  buttonLayout->addWidget(executeButton);

  CXTouchButton* closeButton = new CXTouchButton(trUtf8("Закрыть"), this);
  closeButton->setObjectName("mCloseButton");
  buttonLayout->addWidget(closeButton);
  /**/
  centralLayout->addLayout(buttonLayout);

  connect(executeButton, SIGNAL(clicked()), this, SLOT(onExecute()));
  connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

  registerManager();

  load("utils.xml");
}

CXUtilsWindow::~CXUtilsWindow()
{

}

void
CXUtilsWindow::load(const QString& aFileName)
{
  QDomDocument doc;

  QFile xmlFile(aFileName);
  if (!xmlFile.open(QIODevice::ReadOnly))
    return;

  QString msg;
  int line;
  int column;

  if (doc.setContent(&xmlFile, &msg, &line, &column))
  {
    QDomElement root = doc.documentElement();
    QDomElement element = root.firstChildElement("util");

    QTreeWidgetItem* newItem = NULL;

    while (!element.isNull())
    {
      newItem = new QTreeWidgetItem(QStringList() << element.attribute("name"));
      newItem->setData(0, Qt::UserRole + 100, element.attribute("cmd"));

      mTreeWidget->addTopLevelItem(newItem);
      element = element.nextSiblingElement("util");
    }
  }

  xmlFile.close();
}

void
CXUtilsWindow::onExecute()
{
  QTreeWidgetItem* curItem = mTreeWidget->currentItem();

  if (curItem != NULL)
  {
    QString command = curItem->data(0, Qt::UserRole + 100).toString();
    mProcess = new CXProcess(this);

    connect(mProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this,
        SLOT(onProcessFinish(int, QProcess::ExitStatus)));
    connect(mProcess, SIGNAL(error(QProcess::ProcessError)), this,
        SLOT(onProcessError(QProcess::ProcessError)));
    mBox = new QMessageBox(QMessageBox::Information,trUtf8("Идет отработка"),trUtf8("\tПрервать\t"),QMessageBox::Ok,this);
    mBox->setMinimumWidth(600);
    mBox->show();
    mProcess->start(command);
  }
}

void
CXUtilsWindow::onProcessFinish(int aExitCode, QProcess::ExitStatus aExitStatus)
{
  Q_UNUSED(aExitCode)

  if (aExitStatus == QProcess::NormalExit)
  {
    mBox->setText(trUtf8("\tЗавершено\t"));
  }
  mProcess->deleteLater();
  mProcess = NULL;
}

void
CXUtilsWindow::onProcessError(QProcess::ProcessError aError)
{
  Q_UNUSED(aError)

  QMessageBox::critical(NULL, trUtf8("Ошибка"), qobject_cast<QProcess*>(sender())->errorString());
  mBox->setText(trUtf8("Ошибка"));
  mProcess->deleteLater();
  mProcess = NULL;
}
