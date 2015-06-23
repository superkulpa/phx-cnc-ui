/********************************************************************************
** Form generated from reading UI file 'CXIniFileList.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXINIFILELIST_H
#define UI_CXINIFILELIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "CXTouchButton.h"

QT_BEGIN_NAMESPACE

class Ui_CXIniFileList
{
public:
    QVBoxLayout *verticalLayout;
    QListView *mIniFileView;
    QHBoxLayout *horizontalLayout;
    CXTouchButton *btnUp;
    CXTouchButton *btnLoad;
    CXTouchButton *btnDown;

    void setupUi(QWidget *CXIniFileList)
    {
        if (CXIniFileList->objectName().isEmpty())
            CXIniFileList->setObjectName(QString::fromUtf8("CXIniFileList"));
        CXIniFileList->resize(378, 486);
        verticalLayout = new QVBoxLayout(CXIniFileList);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mIniFileView = new QListView(CXIniFileList);
        mIniFileView->setObjectName(QString::fromUtf8("mIniFileView"));

        verticalLayout->addWidget(mIniFileView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnUp = new CXTouchButton(CXIniFileList);
        btnUp->setObjectName(QString::fromUtf8("btnUp"));

        horizontalLayout->addWidget(btnUp);

        btnLoad = new CXTouchButton(CXIniFileList);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));

        horizontalLayout->addWidget(btnLoad);

        btnDown = new CXTouchButton(CXIniFileList);
        btnDown->setObjectName(QString::fromUtf8("btnDown"));

        horizontalLayout->addWidget(btnDown);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CXIniFileList);

        QMetaObject::connectSlotsByName(CXIniFileList);
    } // setupUi

    void retranslateUi(QWidget *CXIniFileList)
    {
        CXIniFileList->setWindowTitle(QApplication::translate("CXIniFileList", "CXIniFileList", 0, QApplication::UnicodeUTF8));
        btnUp->setText(QApplication::translate("CXIniFileList", "\320\222\320\262\320\265\321\200\321\205", 0, QApplication::UnicodeUTF8));
        btnLoad->setText(QApplication::translate("CXIniFileList", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        btnDown->setText(QApplication::translate("CXIniFileList", "\320\222\320\275\320\270\320\267", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXIniFileList: public Ui_CXIniFileList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXINIFILELIST_H
