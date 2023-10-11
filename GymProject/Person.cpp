#pragma warning(disable: 4996)
#include <iostream>

using namespace std;

#include "Person.h"

int Person::numberGenerator = 0;

Person::Person(const std::string& name, const std::string& familyName, const int phoneNumber, const Date& dateOfBirth)
{
	id = ++numberGenerator;
	setName(name);
	setFamilyName(familyName);
	setPhoneNumber(phoneNumber);
	setDateOfBirth(dateOfBirth);
}

int Person::getId() const
{
	return id;
}

std::string Person::getName() const
{
	return name;
}

void Person::setName(const std::string& name)
{
	this->name = name;
}

std::string Person::getFamilyName() const
{
	return familyName;
}

void Person::setFamilyName(const std::string& familyName)
{
	this->familyName = familyName;
}

int Person::getPhoneNumber() const
{
	return phoneNumber;
}

void Person::setPhoneNumber(const int phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

Date Person::getDateOfBirth() const
{
	return dateOfBirth;
}

void Person::setDateOfBirth(const Date& dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}

const Person& Person::operator++()
{
	id++;
	return *this;
}

void Person::show() const
{
	cout << "name: " << name << " " << familyName << ", id: " << id << ", phone: " << phoneNumber << ", DOB: ";
	dateOfBirth.show();
}