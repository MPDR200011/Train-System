#include "System.h"
#include "TrainSystemException.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void prompt();
bool processCommand(string command);
void createTask(vector<string> arguments);
void deleteTask(vector<string> arguments);
void searchTask(vector<string> arguments);
void purchaseTask(vector<string> arguments);
void listTask(vector<string> arguments);
void helpTask(vector<string> arguments);
vector<string> splitArgumets(string&);

void loadPassengers();
void loadStations();
void loadTrains();
void loadTrips();

void prompt() {
	cout << "Train System $ ";
}

//TODO delete task
//TODO search task
//TODO create card
//TODO card payments management

bool processCommand(string command) {
	vector<string> arguments = splitArgumets(command);
	if (arguments.size() == 0) {
		cout << "Command is empty." << endl;
		return false;
	}
	string task = arguments[0];
	if (task == "create") {
		createTask(vector<string>(arguments.begin()+1, arguments.end()));
	} else if (task == "delete") {
		deleteTask(vector<string>(arguments.begin()+1, arguments.end()));
	} else if (task == "search") {
		//searchTask(vector<string>(arguments.begin()+1, arguments.end()));
	} else if (task == "purchase") {
		purchaseTask(vector<string>(arguments.begin()+1, arguments.end()));
	} else if (task == "list") {
		listTask(vector<string>(arguments.begin()+1, arguments.end()));
	} else if(task == "help") {
		helpTask(vector<string>(arguments.begin()+1, arguments.end()));		 
	} else if (task == "exit") {
		return true;
	} else {
		cout << task << " command does not exist." << endl;
	}
	return false;
}

void createTask(vector<string> arguments) {
	if (arguments.size() == 0) {
		cout << "No arguments." << endl;
		return;
	}
	string type = arguments[0];
	if (type == "passenger") {
		if (arguments.size() == 3) {
			if (!System::instance.createPassenger(vector<string>(arguments.begin()+1,arguments.end()))) {
				return;
			}
		} else {
			cout << "Invalid number of arguments." << endl;
			return;
		}
	} else if (type == "station") {
		if (arguments.size() == 2) {
			if(!System::instance.createStation(vector<string>(arguments.begin()+1,arguments.end()))) {
				return;
			}
		} else {
			cout << "Invalid number of arguments." << endl;
			return;
		}
	} else if (type == "train") {
		if (arguments.size() == 2) {
			if (!System::instance.createTrain(vector<string>(arguments.begin()+1,arguments.end()))) {
				return;
			}
		} else {
			cout << "Invalid number of arguments." << endl;
			return;
		}
	} else if (type == "trip") {
		if (arguments.size() == 7) {
			if (!System::instance.createTrip(vector<string>(arguments.begin()+1,arguments.end()))) {
				return;
			}
		} else {
			cout << "Invalid number of arguments." << endl;
			return;
		}
	} else {
		cout << "Invalid type " << type << "." << endl;
		return;
	}
	cout << "Successfully created " << type << "." << endl;
}

void deleteTask(vector<string> arguments) {
	if (arguments.size() != 1) {
		cout << "Invalid number of arguments. Must be one." << endl;
	}
	
}

void purchaseTask(vector<string> arguments) {
	if (arguments.size() != 2) {
		cout << "Invalid number of arguments. Must be two." << endl;
		return;
	}
	id_t passengerID = stoi(arguments[0]);
	id_t tripID = stoi(arguments[1]);
	
	try {
		Passenger *p = System::instance.getPassenger(passengerID);
		Trip *tr = System::instance.getTrip(tripID);
		
		TicketPurchaseRequest pr(p,tr);

		if (System::instance.processTicketPurchaseRequest(pr)) {
			pr.printInvoice(cout);
			cout << endl;
		} else {
			cout << "Trip has no free seats." << endl;
		}
	
	} catch (exception &e) {
		cout << "Exception caught: " << endl;
		cout << e.what() << endl;
	}
}

void listTask(vector<string> arguments) {
	if (arguments.size() != 1) {
		cout << "Invalid number of arguments. Must be one." << endl;
		return;
	}
	string type = arguments[0];
	if (type == "passengers") {
		System::instance.listPassengers(cout);
	} else if (type == "stations") {
		System::instance.listStations(cout);
	} else if (type == "trains") {
		System::instance.listTrains(cout);
	} else if (type == "trips") {
		System::instance.listTrips(cout);
	} else {
		cout << "Invalid type." << endl;
	}
}

void helpTask(vector<string> arguments) {
	if (!arguments.size()) {
		cout<<"Available commands:\n create (passenger, train, trip, station)\n delete (passenger, train, trip, station)\n purchase\n list (passengers, trains, stations, trips)"<<endl;
		cout<<" help (create, delete, purchase, list)"<<endl;
		return;
	}
	string type = arguments[0];
	if (type == "create") {
		cout<<"Available commands:\n create passenger [Name] [BirthDate DD-MM-YY HH:MM] \n create trip [Base Price] [Source Station ID] [Destination Station ID] [Train ID] [Departure Date] [Arrival Date]"<<endl;
		cout<<" create train [Max Seats] \n create station [Name]"<<endl;
	} else if (type == "delete") {
		cout<<"Available commands:\n delete passenger [id] \n delete trip [id]\n delete train [id] \n delete station [id]"<<endl;
	} else if (type == "purchase") {
		cout<<"Available commands:\n purchase [Passenger ID] [Trip ID]"<<endl;
	} else if (type == "list") {
		cout<<"Available commands:\n list passengers\n list trips\n list trains\n list stations"<<endl;
	} else {
		cout << "Invalid type." << endl;
	}
}

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

	//cout << System::instance << endl;

	bool programRunning = true;
	while (programRunning) {
		prompt();

		string command;
		getline(cin, command);

		if (processCommand(command)) {
			programRunning = false;
		}
	}

	return 0;
}
