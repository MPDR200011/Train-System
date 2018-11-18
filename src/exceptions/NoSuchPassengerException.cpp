#include "NoSuchPassengerException.h"
#include <sstream>

using namespace std;

NoSuchPassengerException::NoSuchPassengerException(id_t id) {
	this->id = id;
}

const char* NoSuchPassengerException::what() {
	stringstream ss;
	ss << "Non existant passenger id: " << id;
	return ss.str().c_str();
}

