#ifndef DRIVERS_H
#define DRIVERS_H

#include "Defs.h"
#include "Driver.h"
using namespace std;

class Drivers {
public:
    /**
     * Constructors
     */
    Drivers();
    Drivers(const unordered_map<int, Driver> &driverList, int nextId);

    /**
     * Getters and setters
     */
    int getNextId() const;
    void setNextId(int nextId);

    /**
     * Prompts and adds a driver
     */
    void addDriver();

    /**
     * Edits a driver
     */
    void editDriver();

    /**
     * Removes a driver
     */
    void removeDriver();

    /**
     * Prompts for an gets a driver in driverList
     * @return an int representing the id of the driver found
     */
    int findDriver();

    /**
     * Calls findDriver() and prints that driver
     */
    void findAndPrintDriver();

    /**
     * Prints all drivers
     */
    void printAllDrivers();

    /**
     * Checks to see if the driver list is empty,
     * outputs to the user, and waits for enter
     * @return a boolean representing the emptiness of the driverlist
     */
    bool driverListEmpty();

    unordered_map<int, Driver> driverList;

private:
    int nextId;
};

#endif //DRIVERS_H
