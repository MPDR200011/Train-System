#ifndef PASSENGERCARD_H_
#define PASSENGERCARD_H_

#include "project_types.h"
#include <string>

class PassengerCard {

public:
	enum CardType {twentyFive=25,fifty=50,hundred=100};
	static id_t currentID;

public:
	PassengerCard(CardType type, id_t passengerID, std::string pName);

	int getDiscount() const;

private:
	id_t cardID;
	id_t passengerID;
	CardType cardType;
	std::string passengerName;
};

#endif /* PASSENGERCARD_H_ */
