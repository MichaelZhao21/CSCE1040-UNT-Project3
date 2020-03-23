#include "Util.h"

int Util::intInput(const string& message, int start, int end) {
    int input = start - 1;
    cout << message;
    cin >> input;
    while (cin.fail() || input < start || input > end) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << message;
        cin >> input;
    }
    cin.ignore();
    return input;
}

unordered_map<TextLabel, vs> Util::getText() {
    unordered_map<TextLabel, vs> text {
        {
            TextLabel::INTRO,
                {"CSCE 1040 PROJECT 3",
                 "Name:        Michael Zhao (michaelzhao314@gmail.com)",
                 "Date:        3/20/2020",
                 "Instructor:  Mark Keathly",
                 "Description: This project is a simulation of a real system used to schedule drivers",
                 "             and passengers using a transaction-based class system. The system can",
                 "             create schedules, manage rides, and automatically checks for requirements",
                 "             before allocating drivers to passengers. Additionally, it has a save and",
                 "             load system as well as input checking."}
        },
        {
            TextLabel::MAIN_MENU,
                {"MEAN GREEN EAGLELIFT SYSTEM",
                 "1. Driver Menu",
                 "2. Passenger Menu"}
        }};
    return text;
}

int Util::menu(const vs& text) {
    prettyPrint(text);
    return intInput("Enter an option: ", 1, text.size());
}

void Util::load(Rides &rides, Passes &passes, Drivers &drivers) {
    ifstream in("meanGreenData");
    if (in.good()) {
        unordered_map<int, Pass> passMap {};
        unordered_map<int, Driver> driverMap {};
        unordered_map<int, Ride> rideMap {};
        string name, notes, pickLoc, dropLoc;
        int pay, id, cap, status, passId, driverId;
        double rat;
        long pickTime, dropTime;
        bool hcp, pets, open;
        char type;
        while (in >> type) {
            if (type == 'p') {
                in.ignore();
                getline(in, name);
                in >> id >> pay >> hcp >> rat >> pets;
                Pass p(name, id, (PayType) pay, hcp, rat, pets);
                passMap[id] = p;
            }
            else if (type == 'd') {
                in.ignore();
                getline(in, name);
                getline(in, notes);
                in >> id >> cap >> hcp >> type >> rat >> open >> pets;
                Driver d(name, id, cap, hcp, (VehicleType) type, rat, open, pets, notes);
                driverMap[id] = d;
            }
            else if (type == 'r') {
                in.ignore();
                getline(in, pickLoc);
                getline(in, dropLoc);
                in >> id >> pickTime >> cap >> pets >> dropTime >> status >> rat >> passId >> driverId;
                Ride r(id, pickLoc, pickTime, dropLoc, cap, pets, dropTime, (Status) status, rat, passId, driverId);
                rideMap[id] = r;
            }
        }
        passes.setPassList(passMap);
        drivers.setDriverList(driverMap);
        rides.setRideList(rideMap);
    }
    in.close();
}

void Util::save(Rides &rides, Passes &passes, Drivers &drivers) {
    ofstream out("meanGreenData");
    for (pair<int, Pass> pp : passes.getPassList()) {
        Pass p = pp.second;
        out << 'p' << endl << p.getName() << endl << p.getId() << " " << p.getPayType() << " " << p.getHcp() << " " <<
                p.getMinRating() << " " << p.getPets() << endl;
    }
    for (pair<int, Driver> dp : drivers.getDriverList()) {
        Driver d = dp.second;
        out << 'd' << endl << d.getName() << endl << d.getNotes() << endl << d.getId() << " " << d.getCap() << " " <<
            d.getHcp() << " " << d.getType() << " " << d.getRating() << " " << d.getOpen() << " " << d.getPets()
            << endl;
    }
    for (pair<int, Ride> rp : rides.getRideList()) {
        Ride r = rp.second;
        out << 'r' << " " << endl << r.getPickLoc() << endl << r.getDropLoc() << endl << r.getId() << " " << r.getPickTime() <<
                " " << r.getSize() << " " << r.getPets() << " " << r.getDropTime() << " " <<
                r.getStatus() << " " << r.getRating() << " " << r.getPassId() << " " << r.getDriverId() << endl;
    }
    out.close();
}

void Util::prettyPrint(vs messages) {
    int origWidth = (int) messages[0].length() + 6;
    int maxWidth = origWidth;
    for (unsigned int i = 1; i < messages.size(); i++) {
        if (messages[i].size() + 4 > maxWidth) {
            maxWidth = (int) messages[i].length() + 4;
        }
    }
    int diff = 0;
    int uneven = 0;
    if (origWidth != maxWidth) {
        if (maxWidth % 2 == 1) {
            maxWidth++;
            if (origWidth % 2 == 0)
                uneven++;
        };
        diff = (maxWidth - origWidth) / 2;
    }
    cout << "+" << string(diff - uneven, '-') << "- " << messages[0] << " -" << string(diff, '-') << "-+" << endl;
    for (unsigned int i = 1; i < messages.size(); i++) {
        diff = maxWidth - messages[i].length() - 4;
        cout << "| " << messages[i] << string(diff, ' ') << " |" << endl;
    }
    cout << "+" << string(maxWidth - 2, '-') << "+" << endl << endl;
}

string Util::bts(bool in) {
    if (in) return "yes";
    return "no";
}

string Util::printTime(time_t milli) {
    return ctime(&milli);
}

string Util::printUnlessDefault(double in, bool time) {
    if (in == -1) return "N/A";
    if (time) return printTime(in);
    return to_string(in);
}

int Util::genId(int digits) {
    int start = pow(10, digits);
    int end = digits * 10 - 1;
    return rand() % end + start;
}