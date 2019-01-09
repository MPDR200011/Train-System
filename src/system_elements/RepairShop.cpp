#include "RepairShop.h"
#include <iomanip>

int RepairShop::getDaysToAvailability() const {
    return daysToAvailability;
}

int RepairShop::getXCoord() const {
    return xCoord;
}

int RepairShop::getYCoord() const {
    return yCoord;
}

RepairShop::RepairShop(std::string &name, int x, int y) : name(name) {
    this->xCoord = x;
    this->yCoord = y;
    this->daysToAvailability = 0;
    this->currentTrain = nullptr;
}

void RepairShop::setID(id_t id) {
    this->shopID = id;
}

id_t RepairShop::getID() const {
    return shopID;
}

void RepairShop::addTrain(Train *tr) {
    tr->setUnhealthy();
    if (currentTrain == nullptr) {
        currentTrain = tr;
        daysToAvailability = 3;
        return;
    } else {
        trainsToRepair.push(tr);
    }
}

void RepairShop::advanceDay() {
    if (daysToAvailability <= 0) {
        return;
    }
    daysToAvailability--;
    if (daysToAvailability == 0) {
        if (!trainsToRepair.empty()) {
            currentTrain->setHealthy();
            cout << "Train with ID " << currentTrain->getID() << " has returned from shop " << name << "." << endl;
            currentTrain = trainsToRepair.front();
            trainsToRepair.pop();
            daysToAvailability = 3;
        } else {
            if (currentTrain != nullptr) {
                currentTrain->setHealthy();
            }
            currentTrain = nullptr;
        }
    }
}

void RepairShop::save(ofstream &os) {
    os << shopID << " " << isActive() << " \"" << name << "\" "
       << xCoord << " " << yCoord << " " << daysToAvailability;
    if (currentTrain != nullptr) {
        os << " " << currentTrain->getID();
    }
    while (!trainsToRepair.empty()) {
        os << " " << trainsToRepair.front()->getID();
        trainsToRepair.pop();
    }
}

void RepairShop::setDaysToAvailability(int daysToAvailability) {
    RepairShop::daysToAvailability = daysToAvailability;
}

const string &RepairShop::getName() const {
    return name;
}

void RepairShop::printRow(std::ostream &os) {
    os << setw(14) << shopID << setw(30) << name
       << setw(8) << xCoord << setw(8) << yCoord << setw(15) << trainsToRepair.size()*3+daysToAvailability;
}
