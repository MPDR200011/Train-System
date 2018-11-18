#include "PassengerCard.h"

using namespace std;

id_t PassengerCard::currentID = 0;

PassengerCard::PassengerCard(PassengerCard::CardType type, id_t passengerID, string pName) : passengerName(pName) {
	this->cardID = currentID++;
	this->passengerID = passengerID;
	this->cardType = type;
}

int PassengerCard::getDiscount() const {
	switch (cardType) {
		case twentyFive:
			return 25;
			break;
		case fifty:
			return 50;
			break;
		case hundred:
			return 100;
			break;
		default:
			return 0;
			break;
	}
}

PassengerCard::CardType PassengerCard::getType() {
	return cardType;
}

uint PassengerCard::getCost() {
	switch (cardType) {
		case twentyFive:
			return 3900;
			break;
		case fifty:
			return 5000;
			break;
		case hundred:
			return 14900;
			break;
		default:
			return 0;
			break;
	}
}

void PassengerCard::setType(CardType type) {
	cardType = type;
}