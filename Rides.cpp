#include "Rides.h"

Rides::Rides() : rideList(vector<Ride>()) {}

Rides::Rides(const vector<Ride> &rideList) : rideList(rideList) {}

const vector<Ride> &Rides::getRideList() const {
    return rideList;
}

void Rides::setRideList(const vector<Ride> &rideList) {
    Rides::rideList = rideList;
}

void Rides::addRide() {
}

bool Rides::checkDriverOpen() {
    return false;
}

void Rides::editRide() {

}

void Rides::removeRide() {

}

Ride Rides::findRide() {
    return Ride();
}

void Rides::printAllRides() {

}

vector<Ride> Rides::findAllPassRides() {
    return vector<Ride>();
}

vector<Ride> Rides::findAllDriverRides() {
    return vector<Ride>();
}

void Rides::printActiveRides() {

}

void Rides::printCompletedRides() {

}

void Rides::printCancelledRides() {

}

void Rides::printDriverSchedule() {

}

void Rides::printPassSchedule() {

}

void Rides::removeUselessRides() {

}

