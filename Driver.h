#ifndef DRIVER_H
#define DRIVER_H

#include <string>
using namespace std;

enum VehicleType {COMPACT_2_DR = 1, SEDAN_4_DR, SUV, VAN, OTHER};

class Driver {
public:

    Driver();

    Driver(const string &name, int id, int cap, bool hcp, VehicleType type, double rating, bool open, bool pets,
           const string &notes);

    const string &getName() const;

    void setName(const string &name);

    int getId() const;

    void setId(int id);

    int getCap() const;

    void setCap(int cap);

    bool getHcp() const;

    void setHcp(bool hcp);

    VehicleType getType() const;

    void setType(VehicleType type);

    double getRating() const;

    void setRating(int rating);

    bool getOpen() const;

    void setOpen(bool open);

    bool getPets() const;

    void setPets(bool pets);

    const string &getNotes() const;

    void setNotes(const string &notes);

    void printDriver();

private:
    string name;
    int id;
    int cap;
    bool hcp;
    VehicleType type;
    double rating;
    bool open;
    bool pets;
    string notes;
    static string vehicleTypeToString(VehicleType type);
};

#endif //DRIVER_H