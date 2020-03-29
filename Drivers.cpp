#include "Util.h"
#include "Drivers.h"

Drivers::Drivers() : driverList(unordered_map<int, Driver>()), nextId(100000) {}

Drivers::Drivers(const unordered_map<int, Driver> &driverList, int nextId) : driverList(driverList), nextId(nextId) {}

int Drivers::getNextId() const {
    return nextId;
}

void Drivers::setNextId(int nextId) {
    Drivers::nextId = nextId;
}

void Drivers::addDriver() {
    string name, notes;
    int id, cap, type;
    double rating;
    bool hcp, open, pets;

    cout << "<<< Add Driver >>>" << endl;
    id = nextId++;
    Util::parseInput(name, "Name", false);
    Util::parseInput(cap, "Car capacity", 1, 8, false);
    Util::parseInput(hcp, "Handicapped capable", false);
    Util::parseInput(type, "Vehicle type", vs{"Compact (2WD)", "Sedan (4WD)", "SUV", "VAN", "OTHER"}, false);
    Util::parseInput(rating, "Driver rating", 0, 5, false);
    Util::parseInput(open, "Availability", false);
    Util::parseInput(pets, "Allows pets", false);
    Util::parseInput(notes, "Notes", false);
    cout << endl;

    driverList[id] = Driver(name, id, cap, hcp, (VehicleType) type, rating, open, pets, notes);
    driverList[id].printDriver();
    Util::waitForEnter();
}

void Drivers::editDriver() {
    string name, notes;
    int id, cap, type;
    double rating;
    bool hcp, open, pets;

    cout << "<<< Edit Driver >>>" << endl;
    if (driverListEmpty()) return;
    int index = findDriver();

    cout << "<<< Edit information for Driver #" << index << " >>>" << endl;
    if (Util::parseInput(name, "Name", true)) driverList[index].setName(name);
    if (Util::parseInput(cap, "Car capacity", 1, 8, true)) driverList[index].setCap(cap);
    if (Util::parseInput(hcp, "Handicapped capable", true)) driverList[index].setHcp(hcp);
    if (Util::parseInput(type, "Vehicle type", vs{"Compact (2WD)", "Sedan (4WD)", "SUV", "Van", "Other"}, true)) driverList[index].setType((VehicleType) type);
    if (Util::parseInput(rating, "Driver rating", 0, 5, true)) driverList[index].setRating(rating);
    if (Util::parseInput(open, "Availability", true)) driverList[index].setOpen(open);
    if (Util::parseInput(pets, "Allows pets", true)) driverList[index].setPets(pets);
    if (Util::parseInput(notes, "Notes", true)) driverList[index].setNotes(notes);
    cout << endl;

    driverList[index].printDriver();
    Util::waitForEnter();
}

void Drivers::removeDriver() {
    cout << "<<< Remove Driver >>>" << endl;
    if (driverListEmpty()) return;
    driverList.erase(findDriver());
    cout << endl;
}

int Drivers::findDriver() {
    if (driverListEmpty()) {
        perror("DriverList empty in Drivers::findDriver");
        exit(1);
    }
    vs text {"Pick a driver"};
    for (pair<int, Driver> dp : driverList) {
        text.push_back(to_string(dp.first) + " | " + dp.second.getName());
    }
    int index = Util::menu(text);
    return stoi(text[index]);
}

void Drivers::findAndPrintDriver() {
    cout << "<<< Find Driver >>>" << endl;
    if (driverListEmpty()) return;
    driverList[findDriver()].printDriver();
    Util::waitForEnter();
}

void Drivers::printAllDrivers() {
    cout << "<<< Print All Drivers >>>" << endl;
    if (driverListEmpty()) return;
    for (pair<int, Driver> d : driverList)
        d.second.printDriver();
    Util::waitForEnter();
}

bool Drivers::driverListEmpty() {
    if (driverList.empty()) {
        cout << "No drivers :(" << endl << endl;
        Util::waitForEnter();
        return true;
    }
    return false;
}
