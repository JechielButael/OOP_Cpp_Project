#ifndef _GYM_H
#define _GYM_H

#include <string>
#include <vector>

#include "GymLicense.h"
#include "ExerciseMachine.h"
#include "Trainee.h"
#include "Instructor.h"

const int MAX_MACHINES = 20;

//Gym as facade: Gym is used as a high level interface which communicates with all subsystem classes
class Gym
{
private:
	int id;
	string name;
	string address;
	int machinesNum;
	int traineesNum;
	std::vector<ExerciseMachine> allMachines;
	std::vector<Trainee> allTrainees;
	GymLicense* license;
	Instructor* instructor;

	//Gym as singelton: in this system, there will be only 1 instance of Gym
	Gym(const int id = 12345, const string& name = "Holmes Place", const string& address = "20 Menahem Begin"
		, const int maxMachines = 6, const int maxTrainees = 15);
	static Gym theGym;

	//Gym as observer: Gym will have a viewer lists of trainees and instructors that will receive notifications
	vector<Observer*> viewers;
	void notifyAllRegistered(string str) const;


public:

	static Gym* getInstance();
	GymLicense getLicense() const;
	void setGymLicense(const GymLicense* other);
	int getId() const;
	string getAddress() const;
	string getName() const;
	int getMachineNum() const;
	int getTraineeNum() const;
	void setAddress(const std::string& address);
	void setName(const std::string& name);
	void setMachineNum(const int machineNum);
	void setTraineeNum(const int TraineeNum);
	std::vector<ExerciseMachine> getAllMachines() const;
	std::vector<Trainee> getAllTrainees() const;
	bool addTrainee(Trainee* trainee);
	Instructor* getInstructor() const;
	bool addMachine(const ExerciseMachine* machine);
	void setInstructor(Instructor* c);
	void showMachines() const;
	void showInstructor() const;
	void showTrainees() const;
	void registerObserver(Observer* obs);
	void show() const;

};

#endif
