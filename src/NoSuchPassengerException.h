#ifndef NOSUCHPASSENGEREXCEPTION_H_
#define NOSUCHPASSENGEREXCEPTION_H_

#include "TrainSystemException.h"
#include "project_types.h"

class NoSuchPassengerException: public TrainSystemException {
public:
	NoSuchPassengerException(id_t id);
	std::string what();
private:
	id_t id;
};

#endif /* NOSUCHPASSENGEREXCEPTION_H_ */
