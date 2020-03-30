#ifndef PASSES_H
#define PASSES_H

#include "Defs.h"
#include "Pass.h"
using namespace std;

class Passes {
public:
    /**
     * Constructors
     */
    Passes();
    Passes(const unordered_map<int, Pass> &passList, int nextId);

    /**
     * Getters and setters
     */
    int getNextId() const;
    void setNextId(int nextId);

    /**
     * Prompts and adds a pass
     */
    void addPass();

    /**
     * Edits a pass
     */
    void editPass();

    /**
     * Removes a pass
     */
    void removePass();

    /**
     * Prompts for an gets a pass in passList
     * @return an int representing the id of the pass found
     */
    int findPass();

    /**
     * Calls findPass() and prints that pass
     */
    void findAndPrintPass();

    /**
     * Prints all passes
     */
    void printAllPasses();

    /**
     * Checks to see if the pass list is empty,
     * outputs to the user, and waits for enter
     * @return a boolean representing the emptiness of the passlist
     */
    bool passListEmpty();

    unordered_map<int, Pass> passList;

private:
    int nextId;
public:
};

#endif //PASSES_H
