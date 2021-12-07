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

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	answer.resize(2);
	//반까지만해도될듯
	int lastIndex = yellow + 1;
	int w = 0, h=0;

	for (int i = 1; i < lastIndex; i++)
	{
		h = i;
		w = yellow / h;

		if (yellow % h)
			continue;

		if (brown == h * 2 + w * 2 + 4)
		{
			answer[0] = w + 2;
			answer[1] = h + 2;
			break;
		}
	}
	return answer;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	//solution(10,2);
	solution(8, 1);
	//solution(24, 24);


	return 0;
}
