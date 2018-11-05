#ifndef TRAIN_H_
#define TRAIN_H_

#include "project_types.h"

class Train {
	static id_t currentID;
public:
	Train(uint totalSeats);

	id_t getTrainID();
	uint getMaxSeats();

private:
	id_t trainID;
	uint maxSeats;
};

#endif /* TRAIN_H_ */
