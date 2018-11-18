#include "TripPastException.h"

using namespace std;

const char* TripPastException::what() {
    return "The trip you are trying to purchase has already happened.";
}
