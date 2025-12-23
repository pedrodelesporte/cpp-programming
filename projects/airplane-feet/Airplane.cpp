#include "Airplane.h"

//  static variable to 0
int Airplane::last_airplane_ID_issued = 0;

// default Constructor
Airplane::Airplane() {
    last_airplane_ID_issued++;
    airplane_ID = last_airplane_ID_issued;
    manufacturer = "";
    model = "";
    yearBuilt = 0;
    flightHours = 0;
}

// parameterized Constructor
Airplane::Airplane(string manufacturer, string model, int year, int hours) {
    last_airplane_ID_issued++;
    airplane_ID = last_airplane_ID_issued;
    this->manufacturer = manufacturer;
    this->model = model;
    this->yearBuilt = year;
    this->flightHours = hours;
}

// mutators
void Airplane::setManufacturer(string company) {
    manufacturer = company;
}
void Airplane::setModel(string name) {
    model = name;
}
void Airplane::setYearBuilt(int year) {
    yearBuilt = year;
}
void Airplane::setFlightHours(int hours) {
    flightHours = hours;
}

// accessors
string Airplane::getManufacturer() const {
    return manufacturer;
}
string Airplane::getModel() const {
    return model;
}
int Airplane::getAirplane_ID() const {
    return airplane_ID;
}
int Airplane::getYearBuilt() const {
    return yearBuilt;
}
int Airplane::getFlightHours() const {
    return flightHours;
}
int Airplane::get_last_airplane_ID_issued() {
    return last_airplane_ID_issued;
}

string Airplane::getDescription() const {
    string desc = "ID#: " + to_string(airplane_ID) +
                  ", manufacturer: " + manufacturer +
                  ", model: " + model +
                  ", year: " + to_string(yearBuilt) +
                  ", hours: " + to_string(flightHours);
    return desc;
}