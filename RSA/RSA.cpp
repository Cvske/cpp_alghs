#include <iostream>
using namespace std;
long long euklidean(long long e, long long phi)
{
	long long x, y, add, restOfMod, restOfTotal;
	long long tempPhi, tempE, phi2;
	long long rememberIter;
	x = 1, y = 0;
	tempE = e, tempPhi = phi;
	rememberIter = 1;

	while (tempPhi != 0)
	{
		restOfMod = tempE % tempPhi;
		restOfTotal = tempE / tempPhi;

		add = x + restOfTotal * y;
		x = y;
		y = add;

		tempE = tempPhi;
		tempPhi = restOfMod;
		rememberIter *= (-1);
	}
	if (rememberIter < 0) return phi - x;
	else return x;

}
unsigned long long squares(unsigned long long index, unsigned long long mod, unsigned long long base)
{
	unsigned long long result = 1;
	if (index % 2 == 1)
	{
		index--;
		result *= base;
		result %= mod;
	}


	while (index > 0)
	{
		if (index % 2 == 1)
		{
			result *= base;
			result %= mod;
		}
		base *= base;
		base %= mod;
		index /= 2;
	}
	return result;
}
int main()
{
	ios_base::sync_with_stdio(false);
	unsigned long long t, publicKey, c, e, x, y;
	unsigned long long p, q, result = 1, phi;
	unsigned long long n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> p >> q >> e >> c;
		n = p * q;
		phi = (p - 1) * (q - 1);
		unsigned long long d = euklidean(e, phi);
		//cout << d;
		result = squares(d, n, c);
		cout << result << endl;
		result = 0;
		d = 0;
	}
	return 0;
}