/********************************************************************************
** Form generated from reading UI file 'CXIniFileList.ui'
**
** Created: Mon 24. Sep 17:20:03 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXINIFILELIST_H
#define UI_CXINIFILELIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CXIniFileList
{
public:
    QVBoxLayout *verticalLayout;
    QListView *mIniFileView;
    QPushButton *mSaveButton;

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

        mSaveButton = new QPushButton(CXIniFileList);
        mSaveButton->setObjectName(QString::fromUtf8("mSaveButton"));

        verticalLayout->addWidget(mSaveButton);


        retranslateUi(CXIniFileList);

        QMetaObject::connectSlotsByName(CXIniFileList);
    } // setupUi

    void retranslateUi(QWidget *CXIniFileList)
    {
        CXIniFileList->setWindowTitle(QApplication::translate("CXIniFileList", "CXIniFileList", 0, QApplication::UnicodeUTF8));
        mSaveButton->setText(QApplication::translate("CXIniFileList", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXIniFileList: public Ui_CXIniFileList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXINIFILELIST_H
