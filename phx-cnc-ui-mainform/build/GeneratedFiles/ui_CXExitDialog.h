/********************************************************************************
** Form generated from reading UI file 'CXExitDialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXEXITDIALOG_H
#define UI_CXEXITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include "CXTouchButton.h"

QT_BEGIN_NAMESPACE

class Ui_CXExitDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    CXTouchButton *mTurnOffButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    CXTouchButton *mCancelButton;
    QSpacerItem *horizontalSpacer;
    CXTouchButton *mExitButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *CXExitDialog)
    {
        if (CXExitDialog->objectName().isEmpty())
            CXExitDialog->setObjectName(QString::fromUtf8("CXExitDialog"));
        CXExitDialog->resize(894, 621);
        gridLayout = new QGridLayout(CXExitDialog);
        gridLayout->setSpacing(10);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(873, 248, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 3);

        mTurnOffButton = new CXTouchButton(CXExitDialog);
        mTurnOffButton->setObjectName(QString::fromUtf8("mTurnOffButton"));

        gridLayout->addWidget(mTurnOffButton, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(873, 248, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        mCancelButton = new CXTouchButton(CXExitDialog);
        mCancelButton->setObjectName(QString::fromUtf8("mCancelButton"));

        horizontalLayout->addWidget(mCancelButton);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(365, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 3, 1);

        mExitButton = new CXTouchButton(CXExitDialog);
        mExitButton->setObjectName(QString::fromUtf8("mExitButton"));

        gridLayout->addWidget(mExitButton, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(364, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 2, 1);


        retranslateUi(CXExitDialog);

        QMetaObject::connectSlotsByName(CXExitDialog);
    } // setupUi

    void retranslateUi(QDialog *CXExitDialog)
    {
        CXExitDialog->setWindowTitle(QApplication::translate("CXExitDialog", "CXExitDialog", 0, QApplication::UnicodeUTF8));
        mTurnOffButton->setText(QApplication::translate("CXExitDialog", "\320\222\321\213\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\243\320\247\320\237\320\243", 0, QApplication::UnicodeUTF8));
        mCancelButton->setText(QApplication::translate("CXExitDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        mExitButton->setText(QApplication::translate("CXExitDialog", "\320\222\321\213\321\205\320\276\320\264 \320\261\320\265\320\267 \320\262\321\213\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXExitDialog: public Ui_CXExitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXEXITDIALOG_H
