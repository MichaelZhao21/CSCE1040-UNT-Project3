#ifndef DRIVERS_H
#define DRIVERS_H

#include <vector>
#include <iostream>
#include "Driver.h"
using namespace std;

class Drivers {
public:
    Drivers();

    explicit Drivers(const vector<Driver> &driverList);

    const vector<Driver> &getDriverList() const;

    void setDriverList(const vector<Driver> &driverList);

    void addDriver();

    void editDriver();

    void removeDriver();

    Driver findDriver();

    void printAllDrivers();

private:
    vector<Driver> driverList;
};

#endif //DRIVERS_H
