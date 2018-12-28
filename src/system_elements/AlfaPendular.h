#ifndef TRAIN_SYSTEM_ALFAPENDULAR_H
#define TRAIN_SYSTEM_ALFAPENDULAR_H

#include "Train.h"

class AlfaPendular : public Train {
public:
    const char *getType() const override;

    AlfaPendular(uint maxSeats);

    float getPriceMultiplyer() const override;

    void printRow(std::ostream &os) override;
};


#endif //TRAIN_SYSTEM_ALFAPENDULAR_H
