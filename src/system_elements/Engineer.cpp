#include "Engineer.h"
#include <iomanip>

Engineer::Engineer(std::string name, Date birthDate) : Person(name, birthDate) {}

void Engineer::addTrip(Trip *trip) {
    trips.insert(trip);
}

std::set<Trip *> Engineer::getTrips() {
    return trips;
}

id_t Engineer::getID() const {
    return engineerID;
}

void Engineer::setID(id_t id) {
    this->engineerID = id;
}

void Engineer::printRow(std::ostream &os) {
os << setw(5) << engineerID
	<< setw(35) << name
	<< setw(15) << birthDate.getDateStringWithoutHours()
	<< setw(15);

}
