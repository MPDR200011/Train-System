#include "Train.h"
#include <iomanip>

using namespace std;

id_t Train::currentID = 0;

Train::Train(uint totalSeats) {
	this->trainID = currentID++;
	this->maxSeats = totalSeats;
}

id_t Train::getID() const {
	return trainID;
}

uint Train::getMaxSeats() {
	return maxSeats;
}

void Train::printRow(ostream &os){
	os << setw(5) << trainID 
	<< setw(12) << maxSeats;
}

ostream &operator<<(ostream &os, Train &tr) {
	os << "//// Train ////" << endl;
	os << "ID: " << tr.trainID << endl;
	os << "Max Seats: " << tr.maxSeats << endl;
	return os;
}