#include "Person.h"

Person::Person(std::string name, Date birthDate) : name(name), birthDate(birthDate.getDateString()){}

std::string Person::getName() const {
    return name;
}

Date& Person::getBirthDate() {
    return birthDate;
}

