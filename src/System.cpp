#include <fstream>
#include "System.h"
#include "exceptions/NoSuchPassengerException.h"
#include "exceptions/NoSuchStationException.h"
#include "exceptions/NoSuchTrainException.h"
#include "exceptions/NoSuchTripException.h"
#include "exceptions/TripPastException.h"
#include "exceptions/NoSuchEngineerException.h"
#include "system_elements/AlfaPendular.h"
#include "system_elements/InterCidades.h"
#include "exceptions/InvalidTrainTypeException.h"
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

vector<Passenger *> System::getPassengers() {
    vector<Passenger*> res;
    for_each(passengers.begin(), passengers.end(), [&res](const pair<id_t, Passenger*>& item){
        if (item.second->isActive()) {
			res.push_back(item.second);
        }
    });
	return res;
}

vector<Station *> System::getStations() {
	vector<Station*> res;
    for_each(stations.begin(), stations.end(), [&res](const pair<id_t, Station*>& item){
        if (item.second->isActive()) {
			res.push_back(item.second);
        }
    });
	return res;
}

vector<Train *> System::getTrains() {
	vector<Train*> res;
    for_each(trains.begin(), trains.end(), [&res](const pair<id_t, Train*>& item){
        if (item.second->isActive()) {
			res.push_back(item.second);
        }
    });
	return res;
}

vector<Trip *> System::getTrips() {
	vector<Trip*> res;
    for_each(trips.begin(), trips.end(), [&res](const pair<id_t, Trip*>& item){
        if (item.second->isActive()) {
			res.push_back(item.second);
        }
    });
	return res;
}

Passenger* System::getPassenger(const id_t id) {
	try {
		Passenger* p = passengers.at(id);
		if (!p->isActive()) {
			throw NoSuchPassengerException(id);
		}
		return p;
	} catch (out_of_range &e) {
		throw NoSuchPassengerException(id);
	}
}
	
Trip* System::getTrip(const id_t id) {
	try {
		Trip *tr = trips.at(id);
		if (!tr->isActive()) {
			throw NoSuchTripException(id);
		}
		return tr;
	} catch (out_of_range &e) {
		throw NoSuchTripException(id);
	}
}

Train* System::getTrain(const id_t id) {
	try {
		Train *tr = trains.at(id);
		if (!tr->isActive()) {
			throw NoSuchTrainException(id);
		}
		return tr;
	} catch (out_of_range &e) {
		throw NoSuchTrainException(id);
	}
}

Station* System::getStation(const id_t id) {
	try {
		Station *st = stations.at(id);
		if (!st->isActive()) {
			throw NoSuchStationException(id);
		}
		return st;
	} catch (out_of_range &e) {
		throw NoSuchStationException(id);
	}
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
		if (!item.second->isActive()) {
			continue;
		}
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

void System::createPassenger(string &name, Date birthDate) {
	Passenger *p = new Passenger(name, birthDate);
	srand((uint) time(nullptr));
	id_t id = rand();
	auto result = passengers.insert(pair<id_t, Passenger*>(id, p));
	while (!result.second) {
		id = rand();
		result = passengers.insert(pair<id_t, Passenger*>(id, p));
	}
	p->setID(id);
}

void System::createCard(Passenger *passenger, string &type) {

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

void System::createStation(string &name) {
	Station *st = new Station(name);
	srand((uint)time(nullptr));
	id_t id = rand();
	auto result = stations.insert(pair<id_t, Station*>(id, st));
	while (!result.second) {
		id = rand();
		result = stations.insert(pair<id_t, Station*>(id, st));
	}
	st->setID(id);
	stationsBST.insert(*st);
}

void System::createTrain(uint maxSeats, string type) {
	Train *tr;
	if (type == "AP") {
		tr = new AlfaPendular(maxSeats);
	} else if (type == "IC") {
		tr = new InterCidades(maxSeats);
	} else {
        throw InvalidTrainTypeException(type);
	}
	srand((uint)time(nullptr));
	id_t id = (id_t) rand();
	auto result = trains.insert(pair<id_t, Train*>(id,tr));
	while (!result.second) {
		id = (id_t) rand();
		result = trains.insert(pair<id_t, Train*>(id,tr));
	}
	tr->setID(id);
}

void System::createTrip(uint basePrice, Station* source, Station* destination,
			Train* train, Engineer* engy, const Date departureDate, const Date arrivalDate) {
	Trip *tr = new Trip(basePrice, source, destination, train, engy, departureDate, arrivalDate);
	engy->addTrip(tr);
    srand((uint)time(nullptr));
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
	try {
		Passenger *p = getPassenger(id);
		p->setInactive();
		p->removeCard();
	} catch (NoSuchPassengerException &e) {
		cout << endl << e.what() << endl;
	}
}

void System::removeTrip(id_t id){
	try {
		Trip *tr = getTrip(id);
		tr->setInactive();
	} catch (NoSuchTripException &e) {
        cout << endl << e.what() << endl;
	}
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
		trips[id]->setInactive();
	});

	try {
		Station *st = getStation(id);
		st->setInactive();
	} catch (NoSuchStationException &e) {
		cout << endl << e.what() << endl;
	}
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
		trips[id]->setInactive();
	});

	try {
		Train *tr = getTrain(id);
		tr->setInactive();
	} catch (NoSuchTrainException &e) {
		cout << endl << e.what() << endl;
	}

}

bool System::processTicketPurchaseRequest(TicketPurchaseRequest &request) {
	
	time_t currTime = time(nullptr);
	time_t tripTime = request.trip->getDepartureDate().getTimeStamp();
	if (tripTime <= currTime) {
		throw TripPastException();
	}
	
	if (request.trip->bookSeat()) {
		uint price = request.trip->getCurrentPrice();
		PassengerCard* card = request.passenger->getCard();
		if (card != nullptr) {
			price -= (uint) (price*(card->getDiscount()/100.0F));
		}
		request.setInvoicePrice(price);
		PurchaseLog log(request.trip->getID(), request.passenger->getID(), price);
		request.passenger->logTrip(log);
		logPurchase(log);
		stationsBST.erase(*request.trip->getDest());
		request.trip->getDest()->addPassenger();
		stationsBST.insert(*request.trip->getDest());
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
    vector<Passenger*> vec = getPassengers();
    sort(vec.begin(), vec.end(), [](const Passenger* p1, const Passenger* p2)->bool{
		return p1->getName() < p2->getName();
	});
	os << endl
	<< setw(5) << "id" 
	<< setw(35) << "name" 
	<< setw(15) << "birthdate" 
	<< setw(15) << "card type" << endl;
	for (auto item: vec) {
		item->printRow(os);
		os << endl;
	}
	os << endl;
}

void System::listStations(ostream &os) {
	os << endl
	<< setw(5) << "id" 
	<< setw(35) << "name" << endl;
	for (auto item : getStations()) {
		item->printRow(os);
		os << endl;
	}
	os << endl;
}

void System::listStationsBST(ostream &os){
	os << endl
	<< setw(5) << "id"
	<< setw(35) << "name"
	<< setw(65) << "Number" << endl;
	for (auto itr = stationsBST.begin(); itr != stationsBST.end(); ++itr){
        itr->printRow(os);
        os << setw(65) << itr->getPassengerNumber() << endl;
    }
	os << endl;
}

void System::listTrains(ostream &os) {
	os << endl 
	<< setw(5) << "id"
	<< setw(12) << "max seats"
	<< setw(8) << "type" << endl;
	for (auto item: getTrains()) {
		item->printRow(os);
		os << endl;
	}
	os << endl;
}

void System::listTrips(ostream &os){
	vector<Trip*> vec = getTrips();
	sort(vec.begin(), vec.end(), [](Trip *tr1, Trip *tr2)->bool{
		return tr1->getDepartureDate() < tr2->getDepartureDate();
	});
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
	for (auto item: vec) {
		item->printRow(os);
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
		passengersFile << p->getID() << " " << p->isActive()
		<< " \"" << p->getName() << "\" \"" << p->getBirthDate().getDateString() << "\"" << endl;

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
		stationsFile << st->getID() << " " << st->isActive() << " \"" << st->getName() << "\"" << endl;
	}
	stationsFile.close();
}

void System::saveTrains() {
	ofstream trainsFile("trains.txt", ofstream::out | ofstream::trunc);
	for(auto &item: trains) {
		Train *tr = item.second;
		trainsFile << tr->getID() << " " << tr->isActive() << " " << tr->getMaxSeats() << " " << tr->getType() << endl;
	}
	trainsFile.close();
}

void System::saveTrips() {
	ofstream tripsFile("trips.txt", ofstream::out | ofstream::trunc);
	for (auto &item: trips) {
	    Trip *tr = item.second;
		tripsFile << tr->getID() << " " << tr->isActive() << " " << tr->getBasePrice() << " "
		<< tr->getSource()->getID() << " " << tr->getDest()->getID() << " " << tr->getTrain()->getID() << " "
		<< tr->getEngineer()->getID() << " "
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
    ifstream passengersFile("passengers.txt");
	if (passengersFile.is_open()) {
		string line;
		while (getline(passengersFile, line)) {
			vector<string> arguments = project_utils::splitArguments(line);

			if (arguments.size() != 4) {
				continue;
			}

			try {
				Date birthDate(arguments[3]);
				Passenger *p = new Passenger(arguments[2], birthDate);
				p->setID((id_t)stoul(arguments[0]));
				if (!stoi(arguments[1])) {
					p->setInactive();
				}
				passengers.insert(pair<id_t, Passenger*>(p->getID(),p));
			} catch (...) {
				continue;
			}
		}
		passengersFile.close();
	}
}

void System::loadCards() {
    ifstream cardsFile("cards.txt");
	if (cardsFile.is_open()) {
		string line;
		while (getline(cardsFile, line)) {
			vector<string> arguments = project_utils::splitArguments(line);

			if (arguments.size() != 2) {
				continue;
			}

			try {
				Passenger *p = getPassenger((id_t)stoul(arguments[0]));
				createCard(p, arguments[1]);
			} catch (...) {
				continue;
			}
		}
		cardsFile.close();
	}
}

void System::loadStations() {
	ifstream stationsFile("stations.txt");
	string line;
	if (stationsFile.is_open()) {
		while (getline(stationsFile, line)) {
			vector<string> arguments = project_utils::splitArguments(line);
			if (arguments.size() != 3) {
				continue;
			}

			try {
				Station *st = new Station(arguments[2]);
				st->setID((id_t) stoul( arguments[0] ));
				if (!stoi(arguments[1])) {
					st->setInactive();
				}
				stations.insert(pair<id_t,Station*>(st->getID(),st));
				stationsBST.insert(*st);
			} catch (...) {
				continue;
			}
		}
		stationsFile.close();
	}
}

void System::loadTrains() {
	ifstream trainsFile("trains.txt");
	string line;
	if (trainsFile.is_open()) {
		while (getline(trainsFile, line)) {
			vector<string> arguments = project_utils::splitArguments(line);

			if (arguments.size() != 4) {
				continue;
			}

			try {
				Train *tr;
				if (arguments[3] == "AP") {
					tr = new AlfaPendular(stoi(arguments[2]));
				} else if (arguments[3] == "IC") {
					tr = new InterCidades(stoi(arguments[2]));
				} else {
					continue;
				}
				tr->setID((id_t)stoul(arguments[0]));
				if (!stoi(arguments[1])){
					tr->setInactive();
				}
				trains.insert(pair<id_t, Train*>(tr->getID(), tr));
			} catch (...) {
				continue;
			}
		}
		trainsFile.close();
	}
}

void System::loadTrips() {
	ifstream tripsFile("trips.txt");
	string line;
	if (tripsFile.is_open()) {
		while (getline(tripsFile, line)) {
			vector<string> arguments = project_utils::splitArguments(line);
			if (arguments.size() != 8) {
				continue;
			}

			try {
				Station *src = getStation((id_t)stoul(arguments[3]));
				Station *dest = getStation((id_t)stoul(arguments[4]));
				Train *tr = getTrain((id_t)stoul(arguments[5]));
				Engineer *eng = getEngineer((id_t)stoul(arguments[6]));
				Date dep(arguments[7]);
				Date arr(arguments[8]);
				Trip *trip = new Trip((uint) stoul(arguments[2]), src, dest, tr, eng, dep, arr);
				trip->setID((id_t)stoul(arguments[0]));
				eng->addTrip(trip);
				if (!stoi(arguments[1])) {
					tr->setInactive();
				}
				trips.insert(pair<id_t,Trip*>(trip->getID(),trip));
			} catch (...) {
				continue;
			}
		}
		tripsFile.close();
	}
}

void System::loadPurchases() {
	ifstream purchasesFile("purchases.txt");
	string line;
	if (purchasesFile.is_open()) {
		while (getline(purchasesFile, line)) {
			vector<string> arguments = project_utils::splitArguments(line);
			if (arguments.size() != 3) {
				continue;
			}

			try {
				Passenger *p = getPassenger((id_t) stoul(arguments[1]));
                PurchaseLog log((id_t) stoul(arguments[0]), p->getID(), (uint) stoul(arguments[2]));
                p->logTrip(log);
                logPurchase(log);
			} catch (...) {
				continue;
			}
		}
	}
}

std::vector<Engineer *> System::getEngineers() {
    vector<Engineer*> res;

    for (auto it = engineers.begin(); it != engineers.end(); it++) {
    	if ((*it)->isActive()){
    		res.push_back((*it));
    	}
    }

	return res;
}

Engineer *System::getEngineer(id_t id) {
    for (auto it = engineers.begin(); it != engineers.end(); it++) {
    	if ((*it)->isActive()){
    	    if ((*it)->getID() == id) {
    	    	return *it;
    	    }
    	}
    }

    throw NoSuchEngineerException(id);
}

void System::removeEngineer(id_t id) {
	for (auto it = engineers.begin(); it != engineers.end(); it++) {
        if ((*it)->getID() == id && (*it)->isActive()) {
            return (*it)->setInactive();
        }
    }
}

void System::createEngineer(std::string name, Date birthDate) {
	Engineer *eng = new Engineer(name, birthDate);
	srand((uint)time(nullptr));
	id_t id = rand();
	eng->setID(id);
	auto result = engineers.insert(eng);
	while (!result.second) {
		id = rand();
		eng->setID(id);
		result = engineers.insert(eng);
	}
}

void System::saveEngineers() {
	ofstream engysFile("engineers.txt");
	for (Engineer* eng: engineers) {
		engysFile << eng->getID() << " "
		<< eng->isActive() << " "
		<< "\"" << eng->getName() << "\" "
		<< "\"" << eng->getBirthDate().getDateString() << "\"" << endl;
	}
}

void System::loadEngineers() {
	ifstream engysFile("engineers.txt");
	if (engysFile.is_open()) {
		string line;
		while (getline(engysFile, line)) {
			try {
				vector<string> args = project_utils::splitArguments(line);
				id_t ID = (id_t) stoul(args[0]);
				Date birth(args[3]);
				Engineer* eng = new Engineer(args[2], birth);
				eng->setID(ID);
				if (!stoul(args[1])) {
					eng->setInactive();
				}
				engineers.insert(eng);
			} catch (...) {
				continue;
			}
		}
	}
}

std::vector<Engineer *> System::getPastEngineers() {
	vector<Engineer*> res;

	for (auto it = engineers.begin(); it != engineers.end(); it++) {
		if (!(*it)->isActive()){
			res.push_back((*it));
		}
	}

	return res;
}

void System::listPastEngineers(std::ostream &os) {
    vector<Engineer*> vec = getPastEngineers();
    sort(vec.begin(), vec.end(), [](const Engineer* p1, Engineer* p2)->bool{
		return p1->getName() < p2->getName();
	});
	os << endl
	<< setw(5) << "id"
	<< setw(35) << "name"
	<< setw(15) << "birthdate" << endl;
	for (auto item: vec) {
		item->printRow(os);
		os << endl;
	}
	os << endl;
}

void System::listEngineers(std::ostream &os) {
	vector<Engineer*> vec = getEngineers();
	sort(vec.begin(), vec.end(), [](const Engineer* p1, Engineer* p2)->bool{
		return p1->getName() < p2->getName();
	});
	os << endl
	   << setw(5) << "id"
	   << setw(35) << "name"
	   << setw(15) << "birthdate" << endl;
	for (auto item: vec) {
		item->printRow(os);
		os << endl;
	}
	os << endl;
}

void System::hireEngineer(id_t id) {
    Engineer *toHire = nullptr;
	Engineer *search = new Engineer("",Date(Date::defaultDateString));
    search->setID(id);
	auto it = engineers.find(search);
	if (it != engineers.end()) {
		toHire = *it;
	}

    if (toHire == nullptr) {
		throw NoSuchEngineerException(id);
    } else if (toHire->isActive()) {
		throw NoSuchEngineerException(id);
    }

    toHire->setActive();

}
