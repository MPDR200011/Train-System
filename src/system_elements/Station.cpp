#include "Station.h"
#include <iomanip>

using namespace std;


Station::Station(string name) : name(name), passengerNumber(0){
}

id_t Station::getID() const {
	return stationID;
}

string Station::getName() const {
	return name;
}

int Station::getPassengerNumber() const{
	return passengerNumber;
}

void Station::printRow(ostream &os) const {
	os << setw(5) << stationID 
	<< setw(35) << name;
}

ostream &operator<<(ostream &os, Station &st) {
	os << "//// Station ////" << endl;
	os << "ID: " << st.stationID << endl;
	os << "Name: " << st.name << endl;

	return os;
}

void Station::setID(id_t stationID) {
    this->stationID = stationID;
}

void Station::addPassenger(){
	this->passengerNumber++;
}

void Station::removePassenger(){
	this->passengerNumber--;
}

bool Station::operator < (const Station &st) const{
	if(this->passengerNumber < st.passengerNumber)
		return this->getName() < st.getName();
	else return passengerNumber < st.passengerNumber;
}

bool Station::operator == (const Station &st) const{
	return (passengerNumber == st.passengerNumber && name == st.name);
}
