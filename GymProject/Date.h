#ifndef _DATE_H
#define _DATE_H

#include <iostream>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date(int day = 0, int month = 0, int year = 0);

	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(const int day);
	void setMonth(const int month);
	void setYear(const int year);

	friend istream& operator>>(istream& in, Date& d);
	bool operator==(const Date& other) const;
	void operator=(const Date& other);
	friend ostream& operator<<(ostream& os, const Date& node);

	void show() const;
};

#endif
