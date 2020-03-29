#include "Util.h"
#include "Rides.h"

Rides::Rides() : rideList(unordered_map<int, Ride>()), nextId(10000000) {}

Rides::Rides(const unordered_map<int, Ride> &rideList, int nextId) : rideList(rideList), nextId(nextId) {}

int Rides::getNextId() const {
    return nextId;
}

void Rides::setNextId(int nextId) {
    Rides::nextId = nextId;
}

void Rides::addRide(Passes& passes, Drivers& drivers) {
    int id, size, passId, driverId, hours, mins;
    string pickLoc, dropLoc;
    time_t pickTime, dropTime;
    bool pets;
    vi possDrivers;

    cout << "<<< New Ride >>>" << endl;
    if (passes.passListEmpty()) return;
    id = nextId++;
    bool hasDrivers = false;
    passId = passes.findPass();
    while (!hasDrivers) {
        Util::parseInput(pickLoc, "Pickup location", false);
        Util::parseInput(pickTime, "Pickup time", false);
        Util::parseInput(dropLoc, "Dropoff location", false);
        Util::parseInput(hours, "Length of ride [hours]", 0, 24, false);
        Util::parseInput(mins, "Length of ride [mins]", 0, 59, false);
        Util::parseInput(size, "Party size", 1, 8, false);
        Util::parseInput(pets, "Party has pets", false);
        dropTime = pickTime + (hours * 3600) + (mins * 60);
        possDrivers = findAllMatchingDrivers(passes.passList[passId], drivers, size, pets);
        checkDriverTime(possDrivers, drivers, pickTime, dropTime);
        hasDrivers = (!possDrivers.empty());
        if (!hasDrivers) {
            cout << endl << "No drivers found :(((" << endl;
            bool cont;
            Util::parseInput(cont, "Try again?", false);
            cout << endl;
            if (!cont) return;
        }
    }

    vs text {"Pick a driver"};
    for (int i = 0; i < possDrivers.size(); i++)
        text.push_back(to_string(possDrivers[i]) + " | " + drivers.driverList[possDrivers[i]].getName());
    driverId = possDrivers[Util::menu(text) - 1];

    rideList[id] = Ride(id, pickLoc, pickTime, dropLoc, size, pets, dropTime, passId, driverId);
    rideList[id].printRide();
    Util::waitForEnter();
}

vi Rides::findAllMatchingDrivers(Pass& pass, Drivers& drivers, int size, bool pets) {
    vi output;
    for (pair<int, Driver> d : drivers.driverList)
        if (checkDriverMatchReq(d.second, pass, size, pets))
            output.push_back(d.first);
    return output;
}

bool Rides::checkDriverMatchReq(Driver& driver, Pass& pass, int size, bool pets) {
    if (!driver.getOpen()) return false;
    if (!driver.getPets() && pass.getPets()) return false;
    if (!driver.getPets() && pets) return false;
    if (driver.getCap() < size) return false;
    if (!driver.getHcp() && pass.getHcp()) return false;
    return driver.getRating() >= pass.getMinRating();
}

void Rides::checkDriverTime(vi& poss, Drivers& drivers, time_t pickTime, time_t dropTime) {
    int i = 0;
    while (i != poss.size()) {
        bool works = true;
        vector<Ride> driverRides = getDriverRides(drivers.driverList[poss[i]]);
        for (auto& driverRide : driverRides) {
            if (driverRide.getPickTime() < dropTime && pickTime < driverRide.getDropTime()) {
                works = false;
                break;
            }
        }
        if (!works) poss.erase(poss.begin() + i);
        else i++;
    }
}

int Rides::findRide(Passes& passes, Drivers& drivers) {
    if (rideListEmpty()) {
        perror("RideList empty in Rides::findRide");
        exit(1);
    }
    vector<Ride> rideVec;
    for (pair<int, Ride> r : rideList) {
        rideVec.push_back(r.second);
    }
    vs text = Util::getList("Pick a ride", rideVec, false, passes, drivers);
    int index = Util::menu(text);
    return stoi(text[index]);
}

void Rides::findandPrintRide(Passes& passes, Drivers& drivers) {
    cout << "<<< Find Ride >>>" << endl;
    if (rideListEmpty()) return;
    rideList[findRide(passes, drivers)].printRide();
    Util::waitForEnter();
}

void Rides::cancelRide(Passes& passes, Drivers& drivers) {
    cout << "<<< Cancel Ride >>>" << endl;
    if (rideListEmpty()) return;
    int r = findRide(passes, drivers);
    rideList[r].printRide();
    bool confirm;
    Util::parseInput(confirm, "Are you sure you want to delete this ride?", false);
    cout << endl;
    if (confirm) rideList[r].setStatus(Status::CANCELLED);
}

void Rides::rateRides(Passes& passes, Drivers& drivers) {
    cout << "<<< Rate Ride >>>" << endl;
    vector<Ride> rides;
    for (auto& r : rideList)
        if (r.second.getStatus() == Status::COMPLETED)
            rides.push_back(r.second);
    if (rides.empty()) {
        cout << "No completed rides :(" << endl << endl;
        Util::waitForEnter();
        return;
    }
    vs text = Util::getList("Pick a ride", rides, false, passes, drivers);
    int r = Util::menu(text);
    double rating;
    Util::parseInput(rating, "Enter rating", 0, 5, false);
    rideList[r].setRating(rating);
}

void Rides::printAllRides() {
    cout << "<<< Print All Rides >>>" << endl;
    if (rideListEmpty()) return;
    for (pair<int, Ride> r : rideList)
        r.second.printRide();
    Util::waitForEnter();
}

void Rides::printRideByStatus(Status s) {
    cout << "<<< Print all " << Ride::statusToString(s) << " Rides >>>" << endl;
    if (rideListEmpty()) return;
    vs text {Ride::statusToString(s) + " Rides"};
    for (pair<int, Ride> r : rideList) {
        if (r.second.getStatus() == s)
            text.push_back(to_string(r.second.getId()) + " | " + "Passenger: " + to_string(r.second.getPassId()) + " | " + "Driver: " + to_string(r.second.getDriverId()));
    }
    Util::prettyPrint(text);
    Util::waitForEnter();
}

vector<Ride> Rides::getDriverRides(Driver& driver) {
    vector<Ride> output;
    for (pair<int, Ride> r : rideList) {
        r.second.printRide();
        if (r.second.getDriverId() == driver.getId() && r.second.getStatus() != Status::CANCELLED && r.second.getStatus() != Status::COMPLETED)
            output.push_back(r.second);}
    return output;
}

vector<Ride> Rides::getPassRides(Pass& pass) {
    vector<Ride> output;
    for (pair<int, Ride> r : rideList)
        if (r.second.getPassId() == pass.getId()&& r.second.getStatus() != Status::CANCELLED && r.second.getStatus() != Status::COMPLETED)
            output.push_back(r.second);
    return output;
}

void Rides::printDriverSchedule(Passes& passes, Drivers& drivers) {
    cout << "<<< Print Driver Schedule >>>" << endl;
    if (drivers.driverListEmpty()) return;
    int index = drivers.findDriver();

    vector<Ride> dr = getDriverRides(drivers.driverList[index]);
    vs text = Util::getList("Schedule for Driver #" + to_string(index), dr, false, passes, drivers);
    if (text.size() == 1)
        text.push_back("No scheduled rides :D");
    Util::prettyPrint(text);
    Util::waitForEnter();
}

void Rides::printPassSchedule(Passes& passes, Drivers& drivers) {
    cout << "<<< Print Passenger Schedule >>>" << endl;
    if (passes.passListEmpty()) return;
    int index = passes.findPass();

    vector<Ride> pr = getPassRides(passes.passList[index]);
    vs text = Util::getList("Schedule for Passenger #" + to_string(index), pr, false, passes, drivers);
    if (text.size() == 1)
        text.push_back("No scheduled rides :D");
    Util::prettyPrint(text);
    Util::waitForEnter();
}

void Rides::removeUselessRides() {
    cout << "<<< Remove Completed/Cancelled Rides >>>" << endl;
    if (rideListEmpty()) return;
    vi removed;
    for (pair<int, Ride> r : rideList) {
        if (r.second.getStatus() == Status::CANCELLED || r.second.getStatus() == Status::COMPLETED) {
            removed.push_back(r.first);
            rideList.erase(r.first);
        }
    }
    cout << "Removed rides: " << endl << endl;
    for (auto& i : removed)
        rideList[i].printRide();
    Util::waitForEnter();
}

bool Rides::rideListEmpty() {
    if (rideList.empty()) {
        cout << "No rides :(" << endl << endl;
        Util::waitForEnter();
        return true;
    }
    return false;
}