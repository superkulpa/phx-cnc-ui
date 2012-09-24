/********************************************************************************
** Form generated from reading UI file 'CXIniFileEditor.ui'
**
** Created: Mon 24. Sep 13:09:02 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXINIFILEEDITOR_H
#define UI_CXINIFILEEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CXIniFileEditor
{
public:
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *mIniFileEdit;

    void setupUi(QWidget *CXIniFileEditor)
    {
        if (CXIniFileEditor->objectName().isEmpty())
            CXIniFileEditor->setObjectName(QString::fromUtf8("CXIniFileEditor"));
        CXIniFileEditor->resize(351, 484);
        verticalLayout = new QVBoxLayout(CXIniFileEditor);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mIniFileEdit = new QPlainTextEdit(CXIniFileEditor);
        mIniFileEdit->setObjectName(QString::fromUtf8("mIniFileEdit"));

        verticalLayout->addWidget(mIniFileEdit);


        retranslateUi(CXIniFileEditor);

        QMetaObject::connectSlotsByName(CXIniFileEditor);
    } // setupUi

    void retranslateUi(QWidget *CXIniFileEditor)
    {
        CXIniFileEditor->setWindowTitle(QApplication::translate("CXIniFileEditor", "CXIniFileEditor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXIniFileEditor: public Ui_CXIniFileEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXINIFILEEDITOR_H
