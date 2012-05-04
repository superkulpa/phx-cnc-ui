#ifndef CXWINDOWSMANAGER_H
#define CXWINDOWSMANAGER_H

#include <QList>

#include "AXBaseWindow.h"

/*!
	Класс оконного менеджера.
*/
class CXWindowsManager : public QObject
{
	Q_OBJECT

public:
	CXWindowsManager();
	~CXWindowsManager();

	/*!
		Функия добавления нового окна в менеджер.
		\param aWindow - указатель на новое окно.
	*/
	void addWindow(AXBaseWindow* aWindow);

	/*!
		Установка текущей группы окон.
		\param aGroupNumber - номер группы.
	*/
	void setCurrentGroup(int aGroupNumber);

	/*!
		Функция сохранения геометрии окон.
		\param aFileName - путь с именем файла.
	*/
	void save(const QString& aFileName);
	
	/*!
		Функция загрузка геометрии окон.
		\param aFileName - путь с именем файла.
	*/
	void load(const QString& aFileName);

public slots:
	/*!
		Функция установки заморозки всем окнам.
		\param aIsFreeze - флаг заморозки.
	*/
	void setFreeze(bool aIsFreeze);

protected:
	virtual bool eventFilter(QObject* watched, QEvent* e);

private slots:
	/*!
		Слот обработки изменения геометрии окна.
		\param aNewRect - новая геометрия окна.
		\param aIsResized - признак изменения геометрии при изменении размера.
	*/
	void windowGeometryChange(const QRect& aNewGeometry, bool aIsResized);

private:
	/*!
		Функция определения абсолютного минимума (без учета знака) 2х переменных.
	*/
	int absoluteMin(int aValue1, int aValue2);

	/*!
		Функция определения возможности пересечения 2х геометрий.
		\param aIsVertical - определение пересечения по-вертикали.
	*/
	bool intersects(const QRect& aFirstRect, const QRect& aSecondRect, bool aIsVertical = true);

private:
	QList <QWidget*> mList;
};

#endif // CXWINDOWSMANAGER_H
