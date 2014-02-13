#include "CXWarmingUpDlg.h"

#include <QRegExpValidator>
#include <QClipboard>
#include <QFile>
#include <QDomDocument>
#include <QTextStream>
#include <QMessageBox>
#include <QKeyEvent>

#include "CXTechDlg.h"

CXTechDlg::CXTechDlg(QObject* _master, const MTechs& _techs)
{
  Ui::dlgTechnology::setupUi(this);
  std::for_each(_techs.begin(), _techs.end(), [this](const MTechsItem _item){
    auto btn = new CXTouchButton(this);
    btn->setProperty("tech", _item.first);
    btn->setText(_item.second);
    connect(btn, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    horizontalLayout->addWidget(btn);
    btnList.push_back(btn);
  });
 }

CXTechDlg::~CXTechDlg()
{

}


void
CXTechDlg::onButtonClicked()
{
  QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
  const QString prop = clickedButton->property("tech").toString();
  emit postTechnology(prop);
  hide();
}


void
CXTechDlg::registerTechnology(QObject* _receiver, const char* _member)
{
  connect(this, SIGNAL(postTechnology(QString)), _receiver, _member);
}

static CXTechDlg* techDlg = NULL;

CXTechDlg*
CXTechDlg::create(QObject* _master, const MTechs& _techs, const char* _member)
{
  if(techDlg != NULL) return techDlg;
  techDlg = new CXTechDlg(_master, _techs);
  if(_member) techDlg->registerTechnology(_master, _member);

  return techDlg;
}

CXTechDlg* CXTechDlg::getInstance(){
//  assert(techDlg);
  return techDlg;
}
