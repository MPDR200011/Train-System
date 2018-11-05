#include "Station.h"

using namespace std;

id_t Station::currentID = 0;

Station::Station(string name) : name(name){
	this->stationID = currentID++;
}
