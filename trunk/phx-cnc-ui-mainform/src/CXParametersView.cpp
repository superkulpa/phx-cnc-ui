#include "CXParametersView.h"

#include <QStandardItemModel>
#include <QHeaderView>
#include <QStylePainter>
#include <QSpinBox>
#include <QApplication>
#include <QMouseEvent>

#include "CXSettingsXML.h"

int CXParameterItemDelegate::mDelay = 0;
QMap<int, CXGroupData*> CXParametersView::mGropusMap;
QMap<int, CXParameterData*> CXParametersView::mDataMap;

/**/

CXParameterItemDelegate::CXParameterItemDelegate(QAbstractItemView* parent) :
    QStyledItemDelegate(parent)
{
  mParentWidget = parent;
  mClickTimer = -1;
  mTimerInterval = 0;

  mModel = NULL;

  if (mDelay == 0)
    mDelay = CXSettingsXML::getDelay("settings.xml", "delay");
}

QWidget*
CXParameterItemDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
    {
  switch (index.column())
  {
  case 1:
    {
    QSpinBox* spinBox = new QSpinBox(parent);

    spinBox->setAccelerated(true);
    spinBox->setValue(index.data(Qt::EditRole).toInt());
    spinBox->setRange(index.data(Qt::UserRole + 100).toInt(),
        index.data(Qt::UserRole + 101).toInt());

    connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(updateValue()));

    return spinBox;
  }
  }

  return QStyledItemDelegate::createEditor(parent, option, index);
}

void
CXParameterItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
    {
  switch (index.column())
  {
  case 0:
    {
    QStyleOptionProgressBar progressBarOption;
    progressBarOption.rect = option.rect;
    progressBarOption.minimum = index.data(Qt::UserRole + 100).toInt();
    progressBarOption.maximum = index.data(Qt::UserRole + 101).toInt();
    progressBarOption.progress = index.data(Qt::EditRole).toInt();
    progressBarOption.textVisible = true;
    progressBarOption.textAlignment = Qt::AlignCenter;
    progressBarOption.text = index.data(Qt::DisplayRole).toString();

    QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressBarOption, painter);

    break;
  }
  case 2:
    case 3:
    {
    QStyleOptionButton buttonOption;
    buttonOption.rect = option.rect;
    if (index.column() == 2)
      buttonOption.text = "+";
    else
      buttonOption.text = "-";
    buttonOption.state = QStyle::State_Enabled | QStyle::State_Active;

    QApplication::style()->drawControl(QStyle::CE_PushButton, &buttonOption, painter);

    break;
  }
  default:
    {
    QStyledItemDelegate::paint(painter, option, index);
    break;
  }
  }
}

bool
CXParameterItemDelegate::editorEvent(QEvent* e, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index)
{
  switch (e->type())
  {
  case QEvent::MouseMove:
    {
    if (mClickIndex.row() == index.row() && mClickIndex.column() == 0)
    {
      if (mClickTimer != -1)
        return true;

      QMouseEvent* mouse = dynamic_cast<QMouseEvent*>(e);
      qreal value = mouse->posF().x() / option.rect.width();

      int min = index.data(Qt::UserRole + 100).toInt();
      int max = index.data(Qt::UserRole + 101).toInt();

      model->setData(index, value * (max - min) + min, Qt::EditRole);

      return true;
    }

    if (mClickTimer != -1 && mClickIndex != index)
    {
      killTimer(mClickTimer);
    }

    break;
  }
  case QEvent::MouseButtonRelease:
    {
    if (mClickTimer != -1)
    {
      killTimer(mClickTimer);
      mClickTimer = -1;
    }

    return true;
  }
  case QEvent::MouseButtonPress:
    {
    if (mClickTimer != -1)
      killTimer(mClickTimer);

    mModel = model;
    mClickIndex = index;

    if (index.column() == 0)
    {
      QMouseEvent* mouse = dynamic_cast<QMouseEvent*>(e);
      qreal value = mouse->posF().x() / option.rect.width();

      int min = index.data(Qt::UserRole + 100).toInt();
      int max = index.data(Qt::UserRole + 101).toInt();

      mClickValue = value * (max - min) + min;
    }

    mTimerInterval = mDelay;
    mClickTimer = startTimer(mDelay);

    break;
  }
  default:
    {
    break;
  }
  }

  return QStyledItemDelegate::editorEvent(e, model, option, index);
}

void
CXParameterItemDelegate::timerEvent(QTimerEvent* e)
{
  if (e->timerId() == mClickTimer)
  {
    switch (mClickIndex.column())
    {
    case 0:
      {
      mModel->setData(mClickIndex, mClickValue, Qt::EditRole);

      killTimer(mClickTimer);
      mClickTimer = -1;

      break;
    }
    case 2:
      case 3:
      {
      if (mParentWidget != NULL
          && mParentWidget->indexAt(mParentWidget->mapFromGlobal(QCursor::pos())) != mClickIndex)
      {
        killTimer(mClickTimer);
        mClickTimer = -1;
        return;
      }

      if (mClickIndex.column() == 2)
        mModel->setData(mClickIndex, mClickIndex.data(Qt::EditRole).toInt() + 1, Qt::EditRole);
      else
        mModel->setData(mClickIndex, mClickIndex.data(Qt::EditRole).toInt() - 1, Qt::EditRole);

      if (mTimerInterval == mDelay)
      {
        killTimer(mClickTimer);
        mTimerInterval = 1000;
        mClickTimer = startTimer(mTimerInterval);
      }
      else if (mTimerInterval == 1000)
      {
        killTimer(mClickTimer);
        mTimerInterval = 50;
        mClickTimer = startTimer(mTimerInterval);
      }
      break;
    }
    default:
      {
      killTimer(mClickTimer);
      mClickTimer = -1;

      break;
    }
    }
  }
}

void
CXParameterItemDelegate::updateValue()
{
  emit commitData(qobject_cast<QWidget*>(sender()));
}

/**/

CXParametersModel::CXParametersModel(QList<CXParameterData*> aParameters, QObject* parent) :
    QAbstractItemModel(parent)
{
  mParameters = aParameters;
}

int
CXParametersModel::columnCount(const QModelIndex& parent) const
    {
  Q_UNUSED(parent)

  return 4;
}

QVariant
CXParametersModel::data(const QModelIndex& index, int role) const
    {
  if (index.isValid() && index.row() < mParameters.count())
  {
    if (role == Qt::UserRole + 100)
    {
      return mParameters.at(index.row())->mMin;
    }

    if (role == Qt::UserRole + 101)
    {
      return mParameters.at(index.row())->mMax;
    }

    if (role == Qt::EditRole || role == Qt::DisplayRole)
    {
      switch (index.column())
      {
      case 0:
        {
        if (role == Qt::DisplayRole)
          return mParameters.at(index.row())->mName;
        mParameters.at(index.row())->getValue();
      }
      case 1:
        case 2:
        case 3:
        {
        return mParameters.at(index.row())->getValue();
      }
      }
    }
  }

  return QVariant();
}

bool
CXParametersModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
  if (role == Qt::EditRole)
  {
    mParameters.at(index.row())->setValue(value.toInt());

    emit dataChanged(createIndex(index.row(), 0), createIndex(index.row(), columnCount() - 1));

    return true;
  }

  return false;
}

QModelIndex
CXParametersModel::index(int row, int column, const QModelIndex& parent) const
    {
  Q_UNUSED(parent)

  if (row < rowCount() && column < columnCount())
  {
    return createIndex(row, column);
  }

  return QModelIndex();
}

QModelIndex
CXParametersModel::parent(const QModelIndex& index) const
    {
  Q_UNUSED(index)

  return QModelIndex();
}

int
CXParametersModel::rowCount(const QModelIndex& parent) const
    {
  Q_UNUSED(parent)

  return mParameters.count();
}

Qt::ItemFlags
CXParametersModel::flags(const QModelIndex& index) const
    {
  switch (index.column())
  {
  case 1:
    {
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
  }
  }

  return QAbstractItemModel::flags(index);
}

void
CXParametersModel::sort(int column, Qt::SortOrder order)
{
  if (column == 0)
  {
    beginResetModel();

    int insertIndex = 0;
    QList<CXParameterData*> sortList;
    CXParameterData* curParameter = NULL;

    for (int i = 0; i < mParameters.count(); ++i)
    {
      insertIndex = 0;
      curParameter = mParameters.at(i);

      for (int j = 0; j < sortList.count(); ++j)
      {
        if (order == Qt::AscendingOrder && curParameter->mName < sortList.at(j)->mName)
          break;
        if (order == Qt::DescendingOrder && curParameter->mName > sortList.at(j)->mName)
          break;

        insertIndex++;
      }

      sortList.insert(insertIndex, curParameter);
    }

    mParameters = sortList;

    endResetModel();
  }
}

/**/

CXParametersView::CXParametersView(QWidget* parent, QList<CXParameterData*> aParameters) :
    QTableView(parent)
{
  mIsModified = false;

  QHeaderView* horHeader = horizontalHeader();
  horHeader->hide();

  QHeaderView* vertHeader = verticalHeader();
  vertHeader->hide();
  vertHeader->setDefaultSectionSize(50);

  setEditTriggers(QAbstractItemView::AllEditTriggers);
  setItemDelegate(new CXParameterItemDelegate(this));

  CXParametersModel* model = new CXParametersModel(aParameters, this);

  setModel(model);

  sortByColumn(0, Qt::AscendingOrder);

//	setColumnWidth(1, 100);
  setColumnWidth(2, 70);
  setColumnWidth(3, 70);

  horHeader->setResizeMode(0, QHeaderView::Stretch);

  connect(model, SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this,
      SLOT(onDataChange()));
}

CXParametersView::~CXParametersView()
{
  ;
}

bool
CXParametersView::isModified()
{
  return mIsModified;
}

void
CXParametersView::resetIsModified()
{
  mIsModified = false;
}

void
CXParametersView::closeEditor(QWidget* editor, QAbstractItemDelegate::EndEditHint hint)
{
  QTableView::closeEditor(editor, hint);
}

void
CXParametersView::onDataChange()
{
  mIsModified = true;
}
