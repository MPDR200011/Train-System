#include "IdenticalDestinationException.h"

std::string IdenticalDestinationException::what() {
	return "Trip has identical source and destination.";
}
