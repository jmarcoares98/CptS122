#include "wrapper.h"

void FitnessAppWrapper::displayMenu()
{
	cout << "MAIN MENU" << endl;
	cout << "(1) Load Weekly Diet Plan" << endl;
	cout << "(2) Load Weekly Exercise Plan" << endl;
	cout << "(3) Store Weekly Diet Plan" << endl;
	cout << "(4) Store Weekly Exercise Plan" << endl;
	cout << "(5) Display Weekly Diet Plan" << endl;
	cout << "(6) Display Weekly Exercise Plan" << endl;
	cout << "(7) Edit Daily Diet Plan" << endl;
	cout << "(8) Edit Daily Exercise Plan" << endl;
	cout << "(9) Exit" << endl;
}

int FitnessAppWrapper::getMenu() const
{
	int option = 0;

	cin >> option;

	system("cls");

	return option;
}

void FitnessAppWrapper::loadDailyDietPlan(fstream &fileStream, DietPlan &dietPlan)
{
	fileStream >> dietPlan;
}

bool FitnessAppWrapper::loadWeeklyDietPlan(DietPlan weeklyPlan[])
{
	bool success = false;
	fstream mDietFile("dietPlans.txt");

	if (mDietFile.is_open())
	{
		success = true;
		for (int counter = 0; counter < 7; counter++)
		{
			loadDailyDietPlan(mDietFile, weeklyPlan[counter]);
		}
	}

	mDietFile.close();
	return success;
}

void FitnessAppWrapper::loadDailyExercisePlan(fstream &fileStream, ExercisePlan &exercisePlan)
{
	fileStream >> exercisePlan;
}

bool FitnessAppWrapper::loadWeeklyExercisePlan(ExercisePlan weeklyPlan[])
{
	bool success = false;
	fstream mExerciseFile("exercisePlans.txt");

	if (mExerciseFile.is_open())
	{
		success = true;
		for (int counter = 0; counter < 7; counter++)
		{
			loadDailyExercisePlan(mExerciseFile, weeklyPlan[counter]);
		}
	}

	mExerciseFile.close();

	return success;
}

void FitnessAppWrapper::displayDailyDietPlan(DietPlan &dietPlan)
{
	cout << dietPlan;
}

bool FitnessAppWrapper::displayWeeklyDietplan(DietPlan weeklyPlan[])
{
	int counter = 0;
	bool success = false;

	for (counter = 0; counter < 7; counter++)
	{
		displayDailyDietPlan(weeklyPlan[counter]);
		success = true;
	}
	system("pause");
	system("cls");

	return success;
}

void FitnessAppWrapper::displayDailyExercisePlan(ExercisePlan &exercisePlan)
{
	cout << exercisePlan;
}

bool FitnessAppWrapper::displayWeeklyExercisePlan(ExercisePlan weeklyPlan[])
{
	int counter = 0;
	bool success = false;

	for (counter = 0; counter < 7; counter++)
	{
		displayDailyExercisePlan(weeklyPlan[counter]);
		success = true;
	}
	system("pause");
	system("cls");

	return success;
}

void FitnessAppWrapper::storeDailyDietPlan(ostream &fileStream, DietPlan &dietPlan)
{
	fileStream << dietPlan;
}

bool FitnessAppWrapper::storeWeeklyDietPlan(DietPlan weeklyPlan[])
{
	bool success = false;

	fstream mDietFile("dietPlans.txt");

	if (mDietFile.is_open())
	{
		success = true;
		for (int count = 0; count < 7; count++)
		{
			storeDailyDietPlan(mDietFile, weeklyPlan[count]);
		}
	}
	return success;
}

void FitnessAppWrapper::storeDailyExercisePlan(ostream &fileStream, ExercisePlan &exercisePlan)
{
	fileStream << exercisePlan;
}

bool FitnessAppWrapper::storeWeeklyExercisePlan(ExercisePlan weeklyPlan[])
{
	bool success = false;

	fstream mExerciseFile("exercisePlans.txt");

	if (mExerciseFile.is_open())
	{
		success = true;
		for (int count = 0; count < 7; count++)
		{
			storeDailyExercisePlan(mExerciseFile, weeklyPlan[count]);
		}
	}
	return success;
}

int FitnessAppWrapper::findFile() //find file to edit them
{
	int findFile = 0;

	cout << "Enter File Number: ";
	cin >> findFile;

	int counter = 0;
	for (counter = 0; counter < 7; counter++)
	{
		if (counter == findFile)
		{
			break;
		}
	}

	if (counter == findFile)
	{
		cout << "File Found" << endl;
		system("cls");
	}

	else
	{
		cout << "File Was Not Found" << endl;
		system("cls");
	}

	return counter;
}

bool FitnessAppWrapper::editDietPlan()
{
	bool success = false;
	char newName[30] = "", newDate[30] = "";
	int newCalories = 0, counter = 0, option = 0;

	counter = findFile();
	counter -= 1;

	if (counter < 7)
	{
		success = true;

		cout << "(1) Edit Name" << endl;
		cout << "(2) Edit Calories" << endl;
		cout << "(3) Edit Date" << endl;
		cout << "(4) Edit All" << endl;

		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Enter Name: ";
			cin.getline(newName, sizeof(newName));
			cin.getline(newName, sizeof(newName));
			mDiet[counter].setDietName(newName);
			break;
		case 2:
			cout << "Enter Calories: ";
			cin >> newCalories;
			mDiet[counter].setCalories(newCalories);
			break;
		case 3:
			cout << "Enter Date: ";
			cin.getline(newDate, sizeof(newDate));
			cin.getline(newDate, sizeof(newDate));
			mDiet[counter].setDietDate(newDate);
			break;
		case 4:
			cout << "Enter Name: ";
			cin.getline(newName, sizeof(newName));
			cin.getline(newName, sizeof(newName));
			mDiet[counter].setDietName(newName);

			cout << "Enter Calories: ";
			cin >> newCalories;
			mDiet[counter].setCalories(newCalories);

			cout << "Enter Date: ";
			cin.getline(newDate, sizeof(newDate));
			cin.getline(newDate, sizeof(newDate));
			mDiet[counter].setDietDate(newDate);

			break;
		default:
			cout << "INVALID OPTION!!" << endl;
			break;
		}
	}

	return success;
}

bool FitnessAppWrapper::editExercisePlan()
{
	bool success = false;
	char newName[30] = "", newDate[30] = "";
	int newSteps = 0, counter = 0, option = 0;

	counter = findFile();
	counter -= 1;

	if (counter < 7)
	{
		success = true;

		cout << "(1) Edit Name" << endl;
		cout << "(2) Edit Steps" << endl;
		cout << "(3) Edit Date" << endl;
		cout << "(4) Edit All" << endl;

		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Enter Name: ";
			cin.getline(newName, sizeof(newName));
			cin.getline(newName, sizeof(newName));
			mExercise[counter].setExerciseName(newName);
			break;
		case 2:
			cout << "Enter Calories: ";
			cin >> newSteps;
			mExercise[counter].setSteps(newSteps);
			break;
		case 3:
			cout << "Enter Date: ";
			cin.getline(newDate, sizeof(newDate));
			cin.getline(newDate, sizeof(newDate));
			mExercise[counter].setExerciseDate(newDate);
			break;
		case 4:
			cout << "Enter Name: ";
			cin.getline(newName, sizeof(newName));
			cin.getline(newName, sizeof(newName));
			mExercise[counter].setExerciseName(newName);

			cout << "Enter Calories: ";
			cin >> newSteps;
			mExercise[counter].setSteps(newSteps);

			cout << "Enter Date: ";
			cin.getline(newDate, sizeof(newDate));
			cin.getline(newDate, sizeof(newDate));
			mExercise[counter].setExerciseDate(newDate);
			break;
		default:
			cout << "INVALID OPTION!!" << endl;
			break;
		}
	}

	return success;
}

bool FitnessAppWrapper::exitApp()
{
	bool success = false, dietSuccess = false, exerciseSuccess = false;

	dietSuccess = storeWeeklyDietPlan(mDiet);
	exerciseSuccess = storeWeeklyExercisePlan(mExercise);

	if ((dietSuccess == true && exerciseSuccess == true))
	{
		success = true;
	}

	return success;
}

void FitnessAppWrapper::runApp()
{
	int option = 0;
	bool exit = false, success = false;

	cout << "WELCOME TO THE FITNESS APP!!!" << endl;
	system("pause");
	system("cls");
	do
	{
		displayMenu();
		option = getMenu();

		switch (option)
		{
		case 1:
			success = loadWeeklyDietPlan(mDiet);
			if (success == false)
			{
				cout << "IT WAS NOT SUCCESSFUL!" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "LOAD SUCCESFUL" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 2:
			success = loadWeeklyExercisePlan(mExercise);
			if (success == false)
			{
				cout << "IT WAS NOT SUCCESSFUL!" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "LOAD SUCCESFUL" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 3:
			success = storeWeeklyDietPlan(mDiet);
			if (success == false)
			{
				cout << "IT WAS NOT SUCCESSFUL!" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "STORE SUCCESFUL" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 4:
			success = storeWeeklyExercisePlan(mExercise);
			if (success == false)
			{
				cout << "IT WAS NOT SUCCESFUL!" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "STORE SUCCESFUL" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 5:
			success = displayWeeklyDietplan(mDiet);
			if (success == false)
			{
				cout << "IT WAS NOT SUCCESSFUL!" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 6:
			success = displayWeeklyExercisePlan(mExercise);
			if (success == false)
			{
				cout << "IT WAS NOT SUCCESSFUL!" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 7:
			success = editDietPlan();
			if (success == false)
			{
				cout << "IT WAS NOT SUCCESFUL" << endl;
				system("cls");
			}
			else
			{
				cout << "EDIT SUCCESFUL" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 8:
			success = editExercisePlan();
			if (success == false)
			{
				cout << "IT WAS NOT SUCCESSFUL" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "EDIT SUCCESFUL" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 9:
			success = exitApp();
			if (success == false)
			{
				cout << "FILE WAS NOT SAVED" << endl;
				system("pause");
				system("cls");
			}
			cout << "FILE SAVED" << endl;
			system("pause");
			system("cls");
			exit = true;
			break;
		}
	} while (exit == false);
}