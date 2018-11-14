#ifndef INVALIDDATEEXCEPTION_H_
#define INVALIDDATEEXCEPTION_H_

#include <string>
#include "TrainSystemException.h"

/**
 * @brief Exception reporting an invalid date.
 * 
 * Reports that a Date does not follow gregorian calendar standards
 * 
 */
class InvalidDateException: public TrainSystemException {
public:
	/**
	 * @brief Construct a new Invalid Date Exception object
	 * 
	 * @param dateString String of the Date in question
	 */
	InvalidDateException(std::string dateString);
	std::string what();

public:
	/**
	 * @brief String representing invalid Date
	 * 
	 */
	std::string dateString;
};

#endif /* INVALIDDATEEXCEPTION_H_ */
