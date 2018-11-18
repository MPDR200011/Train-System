#ifndef NOSUCHTRAINEXCEPTION_H_
#define NOSUCHTRAINEXCEPTION_H_

#include <exception>
#include "../project_types.h"

/**
 * @brief Exception reporting that a train ID does not exist in the system
 * 
 */
class NoSuchTrainException: public std::exception {
public:
	NoSuchTrainException(id_t id);
	const char* what();
private:
	id_t id;
};

#endif /* NOSUCHTRAINEXCEPTION_H_ */
