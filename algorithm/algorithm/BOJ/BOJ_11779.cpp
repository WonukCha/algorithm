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
#include<tuple>
#include<functional>

using namespace std;

#define INF 2147483647
vector<pair<int, int>> vPath[1001];
vector<int> vMinimumCost;
vector<int> vMinimumCostpath;

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int nStartVertex , nEndVertex;
	int nVertexCount, nEdgeCount;
	cin >> nVertexCount >> nEdgeCount;

	//못가는 지역은 무한대 표기
	//시작 지역은 0으로 표기

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


	for (int i = 0; i < nEdgeCount; i++)
	{
		int nStartVertex, nEndVertex, nWeight;
		cin >> nStartVertex >> nEndVertex >> nWeight;
		vPath[nStartVertex].push_back(make_pair(nEndVertex, nWeight));
	}

	cin >> nStartVertex;
	cin >> nEndVertex;

	vMinimumCost.resize(nVertexCount + 1, INF);
	vMinimumCost[nStartVertex] = 0;

	vMinimumCostpath.resize(nVertexCount + 1, INF);
	vMinimumCostpath[nStartVertex] = 0;


	pq.push(make_pair(0, nStartVertex));

	while (!pq.empty())
	{
		int nCurStratVertex, nCurWeight;
		nCurWeight = pq.top().first;
		nCurStratVertex = pq.top().second;
		pq.pop();

		if (vMinimumCost[nCurStratVertex] == nCurWeight)
		{
			for (int i = 0; i < vPath[nCurStratVertex].size(); i++)
			{

				int nCurEndVertex = vPath[nCurStratVertex][i].first;
				int nStopoverWeight = vPath[nCurStratVertex][i].second;
				if (vMinimumCost[nCurEndVertex] >(nCurWeight + nStopoverWeight))
				{
					vMinimumCost[nCurEndVertex] = nCurWeight + nStopoverWeight;
					vMinimumCostpath[nCurEndVertex] = nCurStratVertex;
					pq.push({ vMinimumCost[nCurEndVertex], nCurEndVertex });
				}
			}
		}
	}
	cout << vMinimumCost[nEndVertex] << "\n";

	stack<int> sResult;
	int cur = nEndVertex;
	sResult.push(cur);
	while (true)
	{
		sResult.push(vMinimumCostpath[cur]);
		if (vMinimumCostpath[cur] == nStartVertex)
		{
			break;
		}
		cur = vMinimumCostpath[cur];
	}

	cout << sResult.size() << "\n";
	while (!sResult.empty())
	{
		int result = sResult.top(); sResult.pop();
		cout << result << " ";
	}
	return 0;
}
