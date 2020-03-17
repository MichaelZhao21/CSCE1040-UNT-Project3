#ifndef DRIVERS_H
#define DRIVERS_H

#include "Defs.h"
#include "Driver.h"
using namespace std;

class Drivers {
public:
    Drivers();
    Drivers(const unordered_map<int, Driver> &driverList);
    const unordered_map<int, Driver> &getDriverList() const;
    void setDriverList(const unordered_map<int, Driver> &driverList);
    void addDriver();
    void editDriver();
    void removeDriver();
    Driver findDriver();
    void printAllDrivers();
private:
    unordered_map<int, Driver> driverList;
};

#endif //DRIVERS_H
