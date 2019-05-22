#include "list.h"

//List Functions

List::List()
{
	pHead = nullptr;
}

List::~List()
{
	destroyList();
}

Node * List::getHeadPtr() const
{
	return pHead;
}

void List::setHeadPtr(Node* const pNewHead)
{
	pHead = pNewHead;
}

bool List::insertAtFront(Node * pMem)
{
	bool success = false;                   

	if (pMem != nullptr)
	{
		success = true; 
		pMem->setNext(pHead);
		pHead = pMem;
	}


	return success;
}



//destructors
void List::destroyListHelper(Node * const pMem)
{
	destroyListHelper(pHead);
	if (pMem != nullptr)
	{
		destroyListHelper(pMem->getNext());
		delete pMem;
	}
}

void List::destroyList()
{
	destroyListHelper(pHead);
}