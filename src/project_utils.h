#ifndef PROJ_UTILS_H
#define PROJ_UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include "Date.h"

using namespace std;

#define FOURTY_HEIGHT_HOURS 172800

/**
 * @brief Abreviation for unsigned ints
 * 
 */
typedef unsigned int uint;

/**
 * @brief Contextual typedef for ID's
 * 
 * Since IDs are unsigned integers, this typedef helps get rid of mistakes where people
 * might use a signed int for IDs and cause overflow problems.
 * 
 */
typedef unsigned int id_t;

namespace project_utils {
    /**
     * @brief Template function to read any variable from cin.
     *
     * @tparam T
     * @param var
     * @return true If cin reports EOF.
     * @return false IF cin doesn't report EOF.
     */
    template <class T>
    bool readVar(T &var) {
        if (!cin.good()) {
            cin.ignore(INT32_MAX, '\n');
            cin.clear();
        }

        bool validInput = false;
        while (!validInput) {
            cin >> var;
            if (!cin.good()) {
                if (cin.eof()) {
                    cin.clear();
                    cin.ignore(INT32_MAX, '\n');
                    cin.clear();
                    return true;
                } else {
                    cout << "Invalid input, try again - ";
                    cin.clear();
                    cin.ignore(INT32_MAX, '\n');
                    cin.clear();
                }
            } else {
                cin.clear();
                cin.ignore(INT32_MAX, '\n');
                cin.clear();
                validInput = true;
            }
        }
        return false;
    }

    /**
     * @brief Function to read a string using getline(cin).
     *
     * @param s
     * @return true If cin reports EOF.
     * @return false If cin doesn't report EOF.
     */
    bool readLine(string &s);

    /**
     * @brief Read a birthdate
     *
     * Asks user to input a date in the format "dd-mm-yyyy".
     *
     * @return Date
     */
    Date readBirthDate();

    /**
     * @brief Read a date
     *
     * Asks user to input a date in the format "dd-mm-yyyy HH:MM".
     *
     * @return Date
     */
    Date readDate();

    std::vector<std::string> splitArguments(std::string& command);
}

#endif