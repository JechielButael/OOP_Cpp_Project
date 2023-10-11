#pragma warning(disable: 4996)
#include <iostream>
#include "Gym.h"

Gym Gym::theGym;

Gym::Gym(const int id, const std::string& name, const std::string& address, const int maxMachines, const int maxTrainees)
{
	this->id = id;
	setName(name);
	setAddress(address);
	setMachineNum(maxMachines);
	setTraineeNum(maxTrainees);

	allMachines.reserve(maxMachines);
	allTrainees.reserve(maxTrainees);
}

Gym* Gym::getInstance()
{
	return &theGym;
}

GymLicense Gym::getLicense() const
{
	return *license;
}

int Gym::getId() const
{
	return id;
}

std::string Gym::getName() const
{
	return name;
}

void Gym::setName(const std::string& name)
{
	this->name = name;
}

std::string Gym::getAddress() const
{
	return address;
}

void Gym::setAddress(const std::string& address)
{
	this->address = address;
}

int Gym::getMachineNum() const
{
	return machinesNum;
}

void Gym::setMachineNum(const int machineNum)
{
	this->machinesNum = machineNum;
}

int Gym::getTraineeNum() const
{
	return traineesNum;
}

void Gym::setTraineeNum(const int TraineeNum)
{
	this->traineesNum = TraineeNum;
}

std::vector<ExerciseMachine> Gym::getAllMachines() const
{
	return allMachines;
}

std::vector<Trainee> Gym::getAllTrainees() const
{
	return allTrainees;
}

bool Gym::addTrainee(Trainee* trainee)
{
	if (allTrainees.size() == traineesNum)
		return false;

	registerObserver(trainee);
	allTrainees.push_back(*trainee);
	return true;
}

Instructor* Gym::getInstructor() const
{
	if (instructor == NULL)
		return NULL;

	return instructor;
}

void Gym::setInstructor(Instructor* c)
{
	string str = "There is a new instructor in the gym!";
	notifyAllRegistered(str);
	registerObserver(c);
	instructor = new Instructor(*c);
}

void Gym::setGymLicense(const GymLicense* other)
{
	string str = "the gym license got updated!";
	license = new GymLicense(*other);
	notifyAllRegistered(str);
}

bool Gym::addMachine(const ExerciseMachine* machine)
{
	if (allMachines.size() == machinesNum)
		return false;

	string str = "There is a new exercise machine! make sure to check it out!";
	allMachines.push_back(*machine);
	notifyAllRegistered(str);
	return true;
}

void Gym::showMachines() const
{
	vector<ExerciseMachine>::const_iterator itr = allMachines.begin();
	vector<ExerciseMachine>::const_iterator itrEnd = allMachines.end();

	if (itr == itrEnd)
	{
		cout << "There isn't machines in the gym\n\n";
		return;
	}
	cout << "Exercise machines are:\n";
	for ( ; itr != itrEnd; ++itr)
	{
		(*itr).show();
		cout << "\n";
	}
	cout << "\n\n";
}

void Gym::showInstructor() const
{
	if (!instructor)
	{
		cout << "There is no instructor in the gym\n\n";
		return;
	}
	cout << "Instructor:\n";
	instructor->show();
}

void Gym::showTrainees() const
{
	vector<Trainee>::const_iterator itr = allTrainees.begin();
	vector<Trainee>::const_iterator itrEnd = allTrainees.end();
	if (itr == itrEnd)
	{
		cout << "There isn't trainees in the gym\n\n";
		return;
	}
	cout << "Trainees are:\n";
	for (; itr != itrEnd; ++itr)
	{
		(*itr).show();
	}
	cout << "\n";
}

void Gym::registerObserver(Observer* obs)
{
	cout << "Registerd " << obs->getNameObserver() << " " << obs->getLastNameObserver() << " to get notifications from '" << name << "'\n";
	viewers.push_back(obs);
}

void Gym::notifyAllRegistered(string str) const
{
	vector<Observer*>::const_iterator itr = viewers.begin();
	vector<Observer*>::const_iterator itrEnd = viewers.end();
	for (; itr != itrEnd; ++itr)
		(*itr)->notify(name, str);
}

void Gym::show() const
{
	cout << "Gym:\n\nid: " << id << " ,name: " << name << " ,address: " << address << "\n\n";
	showInstructor();
	cout << endl;
	showMachines();
	cout << endl;
	showTrainees();
	if (license && license->getIsValid())
		cout << "\nStatus license is valid\n" << endl;
	else
		cout << "\nStatus license is invalid\n" << endl;
}
