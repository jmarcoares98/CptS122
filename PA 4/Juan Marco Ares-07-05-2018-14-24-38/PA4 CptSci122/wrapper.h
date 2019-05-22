#ifndef WRAPPER_H
#define WRAPPER_H

#include "fitness.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

//blueprint for the fitness app wrapper
class FitnessAppWrapper
{
public:
	void displayMenu();
	int getMenu() const;

	//for my load files
	void loadDailyDietPlan(fstream &fileStream, DietPlan &dietPlan);
	bool loadWeeklyDietPlan(DietPlan weeklyPlan[]);
	void loadDailyExercisePlan(fstream &fileStream, ExercisePlan &exercisePlan);
	bool loadWeeklyExercisePlan(ExercisePlan weeklyPlan[]);

	//for displaying functions
	void displayDailyDietPlan(DietPlan &dietPlan);
	bool displayWeeklyDietplan(DietPlan weeklyPlan[]);
	void displayDailyExercisePlan(ExercisePlan &exercisePlan);
	bool displayWeeklyExercisePlan(ExercisePlan weeklyPlan[]);

	//for storing functions
	void storeDailyDietPlan(ostream &fileStream, DietPlan &dietPlan);
	bool storeWeeklyDietPlan(DietPlan weeklyPlan[]);
	void storeDailyExercisePlan(ostream &fileStream, ExercisePlan &exercisePlan);
	bool storeWeeklyExercisePlan(ExercisePlan weeklyPlan[]);

	//for my edit functions
	bool editDietPlan();
	bool editExercisePlan();
	int findFile();

	//for my exit function
	bool exitApp();

	//for the main thang
	void runApp();

private:
	DietPlan mDiet[7];
	ExercisePlan mExercise[7];
};

#endif // !#WRAPPER_H