#ifndef List_h
#define List_h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "Time.h"

using namespace std;

class listElement
{
public:
	listElement *next, *previous;
	int key;
};

class List
{
private:
	listElement *head, *tail;
public:
	int numberOfElements;
	Time timeOfOperation;
	bool isExist;
public:
	List();

	~List();

	void randomFill(int quantity);
	
	bool search(int searchedNumber);
	
	void loadFromFile(string name);
	
	void addBehindKey(int keyBehindInsert, int newKey);
	
	void addOnBegin(int newKey);
	
	void addOnEnd(int newKey);
	
	void eraseFromBegin();

	void eraseFromEnd();

	void remove(int erasedKey);
	
	void show();
};

#endif