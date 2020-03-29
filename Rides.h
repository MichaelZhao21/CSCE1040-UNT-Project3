#ifndef RIDES_H
#define RIDES_H

#include "Defs.h"
#include "Passes.h"
#include "Drivers.h"
#include "Ride.h"
using namespace std;

class Rides {
public:
    Rides();
    Rides(const unordered_map<int, Ride> &rideList, int nextId);
    int getNextId() const;
    void setNextId(int nextId);
    void addRide(Passes& passes, Drivers& drivers);
    vi findAllMatchingDrivers(Pass& pass, Drivers& drivers, int size, bool pets);
    bool checkDriverMatchReq(Driver& driver, Pass& pass, int size, bool pets);
    void checkDriverTime(vi& poss, Drivers& drivers, time_t pickTime, time_t dropTime);
    int findRide(Passes& passes, Drivers& drivers);
    void findandPrintRide(Passes& passes, Drivers& drivers);
    void cancelRide(Passes& passes, Drivers& drivers);
    void rateRides(Passes& passes, Drivers& drivers);
    void printAllRides();
    void printRideByStatus(Status s);
    vector<Ride> getDriverRides(Driver& driver);
    vector<Ride> getPassRides(Pass& pass);
    void printDriverSchedule(Passes& passes, Drivers& drivers);
    void printPassSchedule(Passes& passes, Drivers& drivers);
    void removeUselessRides();
    bool rideListEmpty();
    unordered_map<int, Ride> rideList;
private:
    int nextId;

};

#endif //RIDES_H