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
vector<int> vStudent[32005];
int arrPopularity[32005];
queue<int> q;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int nStudentCount, nLine;
	cin >> nStudentCount >> nLine;
	int nFrist, mSecond;
	for (int i = 0; i < nLine; i++)
	{
		cin >> nFrist >> mSecond;
		vStudent[nFrist].push_back(mSecond);
		arrPopularity[mSecond]++;
	}


	int nMergePopularity = 1;
	while (nMergePopularity)
	{
		nMergePopularity = 0;

		for (int i = 1; i <= nStudentCount; i++)
		{
			if (arrPopularity[i] == 0)
			{
				q.push(i);
				arrPopularity[i] = -1;
			}
			if (arrPopularity[i] > 0)
			{
				nMergePopularity += arrPopularity[i];
			}
		}

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			cout << cur << ' ';
			for (int i = 0; i < vStudent[cur].size(); i++)
			{
				int next = vStudent[cur][i];
				if (arrPopularity[next] > 0)
				{
					arrPopularity[next]--;
				}
				
			}
		}
	}
	return 0;
}