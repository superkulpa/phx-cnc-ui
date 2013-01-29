#ifndef CXWINDOWSMANAGER_H
#define CXWINDOWSMANAGER_H

#include <QMap>

#include "AXBaseWindow.h"

class CXVirtualKeyboard;

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
		Функия установки текущей группы окон.
		\param aGroupNumber - номер группы.
	*/
	void setCurrentGroup(int aGroupNumber);

	/*!
		Функция получения текущей группы окон.
		\return Номер группы.
	*/
	int currentGroup();

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
	
	/*!
		Функция загрузка геометрии окона по индексу.
		\param aWindow - указатель на окно.
	*/
	void load(const QString& aClassName, AXBaseWindow* aWindow);

	/*!
		Функция выноса всех окон на передний план.
	*/
	void bringToFront();

	/*!
		Функция получения состояния заморозки.
		\return aIsFreeze - флаг заморозки.
	*/
	bool getFreeze();

public slots:
	/*!
		Функция установки заморозки всем окнам.
		\param aIsFreeze - флаг заморозки.
	*/
	void setFreeze(bool aIsFreeze);

	//! Функция показа/скрытия виртуальной клавиатуры.
	void changeVisibleVirtualKeyboard();

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
	QString mFileName;

	bool mIsFreeze;
	int mGroupNumber;

	QMap <QString, QWidget*> mList;
	QVector <int> mEvents;

//	QVector <QString> mKeyboardWindows;

	CXVirtualKeyboard* mVirtualKeyboard;
	bool IsVirtualKeyboardEnabled;
};

#endif // CXWINDOWSMANAGER_H
