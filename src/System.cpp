#include "System.h"
#include "NoSuchPassengerException.h"
#include "NoSuchStationException.h"
#include "NoSuchTrainException.h"
#include "NoSuchTripException.h"

using namespace std;

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

std::vector<Passenger*>& System::getPassengers() {
	return passengers;
}

std::vector<Station*>& System::getStations() {
	return stations;
}

std::vector<Train*>& System::getTrains() {
	return trains;
}

std::vector<Trip*>& System::getTrips() {
	return trips;
}

Passenger* System::getPassenger(const id_t id) {
	for (Passenger* p: passengers) {
		if (p->getID() == id) {
			return p;
		}
	}

	throw NoSuchPassengerException(id);
}
	
Trip* System::getTrip(const id_t id) {
	for (Trip* t: trips) {
		if (t->getID() == id) {
			return t;
		}
	}

	throw NoSuchTripException(id);
}

Train* System::getTrain(const id_t id) {
	for (Train* t: trains) {
		if (t->getID() == id) {
			return t;
		}
	}

	throw NoSuchTrainException(id);
}

Station* System::getStation(const id_t id) {
	for (Station* st: stations) {
		if (st->getID() == id) {
			return st;
		}
	}

	throw NoSuchStationException(id);
}

bool System::createPassenger(const vector<string> &arguments) {
	try {
		Passenger *p = new Passenger(arguments[0], arguments[1]);
		addPassenger(p);
	}catch (out_of_range &e) {
		cerr << "Invalid number of arguments." << endl;
		return false;
	} catch (exception &e) {
		cerr << e.what() << endl;;
		return false;
	}
	return true;
}

bool System::createStation(const vector<string> &arguments) {
	try {
		Station *st = new Station(arguments[0]);
		addStation(st);
	} catch (out_of_range &e) {
		cerr << "Invalid number of arguments." << endl;
		return false;
	} catch (exception &e) {
		cerr << e.what() << endl;
		return false;
	}
	return true;
}

bool System::createTrain(const vector<string> &arguments) {
	try {
		Train *tr = new Train(stoi(arguments[0]));
		addTrain(tr);
	} catch (out_of_range &e) {
		cerr << "Invalid number of arguments." << endl;
		return false;
	} catch (exception &e) {
		cerr << e.what() << endl;
		return false;
	}
	return true;
}

bool System::createTrip(const vector<string> &arguments) {
	try {
		Station *src = getStation(stoi(arguments[1]));
		Station *dest = getStation(stoi(arguments[2]));
		Train *train = getTrain(stoi(arguments[3]));
		Trip *tr = new Trip(stoi(arguments[0]), src, dest, train, arguments[4], arguments[5]);
		addTrip(tr);
	} catch (out_of_range &e) {
		cerr << "Invalid number of arguments." << endl;
		return false;
	} catch (exception &e) {
		cerr << e.what() << endl;
		return false;
	}
	return true;
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

void System::printPassengers(ostream &os) const {
	for (Passenger *p: passengers) {
		os << *p << endl;
	}
}

void System::printStations(std::ostream &os) const {
	for (Station *st: stations) {
		os << *st << endl;
	}
}

void System::printTrains(std::ostream &os) const {
	for (Train *tr: trains) {
		os << *tr << endl;
	}
}

void System::printTrips(std::ostream &os) const {
	for (Trip *tr: trips) {
		os << *tr << endl;
	}
}

ostream &operator<< (ostream &os, System &sys) {
	sys.printPassengers(os);
	sys.printStations(os);
	sys.printTrains(os);
	sys.printTrips(os);
	return os;
}
