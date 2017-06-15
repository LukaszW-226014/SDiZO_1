#include "Test.h"

Test::Test() {
	numberOfOperation = 200;
	numberOfElement = 10000;
	tmpTime = 0;
	array = new Array();
	list = new List();
	heap = new Heap();
	rbt = new RedBlackTree();
	timeArray();
	//timeList();
	//timeHeap();
	//timeRedBlackTree();
}

Test::~Test() {
}

void Test::timeArray()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "+++++++++++++++++++++++++++++++++++++++++++| Tablica |+++++++++++++++++++++++++++++++++++++++++++" << endl;
	srand((int)time(NULL));
	array->randomFill(numberOfElement);
	

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		array->search((rand() % 2000) - 1000);
		tmpTime += array->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Wyszukiwanie: "<< tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);
	
	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		array->add(rand() % array->numberOfElements, (rand() % 2000) - 1000);
		tmpTime += array->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Dodawanie :" << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);
	
	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		array->remove(rand() % array->numberOfElements-1);
		tmpTime += array->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Usuwanie: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		array->addOnBegin((rand() % 2000) - 1000);
		tmpTime += array->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Dodawanie na poczatku: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		array->addOnEnd((rand() % 2000) - 1000);
		tmpTime += array->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Dodawanie na koncu: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		array->eraseFromBegin();
		tmpTime += array->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Usuwanie z poczatku: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		array->eraseFromEnd();
		tmpTime += array->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Usuwanie z konca: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);
	Show * show = new Show();
}

void Test::timeList()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "+++++++++++++++++++++++++++++++++++++++++++| Lista |+++++++++++++++++++++++++++++++++++++++++++" << endl;
	srand((int)time(NULL));
	list->randomFill(numberOfElement);

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		list->search((rand() % 2000) - 1000);
		tmpTime += list->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Wyszukiwanie: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		list->addBehindKey(rand() % list->numberOfElements, (rand() % 2000) - 1000);
		tmpTime += list->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Dodawanie los: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		list->remove((rand() % 2000) - 1000);
		tmpTime += list->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Usuwanie: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		list->addOnBegin((rand() % 2000) - 1000);
		tmpTime += list->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Dodawanie na poczatku: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		list->addOnEnd((rand() % 2000) - 1000);
		tmpTime += list->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Dodawanie na koniec: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		list->eraseFromBegin();
		tmpTime += list->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Usuwanie z poczatku: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		list->eraseFromEnd();
		tmpTime += list->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Usuwanie z konca: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);
}

void Test::timeHeap()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "+++++++++++++++++++++++++++++++++++++++++++| Kopiec |+++++++++++++++++++++++++++++++++++++++++++" << endl;
	srand((int)time(NULL));
	heap->randomFill(numberOfElement);

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		heap->search((rand() % 2000) - 1000);
		tmpTime += heap->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Wyszukiwanie: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		heap->add((rand() % 2000) - 1000);
		tmpTime += heap->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Dodawanie: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		heap->remove((rand() % 2000) - 1000);
		tmpTime += heap->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Usuwanie: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);
	system("pause");
	exit(0);
}

void Test::timeRedBlackTree()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "+++++++++++++++++++++++++++++++++++++++++++| Drzewo czerwono-czarne |+++++++++++++++++++++++++++++++++++++++++++" << endl;
	srand((int)time(NULL));
	rbt->randomFill(numberOfElement);
	system("cls");

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		rbt->search((rand() % 2000) - 1000);
		tmpTime += rbt->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Wyszukiwanie: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);

	operationCounter = 0;
	tmpTime = 0;
	while (operationCounter < numberOfOperation)
	{
		rbt->add((rand() % 2000) - 1000);
		tmpTime += rbt->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Dodawanie: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);

	operationCounter = 0;
	tmpTime = 0;/*
	while (operationCounter < numberOfOperation)
	{
		rbt->~RedBlackTree();
		tmpTime += rbt->timeOfOperation.tmp;
		operationCounter++;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "Usuwanie: " << tmpTime << endl;
	SetConsoleTextAttribute(hConsole, 7);*/
}
