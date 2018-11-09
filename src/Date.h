#ifndef DATE_H_
#define DATE_H_

#include <ctime>
#include <iostream>
#include <string>

class Date {
public:
	Date(int year, int month, int day,
			int hour = 0, int minute = 0);
	Date(const std::string &dateString);

	friend std::ostream& operator<< (std::ostream &o, Date &d);
	bool operator== (Date &d);
	bool operator< (Date &d);
	bool operator<= (Date &d);
	bool operator> (Date &d);
	bool operator>= (Date &d);
	std::string getDateString() const;
	std::string getDateStringWithoutHours() const;
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int getHour() const;
	int getMinutes() const;


private:
	bool validate();

private:
	tm date;
	static const unsigned int monthsWith31[];
	static const unsigned int monthsWith30[];
	static const char* dateFormat;
};



#endif /* DATE_H_ */
