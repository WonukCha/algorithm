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
int npopularity[1001];
vector<int> nOrder[1001];





int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int nUseNum, nLineNum;

	cin >> nUseNum >> nLineNum;

	for (int i = 0; i < nLineNum; i++)
	{
		int nCount;
		cin >> nCount; 
		int nPer;
		for (int jj = 0; jj < nCount; jj++)
		{
			int nCur;
			cin >> nCur;
			if (jj > 0)
			{
				nOrder[nPer].push_back(nCur);
				npopularity[nCur]++;
			}
			nPer = nCur;
		}
	}
	queue<int> q;
	vector<int>vResult;
	for (int i = 1; i <= nUseNum; i++)
	{
		if (npopularity[i] == 0)
		{
			q.push(i);
		} 
	}
	while (!q.empty())
	{
		int nCur = q.front(); q.pop();
		vResult.push_back(nCur);
		for (int i = 0; i < nOrder[nCur].size(); i++)
		{
			int nPos = nOrder[nCur][i];
			npopularity[nPos]--;
			if (npopularity[nPos] == 0)
			{
				q.push(nPos);
			}
		}
	}

	if (vResult.size() != nUseNum)
	{
		cout << '0';
	}
	else
	{
		for (auto i : vResult)
			cout << i <<'\n';
	}


	return 0;
}