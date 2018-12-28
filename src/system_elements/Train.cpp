#include "Train.h"
#include <iomanip>

using namespace std;

Train::Train(uint totalSeats) {
	this->maxSeats = totalSeats;
}

void Train::setID(id_t id) {
	this->trainID = id;
}

id_t Train::getID() const {
	return trainID;
}

uint Train::getMaxSeats() {
	return maxSeats;
}

void Train::printRow(ostream &os){
}

ostream &operator<<(ostream &os, Train &tr) {
	os << "//// Train ////" << endl;
	os << "ID: " << tr.trainID << endl;
	os << "Max Seats: " << tr.maxSeats << endl;
	return os;
}