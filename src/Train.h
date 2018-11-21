#ifndef TRAIN_H_
#define TRAIN_H_

#include "project_types.h"
#include <iostream>

/**
 * @brief Class for representing a train in the system
 * 
 */
class Train {
	/**
	 * @brief Next ID counter
	 * 
	 * Used to set new ID when Train object is constructed, incremented every time a 
	 * new Train object is constructed.
	 * 
	 */
	static id_t currentID;
public:
	/**
	 * @brief Construct a new Train object
	 * 
	 * @param totalSeats Max capacity of train
	 */
	Train(uint totalSeats);

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
	 * @brief Output train information in a row fashion
	 * 
	 * Outputs the object's information as it was a row in a table.
	 * Useful for outputing all train objects in the system.
	 * 
	 * @param os The output stream to which the train will be output.
	 *
	 */
	void printRow(std::ostream &os);
	friend std::ostream & operator<<(std::ostream &os, Train &tr);

private:
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
