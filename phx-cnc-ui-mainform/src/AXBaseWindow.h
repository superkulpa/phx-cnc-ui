#ifndef AXBASEWINDOW_H
#define AXBASEWINDOW_H

#define RESIZE_BORDER 5
#define CLING_SIZE 10

#include <QWidget>

class CXWindowsManager;

/*!
	������ ��� ����� ��������� �������� ����.
*/
enum eSideType
{
	E_None = 0,
	E_TopLeft,
	E_TopRight,
	E_BottomLeft,
	E_BottomRight,
	E_Left,
	E_Right,
	E_Top,
	E_Bottom
};


/*!
	����� ���� ��� ������������ ��������� ������� � �������.
*/
class AXBaseWindow : public QWidget
{
	Q_OBJECT

public:
	AXBaseWindow();
	~AXBaseWindow();

	/*!
		������� ��������� ����� ��������� ����.
		\param aNewGeometry - ������������� ��� ����� ��������� ����.
	*/
	void setNewGeometry(const QRect& aNewGeometry);

	/*!
		������� ��������� ������ ������ ��� ����.
		\param aNumber - ����� ������.
	*/
	void setGroupNumber(int aNumber);

	/*!
		������� ��������� ������ ������ ����.
		\return ����� ������.
	*/
	int groupNumber();

	/*!
		��������� ����� ��������� ����������� � ��������� �������� ����.
		\param aIsFreeze - ���� ���������.
	*/
	void setFreeze(bool aIsFreeze);

	/*!
		������� ��������� ����� ��������� ����������� � ��������� �������� ����.
		\return ���� ���������.
	*/
	bool isFreeze();

signals:
	/*!
		������ �� ��������� ��������� ����.
		\param aNewRect - ����� ��������� ����.
		\param aIsResized - ������� ��������� ��������� ��� ��������� �������.
	*/
	void geometryChanged(const QRect& aNewRect, bool aIsResized);

	/*!
		������ �������� ����.
	*/
	void closed();

protected:
	/*!
		���������������� ������� ��������� ������� ������ �����.
	*/
	virtual void mousePressEvent(QMouseEvent* e);
	
	/*!
		���������������� ������� ��������� �������� �����.
	*/
	virtual void mouseMoveEvent(QMouseEvent* e);
	
	/*!
		���������������� ������� ��������� ���������� ������ �����.
	*/
	virtual void mouseReleaseEvent(QMouseEvent* e);
	
	/*!
		���������������� ������� ���������.
	*/
	virtual void paintEvent(QPaintEvent* e);

	/*!
		���������������� ������� ������ ��������� ����� �� ������� �����.
	*/
	virtual void leaveEvent(QEvent* e);

	/*!
		���������������� ������� �������� ����.
	*/
	virtual void closeEvent(QCloseEvent* e);

private:
	/*!
		������� ��������� ���� ��������� �������� �����.
		\param aRect - ��������� ����� � ���������� �������� �����������.
		\param aPos - ������� ����� � ���������� �������� �����������.
		\return ���� ��������� ������� ����.
	*/
	eSideType getResizeType(const QRect& aRect, const QPoint& aPos);

public:
	//! ����������� ��������� �� ������� ��������.
	static CXWindowsManager* mManager;

private:
	//! ����� ������ ����.
	int mGroupNumber;

	//! ��� ��������� ������� ����.
	eSideType mResizeType;

	//! ������ �������� �� ���� ��������� �������.
	QList <Qt::CursorShape> mCursors;

	//! ���� ��������� ����.
	bool mIsFreeze;

	//! ������� ���� ��� ������� ����� ������� �����.
	QPoint mPos;

	//! ������� ������� ��� ������� ����� ������� �����.
	QPoint mPressPos;
};

#endif // AXBASEWINDOW_H
