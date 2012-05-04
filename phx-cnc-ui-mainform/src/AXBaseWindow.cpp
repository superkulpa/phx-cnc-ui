#include "AXBaseWindow.h"

#include <QResizeEvent>
#include <QPainter>
#include <QApplication>

#include "CXWindowsManager.h"

CXWindowsManager* AXBaseWindow::mManager = NULL;

AXBaseWindow::AXBaseWindow() : QWidget()
{
	mGroupNumber = -1;
	mResizeType = E_None;

	mCursors.append(Qt::ArrowCursor);
	mCursors.append(Qt::SizeFDiagCursor);
	mCursors.append(Qt::SizeBDiagCursor);
	mCursors.append(Qt::SizeBDiagCursor);
	mCursors.append(Qt::SizeFDiagCursor);
	mCursors.append(Qt::SizeHorCursor);
	mCursors.append(Qt::SizeHorCursor);
	mCursors.append(Qt::SizeVerCursor);
	mCursors.append(Qt::SizeVerCursor);

	mIsFreeze = false;

	if (mManager != NULL) mManager->addWindow(this);

	setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);

	resize(300, 300);
	setMouseTracking(true);
}

AXBaseWindow::~AXBaseWindow()
{
	;
}

void AXBaseWindow::setNewGeometry(const QRect& aNewGeometry)
{
	if (aNewGeometry.size() == size()) update();

	setGeometry(aNewGeometry);
}


void AXBaseWindow::setGroupNumber(int aNumber)
{
	mGroupNumber = aNumber;
}

int AXBaseWindow::groupNumber()
{
	return mGroupNumber;
}

void AXBaseWindow::setFreeze(bool aIsFreeze)
{
	mIsFreeze = aIsFreeze;
	mResizeType = E_None;
	update();
}

bool AXBaseWindow::isFreeze()
{
	return mIsFreeze;
}

void AXBaseWindow::mousePress(QMouseEvent* e)
{
	if (mIsFreeze) return;

	if (e->button() == Qt::LeftButton)
	{
		mPos = pos();
		mPressPos = e->globalPos();

		mResizeType = getResizeType(geometry(), e->globalPos());

		if (mResizeType == E_None)
		{
			qApp->setOverrideCursor(Qt::SizeAllCursor);
		}
		else
		{
			setCursor(mCursors.at(mResizeType));
			qApp->setOverrideCursor(mCursors.at(mResizeType));
		}
	}
}

bool AXBaseWindow::mouseMove(QMouseEvent* e)
{
	if (mIsFreeze) return false;

	if (e->buttons() == Qt::LeftButton)
	{
		QRect geom = geometry();

		int resSize = RESIZE_BORDER * 5;

		if (mResizeType != E_None)
		{
			if (mResizeType == E_Left || mResizeType == E_TopLeft || mResizeType == E_BottomLeft)
			{
				geom.setLeft(e->globalPos().x());
				if (geom.width() < resSize) geom.setLeft(geom.right() - resSize);
			}

			if (mResizeType == E_Top || mResizeType == E_TopLeft || mResizeType == E_TopRight)
			{
				geom.setTop(e->globalPos().y());
				if (geom.height() < resSize) geom.setTop(geom.bottom() - resSize);
			}

			if (mResizeType == E_Right || mResizeType == E_TopRight || mResizeType == E_BottomRight)
			{
				geom.setRight(e->globalPos().x());
				if (geom.width() < resSize) geom.setWidth(resSize);
			}

			if (mResizeType == E_Bottom || mResizeType == E_BottomLeft || mResizeType == E_BottomRight)
			{
				geom.setBottom(e->globalPos().y());
				if (geom.height() < resSize) geom.setHeight(resSize);
			}
		}
		else geom.moveTo(mPos + e->globalPos() - mPressPos);

		emit geometryChanged(geom, mResizeType != E_None);

		return true;
	}
	else
	{
		eSideType resizeType = getResizeType(geometry(), e->globalPos());
		setCursor(mCursors.at(resizeType));
		if (resizeType != mResizeType)
		{
			mResizeType = resizeType;
			update();
		}
	}

	return false;
}

void AXBaseWindow::mouseRelease(QMouseEvent*)
{
	if (mIsFreeze) return;

	setCursor(Qt::ArrowCursor);
	qApp->restoreOverrideCursor();
}

void AXBaseWindow::mousePressEvent(QMouseEvent* e)
{
	QWidget::mousePressEvent(e);
	mousePress(e);
}

void AXBaseWindow::mouseMoveEvent(QMouseEvent* e)
{
	QWidget::mouseMoveEvent(e);

	mouseMove(e);
}

void AXBaseWindow::mouseReleaseEvent(QMouseEvent* e)
{
	QWidget::mouseReleaseEvent(e);

	mouseRelease(e);
}

void AXBaseWindow::paintEvent(QPaintEvent* e)
{
	QWidget::paintEvent(e);

	if (mIsFreeze) return;

	QPainter painter(this);
	painter.setOpacity(0.5);
	painter.setPen(Qt::NoPen);

	QColor acceptColor(Qt::green);
	QColor selectColor(Qt::red);
	QColor paintColor;

	if (mResizeType == E_Top || mResizeType == E_TopLeft || mResizeType == E_TopRight) paintColor = selectColor;
	else paintColor = acceptColor;
	painter.fillRect(QRect(0, 0, width(), RESIZE_BORDER), paintColor);

	if (mResizeType == E_Bottom || mResizeType == E_BottomLeft || mResizeType == E_BottomRight) paintColor = selectColor;
	else paintColor = acceptColor;
	painter.fillRect(QRect(0, height() - RESIZE_BORDER, width(), RESIZE_BORDER), paintColor);

	if (mResizeType == E_Left || mResizeType == E_TopLeft || mResizeType == E_BottomLeft) paintColor = selectColor;
	else paintColor = acceptColor;
	painter.fillRect(QRect(0, 0, RESIZE_BORDER, height()), paintColor);

	if (mResizeType == E_Right || mResizeType == E_TopRight || mResizeType == E_BottomRight) paintColor = selectColor;
	else paintColor = acceptColor;
	painter.fillRect(QRect(width() - RESIZE_BORDER, 0, RESIZE_BORDER, height()), paintColor);
}

void AXBaseWindow::leaveEvent(QEvent* e)
{
	QWidget::leaveEvent(e);

	if (mResizeType != E_None)
	{
		mResizeType = E_None;
		update();
	}
}

void AXBaseWindow::closeEvent(QCloseEvent* e)
{
	QWidget::closeEvent(e);

	emit closed();
}

eSideType AXBaseWindow::getResizeType(const QRect& aRect, const QPoint& aPos)
{
	if (!aRect.contains(aPos)) return E_None;

	QRect area(-RESIZE_BORDER * 2, -RESIZE_BORDER * 2, RESIZE_BORDER * 4, RESIZE_BORDER * 4);

	if (area.contains(aPos - aRect.topLeft())) return E_TopLeft;
	if (area.contains(aPos - aRect.topRight())) return E_TopRight;
	if (area.contains(aPos - aRect.bottomLeft())) return E_BottomLeft;
	if (area.contains(aPos - aRect.bottomRight())) return E_BottomRight;

	if (aPos.y() - aRect.top() <= RESIZE_BORDER) return E_Top;
	if (aPos.x() - aRect.left() <= RESIZE_BORDER) return E_Left;
	if (aRect.right() - aPos.x() <= RESIZE_BORDER) return E_Right;
	if (aRect.bottom() - aPos.y() <= RESIZE_BORDER) return E_Bottom;

	return E_None;
}
