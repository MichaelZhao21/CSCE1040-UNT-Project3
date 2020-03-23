#include "Passes.h"

Passes::Passes() : passList(unordered_map<int, Pass>()){}

Passes::Passes(const unordered_map<int, Pass> &passList) : passList(passList) {}

const unordered_map<int, Pass> &Passes::getPassList() const {
    return passList;
}

void Passes::setPassList(const unordered_map<int, Pass> &passList) {
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