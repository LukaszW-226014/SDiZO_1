#ifndef Heap_h
#define Heap_h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "Time.h"

using namespace std;

class Heap
{
public:
	int numberOfElements;
	bool isExist;
	Time timeOfOperation;
private:
	int *w;
	string upCorner, bottomCorner, vertical;
public:
	Heap();

	~Heap();

	void randomFill(int quantity);

	void loadFromFile(string name);

	void build();

	void show(string txt1, string txt2, int nodeNumber);

	bool search(int searchedNumber);

	void add(int addedNumber);

	void relocate();

	void remove(int erasedNumber);
};

#endif