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

using namespace std;


vector<bool> bCheckList;
vector<tuple<int, int, int>> vList[10001];

struct cmp{
	bool operator()(tuple<int, int, int> t, tuple<int, int, int> u)
	{
		int a = std::get<2>(t);
		int b = std::get<2>(u);

		return a > b;
	}
};


int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> pqNode;

	int nNodeCount, nEdgeCount;
	cin >> nNodeCount >> nEdgeCount;
	int nWeight, nStartNode, nEndNode;
	for (int i = 0; i < nEdgeCount; i++)
	{
		cin >> nStartNode >> nEndNode >> nWeight;
		vList[nStartNode].push_back(make_tuple(nStartNode, nEndNode, nWeight));
		vList[nEndNode].push_back(make_tuple(nEndNode, nStartNode, nWeight));

	}
	bCheckList.resize(nNodeCount+1,0);
	int nResultWeight = 0;
	int cnt = 0;

	for (int i = 0; i < vList[1].size(); i++)
	{
		pqNode.push(vList[1][i]);
	}
	bCheckList[1] = true;

	while (1)
	{
		int nWeight, nStartNode, nEndNode;
		tie(nStartNode, nEndNode, nWeight) = pqNode.top();
		pqNode.pop();

		if (bCheckList[nEndNode] == true)
			continue;

		bCheckList[nEndNode] = true;
		nResultWeight += nWeight;

		cnt++;
		if (cnt == nNodeCount - 1) break;
		for (int i = 0; i < vList[nEndNode].size(); i++)
		{
			pqNode.push(vList[nEndNode][i]);
		}
	}
	cout << nResultWeight;
	return 0;
}