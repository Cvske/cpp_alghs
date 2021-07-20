#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int vecCnt = 0;
vector<int> vec;
struct node
{
	int val;
	node* left, * right;
};

class tree
{
	node* root;
public:
	tree()
	{
		root = NULL;
	}
	void add(int item)
	{
		node* temp = new node;
		temp->val = item;
		temp->left = nullptr; temp->right = nullptr;

		if (root == nullptr) root = temp;
			
		else
		{
			node* ptrPrev = nullptr;
			node* ptr = root;
			while (ptr != nullptr)
			{
				ptrPrev = ptr;
				if (item > ptr->val)
					ptr = ptr->right;
				else
					ptr = ptr->left;
			}
			if (item < ptrPrev->val) ptrPrev->left = temp;
			else ptrPrev->right = temp;
		}
	}
	void find(int k, vector<int> vec)
	{
		int p1 = 0, p2 = 2147483647;
		bool find = false;
		int start = 0, end = vecCnt - 1;
		
		while (start < end)
		{
			if (vec[start] + vec[end] == k)
			{
				if (abs(vec[start] - vec[end]) < abs(p1 - p2))
				{
					p1 = vec[start];
					p2 = vec[end];
					if (abs(p1 - p2) == 0) break;
				}
				p1 = vec[start];
				p2 = vec[end];
				find = true;
				/*break;*/
				start = 0;
				end--;
			}
			else if (vec[start] + vec[end] < k) start++;
			else
			{
				end--;
				start = 0;
			}
		}
		if(find == false) cout << "NIE ZNALEZIONO";
		else
		{
			if (p1 < p2) cout << p1 << " " << p2;
			else cout << p2 << " " << p1;
		}
	}
	void addToVector()
	{
		countNumbers(root);
	}
	void change(int min, int max)
	{
		delValues(root, min, max);
	}
	void countNumbers(node* ptr)
	{
		if (ptr != NULL)
		{
			vecCnt++;
			vec.push_back(ptr->val);
			countNumbers(ptr->left);
			countNumbers(ptr->right);
		}
	}
	node* delValues(node* root, int min, int max)
	{
		if (root == nullptr) return nullptr;
			
		root->left = delValues(root->left, min, max);
		root->right = delValues(root->right, min, max);


		if (root->val < min)
		{
			node* right = root->right;
			delete root;
			return right;
		}
		if (root->val > max)
		{
			node* left = root->left;
			delete root;
			return left;
		}
		return root;
	}
};

int main()
{
	int n;
	cin >> n;
	tree* drzewko = new tree();
	int value;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		drzewko->add(value);
	}

	int a, b, k;
	cin >> a >> b >> k;
	
	drzewko->change(a, b);
	drzewko->addToVector();
	sort(vec.begin(), vec.end());
	drzewko->find(k, vec);

	delete drzewko;
	return 0;
}
