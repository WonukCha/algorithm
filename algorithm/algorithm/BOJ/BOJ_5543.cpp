#include <iostream>

using namespace std;
#define INT_MAX 2147483647

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nMinBurgerPrice = INT_MAX;
	int nMinBeveragePrice = INT_MAX;
	int nTemp = 0;
	for (int i = 0; i < 3; i++)
	{
		cin >> nTemp;
		if (nMinBurgerPrice > nTemp)
			nMinBurgerPrice = nTemp;
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> nTemp;
		if (nMinBeveragePrice > nTemp)
			nMinBeveragePrice = nTemp;
	}
	cout << nMinBurgerPrice + nMinBeveragePrice-50;

	return 0;
}
