/********************************************************************************
** Form generated from reading UI file 'CXParam.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXPARAM_H
#define UI_CXPARAM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "CXTouchButton.h"

QT_BEGIN_NAMESPACE

class Ui_CXParamUiClass
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *mKeysBox;
    QHBoxLayout *mKeysLayout;
    QStackedWidget *mStackWidget;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *mValuesScroll;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *frame_2;
    QGridLayout *gridLayout;
    CXTouchButton *mButton6;
    CXTouchButton *mButtonDot;
    CXTouchButton *mButton7;
    CXTouchButton *mButton8;
    CXTouchButton *mButton9;
    CXTouchButton *mButton4;
    CXTouchButton *mButton5;
    CXTouchButton *mButton1;
    CXTouchButton *mButton2;
    CXTouchButton *mButton3;
    CXTouchButton *mButton0;
    QSpacerItem *verticalSpacer_3;
    CXTouchButton *mButtonBackspace;
    CXTouchButton *mButtonDel;
    QGroupBox *groupBox;
    QHBoxLayout *mImagesLayout;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *mErrorLabel;
    QHBoxLayout *horizontalLayout;
    CXTouchButton *mLaunchGC;
    CXTouchButton *mRestoreButton;
    QSpacerItem *horizontalSpacer;
    CXTouchButton *mAcceptButton;
    CXTouchButton *mCloseButton;

    void setupUi(QWidget *CXParamUiClass)
    {
        if (CXParamUiClass->objectName().isEmpty())
            CXParamUiClass->setObjectName(QString::fromUtf8("CXParamUiClass"));
        CXParamUiClass->resize(600, 400);
        verticalLayout = new QVBoxLayout(CXParamUiClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(CXParamUiClass);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout->addWidget(label);

        mKeysBox = new QGroupBox(CXParamUiClass);
        mKeysBox->setObjectName(QString::fromUtf8("mKeysBox"));
        mKeysLayout = new QHBoxLayout(mKeysBox);
        mKeysLayout->setSpacing(6);
        mKeysLayout->setContentsMargins(1, 1, 1, 1);
        mKeysLayout->setObjectName(QString::fromUtf8("mKeysLayout"));

        verticalLayout->addWidget(mKeysBox);

        mStackWidget = new QStackedWidget(CXParamUiClass);
        mStackWidget->setObjectName(QString::fromUtf8("mStackWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(1, 1, 1, 1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_2 = new QGroupBox(page);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(1, 1, 1, 1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        mValuesScroll = new QScrollArea(groupBox_2);
        mValuesScroll->setObjectName(QString::fromUtf8("mValuesScroll"));
        mValuesScroll->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 293, 236));
        mValuesScroll->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(mValuesScroll);


        verticalLayout_2->addWidget(groupBox_2);


        gridLayout_2->addLayout(verticalLayout_2, 1, 0, 1, 1);

        frame_2 = new QGroupBox(page);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(332, 16777215));
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mButton6 = new CXTouchButton(frame_2);
        mButton6->setObjectName(QString::fromUtf8("mButton6"));
        mButton6->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButton6, 1, 2, 1, 1);

        mButtonDot = new CXTouchButton(frame_2);
        mButtonDot->setObjectName(QString::fromUtf8("mButtonDot"));
        mButtonDot->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonDot, 4, 1, 1, 1);

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

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 5, 0, 1, 3);

        mButtonBackspace = new CXTouchButton(frame_2);
        mButtonBackspace->setObjectName(QString::fromUtf8("mButtonBackspace"));
        mButtonBackspace->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonBackspace, 3, 0, 1, 1);

        mButtonDel = new CXTouchButton(frame_2);
        mButtonDel->setObjectName(QString::fromUtf8("mButtonDel"));
        mButtonDel->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(mButtonDel, 3, 2, 1, 1);


        gridLayout_2->addWidget(frame_2, 1, 1, 1, 1);

        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        mImagesLayout = new QHBoxLayout(groupBox);
        mImagesLayout->setSpacing(6);
        mImagesLayout->setContentsMargins(4, 4, 4, 4);
        mImagesLayout->setObjectName(QString::fromUtf8("mImagesLayout"));

        gridLayout_2->addWidget(groupBox, 0, 0, 1, 2);

        mStackWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        mErrorLabel = new QLabel(page_2);
        mErrorLabel->setObjectName(QString::fromUtf8("mErrorLabel"));
        QFont font1;
        font1.setPointSize(14);
        mErrorLabel->setFont(font1);
        mErrorLabel->setStyleSheet(QString::fromUtf8("color: red"));
        mErrorLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(mErrorLabel);

        mStackWidget->addWidget(page_2);

        verticalLayout->addWidget(mStackWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mLaunchGC = new CXTouchButton(CXParamUiClass);
        mLaunchGC->setObjectName(QString::fromUtf8("mLaunchGC"));

        horizontalLayout->addWidget(mLaunchGC);

        mRestoreButton = new CXTouchButton(CXParamUiClass);
        mRestoreButton->setObjectName(QString::fromUtf8("mRestoreButton"));
        mRestoreButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(mRestoreButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        mAcceptButton = new CXTouchButton(CXParamUiClass);
        mAcceptButton->setObjectName(QString::fromUtf8("mAcceptButton"));
        mAcceptButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(mAcceptButton);

        mCloseButton = new CXTouchButton(CXParamUiClass);
        mCloseButton->setObjectName(QString::fromUtf8("mCloseButton"));
        mCloseButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(mCloseButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CXParamUiClass);
        QObject::connect(mCloseButton, SIGNAL(clicked()), CXParamUiClass, SLOT(close()));

        mStackWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CXParamUiClass);
    } // setupUi

    void retranslateUi(QWidget *CXParamUiClass)
    {
        CXParamUiClass->setWindowTitle(QApplication::translate("CXParamUiClass", "CXParamUi", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CXParamUiClass", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", 0, QApplication::UnicodeUTF8));
        mKeysBox->setTitle(QString());
        groupBox_2->setTitle(QApplication::translate("CXParamUiClass", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\270", 0, QApplication::UnicodeUTF8));
        mButton6->setText(QApplication::translate("CXParamUiClass", "6", 0, QApplication::UnicodeUTF8));
        mButton6->setShortcut(QApplication::translate("CXParamUiClass", "6", 0, QApplication::UnicodeUTF8));
        mButtonDot->setText(QApplication::translate("CXParamUiClass", ".", 0, QApplication::UnicodeUTF8));
        mButtonDot->setShortcut(QApplication::translate("CXParamUiClass", ".", 0, QApplication::UnicodeUTF8));
        mButton7->setText(QApplication::translate("CXParamUiClass", "7", 0, QApplication::UnicodeUTF8));
        mButton7->setShortcut(QApplication::translate("CXParamUiClass", "7", 0, QApplication::UnicodeUTF8));
        mButton8->setText(QApplication::translate("CXParamUiClass", "8", 0, QApplication::UnicodeUTF8));
        mButton8->setShortcut(QApplication::translate("CXParamUiClass", "8", 0, QApplication::UnicodeUTF8));
        mButton9->setText(QApplication::translate("CXParamUiClass", "9", 0, QApplication::UnicodeUTF8));
        mButton9->setShortcut(QApplication::translate("CXParamUiClass", "9", 0, QApplication::UnicodeUTF8));
        mButton4->setText(QApplication::translate("CXParamUiClass", "4", 0, QApplication::UnicodeUTF8));
        mButton4->setShortcut(QApplication::translate("CXParamUiClass", "4", 0, QApplication::UnicodeUTF8));
        mButton5->setText(QApplication::translate("CXParamUiClass", "5", 0, QApplication::UnicodeUTF8));
        mButton5->setShortcut(QApplication::translate("CXParamUiClass", "5", 0, QApplication::UnicodeUTF8));
        mButton1->setText(QApplication::translate("CXParamUiClass", "1", 0, QApplication::UnicodeUTF8));
        mButton1->setShortcut(QApplication::translate("CXParamUiClass", "1", 0, QApplication::UnicodeUTF8));
        mButton2->setText(QApplication::translate("CXParamUiClass", "2", 0, QApplication::UnicodeUTF8));
        mButton2->setShortcut(QApplication::translate("CXParamUiClass", "2", 0, QApplication::UnicodeUTF8));
        mButton3->setText(QApplication::translate("CXParamUiClass", "3", 0, QApplication::UnicodeUTF8));
        mButton3->setShortcut(QApplication::translate("CXParamUiClass", "3", 0, QApplication::UnicodeUTF8));
        mButton0->setText(QApplication::translate("CXParamUiClass", "0", 0, QApplication::UnicodeUTF8));
        mButton0->setShortcut(QApplication::translate("CXParamUiClass", "0", 0, QApplication::UnicodeUTF8));
        mButtonBackspace->setText(QApplication::translate("CXParamUiClass", "\342\206\220", 0, QApplication::UnicodeUTF8));
        mButtonBackspace->setShortcut(QApplication::translate("CXParamUiClass", "Backspace", 0, QApplication::UnicodeUTF8));
        mButtonDel->setText(QApplication::translate("CXParamUiClass", "Del", 0, QApplication::UnicodeUTF8));
        mButtonDel->setShortcut(QApplication::translate("CXParamUiClass", "Del", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CXParamUiClass", "\320\241\320\261\320\276\321\200\320\272\320\260 \321\200\320\265\320\267\320\260\320\272\320\260", 0, QApplication::UnicodeUTF8));
        mErrorLabel->setText(QString());
        mLaunchGC->setText(QApplication::translate("CXParamUiClass", "\320\223\320\260\320\267\320\232\320\276\320\275\321\201\320\276\320\273\321\214", 0, QApplication::UnicodeUTF8));
        mRestoreButton->setText(QApplication::translate("CXParamUiClass", "\320\222\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mAcceptButton->setText(QApplication::translate("CXParamUiClass", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mCloseButton->setText(QApplication::translate("CXParamUiClass", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXParamUiClass: public Ui_CXParamUiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXPARAM_H
