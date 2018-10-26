#include "InvalidDateException.h"
#include <sstream>

using namespace std;

InvalidDateException::InvalidDateException(string dateString) :
		dateString(dateString) {
}

std::string InvalidDateException::what() {
	stringstream ss;
	ss << "Invalid date: " << dateString;
	return ss.str();
}
