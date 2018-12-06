#ifndef TICKETPURCHASEREQUEST_H_
#define TICKETPURCHASEREQUEST_H_

#include "system_elements/Passenger.h"
#include "TicketInvoice.h"
#include "system_elements/Trip.h"
#include <iostream>

/**
 * @brief Class to represent a ticket purchase request
 * 
 * Objects of this class are passed to the system to be processed and validated.
 * Contains a TicketInvoice object with price set to 0, it is later set by the system 
 * when the request is processed.
 * 
 */
class TicketPurchaseRequest {
	friend class System;
public:
	/**
	 * @brief Construct a new Ticket Purchase Request object
	 * 
	 * @param passenger Pointer to passenger object that purchased the ticket
	 * @param t Pointer to trip object which ticket has be bought
	 */
	TicketPurchaseRequest(Passenger* passenger, Trip* t);
	/**
	 * @brief Destroy the Ticket Purchase Request object
	 * 
	 */
	~TicketPurchaseRequest();

	/**
	 * @brief Get the Passenger object
	 * 
	 * @return const Passenger* 
	 */
	const Passenger* getPassenger() const;
	/**
	 * @brief Get the Trip object
	 * 
	 * @return const Trip* 
	 */
	const Trip* getTrip() const;
	/**
	 * @brief Get the Invoice object
	 * 
	 * 
	 * 
	 * @return const TicketInvoice 
	 */
	const TicketInvoice getInvoice() const;

	/**
	 * @brief Set the price of the invoiceof the purchase
	 * 
	 * @param price 
	 */
	void setInvoicePrice(uint price);

	/**
	 * @brief Prints the invoice the a specified output buffer
	 * 
	 * @param os Output buffer
	 */
	void printInvoice(std::ostream &os);

private:
	/**
	 * @brief Object of the purchase's invoice
	 * 
	 */
	TicketInvoice invoice;
	/**
	 * @brief Pointer to the passenger that bought the ticket
	 * 
	 */
	Passenger* passenger;
	/**
	 * @brief Pointer to the trip which ticket has been bought
	 * 
	 */
	Trip* trip;
};

#endif /* TICKETPURCHASEREQUEST_H_ */
