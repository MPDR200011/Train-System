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

	virtual float getPriceMultiplyer() const = 0;
	virtual const char* getType() const = 0;

	/**
	 * @brief Output train information in a row fashion
	 * 
	 * Outputs the object's information as it was a row in a table.
	 * Useful for outputing all train objects in the system.
	 * 
	 * @param os The output stream to which the train will be output.
	 *
	 */
	virtual void printRow(std::ostream &os) = 0;
	friend std::ostream & operator<<(std::ostream &os, Train &tr);

protected:
	/**
	 * @brief Id of the train
	 * 
	 */
	id_t trainID;
	/**
	 * @brief Max capacity of the train
	 * 
	 */
	uint maxSeats;
};

#endif /* TRAIN_H_ */
