#include "PassengerCard.h"

using namespace std;

id_t PassengerCard::currentID = 0;

PassengerCard::PassengerCard(PassengerCard::CardType type, string pName) : passengerName(pName) {
	this->cardID = currentID++;
	this->cardType = type;
}

int PassengerCard::getDiscount() const {
	return cardType;
}
