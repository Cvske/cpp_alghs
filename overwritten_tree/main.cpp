#include <iostream>

using namespace std;

struct node
{
	int value;
	node* child, * next, * parent;
};


class TTree
{
private:
	node* root;
public:
	node* getRoot()
	{
		return root->child;
	}
	TTree()
	{
		this->root = nullptr;
	}
	~TTree()
	{
		node* main = root->child;
		while (main != root)
		{
			while (main->child != nullptr)
				main = main->child;


			while (main->next == nullptr && main != root)
			{
				main = main->parent;
				if (main->child->next != nullptr)
					delete main->child->next;
				delete main->child;
			}


			if (main->next != nullptr)
				main = main->next;

		}
	}
	void insert_first()
	{
		int n;
		cin >> n;
		int* tab = new int[n];
		for (int i = 0; i < n; i++)
			cin >> tab[i];

		node* temp = new node;
		temp->value = 0;
		temp->parent = nullptr;
		temp->next = nullptr;
		temp->child = nullptr;
		root = temp;

		node* cur = root;
		for (int i = 0; i < n; i++)
		{
			node* temp = new node;
			temp->value = tab[i];
			temp->parent = cur;
			temp->next = nullptr;
			temp->child = nullptr;
			cur->child = temp;
			cur = temp;
		}

	}
	void insert()
	{
		int n, cnt = 0;
		cin >> n;
		int* tab = new int[n];
		for (int i = 0; i < n; i++)
			cin >> tab[i];

		node* temp = root->child;
		while (temp->value != tab[0] && temp->next != nullptr)
			temp = temp->next;

		node* prevParent  = temp->parent;





		while (cnt < n)
		{
			if (temp->value != tab[cnt] && temp->next == nullptr)
			{
				node* add = new node;
				add->value = tab[cnt];
				add->child = nullptr;
				add->parent = prevParent;
				add->next = nullptr;
				temp->next = add;
				temp = add;
				cnt++;


				for (cnt; cnt < n; cnt++)
				{
					node* add = new node;
					add->parent = temp;
					add->next = nullptr;
					add->child = nullptr;
					add->value = tab[cnt];
					temp->child = add;
					temp = add;
				}
			}
			while (temp->value == tab[cnt] && temp->child != nullptr && cnt < n)
			{
				temp = temp->child;
				cnt++;
			}
			prevParent = temp->parent;

			if (temp->value == tab[cnt] && temp->child == nullptr && cnt < n)
			{
				cnt++;
				for (cnt; cnt < n; cnt++)
				{
					node* add = new node;
					add->parent = temp;
					add->next = nullptr;
					add->child = nullptr;
					add->value = tab[cnt];
					temp->child = add;
					temp = add;
				}
			}
			else if ((temp->value != tab[cnt]) && cnt < n)
			{

				while (temp->next != nullptr && temp->value != tab[cnt])
					temp = temp->next;
			}

		}

		delete[]tab;
	}
	void display()
	{
		node* main = root->child;
		while (main != root)
		{
			while (main->child != nullptr)
			{
				cout << main->value << " ";
				main = main->child;
			}
			cout << main->value << " ";


			while (main->next == nullptr && main != root)
				main = main->parent;

			if (main->next != nullptr)
				main = main->next;

		}
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	TTree* tree = new TTree;
	unsigned int n;
	cin >> n;
	tree->insert_first();
	for (int i = 1; i < n; i++)
		tree->insert();

	tree->display();


	delete tree;
	return 0;
}