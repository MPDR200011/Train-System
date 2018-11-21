#ifndef TRIPPASTEXCEPTION_H_
#define TRIPPASTEXCEPTION_H_

#include <exception>

/**
 * @brief An exception reporting that a trip is already in the past
 * 
 */
class TripPastException: public std::exception{
public:
    const char* what();
};

#endif
