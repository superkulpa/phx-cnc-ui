#include "CXWindowsManager.h"

#include <QList>
#include <QDesktopWidget>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDomDocument>
#include <QMouseEvent>

#include "CXGroupPanel.h"
#include "CXVirtualKeyboard.h"
#include "CXSettingsXML.h"

CXWindowsManager::CXWindowsManager()
{
  mList.insertMulti("QDesktopWidget", QApplication::desktop());
  mList.insertMulti("QDesktopWidget", QApplication::desktop());

  mEvents << QEvent::MouseButtonDblClick << QEvent::MouseButtonPress << QEvent::MouseMove
      << QEvent::MouseButtonRelease << QEvent::Wheel << QEvent::KeyPress << QEvent::FocusIn
      << QEvent::WindowActivate << QEvent::HoverMove;
//	mKeyboardWindows << "QTextEdit"

  qApp->installEventFilter(this);

  mIsFreeze = false;
  mGroupNumber = 0;
  mVirtualKeyboard = NULL;
  IsVirtualKeyboardEnabled = true;
  QString virtualKeyboardEnabled = CXSettingsXML::getValue("settings.xml", "virtual_keyboard");
  if (!virtualKeyboardEnabled.isEmpty() && virtualKeyboardEnabled.toInt() == 0)
    IsVirtualKeyboardEnabled = false;
}

CXWindowsManager::~CXWindowsManager()
{
  save("settings.xml");
}

void
CXWindowsManager::addWindow(AXBaseWindow* aWindow)
{
  if (aWindow == NULL || mList.values().contains(aWindow))
    return;

  QString className = aWindow->metaObject()->className();

  if (mList.contains(className))
  {
    int number = 1;
    while (mList.contains(className + QString::number(number)))
    {
      number++;
    }

    className += QString::number(number);
  }

  mList.insert(className, aWindow);

  connect(aWindow, SIGNAL(geometryChanged(const QRect&, bool)),
      SLOT(windowGeometryChange(const QRect&, bool)));

  load(className, aWindow);
  aWindow->setFreeze(mIsFreeze);
}

void
CXWindowsManager::setCurrentGroup(int aGroupNumber)
{
  if (mGroupNumber == aGroupNumber)
    return;

  mGroupNumber = aGroupNumber;
  AXBaseWindow* curWindow = NULL;

  QMap<QString, QWidget*>::iterator iter;
  for (iter = mList.begin(); iter != mList.end(); ++iter)
  {
    curWindow = qobject_cast<AXBaseWindow*>(*iter);

    if (curWindow == NULL)
      continue;

    if (curWindow->groupNumber() >= 0)
    {
      if (curWindow->groupNumber() > 0 && curWindow->groupNumber() != mGroupNumber)
        curWindow->hide();
      else
        curWindow->show();
    }
  }
}

int
CXWindowsManager::currentGroup()
{
  return mGroupNumber;
}

void
CXWindowsManager::save(const QString& aFileName)
{
  if (!QFile::exists(aFileName))
  {
    QFile xmlFile(aFileName);

    if (!xmlFile.open(QIODevice::WriteOnly))
      return;

    QTextStream out(&xmlFile);
    out.setCodec("UTF-8");

    out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<Settings>\n</Settings>";

    xmlFile.close();
  }

  QFile xmlFile(aFileName);

  if (!xmlFile.open(QIODevice::ReadOnly))
    return;

  QDomDocument document("");
  if (!document.setContent(&xmlFile))
    return;

  QDomElement root = document.documentElement();

  if (!root.isNull())
  {
    AXBaseWindow* curWindow = NULL;

    QDomElement manager = root.firstChildElement("manager");
    if (manager.isNull())
    {
      manager = document.createElement("manager");
      manager.setAttribute("freeze", mIsFreeze);
      root.appendChild(manager);
    }
    else
    {
      manager.setAttribute("freeze", mIsFreeze);
    }

    QString className;

    QMap<QString, QWidget*>::iterator iter;
    for (iter = mList.begin(); iter != mList.end(); ++iter)
    {
      curWindow = qobject_cast<AXBaseWindow*>(*iter);

      if (curWindow != NULL)
      {
        className = iter.key();

        QDomElement saveElement = root.firstChildElement(QString("window_%1").arg(className));
        QDomElement newElement = document.createElement(QString("window_%1").arg(className));
        newElement.appendChild(
            document.createTextNode(curWindow->saveGeometry().toBase64().data()));
        if (saveElement.isNull())
        {
          root.appendChild(newElement);
        }
        else
        {
          root.replaceChild(newElement, saveElement);
        }
      }
    }
  }

  xmlFile.close();

  xmlFile.open(QIODevice::WriteOnly);
  QTextStream out(&xmlFile);
  out.setCodec("UTF-8");

  document.save(out, 2);

  xmlFile.close();
}

void
CXWindowsManager::load(const QString& aFileName)
{
  mFileName = aFileName;

  QFile xmlFile(aFileName);

  if (!xmlFile.open(QIODevice::ReadOnly))
    return;

  QDomDocument document("");
  if (!document.setContent(&xmlFile))
    return;

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
        QString className = element.tagName().mid(7);

        if (mList.contains(className))
        {
          curWindow = qobject_cast<AXBaseWindow*>(mList.value(className));

          if (curWindow != NULL)
          {
            curWindow->restoreGeometry(QByteArray::fromBase64(QByteArray().append(element.text())));
//						curWindow->setFreeze(element.attribute("freeze").toInt());
          }
        }
      }

      element = element.nextSiblingElement();
    }
  }

  setFreeze(isFreeze);
}

void
CXWindowsManager::load(const QString& aClassName, AXBaseWindow* aWindow)
{
  /*
   QFile xmlFile(mFileName);

   if (xmlFile.open(QIODevice::ReadOnly))
   {
   QXmlQuery query;
   query.setFocus(&xmlFile);
   query.setQuery(QString("/Settings/window_%1/text()").arg(aIndex - 1));

   QString res;
   if (query.evaluateTo(&res))
   {
   AXBaseWindow* curWindow = qobject_cast<AXBaseWindow*>(mList.at(aIndex));
   curWindow->restoreGeometry(QByteArray::fromBase64(QByteArray().append(res)));
   }

   xmlFile.close();
   }
   */
  if (aWindow == NULL)
    return;
  if (!QFile::exists(mFileName))
    return;

  QFile xmlFile(mFileName);

  if (!xmlFile.open(QIODevice::ReadOnly))
    return;

  QDomDocument document("");
  if (!document.setContent(&xmlFile))
    return;

  QDomElement root = document.documentElement();

//	bool isFreeze = mIsFreeze;

  if (!root.isNull())
  {
    QDomElement element = root.firstChildElement();

    while (!element.isNull())
    {
      /*
       if (element.tagName() == "manager")
       {
       isFreeze = element.attribute("freeze").toInt();
       }
       */
      if (element.tagName().left(7) == "window_")
      {
        QString className = element.tagName().mid(7);
        if (aClassName == className)
        {
          aWindow->restoreGeometry(QByteArray::fromBase64(QByteArray().append(element.text())));
//					curWindow->setFreeze(element.attribute("freeze").toInt());

          return;
        }
      }

      element = element.nextSiblingElement();
    }
  }
  /**/
}

void
CXWindowsManager::bringToFront()
{
  AXBaseWindow* curWindow = NULL;

  QMap<QString, QWidget*>::iterator iter;
  for (iter = mList.begin(); iter != mList.end(); ++iter)
  {
    curWindow = qobject_cast<AXBaseWindow*>(*iter);

    if (curWindow == NULL)
      continue;

    if (curWindow->isVisible())
      curWindow->raise();
  }
}

bool
CXWindowsManager::getFreeze()
{
  return mIsFreeze;
}

void
CXWindowsManager::setFreeze(bool aIsFreeze)
{
  if (!aIsFreeze)
  {
    if (IsVirtualKeyboardEnabled)
    {
      if (mVirtualKeyboard == NULL)
        mVirtualKeyboard = new CXVirtualKeyboard;
      mVirtualKeyboard->show();
    }
  }
  else if (mVirtualKeyboard != NULL)
  {
    mVirtualKeyboard->hide();
  }

  if (mIsFreeze == aIsFreeze)
    return;

  mIsFreeze = aIsFreeze;
  /*
   if (mIsFreeze) qApp->removeEventFilter(this);
   else qApp->installEventFilter(this);
   */
  AXBaseWindow* curWindow = NULL;

  QMap<QString, QWidget*>::iterator iter;
  for (iter = mList.begin(); iter != mList.end(); ++iter)
  {
    curWindow = qobject_cast<AXBaseWindow*>(*iter);

    if (curWindow != NULL)
      curWindow->setFreeze(aIsFreeze);
  }
}

void
CXWindowsManager::changeVisibleVirtualKeyboard()
{
  if (mVirtualKeyboard == NULL)
    mVirtualKeyboard = new CXVirtualKeyboard;

  if (mVirtualKeyboard->isVisible())
    mVirtualKeyboard->hide();
  else
    mVirtualKeyboard->show();
}

bool
CXWindowsManager::eventFilter(QObject* watched, QEvent* e)
{
  if (e->type() == QEvent::WindowActivate)
  {
    if (QString(watched->metaObject()->className()) == QString("CXGroupPanel"))
    {
      bringToFront();

      if (mIsFreeze && mVirtualKeyboard != NULL)
        mVirtualKeyboard->hide();

      return false;
    }

    if (watched->property("readOnly").isValid() && watched->property("readOnly").toBool() == false)
    {
      if (mVirtualKeyboard == NULL && IsVirtualKeyboardEnabled)
        mVirtualKeyboard = new CXVirtualKeyboard;

      return false;
    }
  }

  if (mIsFreeze)
    return false;

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
        bool isPanel = (qobject_cast<CXGroupPanel*>(widget) != NULL
            || watched->objectName() == QString("mCloseButton")
            || watched->objectName() == QString("mSaveAsButton"));

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
            if (isPanel)
              return res;

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

        if (!isPanel)
          return true;
      }
    }

    return false;
  }

  return false;
}

void
CXWindowsManager::windowGeometryChange(const QRect& aNewGeometry, bool aIsResized)
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

    QMap<QString, QWidget*>::iterator iter;
    for (iter = mList.begin(); iter != mList.end(); ++iter)
    {
      if (*iter == window || !(*iter)->isVisible())
        continue;

      if (iter.key() == "QDesktopWidget")
        curRect = qobject_cast<QDesktopWidget*>(*iter)->availableGeometry();
      else
        curRect = (*iter)->geometry();

      if (intersects(aNewGeometry, curRect))
      {
        curValue = absoluteMin(aNewGeometry.top() - curRect.top(),
            aNewGeometry.top() - curRect.bottom() - 1);

        if (qAbs(curValue) <= qMin(CLING_SIZE, minTop))
        {
          minTop = qAbs(curValue);
          if (aIsResized)
            newRect.setTop(aNewGeometry.top() - curValue);
          else
            newRect.moveTo(newRect.left(), aNewGeometry.top() - curValue);
        }

        curValue = absoluteMin(aNewGeometry.bottom() - curRect.top(),
            aNewGeometry.bottom() - curRect.bottom() - 1);

        if (qAbs(curValue) <= qMin(CLING_SIZE, minBottom))
        {
          minBottom = qAbs(curValue);
          if (aIsResized)
            newRect.setBottom(aNewGeometry.bottom() - curValue - 1);
          else
            newRect.moveTo(newRect.left(), aNewGeometry.bottom() - curValue - newRect.height());
        }
      }

      if (intersects(aNewGeometry, curRect, false))
      {
        curValue = absoluteMin(aNewGeometry.left() - curRect.left(),
            aNewGeometry.left() - curRect.right() - 1);

        if (qAbs(curValue) <= qMin(CLING_SIZE, minLeft))
        {
          minLeft = qAbs(curValue);
          if (aIsResized)
            newRect.setLeft(aNewGeometry.left() - curValue);
          else
            newRect.moveTo(aNewGeometry.left() - curValue, newRect.top());
        }

        curValue = absoluteMin(aNewGeometry.right() - curRect.left(),
            aNewGeometry.right() - curRect.right() - 1);

        if (qAbs(curValue) <= qMin(CLING_SIZE, minRight))
        {
          minRight = qAbs(curValue);
          if (aIsResized)
            newRect.setRight(aNewGeometry.right() - curValue - 1);
          else
            newRect.moveTo(aNewGeometry.right() - curValue - newRect.width(), newRect.top());
        }
      }
    }

    window->setNewGeometry(newRect);
  }
}

int
CXWindowsManager::absoluteMin(int value1, int value2)
{
  if (qAbs(value1) < qAbs(value2))
    return value1;

  return value2;
}

bool
CXWindowsManager::intersects(const QRect& aFirstRect, const QRect& aSecondRect, bool aIsVertical)
{
  if (aIsVertical)
  {
    if (aFirstRect.left() >= aSecondRect.left() - CLING_SIZE
        && aFirstRect.left() <= aSecondRect.right() + CLING_SIZE + 1)
      return true;
    if (aFirstRect.right() >= aSecondRect.left() - CLING_SIZE
        && aFirstRect.right() <= aSecondRect.right() + CLING_SIZE + 1)
      return true;
    if (aFirstRect.left() <= aSecondRect.left() && aFirstRect.right() >= aSecondRect.right())
      return true;
  }
  else
  {
    if (aFirstRect.top() >= aSecondRect.top() - CLING_SIZE
        && aFirstRect.top() <= aSecondRect.bottom() + CLING_SIZE + 1)
      return true;
    if (aFirstRect.bottom() >= aSecondRect.top() - CLING_SIZE
        && aFirstRect.bottom() <= aSecondRect.bottom() + CLING_SIZE + 1)
      return true;
    if (aFirstRect.top() <= aSecondRect.top() && aFirstRect.bottom() >= aSecondRect.bottom())
      return true;
  }

  return false;
}
