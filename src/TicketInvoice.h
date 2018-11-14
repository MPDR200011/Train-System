#ifndef TICKETINVOICE_H_
#define TICKETINVOICE_H_

#include "Passenger.h"
#include "Trip.h"
#include "project_types.h"
#include <string>
#include <iostream>

/**
 * @brief Class for representing an invoice of a ticket purchase in the system.
 * 
 */
class TicketInvoice {
public:
    /**
     * @brief Construct a new Ticket Invoice object
     * 
     * @param p Pointer to the passanger that has done the purchase
     * @param t Trip to which the ticket has been purchased
     */
    TicketInvoice(Passenger* p, Trip* t);

    /**
     * @brief Get the Passenger Name
     * 
     * @return const std::string Name of the passenger
     */
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