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
private:
    static std::string safeGetString(OpenXLSX::XLWorksheet& sheet, uint32_t row, uint32_t col) {
        try {
            auto cell = sheet.cell(row, col);
            auto valueType = cell.value().type();

            if (valueType == OpenXLSX::XLValueType::Empty) {
                return "";
            }

            // Если это число (возможно дата Excel)
            if (valueType == OpenXLSX::XLValueType::Integer ||
                valueType == OpenXLSX::XLValueType::Float) {

                double numericValue = (valueType == OpenXLSX::XLValueType::Integer)
                    ? static_cast<double>(cell.value().get<int>())
                    : cell.value().get<double>();

                // Проверяем, может ли это быть датой Excel
                if (numericValue > 1000 && numericValue < 50000) {
                    return convertExcelDateToString(numericValue);
                }

                // Для обычных чисел возвращаем как строку
                return std::to_string(numericValue);
            }

            // Для строк и других типов
            return cell.value().get<std::string>();

        } catch (const std::exception& e) {
            std::cerr << "Error reading cell (" << row << "," << col << "): " << e.what() << std::endl;
            return "";
        }
    }

    static int safeGetInt(OpenXLSX::XLWorksheet& sheet, uint32_t row, uint32_t col) {
        try {
            auto cell = sheet.cell(row, col);
            auto valueType = cell.value().type();

            if (valueType == OpenXLSX::XLValueType::Empty) {
                return 0;
            }

            if (valueType == OpenXLSX::XLValueType::Integer) {
                return cell.value().get<int>();
            }
            else if (valueType == OpenXLSX::XLValueType::Float) {
                return static_cast<int>(cell.value().get<double>());
            }
            else if (valueType == OpenXLSX::XLValueType::String) {
                std::string strVal = cell.value().get<std::string>();
                return strVal.empty() ? 0 : std::stoi(strVal);
            }

            return 0;

        } catch (const std::exception& e) {
            std::cerr << "Error reading int from cell (" << row << "," << col << "): " << e.what() << std::endl;
            return 0;
        }
    }

    static std::string convertExcelDateToString(double excelDate) {
        // Упрощенная конвертация Excel serial date в строку
        // Excel использует даты с 1 января 1900 года
        int days = static_cast<int>(excelDate);
        int year = 1900;
        int month = 1;
        int day = 1;

        if (days > 0) {
            day += days - 1; // -1 потому что 1 января 1900 = 1

            int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

            while (day > daysInMonth[month-1]) {
                day -= daysInMonth[month-1];
                month++;
                if (month > 12) {
                    month = 1;
                    year++;
                    // Проверка високосного года
                    daysInMonth[1] = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
                }
            }
        }

        // Форматируем как "YYYY-MM-DD"
        char buffer[11];
        std::snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", year, month, day);
        return std::string(buffer);
    }

public:
    static serialContainer<Record> readExcel(String path) {
        XLDocument doc;
        serialContainer<Record> records;

        try {
            doc.open(path);
            auto sheetNames = doc.workbook().sheetNames();
            auto sheet = doc.workbook().worksheet(sheetNames[0]);

            // Отладочный вывод для проверки структуры
            std::cout << "Sheet has " << sheet.rowCount() << " rows" << std::endl;

            for(uint32_t i = 1; i < sheet.rowCount(); ++i) {
                // Используем безопасные функции вместо прямого .value()
                Date date = safeGetString(sheet, i + 1, 1);
                String series = safeGetString(sheet, i + 1, 2);
                Int number = safeGetInt(sheet, i + 1, 3);  // Убрал std::stoi
                String section = safeGetString(sheet, i + 1, 4);
                String repair = safeGetString(sheet, i + 1, 5);
                String testsType = safeGetString(sheet, i + 1, 6);
                String normalPower = safeGetString(sheet, i + 1, 7);
                String emergencyPower = safeGetString(sheet, i + 1, 8);
                String vsh1 = safeGetString(sheet, i + 1, 9);
                String vsh2 = safeGetString(sheet, i + 1, 10);
                String supercharging = safeGetString(sheet, i + 1, 11);
                String time = safeGetString(sheet, i + 1, 12);
                String consuption = safeGetString(sheet, i + 1, 13);
                String notes = safeGetString(sheet, i + 1, 14);
                String master = safeGetString(sheet, i + 1, 15);

                records.push_back(Record(date, series, number, section, repair, testsType,
                                       normalPower, emergencyPower, vsh1, vsh2, supercharging,
                                       time, consuption, notes, master));
            }
        } catch (const std::exception& e) {
            std::cerr << "Error in readExcel: " << e.what() << std::endl;
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
