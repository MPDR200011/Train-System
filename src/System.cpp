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

Passenger* System::getPassenger(const id_t id) {
	for (Passenger* p: passengers) {
		if (p->getID() == id) {
			return p;
		}
	}

	return nullptr;
}
	
Trip* System::getTrip(const id_t id) {
	for (Trip* t: trips) {
		if (t->getID() == id) {
			return t;
		}
	}

	return nullptr;
}
Train* System::getTtrain(const id_t id) {
	for (Train* t: trains) {
		if (t->getID() == id) {
			return t;
		}
	}

	return nullptr;
}

Station* System::getStation(const id_t id) {
	for (Station* st: stations) {
		if (st->getID() == id) {
			return st;
		}
	}

	return nullptr;
}

bool System::addPassenger(Passenger* passenger) {
	passengers.push_back(passenger);
	return true;
}

bool System::addTrip(Trip* trip) {
	trips.push_back(trip);
	return true;
}

bool System::addTrain(Train* train) {
	trains.push_back(train);
	return true;
}

bool System::addStation(Station* station) {
	stations.push_back(station);
	return true;
}

bool System::processTicketPurchaseRequest(TicketPurchaseRequest &request) {
	if (request.trip->bookSeat()) {
		request.passenger->addTrip(request.trip);
		uint basePrice = request.trip->getBasePrice();
		PassengerCard* card = request.passenger->getCard();
		if (card != nullptr) {
			basePrice -= basePrice*(card->getDiscount()/100.0);
		}
		request.setPrice(basePrice);
		return true;
	} else {
		return false;
	}
}
