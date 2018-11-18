#ifndef TRAIN_H_
#define TRAIN_H_

#include "project_types.h"
#include <iostream>

class Train {
	static id_t currentID;
public:
	Train(uint totalSeats);

	id_t getID() const;
	uint getMaxSeats();

	void printRow(std::ostream &os);
	friend std::ostream & operator<<(std::ostream &os, Train &tr);

private:
	id_t trainID;
	uint maxSeats;
};

#endif /* TRAIN_H_ */
