#include "Date.h"
#include "InvalidDateException.h"
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;

const unsigned int Date::monthsWith31[] = {0, 2, 4, 6, 7, 9, 11};
const unsigned int Date::monthsWith30[] = {3, 5, 8, 10};
const char* Date::dateFormat = "%d-%m-%Y %H:%M";

Date::Date(int year, int month, int day,
		int hour, int minutes) {
	date.tm_year = year-1900;
	date.tm_mon = month-1;
	date.tm_mday = day;
	date.tm_hour = hour;
	date.tm_min = minutes;
	date.tm_sec = 0;

	if (!validate()) {
		throw InvalidDateException(getDateString());
	}
}

Date::Date(const std::string &dateString) {
	stringstream ss(dateString);
	ss >> get_time(&date, dateFormat);
	date.tm_sec = 0;

	if (!validate()) {
		throw InvalidDateException(getDateString());
	}
}

bool Date::validate() {
	if (date.tm_sec < 0 || date.tm_sec > 60)
		return false;
	if (date.tm_min < 0 || date.tm_min > 59)
		return false;
	if (date.tm_hour < 0 || date.tm_hour > 23)
		return false;
	if (date.tm_mon < 0 || date.tm_mon > 11)
		return false;
	if (date.tm_mday < 0)
		return false;
	if (date.tm_year < 0)
		return false;

	if (find(monthsWith31, monthsWith31+7, date.tm_mon) != monthsWith31+7) {
		return date.tm_mday <= 31;
	} else if (find(monthsWith30, monthsWith30+4, date.tm_mon) != monthsWith30+4) {
		return date.tm_mday <= 30;
	} else {
		if (date.tm_year % 4 == 0) {
			return date.tm_mday <= 29;
		} else {
			return date.tm_mday <= 28;
		}
	}
}

int Date::getYear() const {
	return date.tm_year + 1900;
}

int Date::getMonth() const {
	return date.tm_mon + 1;
}

int Date::getDay() const {
	return date.tm_mday;
}

int Date::getHour() const {
	return date.tm_hour;
}

int Date::getMinutes() const {
	return date.tm_min;
}

std::string Date::getDateString() const {
	char str[80];
	strftime(str, 80, dateFormat, &date);
	return string(str);
}

std::string Date::getDateStringWithoutHours() const {
	return getDateString().substr(0, 10);
}

std::ostream& operator <<(std::ostream& o, Date& d) {
	o << d.getDateString();
	return o;
}

bool Date::operator ==(Date& d) {
	if (date.tm_year == d.date.tm_year) {
		if (date.tm_mon == d.date.tm_mon) {
			if (date.tm_mday == d.date.tm_mday) {
				if (date.tm_hour == d.date.tm_hour) {
					if (date.tm_min == d.date.tm_min) {
						return date.tm_sec == d.date.tm_sec;
					}
				}
			}
		}
	}
	return false;
}

bool Date::operator <(Date& d) {
	if (date.tm_year == d.date.tm_year) {
		if (date.tm_mon == d.date.tm_mon) {
			if (date.tm_mday == d.date.tm_mday) {
				if (date.tm_hour == d.date.tm_hour) {
					if (date.tm_min == d.date.tm_min) {
						return date.tm_sec < d.date.tm_sec;
					} else {
						return date.tm_min < d.date.tm_min;
					}
				} else {
					return date.tm_hour < d.date.tm_hour;
				}
			} else {
				return date.tm_mday < d.date.tm_mday;
			}
		} else {
			return date.tm_mon < d.date.tm_mon;
		}
	}else {
		return date.tm_year < d.date.tm_year;
	}
}

bool Date::operator <=(Date& d) {
	return ((*this < d) || (*this == d));
}

bool Date::operator >(Date& d) {
	return !(*this <= d);
}

bool Date::operator >=(Date& d) {
	return !(*this < d);
}
