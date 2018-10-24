/*
 * System.cpp
 *
 *  Created on: Oct 24, 2018
 *      Author: mpdr
 */

#include "System.h"


const std::vector<Passenger*>& System::getPassengers() const {
	return passengers;
}

const std::vector<Station*>& System::getStations() const {
	return stations;
}

const std::vector<Train*>& System::getTrains() const {
	return trains;
}

const std::vector<Trip*>& System::getTrips() const {
	return trips;
}

