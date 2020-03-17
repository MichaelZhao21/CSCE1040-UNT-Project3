#include "Util.h"

Rides::Rides() : rideList(unordered_map<int, Ride>()) {}

Rides::Rides(const unordered_map<int, Ride> &rideList) : rideList(rideList) {}

const unordered_map<int, Ride> &Rides::getRideList() const {
    return rideList;
}

void Rides::setRideList(const unordered_map<int, Ride> &rideList) {
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

unordered_map<int, Ride> Rides::findAllPassRides() {
    return unordered_map<int, Ride>();
}

unordered_map<int, Ride> Rides::findAllDriverRides() {
    return unordered_map<int, Ride>();
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
