#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int nCount;
	cin >> nCount;
	vector<int> vRope(nCount, 0);
	for (int i = 0; i < nCount; i++)
	{
		cin >> vRope[i];
	}
	sort(vRope.begin(), vRope.end());

	int nLastIndex = nCount - 1;
	int nCurrentUseRope = 1;
	int nMaxWeight = 0;

	for (int i = nLastIndex; i >= 0; i--)
	{
		if (nMaxWeight <= vRope[i] * nCurrentUseRope)
		{
			nMaxWeight = vRope[i] * nCurrentUseRope;
		}
		nCurrentUseRope++;
	}
	cout << nMaxWeight;

	return 0;
}