#include <iostream>
using namespace std;

void quickSort(int tab1[], int tab2[], int tab3[], int tab4[], int left, int right)
{

	int i = left, j = right;
	int x = tab4[(left + right) / 2];



	while (i <= j) {

		while (tab4[i] < x)

			i++;

		while (tab4[j] > x)

			j--;

		if (i <= j) {

			swap(tab1[i], tab1[j]);
			swap(tab2[i], tab2[j]);
			swap(tab3[i], tab3[j]);
			swap(tab4[i], tab4[j]);
			i++;
			j--;

		}

	};



	if (left < j)

		quickSort(tab1, tab2, tab3, tab4, left, j);

	if (i < right)

		quickSort(tab1, tab2, tab3, tab4, i, right);

}

int main()
{
	ios_base::sync_with_stdio(false);

	int liczbaMediow, pierwszeMedium, dzienTygodnia, liczbaDni, m, start;
	int licznik = 1;
	cin >> liczbaMediow >> pierwszeMedium >> dzienTygodnia >> liczbaDni >> m;
	long long suma = 1;
	int* tabA = new int[m];
	int* tabB = new int[m];
	int* tabC = new int[m];
	int* tabD = new int[m];
	unsigned long long** tabBool = new unsigned long long* [liczbaMediow];

	for (int i = 0; i < liczbaMediow; i++)
		tabBool[i] = new unsigned long long[7];
	for (int i = 0; i < liczbaMediow; i++)
		for (int j = 0; j < 7; j++)
			tabBool[i][j] = 0;
	tabBool[pierwszeMedium][dzienTygodnia] = 1;


	for (int i = 0; i < m; i++)
	{
		cin >> tabA[i] >> tabB[i] >> tabC[i] >> tabD[i];
		tabA[i] %= 100000007;
		tabB[i] %= 100000007;
		tabC[i] %= 100000007;
		tabD[i] %= 100000007;
	}
	quickSort(tabA, tabD, tabC, tabB, 0, m - 1);


	int j = 1, cnt = 0;
	int obecnyDzien = (dzienTygodnia + 1) % 7;
	while (tabB[cnt] != obecnyDzien)
	{
		
		if (cnt== m && obecnyDzien != tabB[cnt])
		{
			cnt = 0;
			obecnyDzien = dzienTygodnia;
			break;
		}
		cnt++;
			
	}
	/*if ((cnt == m) && obecnyDzien == dzienTygodnia) obecnyDzien = dzienTygodnia;*/

	while (j < liczbaDni)
	{
		while (tabB[cnt] == obecnyDzien)
		{
			tabBool[tabA[cnt]][tabB[cnt]] += tabBool[tabC[cnt]][tabD[cnt]] % 100000007;
			suma+= tabBool[tabC[cnt]][tabD[cnt]] % 100000007;
			if (cnt + 1 == m) cnt = 0;
			else cnt++;
		}

		obecnyDzien++;
		obecnyDzien %= 7;
		j++;
		for (int i = 0; i < liczbaMediow; i++)
			tabBool[i][(obecnyDzien) % 7] = 0;
		
	}
	suma %= 100000007;


	cout << suma;


	for (int i = 0; i < liczbaMediow; i++)
	{
		delete[] tabBool[i];
	}  
	delete[] tabBool;
	delete[]tabA;
	delete[]tabB;
	delete[]tabC;
	delete[]tabD;

	return 0;
}
