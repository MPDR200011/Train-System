#ifndef PURCHASELOG_H_
#define PURCHASELOG_H_

#include <iostream>
#include <string>
#include "project_utils.h"

/**
 * @brief A class representing the log of a trip ticket purchase
 * 
 */
class PurchaseLog {
    /**
     * Current id counter, used to set id on object construction
     * Incremented every time an object is constructed
     */
    static id_t currentID;
public:
    /**
     * @brief Construct a new Purchase Log object
     * 
     * @param tripID 
     * @param passengerID
     */
    PurchaseLog(id_t tripID, id_t passengerID, uint price);

    /**
     * @brief Get the log ID
     * 
     * @return const id_t 
     */
    id_t getID() const;
    /**
     * @brief Get the Trip ID 
     * 
     * @return const int 
     */
    id_t getTripID() const;
    /**
     * Get the passenger ID
     *
     * @return
     */
    id_t getPassengerID() const;

    /**
     * Get the price
     * @return
     */
    uint getPrice() const;

    friend std::ostream &operator<< (std::ostream &os, PurchaseLog &pl);

private:
    id_t logID;
    id_t tripID;
    id_t passengerID;
    uint price;
};

#endif
