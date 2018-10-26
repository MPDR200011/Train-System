/*
 * System.h
 *
 *  Created on: Oct 24, 2018
 *      Author: mpdr
 */
#include <vector>
#include "Passenger.h"
#include "Trip.h"
#include "Train.h"
#include "Station.h"
#include "TicketPurchaseRequest.h"
#include "Date.h"
#include "InvalidDateException.h"


#ifndef SYSTEM_H_
#define SYSTEM_H_

class System {
public:
	System() = default;
	~System();
	const std::vector<Passenger*>& getPassengers() const;
	const std::vector<Trip*>& getTrips() const;
	const std::vector<Train*>& getTrains() const;
	const std::vector<Station*>& getStations() const;

	void processSearchRequest() const;
	void processTicketPurchaseRequest(TicketPurchaseRequest &request);

private:
	std::vector<Passenger*> passengers;
	std::vector<Trip*> trips;
	std::vector<Train*> trains;
	std::vector<Station*> stations;

public:
	static System instance;
};

#endif /* SYSTEM_H_ */
