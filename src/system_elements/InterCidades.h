#ifndef TRAIN_SYSTEM_INTERCIDADES_H
#define TRAIN_SYSTEM_INTERCIDADES_H

#include "Train.h"

class InterCidades : public Train {
public:
    InterCidades(uint maxSeats);

    const char *getType() const override;

    float getPriceMultiplyer() const override;

    void printRow(std::ostream &os) override;

};


#endif //TRAIN_SYSTEM_INTERCIDADES_H
