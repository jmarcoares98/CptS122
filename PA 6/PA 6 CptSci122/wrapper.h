#ifndef WRAPPER_H
#define WRAPPER_H

#include "BST.h"
#include "BSTNode.h"

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

template <typename T, typename R>
class Wrapper
{
public:
	void converter(BSTNode<T, R> * root);
	void printEnglish();

	void runApp(BSTNode<T, R> * root);

};

template <typename T, typename R>
void Wrapper<T, R>::converter(BSTNode<T, R> * root)
{
	BST<char, string> bst;
	fstream infile("Convert.txt");
	string morse = "";
	char tempEng = '\0';

	while (!infile.eof())
	{
		infile.get(tempEng);
		tempEng = toupper(tempEng); //converting all lowercase to uppercase

		if (tempEng != '\n') //until new line
		{
			morse = bst.searchTree(root, tempEng);
			cout << morse << " "; //to make the morse code look more eligible
		}
		else //print a new line if it is a new line
		{
			cout << endl;
		}
	}

	cout << endl;
	infile.close();
}

template <typename T, typename R>
void Wrapper<T, R>::printEnglish()
{
	fstream infile("Convert.txt");
	string sentence = "";

	while (!infile.eof())
	{
		std::getline(infile, sentence, '\n'); //gets the sentences in the convert.txt
		cout << sentence << endl;
	}

	cout << endl;
	infile.close();
}

template <typename T, typename R>
void Wrapper<T, R>::runApp(BSTNode<T, R> * root)
{
	BST<char, string> translate; //goes into the bst constructor
	char select = '\0';
	bool exit = false;

	root = translate.getRoot(); //initializing the root from BST

	do {
		cout << "Morse Table" << endl;
		translate.printTree(root);

		cout << "Morse Code: " << endl;
		converter(root);
		cout << endl;

		//just a little fun with the PA
		cout << "Would you like to see the Original Sentence? (Y/N)" << endl << "Select: ";
		cin >> select;
		system("cls");

		if (select == 'Y' || select == 'y')
		{
			cout << "Morse Table" << endl;
			translate.printTree(root);

			cout << "Morse Code: " << endl;
			converter(root);
			cout << endl;

			cout << "Original Sentence: " << endl;
			printEnglish();
			exit = true;
		}
		else if (select == 'N' || select == 'n')
		{
			cout << "OK, Goodbye!" << endl;
			exit = true;
		}
		else
		{
			cout << "Invlaid Input!" << endl;
			system("pause");
			system("cls");
		}
	} while (exit == false);
}
#endif // !WRAPPER_H
