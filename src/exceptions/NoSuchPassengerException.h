#ifndef NOSUCHPASSENGEREXCEPTION_H_
#define NOSUCHPASSENGEREXCEPTION_H_

#include "../project_types.h"
#include <exception>

/**
 * @brief Exception reporting that a passenger ID does not exist in the system
 * 
 */
class NoSuchPassengerException: public std::exception {
public:
	NoSuchPassengerException(id_t id);
	const char* what();
private:
	id_t id;
};

#endif /* NOSUCHPASSENGEREXCEPTION_H_ */
