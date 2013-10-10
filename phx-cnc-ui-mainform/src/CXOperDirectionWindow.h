#ifndef CXOperDIRECTIONWINDOW_H
#define CXOperDIRECTIONWINDOW_H

#include "AXBaseWindow.h"

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

#include "CXOperDirectionView.h"
#include "CXOperVelocityView.h"

class CXTouchButton;
class CXUtilsWindow;

/*!
 Класс настройки направления и скорости реза с функциональными кнопками.
 */
class CXOperDirectionWindow : public AXBaseWindow
{
Q_OBJECT

public:
  //! Конструктор.
  CXOperDirectionWindow();

  //! Деструктор.
  virtual ~CXOperDirectionWindow();

public slots:
  //! Слот показа утилит.
  void
  onUtils();

  //! Слот сброса координат.
  void
  onResetCoordinates();

signals:
  /*!
   Сигнал о изменении позиции реза.

   \param aPos - координаты реза.
   \param aIsAbsolute - абсолютное ли смещение.
   */
  void
  positionChanged(const QPointF& aPos, bool aIsAbsolute);

private slots:
  //! Запуск процесса.
  void
  onStart();

  //! Остановка процесса.
  void
  onStop();

  //! Слот обработки клика по X и Y.
  void
  onXYClick();

  //! Слот получения строки команды по направлению.
  QString getDirectionCommand(OperDirectionView::eMoveDirection aDirection);

  //! Слот на изменение направления.
  void
  onDirectionChange(OperDirectionView::eMoveDirection aDirection);

  //! Слот на изменение направления и скорости.
  void
  onDirectionChange(OperDirectionView::eMoveDirection aDirection, eVelocity aVelocity);

  //! Слот на изменение скорости.
  void
  onVelocityChange(eVelocity aVelocity);

  //! Слот увеличения скорости.
  void
  onUpSpeed();

  //! Слот уменьшения скорости.
  void
  onDownSpeed();

  //! Изменение режима работы
  void
  onModeChange();

  //! Слот получения команды от ядра.
  void
  onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue);

private:
  void
  StopCP();
  void
  StartCP();

private:
  bool mIsRunning;
  CXTouchButton* mForwardButton;
  CXTouchButton* mBackwardButton;
  CXTouchButton* mSearchButton;
  CXTouchButton* mStopButton;

  CXTouchButton* mXYButton;
  QLineEdit* mXEdit;
  QLineEdit* mYEdit;
  QLabel* mFLabel;
  QLineEdit* mFEdit;

  CXTouchButton* mCycleButton;
  CXTouchButton* mStepButton;
  CXTouchButton* mFastButton;

  CXOperDirectionView* mOperDirectionView;
  CXOperVelocityView* mOperVelocityView;
  //QLabel* mCurrentFrameLabel;
  QWidget* mFrameWidget;
  CXTouchButton* mFPlusButton;
  CXTouchButton* mFMinusButton;
  CXOperVelocityView* mVelocityView;
  //Номер кадра
  QLineEdit* mFrameEdit;
  //Пробивка
  QLineEdit* mBurnEdit;

  CXUtilsWindow* mUtils;
  int mRotateAxis;
};

#endif // CXOperDIRECTIONWINDOW_H
