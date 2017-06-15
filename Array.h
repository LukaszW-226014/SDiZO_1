#ifndef Array_h
#define Array_h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "Time.h"

using namespace std;

class Array
{
public:
	int numberOfElements;
	Time timeOfOperation;
private:
	int *w;
public:
	Array();
	~Array();

	void randomFill(int quantity);

	void show();

	void remove(int numberID);

	void relocate();

	void eraseFromBegin();

	void eraseFromEnd();

	void addOnBegin(int addedNumber);

	void addOnEnd(int addedNumber);

	void add(int newID, int addedNumber);

	void search(int searchedNumber);

	void loadFromFile(string name);
};

#endif