#include "System.h"

System System::instance = System();

System::~System() {
	passengers.clear();
	trips.clear();
	trains.clear();
	stations.clear();
}

const std::vector<Passenger*>& System::getPassengers() const {
	return passengers;
}

const std::vector<Station*>& System::getStations() const {
	return stations;
}

const std::vector<Train*>& System::getTrains() const {
	return trains;
}

const std::vector<Trip*>& System::getTrips() const {
	return trips;
}

