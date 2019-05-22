#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using std::cout; // we can now use cout without explicitly writing std::cout
using std::cin;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::fstream;
using std::endl;
using std::string;

class Node
{
public:
	//constructors
	Node();

	//getters
	int getRecord();
	int getID();
	string getName();
	string getEmail();
	string getUnits();
	string getMajor();
	string getLevel();
	string getAbsences();
	int getNumAbsences();

	Node *& getNext();

	//setter
	void setRecord(int newRecord);
	void setID(int newID);
	void setName(string newName);
	void setEmail(string newEmail);
	void setUnits(string newUnits);
	void setMajor(string newMajor);
	void setLevel(string newLevel);
	void setAbsences(string newAbsences);
	void setNumAbsences(int newNum);

	void setNext(Node *newLeft);

	void insertNode(Node *p);

private:
	int mRecord;
	int mID;
	string mName;
	string mEmail;
	string mUnits;
	string mMajor;
	string mLevel;
	string mDateAbsences;
	int mNumAbsences;
	Node *mNext;
};

class Stack
{
public:
	//constructor
	Stack();

	//destructor
	~Stack();

	void push(string newDate);
	void pop(string newDate);
	string peek(string newDate);
	bool isEmpty(string newDate);

private:
	string date[12];
	int mpTop;
};

ostream & operator << (ostream &lhs, Node &rhs);
fstream & operator >> (fstream &lhs, Node &rhs); //getting lines from masterlist
fstream & operator << (fstream &lhs, Node &rhs);

#endif // !CONTAINER_H