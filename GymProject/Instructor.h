#ifndef _INSTRUCTOR_H
#define _INSTRUCTOR_H

#include "Employee.h"
#include "Trainee.h"

class Observer;

class Instructor : public Trainee, public Employee
{
private:
	int numExpYears;

public:
	Instructor(const Trainee& trainee, const Employee& employee, int numExpYears);
	Instructor(const Instructor& other);

	int getNumExpYears() const;
	void setNumExpYears(const int num);
	virtual void show() const;

	//observer functions
	virtual void notify(const string& shopName, string msg) const;
	virtual Observer* clone() const;
};

#endif
