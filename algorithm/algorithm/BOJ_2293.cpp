#include <iostream>
#include<vector>

using namespace std;

int main(void)
{
	int nCoinCount, nTargetPrice;

	cin >> nCoinCount >> nTargetPrice;
	vector<int> vConinList(nCoinCount);
	vector<int> vD1(nTargetPrice+1);
	vector<int> vD2(nTargetPrice + 1);

	for (int i = 0; i < nCoinCount; i++)
	{
		cin >> vConinList[i];
	}
	
	vD1[0] = 1;
	//for (int i = 0; i <= nTargetPrice; i += vConinList[0])
	//{
	//	vD1[i] = 1;
	//}

	for (int i = 0; i < nCoinCount; i++)
	{
		fill(vD2.begin(), vD2.end(), 0);
		for (int j = 0; j <= nTargetPrice; j++)
		{
			vD2[j] = vD1[j];
			if (0 <= j - vConinList[i])
			{
				vD2[j] += vD1[j - vConinList[i]];
			}
			vD1[j] = vD2[j];
		}
	}
	cout << vD1[nTargetPrice];
	return 0;
}