#ifndef AXBASEWINDOW_H
#define AXBASEWINDOW_H

#define RESIZE_BORDER 5
#define CLING_SIZE 10

#include <QWidget>

class CXUdpManager;
class CXWindowsManager;

/*!
 Список для флага изменения размеров окна.
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
 Класс окна для отслеживания изменений размера и позиции.
 */
class AXBaseWindow : public QWidget
{
Q_OBJECT
  public:
  //! Конструктор.
  AXBaseWindow();

  //! Деструктор.
  virtual ~AXBaseWindow();

  //! Функция регистрации объекта в менеджере.
  void
  registerManager();

  /*!
   Функция установки новой геометрии окна.
   \param aNewGeometry - прямоугольник для новой геометрии окна.
   */
  void
  setNewGeometry(const QRect& aNewGeometry);

  /*!
   Функция установки номера группы для окна.
   \param aNumber - номер группы.
   */
  void
  setGroupNumber(int aNumber);

  /*!
   Функция получения номера группы окна.
   \return Номер группы.
   */
  int
  groupNumber();

  /*!
   Установка флага заморозки перемещения и изменения размеров окна.
   \param aIsFreeze - флаг заморозки.
   */
  void
  setFreeze(bool aIsFreeze);

  /*!
   Функция получения флага заморозки перемещения и изменения размеров окна.
   \return Флаг заморозки.
   */
  bool
  isFreeze();

  /*!
   Функция обработки нажатия кнопки мышки.
   */
  void
  mousePress(QMouseEvent* e);

  /*!
   Функция обработки движения мышки.
   \return Обработано событие или проигнорировано.
   */
  bool
  mouseMove(QMouseEvent* e);

  /*!
   Функция обработки отпускания кнопки мышки.
   */
  void
  mouseRelease(QMouseEvent* e);

signals:
  /*!
   Сигнал об изменении геометрии окна.
   \param aNewRect - новая геометрия окна.
   \param aIsResized - признак изменения геометрии при изменении размера.
   */
  void
  geometryChanged(const QRect& aNewRect, bool aIsResized);

  /*!
   Сигнал закрытия окна.
   */
  void
  closed();

protected:
  /*!
   Переопределенная фукнция обработки нажатия кнопки мышки.
   */
  virtual void
  mousePressEvent(QMouseEvent* e);

  /*!
   Переопределенная фукнция обработки движения мышки.
   */
  virtual void
  mouseMoveEvent(QMouseEvent* e);

  /*!
   Переопределенная фукнция обработки отпускания кнопки мышки.
   */
  virtual void
  mouseReleaseEvent(QMouseEvent* e);

  /*!
   Переопределенная фукнция рисования.
   */
  virtual void
  paintEvent(QPaintEvent* e);

  /*!
   Переопределенная фукнция выхода указателя мышки за пределы мышки.
   */
  virtual void
  leaveEvent(QEvent* e);

  /*!
   Переопределенная фукнция закрытия окна.
   */
  virtual void
  closeEvent(QCloseEvent* e);

private:
  /*!
   Функция получения типа изменения размеров формы.
   \param aRect - геометрия формы в глобальных экранных координатах.
   \param aPos - позиция мышки в глобальных экранных координатах.
   \return Флаг изменения размера окна.
   */
  eSideType
  getResizeType(const QRect& aRect, const QPoint& aPos);

public:
  //! Статический указатель на оконный менеджер.
  static CXWindowsManager* mManager;

  //! Статический указатель на класс работы с UDP.
  static CXUdpManager* mUdpManager;

private:
  //! Признак нажатия кнопки мышки на форме.
  bool mIsButtonPress;

  //! Номер группы окна.
  int mGroupNumber;

  //! Тип изменения размера окна.
  eSideType mResizeType;

  //! Список курсоров по типу изменения размера.
  QList<Qt::CursorShape> mCursors;

  //! Флаг заморозки окна.
  bool mIsFreeze;

  //! Позиция окна при нажатии левой клавиши мышки.
  QPoint mPos;

  //! Позиция курсора при нажатии левой клавиши мышки.
  QPoint mPressPos;
};

#endif // AXBASEWINDOW_H
