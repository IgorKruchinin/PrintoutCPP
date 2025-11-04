#include "Dao.h"
#include <fmt/format.h>
#include <string>

DAO::DAO(const std::string& db_name) {
    int exit = sqlite3_open(db_name.c_str(), &db);
    if (exit) {
        //std::cerr << "Error open DB: " << sqlite3_errmsg(db) << std::endl;
        throw DBOpeningException(sqlite3_errmsg(db));
    }
}

DAO::~DAO() {
    sqlite3_close(db);
}

bool DAO::create_table() {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS records (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            date TEXT NOT NULL,
            series TEXT,
            number INTEGER,
            section TEXT,
            repair TEXT,
            test_type TEXT,
            normal_power TEXT,
            emergency_power TEXT,
            vsh1 TEXT,
            vsh2 TEXT,
            supercharging TEXT,
            time TEXT,
            fuel_consumption TEXT,
            notes TEXT,
            master TEXT
        );
    )";

    char* errmsg;
    int exit = sqlite3_exec(db, sql, nullptr, 0, &errmsg);
    if (exit != SQLITE_OK) {
        //std::cerr << "Error create table: " << errmsg << std::endl;
        throw DBCreateTableException(errmsg);
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

bool DAO::insert_record(const IRecord &record) {
    std::string sql = fmt::format("INSERT INTO records (date, series, number, section, repair, test_type, normal_power, emergency_power, "\
                             "vsh1, vsh2, supercharging, time, fuel_consumption, notes, master) "\
        "VALUES (\"{}\", \"{}\", {}, \"{}\", \"{}\", \"{}\", \"{}\", \"{}\", \"{}\", \"{}\", \"{}\", \"{}\", \"{}\", \"{}\", \"{}\");"\
                                  ")", record.getDate(), record.getSeries(), record.getNumber(), record.getSection(), record.getRepair(), record.getTestType(), record.getNormalPower(), record.getEmergencyPower(), record.getVSH1(), record.getVSH2(), record.getSupercharging(), record.getTime(), record.getFuelConsuption(), record.getNotes(), record.getMaster());

    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (exit != SQLITE_OK) {
        //std::cerr << "Error prepare statement: " << sqlite3_errmsg(db) << std::endl;
        throw DBPrepareStatementException(sqlite3_errmsg(db));
        return false;
    }

    /*sqlite3_bind_text(stmt, 1, record.getDate().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, record.getSeries().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, record.getNumber());
    sqlite3_bind_text(stmt, 4, record.getSection().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, record.getRepair().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, record.getTestType().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, record.getNormalPower().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 8, record.getEmergencyPower().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 9, record.getVSH1().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 10, record.getVSH2().c_str(), -1, SQLITE_STATIC);

    sqlite3_bind_text(stmt, 11, record.getSupercharging().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 12, record.getTime().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 13, record.getFuelConsuption().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 14, record.getNotes().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 15, record.getMaster().c_str(), -1, SQLITE_STATIC);*/

    exit = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (exit != SQLITE_DONE) {
        //std::cerr << "Error insert: " << sqlite3_errmsg(db) << std::endl;
        throw DBInsertException(sqlite3_errmsg(db));
        return false;
    }
    return true;
}

bool DAO::insert_record(const std::string& date, const std::string& series, int number, const std::string& section,
                        const std::string& repair, const std::string& test_type, const std::string& normal_power,
                        const std::string& emergency_power, const std::string& vsh1, const std::string& vsh2,
                        const std::string& supercharging, const std::string& time, const std::string& fuel_consumption,
                        const std::string& notes, const std::string& master) {
    std::string sql = R"(
        INSERT INTO records (date, series, number, section, repair, test_type, normal_power, emergency_power,
                             vsh1, vsh2, supercharging, time, fuel_consumption, notes, master)
        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);
    )";

    sqlite3_stmt* stmt;
    int exit = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (exit != SQLITE_OK) {
        //std::cerr << "Error prepare statement: " << sqlite3_errmsg(db) << std::endl;
        throw DBPrepareStatementException(sqlite3_errmsg(db));
        return false;
    }

    sqlite3_bind_text(stmt, 1, date.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, series.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, number);
    sqlite3_bind_text(stmt, 4, section.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, repair.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, test_type.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, normal_power.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 8, emergency_power.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 9, vsh1.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 10, vsh2.c_str(), -1, SQLITE_STATIC);

    sqlite3_bind_text(stmt, 11, supercharging.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 12, time.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 13, fuel_consumption.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 14, notes.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 15, master.c_str(), -1, SQLITE_STATIC);

    exit = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (exit != SQLITE_DONE) {
        //std::cerr << "Error insert: " << sqlite3_errmsg(db) << std::endl;
        throw DBInsertException(sqlite3_errmsg(db));
        return false;
    }
    return true;
}

std::shared_ptr<serialContainer<Record>> DAO::fetch_records() {
    const char* sql = "SELECT * FROM records;";
    sqlite3_stmt* stmt;

    int exit = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (exit != SQLITE_OK) {
        //std::cerr << "Error prepare statement: " << sqlite3_errmsg(db) << std::endl;
        throw DBPrepareStatementException(sqlite3_errmsg(db));
    }
    std::shared_ptr<serialContainer<Record>> records(new serialContainer<Record>());
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        ID id = sqlite3_column_int(stmt, 0);
        Date date = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        String series = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        Int number = sqlite3_column_int(stmt, 3);
        String section = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4));
        String repair = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5));
        String test_type = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6));
        String normal_power = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 7));
        String emergency_power = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 8));
        String vsh1 = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 9));
        String vsh2 = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 10));
        String supercharging = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 11));
        String time = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 12));
        String fuel_consumption = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 13));
        String notes = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 14));
        String master = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 15));
        records->emplace_back(Record(id, date, series, number, section, repair, test_type, normal_power, emergency_power, vsh1, vsh2, supercharging, time, fuel_consumption, notes, master));
    }

    sqlite3_finalize(stmt);
    return records;
}


