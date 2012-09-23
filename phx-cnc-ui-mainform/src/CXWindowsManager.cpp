#include "CXWindowsManager.h"

#include <QList>
#include <QDesktopWidget>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDomDocument>
#include <QMouseEvent>

#include "CXPanelWindow.h"

CXWindowsManager::CXWindowsManager()
{
	mList.append(QApplication::desktop());
	mList.append(QApplication::desktop());

	mEvents << QEvent::MouseButtonDblClick << QEvent::MouseButtonPress << QEvent::MouseMove << QEvent::MouseButtonRelease << QEvent::Wheel << QEvent::KeyPress << QEvent::FocusIn << QEvent::WindowActivate << QEvent::HoverMove;
	qApp->installEventFilter(this);

	mIsFreeze = false;
	mGroupNumber = 0;
}

CXWindowsManager::~CXWindowsManager()
{
	save("windows.xml");
}

void CXWindowsManager::addWindow(AXBaseWindow* aWindow)
{
	if (mList.contains(aWindow)) return;

	mList.append(aWindow);

	connect(aWindow, SIGNAL(geometryChanged(const QRect&, bool)), SLOT(windowGeometryChange(const QRect&, bool)));
}

void CXWindowsManager::setCurrentGroup(int aGroupNumber)
{
	if (mGroupNumber == aGroupNumber) return;

	mGroupNumber = aGroupNumber;
	AXBaseWindow* curWindow = NULL;

	QList<QWidget*>::iterator iter;
	for (iter = mList.begin(); iter != mList.end(); ++iter)
	{
		curWindow = qobject_cast<AXBaseWindow*>(*iter);

		if (curWindow == NULL) continue;

		if (curWindow->groupNumber() >= 0 && curWindow->groupNumber() != mGroupNumber) curWindow->hide();
		else if (curWindow->isHidden()) curWindow->show();
	}
}

int CXWindowsManager::currentGroup()
{
	return mGroupNumber;
}

void CXWindowsManager::save(const QString& aFileName)
{
	QFile xmlFile(aFileName);

	if (!xmlFile.open(QIODevice::WriteOnly)) return;

	QTextStream out(&xmlFile);
	out.setCodec("UTF-8");

	out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<Settings>\n";
	out << QString("	<manager freeze=\"%1\"/>").arg(mIsFreeze);

	AXBaseWindow* curWindow = NULL;
	int count = 0;

	QList<QWidget*>::iterator iter;
	for (iter = mList.begin(); iter != mList.end(); ++iter)
	{
		curWindow = qobject_cast<AXBaseWindow*>(*iter);

		if (curWindow != NULL)
		{
			count++;

			out << QString("	<window_%1 freeze=\"%2\">%3</window_%1>\n").arg(count).arg(curWindow->isFreeze()).arg(curWindow->saveGeometry().toBase64().data());
		}
	}

	out << "</Settings>";
}

void CXWindowsManager::load(const QString& aFileName)
{
	QFile xmlFile(aFileName);

	if (!xmlFile.open(QIODevice::ReadOnly)) return;

	QDomDocument document("");
	if (!document.setContent(&xmlFile)) return;

	QDomElement root = document.documentElement();

	bool isFreeze = mIsFreeze;

	if (!root.isNull())
	{
		QDomElement element = root.firstChildElement();
		AXBaseWindow* curWindow = NULL;

		while (!element.isNull())
		{
			if (element.tagName() == "manager")
			{
				isFreeze = element.attribute("freeze").toInt();
			}

			if (element.tagName().left(7) == "window_")
			{
				int index = element.tagName().mid(7).toInt() + 1;
				if (index > 1 && index < mList.count())
				{
					curWindow = qobject_cast<AXBaseWindow*>(mList.at(index));

					if (curWindow != NULL)
					{
						curWindow->restoreGeometry(QByteArray::fromBase64(QByteArray().append(element.text())));
						curWindow->setFreeze(element.attribute("freeze").toInt());
					}
				}
			}

			element = element.nextSiblingElement();
		}
	}

	setFreeze(isFreeze);
}

void CXWindowsManager::bringToFront()
{
	AXBaseWindow* curWindow = NULL;

	QList<QWidget*>::iterator iter;
	for (iter = mList.begin(); iter != mList.end(); ++iter)
	{
		curWindow = qobject_cast<AXBaseWindow*>(*iter);

		if (curWindow == NULL) continue;

		if (curWindow->isVisible()) curWindow->raise();
	}
}

bool CXWindowsManager::getFreeze()
{
	return mIsFreeze;
}

void CXWindowsManager::setFreeze(bool aIsFreeze)
{
	if (mIsFreeze == aIsFreeze) return;

	mIsFreeze = aIsFreeze;
/*
	if (mIsFreeze) qApp->removeEventFilter(this);
	else qApp->installEventFilter(this);
*/
	AXBaseWindow* curWindow = NULL;

	QList<QWidget*>::iterator iter;
	for (iter = mList.begin(); iter != mList.end(); ++iter)
	{
		curWindow = qobject_cast<AXBaseWindow*>(*iter);

		if (curWindow != NULL) curWindow->setFreeze(aIsFreeze);
	}
}

bool CXWindowsManager::eventFilter(QObject* watched, QEvent* e)
{
	if (e->type() == QEvent::WindowActivate && QString(watched->metaObject()->className()) == QString("CXPanelWindow"))
	{
		bringToFront();

		return false;
	}

	if (mIsFreeze) return false;

	if (mEvents.contains(e->type()))
	{
		QWidget* widget = qobject_cast<QWidget*>(watched);
		if (widget != NULL)
		{
			bool isBreak = false;

			while (widget->parentWidget() != NULL)
			{
				widget = widget->parentWidget();

				if (qobject_cast<AXBaseWindow*>(widget) != NULL)
				{
					isBreak = true;
					break;
				}
			}

			if (isBreak)
			{
				AXBaseWindow* baseWindow = qobject_cast<AXBaseWindow*>(widget);
				bool isPanel = (qobject_cast<CXPanelWindow*>(widget) != NULL);

				if (baseWindow != NULL && !baseWindow->isFreeze())
				{
					switch (e->type())
					{
						case QEvent::MouseButtonPress:
						{
							baseWindow->mousePress(dynamic_cast<QMouseEvent*>(e));
							break;
						}
						case QEvent::MouseMove:
						{
							bool res = baseWindow->mouseMove(dynamic_cast<QMouseEvent*>(e));
							if (isPanel) return res;

							break;
						}
						case QEvent::MouseButtonRelease:
						{
							baseWindow->mouseRelease(dynamic_cast<QMouseEvent*>(e));
							break;
						}
						default:
						{
							return true;
						}
					}
				}

				if (!isPanel) return true;
			}
		}

		return false;
	}

	return false;
}

void CXWindowsManager::windowGeometryChange(const QRect& aNewGeometry, bool aIsResized)
{
	AXBaseWindow* window = qobject_cast<AXBaseWindow*>(sender());

	if (window != NULL)
	{
		int minTop = CLING_SIZE + 1;
		int minLeft = minTop;
		int minBottom = minTop;
		int minRight = minTop;

		int curValue = 0;

		QRect newRect = aNewGeometry;
		QRect curRect;

		QList<QWidget*>::iterator iter;
		for (iter = mList.begin(); iter != mList.end(); ++iter)
		{
			if (*iter == window || !(*iter)->isVisible()) continue;

			if (iter == mList.begin()) curRect = qobject_cast<QDesktopWidget*>(*iter)->availableGeometry();
			else curRect = (*iter)->geometry();

			if (intersects(aNewGeometry, curRect))
			{
				curValue = absoluteMin(aNewGeometry.top() - curRect.top(), aNewGeometry.top() - curRect.bottom() - 1);

				if (qAbs(curValue) <= qMin(CLING_SIZE, minTop))
				{
					minTop = qAbs(curValue);
					if (aIsResized) newRect.setTop(aNewGeometry.top() - curValue);
					else newRect.moveTo(newRect.left(), aNewGeometry.top() - curValue);
				}

				curValue = absoluteMin(aNewGeometry.bottom() - curRect.top(), aNewGeometry.bottom() - curRect.bottom() - 1);

				if (qAbs(curValue) <= qMin(CLING_SIZE, minBottom))
				{
					minBottom = qAbs(curValue);
					if (aIsResized) newRect.setBottom(aNewGeometry.bottom() - curValue - 1);
					else newRect.moveTo(newRect.left(), aNewGeometry.bottom() - curValue - newRect.height());
				}
			}

			if (intersects(aNewGeometry, curRect, false))
			{
				curValue = absoluteMin(aNewGeometry.left() - curRect.left(), aNewGeometry.left() - curRect.right() - 1);

				if (qAbs(curValue) <= qMin(CLING_SIZE, minLeft))
				{
					minLeft = qAbs(curValue);
					if (aIsResized) newRect.setLeft(aNewGeometry.left() - curValue);
					else newRect.moveTo(aNewGeometry.left() - curValue, newRect.top());
				}

				curValue = absoluteMin(aNewGeometry.right() - curRect.left(), aNewGeometry.right() - curRect.right() - 1);

				if (qAbs(curValue) <= qMin(CLING_SIZE, minRight))
				{
					minRight = qAbs(curValue);
					if (aIsResized) newRect.setRight(aNewGeometry.right() - curValue - 1);
					else newRect.moveTo(aNewGeometry.right() - curValue - newRect.width(), newRect.top());
				}
			}
		}

		window->setNewGeometry(newRect);
	}
}

int CXWindowsManager::absoluteMin(int value1, int value2)
{
	if (qAbs(value1) < qAbs(value2)) return value1;

	return value2;
}

bool CXWindowsManager::intersects(const QRect& aFirstRect, const QRect& aSecondRect, bool aIsVertical)
{
	if (aIsVertical)
	{
		if (aFirstRect.left() >= aSecondRect.left() - CLING_SIZE && aFirstRect.left() <= aSecondRect.right() + CLING_SIZE + 1) return true;
		if (aFirstRect.right() >= aSecondRect.left() - CLING_SIZE && aFirstRect.right() <= aSecondRect.right() + CLING_SIZE + 1) return true;
		if (aFirstRect.left() <= aSecondRect.left() && aFirstRect.right() >= aSecondRect.right()) return true;
	}
	else
	{
		if (aFirstRect.top() >= aSecondRect.top() - CLING_SIZE && aFirstRect.top() <= aSecondRect.bottom() + CLING_SIZE + 1) return true;
		if (aFirstRect.bottom() >= aSecondRect.top() - CLING_SIZE && aFirstRect.bottom() <= aSecondRect.bottom() + CLING_SIZE + 1) return true;
		if (aFirstRect.top() <= aSecondRect.top() && aFirstRect.bottom() >= aSecondRect.bottom()) return true;
	}

	return false;
}
