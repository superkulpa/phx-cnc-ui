#include "CXCompileEdit.h"

#include <QVBoxLayout>
#include <QHeaderView>
#include <QDomDocument>

CXCompileEdit::CXCompileEdit() : AXBaseWindow()
{
	QVBoxLayout* centralLayout = new QVBoxLayout(this);
	centralLayout->setMargin(5);

	mTreeWidget = new QTreeWidget(this);
	mTreeWidget->setColumnCount(2);
	mTreeWidget->setHeaderHidden(true);
	mTreeWidget->setRootIsDecorated(false);
	mTreeWidget->header()->setResizeMode(0, QHeaderView::ResizeToContents);

	mTreeWidget->setMinimumHeight(10);
	centralLayout->addWidget(mTreeWidget);

	registerManager();
}

CXCompileEdit::~CXCompileEdit()
{

}

void CXCompileEdit::setText(const QString& aText)
{
	mTreeWidget->clear();

	QDomDocument doc;

	if (doc.setContent(aText))
	{
		QDomElement root = doc.documentElement();
		QDomElement element = root.firstChildElement("parameters");
		element = element.firstChildElement("parameter");

		while (!element.isNull())
		{
			mTreeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList() << element.attribute("name") << element.attribute("value")));
			element = element.nextSiblingElement("parameter");
		}
	}
}
