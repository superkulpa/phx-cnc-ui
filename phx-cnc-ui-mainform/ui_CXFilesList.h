/********************************************************************************
** Form generated from reading UI file 'CXFilesList.ui'
**
** Created: Mon 24. Sep 17:06:08 2012
**      by: Qt User Interface Compiler version 4.8.2
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
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CXFilesList
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListView *mFileView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *mDownButton;
    QPushButton *mOpenButton;
    QPushButton *mUpButton;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *mCompileEdit;

    void setupUi(QWidget *CXFilesList)
    {
        if (CXFilesList->objectName().isEmpty())
            CXFilesList->setObjectName(QString::fromUtf8("CXFilesList"));
        CXFilesList->resize(458, 623);
        verticalLayout_2 = new QVBoxLayout(CXFilesList);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(CXFilesList);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(7);
        verticalLayout->setContentsMargins(7, 7, 7, 7);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mFileView = new QListView(groupBox);
        mFileView->setObjectName(QString::fromUtf8("mFileView"));
        mFileView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        mFileView->setIconSize(QSize(25, 25));

        verticalLayout->addWidget(mFileView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        mDownButton = new QPushButton(groupBox);
        mDownButton->setObjectName(QString::fromUtf8("mDownButton"));
        mDownButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        mDownButton->setIcon(icon);
        mDownButton->setIconSize(QSize(24, 24));
        mDownButton->setAutoRepeat(true);
        mDownButton->setAutoRepeatInterval(100);

        horizontalLayout_2->addWidget(mDownButton);

        mOpenButton = new QPushButton(groupBox);
        mOpenButton->setObjectName(QString::fromUtf8("mOpenButton"));
        mOpenButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/open_folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        mOpenButton->setIcon(icon1);
        mOpenButton->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(mOpenButton);

        mUpButton = new QPushButton(groupBox);
        mUpButton->setObjectName(QString::fromUtf8("mUpButton"));
        mUpButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/up.png"), QSize(), QIcon::Normal, QIcon::Off);
        mUpButton->setIcon(icon2);
        mUpButton->setIconSize(QSize(24, 24));
        mUpButton->setAutoRepeat(true);
        mUpButton->setAutoRepeatInterval(100);

        horizontalLayout_2->addWidget(mUpButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        mCompileEdit = new QTextEdit(groupBox);
        mCompileEdit->setObjectName(QString::fromUtf8("mCompileEdit"));
        mCompileEdit->setMaximumSize(QSize(16777215, 80));
        mCompileEdit->setReadOnly(true);

        verticalLayout->addWidget(mCompileEdit);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(CXFilesList);

        QMetaObject::connectSlotsByName(CXFilesList);
    } // setupUi

    void retranslateUi(QWidget *CXFilesList)
    {
        CXFilesList->setWindowTitle(QApplication::translate("CXFilesList", "CXFilesList", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CXFilesList", "\320\244\320\260\320\271\320\273 \320\264\320\260\320\275\320\275\321\213\321\205", 0, QApplication::UnicodeUTF8));
        mDownButton->setText(QString());
        mOpenButton->setText(QString());
        mUpButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CXFilesList: public Ui_CXFilesList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXFILESLIST_H
