#include <iostream>

using namespace std;

#include "ExerciseMachine.h"

const char* machineTypes[5] = { "Bicycle", "Rowing-machine", "Leg-press", "Lat-pulldown", "Chest-press" };

ExerciseMachine::ExerciseMachine(int id, eName name, double weight, int maintenancesNum, LinkedList<Date>& maintenancesDates)
{
	this->id = id;
	this->name = name;
	this->weight = weight;
	this->maintenancesNum = maintenancesNum;
	this->maintenancesDates = maintenancesDates;
}

int ExerciseMachine::getId() const
{
	return id;
}

double ExerciseMachine::getWeight() const
{
	return weight;
}

ExerciseMachine::eName ExerciseMachine::getName() const
{
	return name;
}

void ExerciseMachine::setWeight(const double weight)
{
	this->weight = weight;
}

int ExerciseMachine::getMaintenancesNum() const
{
	return maintenancesNum;
}

void ExerciseMachine::setMaintenancesNum(const int num)
{
	this->maintenancesNum = maintenancesNum;
}

LinkedList<Date>& ExerciseMachine::getMaintenancesDates()
{
	return maintenancesDates;
}

void ExerciseMachine::show() const
{
	cout << " id = " << id << ", name = " << machineTypes[name] << ", weight = " << weight << "\n";
	cout << " maintenance dates are: \n";
	
	cout << maintenancesDates;
}