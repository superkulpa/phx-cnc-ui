/********************************************************************************
** Form generated from reading UI file 'CXVirtualKeyboard.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXVIRTUALKEYBOARD_H
#define UI_CXVIRTUALKEYBOARD_H

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

class Ui_CXVirtualKeyboard
{
public:
    QGridLayout *gridLayout_3;
    CXTouchButton *mButtonBackspace;
    CXTouchButton *mButtonEnter;
    CXTouchButton *mButtonDel;
    CXTouchButton *mCloseButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    CXTouchButton *mButtonC_4;
    CXTouchButton *mButton8;
    CXTouchButton *mButton3;
    CXTouchButton *mButtonB_7;
    CXTouchButton *mButtonPlus;
    CXTouchButton *mButton1;
    CXTouchButton *mButtonC_8;
    CXTouchButton *mButtonB_6;
    CXTouchButton *mButtonB_5;
    CXTouchButton *mButtonMinus;
    CXTouchButton *mButtonB;
    CXTouchButton *mButtonC_3;
    CXTouchButton *mButtonB_9;
    CXTouchButton *mButtonB_4;
    CXTouchButton *mButtonA_5;
    CXTouchButton *mButtonA;
    CXTouchButton *mButtonC;
    CXTouchButton *mButtonB_2;
    CXTouchButton *mButtonA_2;
    CXTouchButton *mButton7;
    CXTouchButton *mButtonA_8;
    CXTouchButton *mButton0;
    CXTouchButton *mButtonA_7;
    CXTouchButton *mButton6;
    CXTouchButton *mButtonC_5;
    CXTouchButton *mButton4;
    CXTouchButton *mButton2;
    CXTouchButton *mButton5;
    CXTouchButton *mButtonC_7;
    CXTouchButton *mButtonB_3;
    CXTouchButton *mButtonB_8;
    CXTouchButton *mButtonA_9;
    CXTouchButton *mButtonA_3;
    CXTouchButton *mButtonA_6;
    CXTouchButton *mButtonA_4;
    CXTouchButton *mButtonC_2;
    CXTouchButton *mButton9;
    CXTouchButton *mButtonC_6;
    QSpacerItem *verticalSpacer;
    QButtonGroup *mLiteralGroup;

    void setupUi(QWidget *CXVirtualKeyboard)
    {
        if (CXVirtualKeyboard->objectName().isEmpty())
            CXVirtualKeyboard->setObjectName(QString::fromUtf8("CXVirtualKeyboard"));
        CXVirtualKeyboard->resize(323, 326);
        gridLayout_3 = new QGridLayout(CXVirtualKeyboard);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setContentsMargins(7, 7, 7, 7);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        mButtonBackspace = new CXTouchButton(CXVirtualKeyboard);
        mLiteralGroup = new QButtonGroup(CXVirtualKeyboard);
        mLiteralGroup->setObjectName(QString::fromUtf8("mLiteralGroup"));
        mLiteralGroup->addButton(mButtonBackspace);
        mButtonBackspace->setObjectName(QString::fromUtf8("mButtonBackspace"));
        mButtonBackspace->setFocusPolicy(Qt::NoFocus);

        gridLayout_3->addWidget(mButtonBackspace, 1, 0, 1, 1);

        mButtonEnter = new CXTouchButton(CXVirtualKeyboard);
        mLiteralGroup->addButton(mButtonEnter);
        mButtonEnter->setObjectName(QString::fromUtf8("mButtonEnter"));
        mButtonEnter->setFocusPolicy(Qt::NoFocus);

        gridLayout_3->addWidget(mButtonEnter, 1, 1, 1, 1);

        mButtonDel = new CXTouchButton(CXVirtualKeyboard);
        mLiteralGroup->addButton(mButtonDel);
        mButtonDel->setObjectName(QString::fromUtf8("mButtonDel"));
        mButtonDel->setFocusPolicy(Qt::NoFocus);

        gridLayout_3->addWidget(mButtonDel, 1, 2, 1, 1);

        mCloseButton = new CXTouchButton(CXVirtualKeyboard);
        mCloseButton->setObjectName(QString::fromUtf8("mCloseButton"));
        mCloseButton->setFocusPolicy(Qt::NoFocus);

        gridLayout_3->addWidget(mCloseButton, 2, 1, 1, 2);

        widget = new QWidget(CXVirtualKeyboard);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mButtonC_4 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonC_4);
        mButtonC_4->setObjectName(QString::fromUtf8("mButtonC_4"));
        mButtonC_4->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonC_4, 2, 3, 1, 1);

        mButton8 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton8);
        mButton8->setObjectName(QString::fromUtf8("mButton8"));
        mButton8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton8, 7, 2, 1, 1);

        mButton3 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton3);
        mButton3->setObjectName(QString::fromUtf8("mButton3"));
        mButton3->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton3, 8, 1, 1, 1);

        mButtonB_7 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonB_7);
        mButtonB_7->setObjectName(QString::fromUtf8("mButtonB_7"));
        mButtonB_7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonB_7, 4, 3, 1, 1);

        mButtonPlus = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonPlus);
        mButtonPlus->setObjectName(QString::fromUtf8("mButtonPlus"));
        mButtonPlus->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonPlus, 9, 0, 1, 1);

        mButton1 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton1);
        mButton1->setObjectName(QString::fromUtf8("mButton1"));
        mButton1->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton1, 9, 2, 1, 1);

        mButtonC_8 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonC_8);
        mButtonC_8->setObjectName(QString::fromUtf8("mButtonC_8"));
        mButtonC_8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonC_8, 5, 3, 1, 1);

        mButtonB_6 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonB_6);
        mButtonB_6->setObjectName(QString::fromUtf8("mButtonB_6"));
        mButtonB_6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonB_6, 4, 0, 1, 1);

        mButtonB_5 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonB_5);
        mButtonB_5->setObjectName(QString::fromUtf8("mButtonB_5"));
        mButtonB_5->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonB_5, 3, 1, 1, 1);

        mButtonMinus = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonMinus);
        mButtonMinus->setObjectName(QString::fromUtf8("mButtonMinus"));
        mButtonMinus->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonMinus, 9, 3, 1, 1);

        mButtonB = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonB);
        mButtonB->setObjectName(QString::fromUtf8("mButtonB"));
        mButtonB->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonB, 0, 1, 1, 1);

        mButtonC_3 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonC_3);
        mButtonC_3->setObjectName(QString::fromUtf8("mButtonC_3"));
        mButtonC_3->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonC_3, 2, 0, 1, 1);

        mButtonB_9 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonB_9);
        mButtonB_9->setObjectName(QString::fromUtf8("mButtonB_9"));
        mButtonB_9->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonB_9, 6, 2, 1, 1);

        mButtonB_4 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonB_4);
        mButtonB_4->setObjectName(QString::fromUtf8("mButtonB_4"));
        mButtonB_4->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonB_4, 2, 2, 1, 1);

        mButtonA_5 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonA_5);
        mButtonA_5->setObjectName(QString::fromUtf8("mButtonA_5"));
        mButtonA_5->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonA_5, 3, 0, 1, 1);

        mButtonA = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonA);
        mButtonA->setObjectName(QString::fromUtf8("mButtonA"));
        mButtonA->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonA, 0, 0, 1, 1);

        mButtonC = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonC);
        mButtonC->setObjectName(QString::fromUtf8("mButtonC"));
        mButtonC->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonC, 0, 2, 1, 1);

        mButtonB_2 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonB_2);
        mButtonB_2->setObjectName(QString::fromUtf8("mButtonB_2"));
        mButtonB_2->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonB_2, 1, 0, 1, 1);

        mButtonA_2 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonA_2);
        mButtonA_2->setObjectName(QString::fromUtf8("mButtonA_2"));
        mButtonA_2->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonA_2, 0, 3, 1, 1);

        mButton7 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton7);
        mButton7->setObjectName(QString::fromUtf8("mButton7"));
        mButton7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton7, 7, 1, 1, 1);

        mButtonA_8 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonA_8);
        mButtonA_8->setObjectName(QString::fromUtf8("mButtonA_8"));
        mButtonA_8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonA_8, 5, 1, 1, 1);

        mButton0 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton0);
        mButton0->setObjectName(QString::fromUtf8("mButton0"));
        mButton0->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton0, 9, 1, 1, 1);

        mButtonA_7 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonA_7);
        mButtonA_7->setObjectName(QString::fromUtf8("mButtonA_7"));
        mButtonA_7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonA_7, 4, 2, 1, 1);

        mButton6 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton6);
        mButton6->setObjectName(QString::fromUtf8("mButton6"));
        mButton6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton6, 7, 0, 1, 1);

        mButtonC_5 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonC_5);
        mButtonC_5->setObjectName(QString::fromUtf8("mButtonC_5"));
        mButtonC_5->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonC_5, 3, 2, 1, 1);

        mButton4 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton4);
        mButton4->setObjectName(QString::fromUtf8("mButton4"));
        mButton4->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton4, 8, 2, 1, 1);

        mButton2 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton2);
        mButton2->setObjectName(QString::fromUtf8("mButton2"));
        mButton2->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton2, 8, 0, 1, 1);

        mButton5 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton5);
        mButton5->setObjectName(QString::fromUtf8("mButton5"));
        mButton5->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton5, 8, 3, 1, 1);

        mButtonC_7 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonC_7);
        mButtonC_7->setObjectName(QString::fromUtf8("mButtonC_7"));
        mButtonC_7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonC_7, 5, 0, 1, 1);

        mButtonB_3 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonB_3);
        mButtonB_3->setObjectName(QString::fromUtf8("mButtonB_3"));
        mButtonB_3->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonB_3, 1, 3, 1, 1);

        mButtonB_8 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonB_8);
        mButtonB_8->setObjectName(QString::fromUtf8("mButtonB_8"));
        mButtonB_8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonB_8, 5, 2, 1, 1);

        mButtonA_9 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonA_9);
        mButtonA_9->setObjectName(QString::fromUtf8("mButtonA_9"));
        mButtonA_9->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonA_9, 6, 1, 1, 1);

        mButtonA_3 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonA_3);
        mButtonA_3->setObjectName(QString::fromUtf8("mButtonA_3"));
        mButtonA_3->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonA_3, 1, 2, 1, 1);

        mButtonA_6 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonA_6);
        mButtonA_6->setObjectName(QString::fromUtf8("mButtonA_6"));
        mButtonA_6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonA_6, 3, 3, 1, 1);

        mButtonA_4 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonA_4);
        mButtonA_4->setObjectName(QString::fromUtf8("mButtonA_4"));
        mButtonA_4->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonA_4, 2, 1, 1, 1);

        mButtonC_2 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonC_2);
        mButtonC_2->setObjectName(QString::fromUtf8("mButtonC_2"));
        mButtonC_2->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonC_2, 1, 1, 1, 1);

        mButton9 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButton9);
        mButton9->setObjectName(QString::fromUtf8("mButton9"));
        mButton9->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton9, 7, 3, 1, 1);

        mButtonC_6 = new CXTouchButton(widget);
        mLiteralGroup->addButton(mButtonC_6);
        mButtonC_6->setObjectName(QString::fromUtf8("mButtonC_6"));
        mButtonC_6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonC_6, 4, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 10, 0, 1, 4);


        gridLayout_3->addWidget(widget, 0, 0, 1, 3);

        gridLayout_3->setRowStretch(0, 10);

        retranslateUi(CXVirtualKeyboard);

        QMetaObject::connectSlotsByName(CXVirtualKeyboard);
    } // setupUi

    void retranslateUi(QWidget *CXVirtualKeyboard)
    {
        CXVirtualKeyboard->setWindowTitle(QApplication::translate("CXVirtualKeyboard", "CXVirtualKeyboard", 0, QApplication::UnicodeUTF8));
        mButtonBackspace->setText(QApplication::translate("CXVirtualKeyboard", "\342\206\220", 0, QApplication::UnicodeUTF8));
        mButtonBackspace->setShortcut(QApplication::translate("CXVirtualKeyboard", "Backspace", 0, QApplication::UnicodeUTF8));
        mButtonEnter->setText(QApplication::translate("CXVirtualKeyboard", "Enter", 0, QApplication::UnicodeUTF8));
        mButtonEnter->setShortcut(QApplication::translate("CXVirtualKeyboard", "Return, Ctrl+S", 0, QApplication::UnicodeUTF8));
        mButtonDel->setText(QApplication::translate("CXVirtualKeyboard", "Del", 0, QApplication::UnicodeUTF8));
        mButtonDel->setShortcut(QApplication::translate("CXVirtualKeyboard", "Del", 0, QApplication::UnicodeUTF8));
        mCloseButton->setText(QApplication::translate("CXVirtualKeyboard", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mButtonC_4->setText(QApplication::translate("CXVirtualKeyboard", "L", 0, QApplication::UnicodeUTF8));
        mButtonC_4->setShortcut(QApplication::translate("CXVirtualKeyboard", "L", 0, QApplication::UnicodeUTF8));
        mButton8->setText(QApplication::translate("CXVirtualKeyboard", "8", 0, QApplication::UnicodeUTF8));
        mButton8->setShortcut(QApplication::translate("CXVirtualKeyboard", "8", 0, QApplication::UnicodeUTF8));
        mButton3->setText(QApplication::translate("CXVirtualKeyboard", "3", 0, QApplication::UnicodeUTF8));
        mButton3->setShortcut(QApplication::translate("CXVirtualKeyboard", "3", 0, QApplication::UnicodeUTF8));
        mButtonB_7->setText(QApplication::translate("CXVirtualKeyboard", "T", 0, QApplication::UnicodeUTF8));
        mButtonB_7->setShortcut(QApplication::translate("CXVirtualKeyboard", "T", 0, QApplication::UnicodeUTF8));
        mButtonPlus->setText(QApplication::translate("CXVirtualKeyboard", "+", 0, QApplication::UnicodeUTF8));
        mButtonPlus->setShortcut(QApplication::translate("CXVirtualKeyboard", "+", 0, QApplication::UnicodeUTF8));
        mButton1->setText(QApplication::translate("CXVirtualKeyboard", "1", 0, QApplication::UnicodeUTF8));
        mButton1->setShortcut(QApplication::translate("CXVirtualKeyboard", "1", 0, QApplication::UnicodeUTF8));
        mButtonC_8->setText(QApplication::translate("CXVirtualKeyboard", "X", 0, QApplication::UnicodeUTF8));
        mButtonC_8->setShortcut(QApplication::translate("CXVirtualKeyboard", "X", 0, QApplication::UnicodeUTF8));
        mButtonB_6->setText(QApplication::translate("CXVirtualKeyboard", "Q", 0, QApplication::UnicodeUTF8));
        mButtonB_6->setShortcut(QApplication::translate("CXVirtualKeyboard", "Q", 0, QApplication::UnicodeUTF8));
        mButtonB_5->setText(QApplication::translate("CXVirtualKeyboard", "N", 0, QApplication::UnicodeUTF8));
        mButtonB_5->setShortcut(QApplication::translate("CXVirtualKeyboard", "N", 0, QApplication::UnicodeUTF8));
        mButtonMinus->setText(QApplication::translate("CXVirtualKeyboard", "-", 0, QApplication::UnicodeUTF8));
        mButtonMinus->setShortcut(QApplication::translate("CXVirtualKeyboard", "-", 0, QApplication::UnicodeUTF8));
        mButtonB->setText(QApplication::translate("CXVirtualKeyboard", "B", 0, QApplication::UnicodeUTF8));
        mButtonB->setShortcut(QApplication::translate("CXVirtualKeyboard", "B", 0, QApplication::UnicodeUTF8));
        mButtonC_3->setText(QApplication::translate("CXVirtualKeyboard", "I", 0, QApplication::UnicodeUTF8));
        mButtonC_3->setShortcut(QApplication::translate("CXVirtualKeyboard", "I", 0, QApplication::UnicodeUTF8));
        mButtonB_9->setText(QApplication::translate("CXVirtualKeyboard", "Z", 0, QApplication::UnicodeUTF8));
        mButtonB_9->setShortcut(QApplication::translate("CXVirtualKeyboard", "Z", 0, QApplication::UnicodeUTF8));
        mButtonB_4->setText(QApplication::translate("CXVirtualKeyboard", "K", 0, QApplication::UnicodeUTF8));
        mButtonB_4->setShortcut(QApplication::translate("CXVirtualKeyboard", "K", 0, QApplication::UnicodeUTF8));
        mButtonA_5->setText(QApplication::translate("CXVirtualKeyboard", "M", 0, QApplication::UnicodeUTF8));
        mButtonA_5->setShortcut(QApplication::translate("CXVirtualKeyboard", "M", 0, QApplication::UnicodeUTF8));
        mButtonA->setText(QApplication::translate("CXVirtualKeyboard", "A", 0, QApplication::UnicodeUTF8));
        mButtonA->setShortcut(QApplication::translate("CXVirtualKeyboard", "A", 0, QApplication::UnicodeUTF8));
        mButtonC->setText(QApplication::translate("CXVirtualKeyboard", "C", 0, QApplication::UnicodeUTF8));
        mButtonC->setShortcut(QApplication::translate("CXVirtualKeyboard", "C", 0, QApplication::UnicodeUTF8));
        mButtonB_2->setText(QApplication::translate("CXVirtualKeyboard", "E", 0, QApplication::UnicodeUTF8));
        mButtonB_2->setShortcut(QApplication::translate("CXVirtualKeyboard", "E", 0, QApplication::UnicodeUTF8));
        mButtonA_2->setText(QApplication::translate("CXVirtualKeyboard", "D", 0, QApplication::UnicodeUTF8));
        mButtonA_2->setShortcut(QApplication::translate("CXVirtualKeyboard", "D", 0, QApplication::UnicodeUTF8));
        mButton7->setText(QApplication::translate("CXVirtualKeyboard", "7", 0, QApplication::UnicodeUTF8));
        mButton7->setShortcut(QApplication::translate("CXVirtualKeyboard", "7", 0, QApplication::UnicodeUTF8));
        mButtonA_8->setText(QApplication::translate("CXVirtualKeyboard", "V", 0, QApplication::UnicodeUTF8));
        mButtonA_8->setShortcut(QApplication::translate("CXVirtualKeyboard", "V", 0, QApplication::UnicodeUTF8));
        mButton0->setText(QApplication::translate("CXVirtualKeyboard", "0", 0, QApplication::UnicodeUTF8));
        mButton0->setShortcut(QApplication::translate("CXVirtualKeyboard", "0", 0, QApplication::UnicodeUTF8));
        mButtonA_7->setText(QApplication::translate("CXVirtualKeyboard", "S", 0, QApplication::UnicodeUTF8));
        mButtonA_7->setShortcut(QApplication::translate("CXVirtualKeyboard", "S", 0, QApplication::UnicodeUTF8));
        mButton6->setText(QApplication::translate("CXVirtualKeyboard", "6", 0, QApplication::UnicodeUTF8));
        mButton6->setShortcut(QApplication::translate("CXVirtualKeyboard", "6", 0, QApplication::UnicodeUTF8));
        mButtonC_5->setText(QApplication::translate("CXVirtualKeyboard", "O", 0, QApplication::UnicodeUTF8));
        mButtonC_5->setShortcut(QApplication::translate("CXVirtualKeyboard", "O", 0, QApplication::UnicodeUTF8));
        mButton4->setText(QApplication::translate("CXVirtualKeyboard", "4", 0, QApplication::UnicodeUTF8));
        mButton4->setShortcut(QApplication::translate("CXVirtualKeyboard", "4", 0, QApplication::UnicodeUTF8));
        mButton2->setText(QApplication::translate("CXVirtualKeyboard", "2", 0, QApplication::UnicodeUTF8));
        mButton2->setShortcut(QApplication::translate("CXVirtualKeyboard", "2", 0, QApplication::UnicodeUTF8));
        mButton5->setText(QApplication::translate("CXVirtualKeyboard", "5", 0, QApplication::UnicodeUTF8));
        mButton5->setShortcut(QApplication::translate("CXVirtualKeyboard", "5", 0, QApplication::UnicodeUTF8));
        mButtonC_7->setText(QApplication::translate("CXVirtualKeyboard", "U", 0, QApplication::UnicodeUTF8));
        mButtonC_7->setShortcut(QApplication::translate("CXVirtualKeyboard", "U", 0, QApplication::UnicodeUTF8));
        mButtonB_3->setText(QApplication::translate("CXVirtualKeyboard", "H", 0, QApplication::UnicodeUTF8));
        mButtonB_3->setShortcut(QApplication::translate("CXVirtualKeyboard", "H", 0, QApplication::UnicodeUTF8));
        mButtonB_8->setText(QApplication::translate("CXVirtualKeyboard", "W", 0, QApplication::UnicodeUTF8));
        mButtonB_8->setShortcut(QApplication::translate("CXVirtualKeyboard", "W", 0, QApplication::UnicodeUTF8));
        mButtonA_9->setText(QApplication::translate("CXVirtualKeyboard", "Y", 0, QApplication::UnicodeUTF8));
        mButtonA_9->setShortcut(QApplication::translate("CXVirtualKeyboard", "Y", 0, QApplication::UnicodeUTF8));
        mButtonA_3->setText(QApplication::translate("CXVirtualKeyboard", "G", 0, QApplication::UnicodeUTF8));
        mButtonA_3->setShortcut(QApplication::translate("CXVirtualKeyboard", "G", 0, QApplication::UnicodeUTF8));
        mButtonA_6->setText(QApplication::translate("CXVirtualKeyboard", "P", 0, QApplication::UnicodeUTF8));
        mButtonA_6->setShortcut(QApplication::translate("CXVirtualKeyboard", "P", 0, QApplication::UnicodeUTF8));
        mButtonA_4->setText(QApplication::translate("CXVirtualKeyboard", "J", 0, QApplication::UnicodeUTF8));
        mButtonA_4->setShortcut(QApplication::translate("CXVirtualKeyboard", "J", 0, QApplication::UnicodeUTF8));
        mButtonC_2->setText(QApplication::translate("CXVirtualKeyboard", "F", 0, QApplication::UnicodeUTF8));
        mButtonC_2->setShortcut(QApplication::translate("CXVirtualKeyboard", "F", 0, QApplication::UnicodeUTF8));
        mButton9->setText(QApplication::translate("CXVirtualKeyboard", "9", 0, QApplication::UnicodeUTF8));
        mButton9->setShortcut(QApplication::translate("CXVirtualKeyboard", "9", 0, QApplication::UnicodeUTF8));
        mButtonC_6->setText(QApplication::translate("CXVirtualKeyboard", "R", 0, QApplication::UnicodeUTF8));
        mButtonC_6->setShortcut(QApplication::translate("CXVirtualKeyboard", "R", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXVirtualKeyboard: public Ui_CXVirtualKeyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXVIRTUALKEYBOARD_H
