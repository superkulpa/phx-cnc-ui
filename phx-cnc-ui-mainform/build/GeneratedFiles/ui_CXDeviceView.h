/********************************************************************************
** Form generated from reading UI file 'CXDeviceView.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXDEVICEVIEW_H
#define UI_CXDEVICEVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CXDeviceView
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *mNameLabel;
    QTableWidget *mChannelsTable;

    void setupUi(QWidget *CXDeviceView)
    {
        if (CXDeviceView->objectName().isEmpty())
            CXDeviceView->setObjectName(QString::fromUtf8("CXDeviceView"));
        CXDeviceView->resize(400, 300);
        verticalLayout = new QVBoxLayout(CXDeviceView);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(7, 7, 7, 7);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mNameLabel = new QLabel(CXDeviceView);
        mNameLabel->setObjectName(QString::fromUtf8("mNameLabel"));
        mNameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(mNameLabel);

        mChannelsTable = new QTableWidget(CXDeviceView);
        mChannelsTable->setObjectName(QString::fromUtf8("mChannelsTable"));
        mChannelsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        mChannelsTable->setAlternatingRowColors(true);
        mChannelsTable->setSelectionMode(QAbstractItemView::SingleSelection);
        mChannelsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        mChannelsTable->horizontalHeader()->setVisible(false);
        mChannelsTable->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(mChannelsTable);


        retranslateUi(CXDeviceView);

        QMetaObject::connectSlotsByName(CXDeviceView);
    } // setupUi

    void retranslateUi(QWidget *CXDeviceView)
    {
        CXDeviceView->setWindowTitle(QApplication::translate("CXDeviceView", "CXDeviceView", 0, QApplication::UnicodeUTF8));
        mNameLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CXDeviceView: public Ui_CXDeviceView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXDEVICEVIEW_H
