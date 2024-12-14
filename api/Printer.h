 #pragma once
#include "Definitions.h"
#include "Record.h"
#include "TableStructure.h"
#include <string>
#include <format>
#include <functional>
#include <sstream>

class InvalidDateException {};

class Printer {
    const std::function <void (String, bool&)> printFunc;
    String formatString;
    TableStructure ts;
public:
    Printer(TableStructure &ts, const std::function <void (String, bool&)> &printFunc) :printFunc(printFunc), ts(ts) {}
    void print(const IRecord &record, bool &showPrintDialog) {
        String printString = preparePrintingString(ts, record);
        printFunc(printString, showPrintDialog);
    }
    static String preparePrintingString(TableStructure &ts, const IRecord &record) {
        std::stringstream ss;
        ss << ts.getDateFieldName() << ": " << reformDate(record.getDate()) << "\t" \
           << ts.getSeriesFieldName() << ": " << addUp(record.getSeries(), ' ', 10) << "\t" \
           << ts.getNumberFieldName() << ": " << addUp(record.getNumber(), ' ', 10) << "\t" \
           << ts.getSectionFieldName() << ": " << addUp(record.getSection(), ' ', 10) << "\t" \
           << ts.getRepairFieldName() << ": " << addUp(record.getRepair(), ' ', 10) << "\n" \
           << ts.getTestTypeFieldName() << ": " << record.getTestType() << "\n" \
           << ts.getNormalPowerFieldName() << ": " << addUp(record.getNormalPower(), ' ', 10) << "\t" \
           << ts.getVSH1FieldName() << ": " << addUp(record.getVSH1(), ' ', 10) << "\t" \
           << ts.getSuperchargingFieldName() << ": " << addUp(record.getSupercharging(), ' ', 10) << "\n" \
           << ts.getEmergencyPowerFieldName() << ": " << addUp(record.getEmergencyPower(), ' ', 10) << "\t" \
           << ts.getVSH2FieldName() << ": " << addUp(record.getVSH2(), ' ', 10) << "\t" \
           << ts.getTimeFieldName() << ": " << addUp(record.getTime(), ' ', 10) << "\n" \
           << ts.getFuelConsuptionFieldName() << ": " <<  addUp(record.getFuelConsuption(), ' ', 10) << "\n" \
           << ts.getNotesFieldName() << ": " << record.getNotes() << "\n" \
           << ts.getMasterFieldName() << ": " << record.getMaster() << "\n";
        return ss.str();
    }
    static String addUp(String str, char symbol, int symbols_count) {
        std::stringstream ss;
        ss << str;
        while (ss.str().size() < symbols_count){
            ss << symbol;
        }
        return ss.str();
    }
    static String addUp(Int number, char symbol, int symbols_count) {
        std::stringstream ss;
        ss << number;
        while (ss.str().size() < symbols_count){
            ss << symbol;
        }
        return ss.str();
    }
    static String reformDate(String date) {
        if (date.size() != 10) {
            throw InvalidDateException();
        }
        std::stringstream newDate;
        newDate << date[8] << date[9] << '.' << date[5] << date[6] << '.' << date[0] << date[1] << date[2] << date[3];
        return newDate.str();
    }
};
