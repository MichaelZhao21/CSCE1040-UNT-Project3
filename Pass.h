#ifndef PASS_H
#define PASS_H

#include "Defs.h"

enum PayType {CASH = 1, CREDIT, DEBIT};

class Pass {
public:
    Pass();
    Pass(const string &name, int id, PayType payType, bool hcp, double minRating, bool pets);
    const string &getName() const;
    void setName(const string &name);
    int getId() const;
    void setId(int id);
    PayType getPayType() const;
    void setPayType(PayType payType);
    bool getHcp() const;
    void setHcp(bool hcp);
    double getMinRating() const;
    void setMinRating(double minRating);
    bool getPets() const;
    void setPets(bool hasPets);
    void printPass();
private:
    string name;
    int id;
    PayType payType;
    bool hcp, pets;
    double minRating;
    static string payTypeToString(PayType p);
};


#endif //PASS_H
