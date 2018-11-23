#include "System.h"
#include "exceptions/NoSuchPassengerException.h"
#include "exceptions/NoSuchStationException.h"
#include "exceptions/NoSuchTrainException.h"
#include "exceptions/NoSuchTripException.h"
#include "exceptions/TripPastException.h"
#include <algorithm>
#include <iomanip>

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

int System::getStationIndex(id_t stationID) {
	for (uint i = 0; i < stations.size(); i++) {
		if (stations[i]->getID() == stationID) {
			return i;
		}
	}
	return -1;
}

int System::getTrainIndex(id_t trainID) {
	for (uint i = 0; i < trains.size(); i++) {
		if (trains[i]->getID() == trainID) {
			return i;
		}
	}
	return -1;
}

int System::getTripIndex(id_t tripID) {
	for (uint i = 0; i < trips.size(); i++) {
		if (trips[i]->getID() == tripID) {
			return i;
		}
	}
	return -1;
}

vector<Trip*> System::searchTrips(Station *src, Station *dest, bool searchByArrivalDate, Date arrivalDate) {
	
	if (src == nullptr && dest == nullptr && !searchByArrivalDate) {
		return trips;
	}

	vector<Trip*> res;

	for (Trip *tr: trips) {
		bool srcMatch = src == nullptr;
		bool destMatch = dest == nullptr;
		bool arrivalMatch = !searchByArrivalDate;
		if (!srcMatch) {
			srcMatch = tr->getSource() == src;
		}
		if (!destMatch) {
			destMatch = tr->getDest() == dest;
		}
		if (!arrivalMatch) {
			arrivalMatch = tr->getArrivalDate() <= arrivalDate;
		}
		if (srcMatch && destMatch && arrivalMatch) {
			res.push_back(tr);
		}
	}

	return res;

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
	} else if (type == "hundred") {
		cardType = PassengerCard::hundred;
	} else {
		cout << "Invalid card type: " << type << endl;
		return;
	}

	PassengerCard *pc = new PassengerCard(cardType, passenger->getID(), passenger->getName());
	passenger->setCard(pc);
	cardsToPay.push_back(passenger);
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
			Train* train, const Date departureDate, const Date arrivalDate) {
	Trip *tr = new Trip(basePrice, source, destination, train, departureDate, arrivalDate);
	trips.push_back(tr);
}

bool System::removePassenger(id_t id){
	for (auto it = passengers.begin(); it != passengers.end(); it++) {
		if ((*it)->getID() == id) {
			Passenger* temp = *it;
			it = --passengers.erase(it);
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
			it = --trips.erase(it);
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
			removeTrip(tr->getID());
		}
	}

	for (auto it = stations.begin(); it != stations.end(); it++) {
		if ((*it)->getID() == id) {
			Station* temp = *it;
			it = --stations.erase(it);
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
			removeTrip(tr->getID());
		}
	}

	for (auto it = trains.begin(); it != trains.end(); it++) {
		if ((*it)->getID() == id) {
			Train* temp = *it;
			it = --trains.erase(it);
			delete temp;
			return true;
		}
	}
	return false;
}

void System::sortPassengers() {
	sort(passengers.begin(), passengers.end(), [](const Passenger *p1, const Passenger *p2)->bool{
		return p1->getID() < p2->getID();
	});
}

void System::sortPassengersByName() {
	sort(passengers.begin(), passengers.end(), [](const Passenger* p1, const Passenger* p2)->bool{
		return p1->getName() < p2->getName();
	});
}

void System::sortStations() {
	sort(stations.begin(), stations.end(), [](const Station *st1, const Station *st2)->bool{
		return st1->getID() < st2->getID();
	});
}

void System::sortTrains() {
	sort(trains.begin(), trains.end(), [](const Train *tr1, const Train *tr2)->bool{
		return tr1->getID() < tr2->getID();
	});
}

void System::sortTrips(){
	sort(trips.begin(), trips.end(), [](const Trip *tr1, const Trip *tr2)->bool{
		return tr1->getID() < tr2->getID();
	});
}

void System::sortTripsByDate() {
	sort(trips.begin(), trips.end(), [](Trip *tr1, Trip *tr2)->bool{
		return tr1->getDepartureDate() < tr2->getDepartureDate();
	});
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
		PassengerCard* card = request.passenger->getCard();
		if (card != nullptr) {
			price *= 1-(card->getDiscount()/100.0);
		}
		request.setInvoicePrice(price);
		PurchaseLog log(request.trip->getID(),request.passenger->getName(), 
			request.trip->getSource()->getName(),
			request.trip->getDest()->getName(),
			request.trip->getDepartureDate().getDateString(),
			to_string(price));
		request.passenger->logTrip(log);
		logPurchase(log);
		return true;
	} else {
		return false;
	}
}

void System::logPurchase(PurchaseLog log) {
	sales.push_back(log);
}

const vector<PurchaseLog> & System::getLogs() const {
	return sales;
}

void System::processCards() {
	for (auto it = cardsToPay.begin(); it != cardsToPay.end(); it++) {
		Passenger *p = *it;
		cout << "Passenger " << p->getName() << " of ID " << p->getID()
		<< " has not payed his/her card, invalidating it." << endl;
		p->removeCard();
	}
	cardsToPay.clear();
	for (Passenger *p: passengers) {
		if (p->getCard() != nullptr) {
			cardsToPay.push_back(p);
		}
	}
}

bool System::payCard(id_t passengerID, ostream &os) {
	
	for (Passenger *p: passengers) {
		if (p->getID() == passengerID) {
			auto it = find(cardsToPay.begin(), cardsToPay.end(), p);
			if (it != cardsToPay.end()) {
				cardsToPay.erase(it);
				os << endl;
				os << "Nome: " << p->getName() << endl;
				string costString = to_string(p->getCard()->getCost());
				costString.insert(costString.end()-2, ',');
				os << "Valor do cartao: " << costString << " euros" << endl;
				return true;
			} else {
				return false;
			}
		}
	}

	throw NoSuchPassengerException(passengerID);
}

void System::listPassengers(ostream &os){
	sortPassengersByName();
	os << endl 
	<< setw(5) << "id" 
	<< setw(35) << "name" 
	<< setw(15) << "birthdate" 
	<< setw(15) << "card type" << endl;
	for (Passenger *p: passengers) {
		p->printRow(os);
		os << endl;
	}
	os << endl;
}

void System::listStations(ostream &os) {
	os << endl
	<< setw(5) << "id" 
	<< setw(35) << "name" << endl;
	for (Station *st: stations) {
		st->printRow(os);
		os << endl;
	}
	os << endl;
}

void System::listTrains(ostream &os) {
	os << endl 
	<< setw(5) << "id"
	<< setw(12) << "max seats" << endl;
	for (Train *tr: trains) {
		tr->printRow(os);
		os << endl;
	}
	os << endl;
}

void System::listTrips(ostream &os){
	os << endl 
	<< setw(5) << "id"
	<< setw(13) << "base price" 
	<< setw(16) << "current price" 
	<< setw(20) << "source name" 
	<< setw(20) << "departure date" 
	<< setw(20) << "destination name" 
	<< setw(20) << "arrival date" 
	<< setw(10) << "train id" 
	<< setw(16) << "free seats" << endl;
	for (Trip *tr: trips) {
		tr->printRow(os);
		os << endl;
	}
	os << endl;
}

void System::printPassengers(ostream &os) const {
	for (Passenger *p: passengers) {
		os << *p << endl;
	}
}

void System::printStations(ostream &os) const {
	for (Station *st: stations) {
		os << *st << endl;
	}
}

void System::printTrains(ostream &os) const {
	for (Train *tr: trains) {
		os << *tr << endl;
	}
}

void System::printTrips(ostream &os) const {
	for (Trip *tr: trips) {
		os << *tr << endl;
	}
}

void System::printSales(ostream &os) const {
	for (PurchaseLog log: sales) {
		os << endl << log << endl;
	}
}

ostream &operator<< (ostream &os, System &sys) {
	sys.printPassengers(os);
	sys.printStations(os);
	sys.printTrains(os);
	sys.printTrips(os);
	return os;
}
