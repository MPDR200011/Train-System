#ifndef INVALIDDATEEXCEPTION_H_
#define INVALIDDATEEXCEPTION_H_

#include <string>
#include "TrainSystemException.h"

class InvalidDateException: public TrainSystemException {
public:
	InvalidDateException(std::string dateString);
	std::string what();

public:
	std::string dateString;
};

#endif /* INVALIDDATEEXCEPTION_H_ */
