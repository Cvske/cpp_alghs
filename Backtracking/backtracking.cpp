#include <iostream>
using namespace std;


bool stacje(int wol, int size, int** tabStacje, int* tabBool, int k)
{

	for (int i = k; i < size; i++) {
		if (tabBool[tabStacje[i][0]] == 0 && tabBool[tabStacje[i][1]] == 0)
		{
			if (wol == 0) return false;
			else tabBool[tabStacje[i][0]] = 1;
			if (stacje(wol - 1, size, tabStacje, tabBool, i+1)) return true;
			else
			{
				tabBool[tabStacje[i][0]] = 0;
				tabBool[tabStacje[i][1]] = 1;
				if (stacje(wol - 1, size, tabStacje, tabBool, i + 1)) return true;
				else
				{
					tabBool[tabStacje[i][1]] = 0;
					return false;
				}

			}
		}
	}
		return true;

}

int main()
{

	ios_base::sync_with_stdio(false);
	int wolontariusze, bezpPolaczenia;
	int t;
	int liczbaStacji;
	cin >> t;
	bool dec;
	for (int i = 0; i < t; i++)
	{
		cin >> liczbaStacji >> bezpPolaczenia >> wolontariusze;
		int* tabBool = new int[liczbaStacji+1];
		int** tabStacje = new int* [bezpPolaczenia];
		for (int i = 1; i < liczbaStacji+1; i++) tabBool[i] = 0;
		for (int i = 0; i < bezpPolaczenia; i++)	tabStacje[i] = new int[2];
		for (int i = 0; i < bezpPolaczenia; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cin >> tabStacje[i][j];
			}
		}



		dec = stacje(wolontariusze, bezpPolaczenia, tabStacje, tabBool, 0);
		if (dec == false) cout << "NIE" << endl;
		else cout << "TAK" << endl;


		for (int i = 0; i < bezpPolaczenia; i++) delete[] tabStacje[i];
		delete[]tabBool; delete[]tabStacje;
	}
	return 0;
}
