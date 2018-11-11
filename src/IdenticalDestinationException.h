#ifndef IDENTICALDESTINATIONEXCEPTION_H_
#define IDENTICALDESTINATIONEXCEPTION_H_

#include "TrainSystemException.h"

/**
 * @brief Exception reporting when a trip has destination identical to source
 * 
 */
class IdenticalDestinationException: public TrainSystemException {
public:
	std::string what();
};

#endif /* IDENTICALDESTINATIONEXCEPTION_H_ */
