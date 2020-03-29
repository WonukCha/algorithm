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
vector<pair<int,int>> vPath[20001];
vector<int> vMinimumCostGraph;




int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int nStartVertex;
	int nVertexCount , nEdgeCount;
	cin >> nVertexCount >> nEdgeCount;
	cin >> nStartVertex;

	//못가는 지역은 무한대 표기
	//시작 지역은 0으로 표기
	vMinimumCostGraph.resize(nVertexCount + 1, INF);
	vMinimumCostGraph[nStartVertex] = 0;

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


	for (int i = 0; i < nEdgeCount; i++)
	{
		int nStartVertex, nEndVertex, nWeight;
		cin >> nStartVertex >> nEndVertex >> nWeight;
		vPath[nStartVertex].push_back(make_pair(nEndVertex, nWeight));
	}
	pq.push(make_pair(0, nStartVertex));

	while (!pq.empty())
	{
		int nCurEndVertex, nCurWeight;
		nCurWeight = pq.top().first;
		nCurEndVertex  = pq.top().second;
		pq.pop();

		if (vMinimumCostGraph[nCurEndVertex] == nCurWeight)
		{
			for (int i = 0; i < vPath[nCurEndVertex].size(); i++)
			{

				int nStopover = vPath[nCurEndVertex][i].first;
				int nStopoverWeight = vPath[nCurEndVertex][i].second;
				if (vMinimumCostGraph[nStopover] > (nCurWeight + nStopoverWeight))
				{
					vMinimumCostGraph[nStopover] = nCurWeight + nStopoverWeight;
					pq.push({ vMinimumCostGraph[nStopover], nStopover});
				}
			}
		}

	}
	for (int j = 1; j <= nVertexCount; j++)
	{
		if (vMinimumCostGraph[j] == INF)
		{
			cout << "INF" << '\n';
		}
		else
		{
			cout << vMinimumCostGraph[j] << '\n';
		}
	}
	return 0;
}