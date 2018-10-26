#include <ctime>
#include <iostream>
#include <string>

#ifndef DATE_H_
#define DATE_H_

class Date {
public:
	Date(unsigned int year, unsigned int month, unsigned int day,
			unsigned int hour = 0, unsigned int minute = 0);

	bool isValid();
	friend std::ostream& operator<< (std::ostream &o, Date &d);

private:
	std::string buildString();

private:
	tm date;
	static const unsigned int monthsWith31[];
	static const unsigned int monthsWith30[];
	static const char* dateFormat;
};



#endif /* DATE_H_ */
