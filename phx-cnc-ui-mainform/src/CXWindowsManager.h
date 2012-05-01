#ifndef CXWINDOWSMANAGER_H
#define CXWINDOWSMANAGER_H

#include <QList>

#include "AXBaseWindow.h"

/*!
	����� �������� ���������.
*/
class CXWindowsManager : public QObject
{
	Q_OBJECT

public:
	CXWindowsManager();
	~CXWindowsManager();

	/*!
		������ ���������� ������ ���� � ��������.
		\param aWindow - ��������� �� ����� ����.
	*/
	void addWindow(AXBaseWindow* aWindow);

	/*!
		��������� ������� ������ ����.
		\param aGroupNumber - ����� ������.
	*/
	void setCurrentGroup(int aGroupNumber);

	/*!
		������� ��������� ��������� ���� �����.
		\param aIsFreeze - ���� ���������.
	*/
	void setFreeze(bool aIsFreeze);

	/*!
		������� ���������� ��������� ����.
		\param aFileName - ���� � ������ �����.
	*/
	void save(const QString& aFileName);
	
	/*!
		������� �������� ��������� ����.
		\param aFileName - ���� � ������ �����.
	*/
	void load(const QString& aFileName);

private slots:
	/*!
		���� ��������� ��������� ��������� ����.
		\param aNewRect - ����� ��������� ����.
		\param aIsResized - ������� ��������� ��������� ��� ��������� �������.
	*/
	void windowGeometryChange(const QRect& aNewGeometry, bool aIsResized);

private:
	/*!
		������� ����������� ����������� �������� (��� ����� �����) 2� ����������.
	*/
	int absoluteMin(int aValue1, int aValue2);

	/*!
		������� ����������� ����������� ����������� 2� ���������.
		\param aIsVertical - ����������� ����������� ��-���������.
	*/
	bool intersects(const QRect& aFirstRect, const QRect& aSecondRect, bool aIsVertical = true);

private:
	QList <QWidget*> mList;
};

#endif // CXWINDOWSMANAGER_H
