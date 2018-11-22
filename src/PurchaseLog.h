#ifndef PURCHASELOG_H_
#define PURCHASELOG_H_

#include <iostream>
#include <string>
#include "project_types.h"

/**
 * @brief A class representing the log of a trip tiket purchase
 * 
 */
class PurchaseLog {
public:
    /**
     * @brief Current ID counter
     * 
     * Used to set the id of the purchase object when it is created.
     * It's incremented every time a new object is created.
     * 
     */
    static id_t currentId;
    /**
     * @brief Construct a new Purchase Log object
     * 
     * @param tripID 
     * @param passengerName 
     * @param sourceName 
     * @param destName 
     * @param departureDate 
     * @param price 
     */
    PurchaseLog(int tripID, std::string passengerName, std::string sourceName, std::string destName, std::string departureDate, std::string price);

    /**
     * @brief Get the log ID
     * 
     * @return const id_t 
     */
    const id_t getID() const;
    /**
     * @brief Get the Trip ID 
     * 
     * @return const int 
     */
    const int getTripID() const;
    /**
     * @brief Get the Passenger Name
     * 
     * @return const std::string 
     */
    const std::string getPassengerName() const;
    /**
     * @brief Get the Source Name
     * 
     * @return const std::string 
     */
    const std::string getSourceName() const;
    /**
     * @brief Get the Dest Name
     * 
     * @return const std::string 
     */
    const std::string getDestName() const;
    /**
     * @brief Get the Departure Date String
     * 
     * @return const std::string 
     */
    const std::string getDepartureDate() const;
    /**
     * @brief Get the Price String in cents
     * 
     * @return const std::string 
     */
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