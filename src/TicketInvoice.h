#ifndef TICKETINVOICE_H_
#define TICKETINVOICE_H_

#include "Passenger.h"
#include "Trip.h"
#include "project_types.h"
#include <string>
#include <iostream>

class TicketInvoice {
public:
    TicketInvoice(Passenger* p, Trip* t);

    const std::string getPassengerName() const;
    const std::string getSourceName() const;
    const std::string getDestName() const;
    const std::string getPriceString() const;
    void setPrice(uint price);

    friend std::ostream & operator<<(std::ostream &os, TicketInvoice &in);

private:
    std::string passengerName;
    std::string sourceName;
    std::string departureDate;
    std::string destName;
    std::string arrivalDate;
    uint price;
};

#endif