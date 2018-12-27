#include "Passenger.h"
#include <iomanip>

using namespace std;

Passenger::Passenger(string name, Date birthDate): Person(name, birthDate) {
	this->card = nullptr;
}

Passenger::~Passenger() {
	delete card;
}

void Passenger::setID(id_t id) {
	this->passengerID = id;
}

id_t Passenger::getID() const {
	return passengerID;
}

const vector<PurchaseLog> & Passenger::getTripLogs() const {
	return tripLogs;
}

bool Passenger::setCard(PassengerCard *c) {
	if (card == nullptr) {
		card = c;
		return true;
	} else {
		card->setType(c->getType());
		return false;
	}
}

PassengerCard* Passenger::getCard() const {
	return card;
}

void Passenger::logTrip(PurchaseLog log) {
	tripLogs.push_back(log);
}

void Passenger::removeCard() {
	delete card;
	card = nullptr;
}

void Passenger::printRow(ostream &os) {
	os << setw(5) << passengerID
	<< setw(35) << name
	<< setw(15) << birthDate.getDateStringWithoutHours()
	<< setw(15);
	if (card == nullptr) {
		os << " None";
	} else {
		switch (card->getDiscount()) {
			case 25:
				os << " Twenty-Five";
				break;
			case 50:
				os << " Fifty";
				break;
			case 100:
				os << " Hundred";
				break;
		}
	}
}

ostream &operator<<(ostream &os, Passenger &p) {
	os << "//// Passenger ////" << endl;
	os << "ID: " << p.passengerID << endl;
	os << "Name: " << p.name << endl;
	os << "BirthDate: " << p.birthDate << endl;
	os << "Card Type: ";
	if (p.card == nullptr) {
		os << "None";
	} else {
		switch(p.card->getDiscount()) {
			case 25:
				os << "Twenty Five";
				break;
			case 50:
				os << "Fifty";
				break;
			case 100:
				os << "Hundred";
				break;
			default:
				break;
		}
	}
	os << endl;
	return os;
}

