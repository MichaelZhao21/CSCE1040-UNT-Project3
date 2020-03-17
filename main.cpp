#include "Util.h"
using namespace std;

int main() {
    // Declare collector objects
    Drivers drivers;
    Passes passes;
    Rides rides;

    // Load previous instance, if possible
    Util::load(rides, passes, drivers);

    // Test!
    Driver d("John", 534291, 5, false, 2, 5, true, false, "I AM COOL");
    Pass p("Michael", 320668, (PayType) 2, true, 1, true);
    Ride r(327121, "3208 Mill Ridge Dr", 1583798400, "4428 Waskom Dr", 5, false, 320668, 534291);

    p.printPass();

    rides.setRideList(vector<Ride>{r});
    passes.setPassList(vector<Pass>{p});
    drivers.setDriverList(vector<Driver>{d});
    Util::save(rides, passes, drivers);
    cout << d.getNotes() << endl;

    return 0;
}