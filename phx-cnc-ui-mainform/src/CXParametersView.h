#ifndef CXPARAMETERSVIEW_H
#define CXPARAMETERSVIEW_H

#include <QStyledItemDelegate>
#include <QTableView>
#include <QMap>
#include <QAbstractItemModel>

#include "CXParameterData.h"

/*!
	Класс QStyledItemDelegate для отрисовки данных.
*/
class CXParameterItemDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	CXParameterItemDelegate(QAbstractItemView* parent = 0);

	//! Переопределенная функция создания редактора для ячейки
	virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;

	//! Переопределенная функция отрисовки делегата.
	virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

protected:
	//! Переопределенная функция событий редактора.
	virtual bool editorEvent(QEvent* e, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index);

	//! Переопределенная функция событий таймера.
	virtual void timerEvent(QTimerEvent* e);

private slots:
	//! Слот обновления значения.
	void updateValue();

private:
	QAbstractItemView* mParentWidget;
	int mClickTimer;
	int mTimerInterval;
	QAbstractItemModel* mModel;
	QModelIndex mClickIndex;
};

/*!
	Класс модели параметров.
*/
class CXParametersModel : public QAbstractItemModel
{
public:
	CXParametersModel(QList <CXParameterData*> aParameters, QObject* parent = 0);

	//! Переопределенная функция получения количества колонок в модели.
	virtual int	columnCount(const QModelIndex& parent = QModelIndex()) const;

	//! Переопределенная функция получения данных модели по индексу.
	virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

	//! Переопределенная функция установки данных модели по индексу.
	virtual bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);

	//! Переопределенная функция получения индекса модели.
	virtual QModelIndex	index(int row, int column, const QModelIndex& parent = QModelIndex()) const;

	//! Переопределенная функция получения родителя по индексу.
	virtual QModelIndex	parent(const QModelIndex& index) const;

	//! Переопределенная функция получения количества строк в модели.
	virtual int	rowCount(const QModelIndex& parent = QModelIndex()) const;

	//! Переопределенная функция получения флагов по индексу.
	virtual Qt::ItemFlags flags(const QModelIndex& index) const;

	//!
	virtual void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

private:
	QList <CXParameterData*> mParameters;
};

/*!
	Класс для отображения параметров.
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
	//! Номер группы параметров, которые будут отображены.
//	int mGroupNumber;

	//! Статический список групп.
	static QMap <int, CXGroupData*> mGropusMap;

	//! Статический список параметров с привязкой к номеру группы.
	static QMap<int, CXParameterData*> mDataMap;
};

#endif // CXPARAMETERSVIEW_H
