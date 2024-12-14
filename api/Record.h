#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Definitions.h"

using namespace std;

class IRecord {
public:
    virtual ID getID() const = 0;
 virtual Date getDate() const = 0;
 virtual String getSeries() const = 0;
 virtual Int getNumber() const = 0;
 virtual String getSection() const = 0;
 virtual String getRepair() const = 0;
 virtual String getTestType() const = 0;
 virtual String getNormalPower() const = 0;
 virtual String getEmergencyPower() const = 0;
 virtual String getVSH1() const = 0;
 virtual String getVSH2() const = 0;
 virtual String getSupercharging() const = 0;
 virtual String getTime() const = 0;
 virtual String getFuelConsuption() const = 0;
 virtual String getNotes() const = 0;
 virtual String getMaster() const = 0;

 virtual void setID(const ID &ID) = 0;
 virtual void setDate(const Date& date) = 0;
 virtual void setSeries(const String& series) = 0;
 virtual void setNumber(const Int& number) = 0;
 virtual void setSection(const String& section) = 0;
 virtual void setRepair(const String& repair) = 0;
 virtual void setTestType(const String& test_type) = 0;
 virtual void setNormalPower(const String& normal_power) = 0;
 virtual void setEmergencyPower(const String& emergency_power) = 0;
 virtual void setVSH1(const String& vsh1) = 0;
 virtual void setVSH2(const String& vsh2) = 0;
 virtual void setSupercharging(const String& supercharging) = 0;
 virtual void setTime(const String& time) = 0;
 virtual void setFuelConsuption(const String& fuel_consumption) = 0;
 virtual void setNotes(const String& notes) = 0;
 virtual void setMaster(const String& master) = 0;
};

class Record : public IRecord {
private:
    ID id;
 Date date;
 String series;
 Int number;
 String section;
 String repair;
 String test_type;
 String normal_power;
 String emergency_power;
 String vsh1;
 String vsh2;
 String supercharging;
 String time;
 String fuel_consumption;
 String notes;
 String master;

public:
 Record( Date &date, String &series, Int &number, String &section, String &repair, String &test_type, String &normal_power, String &emergency_power, String &vsh1, String &vsh2, String &supercharging, String &time, String  &fuel_consumption, String &notes, String &master) {
     setID(-1);
     setDate(date);
    setSeries(series);
    setNumber(number);
    setSection(section);
    setRepair(repair);
    setTestType(test_type);
    setNormalPower(normal_power);
    setEmergencyPower(emergency_power);
    setVSH1(vsh1);
    setVSH2(vsh2);
    setSupercharging(supercharging);
    setTime(time);
    setFuelConsuption(fuel_consumption);
    setNotes(notes);
    setMaster(master);
}
 Record(ID id, Date &date, String &series, Int &number, String &section, String &repair, String &test_type, String &normal_power, String &emergency_power, String &vsh1, String &vsh2, String &supercharging, String &time, String  &fuel_consumption, String &notes, String &master) {
     setID(id);
     setDate(date);
     setSeries(series);
     setNumber(number);
     setSection(section);
     setRepair(repair);
     setTestType(test_type);
     setNormalPower(normal_power);
     setEmergencyPower(emergency_power);
     setVSH1(vsh1);
     setVSH2(vsh2);
     setSupercharging(supercharging);
     setTime(time);
     setFuelConsuption(fuel_consumption);
     setNotes(notes);
     setMaster(master);
 }
 Record() {}
 ~Record() {}

ID getID() const override {return id;}
 Date getDate() const override { return date; }
 String getSeries() const override { return series; }
 Int getNumber() const override { return number; }
 String getSection() const override { return section; }
 String getRepair() const override { return repair; }
 String getTestType() const override { return test_type; }
 String getNormalPower() const override { return normal_power; }
 String getEmergencyPower() const override { return emergency_power; }
 String getVSH1() const override { return vsh1; }
 String getVSH2() const override { return vsh2; }
 String getSupercharging() const override { return supercharging; }
 String getTime() const override { return time; }
 String getFuelConsuption() const override { return fuel_consumption; }
 String getNotes() const override { return notes; }
 String getMaster() const override {return master; }

 void setID(const ID &id) override {this->id = id;}
 void setDate(const Date& date) override {this->date = date;}
 void setSeries(const String& series) override {this->series = series;}
 void setNumber(const Int& number) override {this->number = number;}
 void setSection(const String& section) override {this->section = section;}
 void setRepair(const String& repair) override {this->repair = repair;}
 void setTestType(const String& test_type) override {this->test_type = test_type;}
 void setNormalPower(const String& normal_power) override {this->normal_power = normal_power;}
 void setEmergencyPower(const String& emergency_power) override {this->emergency_power = emergency_power;}
 void setVSH1(const String& vsh1) override {this->vsh1 = vsh1;}
 void setVSH2(const String& vsh2) override {this->vsh2 = vsh2;}
 void setSupercharging(const String& supercharging) override {this->supercharging = supercharging;}
 void setTime(const String& time)  override {this->time = time;}
 void setFuelConsuption(const String& fuel_consumption) override {this->fuel_consumption = fuel_consumption;}
 void setNotes(const String& notes) override {this->notes = notes;}
 void setMaster(const String& master) override {this->master = master;}

};
