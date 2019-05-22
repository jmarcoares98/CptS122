#include "fitness.h"

//functions for DietPlan class
DietPlan::DietPlan(int calories, string newDietName, string newDietDate)
{
	if (calories <= 0)
	{
		mCalories = 0;
	}
	else
	{
		mCalories = calories;
	}

	mDietName = newDietName;
	mDietDate = newDietDate;
}

DietPlan::DietPlan(DietPlan &copyDietPlan)
{
	mCalories = copyDietPlan.getCalories();
	mDietName = copyDietPlan.getDietName();
	mDietDate = copyDietPlan.getDietDate();
}

DietPlan::~DietPlan()
{
	//default destructor
}

int DietPlan::getCalories()
{
	return mCalories;
}

string DietPlan::getDietName()
{
	return mDietName;
}

string DietPlan::getDietDate()
{
	return mDietDate;
}

void DietPlan::setCalories(int calories)
{
	if (calories >= 0)
	{
		mCalories = calories;
	}
}

void DietPlan::setDietName(string newDietName)
{
	mDietName = newDietName;
}

void DietPlan::setDietDate(string newDietDate)
{
	mDietDate = newDietDate;
}

fstream & operator >> (fstream &lhs, DietPlan &rhs)
{
	string space = "";
	string strcal = "";
	string nametemp = "";
	string datetemp = "";
	int caltemp = 0;

	std::getline(lhs, nametemp);
	std::getline(lhs, strcal);
	std::getline(lhs, datetemp);
	std::getline(lhs, space); //for the extra space in the file

	caltemp = std::stoi(strcal);
	
	rhs.setCalories(caltemp);
	rhs.setDietName(nametemp);
	rhs.setDietDate(datetemp);

	return lhs;
}

ostream & operator << (ostream &lhs, DietPlan &rhs)
{
	lhs << rhs.getDietName() << endl;
	lhs << rhs.getCalories() << endl;
	lhs << rhs.getDietDate() << endl << endl;
	
	return lhs;
}

fstream & operator << (fstream &lhs, DietPlan &rhs)
{
	int newCalories = 0;
	string newDietName = "";
	string newDietDate = "";

	cout << "New Diet Name: ";
	cin >> newDietName;
	cout << "Set Calories: ";
	cin >> newCalories; 
	cout << "Set Date: ";
	cin >> newDietDate;

	DietPlan(newCalories, newDietName, newDietDate);

	lhs << rhs.getDietName() << endl;
	lhs << rhs.getCalories() << endl;
	lhs << rhs.getDietDate() << endl;

	return lhs;
}


//Functions for ExercisePlan class
ExercisePlan::ExercisePlan(int steps, string newExericseName, string newExerciseDate)
{
	if (steps <= 0)
	{
		mSteps = 0;
	}
	else
	{
		mSteps = steps;
	}

	mExerciseName = newExericseName;
	mExerciseDate = newExerciseDate;
}

ExercisePlan::ExercisePlan(ExercisePlan &copyExercisePlan)
{
	mSteps = copyExercisePlan.getSteps();
	mExerciseName = copyExercisePlan.getExerciseName();
	mExerciseDate = copyExercisePlan.getExerciseDate();
}

ExercisePlan::~ExercisePlan()
{
	//default destructor
}

int ExercisePlan::getSteps()
{
	return mSteps;
}

string ExercisePlan::getExerciseName()
{
	return mExerciseName;
}

string ExercisePlan::getExerciseDate()
{
	return mExerciseDate;
}

void ExercisePlan::setSteps(int newSteps)
{
	if (newSteps >= 0)
	{
		mSteps = newSteps;
	}
}

void ExercisePlan::setExerciseName(string newExerciseName)
{
	mExerciseName = newExerciseName;
}

void ExercisePlan::setExerciseDate(string newExerciseDate)
{
	mExerciseDate = newExerciseDate;
}

fstream & operator >> (fstream &lhs, ExercisePlan &rhs)
{
	string space = "";
	string strcal = "";
	string nametemp = "";
	string datetemp = "";
	int caltemp = 0;

	std::getline(lhs, nametemp);
	std::getline(lhs, strcal);
	std::getline(lhs, datetemp);
	std::getline(lhs, space); //for the extra space in the file

	caltemp = std::stoi(strcal);
	
	rhs.setExerciseName(nametemp);
	rhs.setSteps(caltemp);
	rhs.setExerciseDate(datetemp);

	return lhs;
}

ostream & operator << (ostream &lhs, ExercisePlan &rhs)
{
	lhs << rhs.getExerciseName() << endl;
	lhs << rhs.getSteps() << endl;
	lhs << rhs.getExerciseDate() << endl << endl;

	return lhs;
}


fstream & operator << (fstream &lhs, ExercisePlan &rhs)
{
	int newSteps = 0;
	string newExerciseName = "";
	string newExerciseDate = "";

	cout << "New Exercise Name: ";
	cin >> newExerciseName;
	cout << "Set Steps: ";
	cin >> newSteps;
	cout << "Set Date: ";
	cin >> newExerciseDate;

	ExercisePlan(newSteps, newExerciseName, newExerciseDate);

	lhs << rhs.getExerciseName() << endl;
	lhs << rhs.getSteps() << endl;
	lhs << rhs.getExerciseDate() << endl;
	lhs << endl;

	return lhs;
}