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

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (auto i : scoville)
	{
		pq.push(i);
	}

	while (!pq.empty())
	{
		auto curScoville = pq.top(); pq.pop();
		if (curScoville >= K)
		{
			break;
		}
		else
		{
			if (pq.empty())
			{
				answer = -1;
				break;
			}
			auto nextScoville = pq.top(); pq.pop();
			auto sum = curScoville + (nextScoville * 2);
			pq.push(sum);
			answer++;
		}
	}

	return answer;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	solution({1, 2, 3, 9, 10, 12}, 7);

	return 0;
}
