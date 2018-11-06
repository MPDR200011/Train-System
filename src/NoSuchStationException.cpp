#include "NoSuchStationException.h"
#include <sstream>

using namespace std;

NoSuchStationException::NoSuchStationException(id_t id) {
	this->id = id;
}

string NoSuchStationException::what() {
	stringstream ss;
	ss << "Non existant station id: " << id;
	return ss.str();
}

