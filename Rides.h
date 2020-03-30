#ifndef RIDES_H
#define RIDES_H

#include "Defs.h"
#include "Passes.h"
#include "Drivers.h"
#include "Ride.h"
using namespace std;

class Rides {
public:
    /**
     * Constructors
     */
    Rides();
    Rides(const unordered_map<int, Ride> &rideList, int nextId);

    /**
     * Getters and setters
     */
    int getNextId() const;
    void setNextId(int nextId);

    /**
     * Adds a ride to rideList
     *
     * @param passes - Passes object
     * @param drivers - Drivers object
     */
    void addRide(Passes& passes, Drivers& drivers);

    /**
     * Find all drivers that match the given constraints
     *
     * @param pass - Pass object
     * @param drivers - Drivers object
     * @param size - The size of the ride
     * @param pets - Does the ride contain pets
     * @return an int vector with all of the possible driver IDs
     */
    vi findAllMatchingDrivers(Pass& pass, Drivers& drivers, int size, bool pets);
    
    /**
     * Checks if the driver matches the given requirements for
     * driving a ride for a specific party
     *
     * @param driver - Driver object
     * @param pass - Pass object
     * @param size - The size of the ride
     * @param pets - Does the ride contain pets
     * @return a boolean denoting the acceptability of the driver
     */
    bool checkDriverMatchReq(Driver& driver, Pass& pass, int size, bool pets);
    
    /**
     * Sees if the driver has overlapping times
     *
     * @param poss - Vector of possible drivers
     * @param drivers - Drivers object 
     * @param pickTime - Pickup time 
     * @param dropTime - Dropoff time 
     */
    void checkDriverTime(vi& poss, Drivers& drivers, time_t pickTime, time_t dropTime);
    
    /**
     * See if the passenger has overlapping times
     *
     * @param passId - Passenger ID
     * @param passes - Passes object 
     * @param pickTime - Pickup time 
     * @param dropTime - Dropoff time 
     * @return if a passenger is busy or not
     */
    bool checkPassTime(int passId, Passes &passes, time_t pickTime, time_t dropTime);
    
    /**
     * Prompt user to pick a ride from rideList
     *
     * @param passes - Passes object 
     * @param drivers - Drivers object 
     * @return the id of the ride
     */
    int findRide(Passes& passes, Drivers& drivers);
    
    /**
     * Calls findRide and prints that ride
     *
     * @param passes - Passes object 
     * @param drivers - Drivers object 
     */
    void findandPrintRide(Passes& passes, Drivers& drivers);
    
    /**
     * Sets the status of a ride to cancelled
     *
     * @param passes - Passes object 
     * @param drivers - Drivers object 
     */
    void cancelRide(Passes& passes, Drivers& drivers);
    
    /**
     * Lets passenger rate the ride if it is completed
     *
     * @param passes - Passes object 
     * @param drivers - Drivers object 
     */
    void rateRides(Passes& passes, Drivers& drivers);
    
    /**
     * Prints all of the rides in rideList
     */
    void printAllRides();
    
    /**
     * Takes in the status and prints all rides that
     * have that status
     *
     * @param s - Status enum
     * @param passes - Passes object 
     * @param drivers - Drivers object 
     */
    void printRideByStatus(Status s, Passes& passes, Drivers& drivers);
    
    /**
     * Gets all the rides that a driver drives
     *
     * @param driver - Driver object
     * @return a vector of rides
     */
    vector<Ride> getDriverRides(Driver& driver);
    
    /**
     * Gets all the rides that a passenger has
     *
     * @param pass - Pass object
     * @return a vector of rides
     */
    vector<Ride> getPassRides(Pass& pass);
    
    /**
     * Prints all of the rides that a driver has
     *
     * @param passes - Passes object 
     * @param drivers - Drivers object 
     */
    void printDriverSchedule(Passes& passes, Drivers& drivers);
    
    /**
     * Prints all of the rides that a passenger has
     *
     * @param passes - Passes object 
     * @param drivers - Drivers object 
     */
    void printPassSchedule(Passes& passes, Drivers& drivers);
    
    /**
     * Removes all rides that are completed/cancelled
     */
    void removeUselessRides();
    
    /**
     * Prompts and removes a ride
     *
     * @param passes - Passes object 
     * @param drivers - Drivers object 
     */
    void removeRide(Passes &passes, Drivers &drivers);
    
    /**
     * Checks to see if the rideList is empty,
     * then outputs info to the user and waits for
     * an enter input
     *
     * @return is the ride list empty
     */
    bool rideListEmpty();
    
    /**
     * Checks to see if any rides are complete
     * and sets their status to completed if true
     */
    void checkRideCompletion();
    
    unordered_map<int, Ride> rideList;

private:
    int nextId;
};

#endif //RIDES_H