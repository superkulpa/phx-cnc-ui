/********************************************************************************
** Form generated from reading UI file 'CXTurnDialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXTURNDIALOG_H
#define UI_CXTURNDIALOG_H

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

class Ui_CXTurnDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *mTurnSettings;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    CXTouchButton *mWriteRotationButton;
    CXTouchButton *mCalculateRotationButton;
    QLineEdit *mRotateEdit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    CXTouchButton *mFlipYButton;
    CXTouchButton *mFlipXButton;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLineEdit *mScaleEdit;
    QLabel *label_2;
    CXTouchButton *mWriteScaleButton;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    CXTouchButton *mButton7;
    CXTouchButton *mButton8;
    CXTouchButton *mButton9;
    CXTouchButton *mButton4;
    CXTouchButton *mButton5;
    CXTouchButton *mButton6;
    CXTouchButton *mButton1;
    CXTouchButton *mButton2;
    CXTouchButton *mButton3;
    CXTouchButton *mButtonPlus;
    CXTouchButton *mButton0;
    CXTouchButton *mButtonMinus;
    CXTouchButton *mButtonBackspace;
    CXTouchButton *mButtonEnter;
    CXTouchButton *mButtonDel;
    QSpacerItem *verticalSpacer;
    CXTouchButton *mCloseButton;

    void setupUi(QWidget *CXTurnDialog)
    {
        if (CXTurnDialog->objectName().isEmpty())
            CXTurnDialog->setObjectName(QString::fromUtf8("CXTurnDialog"));
        CXTurnDialog->resize(578, 352);
        horizontalLayout = new QHBoxLayout(CXTurnDialog);
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mTurnSettings = new QFrame(CXTurnDialog);
        mTurnSettings->setObjectName(QString::fromUtf8("mTurnSettings"));
        mTurnSettings->setFrameShape(QFrame::StyledPanel);
        mTurnSettings->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(mTurnSettings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(mTurnSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        mWriteRotationButton = new CXTouchButton(groupBox);
        mWriteRotationButton->setObjectName(QString::fromUtf8("mWriteRotationButton"));
        mWriteRotationButton->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mWriteRotationButton, 0, 1, 1, 1);

        mCalculateRotationButton = new CXTouchButton(groupBox);
        mCalculateRotationButton->setObjectName(QString::fromUtf8("mCalculateRotationButton"));
        mCalculateRotationButton->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(mCalculateRotationButton, 1, 1, 1, 1);

        mRotateEdit = new QLineEdit(groupBox);
        mRotateEdit->setObjectName(QString::fromUtf8("mRotateEdit"));

        gridLayout_2->addWidget(mRotateEdit, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(mTurnSettings);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        mFlipYButton = new CXTouchButton(groupBox_2);
        mFlipYButton->setObjectName(QString::fromUtf8("mFlipYButton"));
        mFlipYButton->setFocusPolicy(Qt::NoFocus);

        gridLayout_3->addWidget(mFlipYButton, 1, 1, 1, 1);

        mFlipXButton = new CXTouchButton(groupBox_2);
        mFlipXButton->setObjectName(QString::fromUtf8("mFlipXButton"));
        mFlipXButton->setFocusPolicy(Qt::NoFocus);

        gridLayout_3->addWidget(mFlipXButton, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(mTurnSettings);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        mScaleEdit = new QLineEdit(groupBox_3);
        mScaleEdit->setObjectName(QString::fromUtf8("mScaleEdit"));

        gridLayout_4->addWidget(mScaleEdit, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        mWriteScaleButton = new CXTouchButton(groupBox_3);
        mWriteScaleButton->setObjectName(QString::fromUtf8("mWriteScaleButton"));
        mWriteScaleButton->setFocusPolicy(Qt::NoFocus);

        gridLayout_4->addWidget(mWriteScaleButton, 0, 1, 2, 1);


        verticalLayout->addWidget(groupBox_3);


        horizontalLayout->addWidget(mTurnSettings);

        frame_2 = new QFrame(CXTurnDialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(332, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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

        mButton6 = new CXTouchButton(frame_2);
        mButton6->setObjectName(QString::fromUtf8("mButton6"));
        mButton6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton6, 1, 2, 1, 1);

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

        mButtonPlus = new CXTouchButton(frame_2);
        mButtonPlus->setObjectName(QString::fromUtf8("mButtonPlus"));
        mButtonPlus->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonPlus, 3, 0, 1, 1);

        mButton0 = new CXTouchButton(frame_2);
        mButton0->setObjectName(QString::fromUtf8("mButton0"));
        mButton0->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton0, 3, 1, 1, 1);

        mButtonMinus = new CXTouchButton(frame_2);
        mButtonMinus->setObjectName(QString::fromUtf8("mButtonMinus"));
        mButtonMinus->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonMinus, 3, 2, 1, 1);

        mButtonBackspace = new CXTouchButton(frame_2);
        mButtonBackspace->setObjectName(QString::fromUtf8("mButtonBackspace"));
        mButtonBackspace->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonBackspace, 4, 0, 1, 1);

        mButtonEnter = new CXTouchButton(frame_2);
        mButtonEnter->setObjectName(QString::fromUtf8("mButtonEnter"));
        mButtonEnter->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonEnter, 4, 1, 1, 1);

        mButtonDel = new CXTouchButton(frame_2);
        mButtonDel->setObjectName(QString::fromUtf8("mButtonDel"));
        mButtonDel->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonDel, 4, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);

        mCloseButton = new CXTouchButton(frame_2);
        mCloseButton->setObjectName(QString::fromUtf8("mCloseButton"));
        mCloseButton->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mCloseButton, 6, 1, 1, 2);


        horizontalLayout->addWidget(frame_2);


        retranslateUi(CXTurnDialog);

        QMetaObject::connectSlotsByName(CXTurnDialog);
    } // setupUi

    void retranslateUi(QWidget *CXTurnDialog)
    {
        CXTurnDialog->setWindowTitle(QApplication::translate("CXTurnDialog", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214/\320\237\320\265\321\200\320\265\320\262\320\265\321\200\320\275\321\203\321\202\321\214/\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CXTurnDialog", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214 \320\243\320\237", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CXTurnDialog", "<html><head/><body><p>\320\243\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260<br/>(0.1 \320\263\321\200\320\260\320\264\321\203\321\201\320\260)</p></body></html>", 0, QApplication::UnicodeUTF8));
        mWriteRotationButton->setText(QApplication::translate("CXTurnDialog", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mCalculateRotationButton->setText(QApplication::translate("CXTurnDialog", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mRotateEdit->setText(QApplication::translate("CXTurnDialog", "0", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CXTurnDialog", "\320\237\320\265\321\200\320\265\320\262\320\265\321\200\320\275\321\203\321\202\321\214 \320\243\320\237", 0, QApplication::UnicodeUTF8));
        mFlipYButton->setText(QApplication::translate("CXTurnDialog", "\320\227\320\265\321\200\320\272\320\260\320\273\321\214\320\275\320\276 \320\277\320\276 Y", 0, QApplication::UnicodeUTF8));
        mFlipXButton->setText(QApplication::translate("CXTurnDialog", "\320\227\320\265\321\200\320\272\320\260\320\273\321\214\320\275\320\276 \320\277\320\276 X", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("CXTurnDialog", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mScaleEdit->setText(QApplication::translate("CXTurnDialog", "100", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CXTurnDialog", "<html><head/><body><p>\320\234\320\260\321\201\321\210\321\202\320\260\320\261<br/>(% \320\276\321\202 \320\276\321\200\320\270\320\263\320\270\320\275\320\260\320\273\320\260)</p></body></html>", 0, QApplication::UnicodeUTF8));
        mWriteScaleButton->setText(QApplication::translate("CXTurnDialog", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mButton7->setText(QApplication::translate("CXTurnDialog", "7", 0, QApplication::UnicodeUTF8));
        mButton7->setShortcut(QApplication::translate("CXTurnDialog", "7", 0, QApplication::UnicodeUTF8));
        mButton8->setText(QApplication::translate("CXTurnDialog", "8", 0, QApplication::UnicodeUTF8));
        mButton8->setShortcut(QApplication::translate("CXTurnDialog", "8", 0, QApplication::UnicodeUTF8));
        mButton9->setText(QApplication::translate("CXTurnDialog", "9", 0, QApplication::UnicodeUTF8));
        mButton9->setShortcut(QApplication::translate("CXTurnDialog", "9", 0, QApplication::UnicodeUTF8));
        mButton4->setText(QApplication::translate("CXTurnDialog", "4", 0, QApplication::UnicodeUTF8));
        mButton4->setShortcut(QApplication::translate("CXTurnDialog", "4", 0, QApplication::UnicodeUTF8));
        mButton5->setText(QApplication::translate("CXTurnDialog", "5", 0, QApplication::UnicodeUTF8));
        mButton5->setShortcut(QApplication::translate("CXTurnDialog", "5", 0, QApplication::UnicodeUTF8));
        mButton6->setText(QApplication::translate("CXTurnDialog", "6", 0, QApplication::UnicodeUTF8));
        mButton6->setShortcut(QApplication::translate("CXTurnDialog", "6", 0, QApplication::UnicodeUTF8));
        mButton1->setText(QApplication::translate("CXTurnDialog", "1", 0, QApplication::UnicodeUTF8));
        mButton1->setShortcut(QApplication::translate("CXTurnDialog", "1", 0, QApplication::UnicodeUTF8));
        mButton2->setText(QApplication::translate("CXTurnDialog", "2", 0, QApplication::UnicodeUTF8));
        mButton2->setShortcut(QApplication::translate("CXTurnDialog", "2", 0, QApplication::UnicodeUTF8));
        mButton3->setText(QApplication::translate("CXTurnDialog", "3", 0, QApplication::UnicodeUTF8));
        mButton3->setShortcut(QApplication::translate("CXTurnDialog", "3", 0, QApplication::UnicodeUTF8));
        mButtonPlus->setText(QApplication::translate("CXTurnDialog", "+", 0, QApplication::UnicodeUTF8));
        mButtonPlus->setShortcut(QApplication::translate("CXTurnDialog", "+", 0, QApplication::UnicodeUTF8));
        mButton0->setText(QApplication::translate("CXTurnDialog", "0", 0, QApplication::UnicodeUTF8));
        mButton0->setShortcut(QApplication::translate("CXTurnDialog", "0", 0, QApplication::UnicodeUTF8));
        mButtonMinus->setText(QApplication::translate("CXTurnDialog", "-", 0, QApplication::UnicodeUTF8));
        mButtonMinus->setShortcut(QApplication::translate("CXTurnDialog", "-", 0, QApplication::UnicodeUTF8));
        mButtonBackspace->setText(QApplication::translate("CXTurnDialog", "\342\206\220", 0, QApplication::UnicodeUTF8));
        mButtonBackspace->setShortcut(QApplication::translate("CXTurnDialog", "Backspace", 0, QApplication::UnicodeUTF8));
        mButtonEnter->setText(QApplication::translate("CXTurnDialog", "Enter", 0, QApplication::UnicodeUTF8));
        mButtonEnter->setShortcut(QApplication::translate("CXTurnDialog", "Enter, Return", 0, QApplication::UnicodeUTF8));
        mButtonDel->setText(QApplication::translate("CXTurnDialog", "Del", 0, QApplication::UnicodeUTF8));
        mButtonDel->setShortcut(QApplication::translate("CXTurnDialog", "Del", 0, QApplication::UnicodeUTF8));
        mCloseButton->setText(QApplication::translate("CXTurnDialog", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXTurnDialog: public Ui_CXTurnDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXTURNDIALOG_H
