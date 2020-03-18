#ifndef FUNCS_H
#define FUNCS_H

#include "Defs.h"
#include "Ride.h"
#include "Rides.h"
#include "Pass.h"
#include "Passes.h"
#include "Driver.h"
#include "Drivers.h"

class Util {
public:
    static int intInput(string message, int start, int end);
    static void printIntro();
    static void printMenu();
    static int getMenuOption();
    static void load(Rides &rides, Passes &passes, Drivers &drivers);
    static void save(Rides &rides, Passes &passes, Drivers &drivers);
    static void prettyPrint(vector<string> messages);
    static string bts(bool in);
    static string printTime(long milli);
    static string printUnlessDefault(double in, bool time);
};

#endif //FUNCS_H