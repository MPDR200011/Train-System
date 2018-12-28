#include <iomanip>
#include "InterCidades.h"

InterCidades::InterCidades(uint maxSeats) : Train(maxSeats) {}

float InterCidades::getPriceMultiplyer() const {
    return 1.1F;
}

void InterCidades::printRow(std::ostream &os) {
    os << setw(5) << trainID
       << setw(12) << maxSeats
       << setw(8) << "IC";
}

const char *InterCidades::getType() const {
    return "IC";
}
