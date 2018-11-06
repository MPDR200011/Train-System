#include "NoSuchPassengerException.h"
#include <sstream>

using namespace std;

NoSuchPassengerException::NoSuchPassengerException(id_t id) {
	this->id = id;
}

string NoSuchPassengerException::what() {
	stringstream ss;
	ss << "Non existant passenger id: " << id;
	return ss.str();
}

