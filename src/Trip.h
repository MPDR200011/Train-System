#ifndef TRIP_H_
#define TRIP_H_

#include <string>
#include "Station.h"
#include "Train.h"
#include "Date.h"
#include "project_types.h"
#include <iostream>

class Trip {
	static id_t currentID;
public:
	Trip(uint basePrice, Station* source, Station* destination,
			Train* train, const std::string dapartureDate, const std::string arrivalDate);
	~Trip();

	id_t getID() const;
	uint getBasePrice() const;
	uint getCurrentPrice();
	Station* getSource() const;
	Station* getDest() const;
	Train* getTrain() const;
	Date & getDepartureDate();
	Date & getArrivalDate();

	bool bookSeat();

	void printRow(std::ostream &os);
	friend std::ostream &operator<<(std::ostream &os, Trip &tr);

private:
	void validate();
	uint getNumberOfFreeSeats() const;

private:
	id_t tripID;
	uint occupiedSeats;
	uint basePrice;
	Station* source;
	Station* destination;
	Train* train;
	Date departureDate;
	Date arrivalDate;

};

#endif /* TRIP_H_ */
