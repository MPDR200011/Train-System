#ifndef TRAIN_SYSTEM_NOSUCHENGINEEREXCEPTION_H
#define TRAIN_SYSTEM_NOSUCHENGINEEREXCEPTION_H


#include <exception>
#include "../project_utils.h"

class NoSuchEngineerException : public std::exception {
public:
    explicit NoSuchEngineerException(id_t id);
    const char* what();

private:
    id_t ID;
};


#endif //TRAIN_SYSTEM_NOSUCHENGINEEREXCEPTION_H
