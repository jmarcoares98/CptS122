#ifndef BSTNODE_H
#define BSTNODE_H

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
class BSTNode
{
public:
	//constructor
	BSTNode(T newEnglish, R newMorse);

	//doesnt need a destructor

	//getters
	T getEnglish();
	R getMorse();
	BSTNode<T, R> *& getLeft();
	BSTNode<T, R> *& getRight();

	//setters
	void setEnglish(T newEnglish);
	void setMorse(R newMorse);
	void setLeft(BSTNode<T, R> * newLeft);
	void setRight(BSTNode<T, R> * newRight);

private:
	T mEnglish; //english characters
	R mMorse; //morse symbols
	BSTNode<T, R> * mpLeft;
	BSTNode<T, R> * mpRight;
};

template <typename T, typename R>
BSTNode<T, R>::BSTNode(T newEnglish, R newMorse)
{
	mEnglish = newEnglish;
	mMorse = newMorse;
	mpLeft = mpRight = nullptr;
}

template <typename T, typename R>
T BSTNode<T, R>::getEnglish()
{
	return mEnglish;
}

template <typename T, typename R>
R BSTNode<T, R>::getMorse()
{
	return mMorse;
}

template <typename T, typename R>
BSTNode<T, R> *& BSTNode<T, R>::getLeft()
{
	return mpLeft;
}

template <typename T, typename R>
BSTNode<T, R> *& BSTNode<T, R>::getRight()
{
	return mpRight;
}

template <typename T, typename R>
void BSTNode<T, R>::setEnglish(T newEnglish)
{
	mEnglish = newEnglish;
}

template <typename T, typename R>
void BSTNode<T, R>::setMorse(R newMorse)
{
	mMorse = newMorse;
}

template <typename T, typename R>
void BSTNode<T, R>::setLeft(BSTNode<T, R> * newLeft)
{
	mpLeft = newLeft;
}

template <typename T, typename R>
void BSTNode<T, R>::setRight(BSTNode<T, R> * newRight)
{
	mpRight = newRight;
}

#endif // !BSTNODE_H