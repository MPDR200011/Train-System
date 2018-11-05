#include "Passenger.h"

using namespace std;

id_t Passenger::currentID = 0;

Passenger::Passenger(string name, string birthDate): name(name), birthDate(birthDate) {
	this->passengerID = currentID++;
	this->card = nullptr;
}

Passenger::~Passenger() {
	delete card;
}

