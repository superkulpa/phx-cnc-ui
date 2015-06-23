/********************************************************************************
** Form generated from reading UI file 'CXVirtualKeyboardNum.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXVIRTUALKEYBOARDNUM_H
#define UI_CXVIRTUALKEYBOARDNUM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>
#include "CXTouchButton.h"

QT_BEGIN_NAMESPACE

class Ui_CXVirtualKeyboardNum
{
public:
    QGridLayout *gridLayout_3;
    CXTouchButton *mButtonBackspace;
    CXTouchButton *mButtonEnter;
    CXTouchButton *mButtonDel;
    CXTouchButton *mCloseButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    CXTouchButton *mButton8;
    CXTouchButton *mButton3;
    CXTouchButton *mButtonPlus;
    CXTouchButton *mButton1;
    CXTouchButton *mButtonMinus;
    CXTouchButton *mButton7;
    CXTouchButton *mButton0;
    CXTouchButton *mButton6;
    CXTouchButton *mButton4;
    CXTouchButton *mButton2;
    CXTouchButton *mButton5;
    CXTouchButton *mButton9;
    QSpacerItem *verticalSpacer;
    QButtonGroup *mLiteralGroup;

    void setupUi(QWidget *CXVirtualKeyboardNum)
    {
        if (CXVirtualKeyboardNum->objectName().isEmpty())
            CXVirtualKeyboardNum->setObjectName(QString::fromUtf8("CXVirtualKeyboardNum"));
        CXVirtualKeyboardNum->resize(363, 197);
        gridLayout_3 = new QGridLayout(CXVirtualKeyboardNum);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(7, 7, 7, 7);
        mButtonBackspace = new CXTouchButton(CXVirtualKeyboardNum);
        mLiteralGroup = new QButtonGroup(CXVirtualKeyboardNum);
        mLiteralGroup->setObjectName(QString::fromUtf8("mLiteralGroup"));
        mLiteralGroup->addButton(mButtonBackspace);
        mButtonBackspace->setObjectName(QString::fromUtf8("mButtonBackspace"));
        mButtonBackspace->setFocusPolicy(Qt::NoFocus);

        gridLayout_3->addWidget(mButtonBackspace, 1, 0, 1, 1);

        mButtonEnter = new CXTouchButton(CXVirtualKeyboardNum);
        mLiteralGroup->addButton(mButtonEnter);
        mButtonEnter->setObjectName(QString::fromUtf8("mButtonEnter"));
        mButtonEnter->setFocusPolicy(Qt::NoFocus);

        gridLayout_3->addWidget(mButtonEnter, 1, 1, 1, 1);

        mButtonDel = new CXTouchButton(CXVirtualKeyboardNum);
        mLiteralGroup->addButton(mButtonDel);
        mButtonDel->setObjectName(QString::fromUtf8("mButtonDel"));
        mButtonDel->setFocusPolicy(Qt::NoFocus);

        gridLayout_3->addWidget(mButtonDel, 1, 2, 1, 1);

        mCloseButton = new CXTouchButton(CXVirtualKeyboardNum);
        mCloseButton->setObjectName(QString::fromUtf8("mCloseButton"));
        mCloseButton->setFocusPolicy(Qt::NoFocus);

        gridLayout_3->addWidget(mCloseButton, 2, 1, 1, 2);

        widget = new QWidget(CXVirtualKeyboardNum);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mButton8 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton8);
        mButton8->setObjectName(QString::fromUtf8("mButton8"));
        mButton8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton8, 0, 2, 1, 1);

        mButton3 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton3);
        mButton3->setObjectName(QString::fromUtf8("mButton3"));
        mButton3->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton3, 1, 1, 1, 1);

        mButtonPlus = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonPlus);
        mButtonPlus->setObjectName(QString::fromUtf8("mButtonPlus"));
        mButtonPlus->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonPlus, 2, 0, 1, 1);

        mButton1 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton1);
        mButton1->setObjectName(QString::fromUtf8("mButton1"));
        mButton1->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton1, 2, 2, 1, 1);

        mButtonMinus = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonMinus);
        mButtonMinus->setObjectName(QString::fromUtf8("mButtonMinus"));
        mButtonMinus->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonMinus, 2, 3, 1, 1);

        mButton7 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton7);
        mButton7->setObjectName(QString::fromUtf8("mButton7"));
        mButton7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton7, 0, 1, 1, 1);

        mButton0 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton0);
        mButton0->setObjectName(QString::fromUtf8("mButton0"));
        mButton0->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton0, 2, 1, 1, 1);

        mButton6 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton6);
        mButton6->setObjectName(QString::fromUtf8("mButton6"));
        mButton6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton6, 0, 0, 1, 1);

        mButton4 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton4);
        mButton4->setObjectName(QString::fromUtf8("mButton4"));
        mButton4->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton4, 1, 2, 1, 1);

        mButton2 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton2);
        mButton2->setObjectName(QString::fromUtf8("mButton2"));
        mButton2->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton2, 1, 0, 1, 1);

        mButton5 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton5);
        mButton5->setObjectName(QString::fromUtf8("mButton5"));
        mButton5->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton5, 1, 3, 1, 1);

        mButton9 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton9);
        mButton9->setObjectName(QString::fromUtf8("mButton9"));
        mButton9->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton9, 0, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 4);


        gridLayout_3->addWidget(widget, 0, 0, 1, 3);

        gridLayout_3->setRowStretch(0, 10);

        retranslateUi(CXVirtualKeyboardNum);

        QMetaObject::connectSlotsByName(CXVirtualKeyboardNum);
    } // setupUi

    void retranslateUi(QWidget *CXVirtualKeyboardNum)
    {
        CXVirtualKeyboardNum->setWindowTitle(QApplication::translate("CXVirtualKeyboardNum", "CXVirtualKeyboard", 0, QApplication::UnicodeUTF8));
        mButtonBackspace->setText(QApplication::translate("CXVirtualKeyboardNum", "\342\206\220", 0, QApplication::UnicodeUTF8));
        mButtonBackspace->setShortcut(QApplication::translate("CXVirtualKeyboardNum", "Backspace", 0, QApplication::UnicodeUTF8));
        mButtonEnter->setText(QApplication::translate("CXVirtualKeyboardNum", "Enter", 0, QApplication::UnicodeUTF8));
        mButtonEnter->setShortcut(QApplication::translate("CXVirtualKeyboardNum", "Return, Ctrl+S", 0, QApplication::UnicodeUTF8));
        mButtonDel->setText(QApplication::translate("CXVirtualKeyboardNum", "Del", 0, QApplication::UnicodeUTF8));
        mButtonDel->setShortcut(QApplication::translate("CXVirtualKeyboardNum", "Del", 0, QApplication::UnicodeUTF8));
        mCloseButton->setText(QApplication::translate("CXVirtualKeyboardNum", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mButton8->setText(QApplication::translate("CXVirtualKeyboardNum", "8", 0, QApplication::UnicodeUTF8));
        mButton8->setShortcut(QApplication::translate("CXVirtualKeyboardNum", "8", 0, QApplication::UnicodeUTF8));
        mButton3->setText(QApplication::translate("CXVirtualKeyboardNum", "3", 0, QApplication::UnicodeUTF8));
        mButton3->setShortcut(QApplication::translate("CXVirtualKeyboardNum", "3", 0, QApplication::UnicodeUTF8));
        mButtonPlus->setText(QApplication::translate("CXVirtualKeyboardNum", "+", 0, QApplication::UnicodeUTF8));
        mButtonPlus->setShortcut(QApplication::translate("CXVirtualKeyboardNum", "+", 0, QApplication::UnicodeUTF8));
        mButton1->setText(QApplication::translate("CXVirtualKeyboardNum", "1", 0, QApplication::UnicodeUTF8));
        mButton1->setShortcut(QApplication::translate("CXVirtualKeyboardNum", "1", 0, QApplication::UnicodeUTF8));
        mButtonMinus->setText(QApplication::translate("CXVirtualKeyboardNum", "-", 0, QApplication::UnicodeUTF8));
        mButtonMinus->setShortcut(QApplication::translate("CXVirtualKeyboardNum", "-", 0, QApplication::UnicodeUTF8));
        mButton7->setText(QApplication::translate("CXVirtualKeyboardNum", "7", 0, QApplication::UnicodeUTF8));
        mButton7->setShortcut(QApplication::translate("CXVirtualKeyboardNum", "7", 0, QApplication::UnicodeUTF8));
        mButton0->setText(QApplication::translate("CXVirtualKeyboardNum", "0", 0, QApplication::UnicodeUTF8));
        mButton0->setShortcut(QApplication::translate("CXVirtualKeyboardNum", "0", 0, QApplication::UnicodeUTF8));
        mButton6->setText(QApplication::translate("CXVirtualKeyboardNum", "6", 0, QApplication::UnicodeUTF8));
        mButton6->setShortcut(QApplication::translate("CXVirtualKeyboardNum", "6", 0, QApplication::UnicodeUTF8));
        mButton4->setText(QApplication::translate("CXVirtualKeyboardNum", "4", 0, QApplication::UnicodeUTF8));
        mButton4->setShortcut(QApplication::translate("CXVirtualKeyboardNum", "4", 0, QApplication::UnicodeUTF8));
        mButton2->setText(QApplication::translate("CXVirtualKeyboardNum", "2", 0, QApplication::UnicodeUTF8));
        mButton2->setShortcut(QApplication::translate("CXVirtualKeyboardNum", "2", 0, QApplication::UnicodeUTF8));
        mButton5->setText(QApplication::translate("CXVirtualKeyboardNum", "5", 0, QApplication::UnicodeUTF8));
        mButton5->setShortcut(QApplication::translate("CXVirtualKeyboardNum", "5", 0, QApplication::UnicodeUTF8));
        mButton9->setText(QApplication::translate("CXVirtualKeyboardNum", "9", 0, QApplication::UnicodeUTF8));
        mButton9->setShortcut(QApplication::translate("CXVirtualKeyboardNum", "9", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXVirtualKeyboardNum: public Ui_CXVirtualKeyboardNum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXVIRTUALKEYBOARDNUM_H
