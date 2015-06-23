/********************************************************************************
** Form generated from reading UI file 'CXOperDirectionDialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXOPERDIRECTIONDIALOG_H
#define UI_CXOPERDIRECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "CXTouchButton.h"

QT_BEGIN_NAMESPACE

class Ui_CXOperDirectionDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *mXEdit;
    QHBoxLayout *horizontalLayout;
    CXTouchButton *mAbsoluteButton;
    CXTouchButton *mRelativeButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *mFrameEdit;
    QLineEdit *mBurnEdit;
    QGridLayout *gridLayout_3;
    QPushButton *mStepMoveButton;
    QPushButton *mBurnMoveButton;
    QPushButton *mStepSetButton;
    QPushButton *mBurnSetButton;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *mTechPointMoveButton;
    QPushButton *mSetTechPointButton;
    QPushButton *mAbsZeroMoveButton;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_2;
    QLineEdit *mYEdit;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    CXTouchButton *mButtonMinus;
    CXTouchButton *mButton6;
    QSpacerItem *verticalSpacer;
    CXTouchButton *mButtonDel;
    CXTouchButton *mButtonEnter;
    CXTouchButton *mButtonBackspace;
    CXTouchButton *mButtonPlus;
    CXTouchButton *mButton7;
    CXTouchButton *mButton8;
    CXTouchButton *mButton9;
    CXTouchButton *mButton4;
    CXTouchButton *mButton5;
    CXTouchButton *mButton1;
    CXTouchButton *mButton2;
    CXTouchButton *mButton3;
    CXTouchButton *mButton0;
    CXTouchButton *mCancelButton;

    void setupUi(QDialog *CXOperDirectionDialog)
    {
        if (CXOperDirectionDialog->objectName().isEmpty())
            CXOperDirectionDialog->setObjectName(QString::fromUtf8("CXOperDirectionDialog"));
        CXOperDirectionDialog->resize(785, 286);
        horizontalLayout_2 = new QHBoxLayout(CXOperDirectionDialog);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(CXOperDirectionDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        mXEdit = new QLineEdit(CXOperDirectionDialog);
        mXEdit->setObjectName(QString::fromUtf8("mXEdit"));

        gridLayout_2->addWidget(mXEdit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mAbsoluteButton = new CXTouchButton(CXOperDirectionDialog);
        mAbsoluteButton->setObjectName(QString::fromUtf8("mAbsoluteButton"));
        mAbsoluteButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(mAbsoluteButton);

        mRelativeButton = new CXTouchButton(CXOperDirectionDialog);
        mRelativeButton->setObjectName(QString::fromUtf8("mRelativeButton"));
        mRelativeButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(mRelativeButton);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 8);

        groupBox = new QGroupBox(CXOperDirectionDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(7, 7, 7, 7);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        mFrameEdit = new QLineEdit(groupBox);
        mFrameEdit->setObjectName(QString::fromUtf8("mFrameEdit"));

        horizontalLayout_3->addWidget(mFrameEdit);

        mBurnEdit = new QLineEdit(groupBox);
        mBurnEdit->setObjectName(QString::fromUtf8("mBurnEdit"));

        horizontalLayout_3->addWidget(mBurnEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        mStepMoveButton = new QPushButton(groupBox);
        mStepMoveButton->setObjectName(QString::fromUtf8("mStepMoveButton"));

        gridLayout_3->addWidget(mStepMoveButton, 0, 0, 1, 1);

        mBurnMoveButton = new QPushButton(groupBox);
        mBurnMoveButton->setObjectName(QString::fromUtf8("mBurnMoveButton"));

        gridLayout_3->addWidget(mBurnMoveButton, 0, 1, 1, 1);

        mStepSetButton = new QPushButton(groupBox);
        mStepSetButton->setObjectName(QString::fromUtf8("mStepSetButton"));

        gridLayout_3->addWidget(mStepSetButton, 1, 0, 1, 1);

        mBurnSetButton = new QPushButton(groupBox);
        mBurnSetButton->setObjectName(QString::fromUtf8("mBurnSetButton"));

        gridLayout_3->addWidget(mBurnSetButton, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        mTechPointMoveButton = new QPushButton(groupBox);
        mTechPointMoveButton->setObjectName(QString::fromUtf8("mTechPointMoveButton"));

        horizontalLayout_5->addWidget(mTechPointMoveButton);

        mSetTechPointButton = new QPushButton(groupBox);
        mSetTechPointButton->setObjectName(QString::fromUtf8("mSetTechPointButton"));

        horizontalLayout_5->addWidget(mSetTechPointButton);

        mAbsZeroMoveButton = new QPushButton(groupBox);
        mAbsZeroMoveButton->setObjectName(QString::fromUtf8("mAbsZeroMoveButton"));

        horizontalLayout_5->addWidget(mAbsZeroMoveButton);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout_2->addWidget(groupBox, 3, 0, 1, 8);

        label_4 = new QLabel(CXOperDirectionDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 2, 1, 1);

        label_5 = new QLabel(CXOperDirectionDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 5, 1, 1);

        label_2 = new QLabel(CXOperDirectionDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 3, 1, 1);

        mYEdit = new QLineEdit(CXOperDirectionDialog);
        mYEdit->setObjectName(QString::fromUtf8("mYEdit"));

        gridLayout_2->addWidget(mYEdit, 0, 4, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 4, 0, 1, 8);


        horizontalLayout_2->addLayout(gridLayout_2);

        frame_2 = new QFrame(CXOperDirectionDialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(332, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mButtonMinus = new CXTouchButton(frame_2);
        mButtonMinus->setObjectName(QString::fromUtf8("mButtonMinus"));
        mButtonMinus->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonMinus, 3, 2, 1, 1);

        mButton6 = new CXTouchButton(frame_2);
        mButton6->setObjectName(QString::fromUtf8("mButton6"));
        mButton6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton6, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 3);

        mButtonDel = new CXTouchButton(frame_2);
        mButtonDel->setObjectName(QString::fromUtf8("mButtonDel"));
        mButtonDel->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonDel, 4, 2, 1, 1);

        mButtonEnter = new CXTouchButton(frame_2);
        mButtonEnter->setObjectName(QString::fromUtf8("mButtonEnter"));
        mButtonEnter->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonEnter, 4, 1, 1, 1);

        mButtonBackspace = new CXTouchButton(frame_2);
        mButtonBackspace->setObjectName(QString::fromUtf8("mButtonBackspace"));
        mButtonBackspace->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonBackspace, 4, 0, 1, 1);

        mButtonPlus = new CXTouchButton(frame_2);
        mButtonPlus->setObjectName(QString::fromUtf8("mButtonPlus"));
        mButtonPlus->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonPlus, 3, 0, 1, 1);

        mButton7 = new CXTouchButton(frame_2);
        mButton7->setObjectName(QString::fromUtf8("mButton7"));
        mButton7->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton7, 0, 0, 1, 1);

        mButton8 = new CXTouchButton(frame_2);
        mButton8->setObjectName(QString::fromUtf8("mButton8"));
        mButton8->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton8, 0, 1, 1, 1);

        mButton9 = new CXTouchButton(frame_2);
        mButton9->setObjectName(QString::fromUtf8("mButton9"));
        mButton9->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton9, 0, 2, 1, 1);

        mButton4 = new CXTouchButton(frame_2);
        mButton4->setObjectName(QString::fromUtf8("mButton4"));
        mButton4->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton4, 1, 0, 1, 1);

        mButton5 = new CXTouchButton(frame_2);
        mButton5->setObjectName(QString::fromUtf8("mButton5"));
        mButton5->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton5, 1, 1, 1, 1);

        mButton1 = new CXTouchButton(frame_2);
        mButton1->setObjectName(QString::fromUtf8("mButton1"));
        mButton1->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton1, 2, 0, 1, 1);

        mButton2 = new CXTouchButton(frame_2);
        mButton2->setObjectName(QString::fromUtf8("mButton2"));
        mButton2->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton2, 2, 1, 1, 1);

        mButton3 = new CXTouchButton(frame_2);
        mButton3->setObjectName(QString::fromUtf8("mButton3"));
        mButton3->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton3, 2, 2, 1, 1);

        mButton0 = new CXTouchButton(frame_2);
        mButton0->setObjectName(QString::fromUtf8("mButton0"));
        mButton0->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton0, 3, 1, 1, 1);

        mCancelButton = new CXTouchButton(frame_2);
        mCancelButton->setObjectName(QString::fromUtf8("mCancelButton"));
        mCancelButton->setFocusPolicy(Qt::NoFocus);
        mCancelButton->setDefault(true);

        gridLayout->addWidget(mCancelButton, 6, 1, 1, 2);


        horizontalLayout_2->addWidget(frame_2);


        retranslateUi(CXOperDirectionDialog);

        QMetaObject::connectSlotsByName(CXOperDirectionDialog);
    } // setupUi

    void retranslateUi(QDialog *CXOperDirectionDialog)
    {
        CXOperDirectionDialog->setWindowTitle(QApplication::translate("CXOperDirectionDialog", "\320\237\320\265\321\200\320\265\320\265\321\205\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CXOperDirectionDialog", "X", 0, QApplication::UnicodeUTF8));
        mXEdit->setText(QApplication::translate("CXOperDirectionDialog", "0", 0, QApplication::UnicodeUTF8));
        mAbsoluteButton->setText(QApplication::translate("CXOperDirectionDialog", "\320\220\320\261\321\201\320\276\320\273\321\216\321\202\320\275\320\276\320\265", 0, QApplication::UnicodeUTF8));
        mRelativeButton->setText(QApplication::translate("CXOperDirectionDialog", "\320\236\321\202\320\275\320\276\321\201\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\265", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_3->setText(QApplication::translate("CXOperDirectionDialog", "\320\235\320\276\320\274\320\265\321\200 \320\272\320\260\320\264\321\200\320\260/\320\277\321\200\320\276\320\261\320\270\320\262\320\272\320\270", 0, QApplication::UnicodeUTF8));
        mFrameEdit->setText(QApplication::translate("CXOperDirectionDialog", "0", 0, QApplication::UnicodeUTF8));
        mStepMoveButton->setText(QApplication::translate("CXOperDirectionDialog", "\320\237\320\265\321\200\320\265\320\265\321\205\320\260\321\202\321\214 \320\262 \320\272\320\260\320\264\321\200", 0, QApplication::UnicodeUTF8));
        mBurnMoveButton->setText(QApplication::translate("CXOperDirectionDialog", "\320\237\320\265\321\200\320\265\320\265\321\205\320\260\321\202\321\214 \320\262 \320\277\321\200\320\276\320\261\320\270\320\262\320\272\321\203", 0, QApplication::UnicodeUTF8));
        mStepSetButton->setText(QApplication::translate("CXOperDirectionDialog", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\262 \320\272\320\260\320\264\321\200", 0, QApplication::UnicodeUTF8));
        mBurnSetButton->setText(QApplication::translate("CXOperDirectionDialog", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\262 \320\277\321\200\320\276\320\261\320\270\320\262\320\272\321\203", 0, QApplication::UnicodeUTF8));
        mTechPointMoveButton->setText(QApplication::translate("CXOperDirectionDialog", "\320\222 \321\202\320\276\321\207\320\272\321\203 \320\262\321\213\320\265\320\267\320\264\320\260", 0, QApplication::UnicodeUTF8));
        mSetTechPointButton->setText(QApplication::translate("CXOperDirectionDialog", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203 \320\262\321\213\320\265\320\267\320\264\320\260", 0, QApplication::UnicodeUTF8));
        mAbsZeroMoveButton->setText(QApplication::translate("CXOperDirectionDialog", "\320\222 0 \320\274\320\260\321\210\320\270\320\275\321\213", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CXOperDirectionDialog", "0.1mm", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CXOperDirectionDialog", "0.1mm", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CXOperDirectionDialog", "Y", 0, QApplication::UnicodeUTF8));
        mYEdit->setText(QApplication::translate("CXOperDirectionDialog", "0", 0, QApplication::UnicodeUTF8));
        mButtonMinus->setText(QApplication::translate("CXOperDirectionDialog", "-", 0, QApplication::UnicodeUTF8));
        mButtonMinus->setShortcut(QApplication::translate("CXOperDirectionDialog", "-", 0, QApplication::UnicodeUTF8));
        mButton6->setText(QApplication::translate("CXOperDirectionDialog", "6", 0, QApplication::UnicodeUTF8));
        mButton6->setShortcut(QApplication::translate("CXOperDirectionDialog", "6", 0, QApplication::UnicodeUTF8));
        mButtonDel->setText(QApplication::translate("CXOperDirectionDialog", "Del", 0, QApplication::UnicodeUTF8));
        mButtonDel->setShortcut(QApplication::translate("CXOperDirectionDialog", "Del", 0, QApplication::UnicodeUTF8));
        mButtonEnter->setText(QApplication::translate("CXOperDirectionDialog", "Enter", 0, QApplication::UnicodeUTF8));
        mButtonEnter->setShortcut(QApplication::translate("CXOperDirectionDialog", "Enter, Return", 0, QApplication::UnicodeUTF8));
        mButtonBackspace->setText(QApplication::translate("CXOperDirectionDialog", "\342\206\220", 0, QApplication::UnicodeUTF8));
        mButtonBackspace->setShortcut(QApplication::translate("CXOperDirectionDialog", "Backspace", 0, QApplication::UnicodeUTF8));
        mButtonPlus->setText(QApplication::translate("CXOperDirectionDialog", "+", 0, QApplication::UnicodeUTF8));
        mButtonPlus->setShortcut(QApplication::translate("CXOperDirectionDialog", "+", 0, QApplication::UnicodeUTF8));
        mButton7->setText(QApplication::translate("CXOperDirectionDialog", "7", 0, QApplication::UnicodeUTF8));
        mButton7->setShortcut(QApplication::translate("CXOperDirectionDialog", "7", 0, QApplication::UnicodeUTF8));
        mButton8->setText(QApplication::translate("CXOperDirectionDialog", "8", 0, QApplication::UnicodeUTF8));
        mButton8->setShortcut(QApplication::translate("CXOperDirectionDialog", "8", 0, QApplication::UnicodeUTF8));
        mButton9->setText(QApplication::translate("CXOperDirectionDialog", "9", 0, QApplication::UnicodeUTF8));
        mButton9->setShortcut(QApplication::translate("CXOperDirectionDialog", "9", 0, QApplication::UnicodeUTF8));
        mButton4->setText(QApplication::translate("CXOperDirectionDialog", "4", 0, QApplication::UnicodeUTF8));
        mButton4->setShortcut(QApplication::translate("CXOperDirectionDialog", "4", 0, QApplication::UnicodeUTF8));
        mButton5->setText(QApplication::translate("CXOperDirectionDialog", "5", 0, QApplication::UnicodeUTF8));
        mButton5->setShortcut(QApplication::translate("CXOperDirectionDialog", "5", 0, QApplication::UnicodeUTF8));
        mButton1->setText(QApplication::translate("CXOperDirectionDialog", "1", 0, QApplication::UnicodeUTF8));
        mButton1->setShortcut(QApplication::translate("CXOperDirectionDialog", "1", 0, QApplication::UnicodeUTF8));
        mButton2->setText(QApplication::translate("CXOperDirectionDialog", "2", 0, QApplication::UnicodeUTF8));
        mButton2->setShortcut(QApplication::translate("CXOperDirectionDialog", "2", 0, QApplication::UnicodeUTF8));
        mButton3->setText(QApplication::translate("CXOperDirectionDialog", "3", 0, QApplication::UnicodeUTF8));
        mButton3->setShortcut(QApplication::translate("CXOperDirectionDialog", "3", 0, QApplication::UnicodeUTF8));
        mButton0->setText(QApplication::translate("CXOperDirectionDialog", "0", 0, QApplication::UnicodeUTF8));
        mButton0->setShortcut(QApplication::translate("CXOperDirectionDialog", "0", 0, QApplication::UnicodeUTF8));
        mCancelButton->setText(QApplication::translate("CXOperDirectionDialog", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXOperDirectionDialog: public Ui_CXOperDirectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXOPERDIRECTIONDIALOG_H
