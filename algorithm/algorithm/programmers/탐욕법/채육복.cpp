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


/*
5	[2, 4]	[1, 3, 5]	5
5	[2, 4]	[3]	4
3	[3]	[1]	2
*/
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	vector<unsigned int>checkReserve(32,1);
	answer = n;
	do
	{
		if (lost.size() == 0)
		{
			break;
		}
		if (reserve.size() == 0)
		{
			answer = n - lost.size();
			break;
		}
		for (auto i : reserve)
		{
			checkReserve[i]++;
		}
		for (auto i : lost)
		{
			checkReserve[i]--;
		}
		int pre = 0;
		int next = 0;

		for (int i = 1; i < 32; i++)
		{
			if (checkReserve[i] == 0)
			{
				pre = i - 1;
				next = i + 1;

				if (checkReserve[pre] > 1)
				{
					checkReserve[pre]--;
					continue;
				}
				if (checkReserve[next] > 1)
				{
					checkReserve[next]--;
					continue;
				}
				answer--;
			}
		}
	} while (false);

	return answer;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);


	solution(5, { 2,4 }, { 1,3,5 }); //5
	solution(5, { 2,4 }, { 3 }); //4
	solution(3, { 3 }, { 1 }); //2

	return 0;
}
