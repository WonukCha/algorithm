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

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (auto i : commands)
	{
		uint32_t unArrSize = i[1] - i[0] + 1;
		uint32_t unStartPos = i[0] - 1;
		vector<int> cur;
		cur.resize(unArrSize);
		copy(&array[unStartPos], &array[unStartPos]+ unArrSize, &cur[0]);
		sort(cur.begin(), cur.end());
		answer.push_back(cur[i[2] - 1]);
	}
	
	return answer;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	solution({ 1, 5, 2, 6, 3, 7, 4 }, { {2, 5, 3},{4, 4, 1},{1, 7, 3} });
	return 0;
}
