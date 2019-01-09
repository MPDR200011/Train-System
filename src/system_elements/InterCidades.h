#ifndef TRAIN_SYSTEM_INTERCIDADES_H
#define TRAIN_SYSTEM_INTERCIDADES_H

#include "Train.h"

/**
 * Class representing an Inter Cidades train.
 * Its a derivation of the Train class.
 */
class InterCidades : public Train {
public:
    /**
     * Construct a new InterCidades object.
     */
    InterCidades(uint maxSeats);

    /**
     * Get the type
     * @returns "IC"
     */
    const char *getType() const override;

    /**
     * Get the price multiplyer.
     *
     * @returns 1.1
     */
    float getPriceMultiplyer() const override;

    /**
     * Prints the information of the train in a formatted row.
     *
     * @param os
     */
    void printRow(std::ostream &os) override;

};


#endif //TRAIN_SYSTEM_INTERCIDADES_H
