#ifndef TRIPPASTEXCEPTION_H_
#define TRIPPASTEXCEPTION_H_

#include "TrainSystemException.h"

class TripPastException: public TrainSystemException{
public:
    std::string what();
};

#endif