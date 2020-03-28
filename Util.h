#ifndef FUNCS_H
#define FUNCS_H

#include "Defs.h"
#include "Ride.h"
#include "Rides.h"
#include "Pass.h"
#include "Passes.h"
#include "Driver.h"
#include "Drivers.h"

enum TextLabel {INTRO, MAIN, DRIVER, PASS, ADMIN};

extern unordered_map<TextLabel, vs> blockText;

class Util {
public:
    static bool parseInput(int& in, const string& message, int start, int end, bool checkDefault);
    static bool parseInput(double& in, const string& message, double start, double end, bool checkDefault);
    static bool parseInput(string& in, const string& message, bool checkDefault);
    static bool parseInput(int &in, const string &message, const vs &enumNames, bool checkDefault);
    static bool parseInput(bool& in, const string& message, bool checkDefault);
    static bool parseInput(time_t& in, const string& message, bool checkDefault);
    static bool formattedStringInput(string& in, const string& message, const string& format, bool checkDefault);
    static void setBlockText();
    static int menu(vs text);
    static void load(Drivers &drivers, Passes &passes, Rides &rides);
    static void save(Drivers &drivers, Passes &passes, Rides &rides);
    static void prettyPrint(vector<string> messages);
    static void waitForEnter();
    static string bts(bool in);
    static string printTime(long milli);
    static string printUnlessDefault(double in, bool time);
    static void mainLoop(Drivers &drivers, Passes &passes, Rides &rides);
};

#endif //FUNCS_H