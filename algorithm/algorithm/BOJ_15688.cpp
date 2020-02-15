#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>

int nArr[2000005];

using namespace std;

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int nInputCount = 0;
	int nPos = 0;
	int nMaxPos =0;
	cin >> nInputCount;
	
	for (int i = 0; i < nInputCount; i++)
	{
		cin >> nPos;
		nPos += 1000000;
		nArr[nPos]++;
		if (nPos > nMaxPos)
		{
			nMaxPos = nPos;
		}
	}

	for (int j = 0; j <= nMaxPos; j++)
	{
		while (nArr[j]>0)
		{
			cout << j - 1000000 << '\n';
			nArr[j]--;
		}
	}
	return 0;
}