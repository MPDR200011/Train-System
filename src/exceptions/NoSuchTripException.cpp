#include "NoSuchTripException.h"
#include <sstream>

using namespace std;

NoSuchTripException::NoSuchTripException(id_t id) {
	this->id = id;
}

const char* NoSuchTripException::what() {
	stringstream ss;
	ss << "Non existant trip id: " << id;
	return ss.str().c_str();
}
