#ifndef CXPATHVIEW_H
#define CXPATHVIEW_H

#include <QGraphicsView>
#include <QFile>

/*!
	���� ������ ��� ����.
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
	����� ��� ����������� ���� ����.
*/
class CXPathView : public QWidget
{
	Q_OBJECT

public:
	CXPathView(QWidget *parent);
	~CXPathView();

	/*!
		������� ��������� ������������� �������, ���������� �����.

		\return ������������� �������, ���������� �����.
	*/
	QRectF boundingRect();

public slots:
	/*!
		���� �������� ���� ���� �� �����.

		\param aMainFile - �������� ������.
		\param aMainFile - ������ ��������.
	*/
	void load(const QString& aMainFile, const QString& aMoveFile);

	/*!
		���� ���������� �������� ��� ����������� ����� ����.
	*/
	void fitInView();

	/*!
		���� ���������� �������.
	*/
	void zoomIn();
	/*!
		���� ���������� �������.
	*/
	void zoomOut();

protected:
	/*!
		���������������� ������� ���������.
	*/
	void paintEvent(QPaintEvent* e);

	/*!
		���������������� ������� ��������� ������� �����.
	*/
	void wheelEvent(QWheelEvent* e);

	/*!
		���������������� ������� ��������� ������� ������ �����.
	*/
	void mousePressEvent(QMouseEvent* e);

	/*!
		���������������� ������� ��������� �������� �����.
	*/
	void mouseMoveEvent(QMouseEvent* e);

	/*!
		���������������� ������� ��������� ���������� ������ �����.
	*/
	void mouseReleaseEvent(QMouseEvent* e);

	/*!
		���������������� ������� �������� ������� ������ �����.
	*/
	void mouseDoubleClickEvent(QMouseEvent* e);

	/*!
		���������������� ������� ������ �������.
	*/
	void showEvent(QShowEvent* e);

	/*!
		���������������� ������� ��������� ������� �������.
	*/
	void resizeEvent(QResizeEvent* e);

private:
	/*!
		������� ���������� ���� �� ��������� �����.
		\param aTextFile - ���� � ������� �� ����.
		\param aMainPath - �������� ����, ���� ���� ����, � ������ ����� aBurnPath = NULL.
		\param aBurnPath
	*/
	void fillPath(QFile& aTextFile, QPainterPath* aMainPath, QPainterPath* aBurnPath = NULL);

	/*!
		������� ��������� �������� �������.
		\param aScale - ������� ������.
	*/
	void setScale(qreal aScale);

	/*!
		������� ��������� �������� �������� �����������.
		\param aPos - ����� ��������.
	*/
	void setPosition(const QPointF& aPos);

	/*!
		������� ��������� ��������, ��� ������� ����� ����� ���� ���� � ������ ��������� �������� �� ����� ����.
		\param aMargin - ������� �� �����.
		\return �������� �������, ��� ������� ����� ����� ���� ����.
	*/
	qreal getFitScale(qreal aMargin = 0);

private:
	qreal mScale;		//������� ������

	bool mIsFirstStart;

	QPointF mCurPosition;	//������� �������� �����������.
	QPointF mDragPosition;	//������� �������� ����������� ��� �����������.
	QPointF mOldPosition;	//���������� ������ ����������� �����.

	QPainterPath mBurnPath;	//���� ����
	QPainterPath mMovePath;	//���� ��������
	QPainterPath mMainPath;	//�������� ����

	qreal mCellSize;	//������ ������ ��� ���������� ������������ �����.
};

#endif // CXPATHVIEW_H
