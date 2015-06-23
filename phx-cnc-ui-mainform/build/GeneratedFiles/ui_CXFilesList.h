/********************************************************************************
** Form generated from reading UI file 'CXFilesList.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXFILESLIST_H
#define UI_CXFILESLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "CXTouchButton.h"

QT_BEGIN_NAMESPACE

class Ui_CXFilesList
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListView *mFileView;
    QHBoxLayout *horizontalLayout;
    QLabel *mFileNameLabel;
    QLineEdit *mFileNameEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    CXTouchButton *mReturnButton;
    CXTouchButton *mDownButton;
    CXTouchButton *mOpenButton;
    CXTouchButton *mUpButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    CXTouchButton *mSaveButton;
    CXTouchButton *mCloseButton;

    void setupUi(QWidget *CXFilesList)
    {
        if (CXFilesList->objectName().isEmpty())
            CXFilesList->setObjectName(QString::fromUtf8("CXFilesList"));
        CXFilesList->resize(458, 547);
        verticalLayout_2 = new QVBoxLayout(CXFilesList);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(CXFilesList);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 5, 0, 5);
        mFileView = new QListView(groupBox);
        mFileView->setObjectName(QString::fromUtf8("mFileView"));
        mFileView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        mFileView->setIconSize(QSize(25, 25));

        verticalLayout->addWidget(mFileView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mFileNameLabel = new QLabel(groupBox);
        mFileNameLabel->setObjectName(QString::fromUtf8("mFileNameLabel"));

        horizontalLayout->addWidget(mFileNameLabel);

        mFileNameEdit = new QLineEdit(groupBox);
        mFileNameEdit->setObjectName(QString::fromUtf8("mFileNameEdit"));

        horizontalLayout->addWidget(mFileNameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        mReturnButton = new CXTouchButton(groupBox);
        mReturnButton->setObjectName(QString::fromUtf8("mReturnButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../images/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        mReturnButton->setIcon(icon);
        mReturnButton->setIconSize(QSize(24, 24));
        mReturnButton->setAutoRepeat(true);
        mReturnButton->setAutoRepeatInterval(100);

        horizontalLayout_2->addWidget(mReturnButton);

        mDownButton = new CXTouchButton(groupBox);
        mDownButton->setObjectName(QString::fromUtf8("mDownButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        mDownButton->setIcon(icon1);
        mDownButton->setIconSize(QSize(24, 24));
        mDownButton->setAutoRepeat(true);
        mDownButton->setAutoRepeatInterval(100);

        horizontalLayout_2->addWidget(mDownButton);

        mOpenButton = new CXTouchButton(groupBox);
        mOpenButton->setObjectName(QString::fromUtf8("mOpenButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/open_folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        mOpenButton->setIcon(icon2);
        mOpenButton->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(mOpenButton);

        mUpButton = new CXTouchButton(groupBox);
        mUpButton->setObjectName(QString::fromUtf8("mUpButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        mUpButton->setIcon(icon3);
        mUpButton->setIconSize(QSize(24, 24));
        mUpButton->setAutoRepeat(true);
        mUpButton->setAutoRepeatInterval(100);

        horizontalLayout_2->addWidget(mUpButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        mSaveButton = new CXTouchButton(groupBox);
        mSaveButton->setObjectName(QString::fromUtf8("mSaveButton"));

        horizontalLayout_3->addWidget(mSaveButton);

        mCloseButton = new CXTouchButton(groupBox);
        mCloseButton->setObjectName(QString::fromUtf8("mCloseButton"));

        horizontalLayout_3->addWidget(mCloseButton);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(CXFilesList);

        QMetaObject::connectSlotsByName(CXFilesList);
    } // setupUi

    void retranslateUi(QWidget *CXFilesList)
    {
        CXFilesList->setWindowTitle(QApplication::translate("CXFilesList", "CXFilesList", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CXFilesList", "\320\244\320\260\320\271\320\273\321\213 \320\243\320\237", 0, QApplication::UnicodeUTF8));
        mFileNameLabel->setText(QApplication::translate("CXFilesList", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260: ", 0, QApplication::UnicodeUTF8));
        mReturnButton->setText(QString());
        mDownButton->setText(QString());
        mOpenButton->setText(QString());
        mUpButton->setText(QString());
        mSaveButton->setText(QApplication::translate("CXFilesList", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mCloseButton->setText(QApplication::translate("CXFilesList", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXFilesList: public Ui_CXFilesList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXFILESLIST_H
