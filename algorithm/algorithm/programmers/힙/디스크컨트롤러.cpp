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

#define  R_TIME 0
#define  W_TIME 1

struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0;

	priority_queue<pair<int, int>,vector<pair<int, int>>, cmp> pq;
	sort(jobs.begin(), jobs.end());
	uint32_t curTime = 0;
	uint32_t curPos = 0;
	pair<int, int> jop;

	while (true)
	{
		if (curPos == jobs.size() && pq.empty())
			break;


		while (curPos < jobs.size() && curTime >= jobs[curPos][R_TIME] )
		{
			pq.push({ jobs[curPos][R_TIME],jobs[curPos][W_TIME] });
			curPos++;
		}

		if (pq.empty())
		{
			curTime = jobs[curPos][R_TIME];
		}
		else
		{
			jop = pq.top(); pq.pop();
			curTime += jop.second;

			answer += (curTime - jop.first);
		}

	}
	return answer / jobs.size();
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);


	solution({ {0, 3},{1, 9},{2, 6} });

	return 0;
}
