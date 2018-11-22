#include "PurchaseLog.h"

using namespace std;

id_t PurchaseLog::currentId = 0;

PurchaseLog::PurchaseLog(int tripID, string passengerName, string sourceName, string destName, string departureDate, string price):
    passengerName(passengerName), sourceName(sourceName), destName(destName), departureDate(departureDate), price(price) {
        this->logID = currentId++;
        this->tripID = tripID;
}

const id_t PurchaseLog::getID() const {
    return logID;
}

const int PurchaseLog::getTripID() const {
    return tripID;
}

const string PurchaseLog::getPassengerName() const {
    return passengerName;
}

const string PurchaseLog::getSourceName() const {
    return sourceName;
}

const string PurchaseLog::getDestName() const {
    return destName;
}

const string PurchaseLog::getDepartureDate() const {
    return departureDate;
}

const string PurchaseLog::getPrice() const {
    return price;
}

ostream &operator<< (ostream &os, PurchaseLog &pl) {
    os << endl;
    os << "Passenger Name: " << pl.passengerName << endl;
    os << "Source Name: " << pl.sourceName << endl;
    os << "Destination Name: " << pl.destName << endl;
    os << "Date: " << pl.departureDate << endl;
    os << "Price (cents): " << pl.price << endl;
    return os;
}
