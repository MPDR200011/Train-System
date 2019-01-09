#ifndef STATION_H_
#define STATION_H_

#include "SystemElement.h"
#include "../project_utils.h"
#include <string>
#include <iostream>

/**
 * @brief Class for representing a station in the system
 * 
 */
class Station : public SystemElement {

public:
	/**
	 * @brief Construct a new Station object
	 * 
	 * @param name Name of the station.
	 */
	explicit Station(std::string name);

	/**
	 * Set the station ID
	 *
	 * @param stationID
	 */
	void setID(id_t stationID);

	/**
	 * @brief Get the station ID
	 * 
	 * @return id_t 
	 */
	id_t getID() const;

	/**
	 * @brief Get the Station's name
	 * 
	 * @return std::string Station's name
	 */
	std::string getName() const;

	/**
	 *@brief Get the Station's number of passengers
	 *
	 *Get the number of passengers that have the station as Destination
	 *
	 *@return int
	 */
	int getPassengerNumber() const;

	/**
	 * @brief Output station information in a row fashion
	 * 
	 * Outputs the object's information as it was a row in a table.
	 * Useful for outputing all Station objects in the system.
	 * 
	 * @param os The output stream to which the station will be output.
	 */
	void printRow(std::ostream &os) const;
	/**
	 * @brief Output Station object in a user friendly fashion
	 * 
	 * @param os Output stream to which Station object will be output
	 * @param p Station object to be output
	 * @return std::ostream& 
	 */
	friend std::ostream &operator <<(std::ostream &os, Station &st);

	bool operator < (const Station &st) const;

	bool operator == (const Station &st) const;

	/**
	 * @brief Increments Station's number of passengers
	 *
	 */
	void addPassenger();

	/**
	 * @brief Decrements Station's number of passengers
	 *
	 */
	void removePassenger();

private:
	/**
	 * @brief ID of the station
	 * 
	 */
	id_t stationID;
	/**
	 * @brief Name of the station
	 * 
	 */
	std::string name;
	/**
	 * @brief Number of passengers that have the station as destination
	 */
	int passengerNumber;
};

#endif /* STATION_H_ */
