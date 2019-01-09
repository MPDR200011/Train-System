#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "Person.h"
#include "../Date.h"
#include "Trip.h"
#include "PassengerCard.h"
#include "../project_utils.h"
#include <string>
#include <vector>
#include <iostream>
#include "../PurchaseLog.h"

/**
 * @brief Class for representing a passenger in the system
 * Extends class Person.
 *
 */
class Passenger : public Person{

public:
	/**
	 * @brief Construct a new Passenger object
	 * 
	 * @param name Passenger name
	 * @param birthDate Passenger date of birth string in the format: "dd-mm-yyyy HH:MM"
	 */
	Passenger(std::string name, Date birthDate);
	/**
	 * @brief Destroy the Passenger object
	 * 
	 * Sole purpose is to free memory occupied by PassengerCard pointer, if it has a card.
	 * 
	 */
	~Passenger();

	/**
	 * Set the passenger's ID;
	 */
	void setID(id_t id);
	/**
	 * @brief Get the Passenger's ID
	 * 
	 * @return id_t The Passenger's ID
	 */
	id_t getID() const;
	/**
	 * @brief Get the Card object
	 * 
	 * @return PassengerCard* The pointer to the PassengerCard object
	 */
	PassengerCard* getCard() const;
	/**
	 * @brief Get the Trips object
	 * 
	 * @return const std::vector<Trip*>& Reference to the 
	 */
	const std::vector<PurchaseLog> & getTripLogs() const;

	/**
	 * @brief Set the passenger's card
	 * 
	 * Sets the passenger card wether he has one or not.
	 * If the passenger already has one, it is treated as changing the type of the card.
	 * 
	 * @param c Pointer to the PassengerCard object
	 * @return true If the Passenger didn't have a card
	 * @return false If the Passenger didn't have a card
	 */
	bool setCard(PassengerCard *c);

	/**
	 * @brief Logs a trip the passenger has purchased
	 * 
	 * @param log Object with the trip information
	 * @return true 
	 * @return false 
	 */
	void logTrip(PurchaseLog log);

	/**
	 * @brief Remove the passenger's card;
	 * 
	 */
	void removeCard();

	/**
	 * @brief Output the object's attributes in a row fashion
	 * 
	 * Outputs the object's information as it was a row in a table.
	 * Useful for outputing all Passenger objects in the system.
	 * 
	 * @param os Output stream to wich object will be output
	 */
	void printRow(std::ostream &os);

	/**
	 * @brief Output Passenger object in a user friendly fashion
	 * 
	 * @param os Output stream to wich Station object will be output
	 * @param p Passenger object to be output
	 * @return std::ostream& 
	 */
	friend std::ostream & operator<<(std::ostream &os, Passenger &p);

private:
	/**
	 * @brief Passenger's ID
	 * 
	 */
	id_t passengerID;
	/**
	 * @brief Pointer to Passenger's PassengerCard
	 * 
	 * If Passenger does not have acard, it will be nullptr
	 * 
	 */
	PassengerCard* card;
	/**
	 * @brief Vector of trip logs.
	 * 
	 * Contains objects with information about the trips the passenger has reserved.
	 * 
	 */
	std::vector<PurchaseLog> tripLogs;
};

#endif
