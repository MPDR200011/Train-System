#ifndef NOSUCHSTATIONEXCEPTION_H_
#define NOSUCHSTATIONEXCEPTION_H_

#include <exception>
#include "../project_utils.h"

/**
 * @brief Exception reporting that a station ID does not exist in the system.
 * 
 */
class NoSuchStationException: public std::exception {
public:
	NoSuchStationException(id_t id);
	const char* what();
private:
	id_t id;
};

#endif /* NOSUCHSTATIONEXCEPTION_H_ */
