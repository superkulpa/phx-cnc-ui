/********************************************************************************
** Form generated from reading UI file 'CXProcessingParametersWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXPROCESSINGPARAMETERSWINDOW_H
#define UI_CXPROCESSINGPARAMETERSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "CXTouchButton.h"

QT_BEGIN_NAMESPACE

class Ui_CXProcessingParametersWindow
{
public:
    QVBoxLayout *mCentralLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    CXTouchButton *mLoadBaseButton;
    CXTouchButton *mLoadButton;
    CXTouchButton *mCancelButton;

    void setupUi(QDialog *CXProcessingParametersWindow)
    {
        if (CXProcessingParametersWindow->objectName().isEmpty())
            CXProcessingParametersWindow->setObjectName(QString::fromUtf8("CXProcessingParametersWindow"));
        CXProcessingParametersWindow->resize(904, 709);
        mCentralLayout = new QVBoxLayout(CXProcessingParametersWindow);
        mCentralLayout->setObjectName(QString::fromUtf8("mCentralLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        mLoadBaseButton = new CXTouchButton(CXProcessingParametersWindow);
        mLoadBaseButton->setObjectName(QString::fromUtf8("mLoadBaseButton"));

        horizontalLayout->addWidget(mLoadBaseButton);

        mLoadButton = new CXTouchButton(CXProcessingParametersWindow);
        mLoadButton->setObjectName(QString::fromUtf8("mLoadButton"));
        mLoadButton->setDefault(true);

        horizontalLayout->addWidget(mLoadButton);

        mCancelButton = new CXTouchButton(CXProcessingParametersWindow);
        mCancelButton->setObjectName(QString::fromUtf8("mCancelButton"));

        horizontalLayout->addWidget(mCancelButton);


        mCentralLayout->addLayout(horizontalLayout);


        retranslateUi(CXProcessingParametersWindow);

        QMetaObject::connectSlotsByName(CXProcessingParametersWindow);
    } // setupUi

    void retranslateUi(QDialog *CXProcessingParametersWindow)
    {
        CXProcessingParametersWindow->setWindowTitle(QApplication::translate("CXProcessingParametersWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\275\320\260 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\321\203", 0, QApplication::UnicodeUTF8));
        mLoadBaseButton->setText(QApplication::translate("CXProcessingParametersWindow", "\320\222\320\267\321\217\321\202\321\214 \320\270\320\267 \320\261\320\260\320\267\321\213", 0, QApplication::UnicodeUTF8));
        mLoadButton->setText(QApplication::translate("CXProcessingParametersWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mCancelButton->setText(QApplication::translate("CXProcessingParametersWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXProcessingParametersWindow: public Ui_CXProcessingParametersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXPROCESSINGPARAMETERSWINDOW_H
