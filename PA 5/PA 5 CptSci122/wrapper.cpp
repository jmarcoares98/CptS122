#include "wrapper.h"
#include "list.h"

int Menu::displayMenu()
{
	int select = 0;
	cout << "Main Menu" << endl;
	cout << "(1) Import Course List" << endl;
	cout << "(2) Load Master List" << endl;
	cout << "(3) Store Master List" << endl;
	cout << "(4) Mark Absences" << endl;
	cout << "(5) Generate Report" << endl;
	cout << "(6) Exit" << endl;
	cout << "SELECT: ";
	cin >> select;
	system("cls");

	return select;
}

void Menu::runApp()
{
	int option = 0;
	bool exit = false, success = false;
	List *pHead = nullptr;

	cout << "WELCOME TO THE ABSENT TRACKER!!!" << endl;
	system("pause");
	system("cls");

	do 
	{
		option = displayMenu();

		switch (option)
		{
		case 1:
			success = importRecords();
			if (success == false)
			{
				cout << "IT WAS NOT SUCCESSFUL" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "IMPORT SUCCESSFUL" << endl;
				system("pause");
				system("cls");
			}
			break;

		case 2:
			success = loadMasterList();
			if (success == false)
			{
				cout << "IT WAS NOT SUCCESSFUL" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "LOAD SUCCESSFUL" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 3:
			success = storeMasterList();
			if (success == false)
			{
				cout << "IT WAS NOT SUCCESSFUL" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "STORE SUCCESSFUL" << endl;
				system("pause");
				system("cls");
			}
			break;

		case 4:
			markAbsences();
			system("pause");
			system("cls");
			break;

		case 5:
			generateReports();
			system("pause");
			system("cls");
			break;

		case 6:
			cout << "GOODBYE!" << endl;
			system("pause");
			system("cls");

			exit = true;
			break;
		}

	} while (exit == false);
}

bool Menu::importRecords()
{
	List *pList = nullptr;
	Node * pMem = nullptr;
	Node *mNext = nullptr;
	string stringRecord = "", stringID = "";
	string name = "", email = "", units = "", major = "", level = "";
	bool success = false;
	fstream courseList("classList.csv");

	if (courseList.is_open())
	{
		success = true;
		for (int counter = 0; counter < 11; counter++)
		{
			if (counter == 0)
			{
				std::getline(courseList, stringRecord, ',');
				std::getline(courseList, stringID, ',');
				std::getline(courseList, name, ',');
				std::getline(courseList, email, ',');
				std::getline(courseList, units, ',');
				std::getline(courseList, major, ',');
				std::getline(courseList, level, '\n');
			}
			else
			{
				pMem = new Node;
				courseList >> *pMem;
				pMem->setNext(mpHead);
				mpHead = pMem;
			}
		}
	}

	courseList.close();
	return success;
}

bool Menu::storeMasterList()
{
	bool success = false;
	Node * pMem = nullptr;
	Node *mNext = nullptr;

	pMem = this->mpHead;

	fstream masterList("master.txt");

	if (masterList.is_open())
	{
		success = true;

		masterList << "Record,ID,Name,Email,Units,Program,Level, Date Absent, Number of Absences" << endl;
		for (int count = 0; count < 10; count++)
		{
			masterList << *pMem;
			pMem = pMem->getNext();
		}
	}

	return success;
}

bool Menu::loadMasterList()
{
	bool success = false;

	string stringRecord = "", stringID = "", extra = "", extra2 = "";
	string name = "", email = "", units = "", major = "", level = "", absences = "", numAbsences = "";
	string notAbsent = "", notAbsent2 = "";
	int record = 0, ID = 0, num = 0;

	Node * pMem = nullptr;
	pMem = this->mpHead;

	fstream masterList("master.txt");

	if (masterList.is_open())
	{
		success = true;
		for (int count = 0; count < 11; count++)
		{
			if (count == 0)
			{
				std::getline(masterList, stringRecord, ',');
				std::getline(masterList, stringID, ',');
				std::getline(masterList, name, ',');
				std::getline(masterList, email, ',');
				std::getline(masterList, units, ',');
				std::getline(masterList, major, ',');
				std::getline(masterList, level, ',');
				std::getline(masterList, absences, ',');
				std::getline(masterList, numAbsences, '\n');
			}

			else
			{
				std::getline(masterList, stringRecord, ',');
				std::getline(masterList, stringID, ',');
				std::getline(masterList, extra, '"');
				std::getline(masterList, name, '"');
				std::getline(masterList, extra2, ',');
				std::getline(masterList, email, ',');
				std::getline(masterList, units, ',');
				std::getline(masterList, major, ',');
				std::getline(masterList, level, ',');
				std::getline(masterList, absences, ',');
				std::getline(masterList, numAbsences, '\n');

				record = std::stoi(stringRecord);
				ID = std::stoi(stringID);
				num = std::stoi(numAbsences);

				pMem->setRecord(record);
				pMem->setID(ID);
				pMem->setName(name);
				pMem->setEmail(email);
				pMem->setUnits(units);
				pMem->setMajor(major);
				pMem->setLevel(level);
				pMem->setAbsences(absences);
				pMem->setNumAbsences(num);

				pMem = pMem->getNext();
			}
		}
	}

	masterList.close();
	return success;
}

void Menu::markAbsences()
{
	int choose = 0;
	int numAbsent = 0;
	string date = "";
	Node * pMem = nullptr;
	Stack * pDate = nullptr;

	pDate = this->mDate;
	pMem = this->mpHead;

	time_t t = time(0);   
	struct tm * now = localtime(&t);
	char buffer[80];

	strftime(buffer, sizeof(buffer), "%m-%d-%Y", now);

	date = buffer;

	for (int count = 0; count < 10; count++)
	{
		cout << pMem->getName() << endl;
		cout << "Mark as Absent?" << endl;
		cout << "(1) Yes" << endl;
		cout << "(2) No" << endl;
		cout << "Select(num): ";
		cin >> choose;

		if (choose == 1)
		{
			cout << "Marked as Absent" << endl;
			pMem->setAbsences(date);
			numAbsent = pMem->getNumAbsences();
			numAbsent += 1;
			pMem->setNumAbsences(numAbsent);
			pDate[count].push(date);
			pMem = pMem->getNext();
		}
		else if (choose == 2)
		{
			pMem = pMem->getNext();
		}
		else
		{
			cout << "INVALID INPUT" << endl;
			count--;
		}
		system("pause");
		system("cls");
	}
}

void Menu::generateReports() 
{
	time_t t = time(0);
	struct tm * now = localtime(&t);
	string date = "";
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%m-%d-%Y", now);
	date = buffer;

	Node * pMem = nullptr;
	Stack * pDate = nullptr;

	pDate = this->mDate;
	pMem = this->mpHead;

	int choose = 0, num = 0;

	cout << "(1) Report For All Students" << endl;
	cout << "(2) Report Students with Absences" << endl;
	cout << "Select(num): ";
	cin >> choose;

	if (choose == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			if (pMem->getNumAbsences() > 0)
			{
				cout << "Most Recent Date for Absences" << endl;
				cout << pDate[0].peek(date) << endl;
				break;
			}
		}

		for (int count = 0; count < 11; count++)
		{
			cout << pMem->getName() << " - " << "Number of Absents: " << pMem->getNumAbsences()
				<< "- Date Absent: " << pMem->getAbsences() << endl;
			pMem = pMem->getNext();
		}
	}
	else if (choose == 2)
	{
		cout << "Enter Number of Absences: ";
		cin >> num;

		cout << "Students:" << endl;
		for (int i = 0; i < 10; i++)
		{
			if (num == pMem->getNumAbsences())
			{
				cout << pMem->getName() << endl;
			}

			pMem = pMem->getNext();
		}
	}
	else
	{
		cout << "INVALID INPUT!" << endl;
	}
	system("pause");
	system("cls");
}