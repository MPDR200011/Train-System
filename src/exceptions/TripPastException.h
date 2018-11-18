#ifndef TRIPPASTEXCEPTION_H_
#define TRIPPASTEXCEPTION_H_

#include <exception>

class TripPastException: public std::exception{
public:
    const char* what();
};

#endif
