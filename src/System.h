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
#include "PurchaseLog.h"

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
	 * @brief Get a vector of Trip respecting constraints
	 * 
	 * Creates a vector of trip that match the constraints given in the parameters.
	 * 
	 * @param src Pointer to source station object, if it is a nullptr, the function will ignore this constraint.
	 * @param dest Pointer to destination station object, if it is a nullptr, the function will ignore this constraint.
	 * @param searchByArrivalDate Bool checking wether to restrict the dates to before the date specified.
	 * @param arrivalDate Maximum arrival time desired. It's only considered if searchByArrivalDate is set to true.
	 * @return std::vector<Trip*> 
	 */
	std::vector<Trip*> searchTrips(Station *src, Station *dest, bool searchByArrivalDate, Date arrivalDate);

	/**
	 * @brief Remove Passenger from the system
	 * 
	 * Removes the passenger object with id specified by the parameter from the respective vector.
	 * 
	 * @param id 
	 * @return true If passenger was successfully removed.
	 * @return false If passenger never existed.
	 */
	bool removePassenger(id_t id);
	/**
	 * @brief Remove Trip from the system
	 * 
	 * Removes the trip object with id specified by the parameter from the respective vector.
	 * 
	 * @param id 
	 * @return true If trip was successfully removed.
	 * @return false If trip never existed.
	 */
	bool removeTrip(id_t id);
	/**
	 * @brief Remove Station from the system
	 * 
	 * Removes the station object with id specified by the parameter from the respective vector.
	 * 
	 * @param id 
	 * @return true If station was successfully removed.
	 * @return false If station never existed.
	 */
	bool removeStation(id_t id);
	/**
	 * @brief Remove Train from the system
	 * 
	 * Removes the train object with id specified by the parameter from the respective vector.
	 * 
	 * @param id 
	 * @return true If train was successfully removed.
	 * @return false If train never existed.
	 */
	bool removeTrain(id_t id);

	/**
	 * @brief Create a Passenger object
	 * 
	 * Creates a passenger object and adds it to the respective vector.
	 * 
	 * @param name 
	 * @param birthDate 
	 */
	void createPassenger(std::string name, Date birthDate);
	/**
	 * @brief Create a Card object
	 * 
	 * Creates a passenger card object and adds it to the respective passenger.
	 * 
	 * @param p 
	 * @param type 
	 */
	void createCard(Passenger *p, std::string type);
	/**
	 * @brief Create a Station object
	 * 
	 * Creates a station object and adds it to the respective vector.
	 * 
	 * @param name 
	 */
	void createStation(std::string name);
	/**
	 * @brief Create a Train object
	 * 
	 * Creates a train object and adds it to the respective vector.
	 * 
	 * @param maxSeats 
	 */
	void createTrain(uint maxSeats);
	/**
	 * @brief Create a Trip object
	 * 
	 * Creates a station object and adds it to the respective vector.
	 * 
	 * @param basePrice 
	 * @param source 
	 * @param destination 
	 * @param train 
	 * @param dapartureDate 
	 * @param arrivalDate 
	 */
	void createTrip(uint basePrice, Station* source, Station* destination,
			Train* train, const Date dapartureDate, const Date arrivalDate);

	/**
	 * @brief Sort passenger in vector by id
	 * 
	 */
	void sortPassengers();
	/**
	 * @brief Sort passengers in vector by name
	 * 
	 */
	void sortPassengersByName();
	/**
	 * @brief Sort stations in vector by id
	 * 
	 */
	void sortStations();
	/**
	 * @brief Sort trains in vector by id
	 * 
	 */
	void sortTrains();
	/**
	 * @brief Sort trips in vecotr by id
	 * 
	 */
	void sortTrips();
	/**
	 * @brief Sort trips in vector by time of departure
	 * 
	 */
	void sortTripsByDate();

	/**
	 * @brief Process a request for a ticket purchase
	 * 
	 * Receives a request for a ticket purchase and processes it.
	 * Will throw TripPastException if the specified trip has already happened.
	 * 
	 * Checks wether the trip has free seats and, if it does, adds the respective trip to the
	 * passenger's vector of booked trips. Also calculates the price to pay based on available discounts.
	 * 
	 * @param request 
	 * @return true 
	 * @return false 
	 */
	bool processTicketPurchaseRequest(TicketPurchaseRequest &request);

	/**
	 * @brief Log a purchase request
	 * 
	 * @param log 
	 */
	void logPurchase(PurchaseLog log);

	const std::vector<PurchaseLog> & getLogs() const;

	/**
	 * @brief End of month card processing.
	 * 
	 * Works as a complement of the Train system abstraction, it's purpose is to emulate an 
	 * end of the month card processing: The System class has a vector with passenger object
	 * pointers that specifies the passengers that have cards and have not yet payed the monthly fee.
	 * "At the end of the month", this method scans through the vector, removing the card pointer
	 * of any passenger object that is still in it, signifying that it was invalidated due to 
	 * not being payed, and repopulates with the passengers that still have cards.
	 * 
	 */
	void processCards();
	/**
	 * @brief Process card monthly fee payment.
	 * 
	 * Emulates a card payment.
	 * Looks for passenger object of id specified in the arguments, and removes it's
	 * pointer from the cardsToPay vector.
	 * 
	 * @param passengerID 
	 * @param os output stream to print the card payment invoice
	 * @return true If passenger has successfully payed card
	 * @return false If passenger pointer wasn't on the cardsToPay vector
	 */
	bool payCard(id_t passengerID, std::ostream &os);

	/**
	 * @brief Print a table of passengers
	 * 
	 * Prints all passengers' information in a formated table
	 * 
	 * @param os 
	 */
	void listPassengers(std::ostream &os);
	/**
	 * @brief Print a table of stations
	 * 
	 * Prints all stations' information in a formated table
	 * 
	 * @param os 
	 */
	void listStations(std::ostream &os);
	/**
	 * @brief Print a table of trains
	 * 
	 * Prints all trains' information in a formated table
	 * 
	 * @param os 
	 */
	void listTrains(std::ostream &os);
	/**
	 * @brief Print a table of trip
	 * 
	 * Prints all trips' information in a formated table
	 * 
	 * @param os 
	 */
	void listTrips(std::ostream &os);

	/**
	 * @brief Print all passengers
	 * 
	 * Prints all passanger objects in a user friendly way
	 * 
	 * @param os 
	 */
	void printPassengers(std::ostream &os) const;
	/**
	 * @brief Print all stations
	 * 
	 * Prints all station objects in a user friendly way
	 * 
	 * @param os 
	 */
	void printStations(std::ostream &os) const;
	/**
	 * @brief Print all train
	 * 
	 * Prints all train objects in a user friendly way
	 * 
	 * @param os 
	 */
	void printTrains(std::ostream &os) const;
	/**
	 * @brief Print all trips
	 * 
	 * Prints all trip objects in a user friendly way
	 * 
	 * @param os 
	 */
	void printTrips(std::ostream &os) const;

	/**
	 * @brief Print all invoices
	 * 
	 * Prints the invoices of all processed ticket purchase requests
	 * that where validated.
	 * 
	 * @param os pending
	 */
	void printSales(std::ostream &os) const;

	/**
	 * @brief Print everything.
	 * 
	 * Calls the operators overload in all passengers, stations, trains and trips.
	 * 
	 * @param os 
	 * @param sys 
	 * @return std::ostream& 
	 */
	friend std::ostream &operator<<(std::ostream &os, System &sys);

private:
	/**
	 * @brief Passengers vector
	 * 
	 */
	std::vector<Passenger*> passengers;
	/**
	 * @brief Trips vector
	 * 
	 */
	std::vector<Trip*> trips;
	/**
	 * @brief Trains vector
	 * 
	 */
	std::vector<Train*> trains;
	/**
	 * @brief Stations vector
	 * 
	 */
	std::vector<Station*> stations;

	/**
	 * @brief Vector of passengers with pending monthly card fee 
	 * 
	 */
	std::vector<Passenger*> cardsToPay;

	/**
	 * @brief All processed ticket sales invoices
	 * 
	 */
	std::vector<PurchaseLog> sales;

public:
	/**
	 * @brief System class instance
	 * 
	 * Since the System class only really needs to have an instance per program,
	 * a static instance of System is held within itself, making it accessible by 
	 * any part of the program that needs to make a query.
	 * 
	 */
	static System instance;
};

#endif /* SYSTEM_H_ */
