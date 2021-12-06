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

int solution(vector<int> citations) {
	int answer = 0;
	int count = 0;
	count = citations.size();

	sort(citations.begin(), citations.end());

	for (int i = 0; i < citations.size(); i++)
	{
		if (count <= citations[i])
		{
			answer = count;
			break;
		}
		count--;
	}

	return answer;
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	solution({ 3, 0, 6, 1, 5 });

	return 0;
}
