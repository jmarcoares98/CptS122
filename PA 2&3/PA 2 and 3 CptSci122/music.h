#ifndef MUSIC_H
#define MUSIC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUOTATION "\""
#define COMMA ","
#define TIME ":"

typedef struct duration
{
	int minutes;
	int seconds;
}Duration;

typedef struct record
{
	char artist[20];
	char album[30];
	char song[30];
	char genre[15];
	Duration length;
	int played;
	int rating;
	int position;
}Record;

typedef struct node
{
	Record info;
	struct node *pNext; 
	struct node *pPrev;
} Node;

//PA3 for inserting new records in the list
typedef struct newrecord
{
	char newArtist[20];
	char newAlbum[30];
	char newSong[30];
	char newGenre[15];
	Duration newLength;
	int newPlayed;
	int newRating;
	int position;
}NewRecord;

//PA 2 function headers
int mainMenu(void);
FILE * openFile(char *file, char *mode);
int readFile(FILE *infile, char lines[][70]);
int seperateData(char lines[][70], Record *data, int count);
Node * makeNode(Record item);
int storeData(Node **pHead, Record item); //my insertFront() function
void printRecords(Node *pHead);
int printSelectedRecords(Node **pHead, char *artist, Record item);
int editRecords(Node **pHead, char *artist, char *song, Record item);
int rateRecords(Node **pHead, char *song, Record item);
void playRecords(Node **pHead, Record item);
int exitRecords(Node **pHead, Record item, FILE *infile);

//PA 3 function headers
Node * makeNode2(NewRecord item);
int insertRecords(Node **pHead, NewRecord item);
int deleteRecords(Node **pHead, char *song);
int sortArtist(Node **pHead);
int sortAlbum(Node **pHead);
int sortRating(Node **pHead);
int sortPlayed(Node **pHead);
int shuffleRecords(Node **pHead, int numRecords);
void sortShuffle(Node **pHead);

#endif // !MUSIC_H