#include "Util.h"

int Util::intInput(string message, int start, int end) {
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

void Util::load(Rides &rides, Passes &passes, Drivers &drivers) {
    ifstream in("meanGreenData");
    if (in.good()) {
        vector<Pass> passList;
        vector<Driver> driverList;
        vector<Ride> rideList;
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
                passList.push_back(p);
            }
            else if (type == 'd') {
                in.ignore();
                getline(in, name);
                getline(in, notes);
                in >> id >> cap >> hcp >> type >> rat >> open >> pets;
                Driver d(name, id, cap, hcp, type, rat, open, pets, notes);
                driverList.push_back(d);
            }
            else if (type == 'r') {
                in.ignore();
                getline(in, pickLoc);
                getline(in, dropLoc);
                in >> id >> pickTime >> cap >> pets >> dropTime >> status >> rat >> passId >> driverId;
                Ride r(id, pickLoc, pickTime, dropLoc, cap, pets, dropTime, status, rat, passId, driverId);
                rideList.push_back(r);
            }
        }
        passes.setPassList(passList);
        drivers.setDriverList(driverList);
        rides.setRideList(rideList);
    }
    in.close();
}

void Util::save(Rides &rides, Passes &passes, Drivers &drivers) {
    ofstream out("meanGreenData");
    for (const auto& p : passes.getPassList())
        out << 'p' << endl << p.getName() << endl << p.getId() << " " << p.getPayType() << " " << p.getHcp() << " " <<
                p.getMinRating() << " " << p.getPets() << endl;
    for (const auto& d : drivers.getDriverList())
        out << 'd' << endl << d.getName() << endl << d.getNotes() << endl << d.getId() << " " << d.getCap() << " " <<
                d.getHcp() << " " << d.getType() << " " << d.getRating() << " " << d.getOpen() << " " << d.getPets() << endl;
    for (const auto& r : rides.getRideList())
        out << 'r' << " " << endl << r.getPickLoc() << endl << r.getDropLoc() << endl << r.getId() << " " << r.getPickTime() <<
                " " << r.getSize() << " " << r.getPets() << " " << r.getDropTime() << " " <<
                r.getStatus() << " " << r.getRating() << " " << r.getPassId() << " " << r.getDriverId() << endl;
    out.close();
}

void Util::prettyPrint(vector<string> messages) {
    int origWidth = (int) messages[0].length() + 6;
    int maxWidth = origWidth;
    for (unsigned int i = 1; i < messages.size(); i++) {
        cout << messages[i] << endl;
        if (messages[i].size() + 4 > maxWidth) {
            maxWidth = (int) messages[i].length() + 4;
        }
    }
    int diff = 0;
    if (origWidth != maxWidth) {
        if (maxWidth % 2 == 1) maxWidth++;
        diff = (maxWidth - origWidth) / 2;
        cout << maxWidth << " " << origWidth << " " << diff << endl;
    }
    cout << "+" << string(diff, '-') << "- " << messages[0] << " -" << string(diff, '-') << "-+" << endl;
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