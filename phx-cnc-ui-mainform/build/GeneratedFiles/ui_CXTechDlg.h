/********************************************************************************
** Form generated from reading UI file 'CXTechDlg.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXTECHDLG_H
#define UI_CXTECHDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dlgTechnology
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *dlgTechnology)
    {
        if (dlgTechnology->objectName().isEmpty())
            dlgTechnology->setObjectName(QString::fromUtf8("dlgTechnology"));
        dlgTechnology->setWindowModality(Qt::NonModal);
        dlgTechnology->resize(727, 108);
        verticalLayout = new QVBoxLayout(dlgTechnology);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        retranslateUi(dlgTechnology);

        QMetaObject::connectSlotsByName(dlgTechnology);
    } // setupUi

    void retranslateUi(QDialog *dlgTechnology)
    {
        dlgTechnology->setWindowTitle(QApplication::translate("dlgTechnology", "\320\222\321\213\320\261\320\276\321\200 \321\202\320\265\321\205\320\275\320\276\320\273\320\276\320\263\320\270\320\270 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\270", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dlgTechnology: public Ui_dlgTechnology {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXTECHDLG_H
