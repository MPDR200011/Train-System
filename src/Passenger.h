#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "Date.h"
#include "PassengerCard.h"
#include "project_types.h"
#include <string>

class Passenger {
	static id_t currentID;
public:
	Passenger(std::string name, std::string birthDate);
	virtual ~Passenger();

private:
	id_t passengerID;
	std::string name;
	PassengerCard* card;
	Date birthDate;
};

#endif /* PASSENGER_H_ */
