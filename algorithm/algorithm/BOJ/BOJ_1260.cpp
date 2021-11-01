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

vector<int> vNodeEdge[10001];
bool bBfsVis[1001];
bool bDfsVis[1001];
bool desc(int a, int b){ return a > b; }

void bfs(int nNodeCount, int nDegeCount, int nStratNodeNum)
{
	int cur;
	cur = nStratNodeNum;
	queue<int> q;
	q.push(cur);
	bBfsVis[cur] = true;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int next =0; next < vNodeEdge[cur].size(); next++)
		{
			if (!bBfsVis[vNodeEdge[cur][next]])
			{
				q.push(vNodeEdge[cur][next]);
				bBfsVis[vNodeEdge[cur][next]] = true;

			}
		}
	}

}
void dfs(int nNodeCount, int nDegeCount, int nStratNodeNum)
{
	int cur;
	cur = nStratNodeNum;
	stack<int> s;
	s.push(cur);
	
	while (!s.empty())
	{
		cur = s.top();
		s.pop();
		if (bDfsVis[cur])
			continue;
		bDfsVis[cur] = true;
		cout << cur << ' ';
		for (int next = 0; next < vNodeEdge[cur].size(); next++)
		{
			int NextNode = vNodeEdge[cur][vNodeEdge[cur].size() - next - 1];
			if (!bDfsVis[NextNode])
			{
				s.push(NextNode);
			}
		}
	}

}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int nNodeCount, nDegeCount, nStratNodeNum;
	cin >> nNodeCount >> nDegeCount >> nStratNodeNum;
	for (int i = 0; i < nDegeCount; i++)
	{
		int nTempStartNode, nTempnArriveNode;
		cin >> nTempStartNode >> nTempnArriveNode;
		vNodeEdge[nTempStartNode].push_back(nTempnArriveNode);
		vNodeEdge[nTempnArriveNode].push_back(nTempStartNode);
	}
	for (int i = 0; i < nNodeCount; i++)
	{
		sort(vNodeEdge[i].begin(), vNodeEdge[i].end());
	}
	dfs(nNodeCount, nDegeCount, nStratNodeNum);
	cout << '\n';
	bfs(nNodeCount, nDegeCount, nStratNodeNum);

	return 0;
}
