#include <iostream>
#include <vector>
#include <algorithm>    //stable_sort
using namespace std;
struct dane
{
	unsigned long long losowyKod;
	int prio, m, unikalnyNumer;
	int tab[4];
};
bool compare(dane d1, dane d2)
{
	return d1.prio < d2.prio;
}
bool compareKody(dane d1, dane d2)
{
	return d1.losowyKod < d2.losowyKod;
}
void sortPrio(dane* tab, int n, int max)
{
	int count = 1, index = 0;
	const int iloscK = max;
	int min = 0;
	vector <dane> *wektorek=new vector<dane>[iloscK+1];
	for (int i = 1; i < n; i++)
	{
		index = tab[i].prio;
		wektorek[index].push_back(tab[i]);
	}
	for (int i = 0; i < iloscK + 1; i++)
	{
		int j = 0;
		stable_sort(wektorek[i].begin(), wektorek[i].end(), compare);
		for (int j = 0; j < wektorek[i].size(); j++)
		{
			tab[count] = wektorek[i][j];
			count++;
		}
	}
	delete[] wektorek;
}
void sortLosoweKody(dane* tab, int n, int max, int min)
{
	/*min = 0, max = 10000000;*/

	int count = 1, index = 0;
	int iloscK = max/100;
	vector <dane> *wektorek = new vector<dane> [iloscK + 1];
	

	for (int i = 1; i < n; i++)
	{
		/*index = iloscK * (tab[i].losowyKod - min) / (max - min);*/
		index = (tab[i].losowyKod)/100;
		wektorek[index].push_back(tab[i]);
	}
	for (int i = 0; i < iloscK + 1; i++)
	{
		stable_sort(wektorek[i].begin(), wektorek[i].end(), compareKody);
		for (int j = 0; j < wektorek[i].size(); j++)
		{
			tab[count] = wektorek[i][j];
			count++;
		}
	}
	delete[] wektorek;
}
void sortTab(dane* tab, int n, int dec, int max)
{
	int count = 1, index = 0;
	const int iloscK = max+1;
	vector <dane> *wektorek = new vector<dane> [iloscK+1];
	for (int i = 1; i < n; i++)
	{
		index = tab[i].tab[dec];
		index++;
		wektorek[index].push_back(tab[i]);
	}
	for (int i = 0; i < iloscK + 1; i++)
	{
		for (int j = 0; j < wektorek[i].size(); j++)
		{
			tab[count] = wektorek[i][j];
			count++;
		}
	}
	delete[] wektorek;
}

int main()
{
	ios_base::sync_with_stdio(false);
	unsigned long long wynik = 0;
	int n;
	cin >> n;
	dane* tabStruct = new dane[n + 1];
	int unikalnyNumer, m;
	int indexi;
	int tabzPrio[4];
	tabStruct[0].prio = -1;
	tabStruct[0].losowyKod = -1;
	tabStruct[0].unikalnyNumer = -1;
	tabStruct[0].m = -1;
	int maxPrio=0, minPrio=0;
	int maxUnik=0, minUnik=0;
	int maxKody = 0;
	for (int i = 1; i < n + 1; i++) //wczytywanie danych i sortowanie po 1
	{
		cin >> unikalnyNumer;

		tabStruct[unikalnyNumer].unikalnyNumer = unikalnyNumer;
		cin >> tabStruct[unikalnyNumer].prio;

		if (tabStruct[unikalnyNumer].prio > maxPrio) maxPrio = tabStruct[unikalnyNumer].prio;

		cin >> tabStruct[unikalnyNumer].losowyKod;

		if (tabStruct[unikalnyNumer].losowyKod > maxUnik) maxUnik = tabStruct[unikalnyNumer].losowyKod;
		else minUnik = tabStruct[unikalnyNumer].losowyKod;


		cin >> m;
		tabStruct[unikalnyNumer].m = m;
		for (int j = 0; j < 4; j++)
		{
			tabStruct[unikalnyNumer].tab[j] = -1;
			if (j < m)
			{
				cin >> tabStruct[unikalnyNumer].tab[j];
				if (tabStruct[unikalnyNumer].tab[j] > maxKody) maxKody = tabStruct[unikalnyNumer].tab[j];
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> tabzPrio[i];
		if (tabzPrio[i] == 1) indexi = i;
	} // tablica priorytetow

	for (int i = indexi; i >= 0; i--)
	{
		if (tabzPrio[i] == 2) sortPrio(tabStruct, n + 1, maxPrio);
		else if (tabzPrio[i] == 3) sortLosoweKody(tabStruct, n + 1, maxUnik, minUnik);
		else if (tabzPrio[i] == 4)
		{
			for (int i = 3; i >= 0; i--)	sortTab(tabStruct, n + 1, i, maxKody);
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		wynik += ((i - 1) * tabStruct[i].losowyKod);
		wynik %= 100000007;
	}
	cout << wynik;
	delete[]tabStruct;
	return 0;

}
