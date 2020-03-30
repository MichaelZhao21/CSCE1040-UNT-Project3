#ifndef FUNCS_H
#define FUNCS_H

#include "Defs.h"
#include "Ride.h"
#include "Rides.h"
#include "Pass.h"
#include "Passes.h"
#include "Driver.h"
#include "Drivers.h"

enum TextLabel {INTRO = 0, MAIN, DRIVER, PASS, ADMIN};

class Util {
public:
    /**
     * Parses input and makes sure it matches the "in" type, checking to make sure it's in range
     *
     * @param in - variable to input into
     * @param message - message for the user
     * @param min - minimum input value
     * @param max - max input value
     * @param checkDefault - Is no value allowed
     * @return a boolean representing if a value was entered
     */
    static bool parseInput(int& in, const string& message, int min, int max, bool checkDefault);
    
    /**
     * Parses input and makes sure it matches the "in" type, checking to make sure it's in range
     *
     * @param in - variable to input into
     * @param message - message for the user
     * @param min - minimum input value
     * @param max - max input value
     * @param checkDefault - Is no value allowed
     * @return a boolean representing if a value was entered
     */
    static bool parseInput(double& in, const string& message, double min, double max, bool checkDefault);
    
    /**
     * Parses input and makes sure it matches the "in" type
     *
     * @param in - variable to input into
     * @param message - message for the user
     * @param checkDefault - Is no value allowed
     * @return a boolean representing if a value was entered
     */
    static bool parseInput(string& in, const string& message, bool checkDefault);
    
    /**
     * Parses input and makes sure it matches the "in" type, printing the list of enums out
     *
     * @param in - variable to input into
     * @param message - message for the user
     * @param enumNames - The string list of enum names
     * @param checkDefault - Is no value allowed
     * @return a boolean representing if a value was entered
     */
    static bool parseInput(int &in, const string &message, const vs &enumNames, bool checkDefault);
    
    /**
     * Parses input and makes sure it matches the "in" type
     *
     * @param in - variable to input into
     * @param message - message for the user
     * @param checkDefault - Is no value allowed
     * @return a boolean representing if a value was entered
     */
    static bool parseInput(bool& in, const string& message, bool checkDefault);
    
    /**
     * Parses input and makes sure it matches the "in" type
     *
     * @param in - variable to input into
     * @param message - message for the user
     * @param checkDefault - Is no value allowed
     * @return a boolean representing if a value was entered
     */
    static bool parseInput(time_t& in, const string& message, bool checkDefault);
    
    /**
     * Parses a string input using a regular expression
     * 
     * @param in - String to store input in
     * @param message - Prompt to the user
     * @param format - Regex formatting
     * @param checkDefault - Is no value allowed
     * @return a boolean representing if a value was entered
     */
    static bool formattedStringInput(string& in, const string& message, const string& format, bool checkDefault);
    
    /**
     * Gets the large blocks of text from the text file
     * 
     * @return - A hashmap representing each text block as a vector of strings
     */
    static unordered_map<TextLabel, vs> getBlockText();
    
    /**
     * Prints out a menu by adding numbers to the beginning of each line
     * and getting the user input and returning that
     * 
     * @param text - The vector of strings as menu options
     * @return - The menu choice chosen
     */
    static int menu(vs text);
    
    /**
     * Loads the information from the save file
     *
     * @param drivers - Drivers object
     * @param passes - Passengers object
     * @param rides - Rides object
     */
    static void load(Drivers &drivers, Passes &passes, Rides &rides);
    
    /**
     * Writes the information to a file
     *
     * @param drivers - Drivers object
     * @param passes - Passengers object
     * @param rides - Rides object
     */
    static void save(Drivers &drivers, Passes &passes, Rides &rides);
    
    /**
     * Prints the vector of strings in a pretty box
     * With the first string being the title
     * It automatically calculates width and forms the box
     *
     * @param messages - The vector of strings to print, by line
     */
    static void prettyPrint(vs messages);
    
    /**
     * Gets a list of rides and converts it into a vector of strings that can
     * be outputted to the user for a menu
     *
     * @param title - The title of the menu
     * @param rideGroup - The vector of Rides to print
     * @param onlyTime - See if we want to only print time
     * @param passes - Passengers object
     * @param drivers - Drivers object
     * @return a vector of strings representing the formatted output
     */
    static vs getList(string title, const vector<Ride>& rideGroup, bool onlyTime, Passes& passes, Drivers& drivers);
    
    /**
     * Prints the current system time
     */
    static void printCurrTime();
    
    /**
     * Waits until the user presses the return key
     */
    static void waitForEnter();
    
    /**
     * Converts a boolean value to string
     *
     * @param in - boolean value
     * @return "yes" or "no"
     */
    static string bts(bool in);
    
    /**
     * Formats the time in seconds to a string
     *
     * @param seconds - time in seconds
     * @return formatted time string
     */
    static string printTime(long seconds);
    
    /**
     * Prints the double or time value unless not set
     *
     * @param in - The input number
     * @param time - If it is a time
     * @return a string representing the printable value or "N/A"
     */
    static string printUnlessDefault(double in, bool time);
    
    /**
     * The ugly big switch statement that runs the code for the program
     *
     * @param drivers - Drivers object
     * @param passes - Passengers object
     * @param rides - Rides object
     */
    static void mainLoop(Drivers& drivers, Passes& passes, Rides& rides);
    
    /**
     * Completely clears collection objects and even
     * removes the save data file
     *
     * @param drivers - Drivers object
     * @param passes - Passengers object
     * @param rides - Rides object
     */
    static void clearData(Drivers& drivers, Passes& passes, Rides& rides);
    
    /**
     * Fixes random objects created in maps from access
     *
     * @param drivers - Drivers object
     * @param passes - Passengers object
     * @param rides - Rides object
     */
    static void fixErrors(Drivers &drivers, Passes &passes, Rides &rides);
};

#endif //FUNCS_H