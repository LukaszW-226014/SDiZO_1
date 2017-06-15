#ifndef Test_h
#define Test_h

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Array.h"
#include "List.h"
#include "Heap.h"
#include "RedBlackTree.h"
#include "Time.h"
#include "Show.h"

class Test 
{
public:
	Time timeOfOperation;
	Array * array;
	List * list;
	Heap * heap;
	RedBlackTree * rbt;
	double tmpTime;
private:
	int numberOfOperation;
	int operationCounter;
	int numberOfElement;
	
public:
	Test();
	~Test();
	void timeArray();
	void timeList();
	void timeHeap();
	void timeRedBlackTree();
};

#endif 

