#ifndef FUNCS_H
#define FUNCS_H

#include "Defs.h"
#include "Ride.h"
#include "Rides.h"
#include "Pass.h"
#include "Passes.h"
#include "Driver.h"
#include "Drivers.h"


enum TextLabel {INTRO, MAIN_MENU, DRIVER_MENU, PASS_MENU, ADMIN_MENU};

class Util {
public:
    static int intInput(const string& message, int start, int end);
    static unordered_map<TextLabel, vs> getText();
    static int menu(const vs& text);
    static void load(Rides &rides, Passes &passes, Drivers &drivers);
    static void save(Rides &rides, Passes &passes, Drivers &drivers);
    static void prettyPrint(vector<string> messages);
    static string bts(bool in);
    static string printTime(long milli);
    static string printUnlessDefault(double in, bool time);
    static int genId(int digits);
};

#endif //FUNCS_H