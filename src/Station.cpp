#include "Station.h"

using namespace std;

id_t Station::currentID = 0;

Station::Station(string name) : name(name){
	this->stationID = currentID++;
}

id_t Station::getID() const {
	return stationID;
}

string Station::getName() const {
	return name;
}

ostream &operator<<(ostream &os, Station &st) {
	os << "//// Station ////" << endl;
	os << "ID: " << st.stationID << endl;
	os << "Name: " << st.name;

	return os;
}
