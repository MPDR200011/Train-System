#include <sstream>
#include "InvalidTrainTypeException.h"

using namespace std;

const char *InvalidTrainTypeException::what() const noexcept {
    stringstream ss;
    ss << "Invalid train type: " << type;
    return ss.str().c_str();
}

InvalidTrainTypeException::InvalidTrainTypeException(string type) : type(type) {
}
