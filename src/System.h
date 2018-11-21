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

/**
 * @brief Class to represent the central system.
 * 
 * Contains A listing of every passenger, station, train and trip.
 * Is responsible for handling queries and outputing information that is requested.
 * Also handles ticket purchasing.
 * 
 */
class System {
public:
	/**
	 * @brief Construct a new System object.
	 * 
	 */
	System() = default;
	/**
	 * @brief Destroy the System object.
	 * 
	 * Since the listings are handled using pointers, the destructor is in charge od freeing the 
	 * space occupied by them.
	 * 
	 */
	~System();

	/**
	 * @brief Get the Passengers vector.
	 * 
	 * Returns the vector of passengers.
	 * 
	 * @return std::vector<Passenger*>& 
	 */
	std::vector<Passenger*>& getPassengers();
	/**
	 * @brief Get the Trips vector.
	 * 
	 * Returns the vector of trips.
	 * 
	 * @return std::vector<Trip*>& 
	 */
	std::vector<Trip*>& getTrips();
	/**
	 * @brief Get the Trains vector.
	 * 
	 * Returns the vector of trains.
	 * 
	 * @return std::vector<Train*>& 
	 */
	std::vector<Train*>& getTrains();
	/**
	 * @brief Get the Stations vector.
	 * 
	 * Returns the vector of stations.
	 * 
	 * @return std::vector<Station*>& 
	 */
	std::vector<Station*>& getStations();

	/**
	 * @brief Get Passenger pointer.
	 * 
	 * Returns the pointer to the passenger object with id specified in the parameter.
	 * If there is no such object, throws NoSuchPassengerException. 
	 * 
	 * @param id 
	 * @return Passenger* 
	 */
	Passenger* getPassenger(const id_t id);
	/**
	 * @brief Get Trip pointer.
	 * 
	 * Returns the pointer to the trip object with id specified in the parameter.
	 * If there is no such object, throws NoSuchTripException. 
	 * 
	 * @param id 
	 * @return Trip* 
	 */
	Trip* getTrip(const id_t id);
	/**
	 * @brief Get the Train pointer.
	 * 
	 * Returns the pointer to the train object with id specified in the parameter.
	 * If there is no such object, throws NoSuchTrainException. 
	 * 
	 * @param id 
	 * @return Train* 
	 */
	Train* getTrain(const id_t id);
	/**
	 * @brief Get the Station pointer.
	 * 
	 * Returns the pointer to the station object with id specified in the parameter.
	 * If there is no such object, throws NoSuchStationxception. 
	 * 
	 * @param id 
	 * @return Station* 
	 */
	Station* getStation(const id_t id);

	/**
	 * @brief Get Station Index
	 * 
	 * Returns the index of the station object, with id specified in the parameter, 
	 * in the respective vector.
	 * If there is no such object, returns -1.
	 * 
	 * @param stationID 
	 * @return int 
	 */
	int getStationIndex(id_t stationID);
	/**
	 * @brief Get the Train Index
	 * 
	 * Returns the index of the train object, with id specified in the parameter, 
	 * in the respective vector.
	 * If there is no such object, returns -1.
	 * 
	 * @param trainID 
	 * @return int 
	 */
	int getTrainIndex(id_t trainID);
	/**
	 * @brief Get the Trip Index 
	 * 
	 * Returns the index of the trip object, with id specified in the parameter, 
	 * in the respective vector.
	 * If there is no such object, returns -1.
	 * 
	 * @param tripID 
	 * @return int 
	 */
	int getTripIndex(id_t tripID);

	/**
	 * @brief 
	 * 
	 * @param src 
	 * @param dest 
	 * @param searchByArrivalDate 
	 * @param arrivalDate 
	 * @return std::vector<Trip*> 
	 */
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
	void sortPassengersByName();
	void sortStations();
	void sortTrains();
	void sortTrips();
	void sortTripsByDate();

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
