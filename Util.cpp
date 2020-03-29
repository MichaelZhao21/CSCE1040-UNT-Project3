#include "Util.h"

#include <utility>

bool Util::parseInput(int& in, const string& message, int start, int end, bool checkDefault) {
    in = start - 1;
    while (cin.fail() || in < start || in > end) {
        cout << message << " (" << start << "-" << end << "): ";
        if (checkDefault && cin.peek() == '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        cin >> in;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return true;
}

bool Util::parseInput(double& in, const string &message, double start, double end, bool checkDefault) {
    in = start - 1;
    bool fail = true;
    while (fail) {
        fail = false;
        cout << message << " (" << start << "-" << end << "): ";
        if (checkDefault && cin.peek() == '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        cin >> in;
        if (cin.fail() || in < start || in > end) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            fail = true;
        }
    }
    cin.ignore();
    return true;
}

bool Util::parseInput(string& in, const string &message, bool checkDefault) {
    in = "";
    while (in.empty()) {
        cout << message << ": ";
        getline(cin, in);
        if (checkDefault && in.empty())
            return false;
    }
    return true;
}

bool Util::parseInput(int &in, const string &message, const vs &enumNames, bool checkDefault) {
    int size = enumNames.size();
    bool fail = true;
    while (fail) {
        fail = false;
        cout << message << " (";
        for (int i = 1; i < size + 1; i++) {
            cout << i << " - " << enumNames[i - 1];
            if (i != size)
                cout << ", ";
        }
        cout << "): ";
        if (checkDefault && cin.peek() == '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        cin >> in;
        if (cin.fail() || in < 1 || in > enumNames.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            fail = true;
        }
    }
    cin.ignore();
    return true;
}

bool Util::parseInput(bool& in, const string &message, bool checkDefault) {
    char tempIn = ' ';
    while (toupper(tempIn) != 'Y' && toupper(tempIn) != 'N') {
        cout << message << " (y/n): ";
        if (checkDefault && cin.peek() == '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        cin >> tempIn;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    in = (toupper(tempIn) == 'Y');
    return true;
}

bool Util::parseInput(time_t& in, const string &message, bool checkDefault) {
    if (in == 0)
        in = time(nullptr);

    tm *ltm = localtime(&in);
    string date, timeIn;
    bool dateDef, timeDef;

    cout << message << ":" << endl;
    dateDef = formattedStringInput(date, "\tEnter the date (MM/DD/YYYY)", R"(^\d{2}\/\d{2}\/\d{4}$)", checkDefault);
    timeDef = formattedStringInput(timeIn, "\tEnter the time (HH:MM:SS)", R"(^\d{2}:\d{2}:\d{2}$)", checkDefault);

    if (dateDef) {
        ltm->tm_mon = stoi(date.substr(0, 2)) - 1;
        ltm->tm_mday = stoi(date.substr(3, 2));
        ltm->tm_year = stoi(date.substr(6, 4)) - 1900;
    }
    if (timeDef) {
        ltm->tm_hour = stoi(timeIn.substr(0, 2)) + 1;
        ltm->tm_min = stoi(timeIn.substr(3, 2));
        ltm->tm_sec = stoi(timeIn.substr(6, 2));
    }

    in = mktime(ltm);
    return true;
}

bool Util::formattedStringInput(string& in, const string &message, const string &format, bool checkDefault) {
    regex b(format);
    while (!regex_match(in, b)) {
        cout << message << ": ";
        if (checkDefault && cin.peek() == '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        cin >> in;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return true;
}

unordered_map<TextLabel, vs> Util::getBlockText() {
    unordered_map<TextLabel, vs> blockText;
    ifstream in("blocktext");
    string temp;
    vs currText;
    int ctr = 0;
    while (getline(in, temp)) {
        if (temp == "1") {
            blockText[(TextLabel)ctr] = currText;
            currText.clear();
            ctr++;
        }
        else currText.push_back(temp);
    }
    in.close();
    cout << "WEFJWEBFJERBGJKSRHNBGHERGKJERbgwr" << endl;
    prettyPrint(blockText[TextLabel::INTRO]);
    return blockText;
}

int Util::menu(vs text) {
    for (int i = 1; i < text.size(); i++)
        text[i] = to_string(i) + ". " + text[i];
    prettyPrint(text);
    int in;
    parseInput(in, "Choice", 1, text.size() - 1, false);
    cout << endl;
    return in;
}

void Util::load(Drivers &drivers, Passes &passes, Rides &rides) {
    ifstream in("mg.dat");
    if (in.good()) {
        unordered_map<int, Pass> passMap {};
        unordered_map<int, Driver> driverMap {};
        unordered_map<int, Ride> rideMap {};
        string name, notes, pickLoc, dropLoc;
        int pay, id, cap, status, passId, driverId, rid, pid, did, type;
        double rat;
        long pickTime, dropTime;
        bool hcp, pets, open;
        char rpd;

        in >> rid >> pid >> did;
        while (in >> rpd) {
            if (rpd == 'd') {
                in.ignore();
                getline(in, name);
                getline(in, notes);
                in >> id >> cap >> hcp >> type >> rat >> open >> pets;
                Driver d(name, id, cap, hcp, (VehicleType) type, rat, open, pets, notes);
                driverMap[id] = d;
            }
            else if (rpd == 'p') {
                in.ignore();
                getline(in, name);
                in >> id >> pay >> hcp >> rat >> pets;
                Pass p(name, id, (PayType) pay, hcp, rat, pets);
                passMap[id] = p;
            }
            else if (rpd == 'r') {
                in.ignore();
                getline(in, pickLoc);
                getline(in, dropLoc);
                in >> id >> pickTime >> cap >> pets >> dropTime >> status >> rat >> passId >> driverId;
                Ride r(id, pickLoc, pickTime, dropLoc, cap, pets, dropTime, (Status) status, rat, passId, driverId);
                rideMap[id] = r;
            }
        }
        drivers.driverList = driverMap;
        passes.passList = passMap;
        rides.rideList = rideMap;
        drivers.setNextId(did);
        passes.setNextId(pid);
        rides.setNextId(rid);
    }
    in.close();
}

void Util::save(Drivers &drivers, Passes &passes, Rides &rides) {
    ofstream out("mg.dat");
    out << rides.getNextId() << " " << passes.getNextId() << " " << drivers.getNextId() << endl;
    for (pair<int, Driver> dp : drivers.driverList) {
        Driver d = dp.second;
        out << 'd' << endl << d.getName() << endl << d.getNotes() << endl << d.getId() << " " << d.getCap() << " " <<
            d.getHcp() << " " << (int) d.getType() << " " << d.getRating() << " " << d.getOpen() << " " << d.getPets()
            << endl;
    }
    for (pair<int, Pass> pp : passes.passList) {
        Pass p = pp.second;
        out << 'p' << endl << p.getName() << endl << p.getId() << " " << (int) p.getPayType() << " " << p.getHcp() << " " <<
                p.getMinRating() << " " << p.getPets() << endl;
    }
    for (pair<int, Ride> rp : rides.rideList) {
        Ride r = rp.second;
        out << 'r' << endl << r.getPickLoc() << endl << r.getDropLoc() << endl << r.getId() << " " << r.getPickTime() <<
                " " << r.getSize() << " " << r.getPets() << " " << r.getDropTime() << " " <<
                (int) r.getStatus() << " " << r.getRating() << " " << r.getPassId() << " " << r.getDriverId() << endl;
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
    if (origWidth % 2 != maxWidth % 2) uneven++;
    if (origWidth != maxWidth)
        diff = (maxWidth - origWidth) / 2;
    cout << "+" << string(diff, '-') << "- " << messages[0] << " -" << string(diff + uneven, '-') << "+" << endl;
    for (unsigned int i = 1; i < messages.size(); i++) {
        diff = maxWidth - messages[i].length() - 4;
        cout << "| " << messages[i] << string(diff, ' ') << " |" << endl;
    }
    cout << "+" << string(maxWidth - 2, '-') << "+" << endl << endl;
}

vs Util::getList(string title, const vector<Ride>& rideGroup, bool onlyTime, Passes& passes, Drivers& drivers) {
    vs text{move(title)};
    stringstream temp;
    for (auto & r : rideGroup) {
        temp << r.getId();
        if (!onlyTime){
            temp << " | " << "P: " << passes.passList[r.getPassId()].getName() << " (#" << r.getPassId() << ") | ";
            temp << "D: " << drivers.driverList[r.getDriverId()].getName() << " (#" << r.getDriverId() << ")";
        }
        long start = r.getPickTime();
        long end = r.getDropTime();
        string st = ctime(&start);
        string et = ctime(&end);
        temp << " | " << st.substr(0, st.length() - 1) << " -> " << et.substr(0, et.length() - 1);
        text.push_back(temp.str());
        temp.clear();
    }
    return text;
}

vs Util::getList(string title, vector<Driver> driverGroup) {

}

vs Util::getList(string title, vector<Pass> passGroup) {

}


void Util::waitForEnter() {
    cout << "Press enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
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

void Util::mainLoop(Drivers& drivers, Passes& passes, Rides& rides) {
    unordered_map<TextLabel, vs> blockText = getBlockText();
    bool submenu = false;
    int choice = 0;
    int choice2 = 0;

    while (submenu || choice != 4) {
        if (submenu) {
            switch (choice) {
                case 1:
                    choice2 = menu(blockText[TextLabel::DRIVER]);
                    switch (choice2) {
                        case 1:
                            drivers.addDriver();
                            break;
                        case 2:
                            drivers.editDriver();
                            break;
                        case 3:
                            drivers.removeDriver();
                            break;
                        case 4:
                            drivers.findAndPrintDriver();
                            break;
                        case 5:
                            drivers.printAllDrivers();
                            break;
                        case 6:
                            rides.printDriverSchedule(passes, drivers);
                            break;
                        default:
                            submenu = false;
                            break;
                    }
                    break;
                case 2:
                    choice2 = menu(blockText[TextLabel::PASS]);
                    switch (choice2) {
                        case 1:
                            passes.addPass();
                            break;
                        case 2:
                            passes.editPass();
                            break;
                        case 3:
                            passes.removePass();
                            break;
                        case 4:
                            passes.findAndPrintPass();
                            break;
                        case 5:
                            passes.printAllPasses();
                            break;
                        case 6:
                            rides.addRide(passes, drivers);
                            break;
                        case 7:
                            rides.cancelRide(passes, drivers);
                            break;
                        case 8:
                            rides.rateRides(passes, drivers);
                            break;
                        case 9:
                            rides.printPassSchedule(passes, drivers);
                            break;
                        default:
                            submenu = false;
                            break;
                    }
                    break;
                case 3:
                    choice2 = menu(blockText[TextLabel::ADMIN]);
                    switch (choice2) {
                        case 1:
                            rides.printAllRides();
                            break;
                        case 2:
                            rides.findandPrintRide(passes, drivers);
                            break;
                        case 3:
                            rides.printRideByStatus(Status::ACTIVE);
                            break;
                        case 4:
                            rides.printRideByStatus(Status::COMPLETED);
                            break;
                        case 5:
                            rides.printRideByStatus(Status::CANCELLED);
                            break;
                        case 6:
                            rides.removeUselessRides();
                            break;
                        case 7:
                            Util::clearSaveFile();
                        default:
                            submenu = false;
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        else {
            choice = menu(blockText[TextLabel::MAIN]);
            submenu = (choice != 4);
        }

    }
}

void Util::clearSaveFile() {
    ofstream dat("mg.dat");
    if (dat.good())
        dat << "";
    dat.close();
}