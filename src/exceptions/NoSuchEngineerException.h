#ifndef TRAIN_SYSTEM_NOSUCHENGINEEREXCEPTION_H
#define TRAIN_SYSTEM_NOSUCHENGINEEREXCEPTION_H


#include <bits/exception.h>
#include "../project_utils.h"

class NoSuchEngineerException : public std::exception {
public:
    NoSuchEngineerException(id_t id);
    const char* what();

private:
    id_t ID;
};


#endif //TRAIN_SYSTEM_NOSUCHENGINEEREXCEPTION_H
