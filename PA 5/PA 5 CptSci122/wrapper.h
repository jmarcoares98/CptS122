#ifndef TRACKER_H
#define TRACKER_H

#include "node.h"
#include "list.h"

class Menu
{
public:
	int displayMenu();
	bool importRecords();
	bool storeMasterList();
	bool loadMasterList();
	void markAbsences();
	void generateReports();

	void runApp();

private:
	Node *mpHead;
	Stack mDate[12];
};

#endif // !TRACKER_H
