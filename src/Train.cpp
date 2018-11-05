#include "Train.h"

id_t Train::currentID = 0;

Train::Train(uint totalSeats) {
	this->trainID = currentID++;
	this->maxSeats = totalSeats;
}

id_t Train::getTrainID() {
	return trainID;
}

uint Train::getMaxSeats() {
	return maxSeats;
}
