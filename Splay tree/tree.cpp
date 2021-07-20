#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct node
{
	string zespol;
	node* left, * right, * parent;
	vector <string> lista;
};

struct tytul
{
	string nazwa;
	tytul* left, * right, * parent;
	vector <string> lista;
};

class Tree
{
	node* root;
	tytul* root2;
public:
	Tree()
	{
		root = nullptr;
		root2 = nullptr;
	}


	void splay(node* x)
	{
		while (x->parent != nullptr)
		{
			node* y = x->parent;
			node* z = y->parent;
			if (z == nullptr) zig(x);
			else if (z->left == y && y->left == x) zigzig(x);
			else if (z->right == y && y->right == x) zigzig(x);
			else zigzag(x);
		}
		this->root = x;
	}
	void add(string zespol, string tytul)
	{

		if (root == nullptr)
		{
			node* temp = new node;
			temp->zespol = zespol;
			temp->lista.push_back(tytul);
			temp->left = nullptr;
			temp->right = nullptr;
			temp->parent = nullptr;
			root = temp;
		}

		else
		{
			bool exists = false;
			node* ptrPrev = nullptr;
			node* ptr = root;
			while (ptr != nullptr)
			{
				ptrPrev = ptr;
				if (zespol == ptr->zespol)
				{
					exists = true;
					ptr->lista.push_back(tytul);
					splay(ptr);
					break;
				}
				if (zespol > ptr->zespol)
					ptr = ptr->right;
				else
					ptr = ptr->left;
			}

			if (exists == false)
			{
				node* temp = new node;
				temp->zespol = zespol;
				temp->lista.push_back(tytul);
				temp->left = nullptr;
				temp->right = nullptr;
				temp->parent = nullptr;
				if (zespol < ptrPrev->zespol)
				{
					ptrPrev->left = temp;
					temp->parent = ptrPrev;
				}

				else
				{
					ptrPrev->right = temp;
					temp->parent = ptrPrev;
				}
				splay(temp);

			}
			exists = false;
		}
	}

	void zig(node* x)
	{
		node* y = x->parent;

		if (y->left == x)
		{

			node* xRight = x->right;


			x->right = y;
			x->parent = nullptr;
			y->parent = x;
			y->left = nullptr;

			if (xRight != nullptr)
			{
				y->left = xRight;
				xRight->parent = y;
			}

			root = x;
		}
		else if (y->right == x)
		{

			node* xLeft = x->left;

			x->left = y;
			x->parent = nullptr;
			y->parent = x;
			y->right = nullptr;

			if (xLeft != nullptr)
			{
				y->right = xLeft;
				xLeft->parent = y;
			}

			root = x;
		}
	}
	void zigzig(node* x)
	{
		node* y = x->parent;
		node* z = y->parent;

		if (y->right == x)
		{
			node* zLeft = z->left;
			node* yLeft = y->left;
			node* xLeft = x->left;
			node* xRight = x->right;

			x->parent = z->parent;
			x->left = y;
			y->parent = x;
			y->left = z;
			y->right = xLeft;
			z->parent = y;
			z->right = yLeft;
			x->right = xRight;
			z->left = zLeft;

			if (x->parent != nullptr)
			{
				if (x->parent->left == z) x->parent->left = x;
				else x->parent->right = x;
			}


			if (xRight != nullptr)
			{
				
				xRight->parent = x;
			}
			else x->right = nullptr;


			if (xLeft != nullptr)	xLeft->parent = y;

			else y->right = nullptr;



			if (zLeft != nullptr)
			{
				
				zLeft->parent = z;
			}
			else z->left = nullptr;



			if (yLeft != nullptr)	yLeft->parent = z;

			else z->right = nullptr;

		}
		else
		{
			node* zRight = z->right;
			node* yRight = y->right;
			node* xLeft = x->left;
			node* xRight = x->right;

			x->parent = z->parent;

			x->right = y;
			y->parent = x;
			y->left = xRight;
			y->right = z;
			z->parent = y;
			z->left = yRight;
			x->left = xLeft;
			z->right = zRight;


			if (x->parent != nullptr)
			{
				if (x->parent->left == z) x->parent->left = x;
				else x->parent->right = x;
			}


			if (xRight != nullptr) xRight->parent = y;

			else y->left = nullptr;


			if (xLeft != nullptr)
			{
				
				xLeft->parent = x;
			}
			else x->left = nullptr;



			if (zRight != nullptr)
			{
				
				zRight->parent = z;
			}
			else z->right = nullptr;



			if (yRight != nullptr) yRight->parent = z;

			else z->left = nullptr;

		}
	}
	void zigzag(node* x)
	{
		node* y = x->parent;
		node* z = y->parent;
		if (y->right == x)
		{
			node* xLeft = x->left;
			node* xRight = x->right;

			x->parent = z->parent;
			x->left = y;
			x->right = z;

			y->parent = x;
			y->right = xLeft;

			z->parent = x;
			z->left = xRight;

			if (x->parent != nullptr)
			{
				if (x->parent->left == z) x->parent->left = x;
				else x->parent->right = x;
			}

			if (xLeft != nullptr) xLeft->parent = y;

			if (xRight != nullptr) xRight->parent = z;
		}
		else
		{

			node* xLeft = x->left;
			node* xRight = x->right;

			x->parent = z->parent;
			x->left = z;
			x->right = y;

			y->parent = x;
			y->left = xRight;

			z->parent = x;
			z->right = xLeft;

			if (x->parent != nullptr)
			{
				if (x->parent->left == z) x->parent->left = x;
				else x->parent->right = x;
			}

			if (xLeft != nullptr) xLeft->parent = z;

			if (xRight != nullptr) xRight->parent = y;
		}
	}

	void add2(string zespol, string title)
	{

		if (root2 == nullptr)
		{
			tytul* temp = new tytul;
			temp->nazwa = title;
			temp->lista.push_back(zespol);
			temp->left = nullptr;
			temp->right = nullptr;
			temp->parent = nullptr;
			root2 = temp;
		}
			

		else
		{
			bool exists = false;
			tytul* ptrPrev = nullptr;
			tytul* ptr = root2;
			while (ptr != nullptr)
			{
				ptrPrev = ptr;
				if (title == ptr->nazwa)
				{
					exists = true;
					ptr->lista.push_back(zespol);
					splay2(ptr);
					break;
				}
				if (title > ptr->nazwa)
					ptr = ptr->right;
				else
					ptr = ptr->left;
			}
			if (exists == false)
			{

				tytul* temp = new tytul;
				temp->nazwa = title;
				temp->lista.push_back(zespol);
				temp->left = nullptr;
				temp->right = nullptr;
				temp->parent = nullptr;

				if (title < ptrPrev->nazwa)
				{
					ptrPrev->left = temp;
					temp->parent = ptrPrev;
				}

				else
				{
					ptrPrev->right = temp;
					temp->parent = ptrPrev;
				}
				splay2(temp);

			}
			exists = false;
		}
	}
	void splay2(tytul* x)
	{
		while (x->parent != nullptr)
		{
			tytul* y = x->parent;
			tytul* z = y->parent;
			if (z == nullptr) zig2(x);
			else if (z->left == y && y->left == x) zigzig2(x);
			else if (z->right == y && y->right == x) zigzig2(x);
			else zigzag2(x);
		}
		this->root2 = x;
	}
	void zig2(tytul* x)
	{
		tytul* y = x->parent;

		if (y->left == x)
		{

			tytul* xRight = x->right;


			x->right = y;
			x->parent = nullptr;
			y->parent = x;
			y->left = nullptr;

			if (xRight != nullptr)
			{
				y->left = xRight;
				xRight->parent = y;
			}

			root2 = x;
		}
		else if (y->right == x)
		{

			tytul* xLeft = x->left;

			x->left = y;
			x->parent = nullptr;
			y->parent = x;
			y->right = nullptr;

			if (xLeft != nullptr)
			{
				y->right = xLeft;
				xLeft->parent = y;
			}

			root2 = x;
		}
	}
	void zigzig2(tytul* x)
	{
		tytul* y = x->parent;
		tytul* z = y->parent;

		if (y->right == x)
		{
			tytul* zLeft = z->left;
			tytul* yLeft = y->left;
			tytul* xLeft = x->left;
			tytul* xRight = x->right;

			x->parent = z->parent;
			x->left = y;
			y->parent = x;
			y->left = z;
			y->right = xLeft;
			z->parent = y;
			z->right = yLeft;
			x->right = xRight;
			z->left = zLeft;

			if (x->parent != nullptr)
			{
				if (x->parent->left == z) x->parent->left = x;
				else x->parent->right = x;
			}


			if (xRight != nullptr)
			{

				xRight->parent = x;
			}
			else x->right = nullptr;


			if (xLeft != nullptr)	xLeft->parent = y;

			else y->right = nullptr;



			if (zLeft != nullptr)
			{

				zLeft->parent = z;
			}
			else z->left = nullptr;



			if (yLeft != nullptr)	yLeft->parent = z;

			else z->right = nullptr;

		}
		else
		{
			tytul* zRight = z->right;
			tytul* yRight = y->right;
			tytul* xLeft = x->left;
			tytul* xRight = x->right;

			x->parent = z->parent;

			x->right = y;
			y->parent = x;
			y->left = xRight;
			y->right = z;
			z->parent = y;
			z->left = yRight;
			x->left = xLeft;
			z->right = zRight;


			if (x->parent != nullptr)
			{
				if (x->parent->left == z) x->parent->left = x;
				else x->parent->right = x;
			}


			if (xRight != nullptr) xRight->parent = y;

			else y->left = nullptr;


			if (xLeft != nullptr)
			{

				xLeft->parent = x;
			}
			else x->left = nullptr;



			if (zRight != nullptr)
			{

				zRight->parent = z;
			}
			else z->right = nullptr;



			if (yRight != nullptr) yRight->parent = z;

			else z->left = nullptr;

		}
	}
	void zigzag2(tytul* x)
	{
		tytul* y = x->parent;
		tytul* z = y->parent;
		if (y->right == x)
		{
			tytul* xLeft = x->left;
			tytul* xRight = x->right;

			x->parent = z->parent;
			x->left = y;
			x->right = z;

			y->parent = x;
			y->right = xLeft;

			z->parent = x;
			z->left = xRight;

			if (x->parent != nullptr)
			{
				if (x->parent->left == z) x->parent->left = x;
				else x->parent->right = x;
			}

			if (xLeft != nullptr) xLeft->parent = y;

			if (xRight != nullptr) xRight->parent = z;
		}
		else
		{

			tytul* xLeft = x->left;
			tytul* xRight = x->right;

			x->parent = z->parent;
			x->left = z;
			x->right = y;

			y->parent = x;
			y->left = xRight;

			z->parent = x;
			z->right = xLeft;

			if (x->parent != nullptr)
			{
				if (x->parent->left == z) x->parent->left = x;
				else x->parent->right = x;
			}

			if (xLeft != nullptr) xLeft->parent = z;

			if (xRight != nullptr) xRight->parent = y;
		}
	}

	void findThroughCrew(string zespol)
	{
		node* ret = nullptr;
		node* curr = root;
		node* prev = nullptr;
		while (curr != nullptr)
		{
			prev = curr;
			if (zespol < curr->zespol)
				curr = curr->left;
			else if (zespol > curr->zespol)
				curr = curr->right;
			else
			{
				ret = curr;
				break;
			}
		}

		
		if (ret != nullptr)
		{

			for (int i = 0; i < ret->lista.size(); i++)
				cout << ret->lista[i] << endl;
		}

	}

	void findThroughSong(string title)
	{
		tytul* ret = nullptr;
		tytul* curr = root2;
		tytul* prev = nullptr;
		while (curr != nullptr)
		{
			prev = curr;
			if (title < curr->nazwa)
				curr = curr->left;
			else if (title > curr->nazwa)
				curr = curr->right;
			else
			{
				ret = curr;
				break;
			}
		}


		if (ret != nullptr)
		{

			for (int i = 0; i < ret->lista.size(); i++)
				cout << ret->lista[i] << endl;
		}
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	Tree* tree = new Tree();

	string crew, title, znak, n;

	string::size_type sz;
	cin.clear();
	cin.sync();
	getline(cin, n);
	int i_n = stoi(n, &sz);
	for (int i = 0; i < i_n; i++)
	{
		cin.clear();
		cin.sync();
		getline(cin, znak);

		if (znak.compare("d") == 0)
		{
			cin.clear();
			cin.sync();
			getline(cin, crew);

			cin.clear();
			cin.sync();
			getline(cin, title);

			tree->add(crew, title);
			tree->add2(crew, title);
		}
		else if (znak.compare("w") == 0)
		{
			cin.clear();
			cin.sync();
			getline(cin, crew);

			tree->findThroughCrew(crew);
		}
		else if (znak.compare("z") == 0)
		{
			cin.clear();
			cin.sync();
			getline(cin, title);

			tree->findThroughSong(title);
		}	

	}

	delete tree;
	return 0;
}
