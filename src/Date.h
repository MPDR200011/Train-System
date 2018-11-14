#ifndef DATE_H_
#define DATE_H_

#include <ctime>
#include <iostream>
#include <string>

/**
 * @brief Class for representing dates in the program.
 * 
 * Works as an abstraction of C++'s ctime library. 
 * 
 */
class Date {
public:
	/**
	 * @brief Construct a new Date object
	 * 
	 * Constructs Date object and calls validate().
	 * If validation fails, throws InvalidDateException.
	 * 
	 * @param year Date's year
	 * @param month Date's month
	 * @param day Date's day in month
	 * @param hour Date's hour of day (24h format)
	 * @param minute Date's minutes
	 */
	Date(int year, int month, int day,
			int hour = 0, int minute = 0);
	/**
	 * @brief Construct a new Date object
	 * 
	 * Constructs Date object and calls validate().
	 * If validation fails, throws InvalidDateException.
	 * 
	 * @param dateString Date in form of a string in format "dd-mm-yyyy HH:MM". Day, month, year, hour and minutes must be two digits ('02', '08', '12')
	 */
	Date(const std::string &dateString);

	/**
	 * @brief ouput Date object into an output stream
	 * 
	 * Passes a string of the date, to the output stream, in the following format: "dd-mm-yyyy HH:MM"
	 * 
	 * @param o ouput stream
	 * @param d date object
	 * @return std::ostream& reference to the output stream passed as argument  
	 */
	friend std::ostream& operator<< (std::ostream &o, Date &d);
	/**
	 * @brief Check eqaulity between Date objects
	 * 
	 * @param d Date object to compare with self
	 * @return true if equal
	 * @return false if not equal
	 */
	bool operator== (Date &d);
	/**
	 * @brief Check if Date object happens before argument
	 * 
	 * @param d Date object to compare
	 * @return true if object happens before argument
	 * @return false if otherwise
	 */
	bool operator< (Date &d);
	/**
	 * @brief Check if Date object happens before or at same time as argument
	 * 
	 * @param d Date object to compare with self
	 * @return true if object happens before or at same time of argument 
	 * @return false if otherwise
	 */
	bool operator<= (Date &d);
	/**
	 * @brief Check if Date object happens after argument
	 * 
	 * @param d Date object to compare with self
	 * @return true if object happens after argument
	 * @return false if otherwise
	 */
	bool operator> (Date &d);
	/**
	 * @brief Check if Date object happens after or at same time as argument
	 * 
	 * @param d Date object to compare with self
	 * @return true if object happens after or at same time of argument
	 * @return false if otherwise
	 */
	bool operator>= (Date &d);
	/**
	 * @brief Get the Date String
	 * 
	 * @return std::string a string in the format: "dd-mm-yyyy HH:MM"
	 */
	std::string getDateString() const;
	/**
	 * @brief Get the Date String Without Hours
	 * 
	 * @return std::string a string in the format: "dd-mm-yyyy"
	 */
	std::string getDateStringWithoutHours() const;
	/**
	 * @brief Get the Year
	 * 
	 * @return int 
	 */
	int getYear() const;
	/**
	 * @brief Get the Month
	 * 
	 * @return int 
	 */
	int getMonth() const;
	/**
	 * @brief Get the Day
	 * 
	 * @return int 
	 */
	int getDay() const;
	/**
	 * @brief Get the Hour
	 * 
	 * @return int 
	 */
	int getHour() const;
	/**
	 * @brief Get the Minutes
	 * 
	 * @return int 
	 */
	int getMinutes() const;

	/**
	 * @brief Get the Time Stamp object
	 * 
	 * @return long Seconds since epoch at January 1st 1970 00:00
	 */
	long int getTimeStamp();


private:
	/**
	 * @brief Check the validity of date
	 * 
	 * Uses Gregorian calendar standards to validate de Date object, usually after construction.
	 * 
	 * @return true 
	 * @return false 
	 */
	bool validate();

private:
	/**
	 * @brief Time struct generted by ctime
	 * 
	 */
	tm date;
	/**
	 * @brief Array with months with 31 days
	 * 
	 * Months are represented with 0-11 instead of 1-12 
	 * 
	 */
	static const unsigned int monthsWith31[];
	/**
	 * @brief Array with months with 30 days
	 * 
	 * Months are represented with 0-11 instead of 1-12 
	 * 
	 */
	static const unsigned int monthsWith30[];
	/**
	 * @brief String to represent the standard format with wich to print or input the date through a string
	 * 
	 */
	static const char* dateFormat;
};



#endif /* DATE_H_ */
