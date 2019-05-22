#ifndef FITNESS_H
#define FITNESS_H

#include <iostream>
#include <fstream>
#include <string>

using std::cout; // we can now use cout without explicitly writing std::cout
using std::cin;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::fstream;
using std::endl;
using std::string;

class DietPlan
{
public:
	//constructors
	DietPlan(int calories = 0,
		string newDietName = "",
		string newDietDate = "");
	//copy constructor
	DietPlan(DietPlan &copyDietPlan);
	//destructor
	~DietPlan();

	//getters
	int getCalories();
	string getDietName();
	string getDietDate();

	//setters
	void setCalories(int calories);
	void setDietName(string newDietName);
	void setDietDate(string newDietDate);

private:
	int mCalories;
	string mDietName;
	string mDietDate;
};

class ExercisePlan
{
public:
	ExercisePlan(int steps = 0,
		string newExerciseName = "",
		string newExerciseDate = "");
	ExercisePlan(ExercisePlan &copyExercisePlan);
	~ExercisePlan();

	int getSteps();
	string getExerciseName();
	string getExerciseDate();

	void setSteps(int newSteps);
	void setExerciseName(string newExerciseName);
	void setExerciseDate(string newExerciseDate);


private:
	int mSteps;
	string mExerciseName;
	string mExerciseDate;
};

fstream & operator >> (fstream &lhs, DietPlan &rhs);
ostream & operator << (ostream &lhs, DietPlan &rhs);
fstream & operator << (fstream &lhs, DietPlan &rhs);

fstream & operator >> (fstream &lhs, ExercisePlan &rhs);
ostream & operator << (ostream &lhs, ExercisePlan &rhs);
fstream & operator << (fstream &lhs, ExercisePlan &rhs);

#endif // !FITNESS_H