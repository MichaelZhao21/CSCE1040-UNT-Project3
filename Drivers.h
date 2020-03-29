#ifndef DRIVERS_H
#define DRIVERS_H

#include "Defs.h"
#include "Driver.h"
using namespace std;

class Drivers {
public:
    Drivers();
    Drivers(const unordered_map<int, Driver> &driverList, int nextId);
    int getNextId() const;
    void setNextId(int nextId);
    void addDriver();
    void editDriver();
    void removeDriver();
    int findDriver();
    void findAndPrintDriver();
    void printAllDrivers();
    bool driverListEmpty();
    unordered_map<int, Driver> driverList;
private:
    int nextId;
};

#endif //DRIVERS_H
