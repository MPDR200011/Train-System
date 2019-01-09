#ifndef STATION_H_
#define STATION_H_

#include <iostream>
#include <string>
#include "../project_utils.h"
#include "SystemElement.h"

/**
 * @brief Class for representing a station in the system
 *
 */
class Station : public SystemElement {
 public:
  /**
   * @brief Construct a new Station object
   *
   * @param name Name of the station.
   * @param x
   * @param y
   */
  explicit Station(std::string name, int x, int y);

  /**
   * Set the station ID
   *
   * @param stationID
   */
  void setID(id_t stationID);

  /**
   * @brief Get the station ID
   *
   * @return id_t
   */
  id_t getID() const;

  /**
   * Get the x coordinate.
   * @return
   */
  int getX() const;
  /**
   * Get the y coordinate.
   * @return
   */
  int getY() const;

  /**
   * @brief Get the Station's name
   *
   * @return std::string Station's name
   */
  std::string getName() const;

  /**
   *@brief Get the Station's number of passengers
   *
   *Get the number of passengers that have the station as Destination
   *
   *@return int
   */
  int getPassengerNumber() const;

  /**
   * @brief Output station information in a row fashion
   *
   * Outputs the object's information as it was a row in a table.
   * Useful for outputing all Station objects in the system.
   *
   * @param os The output stream to which the station will be output.
   */
  void printRow(std::ostream& os) const;
  /**
   * @brief Output Station object in a user friendly fashion
   *
   * @param os Output stream to wich Station object will be output
   * @param st Station object to be output
   * @return std::ostream&
   */
  friend std::ostream& operator<<(std::ostream& os, Station& st);

  bool operator<(const Station& st) const;

  bool operator==(const Station& st) const;

  /**
   * @brief Increments Station's number of passengers
   *
   */
  void addPassenger();

  /**
   * @brief Decrements Station's number of passengers
   *
   */
  void removePassenger();

 private:
  /**
   * @brief ID of the station
   *
   */
  id_t stationID;
  /**
   * @brief Name of the station
   *
   */
  std::string name;

  /**
   * The stations x coordinate.
   */
  int xCoord;
  /**
   * The stations y coordinate.
   */
  int yCoord;
  /**
   * @brief Number of passengers that have the station as destination
   */
  int passengerNumber;
};

#endif /* STATION_H_ */
