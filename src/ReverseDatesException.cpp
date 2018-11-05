#include "ReverseDatesException.h"
#include <sstream>

ReverseDatesException::ReverseDatesException(const std::string date1,
		const std::string date2) : date1(date1), date2(date2){
}

std::string ReverseDatesException::what() {
	std::stringstream ss("Dates not in right order: ");
	ss << date1 << ", " << date2;
	return ss.str();
}
