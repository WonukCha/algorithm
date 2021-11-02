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

#define pos int
#define price int

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	answer.resize(prices.size());

	stack<pair<pos,price>> s;
	
	for (int i = 0; i < prices.size(); i++)
	{
		do
		{
			if (s.empty())
			{
				s.push({ i,prices[i] });
				break;
			}

			int curPrice = prices[i];

			while (!s.empty() && curPrice < s.top().second)
			{
				int topPrice = s.top().second;
				int topPos = s.top().first;
				answer[topPos] = i - topPos;
				s.pop();
			}

			s.push({ i,curPrice });

		} while (false);
		
	}

	while (!s.empty())
	{
		int topPrice = s.top().second;
		int topPos = s.top().first;
		s.pop();

		answer[topPos] = prices.size() - topPos-1;
	}
	
	return answer;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	solution({ 1, 2, 3, 2, 3 });

	return 0;
}
