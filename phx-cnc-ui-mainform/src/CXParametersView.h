#ifndef CXPARAMETERSVIEW_H
#define CXPARAMETERSVIEW_H

#include <QStyledItemDelegate>
#include <QTableView>
#include <QMap>
#include <QAbstractItemModel>

#include "CXParameterData.h"

/*!
	����� QStyledItemDelegate ��� ��������� ������.
*/
class CXParameterItemDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	CXParameterItemDelegate(QAbstractItemView* parent = 0);

	//! ���������������� ������� �������� ��������� ��� ������
	virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;

	//! ���������������� ������� ��������� ��������.
	virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

protected:
	//! ���������������� ������� ������� ���������.
	virtual bool editorEvent(QEvent* e, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index);

	//! 
	virtual void timerEvent(QTimerEvent* e);

private slots:
	//! ���� ���������� ��������.
	void updateValue();

private:
	QAbstractItemView* mParentWidget;
	int mClickTimer;
	int mTimerInterval;
	QAbstractItemModel* mModel;
	QModelIndex mClickIndex;
};

/*!
	����� ������ ����������.
*/
class CXParametersModel : public QAbstractItemModel
{
public:
	CXParametersModel(QList <CXParameterData*> aParameters, QObject* parent = 0);

	//! ���������������� ������� ��������� ���������� ������� � ������.
	virtual int	columnCount(const QModelIndex& parent = QModelIndex()) const;

	//! ���������������� ������� ��������� ������ ������ �� �������.
	virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

	//! ���������������� ������� ��������� ������ ������ �� �������.
	virtual bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);

	//! ���������������� ������� ��������� ������� ������.
	virtual QModelIndex	index(int row, int column, const QModelIndex& parent = QModelIndex()) const;

	//! ���������������� ������� ��������� �������� �� �������.
	virtual QModelIndex	parent(const QModelIndex& index) const;

	//! ���������������� ������� ��������� ���������� ����� � ������.
	virtual int	rowCount(const QModelIndex& parent = QModelIndex()) const;

	//! ���������������� ������� ��������� ������ �� �������.
	virtual Qt::ItemFlags flags(const QModelIndex& index) const;

	//!
	virtual void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

private:
	QList <CXParameterData*> mParameters;
};

/*!
	����� ��� ����������� ����������.
*/
class CXParametersView : public QTableView
{
	Q_OBJECT

public:
	CXParametersView(QWidget* parent, QList <CXParameterData*> aParameters);
	~CXParametersView();

protected slots:
	virtual void closeEditor(QWidget* editor, QAbstractItemDelegate::EndEditHint hint);

public:
	//! ����� ������ ����������, ������� ����� ����������.
//	int mGroupNumber;

	//! ����������� ������ �����.
	static QMap <int, CXGroupData*> mGropusMap;

	//! ����������� ������ ���������� � ��������� � ������ ������.
	static QMap<int, CXParameterData*> mDataMap;
};

#endif // CXPARAMETERSVIEW_H
