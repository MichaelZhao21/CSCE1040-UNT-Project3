#ifndef PASSES_H
#define PASSES_H

#include "Defs.h"
#include "Pass.h"
using namespace std;

class Passes {
public:
    Passes();
    Passes(const unordered_map<int, Pass> &passList, int nextId);
    int getNextId() const;
    void setNextId(int nextId);
    void addPass();
    void editPass();
    void removePass();
    int findPass();
    void findAndPrintPass();
    void printAllPasses();
    bool passListEmpty();
    unordered_map<int, Pass> passList;
private:
    int nextId;
public:
};

#endif //PASSES_H
