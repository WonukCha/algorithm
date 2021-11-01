#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>


using namespace std;

int main(void)
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	int nFirstArrCount = 0;
	int nSecondArrCount = 0;

	cin >> nFirstArrCount >> nSecondArrCount;

	vector<int> nFisrstArr(nFirstArrCount, 0);
	vector<int> nSecondArr(nSecondArrCount, 0);

	for (int i = 0; i < nFirstArrCount; i++)
	{
		cin >> nFisrstArr[i];
	}
	for (int j = 0; j < nSecondArrCount; j++)
	{
		cin >> nSecondArr[j];
	}

	int nTotalCount = nFirstArrCount + nSecondArrCount;
	int nCurCount = 0;

	int nFirstPos = 0;
	int nSecondPos = 0;

	while (nCurCount < nTotalCount)
	{
		if (nFirstPos == nFirstArrCount)
		{
			cout << nSecondArr[nSecondPos] << ' ';
			nSecondPos++;
			nCurCount++;
			continue;
		}
		if (nSecondPos == nSecondArrCount)
		{
			cout << nFisrstArr[nFirstPos] << ' ';
			nFirstPos++;
			nCurCount++;
			continue;
		}

		if (nFisrstArr[nFirstPos] < nSecondArr[nSecondPos])
		{
			cout << nFisrstArr[nFirstPos] << ' ';
			nFirstPos++;
		}
		else
		{
			cout << nSecondArr[nSecondPos] << ' ';
			nSecondPos++;
		}
		nCurCount++;
	}
	return 0;
}