/**********************************************************
* Programmer: Marco R. Ares                               *
* Class: Computer Science 122, Summer 2018                *
* Programming Assignment: Fitbit                          *
* Date Started: June 6, 2018 - Date Finished: June 8,2018 *
* Descriprion: In this assignment we are going to read    *
* someone's fitbit and then calculate the data. Then we   *
* will have to put the calculated data in a results file  *
**********************************************************/
#include "fitbit.h"

int main(int argc, char*argv)
{
	//initialize all variables
	FILE *infile = NULL;
	FILE *outfile = NULL;
	char lines[1441][60] = { { '\0' },{ '\0' } };
	int numRecords = 0;
	Sleep sleep = 0;
	//1441 was used because I chose to use 1 as a starting line in my index for seperating data
	FitbitData data[1441] = { { "", 0, 0, 0, 0, 0, 0 } }; 
	//for all the data
	int totalFloors = 0, totalSteps = 0, maxSteps = 0, valueSleepStart = 0, valueSleepEnd = 0;
	double totalCalories = 0, totalDistance = 0, avgHeart = 0;

	//opens both the files
	infile = openFile("fitbitdata.csv", "r");
	outfile = openFile("results.csv", "w");

	//reads the fitbitdat.csv using fgets
	numRecords = readFile(infile, lines);

	//places all the fitbitdata into this data
	seperateData(lines, numRecords, data);

	//calculates all the total values
	totalCalories = totalCal(numRecords, data);
	totalDistance = totalDist(numRecords, data);
	totalFloors = totalFloor(numRecords, data);
	totalSteps = totalStep(numRecords, data);

	//calculates the average heartbear
	avgHeart = computeHeart(numRecords, data);

	//calculates the max steps in a minute
	maxSteps = maxStepsinaMin(numRecords, data);

	//calculates the start max value of sleep range
	valueSleepStart = sleepStartValue(numRecords, data);

	//calculates the end max value of sleep range
	valueSleepEnd = sleepEndValue(numRecords, data);

	//prints file into results.csv
	fprintf(outfile, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");
	fprintf(outfile, "%.5f, %.5f, %d, %d, %.5f, %d, %s-%s\n", 
		totalCalories, totalDistance, totalFloors, totalSteps, 
		avgHeart, maxSteps, data[valueSleepStart].minute, data[valueSleepEnd].minute);

	//closes files
	fclose(infile);
	fclose(outfile);
	
	//displays message to inform that data was calculated
	printf( "\n" );
	printf("\t|-------------------------------------------------------------------------------------------------------|\n");
	printf("\t|                                    DATA SUCCESFULLY CALCULATED!                                       |\n");
	printf("\t|                            CHECK RESULTS IN RESULTS.CSV OR PRESS CONTINUE                             |\n");
	printf("\t|-------------------------------------------------------------------------------------------------------|\n");
	printf("\n");
	system("pause");
	system("cls");
	printf("\n");
	printf("\t|----------------------------------------FITBIT DATA RESULTS--------------------------------------------|\n");
	printf("\t|Total Calories |Total Distance |Total Floors |Total Steps |Avg Heartrate |Max Steps |Sleep             |\n");
	printf("\t|%.5f     |%.5f miles  |%d           |%d       |%.5f/24hrs|%d       |%s-%s |\n",
		totalCalories, totalDistance, totalFloors, totalSteps,
		avgHeart, maxSteps, data[valueSleepStart].minute, data[valueSleepEnd].minute);
	printf("\t|-------------------------------------------------------------------------------------------------------|\n");
	printf("\t*also check results.csv\n\n");
	return 0;
}