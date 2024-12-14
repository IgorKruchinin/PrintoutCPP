#include "printoutmainwin.h"
#include "printouttabledialog.h"
#include "printQt.h"
#include "ui_printoutmainwin.h"
#include "api/Record.h"
#include "api/Definitions.h"
#include "api/Printout.h"
#include "excelmanager.h"
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QString>
#include <QCalendarWidget>
#include <memory>

PrintoutMainWin::PrintoutMainWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PrintoutMainWin)
{
    TableStructure ts(tr("Date").toStdString(), tr("Series").toStdString(), tr("Number").toStdString(), tr("Section").toStdString(), tr("Repair").toStdString(), tr("Tests type").toStdString(), tr("Power NM").toStdString(), tr("Power EM").toStdString(), tr("VSH1").toStdString(), tr("VSH2").toStdString(), tr("Supercharging").toStdString(), tr("Time").toStdString(), tr("Fuel consuption").toStdString(), tr("Notes").toStdString(), tr("Master").toStdString());
    backend = new Printout(ts, PrintQt{}, "records");
    ui->setupUi(this);
    setCentralWidget(ui->verticalLayout->parentWidget());
    ui->numberFld->setValidator(new QIntValidator(0, 999999999, this));
    ui->dateFld->setCalendarPopup(true);
    ui->dateFld->setDate(QDate::currentDate());
}

PrintoutMainWin::~PrintoutMainWin()
{
    delete ui;
    delete backend;
}

void PrintoutMainWin::on_printBtn_clicked()
{
    Record record = makeRecord();
    bool showPrintDialog = ui->showPrintDialogCheck->isChecked();
    backend->print(record, showPrintDialog);

}


void PrintoutMainWin::on_clearBtn_clicked()
{
    resetAllFields();
}

void PrintoutMainWin::resetAllFields() {
    ui->dateFld->setDate(QDate::currentDate());
    ui->seriesFld->clear();
    ui->numberFld->clear();
    ui->sectionFld->clear();
    ui->repairFld->clear();
    ui->testsTypeFld->clear();
    ui->normalPowerFld->clear();
    ui->emergencyPowerFld->clear();
    ui->vsh1Fld->clear();
    ui->vsh2Fld->clear();
    ui->superchargingFld->clear();
    ui->timeFld->clear();
    ui->fuelConsuptionFld->clear();
    ui->notesFld->clear();
    ui->masterFld->clear();
}

const Record PrintoutMainWin::makeRecord() const {
    QDate qdate = ui->dateFld->date();
    Date date = qdate.toString(DATE_FORMAT_STRING).toStdString();

    String series = ui->seriesFld->text().toStdString();
    Int number = ui->numberFld->text().toInt();
    String section = ui->sectionFld->text().toStdString();
    String repair = ui->repairFld->text().toStdString();
    String testsType = ui->testsTypeFld->text().toStdString();
    String normalPower = ui->normalPowerFld->text().toStdString();
    String emergencyPower = ui->emergencyPowerFld->text().toStdString();
    String vsh1 = ui->vsh1Fld->text().toStdString();
    String vsh2 = ui->vsh2Fld->text().toStdString();
    String supercharging = ui->superchargingFld->text().toStdString();
    String time = ui->timeFld->text().toStdString();
    String fuelConsumption = ui->fuelConsuptionFld->text().toStdString();
    String notes = ui->notesFld->toPlainText().toStdString();
    String master = ui->masterFld->text().toStdString();

    return Record(date, series, number, section, repair, testsType, normalPower, emergencyPower, vsh1, vsh2, supercharging, time, fuelConsumption, notes, master);
}

void PrintoutMainWin::on_fillIntoTableBtn_clicked()
{
    fillIntoTable();
}

void PrintoutMainWin::fillIntoTable() {
    Record *record = new Record();
    PrintoutTableDialog fillDialog(this, backend, record);
    if (fillDialog.exec() != QDialog::Accepted) {
        return;
    }
    fillFieldsFromRecord(record);
}

void PrintoutMainWin::fillFieldsFromRecord(const IRecord *record) {
    if (record != nullptr) {
        ui->dateFld->setDate(QDate::fromString(QString::fromStdString(record->getDate()), DATE_FORMAT_STRING));
        ui->seriesFld->setText(QString::fromStdString(record->getSeries()));
        ui->numberFld->setText(QString::number(record->getNumber()));
        ui->sectionFld->setText(QString::fromStdString(record->getSection()));
        ui->repairFld->setText(QString::fromStdString(record->getRepair()));
        ui->testsTypeFld->setText(QString::fromStdString(record->getTestType()));
        ui->normalPowerFld->setText(QString::fromStdString(record->getNormalPower()));
        ui->emergencyPowerFld->setText(QString::fromStdString(record->getEmergencyPower()));
        ui->vsh1Fld->setText(QString::fromStdString(record->getVSH1()));
        ui->vsh2Fld->setText(QString::fromStdString(record->getVSH2()));
        ui->superchargingFld->setText(QString::fromStdString(record->getSupercharging()));
        ui->timeFld->setText(QString::fromStdString(record->getTime()));
        ui->fuelConsuptionFld->setText(QString::fromStdString(record->getFuelConsuption()));
        ui->notesFld->setText(QString::fromStdString(record->getNotes()));
        ui->masterFld->setText(QString::fromStdString(record->getMaster()));
    }
}

void PrintoutMainWin::on_openBtn_clicked()
{
    QString excelImportFileName = QFileDialog::getOpenFileName(this, tr("Excel file"), "", tr("Excel files (*.xls *.xlsx *.csv)"));
    //delete backend;
    //TableStructure ts(tr("Date").toStdString(), tr("Series").toStdString(), tr("Number").toStdString(), tr("Section").toStdString(), tr("Repair").toStdString(), tr("Tests type").toStdString(), tr("Power NM").toStdString(), tr("Power EM").toStdString(), tr("VSH1").toStdString(), tr("VSH2").toStdString(), tr("Supercharging").toStdString(), tr("Time").toStdString(), tr("Fuel consuption").toStdString(), tr("Notes").toStdString(), tr("Master").toStdString());
    //backend = new Printout(ts, PrintQt{}, excelImportFileName.toStdString() + ".db");
    serialContainer<Record> records = ExcelManager::readExcel(excelImportFileName.toStdString());
    for (size_t i = 0; i < records.size(); ++i) {
        backend->addRecord(records[i]);
    }
}


void PrintoutMainWin::on_excelExportBtn_clicked()
{
    QString excelExportFileName = QFileDialog::getSaveFileName(this, tr("Excel file"), "", tr("Excel files (*.xls *.xlsx *.csv)"));
    ExcelManager::saveToExcel(excelExportFileName.toStdString() + ".xlsx", *backend->getRecords());
}


void PrintoutMainWin::on_saveBtn_clicked()
{
    backend->addRecord(makeRecord());
    resetAllFields();
}





