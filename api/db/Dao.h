#pragma once
#include <string>
#include <sqlite3.h>
#include <memory>
#include "../Record.h"
#include "../Definitions.h"

class DBException {
    std::string message;
public:
    DBException(std::string message) {
        this->message = message;
    }
    std::string getMessage() {
        return message;
    }
};

class DBOpeningException : public DBException {
public:
    DBOpeningException(std::string message) : DBException(message) {}
};

class DBPrepareStatementException : public DBException {
public:
    DBPrepareStatementException(std::string message) : DBException(message) {}
};

class DBCreateTableException : public DBException {
public:
    DBCreateTableException(std::string message) : DBException(message) {}
};

class DBInsertException : public DBException {
public:
    DBInsertException(std::string message) : DBException(message) {}
};

class DAO {
public:
    DAO(const std::string& db_name);
    ~DAO();

    bool create_table();
    bool insert_record(const std::string& date, const std::string& series, int number, const std::string& section,
                       const std::string& repair, const std::string& test_type, const std::string& normal_power,
                       const std::string& emergency_power, const std::string& vsh1, const std::string& vsh2,
                       const std::string& supercharging, const std::string& time, const std::string& fuel_consumption,
                       const std::string& notes, const std::string& master);
    bool insert_record(const IRecord &record);

    std::shared_ptr<serialContainer<Record>>  fetch_records();

private:
    sqlite3* db;
};
