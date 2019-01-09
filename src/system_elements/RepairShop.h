#ifndef TRAIN_SYSTEM_REPAIRSHOP_H
#define TRAIN_SYSTEM_REPAIRSHOP_H

#include <string>
#include <queue>
#include <set>
#include <fstream>
#include "SystemElement.h"
#include "../project_utils.h"
#include "Train.h"

/**
 * Class representing a repair shop in the system.
 */
class RepairShop : public SystemElement {
public:
    /**
     * Struct with function to be supplied to the Repair shops priority queue.
     */
    struct RepairShopPQUtils {
    public:
        /**
         * Comparison operator.
         *
         * @param rp1 rhs RepairShop
         * @param rp2 lhs RepairShop
         * @return bool
         */
        bool operator()(const RepairShop *rp1, const RepairShop *rp2) const {
            return rp1->trainsToRepair.size() * 3 + rp1->daysToAvailability >
                   rp2->trainsToRepair.size() * 3 + rp2->daysToAvailability;
        }
    };

public:
    /**
     * Construct a new RepairShop object.
     *
     * @param name
     * @param x
     * @param y
     */
    RepairShop(std::string &name, int x, int y);

    /**
     * Set the repair shop ID.
     */
    void setID(id_t id);

    /**
     * Get the repair shop ID.
     * @return
     */
    id_t getID() const;

    /**
     * Get days left to start repairing next train.
     *
     * @return
     */
    int getDaysToAvailability() const;

    /**
     * Get the name of the repair shop.
     *
     * @return
     */
    const string &getName() const;

    /**
     * Get the x coordinate of the repair shop.
     *
     * @return
     */
    int getXCoord() const;

    /**
     * Get the y coordinate of the repair shop.
     *
     * @return
     */
    int getYCoord() const;

    /**
     * Add train to repair queue.
     *
     * @param tr
     */
    void addTrain(Train *tr);

    /**
     * Decrement daysToAvailability.
     * If it becomes 0 after decrementation puts next train in currently being repaired.
     */
    void advanceDay();

    /**
     * Save information into file.
     *
     * @param os
     */
    void save(std::ofstream &os);

    /**
     * Set the daysToAvailability variable.
     *
     * @param daysToAvailability
     */
    void setDaysToAvailability(int daysToAvailability);

    /**
     * Print information in a fromatted line.
     *
     * @param os
     */
    void printRow(std::ostream &os);

private:
    /**
     * The repair shops name.
     */
    std::string name;
    /**
     * The repair shop's ID.
     */
    id_t shopID;
    /**
     * Days till current train is repaired.
     */
    int daysToAvailability;
    /**
     * X coordinate of the shop.
     */
    int xCoord;
    /**
     * Y coordinate of the shop.
     */
    int yCoord;

    /**
     * Pointer to the train that is being repaired.
     */
    Train *currentTrain;
    /**
     * Queue of trains to be repaired.
     */
    std::queue<Train *> trainsToRepair;
};


#endif //TRAIN_SYSTEM_REPAIRSHOP_H
