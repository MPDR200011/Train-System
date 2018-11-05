#ifndef TRAINSYSTEMEXCEPTION_H_
#define TRAINSYSTEMEXCEPTION_H_

#include <string>

class TrainSystemException {
public:
	virtual ~TrainSystemException() = default;
	virtual std::string what() = 0;
};

#endif /* TRAINSYSTEMEXCEPTION_H_ */
