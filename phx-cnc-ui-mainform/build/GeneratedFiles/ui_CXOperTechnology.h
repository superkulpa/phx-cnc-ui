/********************************************************************************
** Form generated from reading UI file 'CXOperTechnology.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXOPERTECHNOLOGY_H
#define UI_CXOPERTECHNOLOGY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "CXTouchButton.h"

QT_BEGIN_NAMESPACE

class Ui_CXOperTechnology
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    CXTouchButton *mBurnButton;
    CXTouchButton *mRBurnButton;
    CXTouchButton *mStopButton;
    CXTouchButton *mTechnology;
    QWidget *mButtonWidget;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frSuppList;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    CXTouchButton *mCutModeButton;
    CXTouchButton *mMarkerButton;
    CXTouchButton *mSVRButton;

    void setupUi(QWidget *CXOperTechnology)
    {
        if (CXOperTechnology->objectName().isEmpty())
            CXOperTechnology->setObjectName(QString::fromUtf8("CXOperTechnology"));
        CXOperTechnology->resize(335, 679);
        CXOperTechnology->setFocusPolicy(Qt::StrongFocus);
        verticalLayout = new QVBoxLayout(CXOperTechnology);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_2 = new QGroupBox(CXOperTechnology);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        mBurnButton = new CXTouchButton(groupBox_2);
        mBurnButton->setObjectName(QString::fromUtf8("mBurnButton"));

        horizontalLayout_3->addWidget(mBurnButton);

        mRBurnButton = new CXTouchButton(groupBox_2);
        mRBurnButton->setObjectName(QString::fromUtf8("mRBurnButton"));

        horizontalLayout_3->addWidget(mRBurnButton);

        mStopButton = new CXTouchButton(groupBox_2);
        mStopButton->setObjectName(QString::fromUtf8("mStopButton"));

        horizontalLayout_3->addWidget(mStopButton);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(groupBox_2);

        mTechnology = new CXTouchButton(CXOperTechnology);
        mTechnology->setObjectName(QString::fromUtf8("mTechnology"));

        verticalLayout->addWidget(mTechnology);

        mButtonWidget = new QWidget(CXOperTechnology);
        mButtonWidget->setObjectName(QString::fromUtf8("mButtonWidget"));
        horizontalLayout_4 = new QHBoxLayout(mButtonWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        frSuppList = new QFrame(mButtonWidget);
        frSuppList->setObjectName(QString::fromUtf8("frSuppList"));
        frSuppList->setLineWidth(0);
        verticalLayout_2 = new QVBoxLayout(frSuppList);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 5, 0, 5);

        horizontalLayout_4->addWidget(frSuppList);


        verticalLayout->addWidget(mButtonWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        mCutModeButton = new CXTouchButton(CXOperTechnology);
        mCutModeButton->setObjectName(QString::fromUtf8("mCutModeButton"));

        horizontalLayout->addWidget(mCutModeButton);

        mMarkerButton = new CXTouchButton(CXOperTechnology);
        mMarkerButton->setObjectName(QString::fromUtf8("mMarkerButton"));

        horizontalLayout->addWidget(mMarkerButton);

        mSVRButton = new CXTouchButton(CXOperTechnology);
        mSVRButton->setObjectName(QString::fromUtf8("mSVRButton"));

        horizontalLayout->addWidget(mSVRButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CXOperTechnology);

        QMetaObject::connectSlotsByName(CXOperTechnology);
    } // setupUi

    void retranslateUi(QWidget *CXOperTechnology)
    {
        CXOperTechnology->setWindowTitle(QString());
        groupBox_2->setTitle(QString());
        mBurnButton->setText(QApplication::translate("CXOperTechnology", "\320\237\321\200\320\276\320\261\320\270\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        mRBurnButton->setText(QApplication::translate("CXOperTechnology", "\320\237\320\276\320\264\320\266\320\270\320\263", 0, QApplication::UnicodeUTF8));
        mStopButton->setText(QApplication::translate("CXOperTechnology", "\320\241\321\202\320\276\320\277 \321\200\320\265\320\267\320\260", 0, QApplication::UnicodeUTF8));
        mTechnology->setText(QApplication::translate("CXOperTechnology", "\320\242\320\265\321\205\320\275\320\276\320\273\320\276\320\263\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        mCutModeButton->setText(QApplication::translate("CXOperTechnology", "\320\247\320\265\321\200\321\207\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        mMarkerButton->setText(QString());
        mSVRButton->setText(QApplication::translate("CXOperTechnology", "\320\241\320\222\320\240", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXOperTechnology: public Ui_CXOperTechnology {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXOPERTECHNOLOGY_H
