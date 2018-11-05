#include "Train.h"

using namespace std;

id_t Train::currentID = 0;

Train::Train(uint totalSeats) {
	this->trainID = currentID++;
	this->maxSeats = totalSeats;
}

id_t Train::getID() {
	return trainID;
}

uint Train::getMaxSeats() {
	return maxSeats;
}

ostream &operator<<(ostream &os, Train &tr) {
	os << "//// Train ////" << endl;
	os << "ID: " << tr.trainID << endl;
	os << "Max Seats: " << tr.maxSeats;
	return os;
}