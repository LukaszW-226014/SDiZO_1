#include "List.h"

List::List() {
	tail = head = NULL;
	numberOfElements = 0;
}

List::~List() {
	listElement * element;

	while (head)
	{
		element = head->next;
		delete head;
		head = element;
	}
	numberOfElements = 0;
}

void List::randomFill(int quantity) {
	for (int i = 1; i <= quantity; i++)
		addOnBegin((rand() % 2000) - 1000);
}

bool List::search(int searchedNumber) {
	isExist = false;
	listElement *element;
	element = head;
	timeOfOperation.counter = 0;
	timeOfOperation.timeStart();
	for (int i = 1; i <= numberOfElements; i++)
	{
		if (element->key == searchedNumber) { isExist = true; break; }
		else element = element->next;
	}
	timeOfOperation.timeTake();
	return isExist;
}

void List::loadFromFile(string name) {
	string s;
	int i = 1;
	string path = "C:/Users/Luke/Development/VisualStudio/SDiZO/SDiZO_1/Source/";

	name = path + name + ".txt";
	ifstream file(name);
	if (!file)
		cout << "Nie mozna otworzyc pliku" << endl;
	else
	{
		getline(file, s);
		int n = atoi(s.c_str());

		while (!file.eof())
		{
			if (i <= n)
			{
				getline(file, s);
				int key = atoi(s.c_str());
				addOnEnd(key);
				i++;
			}
			else break;
		}
		file.close();
		for (i; i <= n; i++)
		{
			addOnEnd(0);
		}
	}
}

void List::addBehindKey(int keyBehindInsert, int newKey) {
	timeOfOperation.counter = 0;
	timeOfOperation.timeStart();
	listElement *element;
	listElement * newElement = new listElement();
	if (!(search(keyBehindInsert)))
	{
		addOnBegin(newKey);
		cout << "Na liscie nie ma elementu o podanej wartosci - wstawiono na poczatek listy" << endl;
	}
	else
	{
		element = head;
		for (int i = 1; i <= numberOfElements; i++)
		{
			if (element->key == keyBehindInsert)
			{
				newElement->next = element->next; newElement->previous = element;
				element->next = newElement;
				if (newElement->next) newElement->next->previous = newElement;
				else tail = newElement;
				newElement->key = newKey;
				numberOfElements++;
				break;
			}
			else element = element->next;
		}

	}
	timeOfOperation.timeTake();
}

void  List::addOnBegin(int newKey) {
	listElement * newElement = new listElement();
	newElement->next = head;
	newElement->previous = NULL;
	if (head) head->previous = newElement;
	head = newElement;
	if (!tail) tail = head;
	newElement->key = newKey;
	numberOfElements++;
}

void List::addOnEnd(int newKey) {
	listElement * newElement = new listElement();
	newElement->previous = tail;
	newElement->next = NULL;
	if (tail) tail->next = newElement;
	tail = newElement;
	if (!head) head = tail;
	newElement->key = newKey;
	numberOfElements++;
}

void List::eraseFromBegin() {
	if (numberOfElements == 0) cout << "Lista jest pusta, nie mozna nic usunac" << endl;
	else
	{
		timeOfOperation.counter = 0;
		timeOfOperation.timeStart();
		head = head->next;
		numberOfElements--;
		timeOfOperation.timeTake();
	}
}

void List::eraseFromEnd() {
	if (numberOfElements == 0) cout << "Lista jest pusta, nie mozna nic usunac" << endl;
	else
	{
		timeOfOperation.counter = 0;
		timeOfOperation.timeStart();
		tail->previous->next = NULL;
		tail->previous = tail;
		numberOfElements--;
		timeOfOperation.timeTake();
	}
}

void List::remove(int erasedKey) {
	listElement *element;
	element = head;
	if (numberOfElements == 0) cout << "Lista jest pusta, nie mozna nic usunac" << endl;
	else
	{
		timeOfOperation.counter = 0;
		timeOfOperation.timeStart();
		while ((element->next != NULL) && (element->key != erasedKey)) { element = element->next; }
		if (element->key == erasedKey)
		{
			if (element->next) element->next->previous = element->previous;
			else tail = element->previous;
			if (element->previous) { element->previous->next = element->next; }
			else head = element->next;
			numberOfElements--;
			timeOfOperation.timeTake();
		}
		else cout << "Na liscie nie ma elementu o podanym kluczu!" << endl;
	}
}

void List::show() {
	listElement * element = new listElement();
	int i = 1;
	if (!head) cout << "Lista jest pusta." << endl;
	else
	{
		element = head;
		while (element)
		{
			cout << i << ". " << element->key << endl;
			element = element->next;
			i++;
		}
		cout << endl;
	}
	delete element;
}