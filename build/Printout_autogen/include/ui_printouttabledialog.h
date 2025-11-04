/********************************************************************************
** Form generated from reading UI file 'printouttabledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTOUTTABLEDIALOG_H
#define UI_PRINTOUTTABLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrintoutTableDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *onceDateFilterLbl;
    QDateEdit *onceDateFilterFld;
    QPushButton *onceDateFilterApplyBtn;
    QLabel *seriesFilterLbl;
    QLineEdit *seriesFilterFld;
    QPushButton *seriesFilterApplyBtn;
    QLabel *numberFilterLbl;
    QLineEdit *numberFilterFld;
    QLabel *dateRangeFilterLbl;
    QDateEdit *firstDateFilterFld;
    QDateEdit *secondDateFilterFld;
    QPushButton *dateRangeFilterApplyBtn;
    QLabel *sectionFilterLbl;
    QLineEdit *sectionFilterFld;
    QPushButton *sectionFilterApplyBtn;
    QPushButton *cancelLastFilterBtn;
    QHBoxLayout *horizontalLayout;
    QTableView *table;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PrintoutTableDialog)
    {
        if (PrintoutTableDialog->objectName().isEmpty())
            PrintoutTableDialog->setObjectName(QString::fromUtf8("PrintoutTableDialog"));
        PrintoutTableDialog->resize(1323, 467);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PrintoutTableDialog->sizePolicy().hasHeightForWidth());
        PrintoutTableDialog->setSizePolicy(sizePolicy);
        PrintoutTableDialog->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(12);
        PrintoutTableDialog->setFont(font);
        PrintoutTableDialog->setSizeGripEnabled(false);
        verticalLayoutWidget = new QWidget(PrintoutTableDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 1302, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        onceDateFilterLbl = new QLabel(verticalLayoutWidget);
        onceDateFilterLbl->setObjectName(QString::fromUtf8("onceDateFilterLbl"));
        onceDateFilterLbl->setFont(font);

        horizontalLayout_2->addWidget(onceDateFilterLbl);

        onceDateFilterFld = new QDateEdit(verticalLayoutWidget);
        onceDateFilterFld->setObjectName(QString::fromUtf8("onceDateFilterFld"));
        onceDateFilterFld->setFont(font);

        horizontalLayout_2->addWidget(onceDateFilterFld);

        onceDateFilterApplyBtn = new QPushButton(verticalLayoutWidget);
        onceDateFilterApplyBtn->setObjectName(QString::fromUtf8("onceDateFilterApplyBtn"));
        onceDateFilterApplyBtn->setFont(font);

        horizontalLayout_2->addWidget(onceDateFilterApplyBtn);

        seriesFilterLbl = new QLabel(verticalLayoutWidget);
        seriesFilterLbl->setObjectName(QString::fromUtf8("seriesFilterLbl"));
        seriesFilterLbl->setFont(font);

        horizontalLayout_2->addWidget(seriesFilterLbl);

        seriesFilterFld = new QLineEdit(verticalLayoutWidget);
        seriesFilterFld->setObjectName(QString::fromUtf8("seriesFilterFld"));
        seriesFilterFld->setFont(font);

        horizontalLayout_2->addWidget(seriesFilterFld);

        seriesFilterApplyBtn = new QPushButton(verticalLayoutWidget);
        seriesFilterApplyBtn->setObjectName(QString::fromUtf8("seriesFilterApplyBtn"));
        seriesFilterApplyBtn->setFont(font);

        horizontalLayout_2->addWidget(seriesFilterApplyBtn);

        numberFilterLbl = new QLabel(verticalLayoutWidget);
        numberFilterLbl->setObjectName(QString::fromUtf8("numberFilterLbl"));
        numberFilterLbl->setFont(font);

        horizontalLayout_2->addWidget(numberFilterLbl);

        numberFilterFld = new QLineEdit(verticalLayoutWidget);
        numberFilterFld->setObjectName(QString::fromUtf8("numberFilterFld"));
        numberFilterFld->setFont(font);

        horizontalLayout_2->addWidget(numberFilterFld);

        dateRangeFilterLbl = new QLabel(verticalLayoutWidget);
        dateRangeFilterLbl->setObjectName(QString::fromUtf8("dateRangeFilterLbl"));
        dateRangeFilterLbl->setFont(font);

        horizontalLayout_2->addWidget(dateRangeFilterLbl);

        firstDateFilterFld = new QDateEdit(verticalLayoutWidget);
        firstDateFilterFld->setObjectName(QString::fromUtf8("firstDateFilterFld"));
        firstDateFilterFld->setFont(font);

        horizontalLayout_2->addWidget(firstDateFilterFld);

        secondDateFilterFld = new QDateEdit(verticalLayoutWidget);
        secondDateFilterFld->setObjectName(QString::fromUtf8("secondDateFilterFld"));
        secondDateFilterFld->setFont(font);

        horizontalLayout_2->addWidget(secondDateFilterFld);

        dateRangeFilterApplyBtn = new QPushButton(verticalLayoutWidget);
        dateRangeFilterApplyBtn->setObjectName(QString::fromUtf8("dateRangeFilterApplyBtn"));
        dateRangeFilterApplyBtn->setFont(font);

        horizontalLayout_2->addWidget(dateRangeFilterApplyBtn);

        sectionFilterLbl = new QLabel(verticalLayoutWidget);
        sectionFilterLbl->setObjectName(QString::fromUtf8("sectionFilterLbl"));
        sectionFilterLbl->setFont(font);

        horizontalLayout_2->addWidget(sectionFilterLbl);

        sectionFilterFld = new QLineEdit(verticalLayoutWidget);
        sectionFilterFld->setObjectName(QString::fromUtf8("sectionFilterFld"));
        sectionFilterFld->setFont(font);

        horizontalLayout_2->addWidget(sectionFilterFld);

        sectionFilterApplyBtn = new QPushButton(verticalLayoutWidget);
        sectionFilterApplyBtn->setObjectName(QString::fromUtf8("sectionFilterApplyBtn"));
        sectionFilterApplyBtn->setFont(font);

        horizontalLayout_2->addWidget(sectionFilterApplyBtn);

        cancelLastFilterBtn = new QPushButton(verticalLayoutWidget);
        cancelLastFilterBtn->setObjectName(QString::fromUtf8("cancelLastFilterBtn"));
        cancelLastFilterBtn->setFont(font);

        horizontalLayout_2->addWidget(cancelLastFilterBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        table = new QTableView(verticalLayoutWidget);
        table->setObjectName(QString::fromUtf8("table"));
        table->setFont(font);

        horizontalLayout->addWidget(table);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(PrintoutTableDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PrintoutTableDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PrintoutTableDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PrintoutTableDialog);
    } // setupUi

    void retranslateUi(QDialog *PrintoutTableDialog)
    {
        PrintoutTableDialog->setWindowTitle(QCoreApplication::translate("PrintoutTableDialog", "Fill from table", nullptr));
        onceDateFilterLbl->setText(QCoreApplication::translate("PrintoutTableDialog", "Once date:", nullptr));
        onceDateFilterApplyBtn->setText(QCoreApplication::translate("PrintoutTableDialog", "Apply", nullptr));
        seriesFilterLbl->setText(QCoreApplication::translate("PrintoutTableDialog", "Series:", nullptr));
        seriesFilterApplyBtn->setText(QCoreApplication::translate("PrintoutTableDialog", "Apply", nullptr));
        numberFilterLbl->setText(QCoreApplication::translate("PrintoutTableDialog", "Number:", nullptr));
        dateRangeFilterLbl->setText(QCoreApplication::translate("PrintoutTableDialog", "Date range:", nullptr));
        dateRangeFilterApplyBtn->setText(QCoreApplication::translate("PrintoutTableDialog", "Apply", nullptr));
        sectionFilterLbl->setText(QCoreApplication::translate("PrintoutTableDialog", "Section:", nullptr));
        sectionFilterApplyBtn->setText(QCoreApplication::translate("PrintoutTableDialog", "Apply", nullptr));
        cancelLastFilterBtn->setText(QCoreApplication::translate("PrintoutTableDialog", "Cancel the last filter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrintoutTableDialog: public Ui_PrintoutTableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTOUTTABLEDIALOG_H
