#include <string>
#include <vector>
#include <stack>


using namespace std;
bool bCheck[201];

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	stack<int>pos;

	for (int i = 0; i < n; i++)
	{
		if (bCheck[i] == false)
		{
			pos.push(i);
			answer++;

			while (!pos.empty())
			{
				int index = pos.top(); pos.pop();
				bCheck[index] = true;
				for (int j = 0; j < computers[index].size(); j++)
				{
					if (computers[index][j] == true && bCheck[j] == false)
						pos.push(j);
				}
			}

		}
	}

	return answer;
}

int main(void)
{

	solution(3 ,{{1, 1, 0}, { 1, 1, 0 }, {0, 0, 1}});
	return 0;
}