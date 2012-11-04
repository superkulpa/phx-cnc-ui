#ifndef CXPATHWINDOW_H
#define CXPATHWINDOW_H

#include "AXBaseWindow.h"

class CXPathView;

/*!
	Класс с отображением путя реза и функциональными кнопками.
*/
class CXPathWindow : public AXBaseWindow
{
	Q_OBJECT

public:
	CXPathWindow();
	~CXPathWindow();

public slots:
	/*!
		Слот загрузки пути реза из файла.

		\param aMainFile - Исходный контур.
		\param aMainFile - Контур движения.
	*/
	void load(const QString& aMainFile, const QString& aMoveFile);

	/*!
		Слот установки текущей позиции реза.

		\param aPos - координаты реза.
		\param aIsAbsolute - абсолютное ли смещение.
	*/
	void setPosition(const QPointF& aPos, bool aIsAbsolute);

	//! Слот разворачивания на весь экран.
	void onMaximize();

private:
	CXPathView* mPathView;
};

#endif // CXPATHWINDOW_H
