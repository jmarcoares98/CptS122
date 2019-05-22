#ifndef BST_H
#define BST_H

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
class BST
{
public:
	BST(BSTNode<T, R> * newRoot = nullptr);
	~BST();

	BSTNode<T, R> * getRoot() const;

	BSTNode<T, R> *makeNode(T newEnglish, R newMorse); //making a new node for tree

	void insertTree(BSTNode<T, R> *&root, T newEnglish, R newMorse);
	R searchTree(BSTNode<T, R> *&root, T newEnglish);
	void printTree(BSTNode<T, R> * root);

private:
	BSTNode<T, R> *mpRoot;

	void burnTree(BSTNode<T, R> * pTree); //for the destructor

};

template <typename T, typename R>
BST<T, R>::BST(BSTNode<T, R> * newRoot)
{
	fstream infile("MorseTable.txt");
	T tempEng;
	R tempMorse;
	char tempSpace = '\0';

	this->mpRoot = newRoot;

	while (!infile.eof()) //reading context in file
	{
		infile.get(tempEng);
		infile.get(tempSpace); //extra space in the file
		std::getline(infile, tempMorse, '\n');
		insertTree(mpRoot, tempEng, tempMorse); // storing it in the BSTNode root
	}

	infile.close();
}

template <typename T, typename R>
BST<T, R>::~BST()
{
	burnTree(this->mpRoot);
}

template <typename T, typename R>
BSTNode<T, R> * BST<T, R>::getRoot() const
{
	return this->mpRoot;
}

template <typename T, typename R>
BSTNode<T, R> * BST<T, R>::makeNode(T newEnglish, R newMorse)
{
	BSTNode<T, R> *newNode = new BSTNode<T, R>(newEnglish, newMorse); // making a new node for tree
	return newNode;
}

//recursive and soring it into BSTNode root
template <typename T, typename R>
void BST<T, R>::insertTree(BSTNode<T, R> *&root, T newEnglish, R newMorse)
{
	if (root == nullptr)
	{
		BSTNode<T, R> *newNode = makeNode(newEnglish, newMorse);
		root = newNode;
	}
	else
	{
		if (newEnglish < root->getEnglish())
		{
			insertTree(root->getLeft(), newEnglish, newMorse);
		}
		else // going to the right side instead of the left side
		{
			insertTree(root->getRight(), newEnglish, newMorse);
		}
	}
}

//use recursion to search left and right in tree
//code contributed from github/CodySigvartson
template <typename T, typename R>
R BST<T, R>::searchTree(BSTNode<T, R> *&root, T newEnglish)
{
	R morse;

	if (root == nullptr)
	{
		cout << "Search was unsuccessful!" << endl;
		return nullptr;
	}

	if (newEnglish == root->getEnglish())
	{
		morse = root->getMorse(); //found the letter
		return morse;
	}
	else if (newEnglish < root->getEnglish()) //left
	{
		morse = searchTree(root->getLeft(), newEnglish); //recursive until the letter is found in the binary search tree
		return morse;
	}
	else //right
	{
		morse = searchTree(root->getRight(), newEnglish);
		return morse;
	}
}

//printing tree using recursion
template <typename T, typename R>
void BST<T, R>::printTree(BSTNode<T, R> * root)
{
	if (root != nullptr)
	{
		printTree(root->getLeft()); //prints the left one
		cout << root->getEnglish() << ": " << root->getMorse() << endl;
		printTree(root->getRight()); // then the right ones
	}
}

//andy's code
template <typename T, typename R>
void BST<T, R>::burnTree(BSTNode<T, R> *pTree) // help destructor function
{
	if (pTree != nullptr)
	{
		burnTree(pTree->getLeft()); // destroys all the ones on the left
		burnTree(pTree->getRight()); // and on the right
		delete pTree;
	}
}
#endif // !BST_H