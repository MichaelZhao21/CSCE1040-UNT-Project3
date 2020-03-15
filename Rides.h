#ifndef RIDES_H
#define RIDES_H

#include <iostream>
#include <vector>
#include "Ride.h"
using namespace std;

class Rides {
public:
    Rides();

    explicit Rides(const vector<Ride> &rideList);

    void addRide();

    bool checkDriverOpen();

    void editRide();

    void removeRide();

    Ride findRide();

    void printAllRides();

    vector<Ride> findAllPassRides();

    vector<Ride> findAllDriverRides();

    void printActiveRides();

    void printCompletedRides();

    void printCancelledRides();

    void printDriverSchedule();

    void printPassSchedule();

    void removeUselessRides();

private:
    vector<Ride> rideList;
public:
    const vector<Ride> &getRideList() const;

    void setRideList(const vector<Ride> &rideList);
};


#endif //RIDES_H
