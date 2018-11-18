#include "NoSuchTrainException.h"
#include <sstream>

using namespace std;

NoSuchTrainException::NoSuchTrainException(id_t id) {
	this->id = id;
}

const char* NoSuchTrainException::what() {
	stringstream ss;
	ss << "Non existant train id: " << id;
	return ss.str().c_str();
}

