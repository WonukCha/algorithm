#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int nSum = 0;
	int nTemp = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> nTemp;
		if (nTemp < 40)
			nTemp = 40;
		nSum += nTemp;
	}
	nSum = nSum / 5;

	cout << nSum;
	return 0;
}
