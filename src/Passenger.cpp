#include "Passenger.h"

using namespace std;

id_t Passenger::currentID = 0;

Passenger::Passenger(string name, string birthDate): name(name), birthDate(birthDate) {
	this->passengerID = currentID++;
	this->card = nullptr;
}

Passenger::~Passenger() {
	delete card;
}

id_t Passenger::getID() const {
	return passengerID;
}

const vector<Trip*> & Passenger::getTrips() const {
	return trips;
}

std::string Passenger::getName() const {
	return name;
}

PassengerCard* Passenger::getCard() const {
	return card;
}

const Date& Passenger::getBirthDate() const {
	return birthDate;
}

bool Passenger::addTrip(Trip* trip) {
	for (Trip* t: trips) {
		if (t->getID() == trip->getID()) {
			return false;
		}
	}
	trips.push_back(trip);
	return true;
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
	return os;
}

