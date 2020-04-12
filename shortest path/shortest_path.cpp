#include <iostream>
using namespace std;
int a, b;

struct node
{
	char character;
	node* left, * right, * up, * down, * next;
	int step;
	int m;
};

class TMap
{
	node* S, * X, * head, * tail;
	node* headL, * tailL;
public:
	TMap()
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->S = nullptr;
		this->X = nullptr;
		this->headL = nullptr;
		this->tailL = nullptr;
	}
	~TMap()
	{
		node* temp;
		node* prev;
		for (int i = 0; i < a + 2; i++)
		{
			temp = head;
			while (temp->next != nullptr)
			{
				prev = temp;
				temp = temp->next;
				delete prev;
			}
		}
	}

	void addToList(node* add)
	{
		if (headL == NULL)
		{
			headL = add;
			tailL = add;
		}
		else
		{
			tailL->next = add;
			tailL = add;
			tailL->next = NULL;
		}
	}
	void deleteFirst()
	{
		headL = headL->next;
	}
	void addHash()
	{
		if (head == NULL)
		{
			node* temp = new node;
			temp->character = '#';
			temp->left = nullptr, temp->right = nullptr, temp->up = nullptr, temp->down = nullptr;
			head = tail = temp;
			temp = nullptr;
		}
		else
		{
			node* temp = new node;
			temp->character = '#';
			temp->left = nullptr, temp->right = nullptr, temp->up = nullptr, temp->down = nullptr;
			tail->right = temp;
			temp->left = tail;
			tail = temp;
			tail->right = nullptr;
		}
	}
	void addNode()
	{
		if (head == NULL)
		{
			node* temp = new node;
			temp->step = 0;
			temp->m = 0;
			cin >> temp->character;
			temp->left = nullptr, temp->right = nullptr, temp->up = nullptr, temp->down = nullptr;
			head = tail = temp;
			temp = nullptr;
		}
		else
		{
			node* temp = new node;
			cin >> temp->character;
			temp->step = 0;
			temp->m = 0;
			temp->left = nullptr, temp->right = nullptr, temp->up = nullptr, temp->down = nullptr;
			tail->right = temp;
			temp->left = tail;
			tail = temp;
			tail->right = nullptr;
		}
	}
	void createArray(int n, int m)
	{

		addHash();
		node* first = head;
		for (int i = 0; i < m + 1; i++)
			addHash();



		for (int i = 0; i < n; i++)
		{
			head = nullptr;
			addHash();
			head->up = first; first->down = head;
			if (first->right != nullptr)
				first = first->right;


			node* first2 = head;
			for (int j = 0; j < m; j++)
			{
				addNode();
				tail->up = first; first->down = tail;
				if (tail->character == 'S') 	S = tail;
				else if (tail->character == 'X') X = tail;
				if (first->right != nullptr)
					first = first->right;
			}
			addHash();
			tail->up = first; first->down = tail;

			first = first2;
		}

		head = nullptr;


		for (int i = 0; i < m + 2; i++)
		{
			addHash();
			first->down = tail; tail->up = first;
			if (first->right != nullptr)
				first = first->right;
		}

	}
	void findPath()
	{
		addToList(S);
		S->character == '!';
		cout << endl;
		while (headL != nullptr)
		{

			if ((headL->up->step - 1 == headL->step) && (headL->up->m > headL->m) && (headL->up->character == '!' || headL->up->character == '2'))
			{
				headL->up->m = headL->m;
				if (headL->up->character == '2')
					headL->up->m++;
			}

			else if (headL->up->character != '#' && headL->up->character != '!' && headL->up->character != '2')
			{
				headL->up->step = headL->step;
				headL->up->step++;
				headL->up->m = headL->m;
				if (headL->up->character == 'M')
				{
					headL->up->m++;
					headL->up->character = '2';
				}


				else headL->up->character = '!';
				addToList(headL->up);
			}



			if ((headL->right->step - 1 == headL->step) && (headL->right->m > headL->m) && (headL->right->character == '!' || headL->right->character == '2'))
			{
				headL->right->m = headL->m;
				if (headL->right->character == '2')
					headL->right->m++;
			}

			else if (headL->right->character != '#' && headL->right->character != '!' && headL->right->character != '2')
			{
				headL->right->step = headL->step;
				headL->right->step++;
				headL->right->m = headL->m;
				if (headL->right->character == 'M')
				{
					headL->right->character = '2';
					headL->right->m++;
				}


				else headL->right->character = '!';
				addToList(headL->right);
			}



			if ((headL->down->step - 1 == headL->step) && (headL->down->m > headL->m) && (headL->down->character == '!' || headL->down->character == '2'))
			{
				headL->down->m = headL->m;
				if (headL->down->character == '2')
					headL->down->m++;
			}

			else if (headL->down->character != '#' && headL->down->character != '!' && headL->down->character != '2')
			{
				headL->down->step = headL->step;
				headL->down->step++;
				headL->down->m = headL->m;
				if (headL->down->character == 'M')
				{
					headL->down->character = '2';
					headL->down->m++;
				}


				else headL->down->character = '!';
				addToList(headL->down);
			}


			if (headL->left->character != '#' && headL->left->character != '!' && headL->left->character != '2')
			{
				headL->left->step = headL->step;
				headL->left->step++;
				headL->left->m = headL->m;
				if (headL->left->character == 'M')
				{
					headL->left->m++;
					headL->left->character = '2';
				}


				else headL->left->character = '!';
				addToList(headL->left);
			}

			deleteFirst();

		}
		cout << X->step << endl << X->m;
	}
};


int main()
{
	ios_base::sync_with_stdio(false);
	TMap* map = new TMap;
	cin >> a;
	cin >> b;
	map->createArray(a, b);
	map->findPath();

	delete map;
}