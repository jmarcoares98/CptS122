/*************************************************************
* Programmer: Marco R. Ares                                  *
* Class: Computer Science 122, Summer 2018                   *
* Programming Assignment: Digital Music Manager              *
* Date Started: June 20, 2018 - Date Finished: June 23, 2018 *
* Descriprion: In this assignment we are going to read       *
* a music playlist and then use the doubly linked list. We   *
* to try and sort it or categorize the songs.                *
*************************************************************/
#include "music.h"

int main()
{
	//initializing variables
	int choose = 0, exit = 0, menu = 0, success = 0, select = 0, exit2 = 0, exit3 = 0, 
		selectSong = 0, edit = 0, rate = 0, play = 0, count = 0, k = 0;
	char lines[9][70] = { '\0', '\0' };
	char artist[30] = { '\0' }, song[30] = { '\0' }, song2[30] = { '\0' };
	int numRecords = 0;
	FILE *infile = NULL;
	Record data = {"", "", "", "", 0, 0, 0 };
	Node *pNode = NULL, *pHead = NULL;

	//PA3 variables
	char *newArtist = "", newAlbum = "", newSong = "", newGenre = "";
	int newMinutes = 0, newSeconds = 0, newPlayed = 0, newRating = 0, 
		insert = 0, delete = 0, sort = 0, selectSort = 0, shuffle = 0;
	NewRecord newData = { "", "", "", "", 0, 0, 0, 0};

	while (menu != 1)
	{
		exit = 0;
		choose = mainMenu();
		system("cls");

		if (choose > 0 && choose < 12)
		{
			while (exit != 1)
			{
				switch (choose)
				{
				case 1: //load
					infile = openFile("musicPlaylist.csv", "r"); 
					numRecords = readFile(infile, lines); //reads the files
					printf("LOAD SUCCESFUL\n");
					system("pause");
					system("cls");
					exit = 1;
					break;
				case 2: //store
					for (int i = 0; i < numRecords; i++) //loops everything of the musicplaylist file into data
					{
						seperateData(lines, &data, count);
						success = storeData(&pHead, data);
						count++;
					}
					if (success == 1);
					{
						printf("STORE SUCCESSFUL\n"); //informs the user that it is now stored
					}
					system("pause");
					system("cls");
					exit = 1;
					break;
				case 3: //display
					printf("SELECT AN OPTION:\n");
					printf("(1) Print All Records\n");
					printf("(2) Print All Records Based on Artist\n");
					printf("SELECT: ");
					scanf("%d", &select);
					if (select == 1)
					{
						printRecords(pHead); //prints every record in the file
					}
					if (select == 2)
					{
						exit2 = 0;
						while (exit2 != 1) // prompts the user to select an artist and it has to be specifically the sam characters
						{
							printf("ARTIST: ");
							gets(artist);
							gets(artist);
							system("cls");
							exit2 = printSelectedRecords(&pHead, artist, data); 
						}
					}
					system("pause");
					system("cls");
					exit = 1;
					break;
				case 4: //insert
					printf("ADD A NEW SONG:\n"); //prompts user to insert a new record
					
					printf("Artist: ");
					gets(newData.newArtist);
					gets(newData.newArtist);
		
					printf("Album: ");
					gets(newData.newAlbum);
			
					printf("Song: ");
					gets(newData.newSong);
				
					printf("Genre: ");
					gets(newData.newGenre);
		
					printf("Duration (minutes): ");
					scanf("%d", &newData.newLength.minutes);
					
					printf("Duration (seconds): ");
					scanf("%d", &newData.newLength.seconds);
	
					printf("Played: ");
					scanf("%d", &newData.newPlayed);
			
					printf("Rating: ");
					scanf("%d", &newData.newRating);

					insert = insertRecords(&pHead, newData);
					if (insert == 1)
					{
						printf("SUCCESFULLY INSERTED NEW RECORD\n");
					}
					system("pause");
					system("cls");
					exit = 1;
					break;
				case 5: //delete
					delete = 0;
					while (delete != 1)
					{
						printf("DELETE A RECORD\n");
						printf("WHICH SONG: ");
						gets(song2);
						if (k == 0)
						{
							k = 1;
							gets(song2); //just for less bugs
						}
						delete = deleteRecords(&pHead, &song2);
					}
					if (delete == 1)
					{
						printf("SUCCESFULLY DELETED RECORD\n");
					}
					system("pause");
					system("cls");
					exit = 1;
					break;
				case 6: //edit
					edit = 0;
					printf("EDIT ARTIST\n"); // prompts user to select an artist
					printf("ARTIST: ");
					gets(artist);
					gets(artist);
					system("cls");
					if ((strcmp(&artist, "Drake") == 0)) // drake has multiple songs so it prompts which song
					{
						printf("CHOOSE SONG: \n");
						printf("(1) Own it\n");
						printf("(2) The Motto\n");
						printf("Song: ");
						gets(song);
						gets(song);
						system("cls");
					}
					if ((strcmp(&artist, "Taylor Swift") == 0)) //same with taylor swift
					{
						printf("CHOOSE SONG: \n");
						printf("(1) Shake it Off\n");
						printf("(2) Stay Stay Stay\n");
						printf("Song: ");
						gets(song);
						gets(song);
						system("cls");
					}
					edit = editRecords(&pHead, artist, song, data);
					if (edit == 1)
					{
						printf("EDIT COMPLETE!\n");
					}
					if (edit == 0)
					{
						printf("INVALID INPUT!\n");
					}
					system("pause");
					system("cls");
					exit = 1;
					break;
				case 7: //sort
					sort = 0;
					printf("SORT PLAYLIST: \n");
					printf("(1) Sort by Artist (A-Z)\n");
					printf("(2) Sort by Album (A-Z)\n");
					printf("(3) Sort by Rating (1-5)\n");
					printf("(4) Sort by Numbers Played (Largest - Smallest)\n");
					printf("SELECT (num): ");
					scanf("%d", &selectSort);
					if (selectSort == 1)
					{
						sort = sortArtist(&pHead);
					}
					if (selectSort == 2)
					{
						sort = sortAlbum(&pHead);
					}
					if (selectSort == 3)
					{
						sort = sortRating(&pHead);
					}
					if (selectSort == 4)
					{
						sort = sortPlayed(&pHead);
					}
					if(sort == 1)
					{
						printf("SUCCESSFULLY SORTED LIST\n");
					}
					system("pause");
					system("cls");
					exit = 1;
					break;
				case 8: //rate
					rate = 0;
					printf("RATE A SONG \n");
					printf("SONG: ");
					gets(song);
					gets(song);
					system("cls");
					rate = rateRecords(&pHead, song, data);
					if (rate == 1)
					{
						printf("RATE SUCCESFUL\n");
					}
					system("pause");
					system("cls");
					exit = 1;
					break;
				case 9: //play
					playRecords(&pHead, data);
					system("pause");
					system("cls");
					exit = 1;
					break;
				case 10: //shuffle
					shuffle = 0;
					printf("SHUFFLING LIST...\n");
					shuffle = shuffleRecords(&pHead, numRecords); //shuffles the playlist
					sortShuffle(&pHead); //this sorts out the shuffles in the list
					system("pause");
					system("cls");
					if (shuffle == 1)
					{
						printf("SUCCESSFULLY SHUFFLED PLAYLIST\n");
					}
					system("pause");
					system("cls");
					exit = 1;
					break;
				case 11: //exit
					exit3 = 0;
					//Now it can write/save at the same file
					infile = openFile("musicPlaylist.csv", "w");
					exit3 = exitRecords(&pHead, data, infile);
					if (exit3 = 1)
					{
						printf("RECORDS WERE SAVED!\n");
					}
					printf("GOODBYE!\n");
					system("pause");
					system("cls");
					exit = 1;
					menu = 1;
					break;
				}
			}
		}
		else
		{
			//if they choose the wrong number in the menu
			printf("INVALID INPUT!\n");
			printf("CHOOSE AGAIN\n");
			system("pause");
			system("cls");
		}
	}

	fclose(infile);
	return 0;
}