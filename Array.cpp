#include "Array.h"

Array::Array() {
	numberOfElements = 0;
	w = new int[numberOfElements];
}

Array::~Array() {
	delete[]w;
	numberOfElements = 0;
}

void Array::randomFill(int quantity) {
	numberOfElements = quantity;
	w = new int[2 * numberOfElements];
	for (int i = 0; i < numberOfElements; i++)
	{
		w[i] = ((rand() % 2000) - 1000);
	}
}

void Array::show() {
	if (numberOfElements == 0) cout << "Tablica jest pusta" << endl;
	else
	{
		for (int i = 0; i < numberOfElements; i++) { cout << i << ": " << w[i] << endl; }
		cout << endl;
	}
}

void Array::remove(int numberID) {
	if (numberOfElements == 0) { cout << "Tablica jest pusta, nie mozna nic usunac" << endl; }
	else if (numberID >= numberOfElements) cout << "Tablica ma mniej elementow!" << endl;
	else {
		timeOfOperation.counter = 0;
		timeOfOperation.timeStart();
		for (int i = numberID; i < numberOfElements; i++)
		{
			w[i] = w[i + 1];

		}

		numberOfElements--;
		relocate();

		timeOfOperation.timeTake();
	}
}

void Array::relocate() {
	int *t = new int[numberOfElements];
	for (int i = 0; i < numberOfElements; i++)
	{
		t[i] = w[i];
	}
	w = new int[2 * numberOfElements];
	for (int i = 0; i < numberOfElements; i++)
	{
		w[i] = t[i];
	}
	delete[]t;
}

void Array::eraseFromBegin() {
	if (numberOfElements == 0) { cout << "Tablica jest pusta, nie mozna nic usunac" << endl; }
	else
	{
		timeOfOperation.counter = 0;
		timeOfOperation.timeStart();
		numberOfElements--;
		for (int i = 0; i < numberOfElements; i++)
		{
			w[i] = w[i + 1];
		}
		relocate();
		timeOfOperation.timeTake();
	}
}

void Array::eraseFromEnd() {
	if (numberOfElements == 0) { cout << "Tablica jest pusta, nie mozna nic usunac" << endl; }

	else
	{
		timeOfOperation.counter = 0;
		timeOfOperation.timeStart();
		w[numberOfElements - 1] = NULL;
		numberOfElements--;
		relocate();
		timeOfOperation.timeTake();
	}
}

void Array::addOnBegin(int addedNumber) {
	numberOfElements++;

	for (int i = numberOfElements - 1; i > 0; i--)
	{
		w[i] = w[i - 1];
	}
	w[0] = addedNumber;
	relocate();
}

void Array::addOnEnd(int addedNumber) {
	timeOfOperation.counter = 0;
	timeOfOperation.timeStart();
	w[numberOfElements] = addedNumber;
	numberOfElements++;
	relocate();
	timeOfOperation.timeTake();
}

void Array::add(int newID, int addedNumber) {
	if (newID >= numberOfElements)
	{

		addOnEnd(addedNumber);
		cout << "Podano indeks wykraczajacy poza rozmiar tablicy. Element zostal dodany na koncu tablicy" << endl;
	}
	else
	{
		timeOfOperation.counter = 0;
		timeOfOperation.timeStart();
		numberOfElements++;
		for (int i = numberOfElements - 1; i > newID; i--)
		{
			w[i] = w[i - 1];
		}
		w[newID] = addedNumber;
		relocate();
		timeOfOperation.timeTake();
	}
}

void Array::search(int searchedNumber) {
	timeOfOperation.counter = 0;
	timeOfOperation.timeStart();
	bool isExist = false;
	for (int i = 0; i < numberOfElements; i++) { if (searchedNumber == w[i]) { isExist = true; break; } }
	timeOfOperation.timeTake();
	if (isExist) cout << "Szukany element znajduje sie w tablicy" << endl;
	if (!isExist) cout << "Szukego elementu nie ma w tablicy" << endl;
}

void Array::loadFromFile(string name) {
	string s;
	int i = 0;
	string path = "C:/Users/Luke/Development/VisualStudio/SDiZO/SDiZO_1/Source/";

	name =  path + name + ".txt";
	ifstream file(name);

	if (!file)
	{
		cout << "Nie mozna otworzyc pliku" << endl;;

	}
	else
	{
		getline(file, s);
		int n = atoi(s.c_str());
		numberOfElements = n;
		while (!file.eof())
		{
			if (i < numberOfElements)
			{
				getline(file, s);
				w[i] = atoi(s.c_str());
				i++;
			}
			else break;

		}
		file.close();
		for (i; i < numberOfElements; i++)
		{
			w[i] = 0;
		}
	}
}