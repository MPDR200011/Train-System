#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "Date.h"
#include "Trip.h"
#include "PassengerCard.h"
#include "project_types.h"
#include <string>
#include <vector>
#include <iostream>

class Passenger {
	static id_t currentID;
public:
	Passenger(std::string name, std::string birthDate);
	virtual ~Passenger();

	id_t getID() const;
	std::string getName() const;
	PassengerCard* getCard() const;
	const Date & getBirthDate() const;
	const std::vector<Trip*> & getTrips() const;
	bool addTrip(Trip* trip);

	friend std::ostream & operator<<(std::ostream &os, Passenger &p);

private:
	id_t passengerID;
	std::string name;
	PassengerCard* card;
	Date birthDate;
	std::vector<Trip*> trips;
};

#endif /* PASSENGER_H_ */
