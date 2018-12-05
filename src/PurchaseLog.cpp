#include "PurchaseLog.h"

using namespace std;

id_t PurchaseLog::currentID = 0;

PurchaseLog::PurchaseLog(id_t tripID, id_t passengerID, uint price) {
    this->logID = currentID++;
    this->tripID = tripID;
    this->passengerID = passengerID;
    this->price = price;
}

id_t PurchaseLog::getID() const {
    return logID;
}

id_t PurchaseLog::getTripID() const {
    return tripID;
}

id_t PurchaseLog::getPassengerID() const {
    return passengerID;
}

ostream &operator<< (ostream &os, PurchaseLog &pl) {
    os << endl;
    os << "Passenger ID: " << pl.passengerID << endl;
    os << "Trip ID: " << pl.tripID << endl;
    os << "Price : " << pl.price << endl;

    return os;
}

uint PurchaseLog::getPrice() const {
    return price;
}
