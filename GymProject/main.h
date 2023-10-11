#ifndef __MAIN__H
#define __MAIN__H

#include "Instructor.h"
#include "Employee.h"
#include "ExerciseMachine.h"
#include "FireDepartmentLicense.h"
#include "Gym.h"
#include "GymLicense.h"
#include "MinistryOfHealthLicense.h"
#include "Person.h"
#include "Trainee.h"
#include "Date.h"
#include "LinkedList.h"

enum eMenuOptions
{
	eSetMaxTraineesGym, eAddTrainee, eAddInstructor, eAddMachineExercise, ePrintTrainees,
	eSetGymLicense, ePrintExerciseMachine, ePrintGym, eNofOptions
};

static const int MAX_LEN = 255;

const char* options[eNofOptions] = { "Change max number of trainees in a gym", "Add a trainee",
"Add an instructor", "Add an exercise machine", "Show all trainees", "Set gym license validation" ,
"Show all exercise machines", "Show gym info" };

int menu();
void cleanBuffer();
int initMaxNumOfTrainees();
//Gym* initGym();
Trainee* initTrainee();
Employee* initEmployee();
int pickFavoriteMachine();
ExerciseMachine* initMachine();
Date* initDate();
Instructor* initInstructor();
GymLicense* initGymLicense();


#endif // !__MAIN__H