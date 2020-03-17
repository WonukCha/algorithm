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

vector<int> v[1001];
bool bVis[1001];

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int nVectorSize, nInputLine;
	cin >> nVectorSize >> nInputLine;

//	vector<vector<int>> v(nVectorSize,vector<int>(0,0));
//	vector<bool> vVis(nVectorSize, false);
	int nStartNode, nArriveNode;
	for (int i = 0; i < nInputLine; i++)
	{
		cin >> nStartNode >> nArriveNode;
		v[nStartNode].push_back(nArriveNode);
		v[nArriveNode].push_back(nStartNode);
	}

	queue<int> q;
	int nResult = 0;
	for (int i = 1; i <= nVectorSize; i++)
	{
		if (bVis[i] == true) continue;
		nResult++;
		bVis[i] = true;
		q.push(i);

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (int jj = 0; jj < v[cur].size(); jj++)
			{
				int nxt = v[cur][jj];
				if (bVis[nxt] == true) continue;
				q.push(nxt);
				bVis[nxt] = true;
			}
		}
	}

	cout << nResult;

	return 0;
}