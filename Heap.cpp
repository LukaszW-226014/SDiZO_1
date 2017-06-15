#include "Heap.h"

Heap::Heap() {
	upCorner = bottomCorner = vertical = "  ";
	upCorner[0] = 218; upCorner[1] = 196;
	bottomCorner[0] = 192; bottomCorner[1] = 196;
	vertical[0] = 179;
	numberOfElements = 0;
	w = new int[numberOfElements + 1];
}

Heap::~Heap() {
	numberOfElements = 0;
	delete[]w;
}

void Heap::randomFill(int quantity) {
	numberOfElements = quantity;
	w = new int[numberOfElements + 1];
	for (int i = 1; i <= numberOfElements; i++)
		w[i] = ((rand() % 2000) - 1000);
	build();
}

void Heap::loadFromFile(string name) {
	string s;
	int i = 0;
	int *t;
	string path = "C:/Users/Luke/Development/VisualStudio/SDiZO/SDiZO_1/Source/";

	name = path + name + ".txt";
	ifstream file(name);

	if (!file)
	{
		cout << "Nie mozna otworzyc pliku" << endl;;
	}
	else
	{
		getline(file, s);
		int n = 10;//atoi(s.c_str());
		numberOfElements = n;
		t = new int[numberOfElements];
		while (!file.eof())
		{
			if (i <= numberOfElements)
			{
				getline(file, s);
				t[i] = atoi(s.c_str());
				i++;
			}
			else break;
		}
		file.close();
		for (i; i <= numberOfElements; i++)
		{
			t[i] = 0;
		}
		w = t;
		build();
	}
}

void Heap::build() {
	for (int i = 2; i <= numberOfElements; i++)
	{
		int elementPosition, upPosition, element;
		elementPosition = i;
		upPosition = (elementPosition) / 2;
		element = w[i];
		while ((upPosition > 0) && (w[upPosition] < element))
		{
			w[elementPosition] = w[upPosition];
			elementPosition = upPosition;
			upPosition = (elementPosition) / 2;
		}
		w[elementPosition] = element;
	}
}

void Heap::show(string txt1, string txt2, int nodeNumber) {
	if (numberOfElements == 0)
		cout << "Kopiec jest pusty" << endl;
	string text;

	if (nodeNumber <= numberOfElements)
	{
		text = txt1;
		if (txt2 == upCorner)
			text[text.length() - 2] = ' ';

		show(text + vertical, upCorner, 2 * nodeNumber + 1);

		text = text.substr(0, txt1.length() - 2);

		cout << text << txt2 << w[nodeNumber] << endl;

		text = txt1;
		if (txt2 == bottomCorner)
			text[text.length() - 2] = ' ';
		show(text + vertical, bottomCorner, 2 * nodeNumber);
	}
}

bool Heap::search(int searchedNumber) {
	timeOfOperation.counter = 0;
	timeOfOperation.timeStart();
	isExist = false;
	for (int i = 1; i <= numberOfElements; i++)
	{
		if (searchedNumber == w[i])
		{
			isExist = true;
			break;
		}
	}
	timeOfOperation.timeTake();
	return isExist;
}

void Heap::add(int addedNumber) {
	timeOfOperation.counter = 0;
	timeOfOperation.timeStart();
	numberOfElements++;
	w[numberOfElements] = addedNumber;
	int newPosition = numberOfElements;
	while ((w[newPosition] > w[newPosition / 2]) && (newPosition > 1))
	{
		int temp = w[newPosition / 2];
		w[newPosition / 2] = w[newPosition];
		w[newPosition] = temp;
		newPosition = (newPosition / 2);
	}
	timeOfOperation.timeTake();
}

void Heap::relocate() {
	int *t = new int[numberOfElements + 1];
	for (int i = 1; i <= numberOfElements; i++)
	{
		t[i] = w[i];
	}
	w = new int[numberOfElements + 1];
	for (int i = 1; i <= numberOfElements; i++)
	{
		w[i] = t[i];
	}
	delete[]t;
}

void Heap::remove(int erasedNumber) {

	if (numberOfElements == 0) cout << "Kopiec jest pusty, nie mozna nic usunac" << endl;
	else
	{
		if (!search(erasedNumber)) cout << "W kopcu nie ma takiej liczby, nie mozna usunac!" << endl;
		else
		{
			timeOfOperation.counter = 0;
			timeOfOperation.timeStart();
			int i;
			for (i = 1; i <= numberOfElements; i++)
			{
				if (w[i] == erasedNumber) break;
			}
			if (i == numberOfElements)
			{
				w[i] = NULL;
				numberOfElements--;
				timeOfOperation.timeTake();
			}
			if (i < numberOfElements)
			{
				w[i] = w[numberOfElements];
				w[numberOfElements] = NULL;
				numberOfElements--;
				if (2 * i > numberOfElements)
				{
					while (i > 1)
					{
						if (w[i] > w[i / 2])
						{
							int temp = w[i / 2];
							w[i / 2] = w[i];
							w[i] = temp;
						}
						i = i / 2;
					}
				}
				else
				{
					while (i <= numberOfElements / 2)
					{
						if ((w[i] < (w[2 * i])) || (w[i] < (w[2 * i + 1])))
						{
							if (w[2 * i] > w[2 * i + 1])
							{
								int temp = w[i];
								w[i] = w[2 * i];
								w[2 * i] = temp;
								i = 2 * i;
							}
							else
							{
								int temp = w[i];
								w[i] = w[2 * i + 1];
								w[2 * i + 1] = temp;
								i = 2 * i + 1;
							}
						}
						else break;
					}

				}
			}
			timeOfOperation.timeTake();
			relocate();
		}
	}
}