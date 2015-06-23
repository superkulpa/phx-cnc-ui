/********************************************************************************
** Form generated from reading UI file 'CXOperBevelHead.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXOPERBEVELHEAD_H
#define UI_CXOPERBEVELHEAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "CXTouchButton.h"

QT_BEGIN_NAMESPACE

class Ui_CXOperBevelHead
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *eposC;
    QLabel *lposC;
    CXTouchButton *bCmove;
    CXTouchButton *bAmove;
    QLabel *lposA;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *eposA;
    QLabel *label_4;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    CXTouchButton *bGoToZero;
    CXTouchButton *bLockZero;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    CXTouchButton *mButton0;
    CXTouchButton *mButton1;
    CXTouchButton *mButton4;
    CXTouchButton *mButton7;
    CXTouchButton *mButton6;
    CXTouchButton *mButton5;
    CXTouchButton *mButtonMinus;
    CXTouchButton *mButton8;
    CXTouchButton *mButtonPlus;
    CXTouchButton *mButtonEnter;
    CXTouchButton *mButtonBackspace;
    CXTouchButton *mButtonDel;
    CXTouchButton *mButton3;
    CXTouchButton *mButton9;
    CXTouchButton *mButton2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    CXTouchButton *bBlockMove;
    CXTouchButton *nextWindow;

    void setupUi(QWidget *CXOperBevelHead)
    {
        if (CXOperBevelHead->objectName().isEmpty())
            CXOperBevelHead->setObjectName(QString::fromUtf8("CXOperBevelHead"));
        CXOperBevelHead->resize(350, 491);
        verticalLayout = new QVBoxLayout(CXOperBevelHead);
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(CXOperBevelHead);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        eposC = new QLineEdit(groupBox);
        eposC->setObjectName(QString::fromUtf8("eposC"));

        gridLayout->addWidget(eposC, 3, 2, 1, 1);

        lposC = new QLabel(groupBox);
        lposC->setObjectName(QString::fromUtf8("lposC"));

        gridLayout->addWidget(lposC, 2, 2, 1, 1);

        bCmove = new CXTouchButton(groupBox);
        bCmove->setObjectName(QString::fromUtf8("bCmove"));

        gridLayout->addWidget(bCmove, 3, 0, 1, 1);

        bAmove = new CXTouchButton(groupBox);
        bAmove->setObjectName(QString::fromUtf8("bAmove"));

        gridLayout->addWidget(bAmove, 1, 0, 1, 1);

        lposA = new QLabel(groupBox);
        lposA->setObjectName(QString::fromUtf8("lposA"));

        gridLayout->addWidget(lposA, 0, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 2);

        eposA = new QLineEdit(groupBox);
        eposA->setObjectName(QString::fromUtf8("eposA"));

        gridLayout->addWidget(eposA, 1, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 3, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 3, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        bGoToZero = new CXTouchButton(CXOperBevelHead);
        bGoToZero->setObjectName(QString::fromUtf8("bGoToZero"));

        horizontalLayout_2->addWidget(bGoToZero);

        bLockZero = new CXTouchButton(CXOperBevelHead);
        bLockZero->setObjectName(QString::fromUtf8("bLockZero"));

        horizontalLayout_2->addWidget(bLockZero);


        verticalLayout->addLayout(horizontalLayout_2);

        frame_2 = new QFrame(CXOperBevelHead);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(16777215, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        mButton0 = new CXTouchButton(frame_2);
        mButton0->setObjectName(QString::fromUtf8("mButton0"));
        mButton0->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mButton0, 3, 1, 1, 1);

        mButton1 = new CXTouchButton(frame_2);
        mButton1->setObjectName(QString::fromUtf8("mButton1"));
        mButton1->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mButton1, 2, 0, 1, 1);

        mButton4 = new CXTouchButton(frame_2);
        mButton4->setObjectName(QString::fromUtf8("mButton4"));
        mButton4->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mButton4, 1, 0, 1, 1);

        mButton7 = new CXTouchButton(frame_2);
        mButton7->setObjectName(QString::fromUtf8("mButton7"));
        mButton7->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mButton7, 0, 0, 1, 1);

        mButton6 = new CXTouchButton(frame_2);
        mButton6->setObjectName(QString::fromUtf8("mButton6"));
        mButton6->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mButton6, 1, 2, 1, 1);

        mButton5 = new CXTouchButton(frame_2);
        mButton5->setObjectName(QString::fromUtf8("mButton5"));
        mButton5->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mButton5, 1, 1, 1, 1);

        mButtonMinus = new CXTouchButton(frame_2);
        mButtonMinus->setObjectName(QString::fromUtf8("mButtonMinus"));
        mButtonMinus->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mButtonMinus, 3, 2, 1, 1);

        mButton8 = new CXTouchButton(frame_2);
        mButton8->setObjectName(QString::fromUtf8("mButton8"));
        mButton8->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mButton8, 0, 1, 1, 1);

        mButtonPlus = new CXTouchButton(frame_2);
        mButtonPlus->setObjectName(QString::fromUtf8("mButtonPlus"));
        mButtonPlus->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mButtonPlus, 3, 0, 1, 1);

        mButtonEnter = new CXTouchButton(frame_2);
        mButtonEnter->setObjectName(QString::fromUtf8("mButtonEnter"));
        mButtonEnter->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mButtonEnter, 4, 1, 1, 1);

        mButtonBackspace = new CXTouchButton(frame_2);
        mButtonBackspace->setObjectName(QString::fromUtf8("mButtonBackspace"));
        mButtonBackspace->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mButtonBackspace, 4, 0, 1, 1);

        mButtonDel = new CXTouchButton(frame_2);
        mButtonDel->setObjectName(QString::fromUtf8("mButtonDel"));
        mButtonDel->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mButtonDel, 4, 2, 1, 1);

        mButton3 = new CXTouchButton(frame_2);
        mButton3->setObjectName(QString::fromUtf8("mButton3"));
        mButton3->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mButton3, 2, 2, 1, 1);

        mButton9 = new CXTouchButton(frame_2);
        mButton9->setObjectName(QString::fromUtf8("mButton9"));
        mButton9->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mButton9, 0, 2, 1, 1);

        mButton2 = new CXTouchButton(frame_2);
        mButton2->setObjectName(QString::fromUtf8("mButton2"));
        mButton2->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mButton2, 2, 1, 1, 1);


        verticalLayout->addWidget(frame_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bBlockMove = new CXTouchButton(CXOperBevelHead);
        bBlockMove->setObjectName(QString::fromUtf8("bBlockMove"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bBlockMove->sizePolicy().hasHeightForWidth());
        bBlockMove->setSizePolicy(sizePolicy);
        bBlockMove->setMinimumSize(QSize(121, 45));

        horizontalLayout->addWidget(bBlockMove);

        nextWindow = new CXTouchButton(CXOperBevelHead);
        nextWindow->setObjectName(QString::fromUtf8("nextWindow"));
        nextWindow->setMinimumSize(QSize(121, 45));

        horizontalLayout->addWidget(nextWindow);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CXOperBevelHead);

        QMetaObject::connectSlotsByName(CXOperBevelHead);
    } // setupUi

    void retranslateUi(QWidget *CXOperBevelHead)
    {
        CXOperBevelHead->setWindowTitle(QApplication::translate("CXOperBevelHead", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CXOperBevelHead", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\275\321\213\320\274 \320\261\320\273\320\276\320\272\320\276\320\274", 0, QApplication::UnicodeUTF8));
        lposC->setText(QApplication::translate("CXOperBevelHead", "0", 0, QApplication::UnicodeUTF8));
        bCmove->setText(QApplication::translate("CXOperBevelHead", "\320\237\320\265\321\200\320\265\320\265\321\205\320\260\321\202\321\214 \320\262 \320\277\320\276\320\267\320\270\321\206\320\270\321\216", 0, QApplication::UnicodeUTF8));
        bAmove->setText(QApplication::translate("CXOperBevelHead", "\320\237\320\265\321\200\320\265\320\265\321\205\320\260\321\202\321\214 \320\262 \320\277\320\276\320\267\320\270\321\206\320\270\321\216", 0, QApplication::UnicodeUTF8));
        lposA->setText(QApplication::translate("CXOperBevelHead", "0", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CXOperBevelHead", "\320\235\320\260\320\272\320\273\320\276\320\275 \321\200\320\265\320\267\320\260\320\272\320\260, A", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CXOperBevelHead", "\320\240\320\260\320\267\320\262\320\276\321\200\320\276\321\202 \320\261\320\273\320\276\320\272\320\260, C", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CXOperBevelHead", "0.1", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CXOperBevelHead", "0.1", 0, QApplication::UnicodeUTF8));
        bGoToZero->setText(QApplication::translate("CXOperBevelHead", "\320\237\320\265\321\200\320\265\320\265\321\205\320\260\321\202\321\214 \320\262 \320\275\320\276\320\273\321\214", 0, QApplication::UnicodeUTF8));
        bLockZero->setText(QApplication::translate("CXOperBevelHead", "\320\244\320\270\320\272\321\201\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\275\320\276\320\273\321\214", 0, QApplication::UnicodeUTF8));
        mButton0->setText(QApplication::translate("CXOperBevelHead", "0", 0, QApplication::UnicodeUTF8));
        mButton0->setShortcut(QApplication::translate("CXOperBevelHead", "0", 0, QApplication::UnicodeUTF8));
        mButton1->setText(QApplication::translate("CXOperBevelHead", "1", 0, QApplication::UnicodeUTF8));
        mButton1->setShortcut(QApplication::translate("CXOperBevelHead", "1", 0, QApplication::UnicodeUTF8));
        mButton4->setText(QApplication::translate("CXOperBevelHead", "4", 0, QApplication::UnicodeUTF8));
        mButton4->setShortcut(QApplication::translate("CXOperBevelHead", "4", 0, QApplication::UnicodeUTF8));
        mButton7->setText(QApplication::translate("CXOperBevelHead", "7", 0, QApplication::UnicodeUTF8));
        mButton7->setShortcut(QApplication::translate("CXOperBevelHead", "7", 0, QApplication::UnicodeUTF8));
        mButton6->setText(QApplication::translate("CXOperBevelHead", "6", 0, QApplication::UnicodeUTF8));
        mButton6->setShortcut(QApplication::translate("CXOperBevelHead", "6", 0, QApplication::UnicodeUTF8));
        mButton5->setText(QApplication::translate("CXOperBevelHead", "5", 0, QApplication::UnicodeUTF8));
        mButton5->setShortcut(QApplication::translate("CXOperBevelHead", "5", 0, QApplication::UnicodeUTF8));
        mButtonMinus->setText(QApplication::translate("CXOperBevelHead", "-", 0, QApplication::UnicodeUTF8));
        mButtonMinus->setShortcut(QApplication::translate("CXOperBevelHead", "-", 0, QApplication::UnicodeUTF8));
        mButton8->setText(QApplication::translate("CXOperBevelHead", "8", 0, QApplication::UnicodeUTF8));
        mButton8->setShortcut(QApplication::translate("CXOperBevelHead", "8", 0, QApplication::UnicodeUTF8));
        mButtonPlus->setText(QApplication::translate("CXOperBevelHead", "+", 0, QApplication::UnicodeUTF8));
        mButtonPlus->setShortcut(QApplication::translate("CXOperBevelHead", "+", 0, QApplication::UnicodeUTF8));
        mButtonEnter->setText(QApplication::translate("CXOperBevelHead", "Enter", 0, QApplication::UnicodeUTF8));
        mButtonEnter->setShortcut(QApplication::translate("CXOperBevelHead", "Enter, Return", 0, QApplication::UnicodeUTF8));
        mButtonBackspace->setText(QApplication::translate("CXOperBevelHead", "\342\206\220", 0, QApplication::UnicodeUTF8));
        mButtonBackspace->setShortcut(QApplication::translate("CXOperBevelHead", "Backspace", 0, QApplication::UnicodeUTF8));
        mButtonDel->setText(QApplication::translate("CXOperBevelHead", "Del", 0, QApplication::UnicodeUTF8));
        mButtonDel->setShortcut(QApplication::translate("CXOperBevelHead", "Del", 0, QApplication::UnicodeUTF8));
        mButton3->setText(QApplication::translate("CXOperBevelHead", "3", 0, QApplication::UnicodeUTF8));
        mButton3->setShortcut(QApplication::translate("CXOperBevelHead", "3", 0, QApplication::UnicodeUTF8));
        mButton9->setText(QApplication::translate("CXOperBevelHead", "9", 0, QApplication::UnicodeUTF8));
        mButton9->setShortcut(QApplication::translate("CXOperBevelHead", "9", 0, QApplication::UnicodeUTF8));
        mButton2->setText(QApplication::translate("CXOperBevelHead", "2", 0, QApplication::UnicodeUTF8));
        mButton2->setShortcut(QApplication::translate("CXOperBevelHead", "2", 0, QApplication::UnicodeUTF8));
        bBlockMove->setText(QApplication::translate("CXOperBevelHead", "\320\221\320\273.\320\224\320\262\320\270\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        nextWindow->setText(QApplication::translate("CXOperBevelHead", ">>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXOperBevelHead: public Ui_CXOperBevelHead {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXOPERBEVELHEAD_H
