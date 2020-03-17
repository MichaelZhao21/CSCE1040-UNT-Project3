#ifndef RIDES_H
#define RIDES_H

#include "Defs.h"
#include "Ride.h"
using namespace std;

class Rides {
public:
    Rides();

    Rides(const unordered_map<int, Ride> &rideList);

    const unordered_map<int, Ride> &getRideList() const;

    void setRideList(const unordered_map<int, Ride> &rideList);

    void addRide();
    bool checkDriverOpen();
    void editRide();
    void removeRide();
    Ride findRide();
    void printAllRides();
    unordered_map<int, Ride> findAllPassRides();
    unordered_map<int, Ride> findAllDriverRides();
    void printActiveRides();
    void printCompletedRides();
    void printCancelledRides();
    void printDriverSchedule();
    void printPassSchedule();
    void removeUselessRides();

private:
    unordered_map<int, Ride> rideList;
};

#endif //RIDES_H