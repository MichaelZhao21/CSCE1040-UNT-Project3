#ifndef RIDE_H
#define RIDE_H

#include <string>
using namespace std;

enum Status {ACTIVE, COMPLETED, CANCELLED};

class Ride {
public:
    Ride();
    Ride(int id, const string &pickLoc, time_t pickTime, const string &dropLoc, int size, bool pets, int passId, int driverId);
    Ride(int id, const string &pickLoc, time_t pickTime, const string &dropLoc, int size, bool pets, time_t dropTime,
         Status status, double rating, int passId, int driverId);
    int getId() const;
    void setId(int id);
    const string &getPickLoc() const;
    void setPickLoc(const string &pickLoc);
    time_t getPickTime() const;
    void setPickTime(time_t pickTime);
    const string &getDropLoc() const;
    void setDropLoc(const string &dropLoc);
    int getSize() const;
    void setSize(int size);
    bool getPets() const;
    void setPets(bool pets);
    time_t getDropTime() const;
    void setDropTime(time_t dropTime);
    Status getStatus() const;
    void setStatus(Status status);
    double getRating() const;
    void setRating(double rating);
    int getPassId() const;
    void setPassId(int passId);
    int getDriverId() const;
    void setDriverId(int driverId);
    void printRide();
private:
    int id;
    string pickLoc;
    time_t pickTime;
    string dropLoc;
    int size;
    bool pets;
    time_t dropTime;
    Status status;
    double rating;
    int passId;
    int driverId;
    static string statusToString(Status s);
};


#endif //RIDE_H
