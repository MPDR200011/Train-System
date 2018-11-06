#include "System.h"
#include "TrainSystemException.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> splitArgumets(string&);
void loadPassengers();
void loadStations();
void loadTrains();
void loadTrips();

vector<string> splitArgumets(string& command) {
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

void loadPassengers() {
	ifstream passengers("passengers.txt");
	string line;
	while (getline(passengers, line)) {
		vector<string> arguments = splitArgumets(line);
		if (!System::instance.createPassenger(arguments)) {
			cerr << "Ivalid line: " << line << endl;
		}
	}
}

void loadStations() {
	ifstream stations("stations.txt");
	string line;
	while (getline(stations, line)) {
		vector<string> arguments = splitArgumets(line);
		if (!System::instance.createStation(arguments)) {
			cerr << "Ivalid line: " << line << endl;
		}
	}
}

void loadTrains() {
	ifstream trains("trains.txt");
	string line;
	while (getline(trains, line)) {
		vector<string> arguments = splitArgumets(line);
		if (!System::instance.createTrain(arguments)) {
			cerr << "Ivalid line: " << line << endl;
		}
	}
}

void loadTrips() {
	ifstream trips("trips.txt");
	string line;
	while (getline(trips, line)) {
		vector<string> arguments = splitArgumets(line);
		if (!System::instance.createTrip(arguments)) {
			cerr << "Ivalid line: " << line << endl;
		}
	}
}

int main() {

	loadPassengers();
	loadStations();
	loadTrains();
	loadTrips();

	cout << System::instance;

	return 0;
}
