/********************************************************************************
** Form generated from reading UI file 'CXEditPathFile.ui'
**
** Created: Mon 24. Sep 16:09:50 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXEDITPATHFILE_H
#define UI_CXEDITPATHFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CXEditPathFile
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *mTitleLabel;
    QTextEdit *mTextEdit;
    QLabel *mCurrentLineLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *mSaveButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *mSaveAsButton;
    QPushButton *mCreateButton;

    void setupUi(QWidget *CXEditPathFile)
    {
        if (CXEditPathFile->objectName().isEmpty())
            CXEditPathFile->setObjectName(QString::fromUtf8("CXEditPathFile"));
        CXEditPathFile->resize(338, 356);
        gridLayout = new QGridLayout(CXEditPathFile);
        gridLayout->setSpacing(5);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_2 = new QGroupBox(CXEditPathFile);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(7);
        verticalLayout_2->setContentsMargins(7, 7, 7, 7);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        mTitleLabel = new QLabel(groupBox_2);
        mTitleLabel->setObjectName(QString::fromUtf8("mTitleLabel"));

        verticalLayout_2->addWidget(mTitleLabel);

        mTextEdit = new QTextEdit(groupBox_2);
        mTextEdit->setObjectName(QString::fromUtf8("mTextEdit"));
        mTextEdit->setTextInteractionFlags(Qt::TextEditorInteraction);

        verticalLayout_2->addWidget(mTextEdit);

        mCurrentLineLabel = new QLabel(groupBox_2);
        mCurrentLineLabel->setObjectName(QString::fromUtf8("mCurrentLineLabel"));

        verticalLayout_2->addWidget(mCurrentLineLabel);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 5);

        horizontalSpacer = new QSpacerItem(140, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        mSaveButton = new QPushButton(CXEditPathFile);
        mSaveButton->setObjectName(QString::fromUtf8("mSaveButton"));

        gridLayout->addWidget(mSaveButton, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(139, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        mSaveAsButton = new QPushButton(CXEditPathFile);
        mSaveAsButton->setObjectName(QString::fromUtf8("mSaveAsButton"));

        gridLayout->addWidget(mSaveAsButton, 1, 2, 1, 1);

        mCreateButton = new QPushButton(CXEditPathFile);
        mCreateButton->setObjectName(QString::fromUtf8("mCreateButton"));

        gridLayout->addWidget(mCreateButton, 1, 3, 1, 1);


        retranslateUi(CXEditPathFile);

        QMetaObject::connectSlotsByName(CXEditPathFile);
    } // setupUi

    void retranslateUi(QWidget *CXEditPathFile)
    {
        CXEditPathFile->setWindowTitle(QApplication::translate("CXEditPathFile", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        mTitleLabel->setText(QString());
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
