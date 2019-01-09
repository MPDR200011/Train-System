#ifndef TRAIN_SYSTEM_ENGINEER_H
#define TRAIN_SYSTEM_ENGINEER_H

#include <set>
#include "Person.h"
#ifdef TRIP_H_ //If this condition checks out then it means that the header is being included
class Trip;
#endif
#include "Trip.h"

/**
 * Class representing an engineer(train driver).
 * Extends class Person.
 */
class Engineer : public Person{
public:
    /**
     * Struct with function operator overrides to be provided to Engineer hash map.
     */
    struct EngineerHashUtils {
    public:
        /**
         * Engineer hash function.
         *
         * @param e
         * @return Index
         */
        int operator() (Engineer* e) const {
            return e->getID();
        }

        /**
         * Engineer equivalence function.
         *
         * @param e1
         * @param e2
         * @return
         */
        bool operator() (const Engineer* e1, const Engineer* e2) const {
            return e1->getID() == e2->getID();
        }
    };
public:
    /**
     * Construct a new Engineer object.
     *
     * @param name
     * @param birthDate
     */
    Engineer(std::string name, Date birthDate);

    /**
     * Get the engineer ID.
     *
     * @return
     */
    id_t getID() const;
    /**
     * Set the engineer ID.
     *
     * @param id
     */
    void setID(id_t id);

    /**
     * Add a trip to the engineer's trip history.
     *
     * @param trip
     */
    void addTrip(Trip* trip);
    /**
     * Get the vector of trips made by the engineer.
     *
     * @return
     */
    std::set<Trip*> getTrips();

    /**
     * Print the engineer information in a formatted row.
     *
     * @param os
     */
    void printRow(std::ostream &os);

private:
    /**
     * Engineer's ID.
     */
    id_t engineerID;
    /**
     * Trips made by the engineer.
     */
    std::set<Trip*> trips;
};


#endif //TRAIN_SYSTEM_ENGINEER_H
