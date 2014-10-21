#ifndef CXOPERBEVELHEAD_H
#define CXOPERBEVELHEAD_H

#include <QWidget>

#include "AXBaseWindow.h"
namespace Ui {
class CXOperBevelHead;
}

class CXOperBevelHead : public AXBaseWindow
{
    Q_OBJECT

public:
    explicit CXOperBevelHead();
    ~CXOperBevelHead();

signals:
  //! Переключить на след окно
  void
  nextWindow();

private slots:
    void onButtonClicked();
    //! Переключить на след окно
    void onNextWindow();
    ///recv udp command
    void onCommandReceive(const QString& aSection, const QString& aCommand, const QString& aValue);
    ///
    void onAMoveClicked();
    ///
    void onCMoveClicked();
    ///
    void onToZeroClicked();
    ///
    void onLockZeroClicked();
private:
    Ui::CXOperBevelHead *ui;
};

#endif // CXOPERBEVELHEAD_H
