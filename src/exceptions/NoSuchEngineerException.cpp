#include <sstream>
#include "NoSuchEngineerException.h"

NoSuchEngineerException::NoSuchEngineerException(id_t id) {
    this->ID = id;
}

const char *NoSuchEngineerException::what() {
    stringstream ss;
    ss << "Non existent Engineer ID: " << ID;
    return ss.str().c_str();
}
