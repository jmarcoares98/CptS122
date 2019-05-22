#ifndef FITBIT
#define FITBIT

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COMMA ","

typedef enum sleep
{
	NONE = 0,
	ASLEEP = 1,
	AWAKE = 2,
	REALLYAWAKE = 3
}Sleep;

typedef struct fitbit
{
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

//for the sleep range values
typedef struct range
{
	int start;
	int end;
	int max;
}Range;

FILE * openFile(char *file, char *mode);
int readFile(FILE *infile, char lines[][60]);
void seperateData(char lines[][60], int numRecords, FitbitData data[1441]);
double totalCal(int numRecords, FitbitData data[1441]);
double totalDist(int numRecords, FitbitData data[1441]);
int totalFloor(int numRecords, FitbitData data[1441]);
int totalStep(int numRecords, FitbitData data[1441]);
double computeHeart(int numRecords, FitbitData data[1441]);
int maxStepsinaMin(int numRecords, FitbitData data[1441]);
int sleepStartValue(int numRecords, FitbitData data[1441]);
int sleepEndValue(int numRecords, FitbitData data[1441]);

#endif