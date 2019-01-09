#include "System.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "exceptions/NoSuchPassengerException.h"
#include "exceptions/NoSuchStationException.h"
#include "exceptions/NoSuchTrainException.h"
#include "exceptions/NoSuchTripException.h"
#include "exceptions/TripPastException.h"
#include "exceptions/NoSuchEngineerException.h"
#include "exceptions/InvalidTrainTypeException.h"
#include <iomanip>

// TODO print unhealthy trains

using namespace std;

/**
 * @brief
 *
 * Prints the main menu and choice prompt.
 *
 */
void mainMenu();

/**
 *
 * Called when chooses to create a passenger/card/station/trip/train.
 *
 */
void createTask();

/**
 * Called when user chooses to create a passenger.
 * Starts respective process.
 */
void createPassenger();

/**
 * Called when user chooses to create a card.
 * Starts respective process.
 */
void createCard();

/**
 * Called when user chooses to create a station.
 * Starts respective process.
 */
void createStation();

/**
 * Called when user chooses to create a train.
 * Starts respective process.
 */
void createTrain();

/**
 * Called when user chooses to create a trip.
 * Starts respective process.
 */
void createTrip();

/**
 * Called when user chooses to hire an engineer.
 * Starts respective process.
 */
void createEngineer();

/**
 * Called when user chooses to create a repair shop.
 * Starts respective process.
 */
void createRepairShop();

/**
 * Called when user chooses to delete a passenger/station/train/trip.
 */
void deleteTask();

/**
 * Function to generate a query to System to get trips.
 * Asks for source station, destination station and arrival date constraints, if the user 
 * wants each of them.
 */
void searchTask();

/**
 * Called to make a ticket purchase request.
 */
void purchaseTask();

/**
 * Called to print tables of passengers/stations/trains/trips
 */
void listTask();

/**
 * Called when the user chooses to send a train to a repair shop.
 */
void sendTrainToRepairTask();

/**
 * Called when the user chooses to print the stations leader board.
 */
void printStationsLB();

/**
 * Called when user chooses to advance day.
 */
void advanceDayTask();

/**
 * Called to process a card payment.
 */
void payCard();

/**
 * Called to initiate monthly card processing.
 */
void checkCards();

void mainMenu() {
    string menuOptions[] = {
            "  1 - Create a new passenger/card/station/train/trip/engineer/repair shop.",
            "  2 - Delete a passenger/station/train/trip/engineer/repair shop.",
            "  3 - Search for trips.",
            "  4 - Process a ticket purchase.",
            "  5 - List all passengers/stations/trains/trips/engineers/repair shops.",
            "  6 - Process card payment.",
            "  7 - Print Sales.",
            "  8 - Send train to repair shop.",
            "  9 - Print stations leader board.",
            " 20 - Advance Day (demonstration purposes).",
            " 50 - End of month card processing.",
            "100 - exit"
    };
    cout << endl << "Train System Interface" << endl;
    cout << endl;
    for (const string &s: menuOptions) {
        cout << s << endl;
    }
    cout << endl;
    cout << "Choose what to do - ";
}

void createTask() {
    cout << endl << "Choose what you want to create:" << endl << endl;
    cout << "1 - Passenger" << endl;
    cout << "2 - Passenger Card" << endl;
    cout << "3 - Station" << endl;
    cout << "4 - Train" << endl;
    cout << "5 - Trip" << endl;
    cout << "6 - Engineer(hire)" << endl;
    cout << "7 - Repair Shop" << endl;
    cout << endl;
    cout << "Choice (-1 to return to main menu) - ";

    bool validChoice = false;
    while (!validChoice) {
        int choice;
        if (project_utils::readVar(choice)) {
            return;
        }
        switch (choice) {
            case -1:
                return;
            case 1: {
                validChoice = true;
                createPassenger();
                break;
            }
            case 2: {
                validChoice = true;
                createCard();
                break;
            }
            case 3: {
                validChoice = true;
                createStation();
                break;
            }
            case 4: {
                validChoice = true;
                createTrain();
                break;
            }
            case 5: {
                validChoice = true;
                createTrip();
                break;
            }
            case 6: {
                validChoice = true;
                createEngineer();
                break;
            }
            case 7: {
                validChoice = true;
                createRepairShop();
                break;
            }
            default: {
                validChoice = false;
                cout << "Invalid choice, try again - ";
                break;
            }
        }
    }

}

void createPassenger() {
    string name;
    cout << "Name - ";
    project_utils::readLine(name);

    Date birthDate = project_utils::readBirthDate();

    try {
        System::instance.createPassenger(name, birthDate);
    } catch (...) {
        cout << "A problem has ocurred creating passenger:" << endl;
        return;
    }

    cout << "Successfully created passenger." << endl;
}

void createCard() {

    if (System::instance.getPassengers().empty()) {
        cout << "There are no passengers to get a card." << endl;
        return;
    }

    System::instance.listPassengers(cout);
    cout << endl;

    Passenger *passenger;
    cout << "Enter the id of the passenger who will own the card - ";
    id_t passengerID;
    project_utils::readVar(passengerID);
    try {
        passenger = System::instance.getPassenger(passengerID);
    } catch (NoSuchPassengerException &e) {
        cout << "Passenger id does not exist, returning to main menu.";
        return;
    }

    string type;
    cout << "Card type (twenty five/fifty/hundred) - ";
    bool validType = false;
    while (!validType) {
        project_utils::readLine(type);
        if (type != "twenty five" && type != "fifty" && type != "hundred") {
            cout << "Not a valid type, try again - ";
        } else {
            validType = true;
        }
    }

    try {
        System::instance.createCard(passenger, type);
    } catch (...) {
        cout << "A problem has ocurred creating card:" << endl;
        return;
    }

    cout << "Successfully created card." << endl;

}

void createStation() {

    cout << "Please enter the name of the station - ";
    string name;
    project_utils::readLine(name);

    cout << "Please enter the X coordinate - ";
    int x;
    project_utils::readVar(x);

    cout << "Please enter the Y coordinate - ";
    int y;
    project_utils::readVar(y);

    try {
        System::instance.createStation(name, x, y);
    } catch (...) {
        cout << "A problem has ocurred creating station:" << endl;
        return;
    }

    cout << "Successfully created station." << endl;
}

void createTrain() {

    cout << "Please enter the amount of seats in the train - ";
    uint maxSeats;
    project_utils::readVar(maxSeats);

    cout << "Type of the train (AP/IC) - ";
    string type;
    project_utils::readVar(type);

    try {
        System::instance.createTrain(maxSeats, type);
    } catch (InvalidTrainTypeException &e) {
        cout << e.what() << ", returning to main menu." << endl;
        return;
    }

    cout << "Successfully created train." << endl;

}

void createTrip() {

    cout << "Please enter base price of the trip - ";
    uint basePrice;
    project_utils::readVar(basePrice);

    System::instance.listStations(cout);
    cout << endl;
    cout << "Source station ID - ";
    id_t sourceID;
    project_utils::readVar(sourceID);
    Station *src;
    try {
        src = System::instance.getStation(sourceID);
    } catch (NoSuchStationException &e) {
        cout << "Station ID does not exist, returning to main menu." << endl;
        return;
    }

    cout << "Destination station ID - ";
    id_t destID;
    project_utils::readVar(destID);
    Station *dest;
    try {
        dest = System::instance.getStation(destID);
    } catch (NoSuchStationException &e) {
        cout << "Station ID does not exist, returning to main menu." << endl;
        return;
    }

    System::instance.listHealthyTrains(cout);
    cout << endl;
    cout << "ID of train that will be doing trip - ";
    id_t trainID;
    project_utils::readVar(trainID);
    Train *tr;
    try {
        tr = System::instance.getTrain(trainID);
    } catch (NoSuchTrainException &e) {
        cout << "Train ID does not exist, returning to main menu." << endl;
        return;
    }

    System::instance.listEngineers(cout);
    cout << endl;
    cout << "ID of engineer that will be driving the train - ";
    id_t engineerID;
    project_utils::readVar(engineerID);
    Engineer *eng;
    try {
        eng = System::instance.getEngineer(engineerID);
    } catch (NoSuchEngineerException &e) {
        cout << e.what() << ", returning to main menu." << endl;
        return;
    }

    cout << "Departure ";
    Date dep = project_utils::readDate();
    cout << "Arrival ";
    Date arr = project_utils::readDate();

    try {
        System::instance.createTrip(basePrice, src, dest, tr, eng, dep, arr);
    } catch (...) {
        cout << "A problem has occurred creating trip:" << endl;
        return;
    }

    cout << "Successfully created trip." << endl;

}

void createEngineer() {
    if (!System::instance.getPastEngineers().empty()) {
        cout << "There are engineers that have already worked in the company." << endl
             << "Please choose which one you want to re-hire: ";
        System::instance.listPastEngineers(cout);
        cout << endl << "Choice - ";
        id_t id;
        project_utils::readVar(id);
        try {
            System::instance.hireEngineer(id);
        } catch (NoSuchEngineerException &e) {
            cout << e.what() << ", returning to main menu." << endl;
            return;
        }
    } else {
        string name;
        cout << "Name - ";
        project_utils::readLine(name);

        Date birthDate = project_utils::readBirthDate();

        try {
            System::instance.createEngineer(name, birthDate);
        } catch (...) {
            cout << "A problem has occurred creating engineer:" << endl;
            return;
        }

        cout << "Successfully hired engineer." << endl;
    }
}

void createRepairShop() {
    cout << "Please input the name of the Repair Shop - ";
    string name;
    project_utils::readLine(name);

    cout << "Please input X coordinate - ";
    int x;
    project_utils::readVar(x);

    cout << "Please input Y coordinate - ";
    int y;
    project_utils::readVar(y);

    try {
        System::instance.createRepairShop(name, x, y);
    } catch (...) {
        cout << "A problem has occurred creating repair shop." << endl;
        return;
    }

    cout << "Successfully created repair shop." << endl;
}

void deleteTask() {
    cout << "What do you want to delete? (passenger/station/train/trip/engineer/repair shop/-1 to return to main menu) - ";
    string choice;
    bool validChoice = false;
    while (!validChoice) {
        validChoice = true;
        project_utils::readLine(choice);
        if (choice == "passenger") {
            System::instance.listPassengers(cout);
            cout << endl;
            cout << "ID - ";
            id_t id;
            project_utils::readVar(id);
            System::instance.removePassenger(id);
        } else if (choice == "station") {
            System::instance.listStations(cout);
            cout << endl;
            cout << "ID - ";
            id_t id;
            project_utils::readVar(id);
            System::instance.removeStation(id);
        } else if (choice == "train") {
            System::instance.listHealthyTrains(cout);
            cout << endl;
            cout << "ID - ";
            id_t id;
            project_utils::readVar(id);
            System::instance.removeTrain(id);
        } else if (choice == "trip") {
            System::instance.listTrips(cout);
            cout << endl;
            cout << "ID - ";
            id_t id;
            project_utils::readVar(id);
            System::instance.removeTrip(id);
        } else if (choice == "engineer") {
            System::instance.listEngineers(cout);
            cout << endl;
            cout << "ID - ";
            id_t id;
            project_utils::readVar(id);
            System::instance.removeEngineer(id);
        } else if (choice == "repair shop"){
            System::instance.listRepairShops(cout);
            cout << endl;
            cout << "ID - ";
            id_t id;
            project_utils::readVar(id);
            System::instance.removeRepairShop(id);
        } else {
            cout << "Invalid choice, try again - ";
            validChoice = false;
        }
    }

    cout << "Done." << endl;

}

void searchTask() {
    cout << "Specify a source restraint? (y/n) - ";
    bool searchBySrc = false;
    string choice;
    do {
        project_utils::readLine(choice);
        if (choice != "y" && choice != "n") {
            cout << "Invalid choice, try again - ";
        } else {
            searchBySrc = choice == "y";
        }
    } while (choice != "y" && choice != "n");

    Station *src = nullptr;
    if (searchBySrc) {
        System::instance.listStations(cout);
        cout << endl;
        id_t id;
        cout << "Please input the ID of the source station - ";
        project_utils::readVar(id);
        try {
            src = System::instance.getStation(id);
        } catch (NoSuchStationException &e) {
            cout << "Station ID does not exist." << endl;
            return;
        }
    }

    cout << "Specify a destination restraint? (y/n) - ";
    bool searchByDest = false;
    do {
        project_utils::readLine(choice);
        if (choice != "y" && choice != "n") {
            cout << "Invalid choice, try again - ";
        } else {
            searchByDest = choice == "y";
        }
    } while (choice != "y" && choice != "n");

    Station *dest = nullptr;
    if (searchByDest) {
        id_t id;
        cout << "Please input the ID of the destination station - ";
        project_utils::readVar(id);
        try {
            dest = System::instance.getStation(id);
        } catch (NoSuchStationException &e) {
            cout << "Station ID does not exist." << endl;
            return;
        }
    }

    cout << "Specify a arrival date restraint? (y/n) - ";
    bool searchByArrivalDate = false;
    do {
        project_utils::readLine(choice);
        if (choice != "y" && choice != "n") {
            cout << "Invalid choice, try again - ";
        } else {
            searchByArrivalDate = choice == "y";
        }
    } while (choice != "y" && choice != "n");

    Date arrivalDate("01-01-1970 00:00");
    if (searchByArrivalDate) {
        arrivalDate = project_utils::readDate();
    }

    vector<Trip *> trips = System::instance.searchTrips(src, dest, searchByArrivalDate, arrivalDate);

    cout << endl;

    if (trips.empty()) {
        cout << "There are no trips that match these constraints." << endl;
        return;
    }

    cout << endl
         << setw(5) << "id"
         << setw(13) << "base price"
         << setw(16) << "current price"
         << setw(20) << "source name"
         << setw(20) << "departure date"
         << setw(20) << "destination name"
         << setw(20) << "arrival date"
         << setw(10) << "train id"
         << setw(16) << "free seats" << endl;
    for (Trip *tr: trips) {
        tr->printRow(cout);
        cout << endl;
    }

}

void purchaseTask() {
    System::instance.listPassengers(cout);
    cout << endl;
    cout << "ID of passenger - ";
    Passenger *passenger;
    id_t passengerID;
    project_utils::readVar(passengerID);
    try {
        passenger = System::instance.getPassenger(passengerID);
    } catch (NoSuchPassengerException &e) {
        cout << "Passenger id does not exist, returning to main menu.";
        return;
    }

    System::instance.listTrips(cout);
    cout << endl;
    cout << "ID of the trip - ";
    Trip *tr;
    id_t tripID;
    project_utils::readVar(tripID);
    try {
        tr = System::instance.getTrip(tripID);
    } catch (NoSuchTripException &e) {
        cout << "Trip id does not exist, returning to main menu.";
        return;
    }

    TicketPurchaseRequest rq(passenger, tr);
    try {
        System::instance.processTicketPurchaseRequest(rq);
    } catch (TripPastException &e) {
        cout << "Trip has already passed." << endl;
        return;
    }

    rq.printInvoice(cout);
    cout << endl;
}

void listTask() {
    cout << "What to list (passengers/stations/trains/trips/engineers/repair shops/-1 to return to main menu) ? ";
    string choice;
    bool validChoice = false;
    while (!validChoice) {
        validChoice = true;
        project_utils::readLine(choice);
        if (choice == "passengers") {
            System::instance.listPassengers(cout);
        } else if (choice == "stations") {
            System::instance.listStations(cout);
        } else if (choice == "trains") {
            System::instance.listHealthyTrains(cout);
        } else if (choice == "trips") {
            System::instance.listTrips(cout);
        } else if (choice == "engineers") {
            System::instance.listEngineers(cout);
        } else if (choice == "repair shops") {
            System::instance.listRepairShops(cout);
        } else {
            cout << "Invalid choice, try again - ";
            validChoice = false;
        }
    }
}

void sendTrainToRepairTask() {
    System::instance.listHealthyTrains(cout);
    cout << endl << "Choose the train to send - ";
    id_t id;
    project_utils::readVar(id);
    Train *tr;
    try {
        tr = System::instance.getTrain(id);
    } catch (NoSuchTrainException &e) {
        cout << e.what() << ", returning to main menu." << endl;
        return;
    }

    System::instance.listStations(cout);
    cout << endl << "Choose in which station the train is stationed - ";
    id_t stationId;
    project_utils::readVar(stationId);
    Station *st;
    try {
        st = System::instance.getStation(stationId);
    } catch (NoSuchStationException &e) {
        cout << e.what() << ", returning to main menu." << endl;
        return;
    }

    cout << "Please input a radius - ";
    uint distance;
    project_utils::readVar(distance);

    try {
        System::instance.sendTrainToRepairShop(tr, st, distance);
    } catch (exception &e) {
        cout << "There are no repair shops available." << endl;
        return;
    }
}

void printStationsLB() {
    System::instance.listStationsBST(cout);
}

void advanceDayTask() {
    cout << "Are you sure? (yes/no): ";
    string answer;
    do {
        project_utils::readLine(answer);
        if (answer != "yes" && answer != "no") {
            cout << "Please enter a valid choice (yes/no) - ";
        }
    } while (answer != "yes" && answer != "no");

    if (answer == "yes") {
        System::instance.advanceDay();
    }

    cout << "Done." << endl;

}

void payCard() {
    System::instance.listPassengers(cout);
    cout << endl;
    cout << "Please enter the ID of the passenger whose card is being paid - ";
    id_t passengerID;
    project_utils::readVar(passengerID);

    try {
        if (!System::instance.payCard(passengerID, cout)) {
            cout << "Passenger doesn't have a card." << endl;
            return;
        }
    } catch (NoSuchPassengerException &e) {
        cout << "Passenger Id doesn't exists." << endl;
        return;
    }

    cout << "Done." << endl;
}

void checkCards() {
    cout
            << "This function will invalidate unpayed cards and reset the the cards payment status, do you wish to proceed? (y/n) - ";
    bool proceed = false;
    string choice;
    do {
        project_utils::readLine(choice);
        if (choice != "y" && choice != "n") {
            cout << "Invalid choice, try again - ";
        } else {
            proceed = choice == "y";
        }
    } while (choice != "y" && choice != "n");

    if (proceed) {
        System::instance.processCards();
        cout << "Done." << endl;
    } else {
        cout << "Returning." << endl;
    }
}

int main() {
    Date d("12-12-2018 11:00");
    cout << d << endl;

    System::instance.loadPassengers();
    System::instance.loadEngineers();
    System::instance.loadCards();
    System::instance.loadStations();
    System::instance.loadTrains();
    System::instance.loadTrips();
    System::instance.loadRepairShops();
    System::instance.loadPurchases();

    bool programmRunning = true;
    while (programmRunning) {

        mainMenu();

        int choice;
        if (project_utils::readVar(choice)) {
            break;
        }

        bool validChoice = false;
        while (!validChoice) {
            switch (choice) {
                case 1: {
                    createTask();
                    validChoice = true;
                    break;
                }
                case 2: {
                    deleteTask();
                    validChoice = true;
                    break;
                }
                case 3: {
                    searchTask();
                    validChoice = true;
                    break;
                }
                case 4: {
                    purchaseTask();
                    validChoice = true;
                    break;
                }
                case 5: {
                    listTask();
                    validChoice = true;
                    break;
                }
                case 6: {
                    payCard();
                    validChoice = true;
                    break;
                }
                case 7: {
                    System::instance.printSales(cout);
                    validChoice = true;
                    break;
                }
                case 8: {
                    sendTrainToRepairTask();
                    validChoice = true;
                    break;
                }
                case 9: {
                    printStationsLB();
                    validChoice = true;
                    break;
                }
                case 20: {
                    advanceDayTask();
                    validChoice = true;
                    break;
                }
                case 50: {
                    checkCards();
                    validChoice = true;
                    break;
                }
                case 100: {
                    programmRunning = false;
                    validChoice = true;
                    break;
                }
                default: {
                    cout << "Invalid choice, try again - ";
                    validChoice = false;
                    break;
                }
            }
        }
        if (programmRunning) {
            cout << "Press ENTER to continue to main menu." << endl;
            getchar();
        }
    }

    System::instance.savePassengers();
    System::instance.saveEngineers();
    System::instance.saveStations();
    System::instance.saveTrains();
    System::instance.saveTrips();
    System::instance.saveRepairShops();
    System::instance.savePurchases();

    return 0;
}
