/********************************************************************************
** Form generated from reading UI file 'CXIniFileEditor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXINIFILEEDITOR_H
#define UI_CXINIFILEEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "CXTouchButton.h"

QT_BEGIN_NAMESPACE

class Ui_CXIniFileEditor
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListView *mIniFileView;
    QHBoxLayout *horizontalLayout1;
    QSpacerItem *horizontalSpacer;
    CXTouchButton *btnUp;
    CXTouchButton *btnLoad;
    CXTouchButton *btnDown;
    QSpacerItem *horizontalSpacer_2;
    QPlainTextEdit *mIniFileEdit;

    void setupUi(QWidget *CXIniFileEditor)
    {
        if (CXIniFileEditor->objectName().isEmpty())
            CXIniFileEditor->setObjectName(QString::fromUtf8("CXIniFileEditor"));
        CXIniFileEditor->resize(902, 484);
        horizontalLayout = new QHBoxLayout(CXIniFileEditor);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(CXIniFileEditor);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(300, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mIniFileView = new QListView(groupBox);
        mIniFileView->setObjectName(QString::fromUtf8("mIniFileView"));

        verticalLayout->addWidget(mIniFileView);

        horizontalLayout1 = new QHBoxLayout();
        horizontalLayout1->setSpacing(6);
        horizontalLayout1->setObjectName(QString::fromUtf8("horizontalLayout1"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout1->addItem(horizontalSpacer);

        btnUp = new CXTouchButton(groupBox);
        btnUp->setObjectName(QString::fromUtf8("btnUp"));

        horizontalLayout1->addWidget(btnUp);

        btnLoad = new CXTouchButton(groupBox);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));

        horizontalLayout1->addWidget(btnLoad);

        btnDown = new CXTouchButton(groupBox);
        btnDown->setObjectName(QString::fromUtf8("btnDown"));

        horizontalLayout1->addWidget(btnDown);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout1->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout1);


        verticalLayout_2->addLayout(verticalLayout);

        mIniFileView->raise();

        horizontalLayout->addWidget(groupBox);

        mIniFileEdit = new QPlainTextEdit(CXIniFileEditor);
        mIniFileEdit->setObjectName(QString::fromUtf8("mIniFileEdit"));

        horizontalLayout->addWidget(mIniFileEdit);


        retranslateUi(CXIniFileEditor);

        QMetaObject::connectSlotsByName(CXIniFileEditor);
    } // setupUi

    void retranslateUi(QWidget *CXIniFileEditor)
    {
        CXIniFileEditor->setWindowTitle(QApplication::translate("CXIniFileEditor", "CXIniFileEditor", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CXIniFileEditor", "\320\222\321\201\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", 0, QApplication::UnicodeUTF8));
        btnUp->setText(QString());
        btnLoad->setText(QString());
        btnDown->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CXIniFileEditor: public Ui_CXIniFileEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXINIFILEEDITOR_H
