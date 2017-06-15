#include "RedBlackTree.h"

RedBlackTree::RedBlackTree()
{
	upCorner = botomCorner = vertical = "  ";
	upCorner[0] = 218; upCorner[1] = 196;
	botomCorner[0] = 192; botomCorner[1] = 196;
	vertical[0] = 179;
	black = "CZARNY";
	red = "CZERWONY";
	sentinel.color = black;
	sentinel.up = &sentinel;
	sentinel.left = &sentinel;
	sentinel.right = &sentinel;
	root = &sentinel;
	numberOfElements = 0;
}

RedBlackTree::~RedBlackTree()
{
	remove(root);
	numberOfElements = 0;
}

void RedBlackTree::remove(Node *node)
{
	if (node != &sentinel)
	{
		while (node != NULL) {
			remove(node->left);
			remove(node->right);
			delete node;
		}
	
	}
}

void RedBlackTree::loadFromFile(string name)
{
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
				add(key);
				i++;
			}
			else break;
		}
		file.close();
		for (i; i <= n; i++)
		{
			add(0);
		}
	}
}

void RedBlackTree::rotateLeft(Node* node)
{
	Node * right, *up;

	right = node->right;
	if (right != &sentinel)
	{
		up = node->up;
		node->right = right->left;
		if (node->right != &sentinel)
			node->right->up = node;

		right->left = node;
		right->up = up;
		node->up = right;

		if (up != &sentinel)
		{
			if (up->left == node) up->left = right; else up->right = right;
		}
		else root = right;
	}
}

void RedBlackTree::rotateRight(Node* node)
{
	Node * left, *up;

	left = node->left;
	if (left != &sentinel)
	{
		up = node->up;
		node->left = left->right;
		if (node->left != &sentinel)
			node->left->up = node;

		left->right = node;
		left->up = up;
		node->up = left;

		if (up != &sentinel)
		{
			if (up->left == node) up->left = left; else up->right = left;
		}
		else root = left;
	}
}

void RedBlackTree::randomFill(int quantity)
{
	int i;
	int *t;
	t = new int[quantity];
	for (i = 0; i < quantity; i++)
		t[i] = ((rand() % 2000) - 1000);

	for (i = 0; i < quantity; i++)
		add(t[i]);
}

void RedBlackTree::show(string txt1, string txt2, Node * node)
{
	string text;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (numberOfElements == 0) cout << "Drzewo jest puste" << endl;
	else if (node != &sentinel)
	{
		text = txt1;
		if (txt2 == upCorner)
			text[text.length() - 2] = ' ';
		show(text + vertical, upCorner, node->right);

		text = text.substr(0, txt1.length() - 2);
		if(node->color == black){
			SetConsoleTextAttribute(hConsole, 15);
			cout << text << txt2 << node->color << ":" << node->key << endl;
		}
		else {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << text << txt2 << node->color << ":" << node->key << endl;
		}
		

		text = txt1;
		if (txt2 == botomCorner)
			text[text.length() - 2] = ' ';
		show(text + vertical, botomCorner, node->left);
	}
	SetConsoleTextAttribute(hConsole, 7);
}

void RedBlackTree::add(int key)
{
	Node *newElement, *uncle;

	newElement = new Node;
	newElement->left = &sentinel;
	newElement->right = &sentinel;
	newElement->up = root;
	newElement->key = key;
	timeOfOperation.counter = 0;
	timeOfOperation.timeStart();
	if (newElement->up == &sentinel) root = newElement;
	else
		while (true)
		{
			if (key < newElement->up->key)
			{
				if (newElement->up->left == &sentinel)
				{
					newElement->up->left = newElement;
					break;
				}
				newElement->up = newElement->up->left;
			}
			if (key >= newElement->up->key)
			{
				if (newElement->up->right == &sentinel)

				{
					newElement->up->right = newElement;
					break;
				}
				newElement->up = newElement->up->right;
			}
		}
	newElement->color = red;
	while ((newElement != root) && (newElement->up->color == red))
	{
		if (newElement->up == newElement->up->up->left)
		{
			uncle = newElement->up->up->right;

			if (uncle->color == red)
			{
				newElement->up->color = black;
				uncle->color = black;
				newElement->up->up->color = red;
				newElement = newElement->up->up;
				continue;
			}

			if (newElement == newElement->up->right)
			{
				newElement = newElement->up;
				rotateLeft(newElement);
			}

			newElement->up->color = black;
			newElement->up->up->color = red;
			rotateRight(newElement->up->up);
			break;
		}
		else
		{
			uncle = newElement->up->up->left;

			if (uncle->color == red)
			{
				newElement->up->color = black;
				uncle->color = black;
				newElement->up->up->color = red;
				newElement = newElement->up->up;
				continue;
			}

			if (newElement == newElement->up->left)
			{
				newElement = newElement->up;
				rotateRight(newElement);
			}

			newElement->up->color = black;
			newElement->up->up->color = red;
			rotateLeft(newElement->up->up);
			break;
		}

	}
	root->color = black;
	numberOfElements++;
	timeOfOperation.timeTake();
}

bool RedBlackTree::isExist(int key)
{
	Node * node;
	bool isExist = false;
	node = root;
	while ((node != &sentinel) && (node->key != key))
	{
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	if (node == &sentinel) isExist = false;
	else isExist = true;
	return isExist;
}

Node* RedBlackTree::search(int key)
{
	Node * node;
	node = root;
	timeOfOperation.counter = 0;
	timeOfOperation.timeStart();
	while ((node != &sentinel) && (node->key != key))
	{
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	if (node == &sentinel) return NULL;
	return node;
	timeOfOperation.timeTake();
}
void RedBlackTree::eraseKey(int key)
{
	if (!isExist(key))
		cout << "W drzewie nie ma elementu o takim kluczu!" << endl;
	else if (numberOfElements == 0)
		cout << "Drzewo jest puste!" << endl;
	else
	{
		timeOfOperation.counter = 0;
		timeOfOperation.timeStart();
		Node *erasedNode, *uncle, *son;
		erasedNode = search(key);
		if ((erasedNode->left == &sentinel) || (erasedNode->right == &sentinel)) {}
		else
		{
			if (erasedNode != &sentinel)
			{
				if (erasedNode->right != &sentinel)
				{
					if (erasedNode->right != &sentinel)
					{
						while (erasedNode->right->left != &sentinel)
							erasedNode->right = erasedNode->right->left;
					}
					erasedNode = erasedNode->right;
				}
				else
				{
					erasedNode = erasedNode->up;
					while ((erasedNode != &sentinel) && (erasedNode == erasedNode->right))
					{
						erasedNode = erasedNode;
						erasedNode = erasedNode->up;
					}
				}
			}
			else
				erasedNode = &sentinel;
		}

		if (erasedNode->left != &sentinel)
			son = erasedNode->left;
		else
			son = erasedNode->right;

		son->up = erasedNode->up;

		if (erasedNode->up == &sentinel)
			root = son;
		else if
			(erasedNode == erasedNode->up->left) erasedNode->up->left = son;
		else
			erasedNode->up->right = son;

		if (erasedNode != erasedNode) erasedNode->key = erasedNode->key;

		if (erasedNode->color == black)
			while ((son != root) && (son->color == black))
			{
				if (son == son->up->left)
				{
					uncle = son->up->right;

					if (uncle->color == red)
					{
						uncle->color == black;
						son->up->color = red;
						rotateLeft(son->up);
						uncle = son->up->right;
					}

					if ((uncle->left->color == black) && (uncle->right->color == black))
					{
						uncle->color = red;
						son = son->up;
						continue;
					}

					if (uncle->right->color == black)
					{
						uncle->left->color == black;
						uncle->color = red;
						rotateRight(uncle);
						uncle = son->up->right;
					}
					uncle->color = son->up->color;
					son->up->color = black;
					uncle->right->color = black;
					rotateLeft(son->up);
					son = root;
				}
				else
				{
					uncle = son->up->left;

					if (uncle->color == red)
					{
						uncle->color = black;
						son->up->color = red;
						rotateRight(son->up);
						uncle = son->up->left;
					}

					if ((uncle->left->color == black) && (uncle->right->color == black))
					{
						uncle->color = red;
						son = son->up;
						continue;
					}

					if (uncle->left->color == black)
					{
						uncle->right->color == black;
						uncle->color = red;
						rotateLeft(uncle);
						uncle = son->up->left;
					}

					uncle->color = son->up->color;
					son->up->color = black;
					uncle->left->color = black;
					rotateRight(son->up);
					son = root;
				}
			}
		son->color = black;
		numberOfElements--;
		timeOfOperation.timeTake();
	}
}