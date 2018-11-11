#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "Date.h"
#include "Trip.h"
#include "PassengerCard.h"
#include "project_types.h"
#include <string>
#include <vector>
#include <iostream>

/**
 * @brief Class for representing a passenger in the system
 * 
 * Holds his ID, name, pointer to a PassengerCard object (if he has one),
 * a Date object representing his date of birth and a vector of pointers to trips he has bought tickets for.
 * 
 */
class Passenger {
	/**
	 * @brief Next ID counter
	 * 
	 * Used to set new ID when Passenger object is constructed, incremented every time a 
	 * new Passenger object is constructed.
	 *  
	 */
	static id_t currentID;
public:
	/**
	 * @brief Construct a new Passenger object
	 * 
	 * @param name Passenger name
	 * @param birthDate Passenger date of birth string in the format: "dd-mm-yyyy HH:MM"
	 */
	Passenger(std::string name, std::string birthDate);
	/**
	 * @brief Destroy the Passenger object
	 * 
	 * Sole purpose is to free memory occupied by PassengerCard pointer, if it has a card.
	 * 
	 */
	~Passenger();

	/**
	 * @brief Get the Passenger's ID
	 * 
	 * @return id_t The Passenger's ID
	 */
	id_t getID() const;
	/**
	 * @brief Get the Name object
	 * 
	 * @return std::string The Passenger's name
	 */
	std::string getName() const;
	/**
	 * @brief Get the Card object
	 * 
	 * @return PassengerCard* The pointer to the PassengerCard object
	 */
	PassengerCard* getCard() const;
	/**
	 * @brief Get the Birth Date object
	 * 
	 * @return const Date& The Date object representing the Passenger's date of birth
	 */
	const Date & getBirthDate() const;
	/**
	 * @brief Get the Trips object
	 * 
	 * @return const std::vector<Trip*>& Reference to the 
	 */
	const std::vector<Trip*> & getTrips() const;
	/**
	 * @brief Add a Trip to the trips vector
	 * 
	 * @param trip The pointer to trip trip to be added
	 * @return true If trip was successefully added
	 * @return false If vector already has a trip with the same ID as the parameter's
	 */
	bool addTrip(Trip* trip);

	/**
	 * @brief Output the object's attributes in a row fashion
	 * 
	 * @param os Output stream to wich object will be output
	 */
	void printRow(std::ostream &os);
	/**
	 * @brief Output Passenger object in a user friendly fashion
	 * 
	 * @param os Output stream
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
	 * @brief Passenger's name
	 * 
	 */
	std::string name;
	/**
	 * @brief Pointer to Passenger's PassengerCard
	 * 
	 * If Passenger does not have acard, it will be nullptr
	 * 
	 */
	PassengerCard* card;
	/**
	 * @brief Date object representing Passenger's date of birth
	 * 
	 */
	Date birthDate;
	/**
	 * @brief Vector with trips Passenger has bought tckets for.
	 * 
	 */
	std::vector<Trip*> trips;
};

#endif /* PASSENGER_H_ */
