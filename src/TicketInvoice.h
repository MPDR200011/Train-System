#ifndef TICKETINVOICE_H_
#define TICKETINVOICE_H_

#include "Passenger.h"
#include "Trip.h"
#include "project_utils.h"
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
    /**
     * @brief Get the Source Name
     * 
     * @return const std::string Name of the source station
     */
    const std::string getSourceName() const;
    /**
     * @brief Get the Dest Name
     * 
     * @return const std::string Name of the destination station
     */
    const std::string getDestName() const;
    /**
     * @brief Get the Price String
     * 
     * @return const std::string A string representing the price in euros(not cents)
     */
    const std::string getPriceString() const;
    /**
     * @brief Get the Price 
     * 
     * @return const uint The price in cents
     */
    const uint getPrice() const;
    /**
     * @brief Set the Price 
     * 
     * @param price 
     */
    void setPrice(uint price);

    friend std::ostream & operator<<(std::ostream &os, TicketInvoice &in);

private:
    /**
     * @brief The name of the passenger that bought the ticket
     * 
     */
    std::string passengerName;
    /**
     * @brief Name of the source station
     * 
     */
    std::string sourceName;
    /**
     * @brief String of the departure date in the format dd-mm-yyyy HH:MM
     * 
     */
    std::string departureDate;
    /**
     * @brief Name of the destination station
     * 
     */
    std::string destName;
    /**
     * @brief String of the arrival date in the format dd-mm-yyyy HH:MM
     * 
     */
    std::string arrivalDate;
    /**
     * @brief Price in cents
     * 
     */
    uint price;
};

#endif