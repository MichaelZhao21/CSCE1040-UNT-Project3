#include "Drivers.h"

Drivers::Drivers() : driverList(vector<Driver>()){}

Drivers::Drivers(const vector<Driver> &driverList) : driverList(driverList) {}

const vector<Driver> &Drivers::getDriverList() const {
    return driverList;
}

void Drivers::setDriverList(const vector<Driver> &driverList) {
    Drivers::driverList = driverList;
}

void Drivers::addDriver() {
    
}

void Drivers::editDriver() {

}

void Drivers::removeDriver() {

}

Driver Drivers::findDriver() {
    return Driver();
}

void Drivers::printAllDrivers() {

}