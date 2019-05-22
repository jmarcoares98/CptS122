#ifndef LIST_H
#define LIST_H

#include "node.h"

#include <iostream>
#include <fstream>
#include <string>

using std::cout; // we can now use cout without explicitly writing std::cout
using std::cin;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::fstream;
using std::endl;
using std::string;


class List
{
public:
	List();
	~List();

	Node * getHeadPtr() const;
	void setHeadPtr(Node * const pNewHead); 

	bool insertAtFront(Node * pMem);

private:
	Node *pHead; 
					 
	void destroyList();                       
	void destroyListHelper(Node * pMem);
};

#endif // !LIST_H