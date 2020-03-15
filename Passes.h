#ifndef PASSES_H
#define PASSES_H

#include <vector>
#include <iostream>
#include "Pass.h"
using namespace std;

class Passes {
public:

    Passes();

    explicit Passes(const vector<Pass> &passList);

    const vector<Pass> &getPassList() const;

    void setPassList(const vector<Pass> &passList);

    void addPass();

    void editPass();

    void deletePass();

    void printAllPasses();

private:
    vector<Pass> passList;
};

#endif //PASSES_H
