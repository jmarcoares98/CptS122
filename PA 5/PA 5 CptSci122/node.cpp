#include "node.h"

//functions for Node class
Node::Node()
{
	mRecord = 0;
	mID = 0;
	mName = "";
	mUnits = "";
	mMajor = "";
	mLevel = "";
	mDateAbsences = "";
	mNumAbsences = 0;
	mNext = nullptr;
}

//getters
int Node::getRecord()
{
	return this->mRecord;
}

int Node::getID()
{
	return this->mID;
}

string Node::getName()
{
	return this->mName;
}

string Node::getEmail()
{
	return this->mEmail;
}

string Node::getUnits()
{
	return this->mUnits;
}

string Node::getMajor()
{
	return this->mMajor;
}

string Node::getLevel()
{
	return this->mLevel;
}

Node *& Node::getNext()
{
	return this->mNext;
}

string Node::getAbsences()
{
	return this->mDateAbsences;
}
int Node::getNumAbsences()
{
	return this->mNumAbsences;
}

//setters
void Node::setRecord(int newRecord)
{
	this->mRecord = newRecord;
}

void Node::setID(int newID)
{
	this->mID = newID;
}

void Node::setName(string newName)
{
	this->mName = newName;
}

void Node::setEmail(string newEmail)
{
	this->mEmail = newEmail;
}

void Node::setUnits(string newUnits)
{
	this->mUnits = newUnits;
}

void Node::setMajor(string newMajor)
{
	this->mMajor = newMajor;
}

void Node::setLevel(string newLevel)
{
	this->mLevel = newLevel;
}

void Node::setNext(Node * const pNext)
{
	this->mNext = pNext;
}

void Node::setAbsences(string newAbsences)
{
	this->mDateAbsences = newAbsences;
}

void Node::setNumAbsences(int newNum)
{
	this->mNumAbsences = newNum;
}


void Node::insertNode(Node *p)
{
	p->mNext = this->mNext;
	this->mNext = p;
}

//funtctions for class Stack
Stack::Stack()
{
	this->mpTop = -1;
}

Stack::~Stack()
{
	//do not have to do anything
}

void Stack::push(string newDate)
{
	mpTop++;
	date[mpTop] = newDate;
}

void Stack::pop(string newDate)
{
	newDate = date[mpTop];
	mpTop--;
}

string Stack::peek(string newDate)
{
	string returnDate;

	returnDate = newDate;

	return returnDate;
}

bool Stack::isEmpty(string newDate)
{ 
	bool success = false;
	if (newDate == "")
	{
		cout << "Stack is Empty!" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		success = true;
	}

	return success;
}

//stream operators functions
ostream & operator << (ostream &lhs, Node &rhs)
{
	lhs << rhs.getRecord() << endl;
	lhs << rhs.getID() << endl;
	lhs << rhs.getName() << endl;
	lhs << rhs.getEmail() << endl;
	lhs << rhs.getUnits() << endl;
	lhs << rhs.getMajor() << endl;
	lhs << rhs.getLevel() << endl;

	return lhs;
}


fstream & operator >> (fstream &lhs, Node &rhs)
{
	string stringRecord = "", stringID = "";
	string name = "", email = "", units = "", major = "", level = "", extra = "", extra2 = "";
	int record = 0, ID = 0;

	std::getline(lhs, stringRecord, ',');
	std::getline(lhs, stringID, ',');
	std::getline(lhs, extra, '"'); //for the extra quotaion;
	std::getline(lhs, name, '"');
	std::getline(lhs, extra2, ',');
	std::getline(lhs, email, ',');
	std::getline(lhs, units, ',');
	std::getline(lhs, major, ',');
	std::getline(lhs, level, '\n');

	record = std::stoi(stringRecord);
	ID = std::stoi(stringID);

	rhs.setRecord(record);
	rhs.setID(ID);
	rhs.setName(name);
	rhs.setEmail(email);
	rhs.setUnits(units);
	rhs.setMajor(major);
	rhs.setLevel(level);

	return lhs;
}

fstream & operator << (fstream &lhs, Node &rhs)
{
	lhs << rhs.getRecord() << ",";
	lhs << rhs.getID() << ",";
	lhs << "\"" << rhs.getName() << "\"" << ",";
	lhs << rhs.getEmail() << ",";
	lhs << rhs.getUnits() << ",";
	lhs << rhs.getMajor() << ",";
	lhs << rhs.getLevel() << ",";
	lhs << rhs.getAbsences() << ",";
	lhs << rhs.getNumAbsences() << endl;

	return lhs;
}