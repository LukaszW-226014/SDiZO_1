#include "Show.h"

Show::Show() {
	goToBegin = true;
	choice = NULL;
	quantity = NULL;
	value = NULL;
	name = "";
	switchChoice();
}
	
Show::~Show() {}

void Show::switchChoice()
{
	cout << "+++++++++++++++++++++++++++++++++++++++++++| Lukasz Wojcik 226014 |+++++++++++++++++++++++++++++++++++++++++++" << endl
		<< "Wybierz: " << endl
		<< "1. Glowne Menu" << endl
		<< "2. Test Jednostkowy" << endl
		<< "3. Zamknij" << endl;
	cin >> choice;
	system("cls");
	switch (choice)
	{
	case 1: {
		menu();

	}break;

	case 2: {
		new Test();
	}break;

	case 3: {
		exit(0);
	}break;
	}
}

void Show::menu() {
	srand((unsigned int)time(NULL));
	while (goToBegin == true) {
		cout << "+++++++++++++++++++++++++++++++++++++++++++| Lukasz Wojcik 226014 |+++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "Wybierz strukture do testow" << endl
			<< "1. Tablica" << endl
			<< "2. Lista" << endl
			<< "3. Kopiec" << endl
			<< "4. Drzewo czerwono - czarne" << endl
			<< "5. Zakoncz program" << endl
			<< "--------------------------------------------" << endl;

		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1: {
			arrayMenu();
		}break;


		case 2: {
			listMenu();
		}break;

		case 3: {
			heapMenu();
		}break;

		case 4: {
			redBlackTreeMenu();
		}break;

		case 5: {
			exit(0);
		}break;
		}
	}
}

void Show::arrayMenu() {
	goToBegin = false;
	Array* array;
	array = new Array();
	while (goToBegin == false)
	{
		cout << "+++++++++++++++++++++++++++++++++++++++++++| Tablica - " << array->numberOfElements << " elementow |+++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "Co chcesz zrobic z ta struktura?" << endl
			<< "1. Zbuduj z pliku " << endl
			<< "2. Wylosuj tablice" << endl
			<< "3. Usun" << endl
			<< "4. Dodaj" << endl
			<< "5. Wyszukaj" << endl
			<< "6. Wyswietl" << endl
			<< "7. Zniszcz strukture" << endl
			<< "8. Wroc do wyboru struktury" << endl
			<< "9. Zakoncz program" << endl
			<< "--------------------------------------------" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: {
			array = new Array();
			cout << "Podaj nazwe pliku do wczytania danych" << endl;
			cin >> name;
			system("cls");
			array->loadFromFile(name);
		} break;

		case 2: {
			while (true)
			{
				system("cls");
				cout << "Ilu elementowa tablice stworzyc?" << endl;
				cin >> quantity;
				system("cls");
				if (quantity <= 0) cout << "Podaj liczbe wieksza od zera!" << endl;
				else break;
			}
			array = new Array();
			array->randomFill(quantity);
		}break;

		case 3: {
			system("cls");
			cout << "1. Usun z poczatku " << endl
				<< "2. Usun z konca" << endl
				<< "3. Usun wybrany element" << endl;

			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
			{
				array->eraseFromBegin();
			}break;

			case 2:
			{
				array->eraseFromEnd();
			}break;

			case 3: {
				while (true)
				{
					cout << "Podaj indeks elementu do usuniecia" << endl;
					cin >> quantity;
					system("cls");
					if (quantity < 0) cout << "Podaj liczbe wieksza od zera!" << endl;
					else break;
				}
				array->remove(quantity);
			}break;
			}
		}break;

		case 4: {
			system("cls");
			cout << "1. Dodaj na poczatek " << endl
				<< "2. Dodaj na koniec" << endl
				<< "3. Dodaj na wybranym miejscu" << endl;

			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
			{
				cout << "Podaj wartosc nowego elementu" << endl;
				cin >> value;
				system("cls");
				timeOfOperation.counter = 0;
				timeOfOperation.timeStart();
				array->addOnBegin(value);
				timeOfOperation.timeTake();
			}break;

			case 2:
			{
				cout << "Podaj wartosc nowego elementu" << endl;
				cin >> value;
				system("cls");
				array->addOnEnd(value);
			}break;

			case 3: {
				while (true)
				{
					cout << "Podaj indeks miejsca, gdzie ma byc wstawiony nowy element" << endl;
					cin >> quantity;
					system("cls");
					if (quantity < 0) cout << "Podaj liczbe wieksza od zera!" << endl;
					else break;
				}

				cout << "Podaj wartosc nowego elementu" << endl;
				cin >> value;
				system("cls");
				array->add(quantity, value);
			}break;
			}
		}break;

		case 5: {
			system("cls");
			cout << "Podaj wartosc, ktora chcesz sprawdzic, czy jest w tablicy" << endl;
			cin >> value;
			system("cls");
			array->search(value);
		}break;

		case 6: {
			system("cls");
			array->show();
		}break;

		case 7: {
			system("cls");
			array->~Array();
			array = new Array();
		}break;

		case 8: {
			array->~Array();
			system("cls");
			goToBegin = true;
		}break;

		case 9: {
			array->~Array();
			exit(0);
		}break;
		}
	}
}

void Show::listMenu() {
	goToBegin = false;
	List* list;
	list = new List();

	while (goToBegin == false) {
		cout << "+++++++++++++++++++++++++++++++++++++++++++| Lista - " << list->numberOfElements << " elementow |+++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "Co chcesz zrobic z ta struktura?" << endl
			<< "1. Zbuduj z pliku " << endl
			<< "2. Wylosuj liste" << endl
			<< "3. Usun" << endl
			<< "4. Dodaj" << endl
			<< "5. Wyszukaj" << endl
			<< "6. Wyswietl" << endl
			<< "7. Zniszcz strukture" << endl
			<< "8. Wroc do wyboru struktury" << endl
			<< "9. Zakoncz program" << endl
			<< "--------------------------------------------" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1: {
			list->~List();
			list = new List();
			cout << "Podaj nazwe pliku do wczytania danych" << endl;
			cin >> name;
			system("cls");
			list->loadFromFile(name);
		}break;

		case 2: {
			list->~List();
			while (true)
			{
				system("cls");
				cout << "Ilu elementowa liste stworzyc?" << endl;
				cin >> quantity;
				system("cls");
				if (quantity <= 0) cout << "Podaj liczbe wieksza od zera!" << endl;
				else break;
			}
			list = new List();
			list->randomFill(quantity);
		}break;

		case 3: {
			system("cls");
			cout << "1. Usun z poczatku " << endl
				<< "2. Usun z konca" << endl
				<< "3. Usun wybrany element" << endl;
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
			{
				list->eraseFromBegin();
			}break;

			case 2:
			{
				list->eraseFromEnd();
			}break;

			case 3: {
				cout << "Co usunac (klucz elementu)?" << endl;
				cin >> quantity;
				system("cls");
				list->remove(quantity);
			}break;
			}
		}break;

		case 4: {
			system("cls");
			cout << "1. Dodaj na poczatek " << endl
				<< "2. Dodaj na koniec" << endl
				<< "3. Dodaj za wybranym elementem" << endl;

			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
			{
				cout << "Podaj klucz nowego elementu" << endl;
				cin >> value;
				system("cls");
				timeOfOperation.counter = 0;
				timeOfOperation.timeStart();
				list->addOnBegin(value);
				timeOfOperation.timeTake();
			}break;

			case 2:
			{
				cout << "Podaj klucz nowego elementu" << endl;
				cin >> value;
				system("cls");
				timeOfOperation.counter = 0;
				timeOfOperation.timeStart();
				list->addOnEnd(value);
				timeOfOperation.timeTake();
			}break;

			case 3: {
				cout << "Podaj klucz elementu do wstawienia" << endl;
				cin >> key;
				system("cls");
				cout << "Za ktorym elementem chcesz wstawic nowy (podaj klucz)?" << endl;
				cin >> quantity;
				cout << endl;
				list->addBehindKey(quantity, key);

			}break;
			}
		}break;

		case 5: {
			system("cls");
			cout << "Podaj klucz, ktory chcesz sprawdzic, czy jest na liscie" << endl;
			cin >> quantity;
			system("cls");
			list->search(quantity);
			if (list->isExist) cout << "Szukany element znajduje sie na liscie" << endl;
			else if (!list->isExist) cout << "Szukego elementu nie ma na liscie" << endl;
		}break;

		case 6: {
			system("cls");
			list->show();
		}break;

		case 7: {
			system("cls");
			list->~List();
			list = new List();
		}break;

		case 8: {
			list->~List();
			system("cls");
			goToBegin = true;
		}break;

		case 9: {
			list->~List();
			exit(0);
		}break;
		}
	}
}

void Show::heapMenu() {
	goToBegin = false;
	Heap *heap;
	heap = new Heap();
	while (goToBegin == false)
	{
		cout << "+++++++++++++++++++++++++++++++++++++++++++| Kopiec - " << heap->numberOfElements << " elementow |+++++++++++++++++++++++++++++++++++++++++++" << endl
			<< "Co chcesz zrobic z ta struktura?" << endl
			<< "1. Zbuduj z pliku " << endl
			<< "2. Wylosuj kopiec" << endl
			<< "3. Usun" << endl
			<< "4. Dodaj" << endl
			<< "5. Wyszukaj" << endl
			<< "6. Wyswietl" << endl
			<< "7. Zniszcz strukture" << endl
			<< "8. Wroc do wyboru struktury" << endl
			<< "9. Zakoncz program" << endl
			<< "--------------------------------------------" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1: {
			cout << "Podaj nazwe pliku do wczytania danych" << endl;
			cin >> name;
			system("cls");
			heap = new Heap();
			heap->loadFromFile(name);
		}break;

		case 2:
		{
			while (true)
			{
				system("cls");
				cout << "Ilu elementowa strukture stworzyc?" << endl;
				cin >> quantity;
				system("cls");
				if (quantity > 0) break;
				else cout << "Podaj liczbe wieksza od zera!" << endl;

			}
			heap = new Heap();
			heap->randomFill(quantity);
		}break;

		case 3: {
			system("cls");
			cout << "Co usunac (klucz)?" << endl;
			cin >> quantity;
			system("cls");
			heap->remove(quantity);
		}break;

		case 4: {
			system("cls");
			cout << "Podaj klucz elementu do wstawienia" << endl;
			cin >> quantity;
			system("cls");
			heap->add(quantity);
		}break;

		case 5: {
			system("cls");
			cout << "Podaj wartosc, ktora chcesz sprawdzic, czy jest w kopcu" << endl;
			cin >> quantity;
			system("cls");
			heap->search(quantity);
			if (heap->isExist) cout << "Szukany element znajduje sie w kopcu" << endl;
			if (!heap->isExist) cout << "Szukego elementu nie ma w kopcu" << endl;
		}break;

		case 6: {
			system("cls");
			heap->show("   ", " ", 1);
		}break;

		case 7: {
			system("cls");
			heap->~Heap();
			heap = new Heap();
		}break;

		case 8: {
			heap->~Heap();
			system("cls");
			goToBegin = true;
		}break;

		case 9: {
			heap->~Heap();
			exit(0);
		}break;
		}
	}
}

void Show::redBlackTreeMenu() {
	goToBegin = false;
	int quantity;
	system("cls");
	RedBlackTree *tree;
	tree = new RedBlackTree();

	while (goToBegin == false)
	{
		cout << "+++++++++++++++++++++++++++++++++++++| Drzewo czerwono-czarne - " << tree->numberOfElements << " elementow |+++++++++++++++++++++++++++++++++++++" << endl 
			<< "Co chcesz zrobic z ta struktura?" << endl 
			<< "1. Zbuduj z pliku " << endl 
			<< "2. Wylosuj drzewo" << endl 
			<< "3. Usun" << endl 
			<< "4. Dodaj" << endl 
			<< "5. Wyszukaj" << endl 
			<< "6. Wyswietl" << endl 
			<< "7. Zniszcz strukture" << endl 
			<< "8. Wroc do wyboru struktury" << endl 
			<< "9. Zakoncz program" << endl
			<< "--------------------------------------------" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1: {
			tree->~RedBlackTree();
			tree = new RedBlackTree();
			string nazwa;
			cout << "Podaj nazwe pliku do wczytania danych" << endl;
			cin >> nazwa;
			cout << endl;
			system("cls");
			tree->loadFromFile(nazwa);
		}break;

		case 2:
		{
			system("cls");
			tree->~RedBlackTree();
			while (true)
			{
				cout << "Ilu elementowa strukture stworzyc?" << endl;
				cin >> quantity;
				if (quantity > 0) break;
				else cout << "Podaj liczbe wieksza od zera!" << endl;
			}
			tree = new RedBlackTree();
			system("cls");
			tree->randomFill(quantity);
			system("cls");

		}break;

		case 3: {
			system("cls");
			cout << "Co usunac?" << endl;
			cin >> quantity;
			cout << endl;
			system("cls");
			tree->eraseKey(quantity);

		}break;

		case 4: {
			system("cls");
			cout << "Podaj wartosc elementu do wstawienia" << endl;
			cin >> quantity;
			cout << endl;
			//timeOfOperation.counter = 0;
			//timeOfOperation.timeStart();
			system("cls");
			tree->add(quantity);
			//timeOfOperation.timeTake();

		}break;

		case 5: {
			system("cls");
			cout << "Podaj wartosc, ktora chcesz sprawdzic, czy jest w drzewie" << endl;
			cin >> quantity;
			cout << endl;
			system("cls");
			tree->isExist(quantity);
			if (tree->isExist(quantity)) cout << "Szukany element znajduje sie w drzewie" << endl;
			if (!tree->isExist(quantity)) cout << "Szukego elementu nie ma w drzewie" << endl;
		}break;

		case 6: {
			system("cls");
			tree->show("    ", "", tree->root);
		}break;

		case 7: {
			system("cls");
			//tree->~RedBlackTree();
			tree = new RedBlackTree();
		}break;

		case 8: {
			//tree->~RedBlackTree();
			system("cls");
			goToBegin = true;
		}break;

		case 9: {
			//tree->~RedBlackTree();
			exit(0);
		}break;
		}
	}
}