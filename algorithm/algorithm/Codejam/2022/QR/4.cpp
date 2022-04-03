#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Initiators
{
public:
	Initiators() = default;
	Initiators(unsigned long long srcPoint, unsigned long long destPoint, unsigned long long sumFun, unsigned long long MaxFun, unsigned long long count)
	{
		this->srcPoint = srcPoint;
		this->destPoint = destPoint;
		this->sumFun = sumFun;
		this->MaxFun = MaxFun;
		this->count = count;
	}
	unsigned long long srcPoint = 0;
	unsigned long long destPoint = 0;
	unsigned long long sumFun = 0;
	unsigned long long MaxFun = 0;
	unsigned long long count = 0;
};

class cmp {
public:
	bool operator()(Initiators t, Initiators u) {
		if (t.sumFun - t.MaxFun == u.sumFun - u.MaxFun)
		{
			return t.count < u.count;
		}
		else
		{
			return t.sumFun - t.MaxFun > u.sumFun - u.MaxFun;
		}
	}
};

void solve(int caseIndex)
{
	unsigned long long result = 0;
	unsigned long long muchineCount = 0;
	cin >> muchineCount;

	vector<bool>used(muchineCount + 1, false);
	vector<unsigned long long>fun(muchineCount + 1, 0);
	vector<unsigned long long>sumFun(muchineCount + 1, 0);
	vector<unsigned int>point(muchineCount + 1, 0);
	vector<vector<unsigned long long>>waypoint(muchineCount + 1, vector<unsigned long long>());
	priority_queue < Initiators, vector<Initiators>, cmp> pq;

	for (unsigned long long i = 1; i <= muchineCount; i++)
	{
		cin >> fun[i];
	}
	for (unsigned long long i = 1; i <= muchineCount; i++)
	{
		cin >> point[i];
		waypoint[point[i]].push_back(i);
		sumFun[i] = fun[i];
	}

	queue<unsigned long long> bfs;
	for (unsigned long long i = 1; i <= muchineCount; i++)
	{
		if (point[i] == 0)
		{
			bfs.push(i);
		}
	}
	unsigned long long max = 0;
	unsigned long long sum = 0;
	unsigned long long cur = 0;
	unsigned long long dest = 0;
	unsigned long long start = 0;
	unsigned long long count = 0;

	while (!bfs.empty())
	{
		cur = bfs.front(); bfs.pop();
		if (point[cur] != 0)
		{
			sumFun[cur] += sumFun[point[cur]];
		}
		if (waypoint[cur].empty())
			continue;
		for (auto it : waypoint[cur])
		{
			bfs.push(it);
		}
	}

	for (unsigned long long i = 1; i <= muchineCount; i++)
	{
		if (waypoint[i].empty())
		{
			cur = i;
			dest = point[cur];
			sum = fun[cur];
			max = fun[cur];
			count = 1;
			while (true)
			{
				if (fun[cur] > max)
					max = fun[cur];

				if (dest == 0)
				{
					start = cur;
					break;
				}
				cur = dest;
				dest = point[cur];
				count++;
			}
			pq.push(Initiators(i, start, sumFun[i], max, count));
		}
	}
	Initiators initiators;
	while (!pq.empty())
	{
		queue<unsigned long long> Init;
		initiators = pq.top(); pq.pop();
		cur = initiators.srcPoint;
		dest = point[cur];


		while (true)
		{
			Init.push(cur);

			if (dest == 0 || used[dest])
			{
				if (initiators.destPoint == cur)
				{
					result += initiators.MaxFun;

					while (!Init.empty())
					{
						point[Init.front()] = 0;
						used[Init.front()] = true;
						Init.pop();
					}
				}
				else
				{
					initiators.sumFun = initiators.sumFun - sumFun[point[cur]];
					unsigned long long it = initiators.srcPoint;
					max = 0;
					count = 1;
					while (it != 0 && used[it] == false)
					{
						if (fun[it] > max)
							max = fun[it];
						it = point[it];
						count++;
					}
					initiators.MaxFun = max;
					initiators.destPoint = cur;
					initiators.count = count;
					pq.push(initiators);
				}
				break;
			}
			cur = dest;
			dest = point[cur];
		}
	}
	cout << "Case #" << caseIndex << ": " << result << "\n";
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testCaseCount = 0;
	int curCase = 0;

	cin >> testCaseCount;
	while (curCase < testCaseCount)
	{
		solve(curCase + 1);
		++curCase;
	}
	return 0;
}