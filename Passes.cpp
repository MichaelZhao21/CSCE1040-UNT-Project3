#include "Passes.h"

Passes::Passes() : passList(vector<Pass>()) {};

Passes::Passes(const vector<Pass> &passList) : passList(passList) {}

const vector<Pass> &Passes::getPassList() const {
    return passList;
}

void Passes::setPassList(const vector<Pass> &passList) {
    Passes::passList = passList;
}

void Passes::addPass() {
}

void Passes::editPass() {

}

void Passes::deletePass() {

}

void Passes::printAllPasses() {

}
