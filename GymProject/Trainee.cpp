#pragma warning(disable: 4996)

#include <iostream>
#include "Trainee.h"

const char* favoriteTypes[5] = { "Bicycle", "Rowing-machine", "Leg-press", "Lat-pulldown", "Chest-press" };

Trainee::Trainee(const Person& base, int favoriteMachine) : Person(base) , Observer(base.getName() , base.getFamilyName())
{
	setFavMachine(favoriteMachine);
}

int Trainee::getFavMachine() const
{
	return favoriteMachine;
}

void Trainee::setFavMachine(int machine)
{
	this->favoriteMachine = machine;
}

void Trainee::show() const
{
	Person::show();
	cout << "his favorite machine: " << favoriteTypes[ExerciseMachine::eName(favoriteMachine)] << "\n";
}

void Trainee::notify(const string& shopName, string msg) const
{
	cout << this->getName() << " " << this->getFamilyName() << " got a new message from " << shopName << ": " << msg << "\n";
}

Observer* Trainee::clone() const { return new Trainee(*this); }


Observer::Observer(const string& firstName, const string& lastName) : firstName(firstName) , lastName(lastName) {}
const string& Observer::getNameObserver() const { return firstName; }
const string& Observer::getLastNameObserver() const { return lastName; }

