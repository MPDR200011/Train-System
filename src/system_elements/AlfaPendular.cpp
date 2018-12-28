#include <iomanip>
#include "AlfaPendular.h"

AlfaPendular::AlfaPendular(uint maxSeats) : Train(maxSeats) {
}

float AlfaPendular::getPriceMultiplyer() const {
    return 2;
}

void AlfaPendular::printRow(std::ostream &os) {
    os << setw(5) << trainID
       << setw(12) << maxSeats
       << setw(8) << "AP";
}

const char *AlfaPendular::getType() const {
    return "AP";
}
