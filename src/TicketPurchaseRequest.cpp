#include "TicketPurchaseRequest.h"

using namespace std;

TicketPurchaseRequest::TicketPurchaseRequest(Passenger* passenger, Trip* t) : 
	invoice(passenger,t) {
	this->passenger = passenger;
	this->trip = t;
}

TicketPurchaseRequest::~TicketPurchaseRequest() {
	this->passenger = nullptr;
	this->trip = nullptr;
}

const Passenger* TicketPurchaseRequest::getPassenger() const {
	return passenger;
}

const Trip* TicketPurchaseRequest::getTrip() const {
	return trip;
}

void TicketPurchaseRequest::setPrice(uint price) {
	invoice.setPrice(price);
}

void TicketPurchaseRequest::printInvoice(ostream &os) {
	os << invoice;
}