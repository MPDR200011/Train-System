#ifndef REVERSEDATESEXCEPTION_H_
#define REVERSEDATESEXCEPTION_H_

#include "TrainSystemException.h"

class ReverseDatesException: public TrainSystemException {
public:
	ReverseDatesException(const std::string date1, const std::string date2);
	std::string what();

private:
	std::string date1, date2;
};

#endif /* REVERSEDATESEXCEPTION_H_ */
