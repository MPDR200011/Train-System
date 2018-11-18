#include "NoSuchStationException.h"
#include <sstream>

using namespace std;

NoSuchStationException::NoSuchStationException(id_t id) {
	this->id = id;
}

const char* NoSuchStationException::what() {
	stringstream ss;
	ss << "Non existant station id: " << id;
	return ss.str().c_str();
}

