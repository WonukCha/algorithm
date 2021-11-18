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

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};
vector<int> solution(vector<string> operations) {
	vector<int> answer(2,0);
	map<int, int> m;
	priority_queue<int> pqMax;
	priority_queue<int, vector<int>, cmp> pqMin;

	for (auto i : operations)
	{
		string strNum = i.substr(2, i.length());
		int nNum = stoi(strNum);
		int nCurNum = 0;

			switch (i[0])
			{
			case 'I':
			{
				m[nNum]++;
				pqMax.push(nNum);
				pqMin.push(nNum);
			}
			break;
			case 'D':
			{
				if (nNum > 0)
				{
					while (!pqMax.empty())
					{
						nCurNum = pqMax.top(); pqMax.pop();
						if (m[nCurNum] > 0)
						{
							m[nCurNum]--;
							break;
						}
					}
				}
				else
				{
					while (!pqMin.empty())
					{
						nCurNum = pqMin.top(); pqMin.pop();
						if (m[nCurNum] > 0)
						{
							m[nCurNum]--;
							break;
						}
					}
				}
			}
			break;
			default:
				break;
			}
	}
	int nCurNum = 0;

	while (!pqMax.empty())
	{
		nCurNum = pqMax.top(); pqMax.pop();
		if (m[nCurNum] > 0)
		{
			answer[0] = nCurNum;
			break;
		}
	}

	while (!pqMin.empty())
	{
		nCurNum = pqMin.top(); pqMin.pop();
		if (m[nCurNum] > 0)
		{
			answer[1] = nCurNum;
			break;
		}
	}
	return answer;
}


int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	solution({ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" });
	return 0;
}
