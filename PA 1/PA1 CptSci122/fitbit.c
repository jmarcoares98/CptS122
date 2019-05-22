#include "fitbit.h"

FILE * openFile(char *file, char *mode)
{
	FILE * infile = NULL;
	infile = fopen(file, mode);
	return infile;
}

int readFile(FILE *infile, char lines[][60])
{
	int i = 0;

	while (!feof(infile))//reads until there is no more
	{
		fgets(lines[i], 60, infile);
		i++;
	}
	
	return i;
}

void seperateData(char lines[][60], int numRecords, FitbitData data[1441])
{
	int count = 1;
	char *pToken = NULL, *pToken2 = NULL, *pCheck = NULL, *pCheck2 = NULL;
	char check[100] = "";

	while (count < numRecords)
	{
		pToken = strtok(lines[count], COMMA); 
		strcpy(data[count].minute, pToken); //minutes
		
		pToken = strtok(NULL, COMMA);
		data[count].calories = atof(pToken); //calories

		pToken = strtok(NULL, COMMA);
		data[count].distance = atof(pToken); 

		pToken = strtok(NULL, COMMA);
		data[count].floors = atoi(pToken);

		//for any missing tokens in line
		//my algorith for checking any null data
		memset(check, '\0', sizeof(check));
		pCheck = strtok(NULL, "\n");
		strncpy(check, pCheck, 1);
		check[1] = 0;
		pCheck2 = check;

		//which means that hearRate has no data
		if (strcmp(pCheck2, COMMA) == 0)
		{
			data[count].heartRate = NULL;

			pToken = strtok(pCheck, COMMA);
			data[count].steps = atoi(pToken);

			pToken = strtok(NULL, ",\n");
			if (pToken == NULL) //which means sleeplevel has no data
			{
				data[count].sleepLevel = NONE;
			}
			else
			{
				data[count].sleepLevel = atoi(pToken);
			}
		}
	
		else 
		{
			pToken = strtok(pCheck, COMMA);
			data[count].heartRate = atoi(pToken);

			pToken = strtok(NULL, COMMA);
			data[count].steps = atoi(pToken);

			pToken = strtok(NULL, ",\n");
			if (pToken == NULL)
			{
				data[count].sleepLevel = NONE;
			}
			else
			{
				data[count].sleepLevel = atoi(pToken);
			}
		}
		++count;
	}
}

double totalCal(int numRecords, FitbitData data[1441])
{
	int i = 1;
	double total = 0.0;

	while (i < numRecords)
	{
		total += data[i].calories;
		i++;
	}
	return total;
}

double totalDist(int numRecords, FitbitData data[1441])
{
	int i = 1;
	double total = 0;
	while (i < numRecords)
	{
		total += data[i].distance;
		i++;
	}

	return total;
}

int totalFloor(int numRecords, FitbitData data[1441])
{
	int i = 1;
	int total = 0;
	while (i < numRecords)
	{
		total += data[i].floors;
		i++;
	}

	return total;
}

int totalStep(int numRecords, FitbitData data[1441])
{
	int i = 1;
	int total = 0;
	while (i < numRecords)
	{
		total += data[i].steps;
		i++;
	}

	return total;
}

double computeHeart(int numRecords, FitbitData data[1441])
{
	int i = 1, count = 1;
	double total = 0;
	double avg = 0.0;
	while (i < numRecords)
	{
		total += data[i].heartRate;
		i++;
		count++;
		if (data[i].heartRate == NULL)
		{
			--count;
		}
	}

	
	avg = total / count;
	return avg;
}

int maxStepsinaMin(int numRecords, FitbitData data[1441])
{
	int i = 1;
	int maximum = 0;

	maximum = data[0].steps;

	for (i = 0; i < numRecords; i++)
	{
		if (data[i].steps > maximum)
		{
			maximum = data[i].steps;
		}
	}

	return maximum;
}

int sleepStartValue(int numRecords, FitbitData data[1441])
{
	int start = 0;
	int i = 1, k = 0, l = 0, level = 0, max = 0;
	Range range[20] = { {0,0,0} };

	for (; i < numRecords; i++)
	{
		if (data[i].sleepLevel > ASLEEP)
		{
			range[k].start += i; //records the start of the sleep level

			for (; i < numRecords; i++)
			{
				range[k].max += 1;
				if (data[i].sleepLevel == ASLEEP)
				{
					k++;
					break;
				}
			}
		}

	}

	max = range[0].max;

	for (l = 0; l < 20; l++)
	{
		if (range[l].max > max)
		{
			max = range[l].max;
			start = range[l].start;
		}
	}


	return start;
}

int sleepEndValue(int numRecords, FitbitData data[1441])
{
	int end = 0;
	int i = 1, k = 0, l = 0, level = 0, max = 0;
	Range range[20] = { { 0,0,0 } };

	for (; i < numRecords; i++)
	{
		if (data[i].sleepLevel > ASLEEP)
		{ 
			for (; i < numRecords; i++)
			{
				range[k].max += 1;
				if (data[i].sleepLevel == ASLEEP)
				{
					range[k].end += (i - 1);
					k++;
					break;
				}
			}
		}

	}
	max = range[0].max;

	for (l = 0; l < 20; l++)
	{
		if (range[l].max > max)
		{
			max = range[l].max;
			end = range[l].end;
		}
	}


	return end;
}
