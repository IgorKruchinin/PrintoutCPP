#pragma once

#include "Record.h"
#include "Printer.h"
#include "db/Dao.h"

#include <vector>
#include <string>
#include <memory>
#include <functional>

class IPrintout {
public:
    virtual void addRecord(const IRecord &record) = 0;
    virtual std::shared_ptr<serialContainer<Record>>  getRecords() = 0;
    //virtual void saveToExcel(std::string path) = 0;
    //virtual void readExcel(std::string path) = 0;
    virtual void print(const IRecord &record, bool &showPrintDialog) = 0;
};

class Printout : public IPrintout {
    DAO *db;
    Printer *printer;
public:
    Printout(TableStructure &ts, const std::function <void (String, bool&)> &printFunc, String path) {
        printer = new Printer(ts, printFunc);
        try {
            db = new DAO(path);
            db->create_table();
        } catch (DBException e) {
            std::cerr << e.getMessage();
        }
    }
    void addRecord(const IRecord &record) override {
        try {
            db->insert_record(record);
        } catch (DBPrepareStatementException e) {
            std::cerr << e.getMessage();
        }
    }
    std::shared_ptr<serialContainer<Record>> getRecords() override {
        try {
            return db->fetch_records();
        } catch (DBException e) {
            std::cerr << e.getMessage();
        }
    return nullptr;

    }
    /*void saveToExcel(std::string path) override {

    }
    void readExcel(std::string path) override {

    }*/
    void print(const IRecord &record, bool &showPrintDialog) override {
        printer->print(record, showPrintDialog);
    }
    ~Printout() {
        delete printer;
        delete db;
    }
};
