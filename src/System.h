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
#include "exceptions/InvalidDateException.h"
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

	int getStationIndex(id_t stationID);
	int getTrainIndex(id_t trainID);
	int getTripIndex(id_t tripID);

	std::vector<Trip*> searchTrips(Station *src, Station *dest, bool searchByArrivalDate, Date arrivalDate);

	bool addPassenger(Passenger* passenger);
	bool addTrip(Trip* trip);
	bool addTrain(Train* train);
	bool addStation(Station* station);

	bool removePassenger(id_t id);
	bool removeTrip(id_t id);	
	bool removeStation(id_t id);
	bool removeTrain(id_t id);

	void createPassenger(std::string name, Date birthDate);
	void createCard(Passenger *p, std::string type);
	void createStation(std::string name);
	void createTrain(uint maxSeats);
	void createTrip(uint basePrice, Station* source, Station* destination,
			Train* train, const Date dapartureDate, const Date arrivalDate);

	void sortPassengers();
	void sortStations();
	void sortTrains();
	void sortTrips();

	bool processTicketPurchaseRequest(TicketPurchaseRequest &request);

	void processCards();
	bool payCard(id_t passengerID);

	void listPassengers(std::ostream &os);
	void listStations(std::ostream &os);
	void listTrains(std::ostream &os);
	void listTrips(std::ostream &os);

	void printPassengers(std::ostream &os) const;
	void printStations(std::ostream &os) const;
	void printTrains(std::ostream &os) const;
	void printTrips(std::ostream &os) const;

	void printSales(std::ostream &os) const;

	friend std::ostream &operator<<(std::ostream &os, System &sys);

private:
	std::vector<Passenger*> passengers;
	std::vector<Trip*> trips;
	std::vector<Train*> trains;
	std::vector<Station*> stations;

	std::vector<Passenger*> cardsToPay;

	std::vector<TicketInvoice> sales;

public:
	static System instance;
};

#endif /* SYSTEM_H_ */
