#include "music.h"

//PA2 Functions
//main menu pops up everytime a task was finished
int mainMenu(void)
{
	int choose = 0;
	printf("MUSIC PLAYLIST \nMAIN MENU:\n");
	printf("(1)  Load\n");
	printf("(2)  Store\n");
	printf("(3)  Display\n");
	printf("(4)  Insert\n");
	printf("(5)  Delete\n");
	printf("(6)  Edit\n");
	printf("(7)  Sort\n");
	printf("(8)  Rate\n");
	printf("(9)  Play\n");
	printf("(10) Shuffle\n");
	printf("(11) Exit\n");
	printf("SELECT: ");
	scanf("%d", &choose);

	return choose;
}

FILE * openFile(char *file, char *mode)
{
	FILE * infile = NULL;
	infile = fopen(file, mode);
	return infile;
}

int readFile(FILE *infile, char lines[][70])
{
	int i = 0;

	while (!feof(infile))//reads until there is no more
	{
		fgets(lines[i], 70, infile);
		i++;
	}

	return i;
}

int seperateData(char lines[][70], Record *data, int count)
{
	int i = 0;
	char *pToken = NULL, *pCheck = NULL, *pCheck2 = NULL, *pCheck3 = NULL;
	char check[100];

	//checks for a quotation mark at the beginning
	memset(check, '\0', sizeof(check));
	pCheck = strtok(lines[count], "\n");
	strncpy(check, pCheck, 1);
	check[1] = 0;
	pCheck2 = check;

	//if it starts with a quotation mark
	if (strcmp(pCheck2, QUOTATION) == 0)
	{
		pToken = strtok(lines[count], QUOTATION);
		strcpy(data->artist, pToken);

		pToken = strtok(NULL, COMMA);
		strcpy(data->album, pToken);

		pToken = strtok(NULL, COMMA);
		strcpy(data->song, pToken);

		pToken = strtok(NULL, COMMA);
		strcpy(data->genre, pToken);

		pToken = strtok(NULL, TIME);
		data->length.minutes = atoi(pToken);

		pToken = strtok(NULL, COMMA);
		data->length.seconds = atoi(pToken);

		pToken = strtok(NULL, COMMA);
		data->played = atoi(pToken);

		pToken = strtok(NULL, ",\n");
		data->rating = atoi(pToken);
		i++;
	}

	//no quotaion mark at the start
	else
	{
		pToken = strtok(lines[count], COMMA);
		strcpy(data->artist, pToken);

		pToken = strtok(NULL, COMMA);
		strcpy(data->album, pToken);

		pToken = strtok(NULL, COMMA);
		strcpy(data->song, pToken);

		pToken = strtok(NULL, COMMA);
		strcpy(data->genre, pToken);

		pToken = strtok(NULL, TIME);
		data->length.minutes = atoi(pToken);

		pToken = strtok(NULL, COMMA);
		data->length.seconds = atoi(pToken);

		pToken = strtok(NULL, COMMA);
		data->played = atoi(pToken);

		pToken = strtok(NULL, ",\n");
		data->rating = atoi(pToken);
		i++;
	}

	return i;
}

Node * makeNode(Record item)
{
	Node *pMem = NULL;

	pMem = (Node *)malloc(sizeof(Node));

	pMem->pNext = NULL;
	pMem->pPrev = NULL; 

	//making the nodes
	strcpy(pMem->info.artist, item.artist);
	strcpy(pMem->info.album, item.album);
	strcpy(pMem->info.song, item.song);
	strcpy(pMem->info.genre, item.genre);
	pMem->info.length = item.length;
	pMem->info.played = item.played;
	pMem->info.rating = item.rating;

	return pMem;
}

//andy's code
int storeData(Node **pHead, Record item)
{
	Node *pMem = NULL;
	int success = 0;

	pMem = makeNode(item); //gets all the records in data
	if (pMem != NULL)
	{
		success = 1;

		if (*pHead == NULL)
		{
			*pHead = pMem;
		}
		else
		{
			pMem->pNext = *pHead;
			if(*pHead != NULL)
			{
				(*pHead)->pPrev = pMem;
			}
			*pHead = pMem;
		}
	}
	return success;
}

//prints out all the records
void printRecords(Node *pHead)
{
	Node *pCur = pHead;

	if (pCur != NULL)
	{
		while (pCur != NULL) //loops through all of the files
		{
			printf("Artist: %s\n", pCur->info.artist);
			printf("Album: %s\n", pCur->info.album);
			printf("Song: %s\n", pCur->info.song);
			printf("Genre: %s\n", pCur->info.genre);
			printf("Duration: %d:%d\n", pCur->info.length.minutes, pCur->info.length.seconds);
			printf("Played: %d\n", pCur->info.played);
			printf("Rating: %d/5\n\n", pCur->info.rating);
			pCur = pCur->pNext;
		}
	}
}

int printSelectedRecords(Node **pHead, char *artist, Record item)
{
	Node *pMem = makeNode(item), *pPrev = NULL,
		*pCur = *pHead;
	int exit = 0;

	if (pMem != NULL)
	{
		while (pCur != NULL)
		{

			if ((pCur != NULL) && (strcmp(artist, pCur->info.artist) == 0)) //loooking for the artist
			{
				printf("Artist: %s\n", pCur->info.artist);
				printf("Album: %s\n", pCur->info.album);
				printf("Song: %s\n", pCur->info.song);
				printf("Genre: %s\n", pCur->info.genre);
				printf("Duration: %d:%d\n", pCur->info.length.minutes, pCur->info.length.seconds);
				printf("Played: %d\n", pCur->info.played);
				printf("Rating: %d/5\n", pCur->info.rating);
				exit = 1;
			}
			if(pCur != NULL)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}
			else
			{
				printf("INVALID INPUT!\n TRY AGAIN\n");
				system("pause");
				system("cls");
				exit = 2;
				break;
			}
		}
	}
	return exit;
}

int editRecords(Node **pHead, char *artist, char *song, Record item)
{
	Node *pMem = makeNode(item), *pPrev = NULL,
		*pCur = *pHead;
	int success = 0, exit = 0, select = 0;
	char editArtist[40] = "", editSong[40] = "", editGenre[20] = "", editAlbum[40] = "\0";


	if (pMem != NULL)
	{
		
		//if they choose drake or taylor swift
		if (song != NULL)
		{
			while (pCur != NULL)
			{
				if ((pCur != NULL) &&
					(strcmp(pCur->info.song, song) == 0))
				{
					success = 1;
					printf("WHAT DO YOU WANT TO EDIT?\n");
					printf("(1) Artist\n");
					printf("(2) Album\n");
					printf("(3) Song\n");
					printf("(4) Genre\n");
					printf("Choose (num): ");
					scanf("%d", &select);

					if (select == 1)
					{
						printf("Your Edit: ");
						gets(editArtist);
						gets(editArtist);
						strcpy(pCur->info.artist, editArtist);
					}
					if (select == 2)
					{
						printf("Your Edit: ");
						gets(editAlbum);
						gets(editAlbum);
						strcpy(pCur->info.album, editAlbum);
					}
					if (select == 3)
					{
						printf("Your Edit: ");
						gets(editSong);
						gets(editSong);
						strcpy(pCur->info.song, editSong);
					}
					if (select == 4)
					{
						printf("Your Edit: ");
						gets(editGenre);
						gets(editGenre);
						strcpy(pCur->info.genre, editGenre);
					}
				}

				if (pCur != NULL)
				{
					pPrev = pCur;
					pCur = pCur->pNext;
				}
			}
		}

		pCur = *pHead;
		//other artists
		while (pCur != NULL)
		{
			if ((pCur != NULL) &&
				(strcmp(pCur->info.artist, artist) == 0))
			{
				success = 1;
				printf("WHAT DO YOU WANT TO EDIT?\n");
				printf("(1) Artist\n");
				printf("(2) Album\n");
				printf("(3) Song\n");
				printf("(4) Genre\n");
				printf("Choose (num): ");
				scanf("%d", &select);

				if (select == 1)
				{
					printf("Your Edit: ");
					gets(editArtist);
					gets(editArtist);
					strcpy(pCur->info.artist, editArtist);
				}
				if (select == 2)
				{
					printf("Your Edit: ");
					gets(editAlbum);
					gets(editAlbum);
					strcpy(pCur->info.album, editAlbum);
				}
				if (select == 3)
				{
					printf("Your Edit: ");
					gets(editSong);
					gets(editSong);
					strcpy(pCur->info.song, editSong);
				}
				if (select == 4)
				{
					printf("Your Edit: ");
					gets(editGenre);
					gets(editGenre);
					strcpy(pCur->info.genre, editGenre);
				}
			}

			if (pCur != NULL)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}
		}

	}
	return success;
}

int rateRecords(Node **pHead, char *song, Record item)
{
	Node *pMem = makeNode(item), *pPrev = NULL,
		*pCur = *pHead;
	int rate = 0, exit = 0;

	if (pMem != NULL)
	{
		while (exit != 1)
		{
			if ((pCur != NULL) &&
				(strcmp(pCur->info.song, song) == 0))
			{
				printf("HOW MUCH DO YOU WANT RATE THE SONG? (1 - 5): "); //prompts to ask for a different rating
				scanf("%d", &rate);
				pCur->info.rating = rate;
				exit = 1;
			}
			if (pCur != NULL)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}
		}
	}

}

void playRecords(Node **pHead, Record item)
{
	Node *pMem = makeNode(item), *pPrev = NULL,
		*pCur = *pHead;
	int exit = 0, play = 0, next = 0;

	if (pMem != NULL)
	{
		//basically just displays the song
		play = 1;
		while (exit != 1)
		{
			if (pCur != NULL)
			{
				printf("Song: %s\n", pCur->info.song);
				printf("Artist: %s\n", pCur->info.artist);
				printf("Album: %s\n", pCur->info.album);
				pCur->info.played++; //adds one to record's played info
				printf("NEXT SONG?\n");
				printf("(1) NEXT\n");
				printf("(2) PREVIOUS\n");
				printf("(3) EXIT\n");
				printf("Select (num): ");
				scanf("%d", &next);
				system("cls");

				switch (next)
				{
				case 1:
					pPrev = pCur;
					pCur = pCur->pNext;
					if (pCur == NULL) //breaks off if there is the next song is a null character
					{
						exit = 1;
						break;
					}
					break;
				case 2:
					pCur = pPrev;
					pPrev = pCur->pPrev;
					break;
				case 3:
					exit = 1;
					break;
				}
			}

			if (pCur == NULL) // when there is no more songs in the list
			{
				printf("The Playlist has ended\n");
				exit = 1;
			}
		}
	}
}

int exitRecords(Node **pHead, Record item, FILE *infile)
{
	Node *pMem = makeNode(item), *pPrev = NULL,
		*pCur = *pHead;
	int exit = 0;

	if (pMem != NULL)
	{
		exit = 1;
		while (pCur != NULL)
		{
			//saves it in the same file
			fprintf(infile, "%s,", pCur->info.artist);
			fprintf(infile, "%s,", pCur->info.album);
			fprintf(infile, "%s,", pCur->info.song);
			fprintf(infile, "%s,", pCur->info.genre);
			fprintf(infile, "%d:%d,", pCur->info.length.minutes, pCur->info.length.seconds);
			fprintf(infile, "%d,", pCur->info.played);
			fprintf(infile, "%d\n", pCur->info.rating);

			if (pCur != NULL)
			{
				pPrev = pCur;
				pCur = pCur->pNext;
			}
		}
	}

	return exit;
}

//PA 3 Functions
//for the inserting function
Node * makeNode2(NewRecord item)
{
	Node *pMem = NULL;

	pMem = (Node *)malloc(sizeof(Node));

	pMem->pNext = NULL;
	pMem->pPrev = NULL;

	//making the nodes
	strcpy(pMem->info.artist, item.newArtist);
	strcpy(pMem->info.album, item.newAlbum);
	strcpy(pMem->info.song, item.newSong);
	strcpy(pMem->info.genre, item.newGenre);
	pMem->info.length = item.newLength;
	pMem->info.played = item.newPlayed;
	pMem->info.rating = item.newRating;

	return pMem;
}

//inserting a new node in the list
int insertRecords(Node **pHead, NewRecord item)
{
	Node *pMem = makeNode2(item);
	int success = 1;

	pMem->pNext = *pHead;
	*pHead = pMem;

	return success;
}

//deleting a record in the list
int deleteRecords(Node **pHead, char *song)
{
	Node *pCur = *pHead, *pTemp = NULL;
	int success = 0;

	while (pCur != NULL &&
		strcmp(pCur->pNext->info.song, song) != 0)
	{
		pCur = pCur->pNext;
		if (pCur->pNext == NULL) //break so that it wont have any compiling error when comparing a null character and a string
		{
			break;
		}
	}
	
	if (pCur->pNext == NULL)
	{
		printf("SONG DOES NOT EXIST IN PLAYLIST\n");
		system("pause");
		system("cls");
		return success;
	}

	if (strcmp(pCur->pNext->info.song, song) == 0)
	{
		success = 1;
		pTemp = pCur->pNext;
		pCur->pNext = pTemp->pNext;
		free(pTemp);
	}

	return success;
}

//sorting artists in order
//code assisted from BBarters youtube video
int sortArtist(Node **pHead)
{
	Node *pPrev = *pHead, *pCur = NULL, *pTemp = (Node*)malloc(sizeof(Node));
	int success = 0;

	for (pPrev = *pHead; pPrev != NULL; pPrev = pPrev->pNext) //loop the nodes on the list
	{
		for (pCur = pPrev->pNext; pCur != NULL; pCur = pCur->pNext) 
		{
			if (strcmp(pPrev->info.artist, pCur->info.artist) > 0) //switching nodes
			{
				success = 1;
				pTemp->info = pPrev->info;
				pPrev->info = pCur->info;
				pCur->info = pTemp->info;
			}
		}
	}
	
	
	return success;
}

//sorting Albums in order
int sortAlbum(Node **pHead)
{
	Node *pPrev = *pHead, *pCur = NULL, *pTemp = (Node*)malloc(sizeof(Node));
	int success = 0;

	for (pPrev = *pHead; pPrev != NULL; pPrev = pPrev->pNext) //loop the nodes on the list
	{
		for (pCur = pPrev->pNext; pCur != NULL; pCur = pCur->pNext)
		{
			if (strcmp(pPrev->info.album, pCur->info.album) > 0) //switching nodes
			{
				success = 1;
				pTemp->info = pPrev->info;
				pPrev->info = pCur->info;
				pCur->info = pTemp->info;
			}
		}
	}


	return success;
}

//sort by rating
int sortRating(Node **pHead)
{
	Node *pPrev = *pHead, *pCur = NULL, *pTemp = (Node*)malloc(sizeof(Node));
	int success = 0;

	for (pPrev = *pHead; pPrev != NULL; pPrev = pPrev->pNext) //loop the nodes on the list
	{
		for (pCur = pPrev->pNext; pCur != NULL; pCur = pCur->pNext)
		{
			if (pPrev->info.rating > pCur->info.rating) //switching nodes
			{
				success = 1;
				pTemp->info = pPrev->info;
				pPrev->info = pCur->info;
				pCur->info = pTemp->info;
			}
		}
	}


	return success;
}

//sorting by numbers of played
int sortPlayed(Node **pHead)
{
	Node *pPrev = *pHead, *pCur = NULL, *pTemp = (Node*)malloc(sizeof(Node));
	int success = 0;

	for (pPrev = *pHead; pPrev != NULL; pPrev = pPrev->pNext) //loop the nodes on the list
	{
		for (pCur = pPrev->pNext; pCur != NULL; pCur = pCur->pNext)
		{
			if (pPrev->info.played > pCur->info.played) //switching nodes
			{
				success = 1;
				pTemp->info = pPrev->info;
				pPrev->info = pCur->info;
				pCur->info = pTemp->info;
			}
		}
	}


	return success;
}

//shuffling 
int shuffleRecords(Node **pHead, int numRecords)
{
	Node *pShuffle = *pHead;
	int success = 0, j = 0;

	success = 1;

	while(pShuffle != NULL) //puts all the records in the pointer array
	{
		j = rand() % (numRecords + 1); //shuffles it
		pShuffle->info.position = j;
		pShuffle = pShuffle->pNext;
	}

	return success;
}

void sortShuffle(Node **pHead)
{
	Node *pPrev = *pHead, *pCur = NULL, *pTemp = (Node*)malloc(sizeof(Node));

	for (pPrev = *pHead; pPrev != NULL; pPrev = pPrev->pNext) //loop the nodes on the list
	{
		for (pCur = pPrev->pNext; pCur != NULL; pCur = pCur->pNext)
		{
			if (pPrev->info.position > pCur->info.position) //switching nodes
			{
				pTemp->info = pPrev->info;
				pPrev->info = pCur->info;
				pCur->info = pTemp->info;
			}
		}
	}
}