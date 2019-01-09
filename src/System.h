#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <map>
#include <vector>
#include <iostream>
#include <unordered_set>
#include "system_elements/Passenger.h"
#include "system_elements/Trip.h"
#include "system_elements/Station.h"
#include "TicketPurchaseRequest.h"
#include "Date.h"
#include "exceptions/InvalidDateException.h"
#include "project_utils.h"
#include "PurchaseLog.h"
#include "exceptions/NoSuchPassengerException.h"
#include "system_elements/Engineer.h"
#include "system_elements/RepairShop.h"

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
	 * Returns the vector of active passengers.
	 * 
	 * @return std::vector<Passenger*>
	 */
    std::vector<Passenger *> getPassengers();
	/**
	 * @brief Get the Trips vector.
	 * 
	 * Returns the map of enabled trips.
	 * 
	 * @return std::vector<Trip*>
	 */
    std::vector<Trip *> getTrips();
	/**
	 * @brief Get the Trains map.
	 * 
	 * Returns the map of enabled trains.
	 * 
	 * @return std::vector<Train*>
	 */
	std::vector<Train *> getTrains();
	/**
	 * @brief Get the Stations map.
	 * 
	 * Returns the map of enabled stations.
	 * 
	 * @return std::vector<Station*>
	 */
	std::vector<Station *> getStations();
	/**
	 * Returns the enabled engineers vector.
	 *
	 * @return std::vector<Engineer*>
	 */
	std::vector<Engineer*> getEngineers();
	/**
	 * Returns the vector of past engineers.
	 *
	 * @return
	 */
	std::vector<Engineer*> getPastEngineers();

	/**
	 * @brief Get Passenger pointer.
	 * 
	 * Returns the pointer to the passenger object with id specified in the parameter.
	 * If there is no such object, throws NoSuchPassengerException. 
	 * 
	 * @param id 
	 * @return Passenger* 
	 */
	Passenger* getPassenger(id_t id);
	/**
	 * @brief Get Trip pointer.
	 * 
	 * Returns the pointer to the trip object with id specified in the parameter.
	 * If there is no such object, throws NoSuchTripException. 
	 * 
	 * @param id 
	 * @return Trip* 
	 */
	Trip* getTrip(id_t id);
	/**
	 * @brief Get the Train pointer.
	 * 
	 * Returns the pointer to the train object with id specified in the parameter.
	 * If there is no such object, throws NoSuchTrainException. 
	 * 
	 * @param id 
	 * @return Train* 
	 */
	Train* getTrain(id_t id);
	/**
	 * @brief Get the Station pointer.
	 * 
	 * Returns the pointer to the station object with id specified in the parameter.
	 * If there is no such object, throws NoSuchStationxception. 
	 * 
	 * @param id 
	 * @return Station* 
	 */
	Station* getStation(id_t id);
	/**
	 * Returns pointer to the engineer that has the specified ID.
	 * If the ID doesn't exist, throws NoSuchEngineerException.
	 *
	 * @param id
	 * @return Engineer*
	 */
	Engineer* getEngineer(id_t id);

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
	 * Sets the passanger with specified ID as inactive, effectively marking it as removed.
	 *
	 * @param id 
	 */
	void removePassenger(id_t id);
	/**
	 * @brief Remove Trip from the system
	 * 
	 * Sets the trip with specified ID as inactive, effectively marking it as removed.
	 *
	 * @param id 
	 */
	void removeTrip(id_t id);
	/**
	 * @brief Remove Station from the system
	 * 
	 * Sets the station with specified ID as inactive, effectively marking it as removed.
	 *
	 * @param id 
	 */
	void removeStation(id_t id);
	/**
	 * @brief Remove Train from the system
	 * 
	 * Sets the train with specified ID as inactive, effectively marking it as removed.
	 *
	 * @param id 
	 */
	void removeTrain(id_t id);
	/**
	 * @brief Remove Engineer from the system
	 *
	 * Sets the engineer with specified ID as inactive, effectively marking it as removed.
	 *
	 * @param id
	 */
	void removeEngineer(id_t id);
	/**
	 * @brief Remove Repair Shop from the system
	 *
	 * Sets the repair shop with specified ID as inactive, effectively marking it as removed.
	 *
	 * @param id
	 */
	void removeRepairShop(id_t id);

	/**
	 * @brief Create a Passenger object
	 * 
	 * Creates a passenger object and adds it to the respective vector.
	 * 
	 * @param name 
	 * @param birthDate 
	 */
	void createPassenger(std::string &name, Date birthDate);
	/**
	 * @brief Create a Card object
	 * 
	 * Creates a passenger card object and adds it to the respective passenger.
	 * 
	 * @param p 
	 * @param type 
	 */
	void createCard(Passenger *p, std::string &type);
	/**
	 * @brief Create a Station object
	 * 
	 * Creates a station object and adds it to the respective vector.
	 * 
	 * @param name
	 * @param x
	 * @param y
	 */
	void createStation(std::string &name, int x, int y);
	/**
	 * @brief Create a Train object
	 *
	 * Creates a train object and adds it to the respective vector.
	 *
	 * @param maxSeats
	 * @param type tpe of the train AP/IC
	 */
	void createTrain(uint maxSeats, std::string type);
	/**
	 * @brief Create a Trip object
	 * 
	 * Creates a station object and adds it to the respective vector.
	 * 
	 * @param basePrice 
	 * @param source 
	 * @param destination 
	 * @param train
	 * @param engy
	 * @param departureDate
	 * @param arrivalDate 
	 */
	void createTrip(uint basePrice, Station* source, Station* destination,
			Train* train, Engineer* engy, Date departureDate, Date arrivalDate);
	/**
	 *
	 * Creates an Engineer object
	 *
	 * @param name
	 * @param birthDate
	 */
	void createEngineer(std::string name, Date birthDate);
	/**
	 * Finds the inactive engineer object with specified ID, and marks it as active.
	 * Effectively hiring him.
	 *
	 * If there is no inactive engineer with the specified ID, throws NoSuchEngineerException.
	 *
	 * @param id
	 */
	void hireEngineer(id_t id);

	/**
	 * Creates a Repair Shop oobject
	 *
	 * @param name
	 * @param x
	 * @param y
	 */
	void createRepairShop(std::string &name, int x, int y);

	/**
	 * Finds the repair shop that is available in the least time and is within
	 * a specified distance from the provided station. And puts the specified train object
	 * there, marking it as unhealthy.
	 *
	 * @param tr
	 * @param st
	 * @param distance
	 */
	void sendTrainToRepairShop(Train *tr, Station *st, uint distance);

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

	/**
	 * Get the logs vector.
	 *
	 * @return std::vector<PurchaseLog>
	 */
	const std::vector<PurchaseLog> & getLogs() const;

	/**
	 * Advances the day in the system, updating the repairshops.
	 *
	 */
	void advanceDay();

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
	 * Prints all stations' information in a formated table.
	 * 
	 * @param os 
	 */
	void listStations(std::ostream &os);
	/**
	 * @brief Print a table of trains
	 * 
	 * Prints all trains' information in a formated table.
	 * 
	 * @param os 
	 */
	void listHealthyTrains(std::ostream &os);
	/**
	 * @brief Print a table of trips
	 * 
	 * Prints all trips' information in a formated table.
	 * 
	 * @param os 
	 */
	void listTrips(std::ostream &os);
	/**
	 * Prints all trains in a formatted table.
	 *
	 * @param os
	 */
	void listEngineers(std::ostream &os);
	/**
	 * Print all active engineers in a formatted table.
	 *
	 * @param os
	 */
	void listPastEngineers(std::ostream &os);
	/**
	 * Print all active repair shops in a formatted table.
	 *
	 * @param os
	 */
	void listRepairShops(std::ostream &os);

	void savePassengers();
	void saveEngineers();
	void saveStations();
	void saveTrains();
	void saveTrips();
	void saveRepairShops();
	void savePurchases();

	void loadPassengers();
	void loadEngineers();
	void loadCards();
	void loadStations();
	void loadTrains();
	void loadTrips();
	void loadRepairShops();
	void loadPurchases();

private:
	/**
	 * @brief Passengers map
	 * 
	 */
	std::map<id_t, Passenger*> passengers;
	/**
	 * @brief Trips map
	 * 
	 */
	std::map<id_t, Trip*> trips;
	/**
	 * @brief Trains map
	 * 
	 */
	std::map<id_t, Train*> trains;
	/**
	 * @brief Stations map
	 * 
	 */
	std::map<id_t, Station*> stations;

	/**
	 * Hash table with all the engineers.
	 */
	std::unordered_set<Engineer*, Engineer::EngineerHashUtils, Engineer::EngineerHashUtils> engineers;

	/**
	 * Repair shops priority queue, keeps the ones that are more likely to become available at top.
	 */
	std::priority_queue<RepairShop*, vector<RepairShop*>,RepairShop::RepairShopPQUtils> shopsPQ;
	/**
	 * Map with all the repair shops.
	 */
	std::map<id_t ,RepairShop*> repairShops;

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

public:
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
};

#endif /* SYSTEM_H_ */
