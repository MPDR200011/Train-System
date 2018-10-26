#include "Date.h"
#include "InvalidDateException.h"
#include <algorithm>

using namespace std;

const unsigned int Date::monthsWith31[] = {0, 2, 4, 6, 7, 9, 11};
const unsigned int Date::monthsWith30[] = {3, 5, 8, 10};
const char* Date::dateFormat = "%d-%m-%Y %H:%M";

Date::Date(unsigned int year, unsigned int month, unsigned int day,
		unsigned int hour, unsigned int minutes) {
	date.tm_year = year-1900;
	date.tm_mon = month-1;
	date.tm_mday = day;
	date.tm_hour = hour;
	date.tm_min = minutes;
	date.tm_sec = 0;

	if (!isValid()) {
		throw InvalidDateException(buildString());
	}
}

bool Date::isValid() {
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
		return date.tm_mday > 31;
	} else if (find(monthsWith30, monthsWith30+4, date.tm_mon) != monthsWith30+4) {
		return date.tm_mday > 30;
	} else {
		if (date.tm_year % 4 == 0) {
			return date.tm_mday <= 29;
		} else {
			return date.tm_mday <= 28;
		}
	}
}

std::string Date::buildString() {
	char str[80];
	strftime(str, 80, dateFormat, &date);
	return string(str);
}

std::ostream& operator <<(std::ostream& o, Date& d) {
	o << d.buildString();
	return o;
}
