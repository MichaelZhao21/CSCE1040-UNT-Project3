#include "Util.h"
using namespace std;

// Global text storage vector
unordered_map<TextLabel, vs> blockText;

int main() {
    // Set block text
    Util::setBlockText();

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