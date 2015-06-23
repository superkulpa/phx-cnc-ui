/********************************************************************************
** Form generated from reading UI file 'CXChannelEdit.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXCHANNELEDIT_H
#define UI_CXCHANNELEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "CXTouchButton.h"

QT_BEGIN_NAMESPACE

class Ui_CXChannelEdit
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QListWidget *mSectionsList;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *mNamesList;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *mModifyEdit;
    QLabel *label_2;
    QLineEdit *mDescriptionEdit;
    QSpacerItem *verticalSpacer;
    CXTouchButton *mAcceptButton;
    CXTouchButton *mCancelButton;

    void setupUi(QDialog *CXChannelEdit)
    {
        if (CXChannelEdit->objectName().isEmpty())
            CXChannelEdit->setObjectName(QString::fromUtf8("CXChannelEdit"));
        CXChannelEdit->resize(820, 300);
        gridLayout = new QGridLayout(CXChannelEdit);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(CXChannelEdit);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(7, 7, 7, 7);
        mSectionsList = new QListWidget(groupBox);
        mSectionsList->setObjectName(QString::fromUtf8("mSectionsList"));
        mSectionsList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_3->addWidget(mSectionsList);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(CXChannelEdit);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(7, 7, 7, 7);
        mNamesList = new QListWidget(groupBox_2);
        mNamesList->setObjectName(QString::fromUtf8("mNamesList"));
        mNamesList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(mNamesList);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(CXChannelEdit);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(7, 7, 7, 7);
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        mModifyEdit = new QLineEdit(groupBox_3);
        mModifyEdit->setObjectName(QString::fromUtf8("mModifyEdit"));

        verticalLayout->addWidget(mModifyEdit);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        mDescriptionEdit = new QLineEdit(groupBox_3);
        mDescriptionEdit->setObjectName(QString::fromUtf8("mDescriptionEdit"));

        verticalLayout->addWidget(mDescriptionEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(groupBox_3, 0, 2, 1, 1);

        mAcceptButton = new CXTouchButton(CXChannelEdit);
        mAcceptButton->setObjectName(QString::fromUtf8("mAcceptButton"));
        mAcceptButton->setAutoDefault(true);
        mAcceptButton->setDefault(true);

        gridLayout->addWidget(mAcceptButton, 1, 2, 1, 1);

        mCancelButton = new CXTouchButton(CXChannelEdit);
        mCancelButton->setObjectName(QString::fromUtf8("mCancelButton"));
        mCancelButton->setAutoDefault(true);
        mCancelButton->setDefault(true);

        gridLayout->addWidget(mCancelButton, 2, 2, 1, 1);


        retranslateUi(CXChannelEdit);
        QObject::connect(mAcceptButton, SIGNAL(clicked()), CXChannelEdit, SLOT(accept()));
        QObject::connect(mCancelButton, SIGNAL(clicked()), CXChannelEdit, SLOT(close()));

        QMetaObject::connectSlotsByName(CXChannelEdit);
    } // setupUi

    void retranslateUi(QDialog *CXChannelEdit)
    {
        CXChannelEdit->setWindowTitle(QApplication::translate("CXChannelEdit", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \320\272\320\260\320\275\320\260\320\273\320\260", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CXChannelEdit", "\320\241\320\265\320\272\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CXChannelEdit", "\320\230\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        label->setText(QApplication::translate("CXChannelEdit", "\320\234\320\276\320\264\320\270\321\204\320\270\320\272\320\260\321\202\320\276\321\200", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CXChannelEdit", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        mAcceptButton->setText(QApplication::translate("CXChannelEdit", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mCancelButton->setText(QApplication::translate("CXChannelEdit", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXChannelEdit: public Ui_CXChannelEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXCHANNELEDIT_H
