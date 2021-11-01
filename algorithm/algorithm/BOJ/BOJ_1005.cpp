
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
#include<utility>
#include<stack>
#include<string>
#include<map>
#include<set>

using namespace std;


void ACMCraft(int nNodeCount, int nLineCount)
{
	vector<int> nConstructionTime(nNodeCount+1, 0);
	vector<int> nPopularity(nNodeCount + 1, 0);
	vector<int> vChild[10001];
	vector<int> nDelayTime(nNodeCount + 1, 0);

	int nResultNode;
	for (int i = 1; i <= nNodeCount; i++)
	{
		cin >> nConstructionTime[i];
	}
	for (int i = 1; i <= nLineCount; i++)
	{
		int nStrat, nEnd;
		cin >> nStrat >> nEnd;
		nPopularity[nEnd]++;
		vChild[nStrat].push_back(nEnd);
	}
	cin >> nResultNode;

	queue<int> q;
	vector<int>vResult;
	for (int i = 1; i <= nNodeCount; i++)
	{
		if (nPopularity[i] == 0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int nCur = q.front(); q.pop();
		vResult.push_back(nCur);
		nDelayTime[nCur] += nConstructionTime[nCur];

		if (nCur == nResultNode)
		{
			cout << nDelayTime[nCur] << "\n";
			break;
		}
		for (int i = 0; i < vChild[nCur].size(); i++)
		{
			int nPos = vChild[nCur][i];
			nPopularity[nPos]--;

			if (nDelayTime[nPos] < nDelayTime[nCur])
			{
				nDelayTime[nPos] = nDelayTime[nCur];
			}
			if (nPopularity[nPos] == 0)
			{
				q.push(nPos);
			}
		}
	}
	

}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int nTestCase;
	cin >> nTestCase;

	for (int TestCase = 0; TestCase < nTestCase; TestCase++)
	{
		int nNodeCount, nLineCount;
		cin >> nNodeCount >> nLineCount;
		ACMCraft(nNodeCount, nLineCount);
	}
	return 0;
}