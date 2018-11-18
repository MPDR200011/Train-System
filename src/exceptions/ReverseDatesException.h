#ifndef REVERSEDATESEXCEPTION_H_
#define REVERSEDATESEXCEPTION_H_

#include <exception>
#include <string>

/**
 * @brief Exception reporting a trip's arrival date happens before departure date
 * 
 */
class ReverseDatesException: public std::exception {
public:
	ReverseDatesException(const std::string date1, const std::string date2);
	const char* what();

private:
	std::string date1, date2;
};

#endif /* REVERSEDATESEXCEPTION_H_ */
