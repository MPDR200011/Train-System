#include "IdenticalDestinationException.h"

const char* IdenticalDestinationException::what() {
	return "Trip has identical source and destination.";
}
