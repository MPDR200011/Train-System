#ifndef NOSUCHTRIPEXCEPTION_H_
#define NOSUCHTRIPEXCEPTION_H_

#include <exception>
#include "../project_types.h"

/**
 * @brief Exception reporting that a trip ID does not exist in the system
 * 
 */
class NoSuchTripException: public std::exception {
public:
	NoSuchTripException(id_t id);
	const char* what();
private:
	id_t id;
};

#endif /* NOSUCHTRIPEXCEPTION_H_ */
