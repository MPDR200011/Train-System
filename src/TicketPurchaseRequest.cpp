#include "TicketPurchaseRequest.h"

using namespace std;

TicketPurchaseRequest::TicketPurchaseRequest(Passenger* p, Trip* t) : 
	invoice(p,t) {
	this->passenger = p;
	this->trip = trip;
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