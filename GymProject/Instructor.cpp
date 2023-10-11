#include <iostream>
#include "Instructor.h"
#include <string.h>

Instructor::Instructor(const Trainee& trainee, const Employee& employee, int numExpYears) :
	Person(trainee.getName(), trainee.getFamilyName(), trainee.getPhoneNumber(), trainee.getDateOfBirth()),
	Trainee(trainee), Employee(employee) , Observer(trainee.getName(), trainee.getFamilyName())
{
	setNumExpYears(numExpYears);
}

Instructor::Instructor(const Instructor& other) : Person(other), Trainee(other), Employee(other) , Observer(other.getName() , other.getFamilyName())
{
	*this = other;
}

int Instructor::getNumExpYears() const
{
	return numExpYears;
}

void Instructor::setNumExpYears(const int num)
{
	this->numExpYears = num;
}

void Instructor::show() const
{
	Trainee::show();
	cout << "Salary is: " << Employee::getSalary() << "\n";
	cout << "Number of experience is: " << numExpYears << "\n";
}

void Instructor::notify(const string& shopName, string msg) const
{
	//string str = "There is a new Instructor";
	//if(str.compare(msg) != 0)
	cout << this->getName() << " " << this->getFamilyName() << " got a new message from " << shopName << ": " << msg << "\n";
}

Observer* Instructor::clone() const { return new Instructor(*this); }