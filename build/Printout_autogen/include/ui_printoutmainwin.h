/********************************************************************************
** Form generated from reading UI file 'printoutmainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTOUTMAINWIN_H
#define UI_PRINTOUTMAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrintoutMainWin
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *openBtn;
    QPushButton *excelExportBtn;
    QPushButton *fillIntoTableBtn;
    QHBoxLayout *horizontalLayout_6;
    QLabel *rheostaticTestsLbl;
    QHBoxLayout *horizontalLayout_7;
    QLabel *dateLbl;
    QDateEdit *dateFld;
    QLabel *seriesLbl;
    QLineEdit *seriesFld;
    QLabel *numberLbl;
    QLineEdit *numberFld;
    QLabel *sectionLbl;
    QLineEdit *sectionFld;
    QLabel *repairLbl;
    QLineEdit *repairFld;
    QHBoxLayout *horizontalLayout_8;
    QLabel *testsTypeLbl;
    QLineEdit *testsTypeFld;
    QHBoxLayout *horizontalLayout_9;
    QLabel *normalPowerLbl;
    QLineEdit *normalPowerFld;
    QLabel *vsh1Lbl;
    QLineEdit *vsh1Fld;
    QLabel *superchargingLbl;
    QLineEdit *superchargingFld;
    QHBoxLayout *horizontalLayout_11;
    QLabel *emergencyPowerLbl;
    QLineEdit *emergencyPowerFld;
    QLabel *vsh2Lbl;
    QLineEdit *vsh2Fld;
    QLabel *timeLbl;
    QLineEdit *timeFld;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_2;
    QLabel *fuelConsuptionLbl;
    QLineEdit *fuelConsuptionFld;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_13;
    QLabel *notesLbl;
    QTextEdit *notesFld;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_4;
    QLabel *masterLbl;
    QLineEdit *masterFld;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *clearBtn;
    QPushButton *saveBtn;
    QPushButton *printBtn;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *showPrintDialogCheck;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PrintoutMainWin)
    {
        if (PrintoutMainWin->objectName().isEmpty())
            PrintoutMainWin->setObjectName(QString::fromUtf8("PrintoutMainWin"));
        PrintoutMainWin->resize(837, 488);
        centralwidget = new QWidget(PrintoutMainWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        centralwidget->setFont(font);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 811, 429));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        openBtn = new QPushButton(verticalLayoutWidget);
        openBtn->setObjectName(QString::fromUtf8("openBtn"));
        openBtn->setFont(font);

        horizontalLayout->addWidget(openBtn);

        excelExportBtn = new QPushButton(verticalLayoutWidget);
        excelExportBtn->setObjectName(QString::fromUtf8("excelExportBtn"));
        excelExportBtn->setFont(font);

        horizontalLayout->addWidget(excelExportBtn);

        fillIntoTableBtn = new QPushButton(verticalLayoutWidget);
        fillIntoTableBtn->setObjectName(QString::fromUtf8("fillIntoTableBtn"));
        fillIntoTableBtn->setFont(font);

        horizontalLayout->addWidget(fillIntoTableBtn);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        rheostaticTestsLbl = new QLabel(verticalLayoutWidget);
        rheostaticTestsLbl->setObjectName(QString::fromUtf8("rheostaticTestsLbl"));
        QFont font1;
        font1.setPointSize(28);
        font1.setBold(true);
        rheostaticTestsLbl->setFont(font1);
        rheostaticTestsLbl->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_6->addWidget(rheostaticTestsLbl);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        dateLbl = new QLabel(verticalLayoutWidget);
        dateLbl->setObjectName(QString::fromUtf8("dateLbl"));
        dateLbl->setFont(font);

        horizontalLayout_7->addWidget(dateLbl);

        dateFld = new QDateEdit(verticalLayoutWidget);
        dateFld->setObjectName(QString::fromUtf8("dateFld"));
        dateFld->setFont(font);

        horizontalLayout_7->addWidget(dateFld);

        seriesLbl = new QLabel(verticalLayoutWidget);
        seriesLbl->setObjectName(QString::fromUtf8("seriesLbl"));
        seriesLbl->setFont(font);

        horizontalLayout_7->addWidget(seriesLbl);

        seriesFld = new QLineEdit(verticalLayoutWidget);
        seriesFld->setObjectName(QString::fromUtf8("seriesFld"));
        seriesFld->setFont(font);

        horizontalLayout_7->addWidget(seriesFld);

        numberLbl = new QLabel(verticalLayoutWidget);
        numberLbl->setObjectName(QString::fromUtf8("numberLbl"));
        numberLbl->setFont(font);

        horizontalLayout_7->addWidget(numberLbl);

        numberFld = new QLineEdit(verticalLayoutWidget);
        numberFld->setObjectName(QString::fromUtf8("numberFld"));
        numberFld->setFont(font);

        horizontalLayout_7->addWidget(numberFld);

        sectionLbl = new QLabel(verticalLayoutWidget);
        sectionLbl->setObjectName(QString::fromUtf8("sectionLbl"));
        sectionLbl->setFont(font);

        horizontalLayout_7->addWidget(sectionLbl);

        sectionFld = new QLineEdit(verticalLayoutWidget);
        sectionFld->setObjectName(QString::fromUtf8("sectionFld"));
        sectionFld->setFont(font);

        horizontalLayout_7->addWidget(sectionFld);

        repairLbl = new QLabel(verticalLayoutWidget);
        repairLbl->setObjectName(QString::fromUtf8("repairLbl"));
        repairLbl->setFont(font);

        horizontalLayout_7->addWidget(repairLbl);

        repairFld = new QLineEdit(verticalLayoutWidget);
        repairFld->setObjectName(QString::fromUtf8("repairFld"));
        repairFld->setFont(font);

        horizontalLayout_7->addWidget(repairFld);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        testsTypeLbl = new QLabel(verticalLayoutWidget);
        testsTypeLbl->setObjectName(QString::fromUtf8("testsTypeLbl"));
        testsTypeLbl->setFont(font);

        horizontalLayout_8->addWidget(testsTypeLbl);

        testsTypeFld = new QLineEdit(verticalLayoutWidget);
        testsTypeFld->setObjectName(QString::fromUtf8("testsTypeFld"));
        testsTypeFld->setFont(font);

        horizontalLayout_8->addWidget(testsTypeFld);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        normalPowerLbl = new QLabel(verticalLayoutWidget);
        normalPowerLbl->setObjectName(QString::fromUtf8("normalPowerLbl"));
        normalPowerLbl->setFont(font);

        horizontalLayout_9->addWidget(normalPowerLbl);

        normalPowerFld = new QLineEdit(verticalLayoutWidget);
        normalPowerFld->setObjectName(QString::fromUtf8("normalPowerFld"));
        normalPowerFld->setFont(font);

        horizontalLayout_9->addWidget(normalPowerFld);

        vsh1Lbl = new QLabel(verticalLayoutWidget);
        vsh1Lbl->setObjectName(QString::fromUtf8("vsh1Lbl"));
        vsh1Lbl->setFont(font);

        horizontalLayout_9->addWidget(vsh1Lbl);

        vsh1Fld = new QLineEdit(verticalLayoutWidget);
        vsh1Fld->setObjectName(QString::fromUtf8("vsh1Fld"));
        vsh1Fld->setFont(font);

        horizontalLayout_9->addWidget(vsh1Fld);

        superchargingLbl = new QLabel(verticalLayoutWidget);
        superchargingLbl->setObjectName(QString::fromUtf8("superchargingLbl"));
        superchargingLbl->setFont(font);

        horizontalLayout_9->addWidget(superchargingLbl);

        superchargingFld = new QLineEdit(verticalLayoutWidget);
        superchargingFld->setObjectName(QString::fromUtf8("superchargingFld"));
        superchargingFld->setFont(font);

        horizontalLayout_9->addWidget(superchargingFld);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        emergencyPowerLbl = new QLabel(verticalLayoutWidget);
        emergencyPowerLbl->setObjectName(QString::fromUtf8("emergencyPowerLbl"));
        emergencyPowerLbl->setFont(font);

        horizontalLayout_11->addWidget(emergencyPowerLbl);

        emergencyPowerFld = new QLineEdit(verticalLayoutWidget);
        emergencyPowerFld->setObjectName(QString::fromUtf8("emergencyPowerFld"));
        emergencyPowerFld->setFont(font);

        horizontalLayout_11->addWidget(emergencyPowerFld);

        vsh2Lbl = new QLabel(verticalLayoutWidget);
        vsh2Lbl->setObjectName(QString::fromUtf8("vsh2Lbl"));
        vsh2Lbl->setFont(font);

        horizontalLayout_11->addWidget(vsh2Lbl);

        vsh2Fld = new QLineEdit(verticalLayoutWidget);
        vsh2Fld->setObjectName(QString::fromUtf8("vsh2Fld"));
        vsh2Fld->setFont(font);

        horizontalLayout_11->addWidget(vsh2Fld);

        timeLbl = new QLabel(verticalLayoutWidget);
        timeLbl->setObjectName(QString::fromUtf8("timeLbl"));
        timeLbl->setFont(font);

        horizontalLayout_11->addWidget(timeLbl);

        timeFld = new QLineEdit(verticalLayoutWidget);
        timeFld->setObjectName(QString::fromUtf8("timeFld"));
        timeFld->setFont(font);

        horizontalLayout_11->addWidget(timeFld);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_2);

        fuelConsuptionLbl = new QLabel(verticalLayoutWidget);
        fuelConsuptionLbl->setObjectName(QString::fromUtf8("fuelConsuptionLbl"));
        fuelConsuptionLbl->setFont(font);

        horizontalLayout_12->addWidget(fuelConsuptionLbl);

        fuelConsuptionFld = new QLineEdit(verticalLayoutWidget);
        fuelConsuptionFld->setObjectName(QString::fromUtf8("fuelConsuptionFld"));
        fuelConsuptionFld->setFont(font);

        horizontalLayout_12->addWidget(fuelConsuptionFld);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        notesLbl = new QLabel(verticalLayoutWidget);
        notesLbl->setObjectName(QString::fromUtf8("notesLbl"));
        notesLbl->setFont(font);

        horizontalLayout_13->addWidget(notesLbl);

        notesFld = new QTextEdit(verticalLayoutWidget);
        notesFld->setObjectName(QString::fromUtf8("notesFld"));
        notesFld->setFont(font);

        horizontalLayout_13->addWidget(notesFld);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_4);

        masterLbl = new QLabel(verticalLayoutWidget);
        masterLbl->setObjectName(QString::fromUtf8("masterLbl"));
        masterLbl->setFont(font);

        horizontalLayout_14->addWidget(masterLbl);

        masterFld = new QLineEdit(verticalLayoutWidget);
        masterFld->setObjectName(QString::fromUtf8("masterFld"));
        masterFld->setFont(font);

        horizontalLayout_14->addWidget(masterFld);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        clearBtn = new QPushButton(verticalLayoutWidget);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));
        clearBtn->setFont(font);

        horizontalLayout_15->addWidget(clearBtn);

        saveBtn = new QPushButton(verticalLayoutWidget);
        saveBtn->setObjectName(QString::fromUtf8("saveBtn"));
        saveBtn->setFont(font);

        horizontalLayout_15->addWidget(saveBtn);

        printBtn = new QPushButton(verticalLayoutWidget);
        printBtn->setObjectName(QString::fromUtf8("printBtn"));
        printBtn->setFont(font);

        horizontalLayout_15->addWidget(printBtn);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        showPrintDialogCheck = new QCheckBox(verticalLayoutWidget);
        showPrintDialogCheck->setObjectName(QString::fromUtf8("showPrintDialogCheck"));
        showPrintDialogCheck->setTristate(false);

        horizontalLayout_2->addWidget(showPrintDialogCheck);


        verticalLayout->addLayout(horizontalLayout_2);

        PrintoutMainWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PrintoutMainWin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 837, 19));
        PrintoutMainWin->setMenuBar(menubar);
        statusbar = new QStatusBar(PrintoutMainWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PrintoutMainWin->setStatusBar(statusbar);

        retranslateUi(PrintoutMainWin);

        QMetaObject::connectSlotsByName(PrintoutMainWin);
    } // setupUi

    void retranslateUi(QMainWindow *PrintoutMainWin)
    {
        PrintoutMainWin->setWindowTitle(QCoreApplication::translate("PrintoutMainWin", "PrintoutMainWin", nullptr));
        openBtn->setText(QCoreApplication::translate("PrintoutMainWin", "Open Excel file", nullptr));
        excelExportBtn->setText(QCoreApplication::translate("PrintoutMainWin", "Export to Excel", nullptr));
        fillIntoTableBtn->setText(QCoreApplication::translate("PrintoutMainWin", "Fill into table", nullptr));
        rheostaticTestsLbl->setText(QCoreApplication::translate("PrintoutMainWin", "Rheostatic Tests", nullptr));
        dateLbl->setText(QCoreApplication::translate("PrintoutMainWin", "Date:", nullptr));
        seriesLbl->setText(QCoreApplication::translate("PrintoutMainWin", "Series:", nullptr));
        numberLbl->setText(QCoreApplication::translate("PrintoutMainWin", "Number:", nullptr));
        numberFld->setInputMask(QString());
        sectionLbl->setText(QCoreApplication::translate("PrintoutMainWin", "Section:", nullptr));
        repairLbl->setText(QCoreApplication::translate("PrintoutMainWin", "Repair:", nullptr));
        testsTypeLbl->setText(QCoreApplication::translate("PrintoutMainWin", "Tests type:", nullptr));
        normalPowerLbl->setText(QCoreApplication::translate("PrintoutMainWin", "Power NM:", nullptr));
        vsh1Lbl->setText(QCoreApplication::translate("PrintoutMainWin", "VSH1 on/off:", nullptr));
        superchargingLbl->setText(QCoreApplication::translate("PrintoutMainWin", "Supercharging, atm:", nullptr));
        emergencyPowerLbl->setText(QCoreApplication::translate("PrintoutMainWin", "Power EM:", nullptr));
        vsh2Lbl->setText(QCoreApplication::translate("PrintoutMainWin", "VSH2 on/off:", nullptr));
        timeLbl->setText(QCoreApplication::translate("PrintoutMainWin", "Time, h:", nullptr));
        fuelConsuptionLbl->setText(QCoreApplication::translate("PrintoutMainWin", "Fuel consuption, l:", nullptr));
        notesLbl->setText(QCoreApplication::translate("PrintoutMainWin", "Notes:", nullptr));
        masterLbl->setText(QCoreApplication::translate("PrintoutMainWin", "Master r/t:", nullptr));
        clearBtn->setText(QCoreApplication::translate("PrintoutMainWin", "Clear", nullptr));
        saveBtn->setText(QCoreApplication::translate("PrintoutMainWin", "Save", nullptr));
        printBtn->setText(QCoreApplication::translate("PrintoutMainWin", "Print", nullptr));
        showPrintDialogCheck->setText(QCoreApplication::translate("PrintoutMainWin", "Show print dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrintoutMainWin: public Ui_PrintoutMainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTOUTMAINWIN_H
