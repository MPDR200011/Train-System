#include "SystemElement.h"

SystemElement::SystemElement() {
    this->active = true;
}

void SystemElement::setActive() {
    this->active = true;
}

void SystemElement::setInactive() {
    this->active = false;
}

bool SystemElement::isActive() const {
    return active;
}
