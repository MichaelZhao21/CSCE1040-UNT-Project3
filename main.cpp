#include "Util.h"
using namespace std;

int main() {
    // Seed random number generator
    srand(time(nullptr));

    // Get text
    unordered_map<TextLabel, vs> text = Util::getText();

    // Declare collector objects
    Drivers drivers;
    Passes passes;
    Rides rides;

    // Load previous instance, if possible
    Util::load(rides, passes, drivers);

    // Print intro
    Util::prettyPrint(text[TextLabel::INTRO]);

    // Main loop
//    int input = Util::menu(text[TextLabel::MAIN_MENU]);
//    while (input != 9) {
//        input = Util::menu(text[TextLabel::MAIN_MENU]);
//    }

    // Test!
    Driver d("John", 534291, 5, false, (VehicleType) 1, 5, true, false, "I AM COOL");
    Pass p("Michael", 320668, (PayType) 2, true, 1, true);
    Ride r(327121, "3208 Mill Ridge Dr", 1584465660, "4428 Waskom Dr", 5, false, 320668, 534291);
    rides.setRideList(unordered_map<int, Ride>({{r.getId(), r}}));
    passes.setPassList(unordered_map<int, Pass>({{p.getId(), p}}));
    drivers.setDriverList(unordered_map<int, Driver>({{d.getId(), d}}));

    p.printPass();
    d.printDriver();
    r.printRide();

    // Save file
    Util::save(rides, passes, drivers);
    return 0;
}