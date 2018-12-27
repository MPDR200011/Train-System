#ifndef TRAIN_SYSTEM_ENGINEER_H
#define TRAIN_SYSTEM_ENGINEER_H

#include <set>
#include "Person.h"
#ifdef TRIP_H_ //If this condition checks out then it means that the header is being included
class Trip;
#endif
#include "Trip.h"


class Engineer : public Person{
public:
    struct EngineerHashUtils {
    public:
        int operator() (Engineer* e) const {
            return e->getID();
        }

        bool operator() (const Engineer* e1, const Engineer* e2) const {
            return e1->getID() == e2->getID();
        }
    };
public:
    Engineer(std::string name, Date birthDate);

    id_t getID() const;
    void setID(id_t id);

    void addTrip(Trip* trip);
    std::set<Trip*> getTrips();

    void printRow(std::ostream &os);

private:
    id_t engineerID;
    std::set<Trip*> trips;
};


#endif //TRAIN_SYSTEM_ENGINEER_H
