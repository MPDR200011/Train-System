#include "project_utils.h"
#include "exceptions/InvalidDateException.h"

bool project_utils::readLine(string &s) {
    if (!cin.good()) {
        cin.ignore(INT32_MAX, '\n');
        cin.clear();
    }

    bool validInput = false;
    while (!validInput) {
        cin.clear();
        getline(cin, s);

        if (!cin.good()) {
            if (cin.eof()) {
                cin.clear();
                cin.ignore(INT32_MAX, '\n');
                cin.clear();
                return true;
            } else {
                cin.clear();
            }
        } else {
            validInput = true;
        }
    }
    return false;
}

Date project_utils::readBirthDate() {
	Date date("01-01-1970 00:00");
	cout << "Birth Date (dd-mm-yyyy) - ";
	bool validDate = true;
	do {
		string dateString;
		readLine(dateString);

		if (dateString.length() != 10) {
			cout << "Date has to be in the exact format (dd-mm-yyyy), try again - ";
			validDate = false;
			continue;
		}
		dateString += " 00:00";

		try {
			date = Date(dateString);
		} catch (InvalidDateException &e) {
			cout << "The date you entered is not valid, try again - ";
			validDate = false;
			continue;
		}
		validDate = true;
	} while (!validDate);
	return date;
}

Date project_utils::readDate() {
	Date date("01-01-1970 00:00");
	cout << "Date (dd-mm-yyyy HH:MM) - ";
	bool validDate = true;
	do {
		string dateString;
		readLine(dateString);

		if (dateString.length() != 16) {
			cout << "Date has to be in the exact format (dd-mm-yyyy HH:MM), try again - ";
			validDate = false;
			continue;
		}

		try {
			date = Date(dateString);
		} catch (InvalidDateException &e) {
			cout << "The date you entered is not valid, try again - ";
			validDate = false;
			continue;
		}

		validDate = true;
	} while (!validDate);
	return date;
}

vector<string> project_utils::splitArguments(string& command) {
	vector<string> v;
	string temp;
	bool isString = false;
	for (const char c: command) {
		if (c == ' ') {
			if (!isString) {
				if (!temp.empty()) {
					v.push_back(temp);
					temp.clear();
				}
			} else {
				temp.push_back(c);
			}
		} else {
			if (c == '\"') {
				if (!isString) {
					isString = true;
				} else {
					v.push_back(temp);
					temp.clear();
					isString = false;
				}
			} else {
				temp.push_back(c);
			}
		}
	}

	if (!temp.empty()) {
		v.push_back(temp);
	}

	return v;
}
