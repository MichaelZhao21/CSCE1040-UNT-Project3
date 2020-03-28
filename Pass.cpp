#include "Util.h"

Pass::Pass() : name(""), id(0), payType(PayType::CASH), hcp(false), minRating(0), pets(0) {}

Pass::Pass(const string &name, int id, PayType payType, bool hcp, double minRating, bool pets) : name(name), id(id),
                                                                                                 payType(payType),
                                                                                                 hcp(hcp),
                                                                                                 minRating(minRating),
                                                                                                 pets(pets) {}

const string &Pass::getName() const {
    return name;
}

void Pass::setName(const string &name) {
    Pass::name = name;
}

int Pass::getId() const {
    return id;
}

void Pass::setId(int id) {
    Pass::id = id;
}

PayType Pass::getPayType() const {
    return payType;
}

void Pass::setPayType(PayType payType) {
    Pass::payType = payType;
}

bool Pass::getHcp() const {
    return hcp;
}

void Pass::setHcp(bool hcp) {
    Pass::hcp = hcp;
}

double Pass::getMinRating() const {
    return minRating;
}

void Pass::setMinRating(double minRating) {
    Pass::minRating = minRating;
}

bool Pass::getPets() const {
    return pets;
}

void Pass::setPets(bool pets) {
    Pass::pets = pets;
}

void Pass::printPass() {
    vs text {"Passenger #" + to_string(id),
                  "Name: " + name,
                  "Payment Preference: " + payTypeToString(payType),
                  "Handicapped: " + Util::bts(hcp),
                  "Default rating required: " + to_string(minRating),
                  "Has pets: " + Util::bts(pets)
                  };
    Util::prettyPrint(text);
}

string Pass::payTypeToString(PayType p) {
    switch (p) {
        case CASH:
            return "Cash";
        case CREDIT:
            return "Credit";
        case DEBIT:
            return "Debit";
        default:
            perror("Invalid PayType in Pass::payTypeToString");
            return "";
    }
}
