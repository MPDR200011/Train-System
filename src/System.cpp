#include <fstream>
#include "System.h"
#include "exceptions/NoSuchPassengerException.h"
#include "exceptions/NoSuchStationException.h"
#include "exceptions/NoSuchTrainException.h"
#include "exceptions/NoSuchTripException.h"
#include "exceptions/TripPastException.h"
#include <algorithm>
#include <iomanip>
#include <ctime>

using namespace std;

System System::instance = System();

System::~System() {
	for (auto &p: passengers) {
		delete p.second;
	}
	for (auto &t: trips) {
		delete t.second;
	}
	for (auto &tr: trains) {
		delete tr.second;
	}
	for (auto &st: stations) {
		delete st.second;
	}
	passengers.clear();
	trips.clear();
	trains.clear();
	stations.clear();
}

std::map<id_t, Passenger*>& System::getPassengers() {
	return passengers;
}

std::map<id_t, Station*>& System::getStations() {
	return stations;
}

std::map<id_t, Train*>& System::getTrains() {
	return trains;
}

std::map<id_t, Trip*>& System::getTrips() {
	return trips;
}

Passenger* System::getPassenger(const id_t id) {
	try {
		Passenger* p = passengers.at(id);
		return p;
	} catch (out_of_range &e) {
		throw NoSuchPassengerException(id);
	}
}
	
Trip* System::getTrip(const id_t id) {
	try {
		Trip *tr = trips.at(id);
		return tr;
	} catch (out_of_range &e) {
		throw NoSuchTripException(id);
	}
}

Train* System::getTrain(const id_t id) {
	try {
		Train *tr = trains.at(id);
		return tr;
	} catch (out_of_range &e) {
		throw NoSuchTrainException(id);
	}
}

Station* System::getStation(const id_t id) {
	try {
		Station *st = stations.at(id);
		return st;
	} catch (out_of_range &e) {
		throw NoSuchStationException(id);
	}
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

	vector<Trip*> res;
	if (src == nullptr && dest == nullptr && !searchByArrivalDate) {
	    for (auto &item: trips) {
	    	res.push_back(item.second);
	    }
		return res;
	}



	for (auto &item: trips) {
		bool srcMatch = src == nullptr;
		bool destMatch = dest == nullptr;
		bool arrivalMatch = !searchByArrivalDate;
		if (!srcMatch) {
			srcMatch = item.second->getSource() == src;
		}
		if (!destMatch) {
			destMatch = item.second->getDest() == dest;
		}
		if (!arrivalMatch) {
			arrivalMatch = item.second->getArrivalDate() <= arrivalDate;
		}
		if (srcMatch && destMatch && arrivalMatch) {
			res.push_back(item.second);
		}
	}

	return res;

}

void System::createPassenger(string name, Date birthDate) {
	Passenger *p = new Passenger(name, birthDate);
	srand(time(nullptr));
	id_t id = rand();
	auto result = passengers.insert(pair<id_t, Passenger*>(id, p));
	while (!result.second) {
		id = rand();
		result = passengers.insert(pair<id_t, Passenger*>(id, p));
	}
	p->setID(id);
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
	srand(time(nullptr));
	id_t id = rand();
	auto result = stations.insert(pair<id_t, Station*>(id, st));
	while (!result.second) {
		id = rand();
		result = stations.insert(pair<id_t, Station*>(id, st));
	}
	st->setID(id);
}

void System::createTrain(uint maxSeats) {
	Train *tr = new Train(maxSeats);
	srand(time(nullptr));
	id_t id = rand();
	auto result = trains.insert(pair<id_t, Train*>(id,tr));
	while (!result.second) {
		id = rand();
		result = trains.insert(pair<id_t, Train*>(id,tr));
	}
	tr->setID(id);
}

void System::createTrip(uint basePrice, Station* source, Station* destination,
			Train* train, const Date departureDate, const Date arrivalDate) {
	Trip *tr = new Trip(basePrice, source, destination, train, departureDate, arrivalDate);
    srand(time(nullptr));
	id_t id = rand();
	auto result = trips.insert(pair<id_t, Trip*>(id,tr));
	while (!result.second) {
		id = rand();
		result = trips.insert(pair<id_t, Trip*>(id,tr));
	}
	tr->setID(id);
}

void System::removePassenger(id_t id){
	for (auto it = cardsToPay.begin(); it != cardsToPay.end(); it++) {
		if ((*it)->getID() == id) {
			cardsToPay.erase(it);
			break;
		}
	}
	passengers.erase(id);
}

void System::removeTrip(id_t id){
	trips.erase(id);
}

void System::removeStation(id_t id) {
	vector<id_t> tripIds;
	for (auto &item: trips) {
		Trip *tr = item.second;
		if (tr->getSource()->getID() == id || tr->getDest()->getID() == id) {
		    tripIds.push_back(tr->getID());
		}
	}
	for_each(tripIds.begin(), tripIds.end(), [this](id_t id){
		trips.erase(id);
	});

	stations.erase(id);
}

void System::removeTrain(id_t id){
    vector<id_t> tripIds;
	for (auto &item: trips) {
		Trip *tr = item.second;
		if (tr->getTrain()->getID() == id) {
		    tripIds.push_back(tr->getID());
		}
	}
	for_each(tripIds.begin(), tripIds.end(), [this](id_t id){
		trips.erase(id);
	});

	trains.erase(id);
}
/*
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
}*/

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
			price *= 1.0F-(card->getDiscount()/100.0F);
		}
		request.setInvoicePrice(price);
		PurchaseLog log(request.trip->getID(), request.passenger->getID(), price);
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
	for (Passenger *p: cardsToPay) {
		cout << "Passenger " << p->getName() << " of ID " << p->getID()
		<< " has not payed his/her card, invalidating it." << endl;
		p->removeCard();
	}
	cardsToPay.clear();
	for (auto &item: passengers) {
		if (item.second->getCard() != nullptr) {
			cardsToPay.push_back(item.second);
		}
	}
}

bool System::payCard(id_t passengerID, ostream &os) {
	Passenger *p = getPassenger(passengerID);
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

void System::listPassengers(ostream &os){
	sortPassengersByName();
	os << endl 
	<< setw(5) << "id" 
	<< setw(35) << "name" 
	<< setw(15) << "birthdate" 
	<< setw(15) << "card type" << endl;
	for (auto &item: passengers) {
		item.second->printRow(os);
		os << endl;
	}
	os << endl;
}

void System::listStations(ostream &os) {
	os << endl
	<< setw(5) << "id" 
	<< setw(35) << "name" << endl;
	for (auto &item : stations) {
		item.second->printRow(os);
		os << endl;
	}
	os << endl;
}

void System::listTrains(ostream &os) {
	os << endl 
	<< setw(5) << "id"
	<< setw(12) << "max seats" << endl;
	for (auto &item: trains) {
		item.second->printRow(os);
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
	for (auto &item: trips) {
		item.second->printRow(os);
		os << endl;
	}
	os << endl;
}

void System::printPassengers(ostream &os) const {
	for (auto &item: passengers) {
		os << *item.second << endl;
	}
}

void System::printStations(ostream &os) const {
	for (auto &item: stations) {
		os << *item.second << endl;
	}
}

void System::printTrains(ostream &os) const {
	for (auto &item: trains) {
		os << *item.second << endl;
	}
}

void System::printTrips(ostream &os) const {
	for (auto &item: trips) {
		os << *item.second << endl;
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

void System::savePassengers() {
	ofstream passengersFile("passengers.txt", ofstream::out | ofstream::trunc);
	ofstream cardsFile("cards.txt", ofstream::out | ofstream::trunc);
	for (auto &item: passengers) {
		Passenger *p = item.second;
		passengersFile << p->getID() << " \"" << p->getName() << "\" \"" << p->getBirthDate().getDateString() << "\"" << endl;

		if (p->getCard() != nullptr) {
			cardsFile << p->getID() << " \"";
			switch (p->getCard()->getType()){
				case PassengerCard::twentyFive:
					cardsFile << "twenty five";
					break;
				case PassengerCard::fifty:
					cardsFile << "fifty";
					break;
				case PassengerCard::hundred:
					cardsFile << "hundred";
					break;
			}
			cardsFile << "\"" << endl;
		}
	}
	passengersFile.close();
	cardsFile.close();
}

void System::saveStations() {
	ofstream stationsFile("stations.txt", ofstream::out | ofstream::trunc);
	for(auto &item: stations) {
		Station *st = item.second;
		stationsFile << st->getID() << " \"" << tr->getName() << "\"" << endl;
	}
	stationsFile.close();
}

void System::saveTrains() {
	ofstream trainsFile("trains.txt", ofstream::out | ofstream::trunc);
	for(auto &item: trains) {
		Train *tr = item.second;
		trainsFile << tr->getID() << " " << tr->getMaxSeats() << endl;
	}
	trainsFile.close();
}

void System::saveTrips() {
	ofstream tripsFile("trips.txt", ofstream::out | ofstream::trunc);
	for (auto &item: trips) {
	    Trip *tr = item.second;
		tripsFile << tr->getID() << " " << tr->getBasePrice() << " "
		<< tr->getSource()->getID() << " " << tr->getDest()->getID() << " " << tr->getTrain()->getID() << " "
		<< "\"" << tr->getDepartureDate().getDateString() << "\" \""
		<< tr->getArrivalDate().getDateString() << "\"" << endl;
	}
	tripsFile.close();
}

void System::savePurchases() {
	ofstream purchasesFile("purchases.txt", ofstream::out | ofstream::trunc);
	for (PurchaseLog &pl: sales) {
		purchasesFile << pl.getTripID() << " " << pl.getPassengerID() << " " << pl.getPrice() << endl;
	}
	purchasesFile.clear();
}

void System::loadPassengers() {

}

void System::loadCards() {

}

void System::loadStations() {

}

void System::loadTrains() {

}

void System::loadTrips() {

}
