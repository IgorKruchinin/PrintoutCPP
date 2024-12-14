#pragma once
#include <string>
#include "Definitions.h"


class TableStructure {
    String dateName;
    String seriesName;
    String numberName;
    String sectionName;
    String repairName;
    String testTypeName;
    String normalPowerName;
    String emergencyPowerName;
    String VSH1Name;
    String VSH2Name;
    String superchargingName;
    String timeName;
    String fuelConsuptionName;
    String notesName;
    String masterName;

public:
    TableStructure(String dateName, String seriesName,\
                   String numberName, String sectionName,\
                   String repairName, String testTypeName,\
                   String normalPowerName, String emergencyPowerName,\
                   String VSH1Name, String VSH2Name,\
                   String superchargingName, String timeName,\
                   String fuelConsuptionName, String notesName,\
                   String masterName) {
        this->dateName = dateName;
        this->seriesName = seriesName;
        this->numberName = numberName;
        this->sectionName = sectionName;
        this->repairName = repairName;
        this->testTypeName = testTypeName;
        this->normalPowerName = normalPowerName;
        this->emergencyPowerName = emergencyPowerName;
        this->VSH1Name = VSH1Name;
        this->VSH2Name = VSH2Name;
        this->superchargingName = superchargingName;
        this->timeName = timeName;
        this->fuelConsuptionName = fuelConsuptionName;
        this->notesName = notesName;
        this->masterName = masterName;
    }
    std::string getDateFieldName() {
        return dateName;
    }
    std::string getSeriesFieldName() {
        return seriesName;
    }
    std::string getNumberFieldName() {
        return numberName;
    }
    std::string getSectionFieldName() {
        return sectionName;
    }
    std::string getRepairFieldName() {
        return repairName;
    }
    std::string getTestTypeFieldName() {
        return testTypeName;
    }
    std::string getNormalPowerFieldName() {
        return normalPowerName;
    }
    std::string getEmergencyPowerFieldName() {
        return emergencyPowerName;
    }
    std::string getVSH1FieldName() {
        return VSH1Name;
    }
    std::string getVSH2FieldName() {
        return VSH2Name;
    }
    std::string getSuperchargingFieldName() {
        return superchargingName;
    }
    std::string getTimeFieldName() {
        return timeName;
    }
    std::string getFuelConsuptionFieldName() {
        return fuelConsuptionName;
    }
    std::string getNotesFieldName() {
        return notesName;
    }
    std::string getMasterFieldName() {
        return masterName;
    }
};
