#include<iostream>
#include<vector>

using namespace std;


int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int nCoinListCount, nTargetPrice, nCoinLastIndex;
	cin >> nCoinListCount >> nTargetPrice;
	nCoinLastIndex = nCoinListCount;
	vector<int> vCoinList(nCoinListCount);
	for (int i = 0; i < nCoinListCount; i++)
	{
		cin >> vCoinList[i];
	}

	int nCurrentCoinCount = 0;
	int nCurrentPrice = 0;
	while (nCurrentPrice != nTargetPrice)
	{
		nCurrentPrice = 0;
		nCurrentCoinCount = 0;
		nCoinLastIndex--;
		for (int i = nCoinLastIndex; i >= 0; i--)
		{
			if (nCurrentPrice >= nTargetPrice)
				break;
			while(nCurrentPrice + vCoinList[i] <= nTargetPrice)
			{
				nCurrentPrice += vCoinList[i];
				nCurrentCoinCount++;
			}
		}
	}
	cout << nCurrentCoinCount;
	return 0;
}