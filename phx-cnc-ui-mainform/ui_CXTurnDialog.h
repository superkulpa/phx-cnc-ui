/********************************************************************************
** Form generated from reading UI file 'CXTurnDialog.ui'
**
** Created: Mon 24. Sep 17:28:54 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CXTURNDIALOG_H
#define UI_CXTURNDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CXTurnDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *mTurnSettings;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_20;
    QPushButton *pushButton_19;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton_21;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QSpacerItem *verticalSpacer;
    QPushButton *mCloseButton;

    void setupUi(QWidget *CXTurnDialog)
    {
        if (CXTurnDialog->objectName().isEmpty())
            CXTurnDialog->setObjectName(QString::fromUtf8("CXTurnDialog"));
        CXTurnDialog->resize(904, 709);
        horizontalLayout = new QHBoxLayout(CXTurnDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mTurnSettings = new QFrame(CXTurnDialog);
        mTurnSettings->setObjectName(QString::fromUtf8("mTurnSettings"));
        mTurnSettings->setFrameShape(QFrame::StyledPanel);
        mTurnSettings->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(mTurnSettings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(mTurnSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        pushButton_17 = new QPushButton(groupBox);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));

        gridLayout_2->addWidget(pushButton_17, 0, 1, 1, 1);

        pushButton_18 = new QPushButton(groupBox);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));

        gridLayout_2->addWidget(pushButton_18, 1, 1, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 1, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(mTurnSettings);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_20 = new QPushButton(groupBox_2);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        pushButton_20->setMinimumSize(QSize(200, 100));

        gridLayout_3->addWidget(pushButton_20, 1, 1, 1, 1);

        pushButton_19 = new QPushButton(groupBox_2);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        pushButton_19->setMinimumSize(QSize(200, 100));

        gridLayout_3->addWidget(pushButton_19, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(mTurnSettings);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_4->addWidget(lineEdit_2, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        pushButton_21 = new QPushButton(groupBox_3);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        pushButton_21->setMinimumSize(QSize(200, 100));

        gridLayout_4->addWidget(pushButton_21, 0, 1, 2, 1);


        verticalLayout->addWidget(groupBox_3);


        horizontalLayout->addWidget(mTurnSettings);

        frame_2 = new QFrame(CXTurnDialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(332, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_7 = new QPushButton(frame_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(frame_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 0, 1, 1, 1);

        pushButton_9 = new QPushButton(frame_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(frame_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 2, 1, 1);

        pushButton_10 = new QPushButton(frame_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout->addWidget(pushButton_10, 3, 0, 1, 1);

        pushButton_11 = new QPushButton(frame_2);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        gridLayout->addWidget(pushButton_11, 3, 1, 1, 1);

        pushButton_12 = new QPushButton(frame_2);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        gridLayout->addWidget(pushButton_12, 3, 2, 1, 1);

        pushButton_13 = new QPushButton(frame_2);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        gridLayout->addWidget(pushButton_13, 4, 0, 1, 1);

        pushButton_14 = new QPushButton(frame_2);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        gridLayout->addWidget(pushButton_14, 4, 1, 1, 1);

        pushButton_15 = new QPushButton(frame_2);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        gridLayout->addWidget(pushButton_15, 4, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);

        mCloseButton = new QPushButton(frame_2);
        mCloseButton->setObjectName(QString::fromUtf8("mCloseButton"));

        gridLayout->addWidget(mCloseButton, 6, 1, 1, 2);


        horizontalLayout->addWidget(frame_2);


        retranslateUi(CXTurnDialog);

        QMetaObject::connectSlotsByName(CXTurnDialog);
    } // setupUi

    void retranslateUi(QWidget *CXTurnDialog)
    {
        CXTurnDialog->setWindowTitle(QApplication::translate("CXTurnDialog", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214/\320\237\320\265\321\200\320\265\320\262\320\265\321\200\320\275\321\203\321\202\321\214/\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CXTurnDialog", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214 \320\243\320\237", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CXTurnDialog", "<html><head/><body><p>\320\243\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260<br/>(0.1 \320\263\321\200\320\260\320\264\321\203\321\201\320\260)</p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_17->setText(QApplication::translate("CXTurnDialog", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButton_18->setText(QApplication::translate("CXTurnDialog", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QString());
        groupBox_2->setTitle(QApplication::translate("CXTurnDialog", "\320\237\320\265\321\200\320\265\320\262\320\265\321\200\320\275\321\203\321\202\321\214 \320\243\320\237", 0, QApplication::UnicodeUTF8));
        pushButton_20->setText(QApplication::translate("CXTurnDialog", "\320\227\320\265\321\200\320\272\320\260\320\273\321\214\320\275\320\276 \320\277\320\276 Y", 0, QApplication::UnicodeUTF8));
        pushButton_19->setText(QApplication::translate("CXTurnDialog", "\320\227\320\265\321\200\320\272\320\260\320\273\321\214\320\275\320\276 \320\277\320\276 X", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("CXTurnDialog", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CXTurnDialog", "<html><head/><body><p>\320\234\320\260\321\201\321\210\321\202\320\260\320\261<br/>(% \320\276\321\202 \320\276\321\200\320\270\320\263\320\270\320\275\320\260\320\273\320\260)</p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_21->setText(QApplication::translate("CXTurnDialog", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("CXTurnDialog", "7", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("CXTurnDialog", "8", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("CXTurnDialog", "9", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("CXTurnDialog", "4", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("CXTurnDialog", "5", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("CXTurnDialog", "6", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("CXTurnDialog", "1", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("CXTurnDialog", "2", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("CXTurnDialog", "3", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("CXTurnDialog", "+", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("CXTurnDialog", "0", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("CXTurnDialog", "-", 0, QApplication::UnicodeUTF8));
        pushButton_13->setText(QApplication::translate("CXTurnDialog", "\342\206\220", 0, QApplication::UnicodeUTF8));
        pushButton_14->setText(QApplication::translate("CXTurnDialog", "Enter", 0, QApplication::UnicodeUTF8));
        pushButton_15->setText(QApplication::translate("CXTurnDialog", "Del", 0, QApplication::UnicodeUTF8));
        mCloseButton->setText(QApplication::translate("CXTurnDialog", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CXTurnDialog: public Ui_CXTurnDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CXTURNDIALOG_H
