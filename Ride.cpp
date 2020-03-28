#include "Util.h"
#include "Ride.h"

Ride::Ride() : id(0), pickLoc(""), pickTime(0), dropLoc(""), size(0), pets(false), dropTime(0),
               status(ACTIVE), rating(0), passId(0), driverId(0) {}

Ride::Ride(int id, const string &pickLoc, time_t pickTime, const string &dropLoc, int size, bool pets, time_t dropTime, int passId,
        int driverId) : id(id), pickLoc(pickLoc), pickTime(pickTime),dropLoc(dropLoc), size(size), pets(pets),
                        dropTime(dropTime), status(ACTIVE), rating(-1), passId(passId), driverId(driverId) {}

Ride::Ride(int id, const string &pickLoc, time_t pickTime, const string &dropLoc, int size, bool pets, time_t dropTime,
           Status status, double rating, int passId, int driverId) : id(id), pickLoc(pickLoc), pickTime(pickTime),
                                                                  dropLoc(dropLoc), size(size), pets(pets),
                                                                  dropTime(dropTime), status(status), rating(rating),
                                                                  passId(passId), driverId(driverId) {}

int Ride::getId() const {
    return id;
}

void Ride::setId(int id) {
    Ride::id = id;
}

const string &Ride::getPickLoc() const {
    return pickLoc;
}

void Ride::setPickLoc(const string &pickLoc) {
    Ride::pickLoc = pickLoc;
}

time_t Ride::getPickTime() const {
    return pickTime;
}

void Ride::setPickTime(time_t pickTime) {
    Ride::pickTime = pickTime;
}

const string &Ride::getDropLoc() const {
    return dropLoc;
}

void Ride::setDropLoc(const string &dropLoc) {
    Ride::dropLoc = dropLoc;
}

int Ride::getSize() const {
    return size;
}

void Ride::setSize(int size) {
    Ride::size = size;
}

bool Ride::getPets() const {
    return pets;
}

void Ride::setPets(bool pets) {
    Ride::pets = pets;
}

time_t Ride::getDropTime() const {
    return dropTime;
}

void Ride::setDropTime(time_t dropTime) {
    Ride::dropTime = dropTime;
}

Status Ride::getStatus() const {
    return status;
}

void Ride::setStatus(Status status) {
    Ride::status = status;
}

double Ride::getRating() const {
    return rating;
}

void Ride::setRating(double rating) {
    Ride::rating = rating;
}

int Ride::getPassId() const {
    return passId;
}

void Ride::setPassId(int passId) {
    Ride::passId = passId;
}

int Ride::getDriverId() const {
    return driverId;
}

void Ride::setDriverId(int driverId) {
    Ride::driverId = driverId;
}

void Ride::printRide() {
    string pt = Util::printTime(time(nullptr));
    string dt = Util::printUnlessDefault(dropTime, true);
    vs text {"Ride #" + to_string(id),
                         "Pickup Location: " + pickLoc,
                         "Pickup Time: " + pt.substr(0, pt.size() - 1),
                         "Drop-off Location: " + dropLoc,
                         "Size of party: " + to_string(size),
                         "Includes pets: " + Util::bts(pets),
                         "Drop-off Time: " + (dt != "N/A" ? dt.substr(0, dt.size() - 1) : dt),
                         "Status: " + statusToString(status),
                         "Rating by Customer: " + Util::printUnlessDefault(rating, false),
                         "Passenger ID: " + to_string(passId),
                         "Driver ID: " + to_string(driverId)};
    Util::prettyPrint(text);
}

string Ride::statusToString(Status s) {
    switch (s) {
        case ACTIVE:
            return "Active";
        case COMPLETED:
            return "Completed";
        case CANCELLED:
            return "Cancelled";
        default:
            perror("Invalid Status in Ride::statusToString");
            return "";
    }
}