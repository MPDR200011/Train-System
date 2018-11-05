#ifndef STATION_H_
#define STATION_H_

#include "project_types.h"
#include <string>

class Station {
	static id_t currentID;
public:
	Station(std::string name);
private:
	id_t stationID;
	std::string name;
};

#endif /* STATION_H_ */
