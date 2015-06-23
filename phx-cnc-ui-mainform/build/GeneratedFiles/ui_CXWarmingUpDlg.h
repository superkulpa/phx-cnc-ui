/********************************************************************************
** Form generated from reading UI file 'CXWarmingUpDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXWARMINGUPDLG_H
#define UI_CXWARMINGUPDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QProgressBar>
#include <QtGui/QVBoxLayout>
#include "CXTouchButton.h"

QT_BEGIN_NAMESPACE

class Ui_WarmingUp
{
public:
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    CXTouchButton *btContinue;
    CXTouchButton *btBreak;

    void setupUi(QDialog *WarmingUpDlg)
    {
        if (WarmingUpDlg->objectName().isEmpty())
            WarmingUpDlg->setObjectName(QString::fromUtf8("WarmingUpDlg"));
        WarmingUpDlg->resize(664, 110);
        verticalLayout = new QVBoxLayout(WarmingUpDlg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        progressBar = new QProgressBar(WarmingUpDlg);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximum(100);
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        groupBox = new QGroupBox(WarmingUpDlg);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btContinue = new CXTouchButton(groupBox);
        btContinue->setObjectName(QString::fromUtf8("btContinue"));

        horizontalLayout->addWidget(btContinue);

        btBreak = new CXTouchButton(groupBox);
        btBreak->setObjectName(QString::fromUtf8("btBreak"));

        horizontalLayout->addWidget(btBreak);


        verticalLayout->addWidget(groupBox);


        retranslateUi(WarmingUpDlg);

        QMetaObject::connectSlotsByName(WarmingUpDlg);
    } // setupUi

    void retranslateUi(QDialog *WarmingUpDlg)
    {
        WarmingUpDlg->setWindowTitle(QApplication::translate("WarmingUp", "\320\237\321\200\320\276\320\263\321\200\320\265\320\262", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("WarmingUp", "\320\237\321\200\320\265\321\200\320\262\320\260\321\202\321\214/\320\277\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214 \320\277\321\200\320\276\320\263\321\200\320\265\320\262", 0, QApplication::UnicodeUTF8));
        btContinue->setText(QApplication::translate("WarmingUp", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        btBreak->setText(QApplication::translate("WarmingUp", "\320\237\321\200\320\265\321\200\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WarmingUp: public Ui_WarmingUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXWARMINGUPDLG_H
