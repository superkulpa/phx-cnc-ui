/********************************************************************************
** Form generated from reading UI file 'CXEditPathFile.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXEDITPATHFILE_H
#define UI_CXEDITPATHFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "CXTouchButton.h"

QT_BEGIN_NAMESPACE

class Ui_CXEditPathFile
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *mTitleGroup;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *mTextEdit;
    QLabel *mCurrentLineLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    CXTouchButton *mSaveButton;
    CXTouchButton *mSaveAsButton;
    CXTouchButton *mCreateButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *CXEditPathFile)
    {
        if (CXEditPathFile->objectName().isEmpty())
            CXEditPathFile->setObjectName(QString::fromUtf8("CXEditPathFile"));
        CXEditPathFile->resize(369, 430);
        verticalLayout = new QVBoxLayout(CXEditPathFile);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mTitleGroup = new QGroupBox(CXEditPathFile);
        mTitleGroup->setObjectName(QString::fromUtf8("mTitleGroup"));
        verticalLayout_2 = new QVBoxLayout(mTitleGroup);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 7, 7, 0);
        mTextEdit = new QTextEdit(mTitleGroup);
        mTextEdit->setObjectName(QString::fromUtf8("mTextEdit"));
        mTextEdit->setTextInteractionFlags(Qt::TextEditorInteraction);

        verticalLayout_2->addWidget(mTextEdit);

        mCurrentLineLabel = new QLabel(mTitleGroup);
        mCurrentLineLabel->setObjectName(QString::fromUtf8("mCurrentLineLabel"));

        verticalLayout_2->addWidget(mCurrentLineLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mSaveButton = new CXTouchButton(mTitleGroup);
        mSaveButton->setObjectName(QString::fromUtf8("mSaveButton"));

        horizontalLayout->addWidget(mSaveButton);

        mSaveAsButton = new CXTouchButton(mTitleGroup);
        mSaveAsButton->setObjectName(QString::fromUtf8("mSaveAsButton"));

        horizontalLayout->addWidget(mSaveAsButton);

        mCreateButton = new CXTouchButton(mTitleGroup);
        mCreateButton->setObjectName(QString::fromUtf8("mCreateButton"));

        horizontalLayout->addWidget(mCreateButton);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(mTitleGroup);


        retranslateUi(CXEditPathFile);

        QMetaObject::connectSlotsByName(CXEditPathFile);
    } // setupUi

    void retranslateUi(QWidget *CXEditPathFile)
    {
        CXEditPathFile->setWindowTitle(QApplication::translate("CXEditPathFile", "Form", 0, QApplication::UnicodeUTF8));
        mTitleGroup->setTitle(QString());
        mCurrentLineLabel->setText(QString());
        mSaveButton->setText(QApplication::translate("CXEditPathFile", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mSaveAsButton->setText(QApplication::translate("CXEditPathFile", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272", 0, QApplication::UnicodeUTF8));
        mCreateButton->setText(QApplication::translate("CXEditPathFile", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXEditPathFile: public Ui_CXEditPathFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXEDITPATHFILE_H
