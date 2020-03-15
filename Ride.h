#ifndef RIDE_H
#define RIDE_H

#include <string>
using namespace std;

class Ride {
public:
    Ride();

    Ride(int id, const string &pickLoc, long pickTime, const string &dropLoc, int size, bool pets, int passId, int driverId);

    Ride(int id, const string &pickLoc, long pickTime, const string &dropLoc, int size, bool pets, long dropTime,
         int status, double rating, int passId, int driverId);

    int getId() const;

    void setId(int id);

    const string &getPickLoc() const;

    void setPickLoc(const string &pickLoc);

    long getPickTime() const;

    void setPickTime(long pickTime);

    const string &getDropLoc() const;

    void setDropLoc(const string &dropLoc);

    int getSize() const;

    void setSize(int size);

    bool getPets() const;

    void setPets(bool pets);

    long getDropTime() const;

    void setDropTime(long dropTime);

    int getStatus() const;

    void setStatus(int status);

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
    long pickTime;
    string dropLoc;
    int size;
    bool pets;
    long dropTime;
    int status;
    double rating;

private:
    int passId;
    int driverId;
};


#endif //RIDE_H
