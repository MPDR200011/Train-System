#include "System.h"
#include "exceptions/NoSuchPassengerException.h"
#include "exceptions/NoSuchStationException.h"
#include "exceptions/NoSuchTrainException.h"
#include "exceptions/NoSuchTripException.h"
#include "exceptions/TripPastException.h"
#include <algorithm>

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

void System::createPassenger(string name, Date birthDate) {
	Passenger *p = new Passenger(name, birthDate);
	passengers.push_back(p);
}

void System::createCard(Passenger *passenger, string type) {

	PassengerCard::CardType cardType;
	if (type == "twenty five") {
		cardType = PassengerCard::twentyFive;
	} else if (type == "fifty") {
		cardType = PassengerCard::fifty;
	} else {
		cardType = PassengerCard::hundred;
	}

	PassengerCard *pc = new PassengerCard(cardType, passenger->getID(), passenger->getName());
	passenger->setCard(pc);
}

void System::createStation(string name) {
	Station *st = new Station(name);
	stations.push_back(st);
}

void System::createTrain(uint maxSeats) {
	Train *tr = new Train(maxSeats);
	trains.push_back(tr);
}

void System::createTrip(uint basePrice, Station* source, Station* destination,
			Train* train, const Date dapartureDate, const Date arrivalDate) {
	Trip *tr = new Trip(basePrice, source, destination, train, dapartureDate, arrivalDate);
	trips.push_back(tr);
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

bool System::removePassenger(id_t id){
	for (auto it = passengers.begin(); it != passengers.end(); it++) {
		if ((*it)->getID() == id) {
			Passenger* temp = *it;
			passengers.erase(it);
			delete temp;
			return true;
		}
	}
	return false;
}

bool System::removeTrip(id_t id){
	for (auto it = trips.begin(); it != trips.end(); it++) {
		if ((*it)->getID() == id) {
			Trip* temp = *it;
			trips.erase(it);
			delete temp;
			return true;
		}
	}
	return false;
}

bool System::removeStation(id_t id) {
	for (auto it = trips.begin(); it != trips.end(); it++) {
		Trip *tr = *it;
		if (tr->getSource()->getID() == id || tr->getDest()->getID() == id) {
			trips.erase(it);
			delete tr;
		}
	}

	for (auto it = stations.begin(); it != stations.end(); it++) {
		if ((*it)->getID() == id) {
			Station* temp = *it;
			stations.erase(it);
			delete temp;
			return true;
		}
	}
	return false;
}

bool System::removeTrain(id_t id){
	for (auto it = trips.begin(); it != trips.end(); it++) {
		Trip *tr = *it;
		if (tr->getTrain()->getID() == id) {
			trips.erase(it);
			delete tr;
		}
	}

	for (auto it = trains.begin(); it != trains.end(); it++) {
		if ((*it)->getID() == id) {
			Train* temp = *it;
			trains.erase(it);
			delete temp;
			return true;
		}
	}
	return false;
}

bool System::processTicketPurchaseRequest(TicketPurchaseRequest &request) {
	
	time_t currTime = time(nullptr);
	time_t tripTime = request.trip->getDepartureDate().getTimeStamp();
	int timeDelta = tripTime - currTime;
	if (timeDelta < 0) {
		throw TripPastException();
	}
	
	if (request.trip->bookSeat()) {
		uint price = request.trip->getCurrentPrice();
		if (!request.passenger->addTrip(request.trip)) {
			PassengerCard* card = request.passenger->getCard();
			if (card != nullptr) {
				price *= 1-(card->getDiscount()/100.0);
			}
		}
		request.setInvoicePrice(price);
		return true;
	} else {
		return false;
	}
}

void System::processCards() {
	for (auto it = cardsToPay.begin(); it != cardsToPay.end(); it++) {
		Passenger *p = *it;
		cout << "Passenger " << p->getName() << " of ID " << p->getID()
		<< " has not payed his/her card, invalidating it." << endl;
		p->removeCard();
		cardsToPay.erase(it);
	}
	cardsToPay.clear();
	for (Passenger *p: passengers) {
		if (p->getCard() != nullptr) {
			cardsToPay.push_back(p);
		}
	}
}

bool System::payCard(id_t passengerID) {
	
	for (Passenger *p: passengers) {
		if (p->getID() == passengerID) {
			auto it = find(cardsToPay.begin(), cardsToPay.end(), p);
			if (it != cardsToPay.end()) {
				cardsToPay.erase(it);
				return true;
			} else {
				return false;
			}
		}
	}

	throw NoSuchPassengerException(passengerID);
}

void System::listPassengers(ostream &os){
	cout << "id - name - birthdate - card type" << endl;
	for (Passenger *p: passengers) {
		p->printRow(cout);
		cout << endl;
	}
	cout << endl;
}

void System::listStations(ostream &os) {
	cout << "id - name" << endl;
	for (Station *st: stations) {
		st->printRow(cout);
		cout << endl;
	}
	cout << endl;
}

void System::listTrains(ostream &os) {
	cout << "id - max seats" << endl;
	for (Train *tr: trains) {
		tr->printRow(cout);
		cout << endl;
	}
	cout << endl;
}

void System::listTrips(ostream &os){
	cout << "id - base price - source name - departure date - destination name - arrival date - train id - occupied seats" << endl;
	for (Trip *tr: trips) {
		tr->printRow(cout);
		cout << endl;
	}
	cout << endl;
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
