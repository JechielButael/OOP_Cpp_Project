#ifndef _EXERCISEMACHINE_H
#define _EXERCISEMACHINE_H

#include "Date.h"
#include "LinkedList.h"

class ExerciseMachine
{
public:
	enum eName { BICYCLE, ROWING_MACHINE, LEG_PRESS, LAT_PULLDOWN, CHEST_PRESS };

private:
	int id;
	eName name;
	double weight;
	int maintenancesNum;
	LinkedList<Date> maintenancesDates;

public:
	ExerciseMachine(int id, eName name, double weight, int maintenancesNum, LinkedList<Date>& maintenancesDates);

	int getId() const;
	eName getName() const;
	double getWeight() const;
	int getMaintenancesNum() const;
	LinkedList<Date>& getMaintenancesDates();
	void setWeight(const double weight);
	void setMaintenancesNum(const int num);
	void show() const;

};

#endif
