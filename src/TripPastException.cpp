#include "TripPastException.h"

using namespace std;

string TripPastException::what() {
    return "The trip you are trying to buy has already happened.";
}