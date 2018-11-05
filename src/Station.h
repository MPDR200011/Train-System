#ifndef STATION_H_
#define STATION_H_

#include "project_types.h"
#include <string>
#include <iostream>

class Station {
	static id_t currentID;
public:
	Station(std::string name);

	id_t getID() const;
	std::string getName() const;

	friend std::ostream &operator <<(std::ostream &os, Station &st);

private:
	id_t stationID;
	std::string name;
};

#endif /* STATION_H_ */
