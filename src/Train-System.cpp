#include "System.h"
#include "TrainSystemException.h"
#include <iostream>

using namespace std;

int main() {
	try {
		Date d("28-02-2017 12:34");

		cout << d;
	} catch (TrainSystemException &e) {
		cerr <<	"A problem has occurred: " << endl;
		cerr << '\t' << e.what();
	}
	return 0;
}
