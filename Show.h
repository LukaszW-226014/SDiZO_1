#ifndef Show_h
#define Show_h

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Array.h"
#include "List.h"
#include "Heap.h"
#include "RedBlackTree.h"
#include "Test.h"
#include "Time.h"

using namespace std;

class Show
{
public:
	bool goToBegin;
	Show();
	~Show();
	void switchChoice();
	void menu();
	void arrayMenu();
	void listMenu();
	void heapMenu();
	void redBlackTreeMenu();

private:
	int choice;
	int quantity;
	int value;
	int key;
	string name;
	Time timeOfOperation;
};

#endif