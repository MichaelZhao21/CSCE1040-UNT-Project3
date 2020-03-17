#include "Util.h"

Drivers::Drivers() : driverList(unordered_map<int, Driver>()) {}

Drivers::Drivers(const unordered_map<int, Driver> &driverList) : driverList(driverList) {}

const unordered_map<int, Driver> &Drivers::getDriverList() const {
    return driverList;
}

void Drivers::setDriverList(const unordered_map<int, Driver> &driverList) {
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