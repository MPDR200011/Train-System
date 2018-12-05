#ifndef TRIP_H_
#define TRIP_H_

#include <string>
#include "Station.h"
#include "Train.h"
#include "Date.h"
#include "project_types.h"
#include <iostream>

/**
 * @brief Class for representing a trip in the system
 * 
 */
class Trip {

public:
	/**
	 * @brief Construct a new Trip object
	 * 
	 * @param basePrice Base price of the trip in cents
	 * @param source Pointer to source station
	 * @param destination Pointer to destination station
	 * @param train Pointer to train that will be in charge of the trip
	 * @param departureDate Date object of the time of departure 
	 * @param arrivalDate Date object of the time of arrival
	 */
	Trip(uint basePrice, Station* source, Station* destination,
			Train* train, const Date departureDate, const Date arrivalDate);
	~Trip();

	/**
	 * Set the trip ID
	 *
	 * @param id
	 */
	void setID(id_t id);

	/**
	 * @brief get ID of the trip
	 * 
	 * @return id_t 
	 */
	id_t getID() const;
	/**
	 * @brief Get the Base Price 
	 * 
	 * @return uint Price in cents
	 */
	uint getBasePrice() const;
	/**
	 * @brief Get the price with discounts in mind
	 * 
	 * @return uint Price with dicounts in cents
	 */
	uint getCurrentPrice();
	/**
	 * @brief Get the Source object
	 * 
	 * @return Station* 
	 */
	Station* getSource() const;
	/**
	 * @brief Get the Destination object
	 * 
	 * @return Station* 
	 */
	Station* getDest() const;
	/**
	 * @brief Get the object of the train responsible for the trip
	 * 
	 * @return Train* 
	 */
	Train* getTrain() const;
	/**
	 * @brief Get the Departure Date object
	 * 
	 * @return Date& 
	 */
	Date & getDepartureDate();
	/**
	 * @brief Get the Arrival Date object
	 * 
	 * @return Date& 
	 */
	Date & getArrivalDate();

	/**
	 * @brief Try to book a seat in the trip
	 * 
	 * If the trip has no available seats it doesn't book one.
	 * 
	 * @return true If it had available seats and has booked one.
	 * @return false If it had no available seats.
	 */
	bool bookSeat();

	/**
	 * @brief Output trip information in a row fashion
	 * 
	 * Outputs the object's information as it was a row in a table.
	 * Useful for outputing all Trip objects in the system.
	 *
	 * @param os The output stream to which the trip will be output.
	 * 
	 */
	void printRow(std::ostream &os);
	friend std::ostream &operator<<(std::ostream &os, Trip &tr);

private:
	/**
	 * @brief Checks validity of trip object
	 * 
	 * Throws IdenticalDestination exception if destination is the same as de source
	 * Throws ReverseDatesException if arrival happens before departure
	 * 
	 */
	void validate();
	/**
	 * @brief Get the Number Of Free Seats
	 * 
	 * @return uint 
	 */
	uint getNumberOfFreeSeats() const;

private:
	/**
	 * @brief Id of the trip
	 * 
	 */
	id_t tripID;
	/**
	 * @brief Number of occupied seats
	 * 
	 */
	uint occupiedSeats;
	/**
	 * @brief Base price of the trip in cents
	 * 
	 */
	uint basePrice;
	/**
	 * @brief Pointer to source station object
	 * 
	 */
	Station* source;
	/**
	 * @brief Pointer to destination station object
	 * 
	 */
	Station* destination;
	/**
	 * @brief Pointer to object of the train responsible for the trip
	 * 
	 */
	Train* train;
	/**
	 * @brief Time of departure
	 * 
	 */
	Date departureDate;
	/**
	 * @brief Time of arrival
	 * 
	 */
	Date arrivalDate;

};

#endif /* TRIP_H_ */
