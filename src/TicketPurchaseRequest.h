#ifndef TICKETPURCHASEREQUEST_H_
#define TICKETPURCHASEREQUEST_H_

#include "Passenger.h"
#include "TicketInvoice.h"
#include "Trip.h"
#include <iostream>

class TicketPurchaseRequest {
	friend class System;
public:
	TicketPurchaseRequest(Passenger* passenger, Trip* t);
	~TicketPurchaseRequest();

	const Passenger* getPassenger() const;
	const Trip* getTrip() const;
	const TicketInvoice getInvoice() const;

	void setInvoicePrice(uint price);
	void printInvoice(std::ostream &os);

private:
	TicketInvoice invoice;
	Passenger* passenger;
	Trip* trip;
};

#endif /* TICKETPURCHASEREQUEST_H_ */
