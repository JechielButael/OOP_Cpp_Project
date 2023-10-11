#ifndef _TRAINEE_H
#define _TRAINEE_H

#include "ExerciseMachine.h"
#include "Person.h"

class Date;

class Observer
{
public:
	Observer(const string& firstName , const string& lastName);
	virtual void notify(const string& name, string str) const = 0;
	virtual Observer* clone() const = 0;
	const string& getNameObserver() const;
	const string& getLastNameObserver() const;
protected:
	string firstName;
	string lastName;
}; // Observer



class Trainee : virtual public Person ,  virtual public Observer
{
private:
	int favoriteMachine;

public:
	Trainee(const Person& base, int favoriteMachine);

	int getFavMachine() const;
	void setFavMachine(int machine);
	virtual void show() const;

	//observer functions
	virtual void notify(const string& shopName, string msg) const;
	virtual Observer* clone() const;
};

#endif
