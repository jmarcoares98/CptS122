//#include "BST.h"
//
//template <typename T, typename R>
//BST::BST(BSTNode * newRoot)
//{
//	fstream infile("MorseTable.txt");
//	char tempEng = '\0';
//	string tempMorse = "";
//	char tempSpace = '\0';
//
//	this->mpRoot = newRoot;
//
//	while (!infile.eof()) //reading context in file
//	{
//		infile.get(tempEng);
//		infile.get(tempSpace); //extra space in the file
//		std::getline(infile, tempMorse, '\n');
//		insertTree(mpRoot, tempEng, tempMorse); // storing it in the BSTNode root
//	}
//
//	infile.close();
//}
//
//template <typename T, typename R>
//BST::~BST()
//{
//	burnTree(this->mpRoot);
//}
//
//template <typename T, typename R>
//BSTNode * BST::getRoot() const
//{
//	return this->mpRoot;
//}
//
//template <typename T, typename R>
//BSTNode * BST::makeNode(T newEnglish, R newMorse)
//{
//	BSTNode *newNode = new BSTNode(newEnglish, newMorse); // making a new node for tree
//	return newNode;
//}
//
////recursive and soring it into BSTNode root
//template <typename T, typename R>
//void BST::insertTree(BSTNode *&root, T newEnglish, R newMorse)
//{
//	if (root == nullptr)
//	{
//		BSTNode *newNode = makeNode(newEnglish, newMorse);
//		root = newNode;
//	}
//	else
//	{
//		if (newEnglish < root->getEnglish())
//		{
//			insertTree(root->getLeft(), newEnglish, newMorse);
//		}
//		else // going to the right side instead of the left side
//		{
//			insertTree(root->getRight(), newEnglish, newMorse);
//		}
//	}
//}
//
////use recursion to search left and right in tree
////code contributed from github/CodySigvartson
//template <typename T, typename R>
//R BST::searchTree(BSTNode *&root, T newEnglish)
//{
//	R morse = "";
//
//	if (root == nullptr)
//	{
//		cout << "Search was unsuccessful!" << endl;
//		return nullptr;
//	}
//	
//	if (newEnglish == root->getEnglish())
//	{
//		morse = root->getMorse(); //found the letter
//		return morse;
//	}
//	else if (newEnglish < root->getEnglish()) //left
//	{
//		morse = searchTree(root->getLeft(), newEnglish); //recursive until the letter is found in the binary search tree
//		return morse;
//	}
//	else //right
//	{
//		morse = searchTree(root->getRight(), newEnglish);
//		return morse;
//	}
//}
//
////printing tree using recursion
//template <typename T, typename R>
//void BST::printTree(BSTNode * root)
//{
//	if (root != nullptr)
//	{
//		printTree(root->getLeft()); //prints the left one
//		cout << root->getEnglish() << ": " << root->getMorse() << endl;
//		printTree(root->getRight()); // then the right ones
//	}
//}
//
////andy's code
//template <typename T, typename R>
//void BST::burnTree(BSTNode *pTree) // help destructor function
//{
//	if (pTree != nullptr)
//	{
//		burnTree(pTree->getLeft()); // destroys all the ones on the left
//		burnTree(pTree->getRight()); // and on the right
//		delete pTree;
//	}
//}