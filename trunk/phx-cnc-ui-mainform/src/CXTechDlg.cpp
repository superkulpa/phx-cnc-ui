#include <QtGui>

#include <QRegExpValidator>
#include <QClipboard>
#include <QFile>
#include <QDomDocument>
#include <QTextStream>
#include <QMessageBox>
#include <QKeyEvent>

#include "CXWarmingUpDlg.h"
#include "CXTechDlg.h"

CXTechDlg::CXTechDlg(QObject* _master, const MTechs& _techs, const MTechs& _opts)
{
  Ui::dlgTechnology::setupUi(this);
  horizontalLayout = new QHBoxLayout(this);
  horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
  verticalLayout->addLayout(horizontalLayout);
  verticalLayout->addStretch();
  std::for_each(_techs.begin(), _techs.end(), [this](const MTechsItem _item){
    auto btn = new CXTouchButton(this);
    btn->setProperty("tech", _item.first);
    btn->setText(_item.second);
    connect(btn, SIGNAL(clicked()), this, SLOT(onButtonClicked()));

    horizontalLayout->addWidget(btn);
    btnList.push_back(btn);
  });

  std::for_each(_opts.begin(), _opts.end(), [this](const MTechsItem _item){
		ckBox.push_front( new QCheckBox(this) );
		ckBox.front()->setProperty("opt", _item.first);
		ckBox.front()->setText(_item.second);
		verticalLayout->addWidget(ckBox.front());
  });
 }

CXTechDlg::~CXTechDlg()
{

}


void
CXTechDlg::onButtonClicked()
{
  QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
  QString prop = clickedButton->property("tech").toString();

  std::for_each(ckBox.begin(), ckBox.end(), [&prop](const QCheckBox* _item){
  	if(_item->isChecked()) prop += ":" + _item->property("opt").toString();
  } );
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
CXTechDlg::create(QObject* _master, const MTechs& _techs, const MTechs& _opts, const char* _member)
{
  if(techDlg != NULL) return techDlg;
  techDlg = new CXTechDlg(_master, _techs, _opts);
  if(_member) techDlg->registerTechnology(_master, _member);

  return techDlg;
}

void
CXTechDlg::setOptions (QString opt_name, int value)
{
  std::for_each(ckBox.begin(), ckBox.end(), [opt_name, value](QCheckBox* _item){
  	if(_item->property("opt").toString() == opt_name)
  		_item->setCheckState(value!=0?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
  } );
}

CXTechDlg* CXTechDlg::getInstance(){
//  assert(techDlg);
  return techDlg;
}
