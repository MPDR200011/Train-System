#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <vector>
#include <iostream>
#include "Passenger.h"
#include "Trip.h"
#include "Train.h"
#include "Station.h"
#include "TicketPurchaseRequest.h"
#include "Date.h"
#include "InvalidDateException.h"
#include "project_types.h"

class System {
public:
	System() = default;
	~System();
	std::vector<Passenger*>& getPassengers();
	std::vector<Trip*>& getTrips();
	std::vector<Train*>& getTrains();
	std::vector<Station*>& getStations();

	Passenger* getPassenger(const id_t id);
	Trip* getTrip(const id_t id);
	Train* getTrain(const id_t id);
	Station* getStation(const id_t id);

	bool addPassenger(Passenger* passenger);
	bool addTrip(Trip* trip);
	bool addTrain(Train* train);
	bool addStation(Station* station);

	bool createPassenger(const std::vector<std::string> &arguments);
	bool createStation(const std::vector<std::string> &arguments);
	bool createTrain(const std::vector<std::string> &arguments);
	bool createTrip(const std::vector<std::string> &arguments);

	bool processTicketPurchaseRequest(TicketPurchaseRequest &request);

	void printPassengers(std::ostream &os) const;
	void printStations(std::ostream &os) const;
	void printTrains(std::ostream &os) const;
	void printTrips(std::ostream &os) const;
	friend std::ostream &operator<<(std::ostream &os, System &sys);

private:
	std::vector<Passenger*> passengers;
	std::vector<Trip*> trips;
	std::vector<Train*> trains;
	std::vector<Station*> stations;

public:
	static System instance;
};

#endif /* SYSTEM_H_ */
