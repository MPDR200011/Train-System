#include "NoSuchTrainException.h"
#include <sstream>

using namespace std;

NoSuchTrainException::NoSuchTrainException(id_t id) {
	this->id = id;
}

string NoSuchTrainException::what() {
	stringstream ss;
	ss << "Non existant train id: " << id;
	return ss.str();
}

