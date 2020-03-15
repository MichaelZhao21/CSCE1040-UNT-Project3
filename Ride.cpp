//
// Created by micha on 3/8/2020.
//

#include "Ride.h"

Ride::Ride() : id(0), pickLoc(""), pickTime(0), dropLoc(""), size(0), pets(false), dropTime(0),
               status(0), rating(0), passId(0), driverId(0) {}

Ride::Ride(int id, const string &pickLoc, long pickTime, const string &dropLoc, int size, bool pets, int passId,
        int driverId) : id(id), pickLoc(pickLoc), pickTime(pickTime),dropLoc(dropLoc), size(size), pets(pets),
                        dropTime(0), status(0), rating(0), passId(passId), driverId(driverId) {}


Ride::Ride(int id, const string &pickLoc, long pickTime, const string &dropLoc, int size, bool pets, long dropTime,
           int status, double rating, int passId, int driverId) : id(id), pickLoc(pickLoc), pickTime(pickTime),
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

long Ride::getPickTime() const {
    return pickTime;
}

void Ride::setPickTime(long pickTime) {
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

long Ride::getDropTime() const {
    return dropTime;
}

void Ride::setDropTime(long dropTime) {
    Ride::dropTime = dropTime;
}

int Ride::getStatus() const {
    return status;
}

void Ride::setStatus(int status) {
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
    // TODO printRide
}
