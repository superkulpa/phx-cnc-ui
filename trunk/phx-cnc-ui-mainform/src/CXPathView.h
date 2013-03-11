#ifndef CXPATHVIEW_H
#define CXPATHVIEW_H

#include <QGraphicsView>
#include <QFile>

/*!
	Типы команд для реза.
*/
enum eCommandTypes
{
	E_Body = 30,
	E_FastLine = 20,
	E_Line = 21,
	E_Arc = 22,
	E_TechnoCommand = 26
};

/*!
	Класс для отображения пути реза.
*/
class CXPathView : public QWidget
{
	Q_OBJECT

public:
	CXPathView(QWidget *parent);
	~CXPathView();

	/*!
		Функция получения прямоугольной области, занимаемой путем.

		\return Прямоугольная области, занимаемая путем.
	*/
	QRectF boundingRect();

public slots:
	/*!
		Слот загрузки пути реза из файла.

		\param aMainFile - Исходный контур.
		\param aMainFile - Контур движения.
	*/
	void load(const QString& aMainFile, const QString& aMoveFile);

	/*!
		Слот подстройки масштаба для отображения всего пути.
	*/
	void fitInView();

	/*!
		Слот увеличения мастаба.
	*/
	void zoomIn();

	/*!
		Слот уменьшения мастаба.
	*/
	void zoomOut();

	/*!
		Слот установки отображения позиции реза.

		\param aIsVisible - флаг отображения позиции реза.
	*/
	void setPositionVisible(bool aIsVisible);

	/*!
		Слот установки позиции реза.

		\param aPos - новые координаты реза.
	*/
	void setPosition(const QPointF& aPos, bool aIsAbsolute);

protected:
	/*!
		Переопределенная фукнция рисования.
	*/
	void paintEvent(QPaintEvent* e);

	/*!
		Переопределенная функция обработки скролла мышки.
	*/
	void wheelEvent(QWheelEvent* e);

	/*!
		Переопределенная фукнция обработки нажатия кнопки мышки.
	*/
	void mousePressEvent(QMouseEvent* e);

	/*!
		Переопределенная фукнция обработки движения мышки.
	*/
	void mouseMoveEvent(QMouseEvent* e);

	/*!
		Переопределенная фукнция обработки отпускания кнопки мышки.
	*/
	void mouseReleaseEvent(QMouseEvent* e);

	/*!
		Переопределенная фукнция двойного нажатия кнопки мышки.
	*/
	void mouseDoubleClickEvent(QMouseEvent* e);

	/*!
		Переопределенная фукнция показа виджета.
	*/
	void showEvent(QShowEvent* e);

	/*!
		Переопределенная фукнция изменения размера виджета.
	*/
	void resizeEvent(QResizeEvent* e);

private:
	/*!
		Функция построения пути по заданному файлу.
		\param aTextFile - файл с данными по пути.
		\param aMainPath - основной путь, либо путь реза, в случае когда aBurnPath = NULL.
		\param aBurnPath
	*/
	void fillPath(QFile& aTextFile, QPainterPath* aMainPath, QPainterPath* aBurnPath = NULL);

	/*!
		Функция установки текущего мастаба.
		\param aScale - текущий мастаб.
	*/
	void setScale(qreal aScale);

	/*!
		Функция установки текущего смещения отображения.
		\param aPos - новое смещение.
	*/
	void setOffset(const QPointF& aPos);

	/*!
		Функция получения масштаба, при котором будет виден весь путь с учетом указанных отступов от краев окна.
		\param aMargin - отступы от краев.
		\return Значение мастаба, при котором будет виден весь путь.
	*/
	qreal getFitScale(qreal aMargin = 0);

private:
	qreal mScale;		//текущий мастаб

	bool mRotateAxis;
	bool mIsFirstStart;
	bool mIsPositionVisible;

	QPointF mPos;

	QPointF mCurPosition;	//текущее смещение отображения.
	QPointF mDragPosition;	//текущее смещение отображения при перемещении.
	QPointF mOldPosition;	//координаты начала перемещения карты.

	QPainterPath mBurnPath;	//Путь реза
	QPainterPath mMovePath;	//Путь движений
	QPainterPath mMainPath;	//Основной путь

	qreal mCellSize;	//Размер ячейки для построения координатной сетки.
};

#endif // CXPATHVIEW_H
