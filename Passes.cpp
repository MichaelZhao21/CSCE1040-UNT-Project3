#include "Util.h"
#include "Passes.h"


Passes::Passes() : passList(unordered_map<int, Pass>()), nextId(100000) {}

Passes::Passes(const unordered_map<int, Pass> &passList, int nextId) : passList(passList), nextId(nextId) {}

int Passes::getNextId() const {
    return nextId;
}

void Passes::setNextId(int nextId) {
    Passes::nextId = nextId;
}

void Passes::addPass() {
    string name;
    int id, payType;
    bool hcp, pets;
    double minRating;

    cout << "<<< Add Passenger >>>" << endl;
    id = nextId++;
    Util::parseInput(name, "Name", false);
    Util::parseInput(payType, "Payment type", vs{"Cash", "Credit", "Debit"}, false);
    Util::parseInput(hcp, "Handicapped", false);
    Util::parseInput(minRating, "Min rating required", 0, 5, false);
    Util::parseInput(pets, "Has pets", false);
    cout << endl;

    passList[id] = Pass(name, id, (PayType) payType, hcp, minRating, pets);
    passList[id].printPass();
    Util::waitForEnter();
}

void Passes::editPass() {
    string name;
    int id, payType;
    bool hcp, pets;
    double minRating;

    cout << "<<< Edit Passenger >>>" << endl;
    if (passListEmpty()) return;
    int index = findPass();

    cout << "<<< Edit information for Passenger #" << index << " >>>" << endl;
    if (Util::parseInput(name, "Name", true)) passList[index].setName(name);
    if (Util::parseInput(payType, "Payment type", vs{"Cash", "Credit", "Debit"}, true)) passList[index].setPayType((PayType) payType);
    if (Util::parseInput(hcp, "Handicapped", true)) passList[index].setHcp(hcp);
    if (Util::parseInput(minRating, "Min rating required", 0, 5, true)) passList[index].setMinRating(minRating);
    if (Util::parseInput(pets, "Has pets", true)) passList[index].setPets(pets);
    cout << endl;

    passList[index].printPass();
    Util::waitForEnter();
}

void Passes::removePass() {
    cout << "<<< Remove Passenger >>>" << endl;
    if (passListEmpty()) return;
    passList.erase(findPass());
    cout << endl;
}

int Passes::findPass() {
    if (passListEmpty()) {
        perror("PassList empty in Passes::findPass");
        exit(1);
    }
    vs text {"Pick a passenger"};
    for (pair<int, Pass> pp : passList) {
        text.push_back(to_string(pp.first) + " | " + pp.second.getName());
    }
    int index = Util::menu(text);
    return stoi(text[index]);
}

void Passes::findAndPrintPass() {
    cout << "<<< Find Passenger >>>" << endl;
    if (passListEmpty()) return;
    passList[findPass()].printPass();
    Util::waitForEnter();
}

void Passes::printAllPasses() {
    cout << "<<< Print All Passengers >>>" << endl;
    if (passListEmpty()) return;
    for (pair<int, Pass> p : passList)
        p.second.printPass();
    Util::waitForEnter();
}

bool Passes::passListEmpty() {
    if (passList.empty()) {
        cout << "No passengers :(" << endl << endl;
        Util::waitForEnter();
        return true;
    }
    return false;
}