#include "PassengerCard.h"

using namespace std;

id_t PassengerCard::currentID = 0;

PassengerCard::PassengerCard(PassengerCard::CardType type, id_t passengerID, string pName) : passengerName(pName) {
	this->cardID = currentID++;
	this->passengerID = passengerID;
	this->cardType = type;
}

int PassengerCard::getDiscount() const {
	return cardType;
}
