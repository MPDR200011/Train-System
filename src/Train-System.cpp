#include "System.h"
#include "TrainSystemException.h"
#include <iostream>

using namespace std;



int main() {
	try {
		Date d("02-02-1999 10:00");

		cout << d;

	} catch (TrainSystemException &e) {
		cerr <<	"A problem has occurred: " << endl;
		cerr << '\t' << e.what();
	}
	return 0;
}
