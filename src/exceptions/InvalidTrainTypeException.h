#ifndef TRAIN_SYSTEM_INVALIDTRAINTYPEEXCEPTION_H
#define TRAIN_SYSTEM_INVALIDTRAINTYPEEXCEPTION_H

#include <string>
#include <exception>

class InvalidTrainTypeException : public std::exception {
public:
    InvalidTrainTypeException(std::string type);

    const char *what() const noexcept override;

private:
    std::string type;
};


#endif //TRAIN_SYSTEM_INVALIDTRAINTYPEEXCEPTION_H
