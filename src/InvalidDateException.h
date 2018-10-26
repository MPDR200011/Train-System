#include <string>

#ifndef INVALIDDATEEXCEPTION_H_
#define INVALIDDATEEXCEPTION_H_

class InvalidDateException {
public:
	InvalidDateException(std::string dateString);
	std::string what();

public:
	std::string dateString;
};

#endif /* INVALIDDATEEXCEPTION_H_ */
