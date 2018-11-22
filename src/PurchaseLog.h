#ifndef PURCHASELOG_H_
#define PURCHASELOG_H_

#include <iostream>
#include <string>
#include "project_types.h"

class PurchaseLog {
public:
    static id_t currentId;
    PurchaseLog(int tripID, std::string passengerName, std::string sourceName, std::string destName, std::string departureDate, std::string price);

    const id_t getID() const;
    const int getTripID() const;
    const std::string getPassengerName() const;
    const std::string getSourceName() const;
    const std::string getDestName() const;
    const std::string getDepartureDate() const;
    const std::string getPrice() const;

    friend std::ostream &operator<< (std::ostream &os, PurchaseLog &pl);

private:
    id_t logID;
    int tripID;
    std::string passengerName;
    std::string sourceName;
    std::string destName;
    std::string departureDate;
    std::string price;
};

#endif