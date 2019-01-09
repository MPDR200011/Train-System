#ifndef TRAIN_H_
#define TRAIN_H_

#include "SystemElement.h"
#include "../project_utils.h"
#include <iostream>

/**
 * @brief Class for representing a train in the system
 * 
 */
class Train : public SystemElement{

public:
	/**
	 * @brief Construct a new Train object
	 * 
	 * @param totalSeats Max capacity of train
	 */
	explicit Train(uint totalSeats);

	/**
	 * Set the train ID
	 *
	 * @param id
	 */
	void setID (id_t id);

	/**
	 * @brief Get the train ID
	 * 
	 * @return id_t 
	 */
	id_t getID() const;
	/**
	 * @brief Get the max capacity
	 * 
	 * @return uint 
	 */
	uint getMaxSeats();

	/**
	 * Marks the train as unhealthy, needing repairs.
	 */
	void setHealthy();
	/**
	 * Marks the train as healthy after being repaired.
	 */
	void setUnhealthy();

	/**
	 *
	 * Tells if the train is in good condition.
	 *
	 * @return healthy private attribute.
	 */
	bool isHealthy() const;

	/**
	 * The function to get the trains price multiplyer.
	 * To be overriden.
	 *
	 * @return
	 */
	virtual float getPriceMultiplyer() const = 0;
	/**
	 * The function to get the type of the train.
	 * To be overriden.
	 *
	 * @return
	 */
	virtual const char* getType() const = 0;

	/**
	 * Function to print information of train in a formated row.
	 *
	 * @param os
	 */
	virtual void printRow(std::ostream &os);

	/**
	 * Print train information in a user friendly way.
	 *
	 * @param os
	 * @param tr
	 * @return
	 */
	friend ostream &operator<<(ostream &os, Train &tr);

protected:
	/**
	 * Is true if the train is in good condition.
	 * False if it needs repairing.
	 */
	bool healthy;

	/**
	 * Id of the train.
	 */
	id_t trainID;

	/**
	 * Max capacity of the train.
	 */
	uint maxSeats;
};


#endif /* TRAIN_H_ */
