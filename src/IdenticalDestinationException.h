#ifndef IDENTICALDESTINATIONEXCEPTION_H_
#define IDENTICALDESTINATIONEXCEPTION_H_

#include "TrainSystemException.h"

class IdenticalDestinationException: public TrainSystemException {
public:
	std::string what();
};

#endif /* IDENTICALDESTINATIONEXCEPTION_H_ */
