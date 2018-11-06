#ifndef NOSUCHTRIPEXCEPTION_H_
#define NOSUCHTRIPEXCEPTION_H_

#include "TrainSystemException.h"
#include "project_types.h"

class NoSuchTripException: public TrainSystemException {
public:
	NoSuchTripException(id_t id);
	std::string what();
private:
	id_t id;
};

#endif /* NOSUCHTRIPEXCEPTION_H_ */
