#ifndef DATE_H_
#define DATE_H_

#include <ctime>
#include <iostream>
#include <string>

class Date {
public:
	Date(unsigned int year, unsigned int month, unsigned int day,
			unsigned int hour = 0, unsigned int minute = 0);
	Date(const std::string &dateString);

	friend std::ostream& operator<< (std::ostream &o, Date &d);
	bool operator== (Date &d);
	bool operator< (Date &d);
	bool operator<= (Date &d);
	bool operator> (Date &d);
	bool operator>= (Date &d);
	std::string getDateString() const;
	unsigned int getYear() const;
	unsigned int getMonth() const;
	unsigned int getDay() const;
	unsigned int getHour() const;
	unsigned int getMinutes() const;


private:
	bool validate();

private:
	tm date;
	static const unsigned int monthsWith31[];
	static const unsigned int monthsWith30[];
	static const char* dateFormat;
};



#endif /* DATE_H_ */
