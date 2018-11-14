#ifndef NOSUCHSTATIONEXCEPTION_H_
#define NOSUCHSTATIONEXCEPTION_H_

#include "TrainSystemException.h"
#include "project_types.h"

/**
 * @brief Exception reporting that a station ID does not exist in the system
 * 
 */
class NoSuchStationException: public TrainSystemException {
public:
	NoSuchStationException(id_t id);
	std::string what();
private:
	id_t id;
};

#endif /* NOSUCHSTATIONEXCEPTION_H_ */
