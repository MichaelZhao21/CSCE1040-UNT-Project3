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
    void editRide();
    void removeRide();
    int findRide();
    void cancelRide();
    void rateRides();
    void printAllRides();
    unordered_map<int, Ride> findAllPassRides();
    unordered_map<int, Ride> findAllDriverRides();
    void printActiveRides();
    void printCompletedRides();
    void printCancelledRides();
    vector<Ride> getDriverRides(Driver& driver);
    vector<Ride> getPassRides(Pass& pass);
    void printDriverSchedule(Drivers& drivers);
    void printPassSchedule(Passes& passes);
    void removeUselessRides();
    unordered_map<int, Ride> rideList;
private:
    int nextId;
};

#endif //RIDES_H