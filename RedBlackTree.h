#ifndef RedBlackTree_h
#define RedBlackTree_h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "Time.h"

using namespace std;

class Node
{
public:
	Node *up, *left, *right;
	int key;
	string color;
};

class RedBlackTree
{
private:
	Node sentinel;
	string upCorner, botomCorner, vertical;
	string black;
	string red;
public:
	Node *root;
	int numberOfElements;
	Time timeOfOperation;

	RedBlackTree();

	~RedBlackTree();

	void remove(Node *node);

	void loadFromFile(string name);

	void rotateLeft(Node* node);

	void rotateRight(Node* node);

	void randomFill(int quantity);

	void show(string txt1, string txt2, Node * node);

	void add(int key);

	bool isExist(int key);

	Node* search(int key);

	void eraseKey(int key);
};

#endif