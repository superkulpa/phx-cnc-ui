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
		QTreeWidgetItem* newItem = NULL;

		QDomElement root = doc.documentElement();
		QDomElement element = root.firstChildElement("parameters");
		element = element.firstChildElement("parameter");

		while (!element.isNull())
		{
			newItem = new QTreeWidgetItem(QStringList() << element.attribute("name") << element.attribute("value"));

			mTreeWidget->addTopLevelItem(newItem);
			element = element.nextSiblingElement("parameter");
		}

		element = root.firstChildElement("errors");
		element = element.firstChildElement("error");

		while (!element.isNull())
		{
			newItem = new QTreeWidgetItem(QStringList() << element.attribute("name") << element.attribute("value"));
			newItem->setForeground(0, Qt::red);

			mTreeWidget->addTopLevelItem(newItem);

			emit error(element.attribute("name"), element.attribute("value").toInt());

			element = element.nextSiblingElement("parameter");
		}
	}
}
