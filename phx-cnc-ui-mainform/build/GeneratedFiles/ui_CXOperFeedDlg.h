/********************************************************************************
** Form generated from reading UI file 'CXOperFeedDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXOPERFEEDDLG_H
#define UI_CXOPERFEEDDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include "CXTouchButton.h"

QT_BEGIN_NAMESPACE

class Ui_CXOperFeedDlg
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *mFRegularEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *mFFastEdit;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *mFSlowEdit;
    QLabel *label_6;
    CXTouchButton *apply;
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

    void setupUi(QDialog *CXOperFeedDlg)
    {
        if (CXOperFeedDlg->objectName().isEmpty())
            CXOperFeedDlg->setObjectName(QString::fromUtf8("CXOperFeedDlg"));
        CXOperFeedDlg->resize(800, 240);
        horizontalLayout_2 = new QHBoxLayout(CXOperFeedDlg);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(CXOperFeedDlg);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        mFRegularEdit = new QLineEdit(CXOperFeedDlg);
        mFRegularEdit->setObjectName(QString::fromUtf8("mFRegularEdit"));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        mFRegularEdit->setFont(font);

        gridLayout_2->addWidget(mFRegularEdit, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout_2->addLayout(horizontalLayout, 3, 0, 1, 7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 7, 0, 1, 7);

        label_4 = new QLabel(CXOperFeedDlg);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 2, 1, 1);

        label_2 = new QLabel(CXOperFeedDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        mFFastEdit = new QLineEdit(CXOperFeedDlg);
        mFFastEdit->setObjectName(QString::fromUtf8("mFFastEdit"));
        mFFastEdit->setFont(font);

        gridLayout_2->addWidget(mFFastEdit, 1, 1, 1, 1);

        label_5 = new QLabel(CXOperFeedDlg);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 2, 1, 1);

        label_3 = new QLabel(CXOperFeedDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        mFSlowEdit = new QLineEdit(CXOperFeedDlg);
        mFSlowEdit->setObjectName(QString::fromUtf8("mFSlowEdit"));
        mFSlowEdit->setFont(font);

        gridLayout_2->addWidget(mFSlowEdit, 2, 1, 1, 1);

        label_6 = new QLabel(CXOperFeedDlg);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 2, 2, 1, 1);

        apply = new CXTouchButton(CXOperFeedDlg);
        apply->setObjectName(QString::fromUtf8("apply"));

        gridLayout_2->addWidget(apply, 4, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);

        frame_2 = new QFrame(CXOperFeedDlg);
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


        retranslateUi(CXOperFeedDlg);

        QMetaObject::connectSlotsByName(CXOperFeedDlg);
    } // setupUi

    void retranslateUi(QDialog *CXOperFeedDlg)
    {
        CXOperFeedDlg->setWindowTitle(QApplication::translate("CXOperFeedDlg", "\320\227\320\260\320\264\320\260\321\202\321\214 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\277\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\271", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CXOperFeedDlg", "\320\240\320\260\320\261\320\276\321\207\320\260\321\217", 0, QApplication::UnicodeUTF8));
        mFRegularEdit->setText(QApplication::translate("CXOperFeedDlg", "0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CXOperFeedDlg", "mm/min", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CXOperFeedDlg", "\320\243\321\201\320\272\320\276\321\200\320\265\320\275\320\275\320\276", 0, QApplication::UnicodeUTF8));
        mFFastEdit->setText(QApplication::translate("CXOperFeedDlg", "0", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CXOperFeedDlg", "mm/min", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CXOperFeedDlg", "\320\227\320\260\320\274\320\265\320\264\320\273\320\265\320\275\320\275\320\276", 0, QApplication::UnicodeUTF8));
        mFSlowEdit->setText(QApplication::translate("CXOperFeedDlg", "0", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CXOperFeedDlg", "mm/min", 0, QApplication::UnicodeUTF8));
        apply->setText(QApplication::translate("CXOperFeedDlg", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mButtonMinus->setText(QApplication::translate("CXOperFeedDlg", "-", 0, QApplication::UnicodeUTF8));
        mButtonMinus->setShortcut(QApplication::translate("CXOperFeedDlg", "-", 0, QApplication::UnicodeUTF8));
        mButton6->setText(QApplication::translate("CXOperFeedDlg", "6", 0, QApplication::UnicodeUTF8));
        mButton6->setShortcut(QApplication::translate("CXOperFeedDlg", "6", 0, QApplication::UnicodeUTF8));
        mButtonDel->setText(QApplication::translate("CXOperFeedDlg", "Del", 0, QApplication::UnicodeUTF8));
        mButtonDel->setShortcut(QApplication::translate("CXOperFeedDlg", "Del", 0, QApplication::UnicodeUTF8));
        mButtonEnter->setText(QApplication::translate("CXOperFeedDlg", "Enter", 0, QApplication::UnicodeUTF8));
        mButtonEnter->setShortcut(QApplication::translate("CXOperFeedDlg", "Enter, Return", 0, QApplication::UnicodeUTF8));
        mButtonBackspace->setText(QApplication::translate("CXOperFeedDlg", "\342\206\220", 0, QApplication::UnicodeUTF8));
        mButtonBackspace->setShortcut(QApplication::translate("CXOperFeedDlg", "Backspace", 0, QApplication::UnicodeUTF8));
        mButtonPlus->setText(QApplication::translate("CXOperFeedDlg", "+", 0, QApplication::UnicodeUTF8));
        mButtonPlus->setShortcut(QApplication::translate("CXOperFeedDlg", "+", 0, QApplication::UnicodeUTF8));
        mButton7->setText(QApplication::translate("CXOperFeedDlg", "7", 0, QApplication::UnicodeUTF8));
        mButton7->setShortcut(QApplication::translate("CXOperFeedDlg", "7", 0, QApplication::UnicodeUTF8));
        mButton8->setText(QApplication::translate("CXOperFeedDlg", "8", 0, QApplication::UnicodeUTF8));
        mButton8->setShortcut(QApplication::translate("CXOperFeedDlg", "8", 0, QApplication::UnicodeUTF8));
        mButton9->setText(QApplication::translate("CXOperFeedDlg", "9", 0, QApplication::UnicodeUTF8));
        mButton9->setShortcut(QApplication::translate("CXOperFeedDlg", "9", 0, QApplication::UnicodeUTF8));
        mButton4->setText(QApplication::translate("CXOperFeedDlg", "4", 0, QApplication::UnicodeUTF8));
        mButton4->setShortcut(QApplication::translate("CXOperFeedDlg", "4", 0, QApplication::UnicodeUTF8));
        mButton5->setText(QApplication::translate("CXOperFeedDlg", "5", 0, QApplication::UnicodeUTF8));
        mButton5->setShortcut(QApplication::translate("CXOperFeedDlg", "5", 0, QApplication::UnicodeUTF8));
        mButton1->setText(QApplication::translate("CXOperFeedDlg", "1", 0, QApplication::UnicodeUTF8));
        mButton1->setShortcut(QApplication::translate("CXOperFeedDlg", "1", 0, QApplication::UnicodeUTF8));
        mButton2->setText(QApplication::translate("CXOperFeedDlg", "2", 0, QApplication::UnicodeUTF8));
        mButton2->setShortcut(QApplication::translate("CXOperFeedDlg", "2", 0, QApplication::UnicodeUTF8));
        mButton3->setText(QApplication::translate("CXOperFeedDlg", "3", 0, QApplication::UnicodeUTF8));
        mButton3->setShortcut(QApplication::translate("CXOperFeedDlg", "3", 0, QApplication::UnicodeUTF8));
        mButton0->setText(QApplication::translate("CXOperFeedDlg", "0", 0, QApplication::UnicodeUTF8));
        mButton0->setShortcut(QApplication::translate("CXOperFeedDlg", "0", 0, QApplication::UnicodeUTF8));
        mCancelButton->setText(QApplication::translate("CXOperFeedDlg", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXOperFeedDlg: public Ui_CXOperFeedDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXOPERFEEDDLG_H
