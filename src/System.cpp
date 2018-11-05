#include "System.h"

System System::instance = System();

System::~System() {
	for (Passenger* p: passengers) {
		delete p;
	}
	for (Trip* t: trips) {
		delete t;
	}
	for (Train* tr: trains) {
		delete tr;
	}
	for (Station* st: stations) {
		delete st;
	}
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

