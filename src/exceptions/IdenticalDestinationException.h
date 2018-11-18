#ifndef IDENTICALDESTINATIONEXCEPTION_H_
#define IDENTICALDESTINATIONEXCEPTION_H_

#include <exception>

/**
 * @brief Exception reporting when a trip has destination identical to source
 * 
 */
class IdenticalDestinationException: public std::exception {
public:
	const char* what();
};

#endif /* IDENTICALDESTINATIONEXCEPTION_H_ */
