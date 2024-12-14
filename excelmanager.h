#ifndef EXCELMANAGER_H
#define EXCELMANAGER_H
#include "api/Definitions.h"
#include "api/Record.h"
#include <QString>
#include <QWidget>
#include "OpenXLSX.hpp"
using namespace OpenXLSX;


class ExcelManager
{
public:
    static serialContainer<Record> readExcel(String path) {
        XLDocument doc(path);
        serialContainer<Record> records;
        auto sheet = doc.workbook().worksheet("Sheet1");
        for(uint32_t i = 1; i < sheet.rowCount(); ++i) {
            Date date = sheet.cell(i + 1, 1).value();
            String series = sheet.cell(i + 1, 2).value();
            Int number = sheet.cell(i + 1, 3).value();
            String section = sheet.cell(i + 1, 4).value();
            String repair = sheet.cell(i + 1, 5).value();
            String testsType = sheet.cell(i + 1, 6).value();
            String normalPower = sheet.cell(i + 1, 7).value();
            String emergencyPower = sheet.cell(i + 1, 8).value();
            String vsh1 = sheet.cell(i + 1, 9).value();
            String vsh2 = sheet.cell(i + 1, 10).value();
            String supercharging = sheet.cell(i + 1, 11).value();
            String time = sheet.cell(i + 1, 12).value();
            String consuption = sheet.cell(i + 1, 13).value();
            String notes = sheet.cell(i + 1, 14).value();
            String master = sheet.cell(i + 1, 15).value();

            records.push_back(Record(date, series, number, section, repair, testsType, normalPower, emergencyPower, vsh1, vsh2, supercharging, time, consuption, notes, master));
        }
        return records;
    }
    static void saveToExcel(String path, serialContainer<Record> records) {
        XLDocument doc;
        doc.create(path);
        auto sheet = doc.workbook().worksheet("Sheet1");
        sheet.cell(1, 1).value() = QObject::tr("Date").toStdString();
        sheet.cell(1, 2).value() = QObject::tr("Series").toStdString();
        sheet.cell(1, 3).value() = QObject::tr("Number").toStdString();
        sheet.cell(1, 4).value() = QObject::tr("Section").toStdString();
        sheet.cell(1, 5).value() = QObject::tr("Repair").toStdString();
        sheet.cell(1, 6).value() = QObject::tr("Tests type").toStdString();
        sheet.cell(1, 7).value() = QObject::tr("Power NM").toStdString();
        sheet.cell(1, 8).value() = QObject::tr("Power EM").toStdString();
        sheet.cell(1, 9).value() = QObject::tr("VSH1").toStdString();
        sheet.cell(1, 10).value() = QObject::tr("VSH2").toStdString();
        sheet.cell(1, 11).value() = QObject::tr("Supercharging").toStdString();
        sheet.cell(1, 12).value() = QObject::tr("Time").toStdString();
        sheet.cell(1, 13).value() = QObject::tr("Fuel consuption").toStdString();
        sheet.cell(1, 14).value() = QObject::tr("Notes").toStdString();
        sheet.cell(1, 15).value() = QObject::tr("Master").toStdString();
        for (size_t i = 0; i < records.size(); ++i) {
            Record record = records[i];
            sheet.cell((i + 2), 1).value() = record.getDate();
            sheet.cell((i + 2), 2).value() = record.getSeries();
            sheet.cell((i + 2), 3).value() = record.getNumber();
            sheet.cell((i + 2), 4).value() = record.getSection();
            sheet.cell((i + 2), 5).value() = record.getRepair();
            sheet.cell((i + 2), 6).value() = record.getTestType();
            sheet.cell((i + 2), 7).value() = record.getNormalPower();
            sheet.cell((i + 2), 8).value() = record.getEmergencyPower();
            sheet.cell((i + 2), 9).value() = record.getVSH1();
            sheet.cell((i + 2), 10).value() = record.getVSH2();
            sheet.cell((i + 2), 11).value() = record.getSupercharging();
            sheet.cell((i + 2), 12).value() = record.getFuelConsuption();
            sheet.cell((i + 2), 13).value() = record.getTime();
            sheet.cell((i + 2), 14).value() = record.getNotes();
            sheet.cell((i + 2), 15).value() = record.getMaster();


        }
        doc.save();
    }
};

#endif // EXCELMANAGER_H
