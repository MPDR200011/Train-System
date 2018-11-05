#include "Trip.h"
#include "IdenticalDestinationException.h"
#include "ReverseDatesException.h"

id_t Trip::currentID = 0;

Trip::Trip(uint basePrice, Station* source, Station* destination,
		Train* train, const std::string &departureDate, const std::string &arrivalDate):
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

id_t Trip::getTripID() const {
	return tripID;
}

uint Trip::getNumberOfFreeSeats() const {
	return train->getTotalSeats() - occupiedSeats;
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

Date& Trip::getDepartureDate() {
	return departureDate;
}

Date& Trip::getArrivalDate() {
	return arrivalDate;
}

