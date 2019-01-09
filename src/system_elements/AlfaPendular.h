#ifndef TRAIN_SYSTEM_ALFAPENDULAR_H
#define TRAIN_SYSTEM_ALFAPENDULAR_H

#include "Train.h"

/**
 * Class representing an ALfa Pendular train.
 * Its a derivation of the Train class.
 */
class AlfaPendular : public Train {
public:
    /**
     *
     * @returns "AP"
     */
    const char *getType() const override;

    /**
     * Construct a new AlfaPendular object
     *
     * @param maxSeats
     */
    AlfaPendular(uint maxSeats);

    /**
     *
     * @return 2
     */
    float getPriceMultiplyer() const override;

    /**
     * Print a formated row of the trains information.
     *
     */
    void printRow(std::ostream &os) override;
};


#endif //TRAIN_SYSTEM_ALFAPENDULAR_H
