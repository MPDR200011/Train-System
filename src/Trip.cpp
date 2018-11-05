#include "Trip.h"
#include "IdenticalDestinationException.h"
#include "ReverseDatesException.h"

using namespace std;

id_t Trip::currentID = 0;

Trip::Trip(uint basePrice, Station* source, Station* destination,
		Train* train, const std::string departureDate, const std::string arrivalDate):
		departureDate(departureDate), arrivalDate(arrivalDate){
	this->tripID = currentID++;
	this->occupiedSeats = 0;
	this->basePrice = basePrice;
	this->source = source;
	this->destination = destination;
	this->train = train;

	validate();
}

Trip::~Trip() {
	this->source = nullptr;
	this->destination = nullptr;
	this->train = nullptr;
}

void Trip::validate() {
	if (source == destination) {
		throw IdenticalDestinationException();
	}

	if (arrivalDate < departureDate) {
		throw ReverseDatesException(departureDate.getDateString(), arrivalDate.getDateString());
	}
}

id_t Trip::getID() const {
	return tripID;
}

uint Trip::getNumberOfFreeSeats() const {
	return train->getMaxSeats() - occupiedSeats;
}

float Trip::getBasePrice() const {
	return basePrice;
}

Station* Trip::getSource() const {
	return source;
}

Station* Trip::getDest() const {
	return destination;
}

Train* Trip::getTrain() const {
	return train;
}

const Date& Trip::getDepartureDate() const {
	return departureDate;
}

const Date& Trip::getArrivalDate() const {
	return arrivalDate;
}

bool Trip::bookSeat() {
	if (getNumberOfFreeSeats() == 0) {
		return false;
	} else {
		occupiedSeats++;
		return true;
	}
}

ostream &operator<<(ostream &os, Trip &tr) {
	os << "//// Trip ////" << endl;
	os << "Base price: " << tr.basePrice << endl;
	os << "Source: " << tr.source->getName() << endl;
	os << "Departure date: " << tr.departureDate << endl;
	os << "Destination: " << tr.destination->getName() << endl;
	os << "Arrival date: " << tr.arrivalDate << endl;
	os << "Train ID: " << tr.train->getID() << endl;
	os << "Occupied Seats: " << tr.occupiedSeats;
	return os;
}

