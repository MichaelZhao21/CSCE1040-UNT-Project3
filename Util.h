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

    static void load(Rides &rides, Passes &passes, Drivers &drivers);

    static void save(Rides &rides, Passes &passes, Drivers &drivers);

    static void prettyPrint(vector<string> messages);

    static string bts(bool in);
};


#endif //FUNCS_H