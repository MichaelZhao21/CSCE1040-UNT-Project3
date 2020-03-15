#include "Driver.h"

Driver::Driver() : name(""), id(0), cap(0), hcp(false), type(0), rating(0.0), open(false), pets(false), notes("") {}

Driver::Driver(const string &name, int id, int cap, bool hcp, int type, double rating, bool open, bool pets,
               const string &notes) : name(name), id(id), cap(cap), hcp(hcp), type(type), rating(rating), open(open),
                                      pets(pets), notes(notes) {}

const string &Driver::getName() const {
    return name;
}

void Driver::setName(const string &name) {
    Driver::name = name;
}

int Driver::getId() const {
    return id;
}

void Driver::setId(int id) {
    Driver::id = id;
}

int Driver::getCap() const {
    return cap;
}

void Driver::setCap(int cap) {
    Driver::cap = cap;
}

bool Driver::getHcp() const {
    return hcp;
}

void Driver::setHcp(bool hcp) {
    Driver::hcp = hcp;
}

int Driver::getType() const {
    return type;
}

void Driver::setType(int type) {
    Driver::type = type;
}

double Driver::getRating() const {
    return rating;
}

void Driver::setRating(int rating) {
    Driver::rating = rating;
}

bool Driver::getOpen() const {
    return open;
}

void Driver::setOpen(bool open) {
    Driver::open = open;
}

bool Driver::getPets() const {
    return pets;
}

void Driver::setPets(bool pets) {
    Driver::pets = pets;
}

const string &Driver::getNotes() const {
    return notes;
}

void Driver::setNotes(const string &notes) {
    Driver::notes = notes;
}

void Driver::printDriver() {
    // TODO printDriver
}
