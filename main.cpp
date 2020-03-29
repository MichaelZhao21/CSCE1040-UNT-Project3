#include "Util.h"
using namespace std;

int main() {
    // Declare collector objects
    Drivers drivers;
    Passes passes;
    Rides rides;

    // Load :P
    Util::load(drivers, passes, rides);

    // Menu system
    Util::mainLoop(drivers, passes, rides);

    // Save :DD
    Util::save(drivers, passes, rides);

    // Don't forget this!!!
    return 0;
}