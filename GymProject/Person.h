#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include "Date.h"
class Date;

class Person
{
private:
	int id;
	static int numberGenerator;
	string name;
	string familyName;
	int phoneNumber;
	Date dateOfBirth;

public:
	Person(const string& name, const string& familyName, const int phoneNumber, const Date& dateOfBirth);

	int getId() const;
	string getName() const;
	string getFamilyName() const;
	int  getPhoneNumber() const;
	Date getDateOfBirth() const;
	void setName(const string& name);
	void setFamilyName(const string& familyName);
	void setPhoneNumber(const int phoneNumber);
	void setDateOfBirth(const Date& dateOfBirth);
	virtual void show() const;

	const Person& operator++();

};

#endif

