/********************************************************************************
** Form generated from reading UI file 'qgasconsole.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGASCONSOLE_H
#define UI_QGASCONSOLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGasConsole
{
public:
    QHBoxLayout *horizontalLayout_8;
    QTabWidget *tabConsole;
    QWidget *tabGeneral;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_20;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QLabel *lLineVoltage;
    QLabel *label_3;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *lCurSetPoint;
    QLabel *label_32;
    QLabel *lWorkLead;
    QLabel *label_34;
    QLabel *lCoolantFlow;
    QLabel *label_36;
    QLabel *lPSStateCode;
    QLabel *lLastErrors;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_21;
    QGridLayout *gridLayout_16;
    QLabel *label_4;
    QLabel *lArcOnTime;
    QLabel *label_6;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *lSysOnTime;
    QLabel *label_40;
    QLabel *lTotStarts;
    QLabel *label_42;
    QLabel *lTotErrors;
    QLabel *label_44;
    QLabel *lRampErrors;
    QLabel *label_46;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_22;
    QGridLayout *gridLayout_17;
    QLabel *label_7;
    QLabel *lPlasmaIG;
    QLabel *label_24;
    QLabel *lShieldIG;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_23;
    QGridLayout *gridLayout_18;
    QLabel *label_9;
    QLabel *lPlasmaCutflow;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *lPlasmaPreflow;
    QLabel *label_49;
    QLabel *lShieldCutflow;
    QLabel *label_51;
    QLabel *lShieldPreflow;
    QLabel *label_53;
    QLabel *label_11;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_24;
    QGridLayout *gridLayout_19;
    QLabel *label_12;
    QLabel *lInletGas1;
    QLabel *label_14;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *lMixedGas1;
    QLabel *label_54;
    QLabel *lInletGas2;
    QLabel *lMixedGas2;
    QLabel *label_58;
    QLabel *label_59;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *btUpdate;
    QPushButton *btClear;
    QPushButton *btTestPreflow;
    QPushButton *btTestCutflow;
    QPushButton *btClose;
    QWidget *tabAdd;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_7;
    QGridLayout *gridLayout_4;
    QLabel *label_43;
    QLabel *lChopperATemp;
    QLabel *label_47;
    QLabel *label_48;
    QLabel *label_50;
    QLabel *label_52;
    QLabel *lChopperBTemp;
    QLabel *label_56;
    QLabel *lChopperCTemp;
    QLabel *label_60;
    QLabel *lChopperDTemp;
    QLabel *label_62;
    QLabel *label_63;
    QLabel *label_64;
    QLabel *lCoolantTemp;
    QLabel *label_66;
    QLabel *lTransformerTemp;
    QLabel *label_68;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_6;
    QGridLayout *gridLayout_6;
    QLabel *labelGC;
    QLabel *lPS_Rev;
    QLabel *lGC_Rev;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_13;
    QLabel *label_31;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_41;
    QSpacerItem *verticalSpacer_2;
    QLabel *lChA_SP;
    QLabel *lChB_SP;
    QLabel *lChB_Cur;
    QLabel *lChC_SP;
    QLabel *lChC_Cur;
    QLabel *lChD_SP;
    QLabel *lChD_Cur;
    QLabel *lChA_Cur;
    QLabel *label_67;
    QLabel *label_69;
    QLabel *label_70;
    QLabel *label_71;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *btUpdateAdd;
    QPushButton *btCloseAdd;

    void setupUi(QDialog *QGasConsole)
    {
        if (QGasConsole->objectName().isEmpty())
            QGasConsole->setObjectName(QString::fromUtf8("QGasConsole"));
        QGasConsole->resize(805, 638);
        horizontalLayout_8 = new QHBoxLayout(QGasConsole);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        tabConsole = new QTabWidget(QGasConsole);
        tabConsole->setObjectName(QString::fromUtf8("tabConsole"));
        QFont font;
        font.setPointSize(18);
        tabConsole->setFont(font);
        tabGeneral = new QWidget();
        tabGeneral->setObjectName(QString::fromUtf8("tabGeneral"));
        verticalLayout_3 = new QVBoxLayout(tabGeneral);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_3 = new QGroupBox(tabGeneral);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_20 = new QHBoxLayout(groupBox_3);
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        lLineVoltage = new QLabel(groupBox_3);
        lLineVoltage->setObjectName(QString::fromUtf8("lLineVoltage"));
        lLineVoltage->setEnabled(false);
        QFont font1;
        font1.setItalic(true);
        lLineVoltage->setFont(font1);
        lLineVoltage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(lLineVoltage, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_3, 0, 2, 1, 1);

        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_15, 1, 0, 1, 1);

        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_16, 2, 0, 1, 1);

        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_17, 3, 0, 1, 1);

        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_18, 4, 0, 1, 1);

        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_19, 5, 0, 1, 1);

        lCurSetPoint = new QLabel(groupBox_3);
        lCurSetPoint->setObjectName(QString::fromUtf8("lCurSetPoint"));
        lCurSetPoint->setEnabled(false);
        lCurSetPoint->setFont(font1);
        lCurSetPoint->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(lCurSetPoint, 1, 1, 1, 1);

        label_32 = new QLabel(groupBox_3);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_32, 1, 2, 1, 1);

        lWorkLead = new QLabel(groupBox_3);
        lWorkLead->setObjectName(QString::fromUtf8("lWorkLead"));
        lWorkLead->setFont(font1);
        lWorkLead->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(lWorkLead, 2, 1, 1, 1);

        label_34 = new QLabel(groupBox_3);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_34, 2, 2, 1, 1);

        lCoolantFlow = new QLabel(groupBox_3);
        lCoolantFlow->setObjectName(QString::fromUtf8("lCoolantFlow"));
        lCoolantFlow->setFont(font1);
        lCoolantFlow->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(lCoolantFlow, 3, 1, 1, 1);

        label_36 = new QLabel(groupBox_3);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_36, 3, 2, 1, 1);

        lPSStateCode = new QLabel(groupBox_3);
        lPSStateCode->setObjectName(QString::fromUtf8("lPSStateCode"));
        lPSStateCode->setFont(font1);
        lPSStateCode->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(lPSStateCode, 4, 1, 1, 2);

        lLastErrors = new QLabel(groupBox_3);
        lLastErrors->setObjectName(QString::fromUtf8("lLastErrors"));
        lLastErrors->setFont(font1);
        lLastErrors->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(lLastErrors, 5, 1, 1, 2);


        horizontalLayout_20->addLayout(gridLayout_5);


        verticalLayout_5->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(tabGeneral);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_21 = new QHBoxLayout(groupBox_2);
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        gridLayout_16 = new QGridLayout();
        gridLayout_16->setSpacing(6);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_16->addWidget(label_4, 0, 0, 1, 1);

        lArcOnTime = new QLabel(groupBox_2);
        lArcOnTime->setObjectName(QString::fromUtf8("lArcOnTime"));
        lArcOnTime->setFont(font1);
        lArcOnTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(lArcOnTime, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_16->addWidget(label_6, 0, 2, 1, 1);

        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_16->addWidget(label_20, 1, 0, 1, 1);

        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_16->addWidget(label_21, 2, 0, 1, 1);

        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_16->addWidget(label_22, 3, 0, 1, 1);

        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_16->addWidget(label_23, 4, 0, 1, 1);

        lSysOnTime = new QLabel(groupBox_2);
        lSysOnTime->setObjectName(QString::fromUtf8("lSysOnTime"));
        lSysOnTime->setFont(font1);
        lSysOnTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(lSysOnTime, 1, 1, 1, 1);

        label_40 = new QLabel(groupBox_2);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setAlignment(Qt::AlignCenter);

        gridLayout_16->addWidget(label_40, 1, 2, 1, 1);

        lTotStarts = new QLabel(groupBox_2);
        lTotStarts->setObjectName(QString::fromUtf8("lTotStarts"));
        lTotStarts->setFont(font1);
        lTotStarts->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(lTotStarts, 2, 1, 1, 1);

        label_42 = new QLabel(groupBox_2);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setAlignment(Qt::AlignCenter);

        gridLayout_16->addWidget(label_42, 2, 2, 1, 1);

        lTotErrors = new QLabel(groupBox_2);
        lTotErrors->setObjectName(QString::fromUtf8("lTotErrors"));
        lTotErrors->setFont(font1);
        lTotErrors->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(lTotErrors, 3, 1, 1, 1);

        label_44 = new QLabel(groupBox_2);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setAlignment(Qt::AlignCenter);

        gridLayout_16->addWidget(label_44, 3, 2, 1, 1);

        lRampErrors = new QLabel(groupBox_2);
        lRampErrors->setObjectName(QString::fromUtf8("lRampErrors"));
        lRampErrors->setFont(font1);
        lRampErrors->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(lRampErrors, 4, 1, 1, 1);

        label_46 = new QLabel(groupBox_2);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setAlignment(Qt::AlignCenter);

        gridLayout_16->addWidget(label_46, 4, 2, 1, 1);


        horizontalLayout_21->addLayout(gridLayout_16);


        verticalLayout_5->addWidget(groupBox_2);

        verticalLayout_5->setStretch(0, 6);
        verticalLayout_5->setStretch(1, 5);

        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        groupBox = new QGroupBox(tabGeneral);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_22 = new QHBoxLayout(groupBox);
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        gridLayout_17 = new QGridLayout();
        gridLayout_17->setSpacing(6);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_17->addWidget(label_7, 0, 0, 1, 1);

        lPlasmaIG = new QLabel(groupBox);
        lPlasmaIG->setObjectName(QString::fromUtf8("lPlasmaIG"));
        lPlasmaIG->setFont(font1);
        lPlasmaIG->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(lPlasmaIG, 0, 1, 1, 1);

        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_17->addWidget(label_24, 1, 0, 1, 1);

        lShieldIG = new QLabel(groupBox);
        lShieldIG->setObjectName(QString::fromUtf8("lShieldIG"));
        lShieldIG->setFont(font1);
        lShieldIG->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_17->addWidget(lShieldIG, 1, 1, 1, 1);


        horizontalLayout_22->addLayout(gridLayout_17);


        verticalLayout_7->addWidget(groupBox);

        groupBox_4 = new QGroupBox(tabGeneral);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_23 = new QHBoxLayout(groupBox_4);
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        gridLayout_18 = new QGridLayout();
        gridLayout_18->setSpacing(6);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_18->addWidget(label_9, 0, 0, 1, 1);

        lPlasmaCutflow = new QLabel(groupBox_4);
        lPlasmaCutflow->setObjectName(QString::fromUtf8("lPlasmaCutflow"));
        lPlasmaCutflow->setFont(font1);
        lPlasmaCutflow->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_18->addWidget(lPlasmaCutflow, 0, 1, 1, 1);

        label_25 = new QLabel(groupBox_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_18->addWidget(label_25, 1, 0, 1, 1);

        label_26 = new QLabel(groupBox_4);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_18->addWidget(label_26, 2, 0, 1, 1);

        label_27 = new QLabel(groupBox_4);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_18->addWidget(label_27, 3, 0, 1, 1);

        lPlasmaPreflow = new QLabel(groupBox_4);
        lPlasmaPreflow->setObjectName(QString::fromUtf8("lPlasmaPreflow"));
        lPlasmaPreflow->setFont(font1);
        lPlasmaPreflow->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_18->addWidget(lPlasmaPreflow, 1, 1, 1, 1);

        label_49 = new QLabel(groupBox_4);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(label_49, 1, 2, 1, 1);

        lShieldCutflow = new QLabel(groupBox_4);
        lShieldCutflow->setObjectName(QString::fromUtf8("lShieldCutflow"));
        lShieldCutflow->setFont(font1);
        lShieldCutflow->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_18->addWidget(lShieldCutflow, 2, 1, 1, 1);

        label_51 = new QLabel(groupBox_4);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(label_51, 2, 2, 1, 1);

        lShieldPreflow = new QLabel(groupBox_4);
        lShieldPreflow->setObjectName(QString::fromUtf8("lShieldPreflow"));
        lShieldPreflow->setFont(font1);
        lShieldPreflow->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_18->addWidget(lShieldPreflow, 3, 1, 1, 1);

        label_53 = new QLabel(groupBox_4);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(label_53, 3, 2, 1, 1);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(label_11, 0, 2, 1, 1);


        horizontalLayout_23->addLayout(gridLayout_18);


        verticalLayout_7->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(tabGeneral);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        horizontalLayout_24 = new QHBoxLayout(groupBox_5);
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        gridLayout_19 = new QGridLayout();
        gridLayout_19->setSpacing(6);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_19->addWidget(label_12, 0, 0, 1, 1);

        lInletGas1 = new QLabel(groupBox_5);
        lInletGas1->setObjectName(QString::fromUtf8("lInletGas1"));
        lInletGas1->setFont(font1);
        lInletGas1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_19->addWidget(lInletGas1, 0, 1, 1, 1);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_19->addWidget(label_14, 0, 2, 1, 1);

        label_28 = new QLabel(groupBox_5);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_19->addWidget(label_28, 1, 0, 1, 1);

        label_29 = new QLabel(groupBox_5);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_19->addWidget(label_29, 2, 0, 1, 1);

        label_30 = new QLabel(groupBox_5);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_19->addWidget(label_30, 3, 0, 1, 1);

        lMixedGas1 = new QLabel(groupBox_5);
        lMixedGas1->setObjectName(QString::fromUtf8("lMixedGas1"));
        lMixedGas1->setFont(font1);
        lMixedGas1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_19->addWidget(lMixedGas1, 2, 1, 1, 1);

        label_54 = new QLabel(groupBox_5);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setAlignment(Qt::AlignCenter);

        gridLayout_19->addWidget(label_54, 1, 2, 1, 1);

        lInletGas2 = new QLabel(groupBox_5);
        lInletGas2->setObjectName(QString::fromUtf8("lInletGas2"));
        lInletGas2->setFont(font1);
        lInletGas2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_19->addWidget(lInletGas2, 1, 1, 1, 1);

        lMixedGas2 = new QLabel(groupBox_5);
        lMixedGas2->setObjectName(QString::fromUtf8("lMixedGas2"));
        lMixedGas2->setFont(font1);
        lMixedGas2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_19->addWidget(lMixedGas2, 3, 1, 1, 1);

        label_58 = new QLabel(groupBox_5);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setAlignment(Qt::AlignCenter);

        gridLayout_19->addWidget(label_58, 2, 2, 1, 1);

        label_59 = new QLabel(groupBox_5);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setAlignment(Qt::AlignCenter);

        gridLayout_19->addWidget(label_59, 3, 2, 1, 1);


        horizontalLayout_24->addLayout(gridLayout_19);


        verticalLayout_7->addWidget(groupBox_5);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(1, 2);
        verticalLayout_7->setStretch(2, 2);

        gridLayout->addLayout(verticalLayout_7, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        btUpdate = new QPushButton(tabGeneral);
        btUpdate->setObjectName(QString::fromUtf8("btUpdate"));
        btUpdate->setEnabled(true);
        QFont font2;
        font2.setPointSize(25);
        btUpdate->setFont(font2);

        horizontalLayout_19->addWidget(btUpdate);

        btClear = new QPushButton(tabGeneral);
        btClear->setObjectName(QString::fromUtf8("btClear"));
        btClear->setFont(font2);

        horizontalLayout_19->addWidget(btClear);

        btTestPreflow = new QPushButton(tabGeneral);
        btTestPreflow->setObjectName(QString::fromUtf8("btTestPreflow"));
        btTestPreflow->setFont(font2);

        horizontalLayout_19->addWidget(btTestPreflow);

        btTestCutflow = new QPushButton(tabGeneral);
        btTestCutflow->setObjectName(QString::fromUtf8("btTestCutflow"));
        btTestCutflow->setFont(font2);

        horizontalLayout_19->addWidget(btTestCutflow);

        btClose = new QPushButton(tabGeneral);
        btClose->setObjectName(QString::fromUtf8("btClose"));
        btClose->setFont(font2);

        horizontalLayout_19->addWidget(btClose);


        verticalLayout->addLayout(horizontalLayout_19);

        verticalLayout->setStretch(0, 8);
        verticalLayout->setStretch(1, 1);

        verticalLayout_3->addLayout(verticalLayout);

        tabConsole->addTab(tabGeneral, QString());
        tabAdd = new QWidget();
        tabAdd->setObjectName(QString::fromUtf8("tabAdd"));
        verticalLayout_4 = new QVBoxLayout(tabAdd);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 49, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 2);

        groupBox_8 = new QGroupBox(tabAdd);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_8);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_43 = new QLabel(groupBox_8);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_43, 0, 0, 1, 1);

        lChopperATemp = new QLabel(groupBox_8);
        lChopperATemp->setObjectName(QString::fromUtf8("lChopperATemp"));
        lChopperATemp->setFont(font1);
        lChopperATemp->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lChopperATemp, 0, 1, 1, 1);

        label_47 = new QLabel(groupBox_8);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_47, 0, 2, 1, 1);

        label_48 = new QLabel(groupBox_8);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_48, 1, 0, 1, 1);

        label_50 = new QLabel(groupBox_8);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_50, 2, 0, 1, 1);

        label_52 = new QLabel(groupBox_8);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_52, 3, 0, 1, 1);

        lChopperBTemp = new QLabel(groupBox_8);
        lChopperBTemp->setObjectName(QString::fromUtf8("lChopperBTemp"));
        lChopperBTemp->setFont(font1);
        lChopperBTemp->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lChopperBTemp, 1, 1, 1, 1);

        label_56 = new QLabel(groupBox_8);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_56, 1, 2, 1, 1);

        lChopperCTemp = new QLabel(groupBox_8);
        lChopperCTemp->setObjectName(QString::fromUtf8("lChopperCTemp"));
        lChopperCTemp->setFont(font1);
        lChopperCTemp->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lChopperCTemp, 2, 1, 1, 1);

        label_60 = new QLabel(groupBox_8);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_60, 2, 2, 1, 1);

        lChopperDTemp = new QLabel(groupBox_8);
        lChopperDTemp->setObjectName(QString::fromUtf8("lChopperDTemp"));
        lChopperDTemp->setFont(font1);
        lChopperDTemp->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lChopperDTemp, 3, 1, 1, 1);

        label_62 = new QLabel(groupBox_8);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_62, 3, 2, 1, 1);

        label_63 = new QLabel(groupBox_8);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_63, 4, 0, 1, 1);

        label_64 = new QLabel(groupBox_8);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        label_64->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_64, 5, 0, 1, 1);

        lCoolantTemp = new QLabel(groupBox_8);
        lCoolantTemp->setObjectName(QString::fromUtf8("lCoolantTemp"));
        lCoolantTemp->setFont(font1);
        lCoolantTemp->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lCoolantTemp, 4, 1, 1, 1);

        label_66 = new QLabel(groupBox_8);
        label_66->setObjectName(QString::fromUtf8("label_66"));
        label_66->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_66, 4, 2, 1, 1);

        lTransformerTemp = new QLabel(groupBox_8);
        lTransformerTemp->setObjectName(QString::fromUtf8("lTransformerTemp"));
        lTransformerTemp->setFont(font1);
        lTransformerTemp->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lTransformerTemp, 5, 1, 1, 1);

        label_68 = new QLabel(groupBox_8);
        label_68->setObjectName(QString::fromUtf8("label_68"));
        label_68->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_68, 5, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 6, 0, 1, 3);


        horizontalLayout_7->addLayout(gridLayout_4);


        gridLayout_2->addWidget(groupBox_8, 0, 1, 1, 1);

        groupBox_7 = new QGroupBox(tabAdd);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_7);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        labelGC = new QLabel(groupBox_7);
        labelGC->setObjectName(QString::fromUtf8("labelGC"));

        gridLayout_6->addWidget(labelGC, 0, 0, 1, 1);

        lPS_Rev = new QLabel(groupBox_7);
        lPS_Rev->setObjectName(QString::fromUtf8("lPS_Rev"));
        lPS_Rev->setFont(font1);
        lPS_Rev->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(lPS_Rev, 0, 1, 1, 1);

        lGC_Rev = new QLabel(groupBox_7);
        lGC_Rev->setObjectName(QString::fromUtf8("lGC_Rev"));
        lGC_Rev->setFont(font1);

        gridLayout_6->addWidget(lGC_Rev, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        label_5 = new QLabel(groupBox_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_5, 0, 2, 1, 1);

        gridLayout_6->setColumnStretch(0, 10);
        gridLayout_6->setColumnStretch(1, 3);
        gridLayout_6->setColumnStretch(2, 1);
        gridLayout_6->setColumnStretch(3, 3);
        gridLayout_6->setColumnStretch(4, 10);

        horizontalLayout_6->addLayout(gridLayout_6);


        gridLayout_2->addWidget(groupBox_7, 2, 0, 1, 2);

        groupBox_6 = new QGroupBox(tabAdd);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_6);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(groupBox_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        label_8 = new QLabel(groupBox_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_8, 0, 4, 1, 1);

        label_10 = new QLabel(groupBox_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_10, 1, 0, 1, 1);

        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_13, 2, 0, 1, 1);

        label_31 = new QLabel(groupBox_6);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_31, 3, 0, 1, 1);

        label_38 = new QLabel(groupBox_6);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_38, 1, 4, 1, 1);

        label_39 = new QLabel(groupBox_6);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_39, 2, 4, 1, 1);

        label_41 = new QLabel(groupBox_6);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_41, 3, 4, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 4, 0, 1, 5);

        lChA_SP = new QLabel(groupBox_6);
        lChA_SP->setObjectName(QString::fromUtf8("lChA_SP"));
        lChA_SP->setFont(font1);
        lChA_SP->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(lChA_SP, 0, 1, 1, 1);

        lChB_SP = new QLabel(groupBox_6);
        lChB_SP->setObjectName(QString::fromUtf8("lChB_SP"));
        lChB_SP->setFont(font1);
        lChB_SP->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(lChB_SP, 1, 1, 1, 1);

        lChB_Cur = new QLabel(groupBox_6);
        lChB_Cur->setObjectName(QString::fromUtf8("lChB_Cur"));
        lChB_Cur->setFont(font1);
        lChB_Cur->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(lChB_Cur, 1, 3, 1, 1);

        lChC_SP = new QLabel(groupBox_6);
        lChC_SP->setObjectName(QString::fromUtf8("lChC_SP"));
        lChC_SP->setFont(font1);
        lChC_SP->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(lChC_SP, 2, 1, 1, 1);

        lChC_Cur = new QLabel(groupBox_6);
        lChC_Cur->setObjectName(QString::fromUtf8("lChC_Cur"));
        lChC_Cur->setFont(font1);
        lChC_Cur->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(lChC_Cur, 2, 3, 1, 1);

        lChD_SP = new QLabel(groupBox_6);
        lChD_SP->setObjectName(QString::fromUtf8("lChD_SP"));
        lChD_SP->setFont(font1);
        lChD_SP->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(lChD_SP, 3, 1, 1, 1);

        lChD_Cur = new QLabel(groupBox_6);
        lChD_Cur->setObjectName(QString::fromUtf8("lChD_Cur"));
        lChD_Cur->setFont(font1);
        lChD_Cur->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(lChD_Cur, 3, 3, 1, 1);

        lChA_Cur = new QLabel(groupBox_6);
        lChA_Cur->setObjectName(QString::fromUtf8("lChA_Cur"));
        lChA_Cur->setFont(font1);
        lChA_Cur->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(lChA_Cur, 0, 3, 1, 1);

        label_67 = new QLabel(groupBox_6);
        label_67->setObjectName(QString::fromUtf8("label_67"));
        label_67->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_67, 1, 2, 1, 1);

        label_69 = new QLabel(groupBox_6);
        label_69->setObjectName(QString::fromUtf8("label_69"));
        label_69->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_69, 2, 2, 1, 1);

        label_70 = new QLabel(groupBox_6);
        label_70->setObjectName(QString::fromUtf8("label_70"));
        label_70->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_70, 3, 2, 1, 1);

        label_71 = new QLabel(groupBox_6);
        label_71->setObjectName(QString::fromUtf8("label_71"));
        label_71->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_71, 0, 2, 1, 1);

        gridLayout_3->setColumnStretch(0, 3);
        gridLayout_3->setColumnStretch(1, 2);
        gridLayout_3->setColumnStretch(2, 1);
        gridLayout_3->setColumnStretch(3, 2);
        gridLayout_3->setColumnStretch(4, 3);

        horizontalLayout_5->addLayout(gridLayout_3);


        gridLayout_2->addWidget(groupBox_6, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer = new QSpacerItem(760, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        btUpdateAdd = new QPushButton(tabAdd);
        btUpdateAdd->setObjectName(QString::fromUtf8("btUpdateAdd"));
        btUpdateAdd->setFont(font2);

        horizontalLayout_9->addWidget(btUpdateAdd);

        btCloseAdd = new QPushButton(tabAdd);
        btCloseAdd->setObjectName(QString::fromUtf8("btCloseAdd"));
        btCloseAdd->setFont(font2);

        horizontalLayout_9->addWidget(btCloseAdd);


        verticalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout_4->addLayout(verticalLayout_2);

        tabConsole->addTab(tabAdd, QString());

        horizontalLayout_8->addWidget(tabConsole);


        retranslateUi(QGasConsole);

        tabConsole->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QGasConsole);
    } // setupUi

    void retranslateUi(QDialog *QGasConsole)
    {
        QGasConsole->setWindowTitle(QApplication::translate("QGasConsole", "GasConsole", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("QGasConsole", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QGasConsole", "Line Voltage", 0, QApplication::UnicodeUTF8));
        lLineVoltage->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("QGasConsole", "V", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("QGasConsole", "Current setpont", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("QGasConsole", "Work Lead", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("QGasConsole", "Coolant Flow", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("QGasConsole", "PS State Code", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("QGasConsole", "Last Errors Codes", 0, QApplication::UnicodeUTF8));
        lCurSetPoint->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("QGasConsole", "Amps", 0, QApplication::UnicodeUTF8));
        lWorkLead->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("QGasConsole", "Amps", 0, QApplication::UnicodeUTF8));
        lCoolantFlow->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("QGasConsole", "GFM", 0, QApplication::UnicodeUTF8));
        lPSStateCode->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        lLastErrors->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("QGasConsole", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260 \320\262\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217 \320\264\321\203\320\263\320\270", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("QGasConsole", "Arc On Time", 0, QApplication::UnicodeUTF8));
        lArcOnTime->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("QGasConsole", "Seconds", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("QGasConsole", "Sys On Time", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("QGasConsole", "Tot Starts", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("QGasConsole", "Tot Start Errors", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("QGasConsole", "Tot Ramp Errors", 0, QApplication::UnicodeUTF8));
        lSysOnTime->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("QGasConsole", "Minutes", 0, QApplication::UnicodeUTF8));
        lTotStarts->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("QGasConsole", "Count", 0, QApplication::UnicodeUTF8));
        lTotErrors->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_44->setText(QApplication::translate("QGasConsole", "Count", 0, QApplication::UnicodeUTF8));
        lRampErrors->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_46->setText(QApplication::translate("QGasConsole", "Count", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("QGasConsole", "\320\223\320\260\320\267\321\213", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("QGasConsole", "Plasma Inlet Gas", 0, QApplication::UnicodeUTF8));
        lPlasmaIG->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("QGasConsole", "Shield Inlet Gas", 0, QApplication::UnicodeUTF8));
        lShieldIG->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("QGasConsole", "\320\224\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\263\320\260\320\267\320\276\320\262", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("QGasConsole", "Plasma Cutflow", 0, QApplication::UnicodeUTF8));
        lPlasmaCutflow->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("QGasConsole", "Plasma Prefow", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("QGasConsole", "Shield Cutflow", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("QGasConsole", "Shield Preflow", 0, QApplication::UnicodeUTF8));
        lPlasmaPreflow->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("QGasConsole", "PSI", 0, QApplication::UnicodeUTF8));
        lShieldCutflow->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_51->setText(QApplication::translate("QGasConsole", "PSI", 0, QApplication::UnicodeUTF8));
        lShieldPreflow->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_53->setText(QApplication::translate("QGasConsole", "PSI", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("QGasConsole", "PSI", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("QGasConsole", "\320\224\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\260\320\262\321\202\320\276\320\263\320\260\320\267\320\276\320\262", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("QGasConsole", "Inlet Cut Gas #1", 0, QApplication::UnicodeUTF8));
        lInletGas1->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("QGasConsole", "PSI", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("QGasConsole", "Inlet Cut Gas #2", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("QGasConsole", "Mixed Gas #1", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("QGasConsole", "Mixed Gas #2", 0, QApplication::UnicodeUTF8));
        lMixedGas1->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_54->setText(QApplication::translate("QGasConsole", "PSI", 0, QApplication::UnicodeUTF8));
        lInletGas2->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        lMixedGas2->setText(QApplication::translate("QGasConsole", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_58->setText(QApplication::translate("QGasConsole", "PSI", 0, QApplication::UnicodeUTF8));
        label_59->setText(QApplication::translate("QGasConsole", "PSI", 0, QApplication::UnicodeUTF8));
        btUpdate->setText(QApplication::translate("QGasConsole", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        btClear->setText(QApplication::translate("QGasConsole", "\320\241\320\261\321\200\320\276\321\201", 0, QApplication::UnicodeUTF8));
        btTestPreflow->setText(QApplication::translate("QGasConsole", "TestPreflow", 0, QApplication::UnicodeUTF8));
        btTestCutflow->setText(QApplication::translate("QGasConsole", "TestCutflow", 0, QApplication::UnicodeUTF8));
        btClose->setText(QApplication::translate("QGasConsole", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
        tabConsole->setTabText(tabConsole->indexOf(tabGeneral), QApplication::translate("QGasConsole", "\320\236\320\261\321\211\320\270\320\265", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("QGasConsole", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("QGasConsole", "Chopper A", 0, QApplication::UnicodeUTF8));
        lChopperATemp->setText(QString());
        label_47->setText(QApplication::translate("QGasConsole", "F 140/185", 0, QApplication::UnicodeUTF8));
        label_48->setText(QApplication::translate("QGasConsole", "Chopper B", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("QGasConsole", "Chopper C", 0, QApplication::UnicodeUTF8));
        label_52->setText(QApplication::translate("QGasConsole", "Chopper D", 0, QApplication::UnicodeUTF8));
        lChopperBTemp->setText(QString());
        label_56->setText(QApplication::translate("QGasConsole", "F 140/185", 0, QApplication::UnicodeUTF8));
        lChopperCTemp->setText(QString());
        label_60->setText(QApplication::translate("QGasConsole", "F 140/185", 0, QApplication::UnicodeUTF8));
        lChopperDTemp->setText(QString());
        label_62->setText(QApplication::translate("QGasConsole", "F 140/185", 0, QApplication::UnicodeUTF8));
        label_63->setText(QApplication::translate("QGasConsole", "Coolant", 0, QApplication::UnicodeUTF8));
        label_64->setText(QApplication::translate("QGasConsole", "Transformer", 0, QApplication::UnicodeUTF8));
        lCoolantTemp->setText(QString());
        label_66->setText(QApplication::translate("QGasConsole", "F 140/158", 0, QApplication::UnicodeUTF8));
        lTransformerTemp->setText(QString());
        label_68->setText(QApplication::translate("QGasConsole", "F 140/248", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("QGasConsole", "\320\240\320\265\320\262\320\270\320\267\320\270\321\217 \320\237\320\236", 0, QApplication::UnicodeUTF8));
        labelGC->setText(QApplication::translate("QGasConsole", "Power Supply Rev / Gas Console Rev", 0, QApplication::UnicodeUTF8));
        lPS_Rev->setText(QString());
        lGC_Rev->setText(QString());
        label_5->setText(QApplication::translate("QGasConsole", "/", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("QGasConsole", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QGasConsole", "Chopper A", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("QGasConsole", "Amps", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("QGasConsole", "Chopper B", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("QGasConsole", "Chopper C", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("QGasConsole", "Chopper D", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("QGasConsole", "Amps", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("QGasConsole", "Amps", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("QGasConsole", "Amps", 0, QApplication::UnicodeUTF8));
        lChA_SP->setText(QString());
        lChB_SP->setText(QString());
        lChB_Cur->setText(QString());
        lChC_SP->setText(QString());
        lChC_Cur->setText(QString());
        lChD_SP->setText(QString());
        lChD_Cur->setText(QString());
        lChA_Cur->setText(QString());
        label_67->setText(QApplication::translate("QGasConsole", "/", 0, QApplication::UnicodeUTF8));
        label_69->setText(QApplication::translate("QGasConsole", "/", 0, QApplication::UnicodeUTF8));
        label_70->setText(QApplication::translate("QGasConsole", "/", 0, QApplication::UnicodeUTF8));
        label_71->setText(QApplication::translate("QGasConsole", "/", 0, QApplication::UnicodeUTF8));
        btUpdateAdd->setText(QApplication::translate("QGasConsole", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        btCloseAdd->setText(QApplication::translate("QGasConsole", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
        tabConsole->setTabText(tabConsole->indexOf(tabAdd), QApplication::translate("QGasConsole", "\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QGasConsole: public Ui_QGasConsole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGASCONSOLE_H
