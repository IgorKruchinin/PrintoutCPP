#include "printouttabledialog.h"
#include "ui_printouttabledialog.h"
#include <QTableView>
#include <QTableWidget>
#include <QStandardItemModel>
#include "api/Record.h"
#include "api/Definitions.h"
#include <memory>

PrintoutTableDialog::PrintoutTableDialog(QWidget *parent, IPrintout *backend, Record *record)
    : QDialog(parent), backend(backend), record(record)
    , ui(new Ui::PrintoutTableDialog)
{
    ui->setupUi(this);
    showMaximized();

    QTableView *table = ui->table;
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableModel = new QStandardItemModel();
    table->setModel(tableModel);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(table, &QAbstractItemView::clicked, this, &PrintoutTableDialog::rowClicked);
    ui->onceDateFilterFld->setCalendarPopup(true);
    ui->onceDateFilterFld->setDate(QDate::currentDate());
    ui->firstDateFilterFld->setCalendarPopup(true);
    ui->firstDateFilterFld->setDate(QDate::currentDate());
    ui->secondDateFilterFld->setCalendarPopup(true);
    ui->secondDateFilterFld->setDate(QDate::currentDate());
    setLayout(ui->verticalLayout);
    loadFromBackend();
}

void PrintoutTableDialog::loadFromBackend() {
    if (backend != nullptr) {
        records = backend->getRecords();
        for (int i = 0; i < records->size(); ++i) {
            tableModel->setItem(i, 0, new QStandardItem(QString::number(records->at(i).getID())));
            tableModel->setItem(i, 1, new QStandardItem(QDate::fromString(QString::fromStdString(records->at(i).getDate()), DATE_FORMAT_STRING).toString(DATE_FORMAT_VIEW_STRING)));
            tableModel->setItem(i, 2, new QStandardItem(QString::fromStdString(records->at(i).getSeries())));
            tableModel->setItem(i, 3, new QStandardItem(QString::number(records->at(i).getNumber())));
            tableModel->setItem(i, 4, new QStandardItem(QString::fromStdString(records->at(i).getSection())));
            tableModel->setItem(i, 5, new QStandardItem(QString::fromStdString(records->at(i).getRepair())));
            tableModel->setItem(i, 6, new QStandardItem(QString::fromStdString(records->at(i).getTestType())));
            tableModel->setItem(i, 7, new QStandardItem(QString::fromStdString(records->at(i).getNormalPower())));
            tableModel->setItem(i, 8, new QStandardItem(QString::fromStdString(records->at(i).getEmergencyPower())));
            tableModel->setItem(i, 9, new QStandardItem(QString::fromStdString(records->at(i).getVSH1())));
            tableModel->setItem(i, 10, new QStandardItem(QString::fromStdString(records->at(i).getVSH2())));
            tableModel->setItem(i, 11, new QStandardItem(QString::fromStdString(records->at(i).getSupercharging())));
            tableModel->setItem(i, 12, new QStandardItem(QString::fromStdString(records->at(i).getTime())));
            tableModel->setItem(i, 13, new QStandardItem(QString::fromStdString(records->at(i).getNotes())));
            tableModel->setItem(i, 14, new QStandardItem(QString::fromStdString(records->at(i).getMaster())));
        }
    }
    tableModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    tableModel->setHeaderData(1, Qt::Horizontal, tr("Date"));
    tableModel->setHeaderData(2, Qt::Horizontal, tr("Series"));
    tableModel->setHeaderData(3, Qt::Horizontal, tr("Number"));
    tableModel->setHeaderData(4, Qt::Horizontal, tr("Section"));
    tableModel->setHeaderData(5, Qt::Horizontal, tr("Repair"));
    tableModel->setHeaderData(6, Qt::Horizontal, tr("Tests type"));
    tableModel->setHeaderData(7, Qt::Horizontal, tr("Normal mode power"));
    tableModel->setHeaderData(8, Qt::Horizontal, tr("Emergency mode power"));
    tableModel->setHeaderData(9, Qt::Horizontal, tr("VSH1"));
    tableModel->setHeaderData(10, Qt::Horizontal, tr("VSH2"));
    tableModel->setHeaderData(11, Qt::Horizontal, tr("Supercharging"));
    tableModel->setHeaderData(12, Qt::Horizontal, tr("Time"));
    tableModel->setHeaderData(13, Qt::Horizontal, tr("Notes"));
    tableModel->setHeaderData(14, Qt::Horizontal, tr("Master"));
}

void PrintoutTableDialog::rowClicked(const QModelIndex index) {
    *(this->record) = records->at(index.row());
}

PrintoutTableDialog::~PrintoutTableDialog()
{
    delete tableModel;
    delete ui;
}
