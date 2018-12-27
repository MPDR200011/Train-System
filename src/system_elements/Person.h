#ifndef TRAIN_SYSTEM_PERSON_H
#define TRAIN_SYSTEM_PERSON_H

#include <string>
#include "SystemElement.h"
#include "../Date.h"

class Person : public SystemElement {
public:
    Person(std::string name, Date birthDate);
	/**
	 * @brief Get the Name object
	 *
	 * @return std::string The Passenger's name
	 */
	std::string getName() const;
	/**
	 * @brief Get the Birth Date object
	 *
	 * @return const Date& The Date object representing the Passenger's date of birth
	 */
	Date & getBirthDate();

protected:
    /**
	 * @brief Person's name
	 *
	 */
	std::string name;
	/**
	 * @brief Date object representing Passenger's date of birth
	 *
	 */
	Date birthDate;
};


#endif //TRAIN_SYSTEM_PERSON_H
