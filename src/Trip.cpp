#include "Trip.h"
#include "exceptions/IdenticalDestinationException.h"
#include "exceptions/ReverseDatesException.h"

using namespace std;

id_t Trip::currentID = 0;

Trip::Trip(uint basePrice, Station* source, Station* destination,
		Train* train, const Date departureDate, const Date arrivalDate):
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

uint Trip::getBasePrice() const {
	return basePrice;
}

uint Trip::getCurrentPrice() {
	time_t currTime = time(nullptr);
	time_t tripDep = departureDate.getTimeStamp();

	if (tripDep - currTime < FOURTY_HEIGHT_HOURS) {
		if (((float)occupiedSeats / (float)train->getMaxSeats()) < 0.5) {
			return basePrice * 0.3;
		}
	}

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

Date& Trip::getDepartureDate() {
	return departureDate;
}

Date& Trip::getArrivalDate() {
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

void Trip::printRow(ostream &os) {
	os << tripID << " " << basePrice << " " << getCurrentPrice() << " " << source->getName() << " " << departureDate.getDateString()
	<< " " << destination->getName() << " " << arrivalDate.getDateString() 
	<< " " << train->getID() << " " << occupiedSeats; 
}

ostream &operator<<(ostream &os, Trip &tr) {
	os << "//// Trip ////" << endl;
	os << "Base price: " << tr.basePrice << endl;
	os << "Current Price: " << tr.getCurrentPrice() << endl;
	os << "Source: " << tr.source->getName() << endl;
	os << "Departure date: " << tr.departureDate << endl;
	os << "Destination: " << tr.destination->getName() << endl;
	os << "Arrival date: " << tr.arrivalDate << endl;
	os << "Train ID: " << tr.train->getID() << endl;
	os << "Occupied Seats: " << tr.occupiedSeats << endl;
	return os;
}

