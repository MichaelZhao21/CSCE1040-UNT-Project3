#ifndef PASSES_H
#define PASSES_H

#include "Defs.h"
#include "Pass.h"
using namespace std;

class Passes {
public:
    Passes();

    Passes(const unordered_map<int, Pass> &passList);

    const unordered_map<int, Pass> &getPassList() const;

    void setPassList(const unordered_map<int, Pass> &passList);

    void addPass();

    void editPass();

    void deletePass();

    void printAllPasses();

private:
    unordered_map<int, Pass> passList;
};

#endif //PASSES_H
