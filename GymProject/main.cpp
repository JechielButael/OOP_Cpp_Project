#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include "main.h"

using namespace std;

int main()
{
	int option;
	int stop = 0;

	//getting gym's only static instance (singleton)
	Gym* gym = Gym::getInstance();

	Trainee* trainee = NULL;
	ExerciseMachine* machine = NULL;
	Instructor* instructor = NULL;
	GymLicense* gymLicense = NULL;

	//menu options
	do
	{
		option = menu();
		switch (option)
		{
		case eSetMaxTraineesGym:
		{
			int num = initMaxNumOfTrainees();
			if (num >= 0)
				gym->setTraineeNum(num);
			else
				cout << "Invalid number\n\n";
			break;
		}

		case eAddTrainee:
		{
			trainee = initTrainee();
			gym->addTrainee(trainee);
			break;
		}

		case eAddInstructor:
		{
			if (gym->getInstructor() == NULL)
			{
				instructor = initInstructor();
				gym->setInstructor(instructor);
			}
			else
				cout << "The Gym already has an instructor\n\n";
			break;
		}

		case eAddMachineExercise:
		{
			machine = initMachine();
			gym->addMachine(machine);
			break;
		}

		case ePrintTrainees:
		{
			gym->showTrainees();
			break;
		}

		case eSetGymLicense:
		{
			gymLicense = initGymLicense();
			if (gymLicense)
				gym->setGymLicense(gymLicense);
			break;
		}

		case ePrintExerciseMachine:
		{
			gym->showMachines();
			break;
		}

		case ePrintGym:
		{
			gym->show();
			break;
		}

		case -1:
		{
			printf("Bye bye\n\n");
			stop = 1;
			break;
		}

		default:
			printf("Wrong choice\n\n");
			break;
		}
	} while (!stop);

	return 0;
}

int menu()
{
	int option;
	printf("Please choose one of the following options\n\n");
	for (int i = 0; i < eNofOptions; i++)
		cout << i << "-" << options[i] << "\n";
	cout << "-1 -" << "Quit\n";
	cin >> option;
	return option;
}

//Gym* initGym()
//{
//	/*int id, maxMachines, maxTrainees;
//	char name[MAX_LEN], address[MAX_LEN];
//
//	cout << "Enter Gym name:\n";
//	cin >> name;
//
//	cout << "Enter Gym address:\n";
//	cin >> address;
//
//	cout << "Enter Gym id:\n";
//	cin >> id;
//
//	cout << "Enter number of max machines:\n";
//	cin >> maxMachines;
//
//	cout << "Enter number of max trainees:\n";
//	cin >> maxTrainees;
//
//	return new Gym(id, name, address, maxMachines, 0, maxTrainees, 0);*/
//	return new Gym(12345, "Holmes Place", "20 Menahem Begin", 6, 15);
//}


//All inits:

int initMaxNumOfTrainees()
{
	int num;
	cout << "Enter new max num" << endl;
	cin >> num;

	return num;
}

Trainee* initTrainee()
{
	string name, lastName;
	int phoneNumber, favorite;

	cout << "Enter name:\n";
	cleanBuffer();
	getline(cin, name);

	cout << "Enter last name:\n";
	getline(cin, lastName);

	cout << "Enter phone number:\n";
	cin >> phoneNumber;

	Date* dateOfBirth = initDate();
	favorite = pickFavoriteMachine();

	return new Trainee(Person(name, lastName, phoneNumber, *dateOfBirth), (ExerciseMachine::eName)favorite);
}

Employee* initEmployee()
{
	string name, lastName;
	int phoneNumber;
	double salary;

	cout << "Enter name:\n";
	getline(cin, name);

	cout << "Enter last name:\n";
	getline(cin, lastName);

	cout << "Enter phone number:\n";
	cin >> phoneNumber;

	cout << "Enter salary:\n";
	cin >> salary;

	Date* dateOfBirth = initDate();

	return new Employee(Person(name, lastName, phoneNumber, *dateOfBirth), salary);
}

int pickFavoriteMachine()
{
	int fav;
	cout << "Enter type machine\n0-Bicycle, 1- Rowing-machine, 2-Leg-press, 3-Lat-pulldown, 4-Chest-press\n";
	cin >> fav;
	return fav;
}

ExerciseMachine* initMachine()
{
	int type, id, maintenancesNum;
	double weight;
	LinkedList<Date> arr;
	Date* temp;
	type = pickFavoriteMachine();

	cout << "Enter serial number of machine:\n";
	cin >> id;

	cout << "Enter weight of machine:\n";
	cin >> weight;

	cout << "Enter number of maintenance dates for the machine:\n";
	cin >> maintenancesNum;

	if (maintenancesNum > 0)
	{
		for (int i = 0; i < maintenancesNum; i++)
		{
			cout << "Add maintenance date " << maintenancesNum << " :\n";
			temp = initDate();
			arr.push_back(*temp);
		}
	}
	return new ExerciseMachine(id, (ExerciseMachine::eName)type, weight, maintenancesNum, arr);
}

Date* initDate()
{
	int day;
	int month;
	int year;
	cout << "Enter Date:\n";

	do
	{
		cout << "Enter day (must be between 1-31):\n";
		cin >> day;
	} while (day < 0 || day > 31);
	
	do
	{
		cout << "Enter month (must be between 1-12):\n";
		cin >> month;
	} while (month < 0 || month > 12);

	do
	{
		cout << "Enter year (must be between 1900-2030):\n";
		cin >> year;
	} while (year < 1900 || year > 2030);

	return new Date(day, month, year);
}

Instructor* initInstructor()
{
	Trainee* t = initTrainee();

	double salary;
	cout << "Enter salary:\n";
	cin >> salary;

	string name, lastName;
	int phoneNumber = t->getPhoneNumber();
	Date d = t->getDateOfBirth();

	name = t->getName();
	lastName = t->getFamilyName();

	Employee* e = new Employee(Person(name, lastName, phoneNumber, d), salary);

	int numOfExp;
	cout << "Enter number of experience:\n";
	cin >> numOfExp;

	return new Instructor(*t, *e, numOfExp);
}

GymLicense* initGymLicense()
{
	int numOfEmergencySigns, numOfDefibrilators;

	cout << "Edit fire Department License:\n";
	cout << "Enter the number of emergency signs:\n";
	cin >> numOfEmergencySigns;

	cout << "Edit ministry Of Health License:\n";
	cout << "Enter the number of defibrilators:\n";
	cin >> numOfDefibrilators;

	if (numOfEmergencySigns >= 0 && numOfDefibrilators >= 0)
		return new GymLicense(*(new MinistryOfHealthLicense(numOfDefibrilators)),
			*(new FireDepartmentLicense(numOfEmergencySigns)));
	else
	{
		cout << "Invalid inputs\n\n";
		return NULL;
	}
}

void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}
